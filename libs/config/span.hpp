#pragma once
#include "config/net.hpp"

#include <iterator>

namespace config
{
    template < class Iter >
    struct iter_span
    {
        using iterator   = Iter;
        using const_iterator = Iter;
        using value_type = typename std::iterator_traits< Iter >::value_type;

        constexpr iter_span(Iter first, Iter last)
        : first_(first)
        , last_(last)
        {
            assert(last_ >= first_);
        }

        constexpr Iter begin() const { return first_; }

        constexpr Iter end() const { return last_; }

        constexpr std::size_t size() const { return last_ - first_; }

        constexpr auto data() const { return first_; }

      private:
        Iter first_, last_;
    };

    template < class Iter, std::size_t I >
    constexpr auto get(iter_span< Iter > const &span)
    {
        static_assert(I < 2);

        if constexpr (I == 0)
            return span.begin();
        else
            return span.end();
    }

    using mutable_byte_span = iter_span< char * >;
    using const_byte_span   = iter_span< const char * >;

    inline auto to_span(net::const_buffer buf)
    {
        auto first = reinterpret_cast< const char * >(buf.data());
        auto last  = first + buf.size();
        return const_byte_span(first, last);
    }

    inline auto to_span(net::mutable_buffer buf)
    {
        auto first = reinterpret_cast< char * >(buf.data());
        auto last  = first + buf.size();
        return mutable_byte_span(first, last);
    }

}   // namespace config

namespace std
{
    template < class Iter >
    struct tuple_size< config::iter_span< Iter > > : std::integral_constant< std::size_t, 2 >
    {
    };
}   // namespace std
