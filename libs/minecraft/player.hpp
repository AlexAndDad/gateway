#pragma once

namespace minecraft
{
    template < class Connection >
    struct player
    {
        player(Connection connection)
        : connection(std::move(connection))
        {
        }

      public:
        // World related data
         position;



      private:
        Connection connection
    }
};   // namespace minecraft
}