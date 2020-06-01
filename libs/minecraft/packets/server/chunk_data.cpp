#include "chunk_data.hpp"

#include "parse.hpp"

#include <bit>

namespace minecraft::packets::server
{

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, chunk_data_type &target, error_code &ec)
    {
        boost::ignore_unused(first,last,target,ec);
        BOOST_ASSERT(false); // should never be called
        return first;
    }



}   // namespace minecraft::packets::server