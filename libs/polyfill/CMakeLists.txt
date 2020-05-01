file(GLOB_RECURSE
        polyfill_src_files
        LIST_DIRECTORIES false
        CONFIGURE_DEPENDS
        "*.cpp")
file(GLOB_RECURSE
        polyfill_generated_hdr_files
        LIST_DIRECTORIES false
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_BINARY_DIR}/*.hpp")
file(GLOB_RECURSE
        polyfill_hdr_files
        LIST_DIRECTORIES false
        CONFIGURE_DEPENDS
        "*.hpp")
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

set(all_libs "${all_libs}" PARENT_SCOPE)
set(all_spec_files "${all_spec_files}" PARENT_SCOPE)
