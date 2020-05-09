
namespace minecraft::nbt
{
    //
    // <editor-fold desc="basic_hash_node_impl">
    //

    template < class M, class K >
    auto basic_hash_node_impl< M, K >::new_(key_ptr pkey) -> ptr< basic_hash_node_impl >
    {
        auto sp = pkey.storage();
        auto p  = sp->alloc(sizeof(basic_hash_node_impl));
        return ptr< basic_hash_node_impl >(sp, new (p) basic_hash_node_impl(pkey.to_ref()));
    }

    template < class M, class K >
    auto basic_hash_node_impl< M, K >::link(ptr< basic_hash_node_impl > pnew_node) -> ptr< basic_hash_node_impl >
    {
        auto my_next = this->next();   // ref
        this->next(pnew_node.to_ref());
        pnew_node->next(std::move(my_next));
        return pnew_node;
    }

    template < class M, class K >
    auto basic_hash_node_impl< M, K >::unlink_next(storage_provider *sp) -> ptr< basic_hash_node_impl >
    {
        auto pnext = next().to_ptr(sp);
        if (pnext)
        {
            next(pnext->next());
            pnext->next(ref< basic_hash_node_impl >());
        }
        return pnext;
    }

    // </editor-fold>

    //
    // <editor-fold desc="basic_hash_table_impl">
    //

    template < class M, class K >
    basic_hash_table_impl< M, K >::basic_hash_table_impl(storage_provider *sp, std::int32_t capacity)
    : capacity_(capacity)
    , size_(0)
    , collisions_(0)
    , buckets_(invalid_offset())
    {
        // allocate space for base buckets
        auto p       = reinterpret_cast< bucket_impl * >(sp->alloc(sizeof(bucket_impl) * capacity));
        auto pbucket = ptr< bucket_impl >(sp, p);

        // default-construct base buckets
        while (capacity--)
        {
            new (p) bucket_impl();
            ++p;
        }

        // store owning reference
        buckets_ = pbucket.to_ref();
    }

    template < class M, class K >
    auto basic_hash_table_impl< M, K >::new_(storage_provider *sp, std::int32_t capacity)
        -> ptr< basic_hash_table_impl >
    {
        return ptr< basic_hash_table_impl >(
            sp, new (sp->alloc(sizeof(basic_hash_table_impl))) basic_hash_table_impl(sp, capacity));
    }

    template < class M, class K >
    auto basic_hash_table_impl< M, K >::destroy(storage_provider *sp) -> void
    {
        for (auto &bucket : buckets(sp))
        {
            auto pbucket = ptr< bucket_impl >(sp, &bucket);
            if (pbucket->has_key())
            {
                while (auto punlinked = pbucket->unlink_next(sp))
                    delete_(punlinked);

                pbucket->destroy(sp);
            }
        }

        // then free the memory of the buckets
        sp->free(buckets_.to_ptr(sp).get(), sizeof(bucket_impl) * capacity_);
    }

    template < class M, class K >
    auto delete_(ptr< basic_hash_table_impl< M, K > > pheader) -> void
    {
        pheader->destroy(pheader.storage());
        pheader.storage()->free(pheader.get(), sizeof(*pheader));
    }

    template < class M, class K >
    auto basic_hash_table_impl< M, K >::acquire_node(ptr< basic_hash_table_impl > pself, key_type key) -> ptr< bucket_impl >
    {
        // note - invalidates existing base buckets and all pointers to nodes
        rehash_check(pself);

        auto pkey = key.to_ptr(pself.storage());

        auto pbase_bucket = ptr(pself.storage(), &pself->buckets(pself.storage())[pkey->hash() % pself->capacity()]);
        auto pcandidate   = pbase_bucket;
        do
        {
            auto has_key  = pcandidate->has_key();
            auto same_key = has_key and (*(pcandidate->key().to_ptr(pself.storage())) == *pkey);
            if (not has_key || same_key)
            {
                if (not has_key)
                    ++pself->size_;
                delete_(pcandidate->key(std::move(key)).to_ptr(pself.storage()));
                return pcandidate;
            }

            pcandidate = pcandidate->next().to_ptr(pself.storage());

        } while (pcandidate);

        ++pself->collisions_;
        ++pself->size_;
        // note: realloc possible here
        auto pnext = bucket_impl::new_(pkey);
        // bug here - could have reallocated
        return pbase_bucket->link(pnext);
    }

    template < class M, class K >
    auto basic_hash_table_impl< M, K >::buckets(storage_provider *sp) -> std::span< bucket_impl >
    {
        assert(not this->buckets_.empty());
        auto pv = this->buckets_.to_ptr(sp);
        return std::span< bucket_impl >(pv.get(), this->capacity_);
    }

    template < class M, class K >
    auto basic_hash_table_impl< M, K >::rehash_check(ptr<basic_hash_table_impl>) -> void
    {
    }

    // </editor-fold>

}   // namespace minecraft::nbt