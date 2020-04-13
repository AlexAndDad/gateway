#include "minecraft/server/login_success.hpp"
#include <iostream>

namespace minecraft::server
{
    std::ostream &operator<<(std::ostream &os, login_success const &arg)
    {
        os << "login_success.UUID : " << arg.uuid << "\nlogin_success.username : " << arg.username;
        return os;
    }

}   // namespace minecraft::server