set(TEST_DATA_DIR "${PROJECT_SOURCE_DIR}/test_data")
configure_file(test_data.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/test_data.hpp @ONLY)

file(GLOB_RECURSE config_src_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        "*.cpp")
file(GLOB_RECURSE config_generated_hdr_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_BINARY_DIR}/*.hpp")
file(GLOB_RECURSE config_hdr_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        "*.hpp")
list(APPEND config_hdr_files ${generated_hdr_files})
set(config_spec_files ${config_src_files})
list(FILTER config_spec_files INCLUDE REGEX "^.*.\\.spec\\.cpp$")
list(FILTER config_src_files EXCLUDE REGEX "^.*.\\.spec\\.cpp$")

add_library(config_lib INTERFACE)
target_compile_definitions(config_lib
        INTERFACE
        -DBOOST_ASIO_NO_DEPRECATED
        -DWISE_ENUM_STRING_TYPE=std::string_view
        -DBOOST_ASIO_DISABLE_CONCEPTS  # gcc10 and clang10 won't compile an asio program with coroutines and concepts
        -DSPDLOG_FMT_EXTERNAL=1
        )
target_link_libraries(config_lib INTERFACE WiseEnum::wise_enum)

target_include_directories(config_lib
        INTERFACE
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND all_libs config_lib)
list(APPEND all_spec_files ${config_spec_files})

set(all_libs "${all_libs}" PARENT_SCOPE)
set(all_spec_files "${all_spec_files}" PARENT_SCOPE)
