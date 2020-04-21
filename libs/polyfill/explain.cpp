#include "polyfill/explain.hpp"

#include <iomanip>

using namespace std::literals;

namespace polyfill
{
    namespace detail
    {
        std::string_view sep(std::size_t level) { return level ? " -> " : ""; }

        void start_entry(std::ostream &s, std::exception &e, std::size_t level)
        {
            fmt::print(s, "{}[exception {}", sep(level), std::quoted(e.what()));
            s << std::string(level, ' ') << "exception: " << e.what() << '\n';
        }

        void start_entry(std::ostream &s, config::system_error &e, std::size_t level)
        {
            auto &&code = e.code();
            fmt::print(s,
                       "{}[exception system_error [message {}] [code {}] [category {}] {}",
                       sep(level),
                       std::quoted(code.message()),
                       code.value(),
                       code.category().name(),
                       std::quoted(e.what()));
        }

        void close_entry(std::ostream &os) { os.put(']'); }
    }   // namespace detail

    void explainer::print(std::ostream &os, std::string_view s, std::size_t)
    {
        fmt::print(os, "[exception {}]", s);
    }

    explainer::explainer(std::exception_ptr ep)
    : ep(std::move(ep))
    {
    }

    void explainer::operator()(std::ostream &s) const
    {
        try
        {
            std::rethrow_exception(ep);
            s << "no exception"sv;
        }
        catch (config::system_error &e)
        {
            print(s, e);
        }
        catch (std::exception &e)
        {
            print(s, e);
        }
        catch (...)
        {
            print(s, "unknown"sv);
        }
    }

    std::ostream &operator<<(std::ostream &s, explainer const &ex)
    {
        ex(s);
        return s;
    }

    auto explain(std::exception_ptr ep) -> explainer { return explainer { ep }; }

    auto deduce_return_code(std::exception_ptr ep) -> int
    {
        int result = 0;
        try
        {
            std::rethrow_exception(ep);
        }
        catch (config::system_error &se)
        {
            result = se.code().value();
        }
        catch (...)
        {
            result = 127;
        }

        return result;
    }

}   // namespace polyfill