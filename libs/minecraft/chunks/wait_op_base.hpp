#pragma once
#include "chunk_service_traits.hpp"
#include "chunk_update.hpp"

namespace minecraft::chunks
{
    struct wait_op_base : chunk_service_traits
    {
        virtual void notify_update(chunk_update update) = 0;
        virtual void notify_error(error_code ec)        = 0;
    };

}   // namespace minecraft::chunks