#pragma once

#include "tag_type.hpp"
#include "minecraft/variant.hpp"
#include <boost/container/vector.hpp>
#include <boost/unordered_map.hpp>
#include <string>


namespace minecraft::nbt
{
    struct value;
    struct list;
    using string     = std::string;
    struct compound;
    using int_array  = boost::container::vector< std::int32_t >;
    using byte_array = boost::container::vector< std::int8_t >;
    using long_array = boost::container::vector< std::int64_t >;

    using value_variant = variant<
        monostate,
        std::int8_t,
        std::int16_t,
        std::int32_t,
        std::int64_t,
        double,
        float,
        string,
        list,
        compound,
        int_array,
        byte_array,
        long_array >;

    template<class T> using list_impl = boost::container::vector<T>;

    using list_variant = boost::mp11::mp_transform< list_impl, value_variant >;

//    using value_variant = boost::mp11::mp_push_front< type_variant, monostate >;

    template < tag_type T >
    struct tag_t
    {
        static constexpr tag_type value = T;
        constexpr tag_type        operator()() const { return T; }
    };

    template < tag_type T >
    inline constexpr auto tag_c = tag_t< T >();

    // clang-format off
    template < tag_type > struct to_value;
    template <> struct to_value< tag_type::End > { using type = monostate; };
    template <> struct to_value< tag_type::Byte > { using type = std::int8_t; };
    template <> struct to_value< tag_type::Short > { using type = std::int16_t; };
    template <> struct to_value< tag_type::Int > { using type = std::int32_t; };
    template <> struct to_value< tag_type::Long > { using type = std::int64_t; };
    template <> struct to_value< tag_type::Double > { using type = double; };
    template <> struct to_value< tag_type::Float > { using type = float; };
    template <> struct to_value< tag_type::String > { using type = string; };
    template <> struct to_value< tag_type::List > { using type = list; };
    template <> struct to_value< tag_type::Compound > { using type = compound ; };
    template <> struct to_value< tag_type::Byte_Array > { using type = byte_array ; };
    template <> struct to_value< tag_type::Int_Array > { using type = int_array ; };
    template <> struct to_value< tag_type::Long_Array > { using type = long_array ; };
    template < tag_type Type > using to_value_t = typename to_value< Type >::type;
    // clang-format on

    // clang-format off
    template < class Storage > struct to_tag;
    template <> struct to_tag< monostate > { static constexpr tag_type value = End; };
    template <> struct to_tag< std::int8_t > { static constexpr tag_type value = tag_type::Byte; };
    template <> struct to_tag< std::int16_t > { static constexpr tag_type value = tag_type::Short; };
    template <> struct to_tag< std::int32_t > { static constexpr tag_type value = tag_type::Int; };
    template <> struct to_tag< std::int64_t > { static constexpr tag_type value = tag_type::Long; };
    template <> struct to_tag< double > { static constexpr tag_type value = tag_type::Double; };
    template <> struct to_tag< float > { static constexpr tag_type value = tag_type::Float; };
    template <> struct to_tag< string > { static constexpr tag_type value = tag_type::String; };
    template <> struct to_tag< list > { static constexpr tag_type value = tag_type::List; };
    template <> struct to_tag< compound  > { static constexpr tag_type value = tag_type::Compound; };
    template <> struct to_tag< byte_array  > { static constexpr tag_type value = tag_type::Byte_Array; };
    template <> struct to_tag< int_array  > { static constexpr tag_type value = tag_type::Int_Array; };
    template <> struct to_tag< long_array  > { static constexpr tag_type value = tag_type::Long_Array; };
    template < class T > constexpr tag_type to_tag_v = to_tag< T >::value;
    // clang-format on

    inline constexpr std::size_t max_string_length = 65535;
    inline constexpr std::size_t max_list_length = std::numeric_limits<std::int32_t>::max();
    inline constexpr std::size_t max_array_length = std::numeric_limits<std::int32_t>::max();

    template < class... Ts >
    struct overloaded : Ts...
    {
        using Ts::operator()...;
    };
    template < class... Ts >
    overloaded(Ts...) -> overloaded< Ts... >;   // not needed as of C++20 ?

}