#include "minecraft/filesystem.hpp"
#include "minecraft/nbt/testing/nbt_data.spec.ipp"
#include "polyfill/hexdump.hpp"
#include "value.hpp"
#include "polyfill/explain.hpp"

#include <catch2/catch.hpp>
#include <sys/mman.h>

using namespace minecraft::nbt;

TEST_CASE("[minecraft::nbt::value]")
{
    /*
    SECTION("prints visitation and structure")
    {
        auto v = value();

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
*/
    SECTION("hello_world")
    {
        using namespace minecraft;

        auto size = fs::file_size(testing::hello_world_nbt_filename);
        auto fd   = ::open(testing::hello_world_nbt_filename, O_RDONLY);
        auto addr = ::mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0);
        ::close(fd);
        auto inbuf = std::string_view(reinterpret_cast< const char * >(addr), size);

        error_code ec;
        auto       val  = value();
        auto       next = parse(inbuf.data(), inbuf.data() + inbuf.size(), val, ec);
        CHECK(val.is(Compound));

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

    SECTION("bigtest")
    {
        using namespace minecraft;

        auto size = fs::file_size(testing::bigtest_nbt_filename);
        auto fd   = ::open(testing::bigtest_nbt_filename, O_RDONLY);
        compose_buffer inbuf(size);
        ::read(fd, inbuf.data(), inbuf.size());
        ::close(fd);

        error_code ec;
        auto       val  = value();
        auto       next = parse(inbuf.data(), inbuf.data() + inbuf.size(), val, ec);
        CHECK(ec.message() == "Success");
        CHECK(val.is(Compound));
        CHECK(next == inbuf.data() + inbuf.size());

        auto output = std::ostringstream();
        output << pretty_print(val);

        const char expected[] = "TAG_Compound(''): 1 entries\n"
                                "{\n"
                                " TAG_Compound('Level'): 11 entries\n"
                                " {\n"
                                "  TAG_Byte_Array('byteArrayTest (the first 1000 values of (n*n*255+n*7)%100, starting "
                                "with n=0 (0, 62, 34, 16, 8, ...))'): [1000 bytes]\n"
                                "  TAG_Byte('byteTest'): 127\n"
                                "  TAG_Double('doubleTest'): 0.4931287132182315\n"
                                "  TAG_List('listTest (compound)'): 2 entries\n"
                                "  {\n"
                                "   TAG_Compound(''): 2 entries\n"
                                "   {\n"
                                "    TAG_Long('created-on'): 1264099775885\n"
                                "    TAG_String('name'): 'Compound tag #0'\n"
                                "   }\n"
                                "   TAG_Compound(''): 2 entries\n"
                                "   {\n"
                                "    TAG_Long('created-on'): 1264099775885\n"
                                "    TAG_String('name'): 'Compound tag #1'\n"
                                "   }\n"
                                "  }\n"
                                "  TAG_List('listTest (long)'): 5 entries\n"
                                "  {\n"
                                "   TAG_Long(''): 11\n"
                                "   TAG_Long(''): 12\n"
                                "   TAG_Long(''): 13\n"
                                "   TAG_Long(''): 14\n"
                                "   TAG_Long(''): 15\n"
                                "  }\n"
                                "  TAG_Compound('nested compound test'): 2 entries\n"
                                "  {\n"
                                "   TAG_Compound('egg'): 2 entries\n"
                                "   {\n"
                                "    TAG_Float('value'): 0.5\n"
                                "    TAG_String('name'): 'Eggbert'\n"
                                "   }\n"
                                "   TAG_Compound('ham'): 2 entries\n"
                                "   {\n"
                                "    TAG_Float('value'): 0.75\n"
                                "    TAG_String('name'): 'Hampus'\n"
                                "   }\n"
                                "  }\n"
                                "  TAG_Int('intTest'): 2147483647\n"
                                "  TAG_Float('floatTest'): 0.49823147\n"
                                "  TAG_String('stringTest'): 'HELLO WORLD THIS IS A TEST STRING ÅÄÖ!'\n"
                                "  TAG_Short('shortTest'): 32767\n"
                                "  TAG_Long('longTest'): 9223372036854775807\n"
                                " }\n"
                                "}";
        CHECK(output.str() == expected);

        //
        // round trip
        //

        compose_buffer comp;
        CHECK_NOTHROW(compose(val, comp));
        CHECK(comp.size() == size);
        auto val2 = value();
        parse(comp.data(), comp.data() + comp.size(), val2, ec);
        CHECK(ec.message() == "Success");
        CHECK(val2 == val);

        SECTION("poison")
        {
            auto inbuf_bad = inbuf;

            // overflow the length og 'hampus'
            inbuf_bad[0xA3] = 0xFF;
            inbuf_bad[0xA4] = 0xFF;
            try
            {
                auto v = value();
                parse(inbuf_bad.data(), inbuf_bad.data() + inbuf_bad.size(), v);
                FAIL();
            }
            catch(...)
            {
                auto s = fmt::format("{}", polyfill::explain().whats());
                CHECK(s == "While parsing value: Incomplete parse\n"
                           "While parsing Compound Element of type Compound: Incomplete parse\n"
                           "While parsing value for 'Level': Incomplete parse\n"
                           "While parsing atom Compound: Incomplete parse\n"
                           "While parsing Compound: Incomplete parse\n"
                           "While parsing Compound Element of type Compound: Incomplete parse\n"
                           "While parsing value for 'nested compound test': Incomplete parse\n"
                           "While parsing atom Compound: Incomplete parse\n"
                           "While parsing Compound: Incomplete parse\n"
                           "While parsing Compound Element of type Compound: Incomplete parse\n"
                           "While parsing value for 'ham': Incomplete parse\n"
                           "While parsing atom Compound: Incomplete parse\n"
                           "While parsing Compound: Incomplete parse\n"
                           "While parsing Compound Element of type String: Incomplete parse\n"
                           "While parsing value for 'name': Incomplete parse\n"
                           "While parsing atom String: Incomplete parse\n"
                           "While parsing String: Incomplete parse\n"
                           "Incomplete parse");
            }

        }
    }
}