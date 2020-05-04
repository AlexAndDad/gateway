#pragma once

#include <fmt/ostream.h>
#include <spdlog/spdlog.h>
#include <string>
#include <string_view>

namespace polyfill
{
    template < typename FMT, typename... Args >
    struct args_with_header
    {
        args_with_header(std::string_view header, FMT fmt_str, const Args &... args)
        : header_(header)
        , fmt_str_(fmt_str)
        , args_(args...)
        {
        }

        friend std::ostream &operator<<(std::ostream &os, const args_with_header &self)
        {
            os << self.header_ << ":";
            auto lam = [&](auto &&... args) { fmt::print(os, self.fmt_str_, args...); };
            std::apply(lam, self.args_);
        }

        std::string_view              header_;
        FMT                           fmt_str_;
        std::tuple< const Args &... > args_;
    };

    struct class_logger
    {
        class_logger(std::string header)
        : header_(std::move(header))
        {
        }

        void log() {}
        void warn() {}

        // Error
        template < typename... Args >
        void error(string_view_t fmt_str, const Args &... args)
        {
            spdlog::error(args_with_header(header_, fmt_str, args...));
        }

      private:
        std::string header_;
    };
}   // namespace polyfill