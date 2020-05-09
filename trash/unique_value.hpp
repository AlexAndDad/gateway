#pragma once
#include "atom.hpp"
#include "impl.hpp"
#include "minecraft/net.hpp"
#include "minecraft/types/buffer.hpp"
#include "pretty_printer.hpp"
#include "value_ref.hpp"

namespace minecraft::nbt
{
    struct compound;
    struct string;

    struct unique_value
    {
        using impl_type = boost::shared_ptr<impl>;

        unique_value(impl_type sp = {})
        : storage_(std::move(sp))
        , value_()
        {
        }

        unique_value(unique_value &&other) = default;
        unique_value &operator=(unique_value &&other) = default;
        unique_value(unique_value const &other)       = delete;
        unique_value &operator=(unique_value const &other) = delete;
        ~unique_value();

        bool empty() const { return (not storage_) or (value_.empty()); }
        bool is_compound() const { return storage_ and value_.type == tag_type::Compound; }
        bool is_list() const { return storage_ and value_.type == tag_type::List; }
        bool is_string() const { return storage_ and value_.type == tag_type::String; }
        bool is_byte() const { return value_.type == tag_type::Byte; }
        bool is_short() const { return value_.type == tag_type::Short; }
        bool is_int() const { return value_.type == tag_type::Int; }
        bool is_long() const { return value_.type == tag_type::Long; }
        bool is_double() const { return value_.type == tag_type::Double; }
        bool is_float() const { return value_.type == tag_type::Float; }


        //
        // Compound interface
        //
        auto set(std::string_view name, std::string_view value) -> void;
        auto create_compound() -> unique_value &;

        //
        // aggregate interface (Lists, Compound, String, Int_List, etc will return the number of elements)
        // values will return 1
        // if empty, 0
        //

        auto size() const -> std::int32_t;
        auto storage() const -> impl_type { return storage_; }

      private:
        auto destroy_state() -> void;
        auto ensure_storage() -> impl_type;

      private:
        boost::shared_ptr< impl > storage_;
        value_ref                 value_;

        friend auto parse(const_buffer_iterator first, const_buffer_iterator last, unique_value &val, error_code &ec)->const_buffer_iterator;
        friend auto pretty_print(unique_value const &uv) -> pretty_printer;
    };

}   // namespace minecraft::nbt