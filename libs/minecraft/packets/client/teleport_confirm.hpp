#include "minecraft/packets/client/play_id.hpp"
#include "minecraft/packets/packet_base.hpp"
#include "minecraft/types.hpp"

namespace minecraft::packets::client
{
    struct teleport_confirm : packet_base< play_id::teleport_confirm, teleport_confirm >
    {

        var<int32_t> teleport_id;

        template < class Self >
        static auto as_nvps(Self &self)
        {
            return nvp_set(nvp("teleport_id", self.teleport_id));
        }
    };

}   // namespace minecraft::packets::client
