cmake_minimum_required(VERSION 3.16)

include(cmake/HunterGate.cmake)
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.253.tar.gz"
        SHA1 "88ea6d37c897a81a080eb9ae0f69d7807bbb3c73"
        LOCAL
)

project(GateWay VERSION 0.1.0)

file(GLOB_RECURSE src_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        src/*.cpp)
file(GLOB_RECURSE hdr_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        src/*.hpp)
add_executable(gateway ${src_files} ${hdr_files})
target_include_directories(gateway PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/src)


find_package(Threads REQUIRED)

hunter_add_package(Boost COMPONENTS system)
find_package(Boost COMPONENTS system REQUIRED CONFIG)

hunter_add_package(WiseEnum)
find_package(WiseEnum)

hunter_add_package(OpenSSL)
find_package(OpenSSL)

target_link_libraries(gateway PUBLIC
        Boost::boost Boost::system
        OpenSSL::Crypto OpenSSL::SSL
        Threads::Threads
        WiseEnum::wise_enum )
