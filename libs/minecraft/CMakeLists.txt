file(GLOB_RECURSE
        in_files
        LIST_DIRECTORIES false
        CONFIGURE_DEPENDS
        "*.in")
list(FILTER in_files EXCLUDE REGEX "test_individual\\.spec\\.cpp\\.in")
foreach(file IN LISTS in_files)
    get_filename_component(fname "${file}" NAME_WLE)
    get_filename_component(fdir "${file}" DIRECTORY)
    file(RELATIVE_PATH relpath "${CMAKE_CURRENT_SOURCE_DIR}" "${fdir}")
    configure_file(${file} "${CMAKE_CURRENT_BINARY_DIR}/${relpath}/${fname}" @ONLY)
endforeach()

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

#
# build the blocks headers
#

add_custom_command(
        OUTPUT blocks/block.hpp
        COMMAND Python3::Interpreter
            ${PROJECT_SOURCE_DIR}/scripts/block_code_gen_1_15_2.py
            ${PROJECT_SOURCE_DIR}/scripts/resources/generated_1_15_2
            ${CMAKE_CURRENT_BINARY_DIR}/
        MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/scripts/resources/generated_1_15_2/reports/blocks.json
        DEPENDS ${PROJECT_SOURCE_DIR}/scripts/block_code_gen_1_15_2.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating v1.15.2 blocks"
        )

list(APPEND minecraft_hdr_files ${generated_hdr_files} blocks/block.hpp)
set(minecraft_spec_files ${minecraft_src_files})
list(FILTER minecraft_spec_files INCLUDE REGEX "^.*.\\.spec\\.[ch]pp$")
list(FILTER minecraft_spec_files EXCLUDE REGEX "^.*.main\\.spec\\.cpp$")
list(FILTER minecraft_src_files EXCLUDE REGEX "^.*.\\.spec\\.[ch]pp$")

add_library(minecraft_lib ${minecraft_src_files} ${minecraft_hdr_files})
set(minecraft_dependencies
        config_lib
        polyfill_lib
        function2::function2
        Boost::boost Boost::filesystem Boost::iostreams Boost::system
        Boost::json
        Boost::webclient
        Threads::Threads
        OpenSSL::Crypto OpenSSL::SSL
        spdlog::spdlog
        utf8cpp
        ZLIB::ZLIB
        Eigen3::Eigen)
target_link_libraries(minecraft_lib PUBLIC "${minecraft_dependencies}")

target_include_directories(minecraft_lib
        PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND all_libs config_lib minecraft_lib)
list(APPEND all_spec_files ${minecraft_spec_files})

# compose per-file tests

add_executable(minecraft_test_1by1 main.spec.cpp)
target_link_libraries(minecraft_test_1by1 PUBLIC Catch2::Catch2)

get_directory_property(parent_dir PARENT_DIRECTORY)
foreach(file IN LISTS minecraft_spec_files)
    string(REPLACE "${parent_dir}/" "" fname1 "${file}")
    string(REPLACE "/" "__" fname2 "${fname1}")
    string(REPLACE ".spec.cpp" "_test" test_exe_name "${fname2}")
    set(this_test_src "${file}")

    add_executable("${test_exe_name}" main.spec.cpp "${this_test_src}")
    target_link_libraries("${test_exe_name}" PUBLIC minecraft_lib)
    target_link_libraries("${test_exe_name}" PUBLIC Catch2::Catch2)

    configure_file(test_individual.spec.cpp.in "test_individual__${test_exe_name}.spec.cpp" @ONLY)
    target_sources(minecraft_test_1by1 PRIVATE "test_individual__${test_exe_name}.spec.cpp")
    add_dependencies(minecraft_test_1by1 "${test_exe_name}")
endforeach()

set(all_libs ${all_libs} PARENT_SCOPE)
set(all_spec_files ${all_spec_files} PARENT_SCOPE)
