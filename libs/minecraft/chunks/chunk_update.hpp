#pragma once
#include "block_update.hpp"
#include "chunk_column_impl.hpp"
#include "chunk_section_impl.hpp"
#include "minecraft/variant.hpp"

#include <memory>

namespace minecraft::chunks
{
    struct chunk_update : chunk_service_traits
    {
        explicit chunk_update(std::unique_ptr< chunk_column_impl > p = nullptr)
        : var_(std::move(p))
        {
        }

        explicit chunk_update(std::vector< block_update > v)
        : var_(std::move(v))
        {
        }

        explicit chunk_update(block_update u)
        : var_(u)
        {
        }

        using value_type = variant< std::unique_ptr< chunk_column_impl >,
                                    block_update,
                                    update_sequence >;

        auto as_variant() -> value_type & { return var_; };
        auto as_variant() const -> value_type const & { return var_; };

      private:
        value_type var_;
    };

}   // namespace minecraft::chunks