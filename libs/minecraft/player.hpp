#pragma once

#include "minecraft/math.hpp"

namespace minecraft
{
    template < class Connection >
    struct player
    {
        player(Connection connection)
        : connection(std::move(connection))
        {
        }

      public:
        // World related data
        math::Vector3d position;   // XZ center, Y bottom
        math::Vector3d rotation;   // degrees [-180, +180]

      private:
        Connection connection;
    };
}   // namespace minecraft
