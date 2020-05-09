#pragma once
#include "empty_item.hpp"
#include "storage_provider.hpp"
#include "tag_type.hpp"

namespace minecraft::nbt
{
    /// contains a reference to the given type
    template < class T >
    struct ptr;

    // actual typed memory representing the offset of a structure (as opposed to a fundamental type)
    template < class T >
    struct ref
    {
        explicit ref(offset off = invalid_offset())
        : off_(off)
        {
        }

        ref(ptr< T > p);
        ref(ref const &other);
        ref(ref &&other);
        ref &operator=(ref const &other);
        ref &operator=(ref &&other);

        bool   empty() const { return invalid_offset(off_); }
        offset get_offset() const { return off_; }

        auto to_ptr(storage_provider *sp) const -> ptr< T >;

        void reset() { off_ = invalid_offset(); }

        operator bool() const { return not invalid_offset(off_); }

        friend auto operator==(ref const &a, ref const &b) -> bool { return a.off_ == b.off_; }

        friend auto operator!=(ref const &a, ref const &b) -> bool { return a.off_ != b.off_; }

      private:
        offset off_;
    };

    template < class T >
    void destroy_(storage_provider *sp, ref< T > &ref);

}   // namespace minecraft::nbt

#include "ref_impl.hpp"
