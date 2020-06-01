#pragma once

#include "player/player.hpp"

#include <boost/optional.hpp>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace region::player
{
    template < class NameType, class PlayerType >
    struct player_cache
    {
        player_cache(std::size_t max_players = 0)
        : max_players_(max_players)
        {
        }

        std::size_t size() { return players_.size(); }

        boost::optional< PlayerType & > get(NameType const &key)
        {
            auto result = boost::optional< PlayerType & >();

            auto iter = players_.find(key);
            if (iter != players_.end())
            {
                result = iter.second;
            }

            return result;
        }

        void set(NameType key, PlayerType player)
        {
            if (size() == max_players_)
            {

            }
            auto res = players_.try_emplace(std::move(key), std::move(player));
            if (not res.second){
                throw std::invalid_argument("Attempting to insert player with name: " + key + " into player_cache when there is already one present.");
            }
        }

      private:
        std::unordered_map< NameType, PlayerType > players_;
        std::size_t                               max_players_;
    };
}   // namespace region