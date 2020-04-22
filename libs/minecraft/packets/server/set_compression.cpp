#include "set_compression.hpp"
#include "minecraft/encode.hpp"

namespace minecraft::packets::server
{
    auto compose(set_compression const &packet, std::vector< char > &buffer) -> void
    {
        var_int const id = static_cast<std::int32_t>(packet.id());
        auto max_bytes = max_encoded_bytes(id) + max_encoded_bytes(packet.threshold);

        auto do_encoding = [&](auto f)
        {
            auto offset = buffer.size();
            buffer.resize(offset + max_bytes);
            auto first = buffer.data() + offset;

            auto next = f(first);

            buffer.resize(offset + std::distance(first, next));
        };

        do_encoding([&](auto iter){
            iter = encode(id, iter);
            iter = encode(packet.threshold, iter);
            return iter;
        });
    }

}