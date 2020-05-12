#include "parse_context.ipp.hpp"

namespace minecraft::nbt
{
    auto parse_context_base::error(error_code ec) -> error_code &
    {
        if (not ec_)
            ec_ = ec;
        return ec_;
    }

    auto parse_context_base::parse(const_buffer_iterator first, const_buffer_iterator last, std::uint8_t &target)
        -> const_buffer_iterator
    {
        if (first == last)
            raise(parsing::incomplete());
        target = static_cast< std::uint8_t >(*first++);
        return first;
    }

    auto parse_context_base::parse(const_buffer_iterator first, const_buffer_iterator last, std::int8_t &target)
        -> const_buffer_iterator
    {
        if (first == last)
            raise(parsing::incomplete());
        target = static_cast< std::int8_t >(*first++);
        return first;
    }

    template struct basic_parse_context< parse_handler & >;

}   // namespace minecraft::nbt