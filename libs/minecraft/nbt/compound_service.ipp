//
// Created by rhodges on 05/05/2020.
//
#pragma once

#include "compound_service.hpp"
#include "storage_provider.hpp"
#include "string_service.hpp"

#include <boost/core/ignore_unused.hpp>
#include <cstdint>
#include <utility>

namespace minecraft::nbt
{
    // ---

    template < class Derived >
    auto compound_service< Derived >::new_compound(std::int32_t nbuckets) -> compound_header *
    {
        auto pmem     = self()->alloc(size_to_blocks(compound_header::extent(nbuckets)));
        return new (pmem) compound_header(nbuckets);
    }

    template < class Derived >
    auto compound_service< Derived >::release_compound(offset id) -> std::uint8_t
    {
        compound_header *hdr = self()->template from_offset< compound_header >(id);
        assert(hdr);
        assert(hdr->is_valid());
        auto uses = hdr->release();
        if (uses == 0)
            destruct(hdr);
        return uses;
    }

    template < class Derived >
    auto compound_service< Derived >::compound_set(offset compound_id, offset name, data_ref value) -> offset
    {
        compound_header *hdr = self()->template from_offset< compound_header >(compound_id);
        string_header *  str = self()->template from_offset< string_header >(name);
        assert(str);
        assert(str->type = tag_type::String);

        compound_bucket *bucket = find_matching_bucket(hdr, str);
        if (not bucket)
        {
            boost::ignore_unused(this->link_bucket(hdr, compound_bucket(name, std::move(value))));
            compound_id = self()->to_offset(maybe_rehash(hdr));
        }
        else
            replace_impl(bucket, std::move(value));

        return compound_id;
    }

    template < class Derived >
    auto compound_service< Derived >::destruct(compound_header *hdr) -> void
    {
        assert(hdr);
        assert(hdr->is_valid());
        assert(hdr->use_count() == 0);

        for (compound_bucket &bucket : hdr->buckets())
        {
            if (bucket.empty())
                assert(invalid_offset(bucket.next));
            else
                destruct(destroy_contents(&bucket));
        }
    }

    template < class Derived >
    auto compound_service< Derived >::destroy_contents(compound_bucket *bucket) -> compound_bucket *
    {
        auto next = self()->template from_offset< compound_bucket >(bucket->next);
        if (bucket->empty())
        {
            assert(next == nullptr);
        }
        else
        {
            self()->release_string(bucket->name);
            self()->release(bucket->value);
        }
        return next;
    }

    template < class Derived >
    auto compound_service< Derived >::destruct(compound_bucket *bucket) -> void
    {
        while (bucket)
        {
            auto next = destroy_contents(bucket);
            self()->free(bucket, size_to_blocks(sizeof(bucket)));
            bucket = next;
        }
    }

    template < class Derived >
    auto compound_service< Derived >::find_matching_bucket(compound_header *hdr, string_header *name)
        -> compound_bucket *
    {
        auto bucket = hdr->get_bucket(name->hash);
        if (bucket->empty())
            return nullptr;

        auto next_bucket = [&]() { return self()->template from_offset< compound_bucket >(bucket->next); };
        for (bucket = next_bucket(); bucket; bucket = next_bucket())
        {
            assert(not bucket->empty());
            if (self()->template from_offset< string_header >(bucket->name) == name)
                break;
        }
        return bucket;
    }

    template < class Derived >
    auto compound_service< Derived >::insert_impl(compound_header *hdr, string_header *name, data_ref data)
        -> compound_header *
    {
        assert(hdr);
        assert(name->is_valid());
        auto bucket = hdr->get_bucket(name->hash);

        hdr->size_ += 1;

        if (bucket->empty())
        {
            bucket->name  = self()->to_offset(name);
            bucket->value = std::move(data);
            assert(invalid_offset(bucket->next));
        }
        else
        {
            compound_bucket *pnext = new_bucket();
            // set value
            pnext->name  = self()->to_offset(name);
            pnext->value = std::move(data);
            // link
            pnext->next  = bucket->next;
            bucket->next = self()->to_offset(pnext);
            ++hdr->collisions_;
            hdr = maybe_rehash(hdr);
        }
        return hdr;
    }

