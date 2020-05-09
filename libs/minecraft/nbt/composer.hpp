#pragma once

namespace minecraft::nbt
{
    struct compose_handler
    {

    };

    struct composer
    {
        composer(compose_handler& handler) : handler_(handler) {}

      private:
        compose_handler& handler_;
    };


}