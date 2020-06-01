//
// Created by ahodges on 28/05/2020.
//

#include "chunk_update_provider/chunk_update_provider.hpp"
#include "minecraft/posix/mmap.hpp"
#include "minecraft/testing/chunk_data.spec.ipp"

#pragma once

namespace minecraft::chunks
{
    struct chunk_cache : chunk_update_provider
    {
        using executor_type = net::executor;

        chunk_cache(executor_type exec)
        : chunk_update_provider(exec)
        , generic_chunk_()
        , exec_(exec)
        {
            auto m = mmap(
                posix::open(fs::path(testing::chunk_data_bin_filename)));

            auto first = m.begin();
            auto last  = m.end();

            var_int id;
            first = minecraft::parse(first, last, id);

            vector2 coords;
            bool full_chunk;
            generic_chunk_.set_primary_bit_mask(0x0f);
            first = parse(first, last,coords,full_chunk, generic_chunk_);
        }

      private:
        chunk_column_impl &create_generic_chunk(chunk_coord_type) {
            return generic_chunk_;
        }

        const chunk_column_impl &get_chunk(chunk_coord_type coords) override
        {
            auto ifind = chunks_.find(coords);
            if (ifind == std::end(chunks_))
                return create_generic_chunk(coords);
            else
                return ifind->second;
        }

        std::unordered_map< chunk_coord_type, chunk_column_impl > chunks_;
        chunk_column_impl generic_chunk_;
        executor_type exec_;
    };
}   // namespace minecraft::chunks