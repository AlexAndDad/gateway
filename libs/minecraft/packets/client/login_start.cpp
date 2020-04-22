#include "login_start.hpp"

#include "minecraft/encode.hpp"

namespace minecraft::packets::client
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

    auto verify(login_start const& frame, error_code& ec) -> error_code&
    {
        ec.clear();

        if (frame.name.size() < 1)
            ec = error::invalid_name;

        return ec;
    }

}