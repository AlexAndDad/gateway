//
// Created by ahodges on 28/05/2020.
//
#pragma once

#include "chunks/types.hpp"
#include <iterator>

namespace minecraft::chunks
{
    struct viewable_chunks_generator
    {
        viewable_chunks_generator(chunk_coord_type centre, std::size_t radius)
            : centre(centre)
            , radius(radius)
        {
        }

        chunk_coord_type centre;
        std::size_t      radius;

        struct iterator
        {
            using value_type        = chunk_coord_type;
            using reference         = value_type const &;
            using pointer           = value_type const *;
            using difference_type   = std::ptrdiff_t;
            using iterator_category = std::forward_iterator_tag;

            iterator(chunk_coord_type centre, std::size_t radius)
                : radius_(radius)
                , v_(centre.x - radius, centre.z - radius)
                , centre_(centre)
                , end_(false)
            {
            }

            iterator(bool end = true)
                : v_(0, 0)
                , centre_(0, 0)
                , end_(end)
            {
            }

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
            bool operator==(iterator const &) const { return end_; }
            bool operator!=(iterator const &) const { return !end_; }

          private:
            void inc()
            {
                if (++v_.z > static_cast< int >(centre_.z + radius_))
                {
                    v_.z = centre_.z - radius_;
                    if (++v_.x > static_cast< int >(centre_.x + radius_))
                    {
                        end_ = true;
                    }
                }
            }

            std::size_t      radius_;
            chunk_coord_type v_;
            chunk_coord_type centre_;
            bool             end_;
        };

        iterator begin() const { return iterator(centre, radius); }
        iterator end() const { return iterator(true); }
    };
}