#include "minecraft/filesystem.hpp"
#include "minecraft/nbt/testing/nbt_data.spec.ipp"
#include "unique_value.hpp"

#include <catch2/catch.hpp>
#include <sys/mman.h>

using namespace minecraft::nbt;

TEST_CASE("minecraft::nbt::value_handle")
{
    SECTION("prints visitation and structure")
    {
        auto v = unique_value();

        v.set("name", "bob");

        std::ostringstream ss;
        ss << pretty_print(v);

        CHECK(ss.str() == "TAG_Compound(''): 1 entries\n"
                          "{\n"
                          " TAG_String('name'): 'bob'\n"
                          "}");
    }

    SECTION("memory use")
    {
        auto sp             = boost::make_shared< impl >();
        auto initial_report = sp->report();
        {
            auto v = unique_value(sp);
            v.set("name", "bob");
            v.set("name", "alice");
            v.set("name", "vera");
            v.set("name", "paul");
            v.set("name", "jobbie");
            CHECK(v.size() == 1);
        }
        auto final_report = sp->report();
        CHECK(initial_report == final_report);
    }

    SECTION("hello_world")
    {
        using namespace minecraft;

        auto size = fs::file_size(testing::hello_world_nbt_filename);
        auto fd   = ::open(testing::hello_world_nbt_filename, O_RDONLY);
        auto addr = ::mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0);
        ::close(fd);
        auto inbuf = std::string_view(reinterpret_cast< const char * >(addr), size);

        error_code ec;
        auto       val  = unique_value();
        auto       next = parse(inbuf.data(), inbuf.data() + inbuf.size(), val, ec);
        CHECK(val.is_compound());

        CHECK(ec.message() == "Success");
        CHECK(next == inbuf.data() + inbuf.size());
        auto output = std::ostringstream();
        output << pretty_print(val);

        const char expected[] = "TAG_Compound(''): 1 entries\n"
                                "{\n"
                                " TAG_Compound('hello world'): 1 entries\n"
                                " {\n"
                                "  TAG_String('name'): 'Bananrama'\n"
                                " }\n"
                                "}";
        CHECK(output.str() == expected);
        ::munmap(addr, size);
    }
}