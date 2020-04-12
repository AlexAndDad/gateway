//
// Created by rhodges on 11/04/2020.
//

#pragma once

#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <string>
#include <string_view>
#include <vector>

namespace gateway
{

    inline
    auto temp_hex(std::uint8_t val) -> std::string_view
    {
        thread_local char hexdigits[2];
        static const char xlate[] = "0123456789abcdef";
        hexdigits[0] = xlate[val >> 4];
        hexdigits[1] = xlate[val & 0xf];
        return std::string_view(hexdigits, 2);
    }

    template<class Word>
    struct hexdump_state;


    template<>
    struct hexdump_state<unsigned char>
    {
        explicit hexdump_state(std::size_t columns)
        : column_width(columns)
        {}

        static char safe_char(unsigned char c)
        {
            if (std::isprint(c))
                return static_cast<char>(c);
            else
                return '.';
        }

        template<class Handler>
        void spacing(Handler handler)
        {
            if (visual.empty())
            {
                if (row_count)
                    handler("\n");
            }
            else
            {
                if (visual.size() % block_width == 0)
                    handler(" ");
            }
        }

        template<class Handler>
        void flush_line(Handler handler)
        {
            assert(!visual.empty());

            while (visual.size() < column_width)
            {
                spacing(handler);
                visual += ' ';
                handler("   ");
            }

            handler(" ");
            handler(visual);
            visual.clear();
            ++row_count;
        }

        template<class Handler>
        void put(unsigned char c, Handler handler)
        {
            spacing(handler);
            handler(temp_hex(c));
            handler(" ");
            visual += safe_char(c);
            if(visual.size() >= column_width)
                flush_line(handler);
        }

        template<class Handler>
        void flush(Handler h)
        {
            if (!visual.empty())
                flush_line(h);
            row_count = 0;
        }

        std::size_t row_count = 0;
        std::size_t block_width = 4;
        std::size_t column_width = 16;
        std::string visual;
        char hexdigits[2] = {};
    };

    template<> struct hexdump_state<char> : hexdump_state<unsigned char> {
        using hexdump_state<unsigned char>::hexdump_state;
    };


    template<class Container>
    struct hexdump
    {
        using iterator = decltype(std::cbegin(std::declval<Container>()));
        using value_type = typename std::iterator_traits<iterator>::value_type;

        explicit hexdump(Container const& c, std::size_t columns = 16)
        : c_(c)
        , columns_(columns)
        {}

        template<class Stream>
        void operator()(Stream& stream) const
        {
            auto handler = [&stream](std::string_view s)
            {
                stream << s;
            };

            auto state = hexdump_state<value_type>(columns_);
            for (auto&& e : c_)
                state.put(e, handler);
            state.flush(handler);
        }

        friend auto operator<<(std::ostream& os, hexdump h) -> std::ostream&
        {
            h(os);
            return os;
        }

        Container const& c_;
        std::size_t columns_;
    };

    inline
    std::string hexstring(std::vector<std::uint8_t> const& data)
    {
        std::string result;
        result.reserve(data.size() * 2);
        for (auto b : data)
        {
            auto t = temp_hex(b);
            result.append(t.begin(), t.end());
        }
        return result;
    }

}