#include "config/net.hpp"
#include "application.hpp"
#include "polyfill/explain.hpp"

#include <iostream>

namespace gateway
{
    void run()
    {
        auto ioc = net::io_context(1);
        auto exec = ioc.get_executor();

        auto app = application(exec);
        app.start();


        ioc.run();
    }

}

int main()
{
    using polyfill::explain;
    using polyfill::deduce_return_code;

    try
    {
        gateway::run();
        return 0;
    }
    catch(...)
    {
        std::cerr << explain() << std::endl;
        return deduce_return_code();
    }
}