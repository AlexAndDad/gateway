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
            huge_frame,
            invalid_varint,
            invalid_array,
            invalid_string,
            invalid_enum,
            invalid_protocol,
            incomplete_parse,
            unexpected_packet,
            invalid_nbt_tag,
        };

        // errors in the minecraft protocol login phase
        enum login_error
        {
            shared_secret_failure = 1,
            not_rsa_key = 2,
            decryption_failure = 3,
        };

        enum protocol_error
        {
            invalid_name = 1,
        };
    };

    inline auto parse_error_category() -> error_category const &
    {
        static struct : error_category
        {
            const char *name() const noexcept { return "minecraft parse error"; }

            std::string message(int value) const
            {
                switch (static_cast< error::parse_error >(value))
                {
                case error::ok:
                    return "ok";
                case error::invalid_packet:
                    return "invalid packet";
                case error::not_implemented:
                    return "not implemented";
                case error::huge_frame:
                    return "huge frame";
                case error::invalid_varint:
                    return "invalid varint";
                case error::invalid_array:
                    return "invalid array";
                case error::invalid_protocol:
                    return "invalid protocol version";
                case error::invalid_string:
                    return "invalid string";
                case error::invalid_enum:
                    return "invalid enum";
                case error::incomplete_parse:
                    return "incomplete parse";
                case error::unexpected_packet:
                    return "unexpected packet";
                case error::invalid_nbt_tag:
                    return "invalid nbt tag";
                }
                return "unknown code: " + std::to_string(value);
            }
        } cat;
        return cat;
    }

    inline auto login_error_category() -> error_category const &
    {
        static struct : error_category
        {
            const char *name() const noexcept { return "minecraft login error"; }

            std::string message(int value) const
            {
                switch (static_cast< error::login_error >(value))
                {
                case error::login_error::shared_secret_failure:
                    return "shared secret failure";
                case error::login_error::not_rsa_key:
                    return "not rsa key";
                case error::login_error::decryption_failure:
                    return "decryption failure";
                }
                return "unknown code: " + std::to_string(value);
            }
        } cat;
        return cat;
    }

    inline auto protocol_error_category() -> error_category const &
    {
        static struct : error_category
        {
            const char *name() const noexcept { return "minecraft protocol error"; }

            std::string message(int value) const
            {
                switch (static_cast< error::protocol_error >(value))
                {
                case error::protocol_error::invalid_name:
                    return "invalid player name";
                }
                return "unknown code: " + std::to_string(value);
            }
        } cat;
        return cat;
    }

    inline auto make_error_code(error::parse_error e) -> error_code
    {
        return error_code(static_cast< int >(e), parse_error_category());
    }

    inline auto make_error_code(error::login_error e) -> error_code
    {
        return error_code(static_cast< int >(e), parse_error_category());
    }

    inline auto make_error_code(error::protocol_error e) -> error_code
    {
        return error_code(static_cast< int >(e), protocol_error_category());
    }
}   // namespace minecraft

namespace boost::system
{
    template <>
    struct is_error_code_enum< minecraft::error::parse_error > : std::true_type
    {
    };

    template <>
    struct is_error_code_enum< minecraft::error::login_error > : std::true_type
    {
    };

    template <>
    struct is_error_code_enum< minecraft::error::protocol_error > : std::true_type
    {
    };
}   // namespace boost::system