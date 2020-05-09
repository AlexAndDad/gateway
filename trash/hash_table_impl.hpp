#pragma once
#include "ptr.hpp"
#include "ref.hpp"
#include "string_impl.hpp"

#include <boost/mp11/list.hpp>
#include <span>

namespace minecraft::nbt
{
    template < class MappedType = void, class KeyType = ref< string_impl > >
    struct basic_hash_node_impl;

    template < class MappedType = void, class KeyType = ref< string_impl > >
    struct basic_hash_node_storage
    {
        using mapped_type = MappedType;
        using key_type    = KeyType;
        using node_type   = ref< basic_hash_node_impl< mapped_type, key_type > >;

        basic_hash_node_storage(key_type key = key_type())
        : next_()
        , key_(std::move(key))
        {
        }

        auto next() const -> node_type { return next_; }
        auto next(node_type n) -> void { next_ = std::move(n); }

        auto key() const -> key_type const & { return key_; }
        auto key(key_type key_override) -> void
        {
            assert(key_.empty());
            key_ = std::move(key_override);
        }

        void destroy(storage_provider *sp)
        {
            assert(next_.empty());
            destroy_(key_.to_ptr(sp));
        }

      private:
        node_type next_;
        key_type  key_;
    };

    template < class MappedType, class KeyType >
    struct basic_hash_node_impl : basic_hash_node_storage< MappedType, KeyType >
    {
        using storage_type = basic_hash_node_storage< MappedType, KeyType >;
        using key_type     = typename storage_type::key_type;
        using mapped_type  = typename storage_type::mapped_type;
        using key_ptr      = boost::mp11::mp_rename< key_type, ptr >;

        static auto new_(key_ptr pkey) -> ptr< basic_hash_node_impl >;
        explicit basic_hash_node_impl(key_type key = key_type())
        : storage_type(std::move(key))
        {
        }

        using storage_type::destroy;
        using storage_type::key;
        using storage_type::next;

        auto has_key() const -> bool { return not key().empty(); }

        /// Link the given node such that it becomes this node's next
        /// Return the pointer to the next node
        auto link(ptr< basic_hash_node_impl >) -> ptr< basic_hash_node_impl >;
        auto unlink_next(storage_provider *sp) -> ptr< basic_hash_node_impl >;

      protected:
        friend auto delete_(ptr< basic_hash_node_impl > pbucket) -> void
        {
            auto sp = pbucket.storage();
            pbucket->destroy(sp);
            sp->free(pbucket.get(), sizeof(*pbucket));
        }
    };

    struct hash_table_base
    {
        static auto estimate_bucket_count(std::int32_t entries) -> std::int32_t;
    };

    template < class MappedType, class KeyType = ref< string_impl > >
    struct basic_hash_table_impl : hash_table_base
    {
        using bucket_impl = basic_hash_node_impl< MappedType, KeyType >;
        using key_type    = typename bucket_impl::key_type;
        using mapped_type = typename bucket_impl::mapped_type;
        using key_ptr     = typename boost::mp11::mp_rename< key_type, ptr >;

        // constructor set
        static auto new_(storage_provider *sp, int32_t capacity) -> ptr< basic_hash_table_impl >;
        basic_hash_table_impl(storage_provider *sp, std::int32_t capacity);

        auto capacity() -> std::int32_t { return capacity_; }
        auto size() -> std::int32_t { return size_; }
        auto collisions() -> std::int32_t { return collisions_; }

        /// Acquire a node matching key. May cause a rehash and a global realloc
        /// \param key pointer to the key identifiying the bucket
        /// \return pointer to the associated bucket. Guaranteed to exist, but not guaranteed without an existing value
        /// @post the map shall contain a matching key
        static auto acquire_node(ptr< basic_hash_table_impl > pself, key_type key) -> ptr< bucket_impl >;

        auto buckets(storage_provider *sp) -> std::span< bucket_impl >;

        static auto rehash_check(ptr< basic_hash_table_impl > pself) -> void;

      protected:
        auto destroy(storage_provider *sp) -> void;

      private:
        std::int32_t       capacity_;
        std::int32_t       size_;
        std::int32_t       collisions_;
        ref< bucket_impl > buckets_;

        friend auto        delete_(ptr< basic_hash_table_impl > ptr) -> void;
        ptr< bucket_impl > link(ptr< bucket_impl > new_bucket);
    };

}   // namespace minecraft::nbt

#include "hash_table_impl.ipp.hpp"
