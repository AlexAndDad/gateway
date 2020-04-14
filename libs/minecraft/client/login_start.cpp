#include "minecraft/client/login_start.hpp"
#include "minecraft/encode.hpp"

namespace minecraft::client
{
    auto compose(login_start const& frame, std::vector<char>& target) -> std::size_t
    {
        using minecraft::encode;

        auto original_size = target.size();
        auto iter = back_inserter(target);

        iter = encode(variable_length(frame.id()), iter);
        iter = encode(frame.name, iter);

        return target.size() - original_size;
    }

}