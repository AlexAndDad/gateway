#include "minecraft/server/spawn_position.hpp"

namespace minecraft::server
{
    std::ostream &operator<<(std::ostream &os, spawn_position const &arg)
    {
        os << "spawn_position.location : " << arg.location;
        return os;
    }

}   // namespace minecraft::server