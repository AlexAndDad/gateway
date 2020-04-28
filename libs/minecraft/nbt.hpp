#pragma once

#include "minecraft/nbt/nbt_end.hpp"
#include "minecraft/nbt/tags.hpp"
#include "minecraft/net.hpp"

#include <stack>
#include "minecraft/variant.hpp"


namespace minecraft::nbt
{
    using value_variant = variant< nbt::nbt_end >;

    struct value
    {
        explicit value(nbt::nbt_end val = {})
        : value_(val)
        {
        }

        bool operator==(value const &other) const;

        value_variant &      as_variant() { return value_; }
        value_variant const &as_variant() const { return value_; }

        template < class T >
        value &assign(T &&x)
        {
            value_ = std::forward< T >(x);
            return *this;
        }

        auto operator=(nbt_end arg) -> value & { return assign(std::move(arg)); }

        value_variant value_;
    };

    std::ostream &operator<<(std::ostream &os, value const &arg);

    template < class Iter >
    Iter encode(value const &arg, Iter iter);

    template < class Iter >
    Iter parse(Iter first, Iter last, value &arg, error_code &ec);

    WISE_ENUM_CLASS((endian, std::uint8_t), (big, 0), (little, 1));

    struct endian_stack
    {
        void push(endian e) { stack_.push(e); }

        void pop() { stack_.pop(); }

        endian query() const
        {
            if (stack_.empty())
                return endian::big;
            else
                return stack_.top();
        }

        static thread_local std::stack< endian > stack_;
    };

    struct set_endian : private endian_stack
    {
        set_endian(endian e) { push(e); }
        set_endian(endian const&) = delete;
        set_endian& operator=(endian const&) = delete;
        ~set_endian() { pop(); }
    };

}   // namespace minecraft::nbt

#include "minecraft/nbt.ipp"
