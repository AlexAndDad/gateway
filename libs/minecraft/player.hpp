#pragma once

#include "minecraft/math.hpp"
#include "polyfill/class_logger.hpp"

#include <memory>

namespace minecraft
{
    template < class... Ts >
    struct overloaded : Ts...
    {
        using Ts::operator()...;
    };
    template < class... Ts >
    overloaded(Ts...) -> overloaded< Ts... >;

    template < class Connection >
    struct player
    : std::enable_shared_from_this< player< Connection > >
    , polyfill::class_logger
    {
        using name_type     = std::string;
        using executor_type = net::io_context::executor_type;
        using strand_type   = net::io_context::strand;

        using delta_time_type = std::chrono::milliseconds;

        player(std::string name, Connection connection, executor_type exec)
        : class_logger("player [" + name + "]")
        , name_(std::move(name))
        , position_()
        , yaw_(0)
        , pitch_(0)
        , has_moved_(true)   // Set this to true so that on a players first tick, they will get sent a position update
        , has_rotated_(true)
        , on_ground_(true)
        , strand_(exec.context())
        , connection_(std::move(connection))
        {
        }

        void start()
        {
            net::co_spawn(
                strand_,
                [self = player< Connection >::shared_from_this()]() -> net::awaitable< void > { co_await self->run(); },
                net::detached);
        }

        /// @brief Signal the player object that it's time to 'disconnect' internally
        void cancel()
        {
            net::co_spawn(
                get_strand(),
                [self = this->shared_from_this()]() -> net::awaitable< void > { co_await self->handle_cancel(); },
                net::detached);
        }

        void tick(delta_time_type delta_time)
        {
            net::co_spawn(
                get_strand(),
                [self = this->shared_from_this(), delta_time]() -> net::awaitable< void > {
                    co_await self->handle_tick(delta_time);
                },
                net::detached);
        }

      private:
        net::awaitable< void > handle_tick(delta_time_type delta_time)   // Handle logic changes here
        {
            BOOST_ASSERT(get_strand().running_in_this_thread());
            boost::ignore_unused(delta_time);

            if (has_moved_)
            {
                auto pack_wrapper = minecraft::packets::server::server_play_packet();
                auto packet       = minecraft::packets::server::player_position_and_look();
                packet.x          = position_.x();
                packet.y          = position_.y();
                packet.z          = position_.z();
                pack_wrapper.set(std::move(packet));
            }

            co_return;
        }

        net::awaitable< void > run()
        {
            BOOST_ASSERT(get_strand().running_in_this_thread());
            // TODO Do start logic to setup the player

            // Handle packets
            while (true)
            {
                try
                {
                    auto packet = co_await connection_.consume_packet();

                    visit(overloaded { [this](monostate &arg) {
                                          boost::ignore_unused(arg);
                                          this->warn("got monostate while consuming a packet in player.");
                                      },
                                       [this](auto &arg) {
                                           boost::ignore_unused(arg);
                                           this->warn("unhandled packet: {} consumed in player. Ignoring...",
                                                      wise_enum::to_string(arg.id()));
                                       },
                                       [this](minecraft::packets::client::animation &arg) {
                                           this->warn("unhandled animation packet");
                                           boost::ignore_unused(arg);
                                       },
                                       [this](minecraft::packets::client::player_position_and_rotation &arg) {
                                           player_position_and_rotation_handler(arg);
                                       } },
                          packet.as_variant());
                }
                catch (std::exception &)
                {
                    error("{}", polyfill::explain());
                    break;
                }
            }
        }

        net::awaitable< void > handle_cancel()
        {
            BOOST_ASSERT(get_strand().running_in_this_thread());
            // Cancel everything
            connection_.cancel();
            co_return;
        }

      private:   // Packet handlers
        void player_position_and_rotation_handler(const minecraft::packets::client::player_position_and_rotation &arg)
        {
            auto new_pos = math::Vector3d(arg.x, arg.feet_y, arg.z);
            if (new_pos != position_)
            {
                position_  = std::move(new_pos);
                has_moved_ = true;
            }
            auto set_rot = [this](float &dest, float val) mutable {
                if (val != dest)
                {
                    dest         = val;
                    has_rotated_ = true;
                }
            };

            set_rot(yaw_, arg.yaw);
            set_rot(pitch_, arg.pitch);
        }

      private:   // data
        strand_type &get_strand() { return strand_; }

        name_type name_;

        // World related data
        math::Vector3d position_;   // XZ center, Y feet (bottom)

        float yaw_;
        float pitch_;

        bool has_moved_;     // has the player moved
        bool has_rotated_;   // has the player rotated
        bool on_ground_;     // this variable represents the clients view of what the player is standing on.

        strand_type strand_;
        Connection  connection_;
    };
}   // namespace minecraft
