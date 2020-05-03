#pragma once

#include "impl.hpp"

namespace minecraft::nbt
{
    struct handle
    {
        handle(handle const &other) noexcept
            : storage_(other.storage_)
            , offset_(other.offset_)
        {
            if (offset_)
            {
                assert(storage_);
                storage_->from_offset< string_header >(offset_)->addref();
            }
        }

        handle &operator=(handle const &other) noexcept
        {
            auto copy = handle(other);
            swap(copy);
            return *this;
        }

        handle(handle &&other)
            : storage_(std::move(other.storage_))
            , offset_(std::exchange(other.offset_, -1))
        {
        }

        handle &operator=(handle &&other)
        {
            swap(other);
            return *this;
        }

        explicit handle(storage_ptr sp = {})
            : storage_(std::move(sp))
            , offset_(-1)
        {
        }

        void swap(handle &other) noexcept
        {
            using std::swap;
            swap(storage_, other.storage_);
            swap(offset_, other.offset_);
        }

        void ensure_storage()
        {
            if (not storage_)
                storage_ = boost::make_shared< impl >();
        }

        void assign(offset id, storage_ptr sp)
        {
            offset_ = id;
            storage_ = std::move(sp);
        }

        bool empty() const { return offset_ == -1; }

        storage_ptr const &get_storage() const { return storage_; }

        offset get_offset() const { return offset_; }

        boost::shared_ptr< impl > storage_;
        offset                    offset_;
    };
}