file(GLOB_RECURSE BOT_SRC_FILES CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE BOT_HDR_FILES CONFIGURE_DEPENDS "*.hpp")

add_executable(bot ${BOT_SRC_FILES} ${BOT_HDR_FILES})
target_link_libraries(bot minecraft_lib)
target_include_directories(bot PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
