//
// Created by rhodges on 12/04/2020.
//

#include "encryption_response.hpp"
#include "gateway/hexdump.hpp"

namespace minecraft::client {

    auto
    operator<<(std::ostream &os, encryption_response const &arg) -> std::ostream &
    {
        os << "client::encryption_response"
              " : shared_secret=" << gateway::hexstring(arg.shared_secret)
           << " : verify_token=" << gateway::hexstring(arg.verify_token);
        return os;
    }

    auto report_on(std::ostream& os, encryption_response const& arg) -> void
    {
        os << arg;
    }


}
