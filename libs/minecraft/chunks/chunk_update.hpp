#pragma once
#include "block_update.hpp"
#include "chunk_column_impl.hpp"
#include "chunk_section_impl.hpp"
#include "minecraft/variant.hpp"

#include <memory>
#include "blocks/air.hpp"
namespace minecraft::chunks
{
    struct chunk_update : chunk_service_traits
    {
        explicit chunk_update(copyable_chunk_column_impl p)
        : var_(std::move(p))
        {
        }

        explicit chunk_update(update_sequence v)
        : var_(std::move(v))
        {
        }

        explicit chunk_update(block_update u={{0,0,0},blocks::air()})
        : var_(u)
        {
        }

        using value_type = variant< block_update, copyable_chunk_column_impl, update_sequence >;

        chunk_update &operator=(copyable_chunk_column_impl && arg) { var_ = std::move(arg);return *this; }
        chunk_update &operator=(update_sequence && arg) { var_ = std::move(arg);return *this; }

        auto as_variant() -> value_type & { return var_; };
        auto as_variant() const -> value_type const & { return var_; };

      private:
        value_type var_;
    };

}   // namespace minecraft::chunks