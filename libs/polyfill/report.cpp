#include "report.hpp"

namespace polyfill {

    void report_on(std::string& os, net::ip::tcp::endpoint const& ep)
    {
        os.append(ep.address().to_string());
        os += ':';
        os.append(std::to_string(ep.port()));
    }

    void
    report_on(std::string &os, error_code const &ec)
    {
        os += "system error: ";
        os += ec.message();
        os += " : code=";
        os += std::to_string(ec.value());
        os += "category=";
        os += ec.category().name();
    }

}