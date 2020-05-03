#include "minecraft/filesystem.hpp"
#include "minecraft/nbt/testing/nbt_data.spec.ipp"
#include "minecraft/nbt/value.hpp"
#include "minecraft/net.hpp"
#include "minecraft/types/buffer.hpp"

#include <boost/core/ignore_unused.hpp>
#include <catch2/catch.hpp>
#include <string_view>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

TEST_CASE("minecraft::nbt::value_impl")
{
    SECTION("hello_world")
    {
        using namespace minecraft;

        auto size = fs::file_size(nbt::testing::hello_world_nbt_filename);
        auto fd   = ::open(nbt::testing::hello_world_nbt_filename, O_RDONLY);
        auto addr = ::mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0);
        ::close(fd);
        auto inbuf = std::string_view(reinterpret_cast< const char * >(addr), size);

        error_code ec;
        auto       val  = nbt::value();
        auto       next = nbt::parse(inbuf.data(), inbuf.data() + inbuf.size(), val, ec);

        CHECK(ec.message() == "Success");
        CHECK(next == inbuf.data() + inbuf.size());
        auto output = std::string();
        pretty_print(output, val);

        const char expected[] = R"__text(TAG_Compound('hello world'): 1 entry
{
 TAG_String('name'): 'Bananrama'
}
)__text";
        CHECK(output == expected);
        ::munmap(addr, size);
    }
/*
    SECTION("bigtest")
    {
        using namespace minecraft;

        auto size = fs::file_size(nbt::testing::bigtest_nbt_filename);
        auto fd   = ::open(nbt::testing::bigtest_nbt_filename, O_RDONLY);
        auto addr = ::mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0);
        ::close(fd);
        auto inbuf = std::string_view(reinterpret_cast< const char * >(addr), size);

        error_code ec;
        auto       val  = nbt::value_impl();
        auto       ctx  = nbt::parse_context(inbuf.data());
        auto       next = nbt::parse(inbuf.data(), inbuf.data() + inbuf.size(), val, ctx);

        CHECK(ec.message() == "Success");
        CHECK(next == inbuf.data() + inbuf.size());
        auto output = std::string();
        pretty_print(output, val, inbuf.data());

        const char expected[] = R"__text(TAG_Compound('hello world'): 1 entry
{
 TAG_String('name'): 'Bananrama'
}
)__text";
        CHECK(output == expected);
        ::munmap(addr, size);
    }
    */
}