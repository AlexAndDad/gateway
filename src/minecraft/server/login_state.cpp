#include "minecraft/server/login_state.hpp"

#include <random>

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
        std::generate(result.begin(), result.end(), [&]{
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
        auto key_text= server_key_.public_der();
        encryption_request_.public_key.assign(key_text.begin(), key_text.end());

        code_ = login_state_code::waiting_encryption_response;
    }


}