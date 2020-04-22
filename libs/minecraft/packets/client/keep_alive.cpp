#include "keep_alive.hpp"
#include "minecraft/encode.hpp"

namespace minecraft::packets::client
{
    void compose(keep_alive const& pkt, compose_buffer& buf)
    {
        auto first = back_inserter(buf);

        first = encode(var_enum(pkt.id()), first);
        encode(pkt.keep_alive_ID, first);
    }

}