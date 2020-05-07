//
// Created by rhodges on 05/05/2020.
//

#include "compound_service.hpp"

#include "compound_service.ipp"
#include "impl.hpp"

namespace minecraft::nbt
{
    template struct compound_service< impl >;

    template void
    print< impl >(std::ostream &os, impl *self, std::string_view name, compound_header *hdr, std::size_t depth);

    auto compound_service_base::compound_advise_buckets(std::int32_t anticipated_size) -> std::int32_t
    {
        auto n = double(anticipated_size) * 1.3;
        auto result = std::min(7, next_prime(std::int32_t(n)));
        return result;
    }

    void compound_service_base::deallocate(storage_provider *storage, compound_header *hdr)
    {
        if (hdr)
            storage->free(hdr, size_to_blocks(hdr->extent()));
    }

    void compound_service_base::deallocate(storage_provider *storage, compound_bucket *bucket)
    {
        if (bucket)
            storage->free(bucket, size_to_blocks(bucket->extent()));
    }

    // destroy contents then destroy and free all extension buckets
    void compound_service_base::destroy_contents(storage_provider *storage, compound_bucket &base)
    {
        while (auto next = unlink(storage, &base))
        {
            deallocate(storage, destroy(storage, next));
        }
        destroy(storage, &base);
    }

    auto compound_service_base::destroy(storage_provider *storage, compound_bucket *bucket) -> compound_bucket *
    {
        assert(storage);
        assert(bucket);
        assert(not bucket->empty());

        minecraft::nbt::release(storage, bucket->value_type, bucket->value_atom);
        return bucket;
    }

    auto compound_service_base::destroy(storage_provider *storage, compound_header *hdr) -> compound_header *
    {
        if (hdr)
        {
            for (auto &bucket : hdr->buckets())
                destroy_contents(storage, bucket);
        }
        return hdr;
    }

    auto compound_service_base::unlink(storage_provider* storage, compound_bucket* prev) -> compound_bucket*
    {
        compound_bucket* result = nullptr;
        if (prev)
        {
            result = storage->from_offset<compound_bucket>(prev->next);
            if (result)
                prev->next = std::exchange(result->next, invalid_offset());
        }
        return result;
    }


    std::int8_t  compound_service_base::release(storage_provider *storage, compound_header *cmp)
    {
        deallocate(storage, destroy(storage, cmp));
        return 0;
    }

    void compound_pretty_printer::operator()(std::ostream &os) const
    {
        auto indent = [&] { return std::string(depth, ' '); };
        fmt::print(os, "{0}{1}('{2}') : {3} entries\n{0}{{\n", indent(), tag_type::Compound, this->name, hdr->size_);

        auto print_bucket = [&](compound_bucket &b) {
            auto pname = storage->from_offset< string_header >(b.name);
            auto n     = std::string_view(pname->data(), pname->size());
            pretty_print(os, storage, n, data_ref(b.value_type, b.value_atom), depth+2);
        };
        for (auto &root_bucket : hdr->buckets())
        {
            if (root_bucket.empty())
                continue;
            auto pbucket = &root_bucket;
            while (pbucket)
            {
                print_bucket(*pbucket);
                pbucket = storage->from_offset< compound_bucket >(pbucket->next);
            }
        }

        fmt::print(os, "{0}}}\n", indent());
    }

}   // namespace minecraft::nbt