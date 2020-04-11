//
// Created by rhodges on 11/04/2020.
//

#pragma once
#include "net.hpp"

namespace minecraft
{
    struct error
    {
        enum parse_error
        {
            ok = 0,

            invalid_packet,
            not_implemented,
            invalid_varint,
            invalid_string
        };
    };


    inline auto parse_error_category() -> error_category const&
    {
        static struct : error_category
        {
            const char* name() const noexcept {
                return "minecraft parse error";
            }

            std::string message(int value) const
            {
                switch(static_cast<error::parse_error>(value))
                {
                case error::ok:
                    return "ok";
                case error::invalid_packet:
                    return "invalid packet";
                case error::not_implemented:
                    return "not implemented";
                case error::invalid_varint:
                    return "invalid varint";
                case error::invalid_string:
                    return "invalid string";
                }
                return "unknown code: " + std::to_string(value);
            }
        } cat;
        return cat;
    }

    inline auto make_error_code(error::parse_error e) -> error_code
    {
        return error_code(static_cast<int>(e), parse_error_category());
    }
}

namespace boost::system
{
    template<>
    struct is_error_code_enum<minecraft::error::parse_error> : std::true_type {};
}