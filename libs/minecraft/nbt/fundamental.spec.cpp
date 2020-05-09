#include "minecraft/filesystem.hpp"
#include "minecraft/nbt/fundamental.hpp"
#include "minecraft/nbt/testing/nbt_data.spec.ipp"

#include <catch2/catch.hpp>
#include <fcntl.h>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace minecraft::nbt;

namespace
{
    struct test_handler final : parse_handler
    {
        std::string      buffer;
        std::size_t      indent_;
        std::string_view current_key_;

        auto indent() const -> std::string { return std::string(indent_, ' '); }
        auto current_key() -> std::string_view
        {
            return std::exchange(current_key_, std::string_view());
        }

        void on_compound_start() override
        {
            buffer += fmt::format("{0}Compound('{1}')\n{0}{{\n", indent(), current_key());
            current_key_ = std::string_view();
            ++indent_;
        }

        void on_key(std::string_view value) override { current_key_ = value; }

        void on_string(std::string_view value) override
        {
            buffer += fmt::format("{0}String('{1}'): '{2}'\n", indent(), current_key(), value);
        }

        virtual void on_byte(std::int8_t value) override
        {
            buffer += fmt::format("{0}Byte('{1}'): {2}\n", indent(), current_key(), std::int32_t(value));
        }
        virtual void on_short(std::int16_t value) override
        {
            buffer += fmt::format("{0}Short('{1}'): {2}\n", indent(), current_key(), value);
        }
        virtual void on_int(std::int32_t value) override
        {
            buffer += fmt::format("{0}Int('{1}'): {2}\n", indent(), current_key(), value);
        }
        virtual void on_long(std::int64_t value) override
        {
            buffer += fmt::format("{0}Long('{1}'): {2}\n", indent(), current_key(), value);
        }
        virtual void on_float(float value) override
        {
            buffer += fmt::format("{0}Float('{1}'): {2}\n", indent(), current_key(), value);
        }
        virtual void on_double(double value) override
        {
            buffer += fmt::format("{0}Double('{1}'): {2}\n", indent(), current_key(), value);
        }

        virtual void on_list(tag_type tag, std::size_t length) override
        {
            buffer += fmt::format(
                "{0}List('{1}'): {3} of {2}\n{0}{{\n", indent(), current_key(), wise_enum::to_string(tag), length);
            ++indent_;
        }
        virtual void on_list_end(std::size_t length) override
        {
            --indent_;
            buffer += fmt::format("{}}} ({} entries)\n", indent(), length);
        }

        virtual void on_integral_list(tag_type tag, minecraft::const_byte_span extent) override {
            buffer += fmt::format("{0}{1}('{2}')(", indent(), wise_enum::to_string(tag), current_key());
            const char* sep = "";
            switch(tag)
            {
            default:
                assert(!"logic error");
            case tag_type::Byte_Array:
                for (auto& b : extent)
                {
                    buffer += fmt::format("{}{:02x}", sep, b);
                    sep = " ";
                }
                break;
            case tag_type::Int_Array:
                for (auto first = extent.begin() ; first < extent.end() ; first+=4)
                {
                    auto buf = boost::endian::big_int32_buf_at ();
                    std::memcpy(buf.data(), first, 4);
                    buffer += fmt::format("{}{:08x}", sep, buf.value());
                    sep = " ";
                }
                break;
            case tag_type::Long_Array:
                for (auto first = extent.begin() ; first < extent.end() ; first+=8)
                {
                    auto buf = boost::endian::big_int64_buf_at ();
                    std::memcpy(buf.data(), first, 8);
                    buffer += fmt::format("{}{:016x}", sep, buf.value());
                    sep = " ";
                }
                break;
            }
            buffer += ")\n";
        }

