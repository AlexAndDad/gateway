#include "nvp.hpp"
#include "minecraft/filesystem.hpp"
#include "minecraft/testing/chunk_data.spec.ipp"
#include "polyfill/explain.hpp"

#include <catch2/catch.hpp>
#include <span>
#include <sys/mman.h>

using namespace minecraft;

TEST_CASE("minecraft::nbt::nvp", "[minecraft][minecraft::nbt][minecraft::nbt::nvp]")
{
    SECTION("height maps") {
        auto size = fs::file_size(testing::chunk_data_bin_filename);
        auto fd   = ::open(testing::chunk_data_bin_filename, O_RDONLY);
        auto addr = ::mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0);
        ::close(fd);

        auto source = std::span<const char>(reinterpret_cast<const char*>(addr) + 11, size - 11);

        auto nvp = nbt::nvp<nbt::Compound>();
        auto next = source.data();
        CHECK_NOTHROW(next = parse(source.data(), source.data() + source.size(), nvp));
        CHECK((next - source.data()) == 622);
        auto &[name, c0] = nvp;
        CHECK(name == "");
        REQUIRE_NOTHROW(c0.at("WORLD_SURFACE"));
        REQUIRE_NOTHROW(c0.at("MOTION_BLOCKING"));
        REQUIRE(c0.at("WORLD_SURFACE").is(nbt::Int_Array));
        REQUIRE(c0.at("MOTION_BLOCKING").is(nbt::Int_Array));
        CHECK(c0.at("WORLD_SURFACE").get_int_array().size() == 36);
        CHECK(c0.at("MOTION_BLOCKING").get_int_array().size() == 36);


        ::munmap(addr, size);
    }
}
