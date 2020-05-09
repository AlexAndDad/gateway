#include "atom.hpp"
#include "array_impl.hpp"
#include "string_impl.hpp"
#include "generic_list_impl.hpp"
#include "compound_impl.hpp"

namespace minecraft::nbt
{
    struct atom_destroyer
    {
        template < class T >
        auto operator()(storage_provider *sp, ref< T > &r) const -> void
        {
            if (not r.empty())
            {
                delete_(r.to_ptr(sp));
                r.reset();
            }
        }
        template < class T >
        auto operator()(storage_provider *, T &) const -> void
        {
        }
    };

    void destroy_(storage_provider *sp, tag_type& type, atom_storage &atom)
    {
        visit_atom(sp, atom_destroyer(), type, atom);
        type = tag_type::End;
    }

    auto deconstruct(tag_type type, atom_storage &target) -> void
    {
        visit_atom(
            [](auto &arg) {
                using type = std::decay_t< decltype(arg) >;
                arg.~type();
            },
            type,
            target);
    }

    auto move_construct(tag_type type, atom_storage &target, atom_storage &&source) -> void
    {
        visit_atom(
            [&](auto &tgt) {
                visit_atom(
                    [&tgt](auto &src) {
                        if constexpr (std::is_same_v< decltype(tgt), decltype(src) >)
                            tgt = std::move(src);
                    },
                    type,
                    source);
            },
            type,
            target);
    }
    auto copy_construct(tag_type type, atom_storage &target, const atom_storage &source) -> void
    {
        visit_atom(
            [&](auto &tgt) {
                visit_atom(
                    [&tgt](auto &src) {
                        if constexpr (std::is_same_v< std::decay_t<decltype(tgt)>, std::decay_t<decltype(src)> >)
                            tgt = src;
                    },
                    type,
                    source);
            },
            type,
            target);
    }
    auto default_initialise(tag_type type, atom_storage &target) -> void {
        visit_atom(
            [&](auto &tgt) {
                tgt = std::decay_t<decltype(tgt)>();
            },
            type,
            target);
    }


}   // namespace minecraft::nbt
