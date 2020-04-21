//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "config/net.hpp"
#include "polyfill/net.hpp"

namespace application
{
    namespace net
    {
        using namespace config::net;
        using namespace polyfill::net;
    }
    using config::error_category;
    using config::error_code;
    using config::system_error;
}