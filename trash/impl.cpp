#include "minecraft/nbt/impl.hpp"

#include "atom.hpp"
#include "generic_list_impl.hpp"
#include "impl_parse_handler.hpp"
#include "parse_context.hpp"
#include "ptr.hpp"
#include "string_impl.hpp"
#include "value_ref.hpp"

#include <boost/functional/hash.hpp>
#include <string_view>

namespace minecraft::nbt
{
    impl::impl(std::int32_t initial_size)
    : storage_provider(initial_size)
    {
    }

    impl::impl(std::int32_t initial_size, std::size_t hash_poison)
    : storage_provider(initial_size, hash_poison)
    {
    }

    auto impl::new_list(tag_type type, std::int32_t capacity) -> ptr< generic_list_impl >
    {
        return generic_list_impl::new_(this, type, capacity);
    }

    auto impl::new_string(std::string_view sv) -> ptr< string_impl > { return string_impl::new_(this, sv); }

    auto impl::new_compound(std::int32_t capacity) -> ptr< compound_impl >
    {
        return compound_impl::new_(this, compound_impl::estimate_bucket_count(capacity));
    }

    // -- parse

    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, impl &target, error_code &ec)
    {
        if (ec)
            return first;

        auto parser  = impl_parse_handler(target);
        auto context = parse_context(parser);
        first        = context.parse_value(first, last);
        ec           = context.error();

        return first;
    }

    void pretty_print(std::ostream &os, impl *self) { boost::ignore_unused(os, self); }

}   // namespace minecraft::nbt