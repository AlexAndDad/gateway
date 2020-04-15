#pragma once

#include <boost/asio.hpp>
#include <boost/beast/core/span.hpp>
namespace config
{
    namespace net = boost::asio;
    using boost::system::error_code;
    using boost::system::system_error;
    using boost::system::error_category;
    using boost::beast::span;
}
