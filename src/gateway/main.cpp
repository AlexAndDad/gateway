#include "config/net.hpp"
#include "application.hpp"
#include "polyfill/explain.hpp"

#include <iostream>
#include <boost/program_options.hpp>

namespace gateway
{
    void run()
    {
        namespace po = boost::program_options;

        app_config config;




        auto ioc = net::io_context(1);
        auto exec = ioc.get_executor();

        auto app = application(exec, config);
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