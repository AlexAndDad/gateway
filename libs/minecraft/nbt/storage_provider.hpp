//
// Created by rhodges on 05/05/2020.
//

#pragma once
#include "minecraft/nbt/free_block.hpp"

#include <boost/smart_ptr/make_unique.hpp>

namespace minecraft::nbt
{
    /// Provide storage for data structures.
    ///
    /// Could be upgraded to use a plymorphic memory resource
    struct storage_provider
    {
        static auto constexpr block_size() { return sizeof(block_storage); }
        static auto constexpr initial_size() -> std::int32_t { return 512; }

        explicit storage_provider(std::int32_t initial_size = storage_provider::initial_size());

        void *grow(std::int32_t new_size);

        void *      memory() { return memory_buffer_.get(); }
        void const *memory() const { return memory_buffer_.get(); }

        template < class T >
        T *from_offset(offset i)
        {
            if (i == -1)
                return nullptr;
            else
                return reinterpret_cast< T * >(reinterpret_cast< block_storage * >(memory()) + i);
        }
        template < class T >

        T const *from_offset(offset i) const
        {
            if (i == -1)
                return nullptr;
            else
                return reinterpret_cast< T const * >(reinterpret_cast< block_storage const * >(memory()) + i);
        }

        offset to_offset(void *p)
        {
            return reinterpret_cast< block_storage * >(p) - reinterpret_cast< block_storage * >(memory());
        }

        /// Allocate n blocks of storage from the free list, return as address or nullptr
        /// \param blocks
        /// \return
        void *alloc(int32_t blocks);

        /// free n blocks at p into the free list
        /// \param where
        /// \param blocks
        void free(void *p, int32_t blocks);

        /// Walk the free list and return total available space
        std::int32_t free_blocks() const;

      private:
        // provide storage for data structure
        std::unique_ptr< block_storage[] > memory_buffer_;
        std::int32_t                       size_;
        free_block                         free_list_;
    };

    struct storage_svc
    {
        template < class T >
        struct ptr
        {
            using value_type = T;
            explicit ptr(offset off = invalid_offset())
            : off_(off)
            {
            }

            ptr(ptr const &) = default;
            ptr(ptr &&other)
            : off_(std::exchange(other.off_, invalid_offset()))
            {
            }

            ptr &operator=(ptr const &) = default;
            ptr &operator               =(ptr &&other) { off_ = std::exchange(other.off_, invalid_offset()); }

            value_type *get(storage_provider *sp) const { return sp->from_offset< T >(off_); }

            operator bool() const { return not invalid_offset(off_); }

            offset reset() { return std::exchange(off_, invalid_offset()); }

            offset reset(storage_provider *sp, T *p) { return std::exchange(off_, sp->to_offset(p)); }

            template < class... Args >
            T *create(storage_provider *sp, Args &&... args)
            {
                void *p      = sp->alloc(size_to_blocks(T::extent(args...)));
                T *   result = new (p) T(std::forward< Args >(args)...);
                off_         = sp->to_offset(result);
                return result;
            }

            void destroy(storage_provider *sp)
            {
                auto p      = get();
                auto extent = p->extent();
                p->~T();
                sp->free(size_to_blocks(extent));
            }

          private:
            offset off_;
        };
    };

}   // namespace minecraft::nbt
