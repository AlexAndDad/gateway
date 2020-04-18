#pragma once
namespace minecraft
{
    template < class Stream, class = void >
    struct has_next_layer : std::false_type
    {
    };

    template < class Stream >
    inline constexpr bool has_next_layer_v = has_next_layer< Stream >::value;

    template < class Stream >
    struct has_next_layer< Stream, std::void_t< decltype(std::declval< Stream >().next_layer()) > > : std::true_type
    {
    };

    template < class Stream, class = void >
    struct has_remote_endpoint : std::false_type
    {
    };

    template < class Stream >
    inline constexpr bool has_remote_endpoint_v = has_remote_endpoint< Stream >::value;

    template < class Stream >
    struct has_remote_endpoint< Stream, std::void_t< decltype(std::declval< Stream >().remote_endpoint()) > >
    : std::true_type
    {
    };

}   // namespace minecraft