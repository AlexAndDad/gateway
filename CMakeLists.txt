cmake_minimum_required(VERSION 3.16)

include(cmake/HunterGate.cmake)
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.253.tar.gz"
        SHA1 "88ea6d37c897a81a080eb9ae0f69d7807bbb3c73"
        LOCAL
)

project(GateWay VERSION 0.1.0)

find_package(Threads REQUIRED)

hunter_add_package(Boost COMPONENTS filesystem iostreams program_options system)
find_package(Boost COMPONENTS filesystem iostreams program_options system REQUIRED CONFIG)

hunter_add_package(BoostWebclient)
find_package(boost_WEBCLIENT)

hunter_add_package(BoostJson)
find_package(boost_json)

hunter_add_package(spdlog COMPONENTS)
find_package(spdlog)

hunter_add_package(WiseEnum)
find_package(WiseEnum)

hunter_add_package(OpenSSL)
find_package(OpenSSL)

hunter_add_package(utf8cpp)
find_package(utf8cpp CONFIG REQUIRED)

hunter_add_package(ZLIB)
find_package(ZLIB CONFIG REQUIRED)

hunter_add_package(Catch)
find_package(Catch2)

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


