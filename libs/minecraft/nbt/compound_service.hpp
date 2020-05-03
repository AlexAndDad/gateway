//
// Created by rhodges on 05/05/2020.
//
#pragma once
#include "data_service.hpp"
#include "offset.hpp"
#include "string_service.hpp"
#include "tag_type.hpp"

#include <cstdint>
#include <iterator>
#include <memory>
#include <span>

namespace minecraft::nbt
{
    struct compound_bucket
    {
        compound_bucket()
        : next(invalid_offset())
        , name(invalid_offset())
        , value()
        {
        }

        compound_bucket(offset name, data_ref&& value)
            : next(invalid_offset())
            , name(name)
            , value(std::move(value))
        {
        }

        // moves are destructive to the source
        compound_bucket(compound_bucket &&other) noexcept
        : next(std::exchange(other.next, invalid_offset()))
        , name(std::exchange(other.name, invalid_offset()))
        , value(std::move(other.value))
        {
        }

        compound_bucket& operator=(compound_bucket &&other) noexcept
        {
            assert(empty());
            assert(invalid_offset(next));
            next = std::exchange(other.next, invalid_offset());
            name = std::exchange(other.name, invalid_offset());
            value = std::move(other.value);
            return *this;
        }

        auto empty() const -> bool { return invalid_offset(name); }

        offset   next;   // position of the next bucket in case of a collision
        offset   name;
        data_ref value;
    };

    struct compound_header
    {
        compound_header(std::int32_t nbuckets)
        : type_(tag_type::Compound)
        , use_count_(1)
        , collisions_(0)
        , size_(0)
        , nbuckets_(nbuckets)
        {
            for (auto &bucket : buckets())
                new (&bucket) compound_bucket();
        }

        tag_type     type_;         // Tag_Compound
        std::uint8_t use_count_;    // reference count. deleted on zero
        std::int8_t  collisions_;   // number of detected collisions.
        std::int32_t size_;         // number of items in the structure
        std::int32_t nbuckets_;     // number of buckets

        // services

        auto get_bucket(std::uint32_t hash) -> compound_bucket * { return &(buckets()[hash % nbuckets_]); }

        // management

        static constexpr auto header_extent() -> std::size_t
        {
            constexpr auto header_alignment = alignof(compound_header);
            constexpr auto bucket_alignment = alignof(compound_bucket);
            using extent_t =
                std::aligned_storage_t< sizeof(compound_header), std::max(header_alignment, bucket_alignment) >;
            return sizeof(extent_t);
        }

        static constexpr auto extent(std::int32_t buckets)
        {
            return header_extent() + sizeof(compound_bucket) * buckets;
        }

        auto extent() const -> std::size_t { return extent(nbuckets_); }
        auto buckets() -> std::span< compound_bucket >
        {
            auto first = reinterpret_cast< compound_bucket * >(reinterpret_cast< char * >(this) + header_extent());
            auto last  = first + nbuckets_;
            return std::span< compound_bucket >(first, last);
        }

        auto is_valid() const -> bool { return this->type_ == tag_type::Compound; }

        auto addref() -> uint8_t
        {
            if (use_count_ < 255)
                ++use_count_;
            return use_count_;
        }

        auto release() -> uint8_t
        {
            assert(use_count_ != 0);
            if (use_count_ < 255)
                --use_count_;
            return use_count_;
        }
        auto use_count() const -> uint8_t { return use_count_; }
    };

    template < class Derived >
    struct const_compound_bucket_iterator
    {
        const_compound_bucket_iterator(Derived const *  host         = nullptr,
                                       compound_header *header       = nullptr,
                                       std::int32_t     bucket_index = 0,
                                       compound_bucket *bucket       = nullptr)
        : host(host)
        , header(header)
        , bucket_index(bucket_index)
        , bucket(bucket)
        {
        }

        using value_type        = compound_bucket const;
        using pointer           = value_type *;
        using reference         = value_type &;
        using difference_type   = std::ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        auto operator*() const -> reference
        {
            assert(host);
            assert(header);
            assert(bucket);

            return *bucket;
        }

        auto operator++() -> const_compound_bucket_iterator &
        {
            assert(host);
            assert(header);
            assert(bucket);

            if (not invalid_offset(bucket->next))
                bucket = host->template from_offset< compound_bucket >(bucket->next);
            else
            {
                bucket = header->get_bucket(++bucket_index);
            }

            return *this;
        }

        Derived const *  host;
        compound_header *header;
        std::int32_t     bucket_index;
        compound_bucket *bucket;
    };

    template < class Derived >
    struct compound_service
    {
        /// Create a new compound
        /// \param n a hint as to the number of items expected to be in the compound.
        /// \return the offset of the new or existing compound
        auto new_compound(std::int32_t n) -> compound_header *;

        /// Reduce the reference count of a compound and possibly destroy it
        /// \param id
        /// \return new use count. Destroyed if 0
        auto release_compound(offset id) -> std::uint8_t;

        /// Set a value into the compound. If the compound is rehashed as a result, return the new offset
        /// \param compound_id
        /// \param item_name
        /// \param value
        /// \return
        auto compound_set(offset compound_id, offset item_name, data_ref value) -> offset;

      private:
        /// Totally destroy the compund and release all objects in it
        /// \param hdr
        auto destruct(compound_header *hdr) -> void;
        auto destroy_contents(compound_bucket *hdr) -> compound_bucket *;
        auto destruct(compound_bucket *hdr) -> void;

        /// Return the bucket that matches the given name, if any.
        /// \param hdr
        /// \param name
        /// \return address of bucket (link) that contains the name, or nullptr if not found
        auto find_matching_bucket(compound_header *hdr, string_header *name) -> compound_bucket *;

        // might rehash so return the new offset
        auto insert_impl(compound_header *hdr, string_header *name, data_ref data) -> compound_header *;

        /// Link in a bucket that is known to be in allocated memory.
        /// \param hdr
        /// \param source
        auto link_allocated_bucket(compound_header *hdr, compound_bucket *source) -> void;

        /// Link a bucket that is known to be in another hash table
        /// \param hdr
        /// \param source
        auto link_static_bucket(compound_header *hdr, compound_bucket &source) -> void;
        auto unlink_after(compound_bucket *current) -> compound_bucket *;

        /// link a bucket (containing a value) into the hash table by moving data from the source bucket
        /// The source bucket is not freed but will be left in a guaranteed empty state
        /// @pre not source.empty()
        /// @post source.empty()
        /// @post hdr->size_ is increased by 1
        /// @return a pointer to the (now unlinked) next bucket that was in source
        [[nodiscard]] auto link_bucket(compound_header *hdr, compound_bucket &&source) -> compound_bucket *;

        /// link a bucket (containing a value) into the hash table by either
        /// * moving data from the source bucket (if it's going into a new head)
        /// * linking the bucket directly
        /// The source bucket may or may not be freed. If it is linked directly, ownership is transferred to hdr.
        /// If the data is moved from, source will be deallocated
        /// @pre not source.empty()
        /// @post source.empty()
        /// @post hdr->size_ is increased by 1
        /// @return a pointer to the (now unlinked) next bucket that was in source
        [[nodiscard]] auto link_bucket(compound_header *hdr, compound_bucket *source) -> compound_bucket *;

        auto replace_impl(compound_bucket *bucket, data_ref data) -> void;

        template<class...Args>
        auto new_bucket(Args&&...) -> compound_bucket *;
        auto maybe_rehash(compound_header *hdr) -> compound_header *;

      private:
        auto self() -> Derived *;
        auto self() const -> Derived const *;
    };
}   // namespace minecraft::nbt
