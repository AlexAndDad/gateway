#include "minecraft/status_packets.hpp"
#include <random>

namespace minecraft::client
{
    auto status_ping::generate() -> status_ping
    {
        static thread_local auto payload = []{
            auto rng = std::random_device();
            return rng();
        }();
        auto result = status_ping();
        result.payload = payload++;
        return result;
    }

}