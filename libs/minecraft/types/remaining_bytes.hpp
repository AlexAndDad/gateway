#pragma once
#include "minecraft/span.hpp"
#include "minecraft/types.hpp"

#include <fmt/format.h>
#include <fmt/ostream.h>
// clang-format off
#include <spdlog/spdlog.h>
#include <spdlog/fmt/bin_to_hex.h>
// clang-format on

#include <vector>

namespace minecraft
{
    /// @brief Represents an array of bytes which takes up the remainder of the packet
    struct remaining_bytes
    {
        void append(const_buffer_iterator first, const_buffer_iterator last) { store_.insert(store_.end(), first, last); }

        auto as_span() const -> const_byte_span
        {
            auto first = reinterpret_cast< const char * >(store_.data());
            auto last  = first + store_.size();
            return const_byte_span(first, last);
        }

        compose_buffer &      as_buffer() { return store_; }
        const compose_buffer &as_buffer() const { return store_; }

      private:
        compose_buffer store_;
    };

    inline const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, remaining_bytes &target, error_code &ec)
    {
        if (not ec)
        {
            target.append(first, last);
            first = last;
        }
        return first;
    }

    template < class Iter >
    Iter encode(const remaining_bytes &in, Iter first)
    {
        auto data = in.as_span();
        return std::copy(data.begin(), data.end(), first);
    }

    inline std::ostream &operator<<(std::ostream &os, remaining_bytes const &rb)
    {
        fmt::print(os, "{:n}", spdlog::to_hex(rb.as_span()));
        return os;
    }

    inline std::string to_string(remaining_bytes const &rb) { return fmt::format("{:n}", spdlog::to_hex(rb.as_span())); }
}   // namespace minecraft