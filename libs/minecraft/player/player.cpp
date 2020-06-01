#include "player.hpp"

namespace minecraft::player
{
    void player::start()
    {
        net::co_spawn(
            get_executor(),
            [self = shared_from_this()]() -> net::awaitable< void > { co_await self->handle_start(); },
            polyfill::coro_except_handler("player [" + name_ + "]", "start()"));
    }

    void player::cancel()
    {
        net::dispatch(net::bind_executor(get_executor(), [self = shared_from_this()]() { self->handle_cancel(); }));
    }

    void player::tick(delta_time_type delta_time)
    {
        net::dispatch(net::bind_executor(get_executor(), [self = shared_from_this(), delta_time]() { self->handle_tick(delta_time); }));
    }

    net::awaitable< void > player::handle_start()
    {
        connection_->start_play();
        co_await handle_login();
        co_await run();
    }

    net::awaitable< void > player::handle_login()
    {
        // ---------- SEND ------------ //
        {   // send join game
            auto make_packet = [&]() {
                auto  packet                    = minecraft::packets::server::server_play_packet();
                auto &pack_data                 = packet.emplace< minecraft::packets::server::join_game >();
                pack_data.entity_id             = get_entity_id();
                pack_data.game_mode             = get_gamemode();
                pack_data.dimension             = get_dimension();
                pack_data.hashed_seed           = current_world_.get_hashed_seed();
                pack_data.max_players           = 20;   // Ignored, so we set a stock value
                pack_data.level_type            = current_world_.get_level_type();
                pack_data.view_distance         = current_world_.get_view_distance();
                pack_data.reduced_debug_info    = false;
                pack_data.enable_respawn_screen = current_world_.respawn_screen();
                return packet;
            };
            connection_.get()->send_packet(make_packet());
        }
        {   // send plugin message
            auto make_packet = [&]() {
                auto  packet                          = minecraft::packets::server::server_play_packet();
                auto &packet_data                     = packet.emplace< minecraft::packets::server::plugin_message >();
                packet_data.channel                        = "minecraft:brand";
                minecraft::varchar< 32767 > my_string = "test_brand";
                compose(my_string, packet_data.data.as_buffer());
                return packet;
            };
            connection_.get()->send_packet(make_packet());
        }

        // send server difficulty
        // send player abilities
        // ( might need to receive plugin_message and client_settings here)
        // send held item change
        // send declare recipes
        // send tags
        // send entity status
        // send declare commands
        // send unlock recipes
        // send player position and look
        // send player info (add player action)
        // send player info (update latency action)
        // send update view position
        // send update light
        // send chunk data
        {
            auto make_packet = [](auto & coords, auto & copyable_chunk){
                auto packet = packets::server::server_play_packet();
                auto &packet_data = packet.emplace<packets::server::chunk_data>();
                packet_data.data.coords = coords;
                packet_data.data.full_chunk = true;
                packet_data.data.column = std::move(copyable_chunk);
                return packet;
            };
            auto res = co_await chunk_update_sub_.start();
            for (std::size_t x = 0; x<res.first;x++)
            {
                auto chunk = co_await res.second.get()->async_pop(net::use_awaitable);
                connection_->send_packet(make_packet(chunk.first,chunk.second));
            }

        }
        // send world border
        {   // send spawn position
            auto make_packet = [&]() {
                auto  packet         = packets::server::server_play_packet();
                auto &packet_data    = packet.emplace< packets::server::spawn_position >();
                packet_data.location = current_world_.get_spawn_position();
                return packet;
            };
            connection_.get()->send_packet(make_packet());
        }
        {   // send player position and look
            auto make_packet = [&]() {
                auto  packet      = packets::server::server_play_packet();
                auto &packet_data = packet.emplace< packets::server::player_position_and_look >();
                auto  pos         = get_position();
                packet_data.x     = pos.x;
                packet_data.y     = pos.y;
                packet_data.z     = pos.z;
                packet_data.yaw   = get_yaw();
                packet_data.pitch = get_pitch();
                packet_data.set_flags(false, false, false, false, false);
                packet_data.teleport_ID = 666;   // TODO handle this
                return packet;
            };
            connection_.get()->send_packet(make_packet());
        }

        // ---------- RECEIVE ------------ //
        // this is an optional order, some may not arrive. Once client status has been received the login stage ends.
        bool condition = true;
        while(condition)
        {
            auto packet = co_await connection_.get()->async_get_client_packet();

            visit(overloaded { [&](minecraft::monostate &) { error("monostate packet received.. this is bad."); },
                               [&](packets::client::teleport_confirm &arg) {
                                   info("teleport_confirm packet recieved");   // TODO handle packet
                                   info("packet: {}\n", arg);
                               },
                               [&](packets::client::player_position_and_rotation &arg) {
                                   info("player_position_and_rotation packet recieved");   // TODO handle arg
                                   info("packet: {}\n", arg);
                               },
                               [&](packets::client::plugin_message &arg) {
                                   info("plugin_message packet received");   // TODO handle arg
                                   info("packet: {}\n", arg);
                               },
                               [&](packets::client::client_settings &arg) {
                                   info("client_settings packet received"); // TODO handle arg
                                   info("packet: {}\n", arg);
                               },
                               [&](packets::client::client_status &arg) {
                                   info("client_status packet received");   // TODO handle arg
                                   info("packet: {}\n", arg);
                                   condition = false;
                               },
                               [&](auto &arg) {
                                    error("received unexpected packet during login sequence. Packet:[{}]",arg);
                                   // TODO log error, kill connection.
                                   // We should always receive a client_status packet before anything not in the list above^
                               } },

                  packet.as_variant());
        }
    }

    void player::handle_tick(delta_time_type delta_time)
    {
        boost::ignore_unused(delta_time);
        if (has_moved_)
        {
            auto pack_wrapper = minecraft::packets::server::server_play_packet();
            auto packet       = minecraft::packets::server::player_position_and_look();
            packet.x          = position_.x;
            packet.y          = position_.y;
            packet.z          = position_.z;
            pack_wrapper.set(std::move(packet));
        }

        return;
    }

    net::awaitable< void > player::run()
    {
        try
        {
            for (;;)
            {
                auto packet = co_await connection_->async_get_client_packet();

                visit(overloaded { [&](monostate &arg) {
                                      boost::ignore_unused(arg);
                                      this->warn("got monostate while consuming a packet in player.");
                                  },
                                   [&](auto &arg) { this->warn("unhandled packet: {} consumed in player. Ignoring...", arg); },
                                   [&](packets::client::animation &) {
                                       // TODO handle
                                   },
                                   [&](packets::client::player_position_and_rotation &arg) { player_position_and_rotation_handler(arg); } },
                      packet.as_variant());
            }
        }
        catch (...)
        {
            // TODO
        }
    }

}   // namespace minecraft::player