//
// Created by rhodges on 05/05/2020.
//
#pragma once
#include "offset.hpp"
#include "tag_type.hpp"

#include <cstdint>
#include <memory>
#include <span>
#include <cassert>

namespace minecraft::nbt
{
    struct data_ref
    {
        data_ref()
        : type(tag_type::End)
        {
        }

        data_ref(data_ref &&other) noexcept
        : type(std::exchange(other.type, tag_type::End))
        {
            std::memcpy(&data, &other.data, sizeof(data));
            std::memset(&other.data, 0, sizeof(other.data));
        }

        data_ref& operator=(data_ref&& other) noexcept
        {
            assert(empty());
            type = std::exchange(other.type, tag_type::End);
            std::memcpy(&data, &other.data, sizeof(data));
            std::memset(&other.data, 0, sizeof(other.data));
            return *this;
        }

        tag_type type;
        union
        {
            std::int8_t  byte_;
            std::int16_t short_;
            std::int32_t int_;
            std::int64_t long_;
            float        float_;
            double       double_;
            offset       ref_;
        } data;

        bool empty() const noexcept { return this->type == tag_type::End; }

        static auto create_long(std::int64_t n) -> data_ref
        {
            auto result  = data_ref();
            result.type  = tag_type::Long;
            result.data.long_ = n;
            return result;
        }

        static auto create_reference(tag_type tag, offset ref) -> data_ref
        {
            auto result      = data_ref();
            result.type      = tag;
            result.data.ref_ = ref;
            return result;
        }
    };

    struct data_service_base
    {
        static auto make_long(std::int64_t n) { return data_ref::create_long(n); }
    };

    template < class Derived >
    struct data_service : data_service_base
    {
        auto make_string_ref(offset id) -> data_ref;

        /// conceptually release (and possibly destroy) the data referred to.
        ///
        /// Not all data types are stored as references. These types will indicate a no-op
        /// \param data
        /// \return the new use count. If zero, the data item will have been destroyed
        ///
        auto release(data_ref const &data) -> std::uint8_t;

      private:
        auto self() -> Derived *;
        auto self() const -> Derived const *;
    };
}   // namespace minecraft::nbt
