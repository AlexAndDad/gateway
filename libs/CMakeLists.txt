#
# all spec files
#

set(libs_spec_files)
set(all_libs)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

add_subdirectory(config)
target_include_directories(config_lib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}")
add_subdirectory(polyfill)
target_include_directories(polyfill_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}")
add_subdirectory(minecraft)
target_include_directories(minecraft_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}")

set(all_libs ${all_libs} PARENT_SCOPE)
set(all_spec_files ${all_spec_files} PARENT_SCOPE)
