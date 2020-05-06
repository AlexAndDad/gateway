#pragma once
#include "error.hpp"
#include "string_service/string_hash_table.hpp"
namespace minecraft::nbt
{
    template < class Derived >
    auto string_service< Derived >::acquire_global_hash_table() -> string_hash_table *
    {
        if (invalid_offset(global_hash_table_))
        {
            auto ht            = new_hash_table< void >(self(), 1);
            global_hash_table_ = self()->to_offset(ht);
            return ht;
        }
        else
        {
            return self()->template from_offset< string_hash_table >(global_hash_table_);
        }
    }

    template < class Derived >
    auto string_service< Derived >::acquire_string(std::string_view str) -> offset
    {
        auto hashtab              = acquire_global_hash_table();
        auto string_hash          = self()->hash(str);
        auto [bucket_id, pbucket] = lookup(self(), hashtab, string_hash, str);
        string_header *presult    = nullptr;
        if (pbucket)
        {
            presult = deref_key(self(), pbucket);
            presult->addref();
        }
        else
        {
            presult                      = new_string(string_hash, str);
            auto [new_table, new_bucket] = insert(self(), hashtab, presult);
            global_hash_table_           = self()->to_offset(new_table);
        }

        return self()->to_offset(presult);
    }

    template < class Derived >
    auto string_service< Derived >::new_string(std::uint32_t hash, std::string_view s) -> string_header *
    {
        if (s.size() > string_header::max_string_size())
            throw system_error(error::string_too_large);

        return new (self()->alloc(size_to_blocks(string_header::extent(s.size())))) string_header(hash, s);
    }

    template < class Derived >
    auto string_service< Derived >::release_string(offset id) -> std::uint8_t
    {
        string_header *hdr       = self()->template from_offset< string_header >(id);
        auto           use_count = hdr->release();
        if (use_count == 0)
        {
            // string no longer used, so free it
            // first remove from global hash table
            auto hash_tab         = self()->template from_offset< string_hash_table >(global_hash_table_);
            auto [index, pbucket] = lookup(self(), hash_tab, hdr->hash, std::string_view(hdr->data(), hdr->size()));
            assert(pbucket);
            unlink(self(), hash_tab, index, pbucket);
            self()->free(hdr, size_to_blocks(hdr->extent()));
        }
        return use_count;
    }

    template < class Derived >
    auto string_service< Derived >::resolve(offset string_id) -> string_header *
    {
        auto result = self()->template from_offset< string_header >(string_id);
        assert(result->is_valid());
        return result;
    }

    template < class Derived >
    auto string_service< Derived >::self() -> Derived *
    {
        return static_cast< Derived * >(this);
    }

    template < class Derived >
    auto string_service< Derived >::self() const -> Derived const *
    {
        return static_cast< Derived const * >(this);
    }

    /*
    template < class Derived >
    auto string_service< Derived >::lookup_string(hash_table *ht, std::uint32_t hash, std::string_view s)
        -> string_header *
    {
        auto bucket_index = hash % ht->size();
        auto bucket       = &(*ht)[bucket_index];

        // search for the current string in the bucket

        while (bucket)
        {
            for (auto &soffset : bucket->locations)
                if (string_equal(soffset, s))
                {
                    return self()->template from_offset< string_header >(soffset);
                    break;
                }
            bucket = self()->template from_offset< hash_bucket >(bucket->next_bucket);
        }
        return nullptr;
    }

    template < class Derived >
    auto string_service< Derived >::string_equal(offset a, std::string_view b) const -> bool
    {
        auto sa = self()->template from_offset< string_header >(a);
        if (sa)
            return (*sa) == b;
        else
            return false;
    }


    template < class Derived >
    auto string_service< Derived >::emplace_string(hash_table *ht, std::uint32_t hash, std::string_view s)
        -> string_header *
    {
        auto loc = self()->find_empty_slot(ht, hash);
        assert(loc);
        // @todo: if no entry, alloc new slot or rehash

        // refcount of sp will be 1
        auto sp = new_string(hash, s);
        if (sp)
        {
            *loc = self()->to_offset(sp);
        }
        return sp;
    }

    template < class Derived >
    auto string_service< Derived >::acquire_string(std::string_view str) -> offset
    {
        auto ht       = acquire_global_hash_table();
        auto hash     = self()->hash(str);
        auto existing = self()->lookup_string(ht, hash, str);
        if (existing)
        {
            existing->addref();
        }
        else
        {
            existing = emplace_string(ht, hash, str);
        }
        return self()->to_offset(existing);
    }

    template < class Derived >
    auto string_service< Derived >::string_get_hash(offset id) -> std::uint32_t
    {
        auto str = self()->template from_offset<string_header>(id);
        assert(str);
        assert(str->is_valid());
        return str->hash;
    }


*/
}   // namespace minecraft::nbt