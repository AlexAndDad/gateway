#pragma once
#include "impl.hpp"

#include <boost/smart_ptr/make_shared.hpp>

namespace minecraft::nbt
{
    struct value_base
    {
        using storage_ptr = boost::shared_ptr< impl >;

        explicit value_base(storage_ptr sp = {})
        : sp_(std::move(sp))
        {
        }

        auto ensure_storage() -> storage_ptr
        {
            if (!sp_)
                sp_ = boost::make_shared<impl>();
            return sp_;
        }

        auto storage() const -> storage_ptr
        {
            return sp_;
        }

      protected:
        storage_ptr sp_;
    };
}   // namespace minecraft::nbt