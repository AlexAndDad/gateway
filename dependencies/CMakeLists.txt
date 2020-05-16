cmake_minimum_required(VERSION 3.16)

include(ProcessorCount)
ProcessorCount(processors)
project(gateway_dependencies VERSION 0.1.0)

set(deps_root "${CMAKE_CURRENT_BINARY_DIR}")
set(deps_prefix "${deps_root}/install")
list(APPEND CMAKE_PREFIX_PATH ${deps_prefix})

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON CACHE BOOL "Whether to check for updates" FORCE)
include("${CMAKE_CURRENT_LIST_DIR}/cmake/BuildCMakeContent.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake/RequireBoost.cmake")


#
# catch2
#
FetchContent_Declare(catch2
        GIT_REPOSITORY  https://github.com/catchorg/Catch2.git
        GIT_TAG v2.12.1)
BuildCmakeContent(catch2 Catch2 CMAKE_ARGS
        "-DCATCH_BUILD_TESTING=OFF"
        "-DCATCH_INSTALL_DOCS=OFF"
        "-DCATCH_INSTALL_HELPERS=OFF")

#
# function2
#

FetchContent_Declare(function2
        GIT_REPOSITORY https://github.com/Naios/function2.git
        GIT_TAG 4.1.0)
BuildCmakeContent(function2 function2)

#
# zlib
#
FetchContent_Declare(zlib
        URL https://www.zlib.net/zlib-1.2.11.tar.gz
        URL_HASH SHA256=c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1)
BuildCmakeContent(zlib ZLIB
        CMAKE_ARGS)

#
# Boost
#

RequireBoost(VERSION 1.73.0 COMPONENTS filesystem iostreams program_options system PREFIX ${deps_prefix})

#
# boost_json
#

FetchContent_Declare(boost_json
        GIT_REPOSITORY  https://github.com/CPPAlliance/json.git
        GIT_TAG develop)
BuildCmakeContent(boost_json boost_json
        CMAKE_ARGS
        -DBOOST_JSON_BUILD_TESTS=OFF
        -DBOOST_JSON_BUILD_EXAMPLES=OFF)

#
# uriparser
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

#
# boost_webclient
#

FetchContent_Declare(boost_webclient
        GIT_REPOSITORY  https://github.com/madmongo1/webclient.git
        GIT_TAG develop)
BuildCMakeContent(boost_webclient boost_webclient
        CMAKE_ARGS
        -Duriparser_DIR=${uriparser_DIR}
        -DBOOST_ROOT=${BOOST_ROOT})
#
# wise_enum
#

FetchContent_Declare(wise_enum
        GIT_REPOSITORY  https://github.com/quicknir/wise_enum.git
        GIT_TAG master)
BuildCmakeContent(wise_enum WiseEnum)

#
# utf8cpp
#
FetchContent_Declare(utf8cpp
        GIT_REPOSITORY  https://github.com/nemtrif/utfcpp.git
        GIT_TAG v3.1)
BuildCmakeContent(utf8cpp utf8cpp
    CMAKE_ARGS
        -DUTF8_TESTS=OFF
        -DUTF8_SAMPLES=OFF)

#
# Eigen3
#
FetchContent_Declare(eigen3
        GIT_REPOSITORY  https://gitlab.com/libeigen/eigen.git
        GIT_TAG 3.3)
BuildCMakeContent(eigen3 Eigen3
        CMAKE_ARGS
        -DBUILD_TESTING=OFF
        -DEIGEN_TEST_CXX11=ON
        -DEIGEN_TEST_SSE4_2=ON
        -DEIGEN_TEST_AVX=ON
        -DEIGEN_TEST_AVX512=ON)

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
