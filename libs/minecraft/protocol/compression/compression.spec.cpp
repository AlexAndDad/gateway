#include "minecraft/net.hpp"
#include "minecraft/protocol/compression.hpp"
#include "minecraft/types.hpp"

#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <catch2/catch.hpp>
#include <sstream>

using namespace std::literals;
using namespace minecraft;

auto to_val = [](char c) {
    switch (c)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return static_cast< unsigned char >(c) - '0';
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
        return (static_cast< unsigned char >(c) - 'a') + 10;
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
        return (static_cast< unsigned char >(c) - 'A') + 10;
    default:
        throw std::runtime_error("garbage");
    }
};

auto to_bytes(std::string_view s) -> std::string
{
    auto result = std::string();
    result.reserve(s.size() / 2);
    std::size_t pos = 0;
    while (pos + 1 < s.size())
    {
        auto ss = s.substr(pos, 2);
        pos += 3;
        unsigned char val = to_val(ss[0]) << 4;
        val |= to_val(ss[1]);
        result.push_back(char(val));
    }
    return result;
}

TEST_CASE("minecraft::protocol::compression")
{
    using namespace minecraft;
    namespace io = boost::iostreams;

    auto zipped = to_bytes(
        "78 9c 6d 93 db 6e d4 30 10 86 dd 2b 84 10 a7 96 53 11 42 3c 41 2f b8 e2 b6 bb b4 50 21 44 d5 56 5a 71 39 6b "
        "cf 26 6e 6c 4f f0 21 db f0 36 7d a5 3e 11 4e 1c 24 3b bb 17 2b 79 3e cf fc 33 fb 3b f3 e8 cb 31 f0 5a 62 87 "
        "1a 8d 3f a1 16 cd 85 e9 e2 91 6c cf 5e e5 57 5a 1a 5c 11 09 f6 3e a7 eb 20 95 58 91 6d 16 68 78 cd de ed dc "
        "5d 4a de c0 1d ee b9 39 0f d6 00 47 f6 36 bf 01 fe 27 48 8b 17 96 4c d9 7e 2c f9 4e c8 5e 17 43 41 83 0b 8b "
        "20 66 c9 11 2f e3 8f 7d dc 91 58 a0 f7 68 ff 4f 55 54 71 a2 e6 5c ba 9a 1d 15 96 98 d3 2b 90 8a bd d9 91 ba "
        "de 92 15 e5 3c 8d 54 ea cc a0 ee 4b 8d 01 2f 69 cb 0e 73 b8 51 fd a5 ac 58 e1 bf 33 b2 c5 eb 06 15 fa b9 01 "
        "42 82 26 23 5c 29 d2 92 f5 a0 d8 cb 9c 55 35 38 3f 33 44 c1 5f bc 8a 8f 37 2b f6 32 b6 29 98 af f1 cc 88 72 "
        "fc c4 3e 97 6f 38 bc 37 18 3f 9c 5d d9 8c 3a b4 c3 3f 9e 8d 10 dd e5 e0 90 7d 28 54 ee 5a 45 16 4f 95 5a 48 "
        "d2 e8 ca af c1 b5 b0 35 2b 19 fb db d2 ff 41 7e 1f df 84 28 84 c0 77 be 1e 8b 28 86 17 38 de 67 e9 0d fd a6 "
        "c0 9e 39 0f fe 44 21 74 f8 0d 34 b2 c3 31 6e 15 f4 bf 0c fe 94 26 78 bc ff 94 92 b6 a0 9a 08 97 7a 2a 72 5b "
        "a9 f3 78 03 4a a5 f8 f9 18 73 25 f5 3a 81 a7 29 41 f5 79 be 90 1d a6 38 35 1d 76 8d 83 f5 79 ce 9a c0 e7 12 "
        "ad ac f2 16 35 59 37 69 3c 1e c1 6d d0 ed 74 14 96 5a f6 22 1d 41 43 85 5f 11 94 2f c8 4d dc 16 f3 70 f0 24 "
        "21 04 5f bb 83 d4 47 d3 fa 47 74 db 4d e9 60 a4 06 e5 e2 d2 89 89 0c 0e a1 4d 39 69 96 4d 5c a2 25 84 aa f6 "
        "13 b8 0d 66 dc ac 58 73 34 02 1f 77 d6 05 8b 13 fc 07 dc de a3 30");

    SECTION("compression works")
    {
        auto        uncompressed = std::string();
        std::string uncompressed2;
        std::string rezipped;

        struct net_buffer_source : io::source
        {
            net_buffer_source(net::const_buffer data)
            : data_(data)
            {
            }

            std::streamsize read(char *s, std::streamsize n)
            {
                if (auto available = data_.size())
                {
                    auto bytes_transferred = net::buffer_copy(
                        net::mutable_buffer(s, std::min(static_cast< std::size_t >(n), available)), data_);
                    data_ += bytes_transferred;
                    return static_cast< std::streamsize >(bytes_transferred);
                }
                return -1;
            }

            net::const_buffer data_;
        };

        io::filtering_streambuf< io::input > in;
        try
        {
            in.push(io::zlib_decompressor());
            in.push(net_buffer_source(net::buffer(zipped)));
            io::copy(in, io::back_inserter(uncompressed));
        }
        catch (std::exception &e)
        {
            FAIL(e.what());
        }
        CHECK(uncompressed.size() == 1158);
        CHECK((unsigned char)(uncompressed.at(0)) == 7);

        minecraft::protocol::compression::inflate_impl inflator;
        uncompressed2.resize(uncompressed.size());
        auto ec = inflator(net::buffer(zipped), net::buffer(uncompressed2));
        CHECK(ec.value() == 0);
        CHECK(uncompressed2 == uncompressed);
    }

    SECTION("round trip - multiple through one pair")
    {
        auto initials = std::vector {
            "the cat sat on the mat."s,
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."s,
            "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum."s,
            "Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of \"de Finibus Bonorum et Malorum\" (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, \"Lorem ipsum dolor sit amet..\", comes from a line in section 1.10.32."s,
            ""s,
            "1"s,
            "foo"s
        };

        protocol::compression::deflate_impl deflator_;
        protocol::compression::inflate_impl inflator_;

        for (std::size_t i = 0; i < initials.size(); ++i)
        {
            INFO("iteration " << i);
            auto &initial      = initials[i];
            auto  compressed   = compose_buffer();
            auto  decompressed = std::string();

            auto ec = deflator_(net::buffer(initial), compressed);
            REQUIRE(ec == error_code());

            decompressed.resize(initial.size());
            ec = inflator_(net::buffer(compressed), net::buffer(decompressed));
            REQUIRE(ec == error_code());
            REQUIRE(decompressed == initial);
        }
    }
}
