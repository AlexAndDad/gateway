#pragma once
#include "array_impl.hpp"
#include "atom.hpp"
#include "generic_list_impl.hpp"
#include "hash_table_impl.hpp"
#include "ptr.hpp"
#include "ref.hpp"
#include "string_impl.hpp"

#include <span>

namespace minecraft::nbt
{
    struct compound_bucket_impl;

    template <>
    struct basic_hash_node_storage< atom_storage >
    {
        using mapped_type = atom_storage;
        using key_type    = ref< string_impl >;
        using node_type   = ref< basic_hash_node_impl< mapped_type, key_type > >;

        basic_hash_node_storage(key_type key)
        : atom_()
        , key_(std::move(key))
        , next_()
        , type_(tag_type::End)
        {
        }

        // basic interface
        auto next() const -> node_type { return next_; }
        auto next(node_type n) -> void { next_ = std::move(n); }
        auto key() const -> key_type const & { return key_; }
        auto key(key_type key_override) -> key_type
        {
            return std::exchange(key_, std::move(key_override));
        }

        void destroy(storage_provider *sp);

        // extended interface
        auto has_value() const -> bool { return type_ != tag_type::End; }

        auto set_value(storage_provider *sp, empty_item) -> void;
        auto set_value(storage_provider *sp, ref< string_impl > arg) -> void;
        auto set_value(storage_provider *sp, ref< generic_list_impl > arg) -> void;
        auto set_value(storage_provider *sp, ref< compound_impl > arg) -> void;
        auto set_value(storage_provider *sp, ref< byte_array_impl > arg) -> void;
        auto set_value(storage_provider *sp, ref< long_array_impl > arg) -> void;
        auto set_value(storage_provider *sp, ref< int_array_impl > arg) -> void;
        auto set_value(storage_provider *sp, std::string_view arg) -> void;
        auto set_value(storage_provider *sp, std::int8_t value) -> void;
        auto set_value(storage_provider *sp, std::int16_t value) -> void;
        auto set_value(storage_provider *sp, std::int32_t value) -> void;
        auto set_value(storage_provider *sp, std::int64_t value) -> void;
        auto set_value(storage_provider *sp, float value) -> void;
        auto set_value(storage_provider *sp, double value) -> void;

        auto atom() const -> atom_storage const& { return atom_; }
        auto atom() -> atom_storage & { return atom_; }
        auto type() const -> tag_type const&  { return type_; }
        auto type()  -> tag_type&  { return type_; }

      private:
        atom_storage atom_;
        key_type     key_;
        node_type    next_;
        tag_type     type_;
    };

    struct compound_impl : basic_hash_table_impl< atom_storage >
    {
        using super = basic_hash_table_impl< atom_storage >;

        using basic_hash_table_impl< atom_storage >::basic_hash_table_impl;

        static auto new_(storage_provider *sp, std::int32_t capacity = 1) -> ptr< compound_impl >;

        template<class T> auto set(storage_provider* sp, ref<string_impl>key , ref<T> value) -> void;

/*
        auto set(storage_provider *sp, ref< string_impl > key, ref< byte_array_impl > value) -> void;
        auto set(storage_provider *sp, ref< string_impl > key, ref< compound_impl > value) -> void;
        auto set(storage_provider *sp, ref< string_impl > key, ref< int_array_impl > value) -> void;
        auto set(storage_provider *sp, ref< string_impl > key, ref< long_array_impl > value) -> void;
        auto set(storage_provider *sp, ref< string_impl > key, ref< string_impl > value) -> void;
        auto set(storage_provider *sp, ref< string_impl > key, ref< generic_list_impl > value) -> void;
*/
        auto set(storage_provider *sp, ref< string_impl > key, empty_item value) -> void;
        auto set(storage_provider *sp, ref< string_impl > key, std::int8_t value) -> void;
        auto set(storage_provider *sp, ref< string_impl > key, std::int16_t value) -> void;
        auto set(storage_provider *sp, ref< string_impl > key, std::int32_t value) -> void;
        auto set(storage_provider *sp, ref< string_impl > key, std::int64_t value) -> void;
        auto set(storage_provider *sp, ref< string_impl > key, float value) -> void;
        auto set(storage_provider *sp, ref< string_impl > key, double value) -> void;

        template < class F >
        auto visit_elements(storage_provider *sp, F &&f) -> void;

        friend auto delete_(ptr< compound_impl > pcmp) -> void;
    };

}   // namespace minecraft::nbt

#include "compound_impl.ipp.hpp"
