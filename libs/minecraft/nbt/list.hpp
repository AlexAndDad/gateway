#pragma once
#include "config.hpp"

namespace minecraft::nbt
{
    struct list
    {
        list(tag_type type = tag_type::Byte);

        template < class T >
        void push_back(T &&arg);

        void reserve(std::int32_t cap);

        auto type_name() const -> std::string_view;

        auto size() const -> std::int32_t;

        template < class F >
        auto visit_all(F &&f) const -> decltype(auto);

        template < class F >
        static auto visit_tag(F &&f, tag_type type) -> decltype(auto);

        friend auto operator==(list const& a, list const& b) -> bool;

        struct setter
        {
            list* p;
            std::int32_t i;

            template<class T> auto operator=(T&& v)
            {
                p->set(i, std::forward<T>(v));
            }
        };

        setter operator[](std::int32_t i)
        {
            return setter{this, i};
        }

        list_variant& as_variant() & { return var_; }
        list_variant&& as_variant() && { return std::move(var_); }
        list_variant const& as_variant() const & { return var_; }

        template<class T>
        auto set(std::size_t n, T&& v) -> decltype(auto)
        {
            visit([&](auto& actual){
                auto& z = actual.at(n);
                z = std::forward<T>(v);
                return z;
            }, as_variant());
        }

      private:
        list_variant var_;
    };

}   // namespace minecraft::nbt

#include "value.hpp"

namespace minecraft::nbt
{
    template < class F >
    auto list::visit_tag(F &&f, tag_type type) -> decltype(auto)
    {
        switch (type)
        {
        default:
        case tag_type::End: return f(tag_c< tag_type::End >);
        case tag_type::Byte: return f(tag_c< tag_type::Byte >);
        case tag_type::Short: return f(tag_c< tag_type::Short >);
        case tag_type::Int: return f(tag_c< tag_type::Int >);
        case tag_type::Long: return f(tag_c< tag_type::Long >);
        case tag_type::Double: return f(tag_c< tag_type::Double >);
        case tag_type::Float: return f(tag_c< tag_type::Float >);
        case tag_type::String: return f(tag_c< tag_type::String >);
        case tag_type::Compound: return f(tag_c< tag_type::Compound >);
        case tag_type::List: return f(tag_c< tag_type::List >);
        case tag_type::Byte_Array: return f(tag_c< tag_type::Byte_Array >);
        case tag_type::Int_Array: return f(tag_c< tag_type::Int_Array >);
        case tag_type::Long_Array: return f(tag_c< tag_type::Long_Array >);
        }
    }

    template < class T >
    void list::push_back(T &&arg)
    {
        if constexpr (std::is_same_v<std::decay_t<T>, value>)
        {
            visit([&]<class A2>(A2&& arg2){
                this->push_back(std::forward<A2>(arg2));
            }, std::forward<T>(arg).as_variant());
        }
        else
        {
            visit(
                [&]< class Val >(list_impl< Val > &vec) {
                    if constexpr (std::is_same_v< std::decay_t< T >, Val >)
                        vec.push_back(std::forward< T >(arg));
                    else
                        throw "not possible";
                },
                var_);
        }
    }

    template < class F >
    auto list::visit_all(F &&f) const -> decltype(auto)
    {
        visit(
            [f = std::forward< F >(f)](auto &&vec) mutable {
                for (auto &elem : vec)
                    f(elem);
            },
            var_);
    }

}   // namespace minecraft::nbt
