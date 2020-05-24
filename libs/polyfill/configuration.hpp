//
// Created by ahodges on 23/05/2020.
//
#pragma once

#include ""
#include "filesystem.hpp"

#include <boost/json.hpp>
#include <exception>
#include <fmt/format.h>
#include <istream>
#include <string_view>

namespace polyfill
{
    struct configuration_error : std::runtime_error
    {
        using std::runtime_error::runtime_error;
    };

    struct configuration_path_error : configuration_error
    {
        using configuration_error::configuration_error;
    };

    struct configuration_parse_error : configuration_error
    {
        using configuration_error::configuration_error;
    };

    struct configuration_structure_error : configuration_error
    {
        using configuration_error::configuration_error;
    };



    using json = boost::json;
    struct configuration
    {
        configuration(std::string_view config_path)
        {
            auto path = fs::path(config_path);
            if (fs::status(path).type() != fs::file_type::regular_file)
                throw configuration_path_error(
                    fmt::format("invalid configuration path: {}", config_path));

            // Path is ok, parse the json file
            auto size        = fs::file_size(path);
            auto file_stream = std::ifstream(config_path);
            std::sting data;
            data.reserve(size);
            file_stream.read(data.data(), size);
            auto ec   = json::error_code();
            json_doc_ = json::parse(data_, ec);
            if (ec.failed())
                throw configuration_parse_error(fmt::format("Error parsing configuration file at [{}] with ec [{}].",config_path,ec));

            if (not json_doc_.is_object())
                throw configuration_structure_error(fmt::format("Invalid configuration file structure. Path [{}]",config_path))
        }

        json::value & operator[](std::string_view key)
        {
            return json_doc_.as_object()[key];
        }

      private:
        json::value json_doc_;
    };

}   // namespace polyfill