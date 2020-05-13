#pragma once
#include "compound.hpp"
#include "encoder.hpp"
#include "list.hpp"
#include "minecraft/parse_error.hpp"
#include "minecraft/types/buffer.hpp"
#include "pretty_printer.hpp"

namespace minecraft::nbt
{
    struct value
    {
        value();

        // clang-format off
        explicit value(compound c) : var_(std::move(c)) { }
        explicit value(list l) : var_(std::move(l)) { }
        explicit value(string l) : var_(std::move(l)) { }
        explicit value(byte_array l) : var_(std::move(l)) { }
        explicit value(int_array l) : var_(std::move(l)) { }
        explicit value(long_array l) : var_(std::move(l)) { }
        explicit value(std::int8_t const& l) : var_(std::move(l)) {}
        explicit value(std::int16_t const& l) : var_(std::move(l)) {}
        explicit value(std::int32_t const& l) : var_(std::move(l)) {}
        explicit value(std::int64_t const& l) : var_(std::move(l)) {}
        explicit value(double const& l) : var_(std::move(l)) {}
        explicit value(float const& l) : var_(std::move(l)) {}
        // clang-format on

        string& operator=(string s) {
            return var_.emplace<string>(std::move(s));
        }

        auto as_variant() const & -> value_variant const & { return var_; }
        auto as_variant() & -> value_variant & { return var_; }
        auto as_variant() && -> value_variant && { return std::move(var_); }

        template<class T, class...Args>
        auto emplace(Args&&...args) -> T&
        {
            return as_variant().emplace<T>(std::forward<Args>(args)...);
        }

        //
        // operators
        //

        auto operator[](std::int32_t const& n) -> list::setter;
        compound::mapped_type & operator[](string const& k);
        compound::mapped_type const& operator[](string const& k) const;

        bool     is(tag_type tag) const;
        tag_type type() const;

        compound &  get_compound();
        compound const &  get_compound() const;
        list &      get_list();
        list const &      get_list() const;
        string &    get_string();
        int_array & get_int_array();
        byte_array &get_byte_array();
        long_array &get_long_array();

        friend auto operator==(value const &l, value const &r) -> bool;
        friend auto operator!=(value const &l, value const &r) -> bool;
        friend void compose(value const &arg, compose_buffer &buf);
        friend auto operator<<(std::ostream& os, value const& v) -> std::ostream&;

        template <class Iter>
        friend Iter encode(value const &arg, Iter first)
        {
            compose_buffer buf;
            compose(arg, buf);

            return std::copy(std::begin(buf), std::end(buf), first);
        }

      private:
        value_variant var_;
    };

    auto pretty_print(value const &arg) -> pretty_printer;

    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, value &target, error_code &ec);
    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, value &target);

    template < class Visitor >
    auto visit(Visitor &&v, value const &val) -> decltype(auto)
    {
        return visit(std::forward< Visitor >(v), val.as_variant());
    }
}   // namespace minecraft::nbt
