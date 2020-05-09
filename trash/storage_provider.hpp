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
        static auto constexpr initial_size() -> std::int32_t { return 512; }

        explicit storage_provider(std::int32_t initial_size = storage_provider::initial_size(),
                                  std::size_t  hash_poison  = generate_hash_poison());

        void *grow(std::int32_t new_size);

        void *memory() const { return memory_buffer_.get(); }

        static auto generate_hash_poison() -> std::size_t;

        template < class T >
        T *from_offset(offset i) const
        {
            return reinterpret_cast<T*>(to_address(i));
        }

        offset to_offset(void *p) const
        {
            return reinterpret_cast< std::uint8_t * >(p) - reinterpret_cast< std::uint8_t * >(memory());
        }

        void *to_address(offset n) const { return n < 0 ? nullptr : reinterpret_cast< std::uint8_t * >(memory()) + n; }

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

        struct storage_report
        {
            std::int32_t free_blocks;
            std::size_t  fragments;

            bool operator==(storage_report const &b) const
            {
                return free_blocks == b.free_blocks && fragments == b.fragments;
            }

            friend std::ostream &operator<<(std::ostream &os, storage_report const &rep);
        };
        auto report() const -> storage_report;

        auto hash_poison() const -> std::size_t { return hash_poison_; }

      private:

        static constexpr auto block_size = sizeof(block_storage);

        std::int32_t size_to_blocks(std::size_t object_extent)
        {
            object_extent += block_size - 1;
            object_extent /= block_size;
            return static_cast< int32_t >(object_extent);
        }

      private:
        // provide storage for data structure
        std::unique_ptr< block_storage[] > memory_buffer_;
        std::int32_t                       size_; // in blocks
        free_block                         free_list_;
        std::size_t                        hash_poison_;
    };

}   // namespace minecraft::nbt
