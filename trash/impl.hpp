#pragma once
#include "minecraft/nbt/free_block.hpp"
#include "minecraft/nbt/offset.hpp"
#include "minecraft/nbt/storage_provider.hpp"
#include "minecraft/net.hpp"
#include "minecraft/types/buffer.hpp"
#include "string_impl.hpp"
#include "compound_impl.hpp"
#include "generic_list_impl.hpp"

#include <boost/smart_ptr/make_shared.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <ostream>
#include <string_view>

namespace minecraft::nbt
{
    struct impl : storage_provider
    {
        /// Construct with a new memory buffer containing `blocks` blocks of storage space
        /// \param blocks the number of blocks to pre-allocate
        impl(std::int32_t initial_size = 100);
        impl(std::int32_t initial_size , std::size_t hash_poison);

        auto new_string(std::string_view sv) -> ptr< string_impl >;
        auto new_compound(std::int32_t capacity) -> ptr<compound_impl>;
        auto new_list(tag_type type, std::int32_t capacity) -> ptr<generic_list_impl>;

        friend void pretty_print(std::ostream &os, impl *self);
    };

    /// Parse a data stream into an impl, destroying the impl
    /// \param first
    /// \param last
    /// \param target
    /// \param ec
    /// \return
    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, impl &target, error_code &ec);

    void pretty_print(std::ostream &os, impl *self);

    using storage_ptr = std::unique_ptr< impl >;

}   // namespace minecraft::nbt