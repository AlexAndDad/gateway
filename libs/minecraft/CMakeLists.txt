file(GLOB_RECURSE
        minecraft_src_files
        LIST_DIRECTORIES false
        CONFIGURE_DEPENDS
        "*.cpp")

file(GLOB_RECURSE
        minecraft_generated_hdr_files
        LIST_DIRECTORIES false
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_BINARY_DIR}/*.hpp")

file(GLOB_RECURSE
        minecraft_hdr_files
        LIST_DIRECTORIES false
        CONFIGURE_DEPENDS
        "*.hpp")
list(APPEND minecraft_hdr_files ${generated_hdr_files})
set(minecraft_spec_files ${minecraft_src_files})
list(FILTER minecraft_spec_files INCLUDE REGEX "^.*.\\.spec\\.cpp$")
list(FILTER minecraft_spec_files EXCLUDE REGEX "^.*.main\\.spec\\.cpp$")
list(FILTER minecraft_src_files EXCLUDE REGEX "^.*.\\.spec\\.cpp$")

add_library(minecraft_lib ${minecraft_src_files} ${minecraft_hdr_files})
set(minecraft_dependencies
        config_lib
        polyfill_lib
        Boost::boost Boost::filesystem Boost::iostreams Boost::system
        Boost::json
        Boost::webclient
        Threads::Threads
        OpenSSL::Crypto OpenSSL::SSL
        spdlog::spdlog
        utf8cpp
        ZLIB::zlib
        Eigen3::Eigen)
target_link_libraries(minecraft_lib PUBLIC "${minecraft_dependencies}")
target_compile_definitions(minecraft_lib PUBLIC "-DSPDLOG_FMT_EXTERNAL=1")
target_include_directories(minecraft_lib
        PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND all_libs config_lib minecraft_lib)
list(APPEND all_spec_files ${minecraft_spec_files})

# compose per-file tests

get_directory_property(parent_dir PARENT_DIRECTORY)
foreach(file IN LISTS minecraft_spec_files)
    string(REPLACE "${parent_dir}/" "" fname1 "${file}")
    string(REPLACE "/" "__" fname2 "${fname1}")
    string(REPLACE ".spec.cpp" "_test" fname3 "${fname2}")
    add_executable("${fname3}" main.spec.cpp "${file}")
    target_link_libraries("${fname3}" PUBLIC "${minecraft_dependencies}")
    target_link_libraries("${fname3}" PUBLIC Catch2::Catch2)
endforeach()

set(all_libs ${all_libs} PARENT_SCOPE)
set(all_spec_files ${all_spec_files} PARENT_SCOPE)
