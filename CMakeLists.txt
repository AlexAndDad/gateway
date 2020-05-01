cmake_minimum_required(VERSION 3.16)

#[[
include(cmake/HunterGate.cmake)
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.253.tar.gz"
        SHA1 "88ea6d37c897a81a080eb9ae0f69d7807bbb3c73"
        LOCAL
)
]]

include(ProcessorCount)
ProcessorCount(processors)

project(GateWay VERSION 0.1.0)
include(FetchContent)

option(SPDLOG_FMT_EXTERNAL "spdlog uses fmt library" ON)

find_package(Threads REQUIRED)

set(deps_root "${CMAKE_CURRENT_BINARY_DIR}/_deps")
set(deps_prefix "${deps_root}/install")

macro(BuildCmakeContent bcc_NAME bcc_PACKAGE)
    cmake_parse_arguments(bcc
            "" # options
            "" #<one_value_keywords>
            "CMAKE_ARGS" # multi_value keywords
            ${ARGN}) #<args>...)
    if (bcc_NAME STREQUAL "")
        message(FATAL_ERROR "BuildDependency: requires name")
    endif()
    if (bcc_PACKAGE STREQUAL "")
        message(FATAL_ERROR "BuildDependency: requires package")
    endif()

    if (NOT ${${bcc_NAME}_POPULATED})
        message(STATUS "[dependencies] Populating ${bcc_PACKAGE}")
        FetchContent_Populate(${bcc_NAME})
    endif()

    if (NOT ${${bcc_NAME}_CONFIGURED})
        message(STATUS "[dependencies] Configuring ${bcc_PACKAGE}")
        execute_process(COMMAND
                "${CMAKE_COMMAND}"
                "-DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}"
                "-DCMAKE_INSTALL_PREFIX=${deps_prefix}"
                "-DCMAKE_PREFIX_PATH=${deps_prefix}"
                ${name_CMAKE_ARGS}
                "-H${${bcc_NAME}_SOURCE_DIR}"
                "-B${${bcc_NAME}_BINARY_DIR}"
                RESULT_VARIABLE bcc_RESULT
                )
        if (NOT bcc_RESULT)
            set(${${bcc_NAME}_CONFIGURED} YES CACHE BOOL "${bcc_NAME} has been configured" FORCE)
        else()
            set(${${bcc_NAME}_CONFIGURED} NO CACHE BOOL "${bcc_NAME} has been configured" FORCE)
            message(FATAL_ERROR "[dependency] failed to configure ${bcc_NAME}")
        endif()
    endif()

    if (NOT ${${bcc_NAME}_BUILT})
        message(STATUS "[dependencies] Building ${bcc_PACKAGE}")
        execute_process(COMMAND "${CMAKE_COMMAND}" "--build" "${${bcc_NAME}_BINARY_DIR}" "--parallel" "${processors}"
                RESULT_VARIABLE bcc_RESULT)
        if (bcc_RESULT)
            set(${${bcc_NAME}_BUILT} NO CACHE BOOL "${bcc_NAME} has been built" FORCE)
            message(FATAL_ERROR "build failed")
        else()
            set(${${bcc_NAME}_BUILT} YES CACHE BOOL "${bcc_NAME} has been built" FORCE)
        endif()
    endif()

    if (NOT ${${bcc_NAME}_INSTALLED})
        message(STATUS "[dependencies] Installing ${bcc_PACKAGE}")
        execute_process(COMMAND "${CMAKE_COMMAND}" "--install" "${${bcc_NAME}_BINARY_DIR}" RESULT_VARIABLE bcc_result)
        if (bcc_RESULT)
            set(${${bcc_NAME}_INSTALLED} NO CACHE BOOL "${bcc_NAME} has been installed" FORCE)
            message(FATAL_ERROR "build failed")
        else()
            set(${${bcc_NAME}_INSTALLED} YES CACHE BOOL "${bcc_NAME} has been installed" FORCE)
        endif()
    endif()

    message(STATUS "[dependencies] ${bcc_PACKAGE}_ROOT=${deps_prefix}")
endmacro()

list(APPEND CMAKE_PREFIX_PATH ${deps_prefix})

FetchContent_Declare(catch2
        GIT_REPOSITORY  https://github.com/catchorg/Catch2.git
        GIT_TAG v2.12.1)
BuildCmakeContent(catch2 Catch2 CMAKE_ARGS
        "-DCATCH_BUILD_TESTING=OFF"
        "-DCATCH_INSTALL_DOCS=OFF"
        "-DCATCH_INSTALL_HELPERS=OFF"
        )
find_package(Catch2 CONFIG REQUIRED)#

message(FATAL_ERROR "done")
find_package(Catch2)


#hunter_add_package(BZip2)
find_package(BZip2 REQUIRED)

include(cmake/RequireBoost.cmake)
RequireBoost(VERSION 1.73.0 COMPONENTS filesystem iostreams program_options system)
#hunter_add_package(Boost COMPONENTS filesystem iostreams program_options system)
find_package(Boost COMPONENTS filesystem iostreams program_options system REQUIRED CONFIG)


FetchContent_Declare(boost_json
        GIT_REPOSITORY  https://github.com/madmongo1/json.git
        GIT_TAG develop)
FetchContent_MakeAvailable(boost_json)

FetchContent_Declare(boost_webclient
        GIT_REPOSITORY  https://github.com/madmongo1/webclient.git
        GIT_TAG develop)
FetchContent_MakeAvailable(boost_webclient)


FetchContent_Declare(wise_enum
    GIT_REPOSITORY  https://github.com/quicknir/wise_enum.git
    GIT_TAG 3.0.0)
FetchContent_MakeAvailable(wise_enum)

find_package(OpenSSL)

FetchContent_Declare(utf8cpp
        GIT_REPOSITORY  https://github.com/nemtrif/utfcpp.git
        GIT_TAG v3.1)
FetchContent_MakeAvailable(utf8cpp)

find_package(ZLIB CONFIG REQUIRED)


FetchContent_Declare(eigen
        GIT_REPOSITORY  https://gitlab.com/libeigen/eigen.git
        GIT_TAG 3.3)
FetchContent_MakeAvailable(eigen)

if (CMAKE_BUILD_TYPE MATCHES "[Dd]ebug")
if (CMAKE_CXX_COMPILER_ID MATCHES "[Cc]lang")
# using Clang
add_compile_options(-Wall -Wextra -pedantic -Werror -fchar8_t)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "[Gg][Nn][Uu]")
# using GCC
add_compile_options(-Wall -Wextra -pedantic -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
# using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
# using Visual Studio C++
add_compile_options(/W4 /WX)
endif ()
endif ()

add_subdirectory(libs)
add_subdirectory(src)
add_subdirectory(test)


