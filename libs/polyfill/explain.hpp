#pragma once

#include "net.hpp"

#include <exception>
#include <fmt/ostream.h>
#include <string_view>

namespace polyfill
{
    namespace detail
    {
        void start_entry(std::ostream &s, std::exception &e, std::size_t level);
        void start_entry(std::ostream &s, config::system_error &e, std::size_t level);
        void close_entry(std::ostream &s);
    }   // namespace detail

    struct explainer
    {
        explainer(std::exception_ptr ep = std::current_exception());

        void operator()(std::ostream &s) const;

        static void another_what(std::exception& e, std::string& result)
        {
            try
            {
                std::rethrow_if_nested(e);
            }
            catch(std::exception& e)
            {
                result += fmt::format("\n{}",e.what());
                another_what(e, result);
            }
            catch(...)
            {
                result += fmt::format("\nnonstandard exception");
            }
        }

        std::string whats() const
        {
            std::string result;
            try
            {
                std::rethrow_exception(ep);
            }
            catch(std::exception& e)
            {
                result += e.what();
                another_what(e, result);
            }
            catch(...)
            {
                result = "nonstandard exception";
            }
            return result;
        }

      private:
        static void print(std::ostream &os, std::string_view s, std::size_t level = 0);

        template < class Exception >
        static void print(std::ostream &os, Exception &e, std::size_t level = 0);

        friend std::ostream &operator<<(std::ostream &s, explainer const &ex);

        std::exception_ptr ep;
    };

    auto explain(std::exception_ptr ep = std::current_exception()) -> explainer;

    auto deduce_return_code(std::exception_ptr ep = std::current_exception()) -> int;

    template < class Exception >
    void explainer::print(std::ostream &os, Exception &e, std::size_t level)
    {
        detail::start_entry(os, e, level);
        try
        {
            std::rethrow_if_nested(e);
        }
        catch (config::system_error &e)
        {
            print(os, e, level + 1);
        }
        catch (std::exception &e)
        {
            print(os, e, level + 1);
        }
        catch (...)
        {
            print(os, std::string_view("unknown"), level + 1);
        }
        detail::close_entry(os);
    }

}   // namespace polyfill