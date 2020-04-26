#include "minecraft/parse.hpp"

namespace minecraft
{
    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, double &target, error_code &ec)
    {
        using value_type          = std::decay_t< decltype(target) >;
        constexpr auto byte_count = sizeof(value_type);

        if (ec.failed())
        {
            if (std::distance(first, last) < static_cast< std::ptrdiff_t >(byte_count))
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

    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, float &target, error_code &ec)
    {
        using value_type          = std::decay_t< decltype(target) >;
        constexpr auto byte_count = sizeof(value_type);

        if (ec.failed())
        {
            if (std::distance(first, last) < static_cast< std::ptrdiff_t >(byte_count))
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

    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, bool &target, error_code &ec)
    {
        if (!ec)
        {
            if (first == last)
                ec = error::incomplete_parse;
            else
            {
                std::uint8_t val;
                last   = parse(first, last, val, ec);
                target = val ? true : false;
            }
        }
        return first;
    }

    auto parse(const_buffer_iterator        first,
               const_buffer_iterator        last,
               std::vector< std::uint8_t > &target,
               error_code &                 ec,
               std::int32_t                 byte_limit) -> const_buffer_iterator
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
                auto available = std::distance(first, last);
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

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, std::u16string &result, error_code &ec)
    {
        auto ret = first;
        while (not ec.failed())
        {
            std::uint16_t length;
            first = parse(first, last, length, ec);
            if (ec.failed())
                break;

            auto available = std::distance(first, last);
            if (available < length * 2)
            {
                ec = error::incomplete_parse;
                break;
            }

            result.resize(length);
            std::memcpy(result.data(), first, length * 2);
            first += length * 2;

            for (auto &elem : result)
                boost::endian::big_to_native_inplace(elem);

            ret = first;
            break;
        }
        return ret;
    }

}   // namespace minecraft