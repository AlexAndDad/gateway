#
# all spec files
#

set(libs_spec_files)
set(all_libs)

#
# config
#

set(TEST_DATA_DIR "${PROJECT_SOURCE_DIR}/test_data")
configure_file(config/test_data.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/config/test_data.hpp @ONLY)

file(GLOB_RECURSE config_src_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        config/*.cpp)
file(GLOB_RECURSE config_generated_hdr_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_BINARY_DIR}/config/*.hpp)
file(GLOB_RECURSE config_hdr_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        src/*.hpp)
list(APPEND config_hdr_files ${generated_hdr_files})
set(config_spec_files ${config_src_files})
list(FILTER config_spec_files INCLUDE REGEX "^.*.\\.spec\\.cpp$")
list(FILTER config_src_files EXCLUDE REGEX "^.*.\\.spec\\.cpp$")

add_library(config_lib INTERFACE)
#target_sources(config_lib INTERFACE ${config_src_files} ${config_hdr_files})
target_compile_definitions(config_lib INTERFACE -DBOOST_ASIO_NO_DEPRECATED)
target_link_libraries(config_lib INTERFACE WiseEnum::wise_enum)

target_include_directories(config_lib
        INTERFACE
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND all_libs config_lib)
list(APPEND all_spec_files ${config_spec_files})


#
# polyfill
#

file(GLOB_RECURSE polyfill_src_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        polyfill/*.cpp)
file(GLOB_RECURSE polyfill_generated_hdr_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_BINARY_DIR}/polyfill/*.hpp)
file(GLOB_RECURSE polyfill_hdr_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        src/*.hpp)
list(APPEND polyfill_hdr_files ${generated_hdr_files})
set(polyfill_spec_files ${polyfill_src_files})
list(FILTER polyfill_spec_files INCLUDE REGEX "^.*.\\.spec\\.cpp$")
list(FILTER polyfill_src_files EXCLUDE REGEX "^.*.\\.spec\\.cpp$")

add_library(polyfill_lib ${polyfill_src_files} ${polyfill_hdr_files})
target_link_libraries(polyfill_lib PUBLIC config_lib Boost::boost)
target_include_directories(polyfill_lib
        PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND all_libs polyfill_lib)
list(APPEND all_spec_files ${polyfill_spec_files})

#
# minecraft
#

file(GLOB_RECURSE minecraft_src_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        minecraft/*.cpp)
file(GLOB_RECURSE minecraft_generated_hdr_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_BINARY_DIR}/minecraft/*.hpp)
file(GLOB_RECURSE minecraft_hdr_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        src/*.hpp)
list(APPEND minecraft_hdr_files ${generated_hdr_files})
set(minecraft_spec_files ${minecraft_src_files})
list(FILTER minecraft_spec_files INCLUDE REGEX "^.*.\\.spec\\.cpp$")
list(FILTER minecraft_src_files EXCLUDE REGEX "^.*.\\.spec\\.cpp$")

add_library(minecraft_lib ${minecraft_src_files} ${minecraft_hdr_files})
target_link_libraries(minecraft_lib PUBLIC
        config_lib polyfill_lib
        Boost::boost Boost::filesystem Boost::system
        Threads::Threads
        OpenSSL::Crypto OpenSSL::SSL
        ZLIB::zlib)

target_include_directories(minecraft_lib
        PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND all_libs config_lib minecraft_lib)
list(APPEND all_spec_files ${minecraft_spec_files})

#
#
#

set(all_libs ${all_libs} PARENT_SCOPE)
set(all_spec_files ${all_spec_files} PARENT_SCOPE)
