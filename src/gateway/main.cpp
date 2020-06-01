#include "config/net.hpp"
#include "application.hpp"
#include "polyfill/explain.hpp"
#include "polyfill/configuration.hpp"
#include <spdlog/spdlog.h>

#include <iostream>
#include <boost/json/string.hpp>

namespace gateway
{
    void run(polyfill::configuration config)
    {
        auto ioc = net::io_context(1);
        auto exec = ioc.get_executor();
        auto app = application(exec,std::move(config));
        app.start();
        ioc.run();
    }

}

int main(int argc, char * argv[])
{
    using polyfill::explain;
    using polyfill::deduce_return_code;

    spdlog::set_level(spdlog::level::debug);

    if (argc < 2)
    {
        std::cerr << "Not enough arguments provided. Expecting configuration file path as first arg.";
        return 1;
    }



    try
    {
        std::cout << "Loading configuration." << std::endl;
        auto config = polyfill::configuration(argv[1]);
        std::cout << "Starting event loop." << std::endl;
        gateway::run(std::move(config));
        return 0;
    }
    catch(...)
    {
        std::cerr << explain() << std::endl;
        return deduce_return_code();
    }
}