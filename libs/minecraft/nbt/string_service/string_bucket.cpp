#include "string_bucket.ipp"

#include <cassert>
#include <utility>

namespace minecraft::nbt
{
    hash_bucket_base::hash_bucket_base()
    : next()
    , value()
    {
    }

    hash_bucket_base::hash_bucket_base(offset value)
    : next()
    , value(std::move(value))
    {
    }

    hash_bucket_base::hash_bucket_base(hash_bucket_base &&other) noexcept
    : next(std::move(other.next))
    , value(std::move(other.value))
    {
    }


    auto deref_key(storage_provider *self, hash_bucket< void > *pbucket) -> string_header *
    {
        assert(pbucket);
        assert(not pbucket->empty());
        return self->template from_offset< string_header >(pbucket->value);
    }

}   // namespace minecraft::nbt