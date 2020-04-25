#pragma once

#include "minecraft/net.hpp"

#include <boost/json.hpp>
#include <boost/operators.hpp>
#include <string>
#include <unordered_map>

namespace minecraft::protocol
{
    std::string insert_dashes(boost::json::string const &uuid);

    template < class StringLike >
    auto to_json_string(StringLike const &sl)
    {
        return boost::json::string(sl.begin(), sl.end());
    }

    struct easy_value
    {
        explicit easy_value(boost::json::value val = nullptr)
        : val_(std::move(val))
        {
        }

        auto operator[](std::string_view index) const -> easy_value
        {
            if (auto op = val_.if_object(); op)
            {
                auto i = op->find(to_json_string(index));
                if (i == op->end())
                    return easy_value();
                else
                    return easy_value(i->value());
            }
            else
                return easy_value();
        }

        template < std::size_t N >
        auto operator[](const char (&index)[N]) const -> easy_value
        {
            return operator[](std::string_view(index, N - 1));
        }

        auto operator[](std::size_t i) const -> easy_value
        {
            if (auto ap = val_.if_array(); ap)
            {
                if (i >= ap->size())
                    return easy_value();
                else
                    return easy_value((*ap)[i]);
            }
            else
            {
                return easy_value();
            }
        }

        friend auto to_object(easy_value const &m) -> boost::json::object
        {
            return static_cast< boost::json::object >(m);
        }

        operator boost::json::object() const
        {
            auto result = boost::json::object();

            if (auto op = val_.if_object())
            {
                result = *op;
            }
            else if (auto ap = val_.if_array())
            {
                std::size_t i = 0;
                for (auto &elem : *ap)
                {
                    result.emplace(std::to_string(i), elem);
                }
            }
            else
            {
                result.emplace(to_string(val_), boost::json::value());
            }
            return result;
        }

        operator boost::json::string() const
        {
            switch (val_.kind())
            {
            case boost::json::kind::string:
                return val_.get_string();
            case boost::json::kind::array:
                return to_string(val_);
            case boost::json::kind::bool_:
                return val_.get_bool() ? "true" : "false";
            case boost::json::kind::double_:
                return boost::json::string(std::to_string(val_.get_double()));
            case boost::json::kind::int64:
                return boost::json::string(std::to_string(val_.get_int64()));
            case boost::json::kind::uint64:
                return boost::json::string(std::to_string(val_.get_uint64()));
            case boost::json::kind::null:
                return "";
            case boost::json::kind::object:
                return to_string(val_);
            }
        }

        operator boost::json::array() const
        {
            auto a1 = [this](auto x) {
                auto a = boost::json::array(1, val_.storage());
                a[0]   = std::move(x);
                return a;
            };

            switch (val_.kind())
            {
            case boost::json::kind::string:
                return a1(val_.get_string());
            case boost::json::kind::array:
                return val_.get_array();
            case boost::json::kind::bool_:
                return a1(val_.get_bool());
            case boost::json::kind::double_:
                return a1(val_.get_double());
            case boost::json::kind::int64:
                return a1(val_.get_int64());
            case boost::json::kind::uint64:
                return a1(val_.get_uint64());
            case boost::json::kind::null:
                return boost::json::array(val_.storage());
            case boost::json::kind::object:
            {
                auto        a = boost::json::array(val_.get_object().size() * 2, val_.storage());
                std::size_t i = 0;
                for (auto &&entry : val_.get_object())
                {
                    a[i++] = entry.key();
                    a[i++] = entry.value();
                }
                return a;
            }
            }
        }

      private:
        boost::json::value val_;
    };

    inline auto to_string(easy_value const &ev) -> boost::json::string
    {
        return static_cast< boost::json::string >(ev);
    }

    template < std::size_t N >
    auto operator==(easy_value const &a, const char (&b)[N])
    {
        return to_string(a) == b;
    }

    struct mojang_login_data
    {
        mojang_login_data(easy_value const &source);
        mojang_login_data(boost::json::value source);

        boost::json::string name;
        boost::json::string id;
        boost::json::array  properties;
    };
}   // namespace minecraft::protocol