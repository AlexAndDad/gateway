#pragma once
#include "ref.hpp"
#include "storage_provider.hpp"
namespace minecraft::nbt
{
    template < class T >
    struct ptr;

    template < class T >
    struct ptr_base
    {
        ptr_base(storage_provider *sp, ref< T > ref)
        : sp_(sp)
        , off_(ref.get_offset())
        {
        }

        ptr_base(storage_provider *sp, T *p)
        : sp_(sp)
        , off_(p ? sp->to_offset(p) : invalid_offset())
        {
        }

        auto operator+=(int n) -> ptr<T> &
        {
            off_ += sizeof(T) * n;
            return static_cast< ptr< T > & >(*this);
        }

        auto get() const -> T * { return sp_->from_offset< T >(off_); }

        template < class U >
        auto cast_static() const -> ptr< U >
        {
            return ptr< U >(storage(), static_cast< U * >(get()));
        }

        template < class U >
        auto cast() const -> ptr< U >
        {
            return ptr< U >(storage(), reinterpret_cast< U * >(get()));
        }

        explicit operator bool() const { return not invalid_offset(off_); }

        T *operator->() const { return get(); }

        storage_provider *storage() const { return sp_; }

        auto get_offset() const -> offset { return off_; }

        auto to_ref() const -> ref< T > { return ref< T >(get_offset()); }

      protected:
        storage_provider *sp_;
        offset            off_;
    };

    // a pointer that can be manipulated by c++
    template < class T >
    struct ptr : ptr_base< T >
    {
        using ptr_base< T >::ptr_base;

        T &operator*() const
        {
            auto p = this->get();
            assert(p);
            return *p;
        }

        T& operator[](std::int32_t i) const
        {
            return *(this->get() + i);
        }
    };

    template<class T>
    ptr(storage_provider* sp, T*) -> ptr<T>;

    template <  >
    struct ptr<void> : ptr_base<void >
    {
        using ptr_base< void >::ptr_base;
    };


    inline void delete_(ptr< void >) {};
    inline void delete_(ptr< std::uint8_t >) {};
    inline void delete_(ptr< std::int8_t >) {};
    inline void delete_(ptr< std::int16_t >) {};
    inline void delete_(ptr< std::int32_t >) {};
    inline void delete_(ptr< std::int64_t >) {};
    inline void delete_(ptr< float >) {};
    inline void delete_(ptr< double >) {};

    template < class T >
    struct is_ptr : std::false_type
    {
    };

    template < class T >
    struct is_ptr< ptr< T > > : std::true_type
    {
    };

    template < class T >
    constexpr bool is_ptr_v = is_ptr< T >::value;

}   // namespace minecraft::nbt