#pragma once
#include "minecraft/nbt/compound_service.hpp"
#include "minecraft/nbt/free_block.hpp"
#include "minecraft/nbt/fundamental.hpp"
#include "minecraft/nbt/offset.hpp"
#include "minecraft/nbt/storage_provider.hpp"
#include "minecraft/nbt/string_service.hpp"
#include "minecraft/nbt/data_service.hpp"

#include <boost/smart_ptr/make_shared.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <string_view>

namespace minecraft::nbt
{
    struct impl
    : storage_provider
    , string_service< impl >
    , hash_table_service< impl >
    , compound_service< impl >
    , data_service<impl>
    {
        /// Construct with a new memory buffer containing `blocks` blocks of storage space
        /// \param blocks the number of blocks to pre-allocate
        impl();

        std::int32_t root_object_;   // position of first structure (-1 for empty)
    };

    /// Parse a data stream into an impl, destroying the impl
    /// \param first
    /// \param last
    /// \param target
    /// \param ec
    /// \return
    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, impl& target, error_code& ec);

    using storage_ptr = boost::shared_ptr< impl >;

}   // namespace minecraft::nbt