//
// Created by rhodges on 13/04/2020.
//

#pragma once

#include "minecraft/net.hpp"

namespace minecraft::security {


    struct error
    {
        enum ssl : int
        {
            ok = 0
        };

        enum codeless : int
        {
            no_cde = 1,
            not_rsa = 2
        };
    };

    error::ssl peek_error();
    error::ssl get_error();

    error_code make_error_code(error::ssl);
    error_code make_error_code(error::codeless);
    error_category const& openssl_category();

    [[noreturn]]
    void throw_error_chain(error::ssl);

    [[noreturn]]
    void throw_error();

    inline void check_success(int result)
    {
        if (not result)
            throw_error();
    }

    inline int check_positive(int val)
    {
        if (val < 0)
            throw_error();
        return val;
    }

}

namespace boost::system
{
    template<>
    struct is_error_code_enum<minecraft::security::error::ssl> : std::true_type {};

    template<>
    struct is_error_code_enum<minecraft::security::error::codeless> : std::true_type {};
}
