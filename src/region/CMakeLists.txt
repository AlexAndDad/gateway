


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

add_library(region_lib ${src_files} ${hdr_files})
target_link_libraries(region_lib PUBLIC minecraft_lib)

add_executable(region main.cpp)
target_link_libraries(region PUBLIC region_lib)
target_link_libraries(region PUBLIC Boost::program_options)

set(all_libs ${all_libs} PARENT_SCOPE)
set(all_spec_files ${all_spec_files} PARENT_SCOPE)
