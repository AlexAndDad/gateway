#include "minecraft/server/encryption_request.hpp"

#include "minecraft/hexdump.hpp"

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <random>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/bin_to_hex.h>

namespace minecraft::server
{
    std::ostream &operator<<(std::ostream &os, encryption_request const &arg)
    {
        fmt::print(os,
                   "[packet [server] [login {}] [server_id {}] [public_key {:n}] [verify_token {:n}]]",
                   wise_enum::to_string(arg.id()),
                   arg.server_id,
                   spdlog::to_hex(arg.public_key),
                   spdlog::to_hex(arg.verify_token));
        return os;
    }

    error_code &validate(encryption_request const &request, security::private_key &pkey, error_code &ec)
    {
        pkey.public_key_from_asn1(net::buffer(request.public_key), ec);
        return ec;
    }

    namespace
    {
        void generate_verify_token(std::vector< std::uint8_t > &tok)
        {
            static thread_local auto eng = [] {
                auto rng = std::random_device();
                auto seq = std::seed_seq { rng(), rng(), rng(), rng(), rng() };
                auto eng = std::default_random_engine(seq);
                return eng;
            }();

            auto dist = std::uniform_int_distribution< std::uint32_t >(0, 255);

            tok.resize(4);
            std::generate(tok.begin(), tok.end(), [&] { return dist(eng); });
        }
    }

    void prepare(encryption_request &req, std::string const& server_id, minecraft::security::private_key const &ppk)
    {
        generate_verify_token(req.verify_token);
        req.server_id = server_id;
        req.public_key = ppk.public_asn1();
    }

}   // namespace minecraft::server