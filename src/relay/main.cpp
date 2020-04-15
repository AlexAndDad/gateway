#include "application.hpp"
#include "config/net.hpp"
#include "polyfill/explain.hpp"

#include <boost/program_options.hpp>
#include <iostream>

namespace relay
{
    void run(app_config config)
    {
        auto ioc  = net::io_context(1);
        auto exec = ioc.get_executor();

        auto app = application(exec, std::move(config));
        app.start();

        ioc.run();
    }

}   // namespace masquerade

int main(int argc, char **argv)
{
    using polyfill::deduce_return_code;
    using polyfill::explain;

    namespace po = boost::program_options;

    std::string upstream_address;
    std::string upstream_port;
    std::string listen_port;

    try
    {
        relay::app_config config;
        auto                   desc = po::options_description();
        desc.add_options()(
            "upstream-host", po::value(&config.upstream_host)->default_value("localhost"), "upstream minecraft server")(
            "upstream-port", po::value(&config.upstream_port)->default_value("25565"), "upstream minecraft port")(
            "port", po::value(&config.listen_port)->default_value("9000"), "port to listen on")("help,-?",
                                                                                                "show this help");

        auto vm = po::variables_map();
        po::store(po::parse_command_line(argc, argv, desc), vm);
        if (vm.count("help"))
        {
            std::cout << desc << std::endl;
            std::exit(0);
        }
        po::notify(vm);

        relay::run(std::move(config));
        return 0;
    }
    catch (...)
    {
        std::cerr << explain() << std::endl;
        return deduce_return_code();
    }
}