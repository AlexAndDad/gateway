#pragma once
#include "config.hpp"
#include "error.hpp"
#include "minecraft/types/buffer.hpp"
#include "value.hpp"

namespace minecraft::nbt
{
    namespace encoding
    {
        struct string_too_long : encode_failure
        {
            string_too_long()
            : encode_failure(error::string_too_long)
            {
            }
        };

        struct list_too_long : encode_failure
        {
            list_too_long()
            : encode_failure(error::list_too_long)
            {
            }
        };

        struct array_too_long : encode_failure
        {
            array_too_long()
            : encode_failure(error::array_too_long)
            {
            }
        };

        struct compound_element_is_empty : encode_failure
        {
            compound_element_is_empty(std::string_view name)
            : encode_failure(error::compound_element_is_empty, fmt::format("Compound element '{}' is empty", name))
            {
            }
        };

        struct not_supported : encode_failure
        {
            not_supported(tag_type type)
            : encode_failure(error::not_supported, fmt::format("encoding raw {} is not supported", type))
            {

            }
        };

    }   // namespace encoding

    struct encoder
    {
        compose_buffer &buf;

        void operator()(std::string_view arg, bool with_type = true) const;
        void operator()(compound const &value, bool with_type = true, bool with_terminator = true) const;
        void operator()(list const &value, bool with_type = true) const;
        void operator()(byte_array const &value, bool with_type = true) const;
        void operator()(int_array const &value, bool with_type = true) const;
        void operator()(long_array const &value, bool with_type = true) const;
        void operator()(monostate const &, bool with_type = true) const;
        void operator()(std::int8_t const &x, bool with_type = true) const;
        void operator()(std::int16_t const &x, bool with_type = true) const;
        void operator()(std::uint16_t const &x) const;
        void operator()(std::int32_t const &x, bool with_type = true) const;
        void operator()(std::int64_t const &x, bool with_type = true) const;
        void operator()(float const &x, bool with_type = true) const;
        void operator()(double const &x, bool with_type = true) const;
        void operator()(compound::value_type const &kv) const;
    };

}   // namespace minecraft::nbt