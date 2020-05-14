#include "encoder.hpp"

#include <boost/endian/buffers.hpp>
#include <spdlog/spdlog.h>

namespace minecraft::nbt
{
    void encoder::operator()(std::string_view arg, bool with_type) const
    {
        if (arg.size() > max_string_length)
            throw encoding::string_too_long();

        if (with_type)
            buf.push_back(String);

        (*this)(static_cast< std::uint16_t >(arg.size()));
        buf.insert(buf.end(), arg.begin(), arg.end());
    }

    void encoder::operator()(const compound &cmp, bool with_type, bool with_terminator) const
    try
    {
        if (with_type)
            buf.push_back(Compound);

        for (auto &entry : cmp)
            (*this)(entry);

        if (with_terminator)
            buf.push_back(End);
    }
    catch (encoding::encode_failure &f)
    {
        std::throw_with_nested(encoding::encode_failure(f.code(), "While encoding Compound"));
    }

    void encoder::operator()(const list &l, bool with_type) const
    {
        visit(
            [&]< class Vec >(Vec const &vec) {
                const auto size = vec.size();
                if (size > max_list_length)
                    throw encoding::list_too_long();

                if (with_type)
                    buf.push_back(List);

                if (vec.size() == 0)
                {
                    buf.push_back(End);
                    (*this)(static_cast< std::int32_t >(vec.size()), false);
                }
                else
                {
                    try
                    {
                        buf.push_back(to_tag_v< typename Vec::value_type >);

                        (*this)(static_cast< std::int32_t >(vec.size()), false);
                        for (auto &entry : vec)
                            (*this)(entry, false);
                    }
                    catch (encoding::encode_failure &f)
                    {
                        std::throw_with_nested(encoding::encode_failure(f.code(), "While encoding List"));
                    }
                }
            },
            l.as_variant());
    }

    void encoder::operator()(const byte_array &arr, bool with_type) const
    {
        if (arr.size() > max_array_length)
            throw encoding::array_too_long();

        if (with_type)
            buf.push_back(Byte_Array);

        (*this)(static_cast< std::int32_t >(arr.size()), false);
        buf.insert(buf.end(), arr.begin(), arr.end());
    }

    void encoder::operator()(const int_array &arr, bool with_type) const
    {
        if (arr.size() > max_array_length)
            throw encoding::array_too_long();

        if (with_type)
            buf.push_back(Int_Array);

        (*this)(static_cast< std::int32_t >(arr.size()), false);
        for (auto &x : arr)
            (*this)(x);
    }

    void encoder::operator()(const long_array &arr, bool with_type) const
    {
        if (arr.size() > max_array_length)
            throw encoding::array_too_long();

        if (with_type)
            buf.push_back(Long_Array);

        (*this)(static_cast< std::int32_t >(arr.size()), false);
        for (auto &x : arr)
            (*this)(x);
    }

    void encoder::operator()(const monostate &, bool with_type) const
    {
        if (with_type)
            buf.push_back(End);
    }
    void encoder::operator()(const int8_t &x, bool with_type) const
    {
        if (with_type)
            buf.push_back(Byte);

        buf.push_back(x);
    }
    void encoder::operator()(const std::int16_t &x, bool with_type) const
    {
        if (with_type)
            buf.push_back(Short);

        boost::endian::big_int16_buf_at acc(x);
        buf.insert(buf.end(), acc.data(), acc.data() + sizeof(std::int16_t));
    }
    void encoder::operator()(const std::uint16_t &x) const
    {
        boost::endian::big_uint16_buf_at acc(x);
        buf.insert(buf.end(), acc.data(), acc.data() + sizeof(std::uint16_t));
    }
    void encoder::operator()(const std::int32_t &x, bool with_type) const
    {
        if (with_type)
            buf.push_back(Int);

        boost::endian::big_int32_buf_at acc(x);
        buf.insert(buf.end(), acc.data(), acc.data() + sizeof(std::int32_t));
    }
    void encoder::operator()(const std::int64_t &x, bool with_type) const
    {
        if (with_type)
            buf.push_back(Long);

        boost::endian::big_int64_buf_at acc(x);
        buf.insert(buf.end(), acc.data(), acc.data() + sizeof(std::int64_t));
    }

    void encoder::operator()(const double &x, bool with_type) const
    {
        if (with_type)
            buf.push_back(Double);

        boost::endian::big_float64_buf_at acc(x);
        buf.insert(buf.end(), acc.data(), acc.data() + sizeof(double));
    }
    void encoder::operator()(const float &x, bool with_type) const
    {
        if (with_type)
            buf.push_back(Float);

        boost::endian::big_float32_buf_at acc(x);
        buf.insert(buf.end(), acc.data(), acc.data() + sizeof(float));
    }

    void encoder::operator()(const compound::value_type &kv) const
    {
        visit(
            [&]< class Type >(Type const &val) {

                buf.push_back(to_tag_v< Type >);

                if constexpr (std::is_same_v< Type, monostate >)
                    throw encoding::compound_element_is_empty(kv.first);
                else
                    try
                    {
                        (*this)(kv.first, false);
                        (*this)(val, false);
                    }
                    catch (encoding::encode_failure &f)
                    {
                        std::throw_with_nested(
                            encoding::encode_failure(f.code(), fmt::format("While encoding element '{}'", kv.first)));
                    }
            },
            kv.second.as_variant());
    }

    void encoder::operator()(tag_type arg) const
    {
        buf.push_back(arg);
    }

}   // namespace minecraft::nbt