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


file(GLOB_RECURSE toolchain_files LIST_DIRECTORIES false CONFIGURE_DEPENDS polly/*.cmake)
add_custom_command(OUTPUT dev_image.flag
        COMMENT "building development docker"
        COMMAND docker build -t gateway/fedora-devel:latest ${CMAKE_CURRENT_LIST_DIR}/dockers/fedora-devel
        COMMAND touch dev_image.flag
        MAIN_DEPENDENCY dockers/fedora-devel/Dockerfile
        USES_TERMINAL)

get_filename_component(toolchain "${CMAKE_TOOLCHAIN_FILE}" NAME_WLE)
message(STATUS "[docker] toolchain=${toolchain}")
add_custom_command(OUTPUT build_container_created.flag
        COMMENT "build dependencies in container"
        COMMAND bash ${CMAKE_CURRENT_LIST_DIR}/dockers/run-dependency-container.sh ${toolchain} ${CMAKE_CURRENT_LIST_DIR}
        COMMAND docker exec -t gateway_${toolchain} mkdir /build
        COMMAND docker exec -t gateway_${toolchain} cmake -H/src/dependencies -B/build/cmake-build-${toolchain}-${CMAKE_BUILD_TYPE}/dependencies -DCMAKE_TOOLCHAIN_FILE=/src/polly/${toolchain}.cmake
        COMMAND docker stop gateway_${toolchain}
        COMMAND docker commit gateway_${toolchain} gateway/dependencies-${toolchain}:latest
        COMMAND touch build_container_created.flag
        MAIN_DEPENDENCY dev_image.flag
        DEPENDS dockers/run-dependency-container.sh
        USES_TERMINAL)
add_custom_target(docker-dependency
        DEPENDS build_container_created.flag)

