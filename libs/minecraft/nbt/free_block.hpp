#pragma once
#include "minecraft/nbt/offset.hpp"
#include <memory>
#include <cassert>

namespace minecraft::nbt
{
    // the shape of the header of free space
    struct free_block
    {
        offset       next = -1;   // offset of next free block
        std::int32_t size = 0;    // size of free space (not including this block)

        // how many blocks of actual storage can we free from this block

        /// Inquire how many free blocks are available
        /// \return number of free blocks
        /// @note complexity O(N)
        std::int32_t available() const { return size + 1; }

        /// consume memory from the front of a free_block, reducing its available space
        /// \param n number of blocks to string by
        /// \return address of new free block
        /// @pre this->available() must be greater than n
        free_block * consume(std::int32_t n)
        {
            assert(size >= n);
            auto pnext  = this + n;
            pnext->size = this->size - n;
            pnext->next = this->next;
            return pnext;
        }

    };

    using block_storage = std::aligned_storage_t< sizeof(free_block) >;

    inline std::int32_t size_to_blocks(std::size_t object_extent)
    {
        object_extent += sizeof(block_storage) - 1;
        object_extent /= sizeof(block_storage);
        return static_cast< int32_t >(object_extent);
    }

}