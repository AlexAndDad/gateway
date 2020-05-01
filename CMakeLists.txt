cmake_minimum_required(VERSION 3.16)

#[[
include(cmake/HunterGate.cmake)
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.253.tar.gz"
        SHA1 "88ea6d37c897a81a080eb9ae0f69d7807bbb3c73"
        LOCAL
)
]]

project(GateWay VERSION 0.1.0)
include(FetchContent)

option(SPDLOG_FMT_EXTERNAL "spdlog uses fmt library" ON)

find_package(Threads REQUIRED)

FetchContent_Declare(catch2_build
        GIT_REPOSITORY  https://github.com/catchorg/Catch2.git
        GIT_TAG v2.12.1
        CMAKE_ARGS -DCMAKE_TOOLCHAIN_FILE="${CMAKE_TOOLCHAIN_FILE}")
    FetchContent_GetProperties(catch2_build)
FetchContent_MakeAvailable(catch2_build)
set(Catch2_FOUND ON)
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


