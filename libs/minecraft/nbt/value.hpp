#pragma once
#include "handle.hpp"
#include "parse_context.hpp"
#include "impl.hpp"

namespace minecraft::nbt
{
    /// A type-erased value containing any type or none
    struct value : handle
    {
        using handle::handle;
    };


    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, value &target, error_code &ec)
    {
        if (ec) return first;
        if (first == last)
        {
            target.reset();
        }
        else
        {
            target.reset(boost::make_unique<impl>());
            first = parse(first, last, *target.get_storage(), ec);
        }
        return first;
    }

}   // namespace minecraft::nbt