#pragma once

#include <wise_enum.h>
#include <minecraft/client/login_start.hpp>
#include "minecraft/client/handshake.hpp"
#include "minecraft/server/encryption_request.hpp"
#include "polyfill/join.hpp"
#include "minecraft/security/private_key.hpp"
#include <random>
#include <minecraft/client/encryption_response.hpp>

namespace minecraft::server {
    WISE_ENUM_CLASS(login_state_code, waiting_handshake, waiting_login_start, waiting_encryption_response, exit_state);

    struct login_state
    {
        login_state(std::string server_id, minecraft::security::private_key server_key);

        void
        operator()(client::handshake const &event);

        void
        operator()(client::login_start const &event);

        void
        operator()(client::encryption_response const &event);

        static std::vector<std::uint8_t> generate_token();


        login_state_code code_ = login_state_code::waiting_handshake;
        minecraft::security::private_key server_key_;
        server::encryption_request encryption_request_;
        std::string server_id_;
        std::vector<std::uint8_t> verify_token_;
        std::int32_t protocol_version_;
        std::vector<std::uint8_t> shared_secret_;
    };

}