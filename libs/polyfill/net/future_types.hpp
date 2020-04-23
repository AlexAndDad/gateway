//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "polyfill/outcome.hpp"

namespace polyfill::net
{
    template < class T >
    using future_result_type = outcome::outcome< T >;
}
