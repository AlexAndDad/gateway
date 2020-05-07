#pragma once

#include "minecraft/incomplete.hpp"
#include "minecraft/net.hpp"
#include "minecraft/parse_error.hpp"
#include "types/buffer.hpp"

//#include "types.hpp"

#include <boost/endian.hpp>
#include <boost/mp11/tuple.hpp>
#include <cstdint>
#include <string>

namespace minecraft
{
    //
    // fundamental types
    //

    auto parse(const_buffer_iterator first, const_buffer_iterator last, double &target, error_code &ec)
        -> const_buffer_iterator;

    auto parse(const_buffer_iterator first, const_buffer_iterator last, float &target, error_code &ec)
        -> const_buffer_iterator;

    auto parse(const_buffer_iterator first, const_buffer_iterator last, bool &target, error_code &ec)
        -> const_buffer_iterator;

    template < typename Integral, typename ValueType = std::decay_t< Integral > >
    auto parse(const_buffer_iterator first, const_buffer_iterator last, Integral &target, error_code &ec)
        -> std::enable_if_t< std::is_integral_v< ValueType > and not std::is_same_v< Integral, bool >,
                             const_buffer_iterator >
    {
        using namespace boost::endian;

        using unsigned_type       = std::make_unsigned_t< ValueType >;
        constexpr auto byte_count = sizeof(unsigned_type);

        if (not ec.failed())
        {
            if (std::distance(first, last) < static_cast< std::ptrdiff_t >(byte_count))
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

    template < class Integral, class U = Integral >
    constexpr int max_var_encoded_bytes()
    {
        static_assert(not std::is_same_v< Integral, U >);
        return 0;
    };

    template <>
    constexpr int max_var_encoded_bytes< std::int32_t >()
    {
        return 5;
    };

    template <>
    constexpr int max_var_encoded_bytes< std::int64_t >()
    {
        return 10;
    };

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

    /*
    inline auto parse(const_buffer_iterator first, const_buffer_iterator last, std::uint8_t &target, error_code &ec)
        -> const_buffer_iterator
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
*/
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

    auto parse(const_buffer_iterator        first,
               const_buffer_iterator        last,
               std::vector< std::uint8_t > &target,
               error_code &                 ec,
               std::int32_t                 byte_limit = 65536) -> const_buffer_iterator;

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

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, std::u16string &result, error_code &ec);

    // parse std::size_t quantity of T into std::vector.
    template < class T >
    const_buffer_iterator parse(const_buffer_iterator                           first,
                                const_buffer_iterator                           last,
                                std::tuple< std::vector< T > &, std::size_t & > result,
                                error_code &                                    ec)
    {
        if (not ec.failed())
        {
            auto &vec = std::get< 0 >(result);
            vec.resize(std::get< 1 >(result));

            for (auto &item : vec)
            {
                first = parse(first, last, item, ec);
                if (ec.failed())
                {
                    break;
                }
            }
        }
        return first;
    }

}   // namespace minecraft