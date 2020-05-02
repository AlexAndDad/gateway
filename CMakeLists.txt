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

set(FETCHCONTENT_UPDATES_DISCONNECTED ON CACHE BOOL "Whether to check for updates" FORCE)

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

    string(TOUPPER $bcc_NAME bcc_NAME_UPPER)
    set("FETCHCONTENT_UPDATES_DISCONNECTED_${bcc_NAME_UPPER}" ON CACHE BOOL "Whether to check for updates" FORCE)


    message(STATUS "[dependencies] fetching properties for ${bcc_NAME}")
    FetchContent_GetProperties("${bcc_NAME}")
    if (NOT "${${bcc_NAME}_POPULATED}")
        FetchContent_Populate(${bcc_NAME})
        FetchContent_GetProperties("${bcc_NAME}")
        message(STATUS "[dependencies] Populating ${bcc_NAME} in ${bcc_NAME}_SOURCE_DIR")
    endif()

    #
    # configure step
    #

    set(bcc_configure_options
            "-DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}"
            "-DCMAKE_INSTALL_PREFIX=${deps_prefix}"
            "-DCMAKE_PREFIX_PATH=${deps_prefix}"
            ${bcc_CMAKE_ARGS}
            "-H${${bcc_NAME}_SOURCE_DIR}"
            "-B${${bcc_NAME}_BINARY_DIR}")
    if (NOT "${${bcc_NAME}_CONFIGURED}" STREQUAL "${bcc_configure_options}")
        message(STATUS "[dependencies] ${bcc_NAME} previously configured with ${${bcc_NAME}_CONFIGURED}")
        message(STATUS "[dependencies] Configuring ${bcc_NAME} with args ${bcc_configure_options}")
        set(${bcc_NAME}_BUILT "" CACHE INTERNAL "")
        set(${bcc_NAME}_INSTALLED "" CACHE INTERNAL "")
        execute_process(COMMAND "${CMAKE_COMMAND}" ${bcc_configure_options})
        if (NOT bcc_RESULT)
            set("${bcc_NAME}_CONFIGURED" "${bcc_configure_options}" CACHE INTERNAL "${bcc_NAME} has been configured")
        else()
            message(FATAL_ERROR "[dependency] failed to configure ${bcc_NAME}")
        endif()
    endif()

    #
    # build step
    #

    set(bcc_build_options "--build" "${${bcc_NAME}_BINARY_DIR}" "--parallel" "${processors}")
    if (NOT "${${bcc_NAME}_BUILT}" STREQUAL "${bcc_build_options}")
        message(STATUS "[dependencies] ${bcc_NAME} previously built ${${bcc_NAME}_BUILT}")
        message(STATUS "[dependencies] Building ${bcc_NAME}")
        set(${bcc_NAME}_INSTALLED "" CACHE INTERNAL "")
        execute_process(COMMAND "${CMAKE_COMMAND}" ${bcc_build_options}
                RESULT_VARIABLE bcc_RESULT)
        if (bcc_RESULT)
            message(FATAL_ERROR "build failed")
        else()
            set("${bcc_NAME}_BUILT" "${bcc_build_options}" CACHE INTERNAL "${bcc_NAME} has been built")
        endif()
    endif()

    #
    # install step
    #

    set(bcc_install_options "--install" "${${bcc_NAME}_BINARY_DIR}")
    if (NOT "${${bcc_NAME}_INSTALLED}" STREQUAL "${bcc_install_options}")
        message(STATUS "[dependencies] ${bcc_NAME} previously installed ${${bcc_NAME}_INSTALLED}")
        message(STATUS "[dependencies] Installing ${bcc_NAME}")
        execute_process(COMMAND "${CMAKE_COMMAND}"  ${bcc_install_options} RESULT_VARIABLE bcc_result)
        if (bcc_RESULT)
            message(FATAL_ERROR "build failed")
        else()
            set("${bcc_NAME}_INSTALLED" "${bcc_install_options}" CACHE INTERNAL "${bcc_NAME} has been installed")
        endif()
    endif()

    message(STATUS "[dependencies] ${bcc_PACKAGE}_ROOT=${deps_prefix}")
endmacro()

list(APPEND CMAKE_PREFIX_PATH ${deps_prefix})

FetchContent_Declare(catch2
        GIT_REPOSITORY  https://github.com/catchorg/Catch2.git
        GIT_TAG v2.12.1)