    template < class Derived >
    auto compound_service< Derived >::maybe_rehash(compound_header *hdr) -> compound_header *
    {
        // never rehash unless there are collisions
        if (hdr->collisions_ == 0)
            return hdr;

        ///@todo write a heuristic and a rehash algorithm

        auto rehash = false;
        if ((hdr->size_ * 3) / 2 >= hdr->nbuckets_)
            rehash = true;
        else if (hdr->collisions_ >= (hdr->size_ / 50))
            rehash = true;
        else if (hdr->collisions_ >= 100)
            rehash = true;
        if (rehash)
        {
            /// @todo - better bucket size algorithm
            auto             new_buckets = (std::max)((hdr->nbuckets_ * 3) / 2, 7);
            compound_header *new_hdr     = new_compound(new_buckets);

            // iterate through the buckets, moving them into the new container
            // then destroy the new container without deleting the contents of the buckets
            for (compound_bucket &head_bucket : hdr->buckets())
                if (not head_bucket.empty())
                    for (auto pnext = link_bucket(new_hdr, std::move(head_bucket)); pnext;
                         pnext      = link_bucket(new_hdr, pnext))
                        ;
            // the old container is guaranteed to be empty so we don't need to cleanly deallocate it, we can
            // just free its memory
            self()->free(hdr, size_to_blocks(hdr->extent()));
            hdr = new_hdr;
        }
        return hdr;
    }

    template < class Derived >
    auto compound_service< Derived >::link_bucket(compound_header *hdr, compound_bucket *source) -> compound_bucket *
    {
        assert(hdr);
        assert(source);
        assert(not source->empty());
        auto pnext = unlink_after(source);

        auto name = self()->template from_offset< string_header >(source->name);

        hdr->size_ += 1;

        if (auto bucket = hdr->get_bucket(name->hash); bucket->empty())
        {
            // going into a fresh bucket, so move and deallocate
            assert(invalid_offset(bucket->next));
            *bucket = std::move(*source);
            self()->free(source, size_to_blocks(sizeof(bucket)));
        }
        else
        {
            source->next = bucket->next;
            bucket->next = self()->to_offset(source);
            ++hdr->collisions_;
        }
        return pnext;
    }

    template < class Derived >
    auto compound_service< Derived >::link_bucket(compound_header *hdr, compound_bucket &&source) -> compound_bucket *
    {
        assert(hdr);
        assert(not source.empty());
        auto pnext = unlink_after(&source);

        auto name = self()->template from_offset< string_header >(source.name);

        hdr->size_ += 1;

        if (auto bucket = hdr->get_bucket(name->hash); bucket->empty())
        {
            // going into a fresh bucket, so just move
            assert(invalid_offset(bucket->next));
            *bucket = std::move(source);
        }
        else
        {
            // being linked in as a dynamic extension so must allocate a new link
            auto new_bucket  = this->new_bucket(std::move(source));
            new_bucket->next = bucket->next;
            bucket->next     = self()->to_offset(new_bucket);
            ++hdr->collisions_;
        }
        return pnext;
    }

    template < class Derived >
    auto compound_service< Derived >::link_static_bucket(compound_header *hdr, compound_bucket &source) -> void
    {
        assert(hdr);
        assert(not source.empty());

        auto pnext = unlink_after(&source);
        this->insert_impl(hdr,
                          self()->template from_offset< string_header >(std::exchange(source.name, invalid_offset())),
                          std::exchange(source.value, data_ref()));
        while (pnext)
        {
        }
    }

    template < class Derived >
    auto compound_service< Derived >::unlink_after(compound_bucket *current) -> compound_bucket *
    {
        auto next = self()->template from_offset< compound_bucket >(std::exchange(current->next, invalid_offset()));
        return next;
    }

    template < class Derived >
    template < class... Args >
    auto compound_service< Derived >::new_bucket(Args &&... args) -> compound_bucket *
    {
        return new (self()->alloc(size_to_blocks(sizeof(compound_bucket))))
            compound_bucket(std::forward< Args >(args)...);
    }

    // replace the value in the bucket but keep the same name
    template < class Derived >
    auto compound_service< Derived >::replace_impl(compound_bucket *bucket, data_ref data) -> void
    {
        self()->release(bucket->value);
        bucket->value = std::move(data);
    }

    template < class Derived >
    auto compound_service< Derived >::self() -> Derived *
    {
        return static_cast< Derived * >(this);
    }
    template < class Derived >
    auto compound_service< Derived >::self() const -> Derived const *
    {
        return static_cast< Derived const * >(this);
    }

}   // namespace minecraft::nbt