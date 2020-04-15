#include "server_accept.hpp"

namespace minecraft::protocol
{
    boost::uuids::uuid server_accept_op_base::generate_uuid()
    {
        auto gen    = boost::uuids::random_generator_mt19937();
        auto result = gen();
        return result;
    }

}   // namespace minecraft::server