        void on_end(std::size_t elements) override
        {
            if (indent_)
            {
                --indent_;
                buffer += fmt::format("{}}} ({} elements)\n", indent(), elements);
            }
            else
            {
                buffer += "End";
            }
        }
    };
}   // namespace
TEST_CASE("minecraft::nbt::fundamental")
{
    auto handler = test_handler();

    SECTION("tag")
    {
        auto check_tag = [&handler](tag_type expected) {
            INFO("" << wise_enum::to_string(expected));
            auto data  = std::array< char, 2 > { '\xff', static_cast< char >(expected) };
            auto first = data.data() + 1;
            auto last  = first + 1;
            auto tag   = tag_type();
            auto ctx   = parse_context(handler);
            auto next  = parse(first, last, tag, ctx);
            CHECK(tag == expected);
            CHECK(ctx.error().message() == "Success");
            CHECK(next == last);

            first = data.data();
            last  = first + 1;
            next  = parse(first, last, tag, ctx);
            CHECK(ctx.error().message() == "Invalid tag");
            CHECK(next == first);

            ctx.error().clear();
            first = data.data();
            last  = first;
            next  = parse(first, last, tag, ctx);
            CHECK(ctx.error().message() == "Incomplete parse");
            CHECK(next == first);
        };

        check_tag(tag_type::End);
        check_tag(tag_type::Byte);
        check_tag(tag_type::Short);
        check_tag(tag_type::Int);
        check_tag(tag_type::Long);
        check_tag(tag_type::Float);
        check_tag(tag_type::Double);
        check_tag(tag_type::Byte_Array);
        check_tag(tag_type::String);
        check_tag(tag_type::List);
        check_tag(tag_type::Compound);
        check_tag(tag_type::Int_Array);
        check_tag(tag_type::Long_Array);
    }
/*
    SECTION("string_atom")
    {
        const char data[] = "      \x00\x0dHello, World!";

        // successful parse
        auto first  = data + 6;
        auto last   = data + 21;
        auto ctx    = parse_context(data, handler);
        auto target = string_atom {};
        auto next   = parse(first, last, target, ctx);
        CHECK(ctx.error().message() == "Success");
        CHECK(next == last);
        CHECK(to_string(target, ctx.storage()) == "Hello, World!");

        // existing error condition
        ctx.error().clear();
        ctx.error(error::invalid_tag);
        next = parse(first, last, target, ctx);
        CHECK(ctx.error().message() == "Invalid tag");
        CHECK(next == first);

        ctx.error().clear();
        last -= 1;
        next = parse(first, last, target, ctx);
        CHECK(ctx.error().message() == "Incomplete parse");
        CHECK(next == first);
    }
*/
    SECTION("hello_world.nbt")
    {
        using namespace minecraft;

        auto size = fs::file_size(nbt::testing::hello_world_nbt_filename);
        auto fd   = ::open(nbt::testing::hello_world_nbt_filename, O_RDONLY);
        auto addr = ::mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0);
        ::close(fd);
        auto inbuf = std::string_view(reinterpret_cast< const char * >(addr), size);

        error_code ec;
        auto       ctx  = parse_context(handler);
        auto       next = nbt::parse_value(inbuf.data(), inbuf.data() + inbuf.size(), ctx);

        CHECK(ec.message() == "Success");
        CHECK(next == inbuf.data() + inbuf.size());

        const char expected[] = R"__text(Compound('hello world')
{
 String('name'): 'Bananrama'
} (1 elements)
)__text";
        CHECK(handler.buffer == expected);
        ::munmap(addr, size);
    }

    SECTION("bigtest")
    {
        using namespace minecraft;

        auto size = fs::file_size(nbt::testing::bigtest_nbt_filename);
        auto fd   = ::open(nbt::testing::bigtest_nbt_filename, O_RDONLY);
        auto addr = ::mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0);
        ::close(fd);
        auto inbuf = std::string_view(reinterpret_cast< const char * >(addr), size);

        auto ctx  = nbt::parse_context(handler);
        auto next = nbt::parse_value(inbuf.data(), inbuf.data() + inbuf.size(), ctx);

        CHECK(ctx.error().message() == "Success");
        auto       output     = handler.buffer;
        const char expected[] = "Compound('Level')\n"
            "{\n"
            " Long('longTest'): 9223372036854775807\n"
            " Short('shortTest'): 32767\n"
            " String('stringTest'): 'HELLO WORLD THIS IS A TEST STRING ÅÄÖ!'\n"
            " Float('floatTest'): 0.49823147\n"
            " Int('intTest'): 2147483647\n"
            " Compound('nested compound test')\n"
            " {\n"
            "  Compound('ham')\n"
            "  {\n"
            "   String('name'): 'Hampus'\n"
            "   Float('value'): 0.75\n"
            "  } (2 elements)\n"
            "  Compound('egg')\n"
            "  {\n"
            "   String('name'): 'Eggbert'\n"
            "   Float('value'): 0.5\n"
            "  } (2 elements)\n"
            " } (2 elements)\n"
            " List('listTest (long)'): 5 of Long\n"
            " {\n"
            "  Long(''): 11\n"
            "  Long(''): 12\n"
            "  Long(''): 13\n"
            "  Long(''): 14\n"
            "  Long(''): 15\n"
            " } (5 entries)\n"
            " List('listTest (compound)'): 2 of Compound\n"
            " {\n"
            "  Compound('')\n"
            "  {\n"
            "   String('name'): 'Compound tag #0'\n"
            "   Long('created-on'): 1264099775885\n"
            "  } (2 elements)\n"
            "  Compound('')\n"
            "  {\n"
            "   String('name'): 'Compound tag #1'\n"
            "   Long('created-on'): 1264099775885\n"
            "  } (2 elements)\n"
            " } (2 entries)\n"
            " Byte('byteTest'): 127\n"
            " Byte_Array('byteArrayTest (the first 1000 values of (n*n*255+n*7)%100, starting with n=0 (0, 62, 34, 16, 8, ...))')(00 3e 22 10 08 0a 16 2c 4c 12 46 20 04 56 4e 50 5c 0e 2e 58 28 02 4a 38 30 32 3e 54 10 3a 0a 48 2c 1a 12 14 20 36 56 1c 50 2a 0e 60 58 5a 02 18 38 62 32 0c 54 42 3a 3c 48 5e 1a 44 14 52 36 24 1c 1e 2a 40 60 26 5a 34 18 06 62 00 0c 22 42 08 3c 16 5e 4c 44 46 52 04 24 4e 1e 5c 40 2e 26 28 34 4a 06 30 00 3e 22 10 08 0a 16 2c 4c 12 46 20 04 56 4e 50 5c 0e 2e 58 28 02 4a 38 30 32 3e 54 10 3a 0a 48 2c 1a 12 14 20 36 56 1c 50 2a 0e 60 58 5a 02 18 38 62 32 0c 54 42 3a 3c 48 5e 1a 44 14 52 36 24 1c 1e 2a 40 60 26 5a 34 18 06 62 00 0c 22 42 08 3c 16 5e 4c 44 46 52 04 24 4e 1e 5c 40 2e 26 28 34 4a 06 30 00 3e 22 10 08 0a 16 2c 4c 12 46 20 04 56 4e 50 5c 0e 2e 58 28 02 4a 38 30 32 3e 54 10 3a 0a 48 2c 1a 12 14 20 36 56 1c 50 2a 0e 60 58 5a 02 18 38 62 32 0c 54 42 3a 3c 48 5e 1a 44 14 52 36 24 1c 1e 2a 40 60 26 5a 34 18 06 62 00 0c 22 42 08 3c 16 5e 4c 44 46 52 04 24 4e 1e 5c 40 2e 26 28 34 4a 06 30 00 3e 22 10 08 0a 16 2c 4c 12 46 20 04 56 4e 50 5c 0e 2e 58 28 02 4a 38 30 32 3e 54 10 3a 0a 48 2c 1a 12 14 20 36 56 1c 50 2a 0e 60 58 5a 02 18 38 62 32 0c 54 42 3a 3c 48 5e 1a 44 14 52 36 24 1c 1e 2a 40 60 26 5a 34 18 06 62 00 0c 22 42 08 3c 16 5e 4c 44 46 52 04 24 4e 1e 5c 40 2e 26 28 34 4a 06 30 00 3e 22 10 08 0a 16 2c 4c 12 46 20 04 56 4e 50 5c 0e 2e 58 28 02 4a 38 30 32 3e 54 10 3a 0a 48 2c 1a 12 14 20 36 56 1c 50 2a 0e 60 58 5a 02 18 38 62 32 0c 54 42 3a 3c 48 5e 1a 44 14 52 36 24 1c 1e 2a 40 60 26 5a 34 18 06 62 00 0c 22 42 08 3c 16 5e 4c 44 46 52 04 24 4e 1e 5c 40 2e 26 28 34 4a 06 30 00 3e 22 10 08 0a 16 2c 4c 12 46 20 04 56 4e 50 5c 0e 2e 58 28 02 4a 38 30 32 3e 54 10 3a 0a 48 2c 1a 12 14 20 36 56 1c 50 2a 0e 60 58 5a 02 18 38 62 32 0c 54 42 3a 3c 48 5e 1a 44 14 52 36 24 1c 1e 2a 40 60 26 5a 34 18 06 62 00 0c 22 42 08 3c 16 5e 4c 44 46 52 04 24 4e 1e 5c 40 2e 26 28 34 4a 06 30 00 3e 22 10 08 0a 16 2c 4c 12 46 20 04 56 4e 50 5c 0e 2e 58 28 02 4a 38 30 32 3e 54 10 3a 0a 48 2c 1a 12 14 20 36 56 1c 50 2a 0e 60 58 5a 02 18 38 62 32 0c 54 42 3a 3c 48 5e 1a 44 14 52 36 24 1c 1e 2a 40 60 26 5a 34 18 06 62 00 0c 22 42 08 3c 16 5e 4c 44 46 52 04 24 4e 1e 5c 40 2e 26 28 34 4a 06 30 00 3e 22 10 08 0a 16 2c 4c 12 46 20 04 56 4e 50 5c 0e 2e 58 28 02 4a 38 30 32 3e 54 10 3a 0a 48 2c 1a 12 14 20 36 56 1c 50 2a 0e 60 58 5a 02 18 38 62 32 0c 54 42 3a 3c 48 5e 1a 44 14 52 36 24 1c 1e 2a 40 60 26 5a 34 18 06 62 00 0c 22 42 08 3c 16 5e 4c 44 46 52 04 24 4e 1e 5c 40 2e 26 28 34 4a 06 30 00 3e 22 10 08 0a 16 2c 4c 12 46 20 04 56 4e 50 5c 0e 2e 58 28 02 4a 38 30 32 3e 54 10 3a 0a 48 2c 1a 12 14 20 36 56 1c 50 2a 0e 60 58 5a 02 18 38 62 32 0c 54 42 3a 3c 48 5e 1a 44 14 52 36 24 1c 1e 2a 40 60 26 5a 34 18 06 62 00 0c 22 42 08 3c 16 5e 4c 44 46 52 04 24 4e 1e 5c 40 2e 26 28 34 4a 06 30 00 3e 22 10 08 0a 16 2c 4c 12 46 20 04 56 4e 50 5c 0e 2e 58 28 02 4a 38 30 32 3e 54 10 3a 0a 48 2c 1a 12 14 20 36 56 1c 50 2a 0e 60 58 5a 02 18 38 62 32 0c 54 42 3a 3c 48 5e 1a 44 14 52 36 24 1c 1e 2a 40 60 26 5a 34 18 06 62 00 0c 22 42 08 3c 16 5e 4c 44 46 52 04 24 4e 1e 5c 40 2e 26 28 34 4a 06 30)\n"
            " Double('doubleTest'): 0.4931287132182315\n"
            "} (11 elements)\n";
        REQUIRE(output == expected);
        CHECK(next == inbuf.data() + inbuf.size());
        ::munmap(addr, size);
    }
}