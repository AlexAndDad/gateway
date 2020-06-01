#pragma once

#include "chunk_update_subscription_manager.hpp"
#include "chunks/chunk_cache.hpp"
#include "dimension.hpp"
#include "gamemode.hpp"
#include "minecraft/math.hpp"
#include "minecraft/types/position2.hpp"
#include "player_connection_base.hpp"
#include "polyfill/async/coro_except_handler.hpp"
#include "polyfill/class_logger.hpp"
#include "world/world.hpp"

#include <memory>

namespace minecraft::player
{
    template < class... Ts >
    struct overloaded : Ts...
    {
        using Ts::operator()...;
    };
    template < class... Ts >
    overloaded(Ts...) -> overloaded< Ts... >;

    struct player
    : std::enable_shared_from_this< player >
    , polyfill::class_logger
    {
        using executor_type   = net::executor;
        using name_type       = std::string;
        using delta_time_type = std::chrono::milliseconds;

        player(name_type                                 name,
               executor_type                             exec,
               std::shared_ptr< player_connection_base > connection,
               world &                                   current_world,
               chunks::chunk_update_provider *           provider)
        : class_logger("player [" + name + "]")
        , name_(std::move(name))
        , entity_id_(1)   // TODO generate a valid EID
        , current_world_(current_world)
        , dimension_(dimension::dimension_type::overworld)
        , gamemode_(gamemode::gamemode_type::survival)
        , position_(0, 0, 0)
        , yaw_(0)
        , pitch_(0)
        , has_moved_(true)
        , has_rotated_(true)
        , on_ground_(true)
        , exec_(exec)
        , connection_(std::move(connection))
        , chunk_update_sub_(get_executor(), chunks::to_chunk_coords(position_), 6, provider)
        {
            boost::ignore_unused(on_ground_);
        }

        void start();
        void cancel();
        void tick(delta_time_type delta_time);

        std::int32_t              get_entity_id() const { return entity_id_; }
        gamemode::gamemode_type   get_gamemode() const { return gamemode_; }
        dimension::dimension_type get_dimension() const { return dimension_; }
        chunks::world_vector3     get_position() const { return position_; }
        float                     get_yaw() const { return yaw_; }
        float                     get_pitch() const { return pitch_; }

      private:
        auto handle_start() -> net::awaitable< void >;
        auto handle_login() -> net::awaitable< void >;
        void handle_tick(delta_time_type delta_time);
        auto run() -> net::awaitable< void >;

        void handle_cancel() { connection_->cancel(); }

      private:   // Packet handlers
        void player_position_and_rotation_handler(const minecraft::packets::client::player_position_and_rotation &arg)
        {
            boost::ignore_unused(arg, has_rotated_);
        }

      private:   // data
        executor_type &get_executor() { return exec_; }

        name_type name_;

        std::int32_t              entity_id_;
        world &                   current_world_;
        dimension::dimension_type dimension_;
        gamemode::gamemode_type   gamemode_;

        // World related data
        chunks::world_vector3 position_;   // XZ center, Y feet (bottom)

        float yaw_;
        float pitch_;

        bool has_moved_;     // has the player moved
        bool has_rotated_;   // has the player rotated
        bool on_ground_;     // this variable represents the clients view of what
                             // the player is standing on.

        executor_type                             exec_;
        std::shared_ptr< player_connection_base > connection_;

        chunk_update_subscription_manager chunk_update_sub_;
    };
}   // namespace minecraft::player
