cmake_minimum_required(VERSION 3.16)

include(cmake/HunterGate.cmake)
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.253.tar.gz"
        SHA1 "88ea6d37c897a81a080eb9ae0f69d7807bbb3c73"
        LOCAL
)

project(GateWay VERSION 0.1.0)

set(TEST_DATA_DIR "${CMAKE_CURRENT_SOURCE_DIR}/test_data")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/config/test_data.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/src/config/test_data.hpp @ONLY)

file(GLOB_RECURSE src_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        src/*.cpp)
file(GLOB_RECURSE generated_hdr_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_BINARY_DIR}/src/*.hpp)
file(GLOB_RECURSE hdr_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        src/*.hpp)
list(APPEND hdr_files ${generated_hdr_files})
set(spec_files ${src_files})
list(FILTER spec_files INCLUDE REGEX "^.*.\\.spec\\.cpp$")
list(FILTER src_files EXCLUDE REGEX "^.*.\\.spec\\.cpp$")
list(FILTER src_files EXCLUDE REGEX "^.*main\\.cpp$")

add_library(gateway_lib ${src_files} ${hdr_files})
target_include_directories(gateway_lib
        PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(gateway src/main.cpp)
target_link_libraries(gateway PUBLIC gateway_lib)

add_executable(gateway_test ${spec_files})
target_link_libraries(gateway_test PUBLIC gateway_lib)

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

target_link_libraries(gateway_test PUBLIC Catch2::Catch2)

target_link_libraries(gateway_lib PUBLIC
        Boost::boost Boost::filesystem Boost::system
        OpenSSL::Crypto OpenSSL::SSL
        Threads::Threads
        WiseEnum::wise_enum
        ZLIB::zlib)
