
add_subdirectory(bot)
add_subdirectory(gateway)

target_include_directories(gateway_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(region)
add_subdirectory(relay)


set(all_libs ${all_libs} PARENT_SCOPE)
set(all_spec_files ${all_spec_files} PARENT_SCOPE)

