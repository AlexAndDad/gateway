#include "net.hpp"

namespace polyfill {
    struct error_code_reporter
    {
        friend std::ostream &
        operator<<(std::ostream &os, error_code_reporter const &ecr);

        error_code ec;
    };

    auto
    report(error_code const &ec) -> error_code_reporter;

    void
    report_on(std::ostream &os, error_code const &ec);
}