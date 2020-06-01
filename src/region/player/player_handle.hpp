#pragma once

#include "player/player.hpp"

#include <memory>

namespace region::player
{
    template < class PlayerType >
    struct player_handle
    {
        using impl_type = PlayerType;

        player_handle(std::shared_ptr<PlayerType> impl)
        : impl_(std::move(impl))
        {
        }

        impl_type &      get() { return *impl_; }
        const impl_type &get() const { return *impl_; }

      private:
        std::shared_ptr< PlayerType > impl_;
    };
}   // namespace region::player