#pragma once

#include <exception>
#include "net.hpp"

namespace polyfill {
    struct explainer
    {
        std::exception_ptr ep = std::current_exception();

        template<class Stream>
        static void
        emit(Stream &s, std::exception &e, std::size_t level)
        {
            s << std::string(level, ' ') << "exception: " << e.what() << '\n';
        }

        template<class Stream>
        static void
        emit(Stream &s, config::system_error &e, std::size_t level)
        {
            s << std::string(level, ' ') << "system error: " << e.what() << " : code=" << e.code().value()
              << " : category=" << e.code().category().name() << " : message=" << e.code().message() << '\n';
        }

        template<class Stream, class Exception>
        static void
        print(Stream &os, Exception &e, std::size_t level = 0)
        {
            emit(os, e, level);
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
                os << std::string(level, ' ') << "exception: unknown" << '\n';
            }
        }

        template<class Stream>
        void
        operator()(Stream &s) const
        {
            try
            {
                std::rethrow_exception(ep);
                s << "no exception";
            }
            catch (config::system_error &e)
            {
                print(s, e);
            }
            catch (std::exception &e)
            {
                print(s, e);
            }
            catch(...)
            {
                s << "exception: unknown" << '\n';
            }
        }

        template<class Stream>
        friend Stream &
        operator<<(Stream &s, explainer const &ex)
        {
            ex(s);
            return s;
        }
    };

    inline
    auto explain(std::exception_ptr ep = std::current_exception()) -> explainer
    {
        return explainer { ep };
    }

    inline
    auto deduce_return_code(std::exception_ptr ep = std::current_exception()) -> int
    {
        int result = 0;
        try
        {
            std::rethrow_exception(ep);
        }
        catch(config::system_error& se)
        {
            result = se.code().value();
        }
        catch(...)
        {
            result = 127;
        }

        return result;
    }
}