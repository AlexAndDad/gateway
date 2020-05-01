if(NOT REQUIRE_BOOST_CMAKE)
    set(REQUIRE_BOOST_CMAKE 1)
else()
    return()
endif()

function(ListToString list outstr)
    set(result)
    foreach(item IN LISTS "${list}")
        message(STATUS "--${item}")
        set(result "${result} " "\"" "${item}" "\"")
    endforeach()
    set(${outstr} "${result}" PARENT_SCOPE)
endfunction()

function(BoostSource boost_VERSION urlout hashout)
    if (boost_VERSION STREQUAL "1.73.0")
        set(${urlout} "https://dl.bintray.com/boostorg/release/1.73.0/source/boost_1_73_0.tar.bz2" PARENT_SCOPE)
        set(${hashout} "SHA256=4eb3b8d442b426dc35346235c8733b5ae35ba431690e38c6a8263dce9fcbb402" PARENT_SCOPE)
    else()
        message(FATAL_ERROR "unknown hash for version ${boost_VERSION}")
    endif()
endfunction()

function(RequireBoost )
    cmake_parse_arguments(boost
            "" # options
            "VERSION" #<one_value_keywords>
            "COMPONENTS" #<multi_value_keywords>
            ${ARGN}) #<args>...)
    if (NOT boost_VERSION)
        message(FATAL_ERROR "RequireBoost: requires VERSION argument")
    endif()
    if (NOT boost_COMPONENTS)
        set(boost_COMPONENTS headers)
    endif()

    include(FetchContent)
    BoostSource("${boost_VERSION}" boost_URL boost_HASH)
    FetchContent_Declare(boost
            URL "${boost_URL}"
            URL_HASH "${boost_HASH}")
    FetchContent_GetProperties(boost)
    if (NOT boost_POPULATED)
        FetchContent_Populate(boost)
    endif ()
    if (NOT boost_BOOTSTRAPPED)
        message("[boost] bootstrapping at ${boost_SOURCE_DIR}")
        execute_process(
                COMMAND "./bootstrap.sh"
                WORKING_DIRECTORY ${boost_SOURCE_DIR}
                RESULT_VARIABLE boost_BOOTSTRAP_ERROR)
        if (NOT boost_BOOTSTRAP_ERROR)
            set(boost_BOOTSTRAPPED YES CACHE BOOL "boost has been bootstrapped" FORCE)
        else()
            message(FATAL_ERROR "cannot bootstrap boost, error code: ${boost_BOOTSTRAP_ERROR}")
        endif()
    endif ()
    if(NOT boost_BUILT_COMPONENTS STREQUAL boost_COMPONENTS)
        include(ProcessorCount)
        ProcessorCount(processors)
        set(b2_args
                "variant=release"
                "link=static"
                "threading=multi"
                "toolset=clang")
        if ("${CMAKE_CXX_STANDARD}" STREQUAL "20")
            list(APPEND b2_args "cxxstd=2a")
        else()
            list(APPEND b2_args "cxxstd=${CMAKE_CXX_STANDARD}")
        endif()
        if (CMAKE_CXX_FLAGS)
            string(REGEX REPLACE "-std=[^ \t\r\n$]*" "" flags "${CMAKE_CXX_FLAGS}")
            list(APPEND b2_args "cxxflags=${flags}")
        endif()
        if (CMAKE_C_FLAGS)
            list(APPEND b2_args "cxxflags=${CMAKE_C_FLAGS}")
        endif()
        if (CMAKE_EXE_LINKER_FLAGS)
            list(APPEND b2_args "linkflags=${CMAKE_EXE_LINKER_FLAGS}")
        endif()
        list(APPEND b2_args
                "--build-dir=${boost_BINARY_DIR}/build"
                "--stage-dir=${boost_BINARY_DIR}/stage"
                "--prefix=${boost_BINARY_DIR}/install"
                "-j${processors}")
        foreach(comp IN LISTS boost_COMPONENTS)
            list(APPEND b2_args "--with-${comp}")
        endforeach()
        list(APPEND b2_args
                "stage"
                "install")

        ListToString(b2_args args_str)
        message(STATUS "[boost] ./b2${args_str}")

        execute_process(
                COMMAND "./b2" "--reconfigure" ${b2_args}
                WORKING_DIRECTORY ${boost_SOURCE_DIR}
                RESULT_VARIABLE boost_BUILD_ERROR)
        if (NOT boost_BUILD_ERROR)
            set(boost_BUILT_COMPONENTS "${boost_COMPONENTS}" CACHE STRING "components built for boost" FORCE)
        else()
            set(boost_BUILT_COMPONENTS "" CACHE STRING "components built for boost" FORCE)
            message(FATAL_ERROR "boost build failed")
        endif()
    endif()

    set(Boost_DIR "${boost_BINARY_DIR}/install/lib/cmake/Boost-${boost_VERSION}" PARENT_SCOPE)

endfunction()
