//
// Created by ahodges on 27/05/2020.
//

#pragma once

#include "chunk_column_impl.hpp"
#include "chunk_service.hpp"
#include "detail/map_view.hpp"
#include "net.hpp"

#include <vector>

namespace minecraft::chunks
{
    struct map_view : std::enable_shared_from_this< map_view >
    {
        using chunk_service_type    = chunk_service;
        using const_chunk_view      = std::shared_ptr< const chunk_column_impl >;
        using chunk_map_type        = std::unordered_map< chunk_coord_type, const_chunk_view >;
        using subscription_map_type = std::unordered_map< chunk_coord_type, connection >;

        map_view(net::executor exec, chunk_coord_type centre_chunk, std::size_t radius, chunk_service_type &service)
        : exec_(exec)
        , service_(service)
        , centre_chunk_(centre_chunk)
        , view_radius_(radius)
        {
        }

        auto start() -> net::awaitable< void >
        {
            // Subscribe to all viewable chunks
            auto res = detail::viewable_chunks_generator(centre_chunk_, view_radius_);

            for (auto &item : res)
            {
                // get a chunk subscription
                // Put in map
            }
        }
        auto cancel() -> void {}

        auto moved_chunk(chunk_coord_type coord) -> std::vector<chunk_coord_type>
        {}

        auto is_viewable(chunk_coord_type coord) -> bool { return chunk_map_.contains(coord); }
        auto get_chunk_column(chunk_coord_type coord) -> std::shared_ptr< chunk_column_impl >
        {
            auto ifind = chunks_.find(coord);
            if (ifind == std::end(chunks_))
            {
                // Need to subscribe to the chunk_
            }
        }

        auto begin() -> map_type::iterator { return chunks_.begin(); }

        auto end() -> map_type::iterator { return chunks_.end(); }

        auto recalculate_map() -> void {}

      private:
        net::executor      exec_;
        chunk_service_type service_;
        chunk_coord_type   centre_chunk_;
        std::size_t        view_radius_;

        chunk_map_type chunk_map_;
    };
}   // namespace minecraft::chunks
