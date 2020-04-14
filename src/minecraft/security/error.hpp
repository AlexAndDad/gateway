//
// Created by rhodges on 13/04/2020.
//

#pragma once

#include "../../../libs/config/net.hpp"

namespace minecraft::security {


    struct error
    {
        enum ssl : int
        {
            ok = 0
        };

        enum codeless : int
        {
            no_cde = 1
        };
    };

    error::ssl peek_error();
    error::ssl get_error();

    config::error_code make_error_code(error::ssl);
    config::error_code make_error_code(error::codeless);
    config::error_category const& openssl_category();

    [[noreturn]]
    void throw_error_chain(error::ssl);

    [[noreturn]]
    void throw_error();

    inline void check_success(int result)
    {
        if (not result)
            throw_error();
    }

}

namespace boost::system
{
    template<>
    struct is_error_code_enum<minecraft::security::error::ssl> : std::true_type {};

    template<>
    struct is_error_code_enum<minecraft::security::error::codeless> : std::true_type {};
}
