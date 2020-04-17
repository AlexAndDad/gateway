
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_STANDARD 20)
    add_executable(bot main.cpp)
    target_link_libraries(bot minecraft_lib)
endif ()
