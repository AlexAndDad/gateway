#include "../../../libs/config/filesystem.hpp"
#include "config/test_data.hpp"

#include <catch2/catch.hpp>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#define ZLIB_CONST
#include <zlib.h>

void add_buffer_to_vector(std::vector<char> &vector, const char *buffer, uLongf length) {
    for (int character_index = 0; character_index < length; character_index++) {
        char current_character = buffer[character_index];
        vector.push_back(current_character);
    }
}

int compress_vector(std::vector<char> source, std::vector<char> &destination) {
    unsigned long source_length = source.size();
    uLongf destination_length = compressBound(source_length);

    char *destination_data = (char *) malloc(destination_length);
    if (destination_data == nullptr) {
        return Z_MEM_ERROR;
    }

    Bytef *source_data = (Bytef *) source.data();
    int return_value = compress2((Bytef *) destination_data, &destination_length, source_data, source_length,
                                 Z_BEST_COMPRESSION);
    add_buffer_to_vector(destination, destination_data, destination_length);
    free(destination_data);
    return return_value;
}

int decompress(std::string_view source, std::vector<char> &destination) {
    unsigned long source_length = source.size();
    uLongf destination_length = compressBound(source_length);

    char *destination_data = (char *) malloc(destination_length);
    if (destination_data == nullptr) {
        return Z_MEM_ERROR;
    }

    Bytef *source_data = (Bytef *) source.data();
    int return_value = uncompress((Bytef *) destination_data, &destination_length, source_data, source.size());
    add_buffer_to_vector(destination, destination_data, destination_length);
    free(destination_data);
    return return_value;
}

void add_string_to_vector(std::vector<char> &uncompressed_data,
                          const char *my_string) {
    int character_index = 0;
    while (true) {
        char current_character = my_string[character_index];
        uncompressed_data.push_back(current_character);

        if (current_character == '\00') {
            break;
        }

        character_index++;
    }
}

TEST_CASE("UK.PAK")
{
    /*
    using namespace config;

    fs::path path = fs::path(test_data_dir());
    path /= "uk.pak";
    auto fd = ::open(path.native().c_str(), O_RDONLY);
    REQUIRE(fd >= 0);
    struct stat buf;
    ::fstat(fd, &buf);

    auto mapping = ::mmap(nullptr, buf.st_size, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd, 0);
    REQUIRE(mapping != nullptr);

    auto zipped_view = std::string_view(reinterpret_cast<const char*>(mapping), buf.st_size);
    std::vector<char> target;

    decompress(zipped_view, target);







    ::munmap(mapping, buf.st_size);
    ::close(fd);
     */
}