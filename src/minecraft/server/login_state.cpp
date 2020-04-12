#include "minecraft/server/login_state.hpp"

#include <random>
#include <openssl/rsa.h>

namespace minecraft::server {

    login_state::login_state(std::string server_id, minecraft::security::private_key server_key)
    : server_key_(std::move(server_key))
    , server_id_(std::move(server_id))
    , verify_token_(generate_token())
    , protocol_version_(0)
    {

    }

    std::vector<std::uint8_t>
    login_state::generate_token()
    {
        auto make_engine = [] {
            auto rng = std::random_device();
            auto seq = std::seed_seq{rng(), rng(), rng(), rng(), rng()};
            auto eng = std::default_random_engine(seq);
            return eng;
        };
        static thread_local auto eng = make_engine();

        auto result = std::vector<std::uint8_t>(4);
        auto dist = std::uniform_int_distribution<std::uint32_t>(0, 255);
        std::generate(result.begin(), result.end(), [&] {
            return dist(eng);
        });
        return result;
    }

    void
    login_state::operator()(client::handshake const &event)
    {
        using namespace std::literals;

        if (code_ != login_state_code::waiting_handshake)
            throw std::runtime_error(polyfill::join("handshake in state: "s, wise_enum::to_string(code_)));

        protocol_version_ = event.protocol_version;

        code_ = login_state_code::waiting_login_start;
    }

    void
    login_state::operator()(client::login_start const &event)
    {
        using namespace std::literals;

        if (code_ != login_state_code::waiting_login_start)
            throw std::runtime_error(polyfill::join("login_state in state: "s, wise_enum::to_string(code_)));

        if (protocol_version_ <= 578)
            encryption_request_.server_id = server_id_;
        encryption_request_.public_key = server_key_.public_asn1();
        encryption_request_.verify_token = verify_token_;

        code_ = login_state_code::waiting_encryption_response;
    }

    void
    login_state::operator()(client::encryption_response const &event)
    {
        using namespace std::literals;

        if (code_ != login_state_code::waiting_encryption_response)
            throw std::runtime_error(polyfill::join("encryption_response in state: "s, wise_enum::to_string(code_)));

        // decrypt verify token

        auto cipher_context = EVP_CIPHER_CTX_new();

        auto rsa = EVP_PKEY_get0_RSA(this->server_key_.native_handle());
        std::vector<std::uint8_t> output(RSA_size(rsa));
        auto outsize = RSA_private_decrypt(event.verify_token.size(), event.verify_token.data(), output.data(), rsa,
                                           RSA_PKCS1_PADDING);

        if (outsize < 0)
            throw std::runtime_error("error decrypting verify_token");
        output.resize(outsize);

        if (output != this->verify_token_)
            throw std::runtime_error("verify token doesn't match");

        output.resize(RSA_size(rsa));
        outsize = RSA_private_decrypt(event.shared_secret.size(), event.shared_secret.data(), output.data(), rsa,
                                      RSA_PKCS1_PADDING);
        if (outsize < 0)
            throw std::runtime_error("error decrypting shared secret");
        output.resize(outsize);
        shared_secret_ = std::move(output);
    }


}