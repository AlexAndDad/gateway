//
// Created by rhodges on 19/04/2020.
//

#include "frame_data.hpp"
#include "minecraft/parse.hpp"

namespace minecraft::protocol
{

    auto frame_data::decode_frame_length(error_code &ec) -> error_code &
    {
        assert(payload_size == 0);
        assert(data_position == 0);

        var_int frame_size;
        auto    first = static_cast< const_buffer_iterator >(payload.data());
        auto    last  = first + payload.size();
        auto    next  = parse(first, last, frame_size, ec);
        if (not ec.failed())
        {
            payload_size  = std::size_t(frame_size.value());
            data_position = std::distance(first, next);
        }
        return ec;
    }

    auto frame_data::get_data() -> net::mutable_buffer
    {
        assert(not shortfall());
        auto result = net::buffer(payload.data() + data_position, payload_size);
        return result;

    }

    void frame_data::remove_one()
    {
        auto first = payload.begin();
        auto last  = first + std::exchange(data_position, 0) + std::exchange(payload_size, 0);
        payload.erase(first, last);
    }

    void frame_data::reset()
    {
        payload_size  = 0;
        data_position = 0;
        payload.clear();
    }


    auto frame_data::begin() const -> const char *
    {
        assert(not shortfall());
        return payload.data() + data_position;
    }

    auto frame_data::end() const -> const char *
    {
        assert(not shortfall());
        return begin() + payload_size;
    }

    void frame_data::consume(std::size_t n)
    {
        assert(payload_size);
        assert(not shortfall());
        data_position += n;
        payload_size -= n;
    }

    auto frame_data::shortfall() const -> std::size_t
    {
        auto size = payload.size();
        assert(data_position <= size);
        size -= data_position;
        if (size >= payload_size)
            return 0;
        else
            return payload_size - size;
    }

}