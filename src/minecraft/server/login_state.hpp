#pragma once

#include <wise_enum.h>
#include <minecraft/client/login_start.hpp>
#include "minecraft/client/handshake.hpp"
#include "minecraft/server/encryption_request.hpp"
#include "polyfill/join.hpp"

namespace minecraft::server {
    WISE_ENUM_CLASS(login_state_code, waiting_handshake, waiting_login_start, waiting_encryption_response, exit_state);

    struct login_state
    {
        void
        operator()(client::handshake const &event)
        {
            using namespace std::literals;

            if (code_ != login_state_code::waiting_handshake)
                throw std::runtime_error(polyfill::join("handshake in state: "s, wise_enum::to_string(code_)));

            code_ = login_state_code::waiting_login_start;
        }

        void
        operator()(client::login_start const &event)
        {
            using namespace std::literals;

            if (code_ != login_state_code::waiting_login_start)
                throw std::runtime_error(polyfill::join("login_state in state: "s, wise_enum::to_string(code_)));

            code_ = login_state_code::waiting_encryption_response;
        }


        login_state_code code_ = login_state_code::waiting_handshake;
        server::encryption_request encryption_request_;
    };

}