FetchContent_GetProperties(catch2)
BuildCmakeContent(catch2 Catch2 CMAKE_ARGS
        "-DCATCH_BUILD_TESTING=OFF"
        "-DCATCH_INSTALL_DOCS=OFF"
        "-DCATCH_INSTALL_HELPERS=OFF"
        )
find_package(Catch2 CONFIG REQUIRED)#


#hunter_add_package(BZip2)
find_package(BZip2 REQUIRED)

include(cmake/RequireBoost.cmake)
RequireBoost(VERSION 1.73.0 COMPONENTS filesystem iostreams program_options system PREFIX ${deps_prefix})
#hunter_add_package(Boost COMPONENTS filesystem iostreams program_options system)
find_package(Boost COMPONENTS filesystem iostreams program_options system REQUIRED CONFIG)


FetchContent_Declare(boost_json
        GIT_REPOSITORY  https://github.com/CPPAlliance/json.git
        GIT_TAG develop)
BuildCmakeContent(boost_json boost_json
        CMAKE_ARGS
            -DBOOST_JSON_BUILD_TESTS=OFF
            -DBOOST_JSON_BUILD_EXAMPLES=OFF)
find_package(boost_json REQUIRED)
#FetchContent_MakeAvailable(boost_json)

#
# openssl
#
find_package(OpenSSL)

#
# boost_webclient
#
FetchContent_Declare(uriparser
        GIT_REPOSITORY  https://github.com/uriparser/uriparser.git
        GIT_TAG uriparser-0.9.3)
BuildCMakeContent(uriparser uriparser
        CMAKE_ARGS
            -DBUILD_SHARED_LIBS=OFF
            -DURIPARSER_BUILD_DOCS=OFF
            -DURIPARSER_BUILD_TESTS=OFF
            -DURIPARSER_BUILD_TOOLS=OFF)
find_package(uriparser  REQUIRED)

FetchContent_Declare(boost_webclient
        GIT_REPOSITORY  https://github.com/madmongo1/webclient.git
        GIT_TAG develop)
BuildCMakeContent(boost_webclient boost_webclient
        CMAKE_ARGS
            -Duriparser_DIR=${uriparser_DIR}
            -DBOOST_ROOT=${BOOST_ROOT})
find_package(boost_webclient  REQUIRED)

#
# wise_enum
#
FetchContent_Declare(wise_enum
    GIT_REPOSITORY  https://github.com/quicknir/wise_enum.git
    GIT_TAG master)
BuildCmakeContent(wise_enum WiseEnum)
find_package(WiseEnum REQUIRED)

#
# utf8cpp
#

FetchContent_Declare(utf8cpp
        GIT_REPOSITORY  https://github.com/nemtrif/utfcpp.git
        GIT_TAG v3.1)
BuildCmakeContent(utf8cpp utf8cpp)
find_package(utf8cpp)


FetchContent_Declare(zlib
        URL https://www.zlib.net/zlib-1.2.11.tar.gz
        URL_HASH SHA256=c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1)
BuildCmakeContent(zlib ZLIB
        CMAKE_ARGS
        )
find_package(ZLIB REQUIRED)


FetchContent_Declare(eigen3
        GIT_REPOSITORY  https://gitlab.com/libeigen/eigen.git
        GIT_TAG 3.3)
BuildCMakeContent(eigen3 Eigen3)
find_package(Eigen3 REQUIRED)

#
# fmt
#

FetchContent_Declare(fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt.git
        GIT_TAG 6.2.0)
BuildCMakeContent(fmt fmt
        CMAKE_ARGS
        -DFMT_DOC=OFF
        -DFMT_INSTALL=ON
        -DFMT_TEST=OFF)
find_package(fmt REQUIRED)

#
# spdlog
#

FetchContent_Declare(spdlog
        GIT_REPOSITORY  https://github.com/gabime/spdlog.git
        GIT_TAG v1.5.0)
BuildCMakeContent(spdlog spdlog
        CMAKE_ARGS
        -DSPDLOG_BUILD_EXAMPLE=OFF
        -DSPDLOG_BUILD_TESTS=OFF
        -DSPDLOG_INSTALL=ON
        -DSPDLOG_FMT_EXTERNAL=ON)
find_package(spdlog REQUIRED)

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


