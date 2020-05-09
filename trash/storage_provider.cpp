#include "storage_provider.hpp"

#include <algorithm>
#include <fmt/ostream.h>
#include <random>

namespace minecraft::nbt
{
    storage_provider::storage_provider(std::int32_t initial_size, std::size_t hash_poison)
    : memory_buffer_(nullptr)
    , size_(0)
    , free_list_ { .next = -1, .size = -1 }
    , hash_poison_(hash_poison)
    {
        if (initial_size)
            free(grow(initial_size), initial_size);
    }

    void *storage_provider::alloc(std::int32_t bytes)
    {
        auto blocks = size_to_blocks(bytes);

        assert(blocks != 0);

        auto prev = &free_list_;



        for (auto pnext = from_offset< free_block >(prev->next);
             pnext ;
             prev = pnext,
                  pnext = from_offset< free_block >(pnext->next))
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
        auto new_size = std::max(std::max(prev_size + blocks, blocks * 3 / 2), 512);
        auto new_store = grow(new_size);
        free(reinterpret_cast< block_storage *>(new_store) + prev_size, (new_size-prev_size) * block_size);
        return alloc(bytes);
    }

    void storage_provider::free(void *p, std::int32_t bytes)
    {
        auto blocks = size_to_blocks(bytes);
        assert(blocks > 0);
        assert(p);
        assert(p >= this->memory_buffer_.get());
        assert(p < this->memory_buffer_.get() + size_);

        auto pblock = new (p) free_block { .next = -1, .size = blocks - 1 };
        auto oblock = to_offset(p);

        auto prev = &free_list_;

        auto coalesce = [this](free_block* pblock)
        {
            auto pnext = from_offset<free_block>(pblock->next);
            if (pblock + pblock->available() == pnext)
            {
                pblock->size += pnext->available();
                pblock->next = pnext->next;
            }
        };

        for (; prev;)
        {
            if (oblock < prev->next)
            {
                // insert into free space
                pblock->next = prev->next;
                prev->next   = oblock;

                coalesce(pblock);
                if (prev != &free_list_)
                    coalesce(prev);
                break;
            }
            else
            {
                // our block is at a higher address than the current next
                // unless we are at the end of the list
                if (prev->next == -1)
                {
                    prev->next = oblock;
                    if (prev != &free_list_)
                        coalesce(prev);
                    break;
                }
                else
                    prev = from_offset< free_block >(prev->next);
            }
        }
    }

    std::int32_t storage_provider::free_blocks() const { return report().free_blocks; }

    auto storage_provider::report() const -> storage_report
    {
        storage_report result = { .free_blocks = 0, .fragments = 0 };

        auto prev = &free_list_;

        for (auto pnext = from_offset< free_block >(prev->next); pnext;
             prev = pnext, pnext = from_offset< free_block >(pnext->next))
        {
            result.free_blocks += pnext->available();
            result.fragments += 1;
        }
        return result;
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

    auto storage_provider::generate_hash_poison() -> std::size_t
    {
        static thread_local auto [eng, dist] = []() {
            auto rng  = std::random_device();
            auto seq  = std::seed_seq { rng(), rng(), rng(), rng(), rng() };
            auto eng  = std::default_random_engine(seq);
            auto dist = std::uniform_int_distribution< std::size_t >(0, std::numeric_limits< std::size_t >::max());
            return std::tuple(std::move(eng), std::move(dist));
        }();

        return dist(eng);
    }

    std::ostream &operator<<(std::ostream &os, storage_provider::storage_report const &rep)
    {
        fmt::print(os, "[storage_report [free_blocks {}] [fragments {}]]", rep.free_blocks, rep.fragments);
        return os;
    }

}   // namespace minecraft::nbt