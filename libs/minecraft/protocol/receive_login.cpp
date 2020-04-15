#include "receive_login.hpp"

namespace minecraft::protocol
{
    boost::uuids::uuid login_op_base::generate_uuid()
    {
        auto gen    = boost::uuids::random_generator_mt19937();
        auto result = gen();
        return result;
    }

}   // namespace minecraft::server