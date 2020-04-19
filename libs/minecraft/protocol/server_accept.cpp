#include "server_accept.hpp"

#include "minecraft/utils/print_variant.hpp"

#include <fmt/ostream.h>

namespace minecraft::protocol
{
    boost::uuids::uuid server_accept_op_base::generate_uuid()
    {
        auto gen    = boost::uuids::random_generator_mt19937();
        auto result = gen();
        return result;
    }

    server_accept_state::server_accept_state(std::string const &              server_id,
                                             std::optional<minecraft::security::private_key> pk,
                                             int                              compression_threshold)
    : server_id(std::move(server_id))
    , server_key(std::move(pk))
    , compression_threshold(compression_threshold)
    {
    }

    auto operator<<(std::ostream &os, server_accept_state const &arg) -> std::ostream &
    {
        const char *type      = "none";
        std::vector<std::uint8_t> key_bytes;
        if (arg.server_key)
        {
            type = "private";
            key_bytes = arg.server_key->private_asn1();
            if (key_bytes.empty())
            {
                type      = "public";
                key_bytes = arg.server_key->private_asn1();
            }
        }

        fmt::print(os,
                   "[server_accept_state [server_id {}] [compression {}] [server_key {} {:n}] [server_packet {}] "
                   "[client_packet {}]]",
                   arg.server_id,
                   arg.compression_threshold,
                   type,
                   spdlog::to_hex(key_bytes),
                   utils::print_variant(arg.server_packet),
                   utils::print_variant(arg.client_packet));

        return os;
    }

}   // namespace minecraft::protocol