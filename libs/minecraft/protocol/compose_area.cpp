//
// Created by rhodges on 19/04/2020.
//

#include "minecraft/protocol/compose_area.hpp"
#include "minecraft/encode.hpp"

namespace minecraft::protocol
{

    compose_buffer &compose_area::prepare()
    {
        offset = max_var_encoded_bytes< std::int32_t >() * 2;
        buffers[0].resize(offset);
        return buffers[0];
    }

    net::const_buffer compose_area::commit(int compression_threshold)
    {
        const auto uncompressed_size = frame().size();

        if (compression_threshold < 0)
        {
            prepend(uncompressed_size);
        }
        else if (uncompressed_size < compression_threshold)
        {
            prepend(0);
            prepend(frame().size());
        }
        else
        {
            buffers[1].resize(offset);
            deflator_(net::buffer(buffers[0]), buffers[1]);
            buffers[0].swap(buffers[1]);
            prepend(uncompressed_size);
            prepend(frame().size());
        }
        return frame();
    }

    auto compose_area::frame() const -> net::const_buffer
    {
        auto result = net::buffer(buffers[0]);
        result += offset;
        return result;
    }

    auto compose_area::prepend(std::int32_t n) -> void
    {
        char tmp[max_var_encoded_bytes< std::int32_t >()];
        auto first = std::begin(tmp);
        auto last  = var_encode(n, first);
        offset -= std::distance(first, last);
        std::copy(first, last, &buffers[0][offset]);
    }

}