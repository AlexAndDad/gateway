
#include "minecraft/protocol/mojang_login_data.hpp"

#include "minecraft/parse_error.hpp"

#include <boost/json.hpp>
#include <fmt/format.h>
#include <string_view>

namespace minecraft::protocol
{
    mojang_login_data::mojang_login_data(boost::json::value val)
    : mojang_login_data(easy_value(std::move(val)))
    {
    }

    mojang_login_data::mojang_login_data(const easy_value &json)
    : name(json["name"])
    , id(json["id"])
    , properties(json["properties"])
    {
    }

    std::string insert_dashes(boost::json::string const &uuid)
    {
        auto view = std::string_view(uuid.data(), uuid.size());

        if (view.size() == 32)
            return fmt::format("{}-{}-{}-{}-{}",
                               view.substr(0, 8),
                               view.substr(8, 4),
                               view.substr(12, 4),
                               view.substr(16, 4),
                               view.substr(20, 12));
        else
            return std::string(view.begin(), view.end());
    }

}   // namespace minecraft::protocol