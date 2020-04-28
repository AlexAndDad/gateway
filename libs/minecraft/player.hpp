#pragma once

#include "minecraft/math.hpp"

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
    struct player : std::enable_shared_from_this< player< Connection > >
    {
        using name_type     = std::string;
        using executor_type = net::io_context::executor_type;
        using strand_type   = net::io_context::strand;

        player(std::string name, Connection connection, executor_type exec)
        : name_(std::move(name))
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
        void stop() {}

      public:
        // Packets yet to handle...

        net::awaitable< void > run()
        {
            // TODO Do start logic to setup the player

            // Handle packets

            auto packet = co_await connection_.consume_packet();

            visit(overloaded { [](monostate &arg) {
                                  boost::ignore_unused(arg);
                                  spdlog::warn("got monostate while consuming a packet in player.");
                              },
                               [](auto &arg) {
                                   boost::ignore_unused(arg);
                                   spdlog::warn("unhandled packet: {} consumed in player. Ignoring...",
                                                wise_enum::to_string(arg.id()));
                               },
                               [](minecraft::packets::client::client_settings &arg) { boost::ignore_unused(arg); } },
                  packet.as_variant());
        }

        name_type name_;

        // World related data
        math::Vector3d position_;   // XZ center, Y bottom
        math::Vector3d rotation_;   // degrees [-180, +180]

      private:
        strand_type strand_;
        Connection  connection_;
    };
}   // namespace minecraft
