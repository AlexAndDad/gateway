#pragma once
#include "minecraft/types.hpp"
#include <fmt/ostream.h>
#include <fmt/format.h>
#include <spdlog/fmt/bin_to_hex.h>
#include <vector>
#include "minecraft/span.hpp"

namespace minecraft
{
    /// @brief Represents an array of bytes which takes up the remainder of the packet
    struct remaining_bytes
    {

        void append(const_buffer_iterator first, const_buffer_iterator last)
        {
            store_.insert(store_.end(), first, last);
        }

        auto as_span() const -> const_byte_span
        {
            auto first = reinterpret_cast<const char*>(store_.data());
            auto last = first + store_.size();
            return const_byte_span (first, last);
        }


    private:
        std::vector<std::uint8_t> store_;
    };

    inline
    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, remaining_bytes& target, error_code& ec)
    {
        if (not ec)
        {
            target.append(first, last);
            first = last;
        }
        return first;
    }

    inline
    std::ostream& operator<<(std::ostream& os, remaining_bytes const& rb)
    {
        fmt::print(os, "{:n}", spdlog::to_hex(rb.as_span()));
        return os;
    }

    inline
    std::string to_string(remaining_bytes const& rb)
    {
        return fmt::format("{:n}", spdlog::to_hex(rb.as_span()));
    }
}