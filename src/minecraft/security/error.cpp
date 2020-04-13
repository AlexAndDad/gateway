//
// Created by rhodges on 13/04/2020.
//

#include "error.hpp"
#include <openssl/err.h>

namespace minecraft::security
{
    namespace
    {
    }

    error::ssl peek_error()
    {
        auto code = ERR_peek_error();
        return static_cast<error::ssl>(code);
    }

    error::ssl get_error()
    {
        auto code = ERR_get_error();
        return static_cast<error::ssl>(code);
    }

    config::error_category const& openssl_category()
    {
        static const
        struct cat : config::error_category
        {
            const char* name() const noexcept override
            {
                return "openssl error";
            }

            std::string message(int code) const override
            {
                auto sz = ERR_error_string(code, nullptr);
                return std::string(sz ? sz : "no error");
            }
        } cat;
        return cat;
    }

    config::error_category const& openssl_codeless_category()
    {
        static const
        struct cat : config::error_category
        {
            const char* name() const noexcept override
            {
                return "openssl codeless error";
            }

            std::string message(int) const override
            {
                return "general failure";
            }
        } cat;
        return cat;
    }

    config::error_code make_error_code(error::ssl code)
    {
        return config::error_code(code, openssl_category());
    }

    config::error_code make_error_code(error::codeless code)
    {
        return config::error_code(code, openssl_codeless_category());
    }

    void throw_error_chain(error::ssl code)
    {
        auto ec = code ? make_error_code(code) : make_error_code(error::codeless::no_cde);
        try
        {
            if (std::current_exception())
                std::throw_with_nested(config::system_error(ec));
            else
                throw config::system_error(ec);
        }
        catch(...)
        {
            if(auto next = get_error())
                throw_error_chain(next);
            else
                throw;
        }
    }

    void throw_error()
    {
        throw_error_chain(get_error());
    }
}