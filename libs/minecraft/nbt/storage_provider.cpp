#include "storage_provider.hpp"

#include <algorithm>

namespace minecraft::nbt
{
    storage_provider::storage_provider(std::int32_t initial_size)
    : memory_buffer_(nullptr)
    , size_(0)
    , free_list_ { .next = -1, .size = -1 }
    {
        if (initial_size)
            free(grow(initial_size), initial_size);
    }

    void *storage_provider::alloc(std::int32_t blocks)
    {
        assert(blocks != 0);

        auto prev = &free_list_;

        for (auto pnext = from_offset< free_block >(prev->next); pnext;
             prev = pnext, pnext = from_offset< free_block >(pnext->next))
        {
            if (pnext->available() == blocks)
            {
                // next block exactly the right size, simply unlink this block and return its address
                prev->next = pnext->next;
                return pnext;
            }
            else if (pnext->available() > blocks)
            {
                // next block is too big, so shrink it, advance it and return the original address
                auto result = pnext;
                pnext       = pnext->consume(blocks);
                prev->next  = to_offset(pnext);
                return result;
            }
        }

        // didn't find a free block large enough, reallocate
        auto prev_size = size_;
        auto increment = (std::min)((std::max)(prev_size / 2, blocks * 3 / 2), 512);
        auto new_store = grow(prev_size + increment);
        free(reinterpret_cast< char * >(new_store) + prev_size, increment);
        return alloc(blocks);
    }

    void storage_provider::free(void *p, std::int32_t blocks)
    {
        assert(blocks > 0);
        assert(p);

        auto pblock = new (p) free_block { .next = -1, .size = blocks - 1 };
        auto prev   = &free_list_;

        auto coalesce = [this](free_block *current, free_block *next) -> bool {
            bool hit = false;
            while (next and (current + current->available() == next))
            {
                hit = true;
                current->size += next->available();
                current = next;
                next    = from_offset< free_block >(current->next);
            }
            return hit;
        };

        for (auto pnext = from_offset< free_block >(prev->next);;
             prev = pnext, pnext = from_offset< free_block >(pnext->next))
        {
            if (coalesce(prev, pblock))
                return;
            else if (pnext > pblock)
            {
                // next block is a higher address, so we link here
                pblock->next = prev->next;
                coalesce(pblock, pnext);
                prev->next = to_offset(pblock);
                break;
            }
            else if (pnext == nullptr)
            {
                prev->next = to_offset(pblock);
                break;
            }
        }
    }

    std::int32_t storage_provider::free_blocks() const
    {
        auto total = std::int32_t(0);
        auto prev  = &free_list_;

        for (auto pnext = from_offset< free_block >(prev->next); pnext;
             prev = pnext, pnext = from_offset< free_block >(pnext->next))
        {
            total += pnext->available();
        }
        return total;
    }

    void *storage_provider::grow(std::int32_t new_size)
    {
        assert(new_size > size_);
        auto new_buffer = boost::make_unique_noinit< block_storage[] >(new_size);
        std::memcpy(new_buffer.get(), memory_buffer_.get(), size_ * sizeof(block_storage));
        memory_buffer_.swap(new_buffer);
        size_ = new_size;
        return memory();
    }

}   // namespace minecraft::nbt