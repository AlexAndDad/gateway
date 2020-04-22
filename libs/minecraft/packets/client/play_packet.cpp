//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#include "play_packet.hpp"

#include "minecraft/parse.hpp"

#include <boost/utility/identity_type.hpp>
#include <functional>

namespace minecraft::packets::client
{

    template<class T> struct identity {};

    template < class... Ts >
    struct for_all_types_impl;

    template <>
    struct for_all_types_impl<>
    {
        template<class...Args>
        bool operator()(Args&&...) const { return false; };
    };

    template < class T, class... Rest >
    struct for_all_types_impl< T, Rest... >
    {
        template < class F, class... Args >
        bool operator()(F &&f, Args &&... args) const
        {
            return f(identity< T >(), args...) or for_all_types_impl< Rest... >()(f, args...);
        }
    };

    template < class F, class... Ts >
    bool for_all_types(F &&f, std::variant< Ts... > &var)
    {
        return for_all_types_impl< Ts... >()(f, var);
    }

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, play_packet &pkt, error_code &ec)
    {
        auto res = first;
        if (not ec)
        {
            auto id = var_enum< play_id >();
            first   = parse(first, last, id, ec);
            for_all_types([&]< class Type >(identity< Type >, play_packet_variant &var) {
                if constexpr (std::is_same_v<Type, std::monostate>)
                    return false;
                else if (Type::id() == id.value())
                {
                    Type& actual = var.emplace<Type>();
                    first = parse(first, last, actual, ec);
                    return true;
                }
                else return false;
            }, pkt.as_variant());
            if (not ec)
                res = first;
        }

        return res;
    }

}   // namespace minecraft::packets::client