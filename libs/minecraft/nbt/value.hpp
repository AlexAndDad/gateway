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

        void assign(storage_ptr sp)
        {
            handle::assign(sp->root_object_, sp);
        }
    };

    void pretty_print(std::string& , value const& )
    {

    }



    inline const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, value &target, error_code &ec)
    {
        if (ec) return first;
        if (first == last)
        {
            target.assign(nullptr);
        }
        else
        {
            target.assign(boost::make_shared<impl>());
            first = parse(first, last, *target.get_storage(), ec);
        }
        return first;
    }

}   // namespace minecraft::nbt