//
// Created by rhodges on 19/04/2020.
//

#pragma once
#include "minecraft/net.hpp"
#include "minecraft/types.hpp"
#include "minecraft/protocol/compression/deflate_impl.hpp"

namespace minecraft::protocol
{
    /// Allows composition of (possibly compressed) frame
    struct compose_area
    {
        // step 1 - reset and return a compose_buffer that the user may *add to* (do not clear)
        compose_buffer &prepare();

        // step 2 - perform compression and add frame
        net::const_buffer commit(int compression_threshold);

        // step 3 - retrieve the frame
        [[nodiscard]] auto frame() const -> net::const_buffer;

      private:
        auto prepend(std::int32_t n) -> void;

        compression::deflate_impl deflator_;
        std::size_t               offset;
        compose_buffer            buffers[2];
    };
}   // namespace minecraft::protocol