cmake_minimum_required(VERSION 3.16)

include(ProcessorCount)
ProcessorCount(processors)

project(GateWay VERSION 0.1.0)

get_filename_component(build_leaf "${CMAKE_CURRENT_BINARY_DIR}" NAME)
message(STATUS "build_leaf=${build_leaf} from ${CMAKE_CURRENT_BINARY_DIR}")
execute_process(COMMAND ${CMAKE_COMMAND} "-H${CMAKE_CURRENT_LIST_DIR}/dependencies" "-B${CMAKE_CURRENT_BINARY_DIR}/dependencies" "-DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}")

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR}/dependencies/install)
find_package(Threads REQUIRED)
find_package(Catch2 CONFIG REQUIRED)#
find_package(BZip2 REQUIRED)
find_package(Boost COMPONENTS filesystem iostreams program_options system REQUIRED CONFIG)
find_package(boost_json REQUIRED)
find_package(OpenSSL)
find_package(uriparser  REQUIRED)
find_package(boost_webclient  REQUIRED)
find_package(WiseEnum REQUIRED)
find_package(utf8cpp)
find_package(ZLIB REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(Python3 REQUIRED)

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


