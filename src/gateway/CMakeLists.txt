


file(GLOB_RECURSE src_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        *.cpp)
file(GLOB_RECURSE generated_hdr_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_BINARY_DIR}/*.hpp)
file(GLOB_RECURSE hdr_files LIST_DIRECTORIES false CONFIGURE_DEPENDS
        *.hpp)
list(APPEND hdr_files ${generated_hdr_files})
set(spec_files ${src_files})
list(FILTER spec_files INCLUDE REGEX "^.*.\\.spec\\.cpp$")
list(APPEND all_spec_files ${spec_files})
list(FILTER src_files EXCLUDE REGEX "^.*.\\.spec\\.cpp$")
list(FILTER src_files EXCLUDE REGEX "^.*main\\.cpp$")

add_library(gateway_lib ${src_files} ${hdr_files})
target_link_libraries(gateway_lib PUBLIC minecraft_lib Boost::json)

add_executable(gateway main.cpp)
target_link_libraries(gateway PUBLIC gateway_lib)

set(all_libs ${all_libs} PARENT_SCOPE)
set(all_spec_files ${all_spec_files} PARENT_SCOPE)
