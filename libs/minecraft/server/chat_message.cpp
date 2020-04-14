#include "chat_message.hpp"

#include "minecraft/encode.hpp"

namespace minecraft::server
{
    std::size_t compose(chat_message const &arg, std::vector< char > &target)
    {
        auto original = target.size();
        auto i        = std::back_inserter(target);
        i             = encode(variable_length(arg.id()), i);
        i             = encode(arg.json_data, i);
        i             = encode(arg.position, i);
        return target.size() - original;
    }

    std::ostream &operator<<(std::ostream &os, chat_message const &arg)
    {
        os << "chat_message.json_data : " << arg.json_data
           << "\nchat_message.position : " << wise_enum::to_string(arg.position);
        return os;
    }

}   // namespace minecraft::server