#pragma once
#include "minecraft/net.hpp"

namespace minecraft::nbt
{
    struct error
    {
        enum parse_error
        {
            invalid_tag       = 1,
            incomplete        = 2,
            not_implemented   = 3,
            compound_too_deep = 4,
            invalid_length = 5,
        };

        enum logic_error
        {
            string_too_large = 1,
        };
    };

    inline auto parse_error_category() -> error_category const &
    {
        static const struct : error_category
        {
            const char *name() const noexcept override { return "nbt::parse_error"; }
            std::string message(int ev) const override
            {
                switch (static_cast< error::parse_error >(ev))
                {
                case error::invalid_tag:
                    return "Invalid tag";
                case error::incomplete:
                    return "Incomplete parse";
                case error::not_implemented:
                    return "Not implemented";
                case error::compound_too_deep:
                    return "Compund nested too deeply";
                case error::invalid_length:
                    return "Length is invalid (-ve?)";
                }
                return "unknown error code: " + std::to_string(ev);
            }

        } cat_;
        return cat_;
    }

    inline auto logic_error_category() -> error_category const &
    {
        static const struct : error_category
        {
            const char *name() const noexcept override { return "nbt::logic_error"; }
            std::string message(int ev) const override
            {
                switch (static_cast< error::logic_error >(ev))
                {
                case error::string_too_large:
                    return "String too larg";
                }
                return "unknown error code: " + std::to_string(ev);
            }

        } cat_;
        return cat_;
    }

    inline error_code make_error_code(error::parse_error e)
    {
        return error_code(static_cast< int >(e), parse_error_category());
    }

    inline error_code make_error_code(error::logic_error e)
    {
        return error_code(static_cast< int >(e), logic_error_category());
    }
}   // namespace minecraft::nbt

namespace boost::system
{
    template <>
    struct is_error_code_enum< minecraft::nbt::error::parse_error > : std::true_type
    {
    };
    template <>
    struct is_error_code_enum< minecraft::nbt::error::logic_error > : std::true_type
    {
    };
}   // namespace boost::system
