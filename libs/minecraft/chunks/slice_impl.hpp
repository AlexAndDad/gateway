//
// Created by rhodges on 17/05/2020.
//

#ifndef GATEWAY_SLICE_IMPL_HPP
#define GATEWAY_SLICE_IMPL_HPP

#include "minecraft/blocks/block_info.hpp"
#include "types.hpp"

namespace minecraft::chunks
{
    struct slice_impl
    {
        using block_type = minecraft::blocks::block_type;

        static constexpr int x_extent = 16;   // x is horizontal
        static constexpr int z_extent = 16;   // z is horizontal

        struct coordinates_range
        {
            struct iterator
            {
                using value_type        = vector2;
                using reference         = value_type const &;
                using pointer           = value_type const *;
                using difference_type   = std::ptrdiff_t;
                using iterator_category = std::forward_iterator_tag;

                iterator(int x, int z)
                : v_(x, z)
                {
                }

                // clang-tidy off
                reference operator*() const { return v_; }
                iterator &operator++()
                {
                    inc();
                    return *this;
                }
                iterator operator++(int)
                {
                    auto tmp = *this;
                    inc();
                    return tmp;
                }
                bool operator==(iterator const &other) const
                {
                    return v_ == other.v_;
                }
                bool operator!=(iterator const &other) const
                {
                    return v_ != other.v_;
                }
                // clang-tidy on

              private:
                void inc()
                {
                    if (++v_.x >= x_extent)
                    {
                        v_.x = 0;
                        ++v_.z;
                    }
                    if (v_.z >= z_extent)
                        v_ = vector2(0, z_extent);
                }

              private:
                vector2 v_;
            };
            iterator begin() const { return iterator(0, 0); }
            iterator end() const { return iterator(0, z_extent); }
        };

        slice_impl();

        static auto all() -> coordinates_range { return coordinates_range(); }

        void clear()
        {
            for (auto &horz : all())
                (*this)[horz] = blocks::air();
        }

        block_type &operator[](vector2 pos) { return zx[pos.z][pos.x]; }

        block_type const &operator[](vector2 pos) const
        {
            return zx[pos.z][pos.x];
        }

        friend std::ostream &operator<<(std::ostream &os, slice_impl const &c);
        friend bool operator==(slice_impl const &a, slice_impl const &b);
        friend bool operator!=(slice_impl const &a, slice_impl const &b);

      private:
        block_type zx[z_extent][x_extent];
    };

    struct slice_printer
    {
        slice_impl const &slice;
        int               yval;
    };

    std::ostream &operator<<(std::ostream &os, slice_printer const &p);

    inline
    auto pretty_print(slice_impl const &s, int yval = -1) -> slice_printer
    {
        return slice_printer { .slice = s, .yval = yval };
    }
}   // namespace minecraft::chunks
#endif   // GATEWAY_SLICE_IMPL_HPP
