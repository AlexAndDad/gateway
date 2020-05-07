#include "string_bucket.ipp"
#include <utility>
#include <cassert>

namespace minecraft::nbt
{
    hash_bucket_base::hash_bucket_base()
        : next(invalid_offset())
        , value(invalid_offset())
    {
    }

    hash_bucket_base::hash_bucket_base(offset value)
        : next(invalid_offset())
        , value(value)
    {
    }


    hash_bucket_base::hash_bucket_base(hash_bucket_base &&other) noexcept
        : next(std::exchange(other.next, invalid_offset()))
        , value(std::exchange(other.value, invalid_offset()))
    {
    }

    hash_bucket_base &hash_bucket_base::operator=(hash_bucket_base &&other) noexcept
    {
        assert(empty());
        assert(invalid_offset(next));
        next  = std::exchange(other.next, invalid_offset());
        value = std::exchange(other.value, invalid_offset());
        return *this;
    }

    auto deref_key(storage_provider *self, hash_bucket< void > *pbucket) -> string_header *
    {
        assert(pbucket);
        assert(not pbucket->empty());
        return self->template from_offset< string_header >(pbucket->value);
    }


}   // namespace minecraft::nbt