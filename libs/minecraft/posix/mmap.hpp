#pragma once
#include "file_descriptor.hpp"

#include <sys/mman.h>

namespace minecraft::posix
{
    inline void *validate_return(void *p, const char *context)
    {
        if (p == nullptr)
            throw system_error(error_code(errno, system_category()), context);
        return p;
    }

    struct mapping
    {
        mapping(void *address, size_t size)
        : address_(address)
        , size_(size)
        {
        }

        mapping(mapping &&other)
        : address_(std::exchange(other.address_, nullptr))
        , size_(other.size_)
        {
        }

        mapping &operator=(mapping &&other)
        {
            if (address_)
                ::munmap(address_, size_);
            address_ = std::exchange(other.address_, nullptr);
            size_    = other.size_;
            return *this;
        }

        ~mapping()
        {
            if (address_)
                ::munmap(address_, size_);
        }

        const_buffer_iterator begin() const
        {
            return reinterpret_cast<const_buffer_iterator>(address_);
        }

        const_buffer_iterator end() const
        {
            return begin() + size_;
        }

      private:
        void * address_;
        size_t size_;
    };


    inline auto mmap(file_descriptor const &fd) -> mapping
    {
        auto size = fd.size();
        auto addr = validate_return(
            ::mmap(
                nullptr, size, PROT_READ, MAP_PRIVATE, fd.native_handle(), 0),
            "mmap");
        return mapping(addr, size);
    }

}   // namespace minecraft::posix