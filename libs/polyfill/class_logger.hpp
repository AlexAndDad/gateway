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
        args_with_header(const std::string &header, FMT fmt_str, const Args &... args)
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
            return os;
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

        // Debug
        template < typename... Args >
        void debug(std::string_view fmt_str, const Args &... args)
        {
            spdlog::debug(args_with_header(header_, fmt_str, args...));
        }
        template < typename T >
        void debug(const T &msg)
        {
            spdlog::debug(args_with_header(header_, "{}", msg));
        }

        // Info
        template < typename... Args >
        void info(std::string_view fmt_str, const Args &... args)
        {
            spdlog::info(args_with_header(header_, fmt_str, args...));
        }
        template < typename T >
        void info(const T &msg)
        {
            spdlog::info(args_with_header(header_, "{}", msg));
        }

        // Warn
        template < typename... Args >
        void warn(std::string_view fmt_str, const Args &... args)
        {
            spdlog::warn(args_with_header(header_, fmt_str, args...));
        }
        template < typename T >
        void warn(const T &msg)
        {
            spdlog::warn(args_with_header(header_, "{}", msg));
        }

        // Error
        template < typename... Args >
        void error(std::string_view fmt_str, const Args &... args)
        {
            spdlog::error(args_with_header(header_, fmt_str, args...));
        }
        template < typename T >
        void error(const T &msg)
        {
            spdlog::error(args_with_header(header_, "{}", msg));
        }

      private:
        std::string header_;
    };
}   // namespace polyfill