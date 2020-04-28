#include "minecraft/packets/client/play_id.hpp"
#include "minecraft/packets/packet_base.hpp"
#include "minecraft/types.hpp"
#include "minecraft/wise_enum.hpp"

namespace minecraft::packets::client
{
    WISE_ENUM_CLASS((chat_mode_type, std::int32_t), (enabled, 0), (commands, 1), (hidden, 2));
    WISE_ENUM_ENABLE_IO(chat_mode_type);

    WISE_ENUM_CLASS((main_hand_type, std::int32_t), (left, 0), (right, 1));
    WISE_ENUM_ENABLE_IO(main_hand_type);

    struct client_settings : packet_base< play_id::client_settings, client_settings >
    {

        varchar< 16 > locale;
        std::uint8_t view_distance;
        var_enum< chat_mode_type > chat_mode;
        bool chat_colours;
        std::uint8_t skin_parts;
        var_enum< main_hand_type > main_hand;

        template < class Self >
        static auto as_nvps(Self &self)
        {
            return nvp_set(nvp("locale", self.locale),
                           nvp("view_distance", self.view_distance),
                           nvp("chat_mode", self.chat_mode),
                           nvp("chat_colours", self.chat_colours),
                           nvp("skin_parts", self.skin_parts),
                           nvp("main_hand", self.main_hand));
        }
    };

}   // namespace minecraft::packets::client