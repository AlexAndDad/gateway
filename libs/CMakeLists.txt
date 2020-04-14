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
target_sources(config_lib INTERFACE ${config_src_files} ${config_hdr_files})

target_include_directories(config_lib
        INTERFACE
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND all_libs config_lib)
list(APPEND app_spec_files ${config_spec_files})







set(all_libs ${all_libs} PARENT_SCOPE)
set(all_spec_files ${all_spec_files} PARENT_SCOPE)
