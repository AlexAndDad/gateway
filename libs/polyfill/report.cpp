#include "report.hpp"

namespace polyfill {

    std::ostream &
    operator<<(std::ostream &os, error_code_reporter const &ecr)
    {
        report_on(os, ecr.ec);
        return os;
    }

    auto
    report(error_code const&ec) -> error_code_reporter
    {
        return error_code_reporter{ec};
    }

    void
    report_on(std::ostream &os, error_code const &ec)
    {
        os << "system error: " << ec.message() << " : code=" << ec.value() << " : category=" << ec.category().name();
    }

}