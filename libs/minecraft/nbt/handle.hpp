#pragma once

#include "impl.hpp"

namespace minecraft::nbt
{
    struct handle
    {
        explicit handle(storage_ptr sp = {})
        : storage_(std::move(sp))
        {
        }

        void swap(handle &other) noexcept
        {
            using std::swap;
            swap(storage_, other.storage_);
        }

        auto reset(storage_ptr sp = {}) -> storage_ptr { return std::exchange(storage_, std::move(sp)); };

        void ensure_storage()
        {
            if (not storage_)
                storage_ = boost::make_unique< impl >();
        }

        bool empty() const { return not storage_; }

        storage_ptr const &get_storage() const { return storage_; }

        storage_ptr storage_;

        //
        // services
        //

        friend void pretty_print(std::ostream &os, handle const &arg) { pretty_print(os, arg.storage_.get()); }
    };
}   // namespace minecraft::nbt