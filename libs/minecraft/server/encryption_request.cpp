#include "minecraft/server/encryption_request.hpp"

#include "minecraft/hexdump.hpp"

#include <random>

namespace minecraft::server
{
    std::ostream &operator<<(std::ostream &os, encryption_request const &arg)
    {
        os << "encryption_request.server_id=" << arg.server_id;
        os << "\nencryption_request.public_key=" << hexstring(arg.public_key);
        os << "\nencryption_request.verify_token=" << hexstring(arg.verify_token);
        return os;
    }

    error_code& validate(encryption_request const& request, security::private_key& pkey, error_code& ec)
    {
        pkey.public_key_from_asn1(net::buffer(request.public_key), ec);
        return ec;
    }

    void prepare(encryption_request &req, minecraft::security::private_key const &ppk)
    {
        static thread_local auto eng = [] {
            auto rng = std::random_device();
            auto seq = std::seed_seq { rng(), rng(), rng(), rng(), rng() };
            auto eng = std::default_random_engine(seq);
            return eng;
        }();

        auto dist = std::uniform_int_distribution< std::uint32_t >(0, 255);

        auto &tok = req.verify_token;
        tok.resize(4);
        std::generate(tok.begin(), tok.end(), [&] { return dist(eng); });

        req.public_key = ppk.public_asn1();
    }

}   // namespace minecraft::server