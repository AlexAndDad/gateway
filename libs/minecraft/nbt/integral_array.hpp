//
// Created by rhodges on 07/05/2020.
//

#ifndef GATEWAY_INTEGRAL_ARRAY_HPP
#define GATEWAY_INTEGRAL_ARRAY_HPP
#include <cstdint>
#include <cstddef>
#include <algorithm>
#include "storage_provider.hpp"
#include "tag_type.hpp"

namespace minecraft::nbt
{
    template<tag_type Type>
    struct integral_array
    {
        using value_type = atom_type_t<Type>;

        std::int32_t length;
        value_type first_data[1];

        std::size_t extent() const {
            return sizeof(integral_array) + sizeof(value_type) * std::min(1, length-1);
        }
    };

    struct array_service
    {
        template<tag_type Type>
        static std::int8_t release(storage_provider* storage, integral_array<Type>* array)
        {
            storage->free(array, size_to_blocks(array->extent()));
            return 0;
        }
    };
}

#endif   // GATEWAY_INTEGRAL_ARRAY_HPP
