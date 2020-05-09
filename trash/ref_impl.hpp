#include "ptr.hpp"

namespace minecraft::nbt
{
    template < class T >
    ref< T >::ref(ptr<T> p)
    : off_(p.get_offset())
    {
    }

    template < class T >
    ref< T >::ref(ref const &other)
    : off_(other.off_)
    {
    }

    template < class T >
    ref< T >::ref(ref &&other)
    : off_(std::exchange(other.off_, invalid_offset()))
    {
    }

    template < class T >
    auto ref< T >::operator=(ref const &other) -> ref &
    {
        off_ = other.off_;
        return *this;
    }

    template < class T >
    auto ref< T >::operator=(ref &&other) -> ref &
    {
        off_ = std::exchange(other.off_, invalid_offset());
        return *this;
    }

    template < class T >
    auto ref< T >:: to_ptr(storage_provider* sp) const -> ptr<T>
    {
        return ptr<T>(sp, *this);
    }

    template<class T>
    void destroy_(storage_provider* sp, ref<T>& ref)
    {
        delete_(ptr<T>(sp, std::move(ref)));
    }



}
