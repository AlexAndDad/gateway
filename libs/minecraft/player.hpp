#pragma once

#include "minecraft/math.hpp"

namespace minecraft
{
    template < class Connection >
    struct player
    {
        using name_type     = std::string;
        using executor_type = net::io_context::executor_type;
        using strand_type   = net::io_context::strand;

        player(std::string name, Connection connection, executor_type exec)
        : name_(std::move(name))
        , strand_(exec.context())
        , connection_(std::move(connection))
        {
        }




      public:
        name_type name_;

        // World related data
        math::Vector3d position_;   // XZ center, Y bottom
        math::Vector3d rotation_;   // degrees [-180, +180]

      private:
        strand_type strand_;
        Connection  connection_;
    };
}   // namespace minecraft
