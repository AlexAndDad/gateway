add_executable(all_test main.spec.cpp ${all_spec_files})
target_link_libraries(all_test PUBLIC ${all_libs})
target_link_libraries(all_test PUBLIC Catch2::Catch2)


