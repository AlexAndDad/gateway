#pragma once

#include "minecraft/incomplete.hpp"
#include "minecraft/parse_error.hpp"
#include "types.hpp"

#include <boost/mp11/tuple.hpp>
#include <cstdint>
#include <string>
#include <wise_enum.h>

namespace minecraft
{
    template < class Iter , class SignedType>
    auto parse_var(Iter first, Iter last, SignedType &result, error_code &ec) -> Iter
    {
        using value_type    = SignedType;
        using unsigned_type = std::make_unsigned_t< value_type >;

        std::size_t   count       = 0;
        unsigned_type accumulator = 0;
        Iter          i           = first;

        while (i != last)
        {
            auto x = static_cast< unsigned_type >(static_cast< std::uint8_t >(*i++));
            accumulator |= (x & 0x7fu) << (7 * count);
            ++count;
            if (not(x & 0x80u))
            {
                ec.clear();
                result = accumulator;
                return i;
            }
            if (count >= max_var_encoded_bytes< SignedType >())
            {
                ec = error::invalid_varint;
                return first;
            }
        }
        ec = error::incomplete_parse;
        return first;
    }

    template < class Iter >
    auto parse(Iter first, Iter last, std::uint8_t &target, error_code &ec) -> Iter
    {
        if (first == last)
            ec = error::incomplete_parse;
        else
        {
            target = static_cast< std::uint8_t >(*first++);
            ec.clear();
        }
        return first;
    }

    template < class Iter, class Enum >
    auto parse(Iter first, Iter last, Enum &target, error_code &ec) -> std::enable_if_t< std::is_enum_v< Enum >, Iter >
    {
        auto underlying = std::underlying_type_t<Enum>();
        auto i = parse(first, last, underlying, ec);
        if (not ec.failed())
            target = static_cast<Enum>(underlying);
        return i;
    }

    template < class Iter >
    auto parse(Iter first, Iter last, std::uint16_t &target, error_code &ec) -> Iter
    {
        if (std::distance(first, last) < 2)
            ec = error::incomplete_parse;
        else
        {
            auto convert = [](char c) {
                return static_cast< std::uint16_t >(std::uint16_t(static_cast< std::uint8_t >(c)));
            };
            auto h = convert(*first++) << 8;
            auto l = convert(*first++);
            target = h | l;
            ec.clear();
        }
        return first;
    }

    template < class Iter >
    auto
    parse(Iter first, Iter last, std::vector< std::uint8_t > &target, error_code &ec, std::int32_t byte_limit = 65536)
        -> Iter
    {
        auto size    = std::int32_t();
        auto current = parse_var(first, last, size, ec);
        if (ec.failed())
            return first;

        if (size > byte_limit)
        {
            ec = error::invalid_array;
            return first;
        }

        target.clear();
        target.reserve(size);
        while (current != last && size)
        {
            --size;
            target.push_back(*current++);
        }

        if (size)
        {
            ec = error::incomplete_parse;
            return first;
        }

        ec.clear();
        return current;
    }



    template < class Iter, class Underlying >
    Iter parse(Iter first, Iter second, var< Underlying > &target, error_code &ec)
    {
        return parse_var(first, second, static_cast< Underlying & >(target), ec);
    }

    template < class Iter, class Enum >
    Iter parse(Iter first, Iter second, var_enum< Enum > &target, error_code &ec)
    {
        using underlying = std::underlying_type_t< Enum >;
        auto accum       = underlying();
        auto i           = parse_var(first, second, accum, ec);
        if (!ec.failed())
            target = static_cast< Enum >(accum);
        return i;
    }

    template<class Iter, class T>
    Iter parse(Iter first, Iter last, std::optional<T>& opt, error_code& ec)
    {
        auto present = std::uint8_t();
        auto current = parse(first, last, present, ec);
        if (ec.failed())
            return first;
        if (present)
        {
            opt.emplace(T());
            current = parse(current, last, *opt, ec);
            if (ec.failed())
            {
                opt.reset();
                return first;
            }
        }
        else
        {
            opt.reset();
        }
        return current;
    }

    template < class Iter, class... Args >
    Iter parse(Iter first, Iter last, std::tuple< Args &... > args, error_code &ec)
    {
        ec.clear();
        auto current = first;
        boost::mp11::tuple_for_each(args, [&](auto &target) {
            if (not ec.failed())
                current = parse(current, last, target, ec);
        });
        if (ec.failed())
            return first;
        else
            return current;
    }

    template < class Iter, std::size_t Limit >
    Iter parse(Iter first, Iter last, varchar< Limit > &result, error_code &ec)
    {
        auto size    = std::int32_t();
        auto current = parse_var(first, last, size, ec);

        constexpr auto byte_limit = Limit * 4;
        if (size > byte_limit)
        {
            ec = error::invalid_string;
        }
        else
        {
            result.reserve(size);
            while (current != last && size)
            {
                --size;
                result.push_back(*current++);
            }

            if (size)
                ec = error::incomplete_parse;
        }

        if (ec.failed())
        {
            result.clear();
            return first;
        }
        else
        {
            return current;
        }
    }

}   // namespace minecraft