cmake_minimum_required(VERSION 3.16)

include(cmake/HunterGate.cmake)
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.253.tar.gz"
        SHA1 "88ea6d37c897a81a080eb9ae0f69d7807bbb3c73"
        LOCAL
)

project(GateWay VERSION 0.1.0)

find_package(Threads REQUIRED)

hunter_add_package(Boost COMPONENTS filesystem system)
find_package(Boost COMPONENTS filesystem system REQUIRED CONFIG)

hunter_add_package(WiseEnum)
find_package(WiseEnum)

hunter_add_package(OpenSSL)
find_package(OpenSSL)

hunter_add_package(ZLIB)
find_package(ZLIB CONFIG REQUIRED)

hunter_add_package(Catch)
find_package(Catch2)


add_subdirectory(libs)
add_subdirectory(src)
add_subdirectory(test)


