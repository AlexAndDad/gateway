#include "player_position_and_look.hpp"

namespace minecraft::packets::server
{
    std::ostream &operator<<(std::ostream &os, const player_position_and_look &arg)
    {
        os << "player_position_and_look.x: " << arg.x << "\nplayer_position_and_look.y: " << arg.y
           << "\nplayer_position_and_look.z: " << arg.z << "\nplayer_position_and_look.yaw: " << arg.yaw
           << "\nplayer_position_and_look.pitch: " << arg.pitch << "\nplayer_position_and_look.flags: " << arg.flags
           << "\nplayer_position_and_look.teleport_ID: " << arg.teleport_ID;
        return os;
    }
}   // namespace minecraft::packets::server
