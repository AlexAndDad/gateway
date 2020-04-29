#pragma once

#include "polyfill/net.hpp"

namespace polyfill::async
{

    struct has_error
    {
        error_code& set_error(error_code const& ec)
        {
            if (ec and not error)
                error = ec;
            return error;
        }

        error_code& clear_error()
        {
            error.clear();
            return error;
        }

        error_code error;
    };

}