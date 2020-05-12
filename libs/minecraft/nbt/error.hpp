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
            invalid_length    = 5,
            list_too_deep     = 6,
            other             = 7,
        };

        enum logic_error
        {
            string_too_large  = 1,
            wrong_value_type  = 2,   // attempt to put wrong type of data into a list
            compound_required = 3,   // attempt to key into a non-compound
            list_required     = 4,   // attempt to index into something that is not a list
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
                case error::invalid_tag: return "Invalid tag";
                case error::incomplete: return "Incomplete parse";
                case error::not_implemented: return "Not implemented";
                case error::compound_too_deep: return "Compund nested too deeply";
                case error::invalid_length: return "Length is invalid (-ve?)";
                case error::list_too_deep: return "List too deep";
                case error::other: return "Other exception during parsing (consult exception)";
                }
                return "Unknown error code: " + std::to_string(ev);
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
                case error::string_too_large: return "String too larg";
                case error::wrong_value_type: return "Wrong value type";
                case error::compound_required: return "Compound required";
                case error::list_required: return "List required";
                }
                return "Unknown error code: " + std::to_string(ev);
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

    // base class of all parsing failures
    struct parse_failure : system_error
    {
    };

    namespace encoding
    {
        struct error
        {
            enum encoding_error
            {
                string_too_long           = 1,
                list_too_long             = 2,
                array_too_long            = 3,
                compound_element_is_empty = 4,
                not_supported             = 5,
            };
        };

        inline auto encoding_error_category() -> error_category const &
        {
            static const struct : error_category
            {
                const char *name() const noexcept override { return "nbt::encoding"; }
                std::string message(int ev) const override
                {
                    switch (static_cast< error::encoding_error >(ev))
                    {
                    case error::string_too_long: return "String too long";
                    case error::list_too_long: return "List too long";
                    case error::array_too_long: return "Array too long";
                    case error::compound_element_is_empty: return "Compount element is empty";
                    case error::not_supported: return "Not supported on this type";
                    }
                    return "unknown error code: " + std::to_string(ev);
                }

            } cat_;
            return cat_;
        }

        inline error_code make_error_code(error::encoding_error e)
        {
            return error_code(static_cast< int >(e), encoding_error_category());
        }

    }   // namespace encoding

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

    template <>
    struct is_error_code_enum< minecraft::nbt::encoding::error::encoding_error > : std::true_type
    {
    };
}   // namespace boost::system

namespace minecraft::nbt
{
    namespace encoding
    {
        struct encode_failure : system_error
        {
            encode_failure(error_code code)
            : system_error(code)
            {
            }

            encode_failure(error_code code, std::string const &what_arg)
            : system_error(code, what_arg)
            {
            }
        };
    }   // namespace encoding

    namespace parsing
    {
        struct parse_failure : system_error
        {
            parse_failure(error_code code)
            : system_error(code)
            {
            }

            parse_failure(error_code code, std::string const &what_arg)
            : system_error(code, what_arg)
            {
            }
        };
    }   // namespace parsing
}   // namespace minecraft::nbt
