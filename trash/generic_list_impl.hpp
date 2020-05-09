#pragma once
#include "array_impl.hpp"
#include "atom.hpp"
#include "ptr.hpp"
#include "ref.hpp"

#include <cstddef>
#include <cstdint>

namespace minecraft::nbt
{
    struct string_impl;

    struct generic_list_impl
    {
        generic_list_impl(storage_provider *sp, tag_type type, std::int32_t capacity);

        auto append(storage_provider *sp, ref< string_impl > rstr) -> void;
        auto append(storage_provider *sp, ref< generic_list_impl > arg) -> void;
        auto append(storage_provider *sp, ref< byte_array_impl > arg) -> void;
        auto append(storage_provider *sp, ref< int_array_impl > arg) -> void;
        auto append(storage_provider *sp, ref< long_array_impl > arg) -> void;
        auto append(storage_provider *sp, std::int64_t const &arg) -> void;
        auto append(storage_provider *sp, std::int32_t const &arg) -> void;
        auto append(storage_provider *sp, std::int16_t const &arg) -> void;
        auto append(storage_provider *sp, std::int8_t const &arg) -> void;
        auto append(storage_provider *sp, double const &arg) -> void;
        auto append(storage_provider *sp, float const &arg) -> void;

        std::size_t data_extent(storage_provider *sp);

        auto size() const -> std::int32_t { return size_; }

        auto type() const -> tag_type { return type_; }

        template < class F >
        auto visit_element(storage_provider *sp, F &&f, std::int32_t n) -> decltype(auto);

        /// visit the data reference
        /// \tparam F
        /// \param sp
        /// \param f called with a ptr<X> where X corresponds to the type of the list
        /// \return
        template < class F >
        auto visit_data(storage_provider *sp, F &&f) -> decltype(auto);

        static ptr< generic_list_impl > new_(storage_provider *sp, tag_type type, std::int32_t capacity);

      private:
        static void init(ptr< generic_list_impl > p);

        template < class T >
        T *capacity_check(storage_provider *sp);

      private:
        std::int32_t capacity_;
        std::int32_t size_;
        ref< void >  data_;
        tag_type     type_;

        friend void delete_(ptr< generic_list_impl > plist);
        friend void destroy_(ptr< generic_list_impl > plist);
    };

}   // namespace minecraft::nbt

#include "generic_list_impl.ipp.hpp"
