#pragma once

namespace minecraft
{
    struct position
    {
        position()
            : x_(0)
            , y_(0)
            , z_(0)
        {
        }

        position(std::int32_t x, std::int32_t y, std::int32_t z)
            : x_(x)
            , y_(y)
            , z_(y)
        {
        }

        friend std::ostream &operator<<(std::ostream &stream, const position &self)
        {
            // All bitsets need to be converted to int32_t, this requires the negative bit to be carried.

            stream << "position.x: " << polyfill::bitset_tools::signedBS_to_signed32(self.x_)
                   << "\nposition.y: " << polyfill::bitset_tools::signedBS_to_signed32(self.y_)
                   << "\nposition.z: " << polyfill::bitset_tools::signedBS_to_signed32(self.z_);
            return stream;
        }

        void set_x(std::int32_t val) { x_ = val; }
        void set_y(std::int32_t val) { y_ = val; }
        void set_z(std::int32_t val) { z_ = val; }

        [[nodiscard]] std::bitset< 26 > x() const { return x_; }
        [[nodiscard]] std::bitset< 12 > y() const { return y_; }
        [[nodiscard]] std::bitset< 26 > z() const { return z_; }

      private:
        std::bitset< 26 > x_;
        std::bitset< 12 > y_;
        std::bitset< 26 > z_;
    };

    template < class Iter >
    Iter encode(const position &in, Iter first)
    {
        std::uint64_t value = 0;
        value |= in.x().to_ulong();
        value <<= 26;
        value |= in.z().to_ulong();
        value <<= 26;
        value |= in.y().to_ulong();

        return write_x_bytes(first, value);
    }


}