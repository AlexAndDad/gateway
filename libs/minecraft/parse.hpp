#pragma once

#include "minecraft/incomplete.hpp"
#include "minecraft/parse_error.hpp"
#include "types.hpp"

#include <boost/endian.hpp>
#include <boost/mp11/tuple.hpp>
#include <cstdint>
#include <string>

namespace minecraft
{
    //
    // fundamental types
    //

    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, double &target, error_code &ec)
    {
        using value_type          = std::decay_t< decltype(target) >;
        constexpr auto byte_count = sizeof(value_type);

        if (ec.failed())
        {
            if (std::distance(first, last) < byte_count)
            {
                ec = error::incomplete_parse;
            }
            else
            {
                using namespace boost::endian;
                endian_buffer< order::big, value_type, 8 * byte_count, align::yes > buffer;
                std::copy(first, first + byte_count, buffer.data());
                target = buffer.value();
                first += byte_count;
            }
        }
        return first;
    }

    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, float &target, error_code &ec)
    {
        using value_type          = std::decay_t< decltype(target) >;
        constexpr auto byte_count = sizeof(value_type);

        if (ec.failed())
        {
            if (std::distance(first, last) < byte_count)
            {
                ec = error::incomplete_parse;
            }
            else
            {
                using namespace boost::endian;
                endian_buffer< order::big, value_type, 8 * byte_count, align::yes > buffer;
                std::copy(first, first + byte_count, buffer.data());
                target = buffer.value();
                first += byte_count;
            }
        }
        return first;
    }

    template < typename Integral, typename ValueType = std::decay_t< Integral > >
    auto parse(const_buffer_iterator first, const_buffer_iterator last, Integral &target, error_code &ec)
        -> std::enable_if_t< std::is_integral_v< ValueType >, const_buffer_iterator >
    {
        using namespace boost::endian;

        using unsigned_type       = std::make_unsigned_t< ValueType >;
        constexpr auto byte_count = sizeof(unsigned_type);

        if (not ec.failed())
        {
            if (std::distance(first, last) < byte_count)
                ec = error::incomplete_parse;
            else
            {
                using namespace boost::endian;
                endian_buffer< order::big, unsigned_type, 8 * byte_count, align::yes > buffer;
                std::copy(first, first + byte_count, buffer.data());
                target = static_cast< Integral >(buffer.value());
                first += byte_count;
            }
        }
        return first;
    }

    template < class Iter, class SignedType >
    auto parse_var(Iter first, Iter last, SignedType &result, error_code &ec) -> Iter
    {
        using value_type    = SignedType;
        using unsigned_type = std::make_unsigned_t< value_type >;

        if (not ec.failed())
        {
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
        }
        return first;
    }

    inline
    auto parse(const_buffer_iterator first, const_buffer_iterator last, std::uint8_t &target, error_code &ec) -> const_buffer_iterator
    {
        if (not ec.failed())
        {
            if (first == last)
                ec = error::incomplete_parse;
            else
            {
                target = static_cast< std::uint8_t >(*first++);
                ec.clear();
            }
        }
        return first;
    }

    template < class Enum >
    auto parse(const_buffer_iterator first, const_buffer_iterator last, Enum &target, error_code &ec)
        -> std::enable_if_t< std::is_enum_v< Enum >, const_buffer_iterator >
    {
        if (not ec.failed())
        {
            auto underlying = std::underlying_type_t< Enum >();
            first           = parse(first, last, underlying, ec);
            if (not ec.failed())
                target = static_cast< Enum >(underlying);
        }
        return first;
    }

    inline auto parse(const_buffer_iterator        first,
                      const_buffer_iterator        last,
                      std::vector< std::uint8_t > &target,
                      error_code &                 ec,
                      std::int32_t                 byte_limit = 65536) -> const_buffer_iterator
    {
        auto ret = first;

        auto err = [&ec, ret](auto code) {
            ec = code;
            return ret;
        };

        if (not ec.failed())
        {
            auto size = std::int32_t();
            first     = parse_var(first, last, size, ec);
            if (not ec.failed())
            {
                auto available = static_cast< std::size_t >(std::distance(first, last));
                if (size > available)
                    return err(error::incomplete_parse);

                if (size > byte_limit)
                    return err(error::invalid_array);

                target.clear();
                target.reserve(size);
                target.insert(target.end(), first, first + size);
                first += size;
                ret = first;
            }
        }
        return ret;
    }

    template < class Underlying >
    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator second, var< Underlying > &target, error_code &ec)
    {
        return parse_var(first, second, static_cast< Underlying & >(target), ec);
    }

    template < class Enum >
    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator second, var_enum< Enum > &target, error_code &ec)
    {
        if (not ec.failed())
        {
            using underlying = std::underlying_type_t< Enum >;
            auto accum       = underlying();
            first            = parse_var(first, second, accum, ec);
            if (not ec.failed())
                target = static_cast< Enum >(accum);
        }
        return first;
    }

    template < class T >
    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, std::optional< T > &opt, error_code &ec)
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

    template < class... Args >
    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, std::tuple< Args &... > args, error_code &ec)
    {
        auto ret = first;
        boost::mp11::tuple_for_each(args, [&](auto &target) { first = parse(first, last, target, ec); });
        if (not ec.failed())
            return ret = first;
        return ret;
    }

    template < std::size_t Limit >
    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, varchar< Limit > &result, error_code &ec)
    {
        auto ret     = first;

        auto size    = std::int32_t();
        first = parse_var(first, last, size, ec);
        if (not ec.failed())
        {
            constexpr auto byte_limit = Limit * 4;
            auto available = std::distance(first, last);
            if (size > byte_limit)
                ec = error::invalid_string;
            else if(size > available)
                ec = error::incomplete_parse;
            else
            {
                result.append(first, first + size);
                first += size;
            }
        }
        if (not ec.failed())
            ret = first;
        return ret;
    }

    inline
    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, std::u16string& result, error_code& ec)
    {
        auto ret = first;
        while(not ec.failed())
        {
            std::uint16_t length;
            first = parse(first, last, length, ec);
            if (ec.failed()) break;

            auto available = std::distance(first, last);
            if (available < length * 2) {
                ec = error::incomplete_parse;
                break;
            }

            result.resize(length);
            std::memcpy(result.data(), first, length * 2);
            first += length * 2;

            for (auto& elem : result)
                boost::endian::big_to_native_inplace(elem);

            ret = first;
            break;
        }
        return ret;
    }

}   // namespace minecraft