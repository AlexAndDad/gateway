#include "shared_secret.hpp"
#include <random>

namespace minecraft::protocol
{
    auto shared_secret::generate() -> void {

        static thread_local auto eng = []{
            auto rng = std::random_device();
            auto seq = std::seed_seq { rng(), rng(), rng(), rng(), rng() };
            return std::default_random_engine (seq);
        }();

        auto dist = std::uniform_int_distribution<std::uint32_t>(0, 255);

        std::array<std::uint8_t, shared_secret::required_size()> data {};
        for (auto& e : data)
            e = dist(eng);

        assign(data.begin(), data.end());
    }
}