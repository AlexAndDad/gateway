#
# all spec files
#

set(libs_spec_files)
set(all_libs)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(config)
add_subdirectory(polyfill)
add_subdirectory(minecraft)

set(all_libs ${all_libs} PARENT_SCOPE)
set(all_spec_files ${all_spec_files} PARENT_SCOPE)
