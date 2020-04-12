#include "frame_parser.hpp"
#include "polyfill/report.hpp"

namespace minecraft
{
    using polyfill::report_on;

    // ===============================================================


    // ===============================================================


    // ===============================================================


    // ===============================================================

    auto operator<<(std::ostream& os, frame_variant const& fv)-> std::ostream&
    {
        auto visitor = [&os](auto&& x)
        {
            report_on(os, x);
        };

        std::visit(visitor, fv.as_variant());
        return os;
    }


    // ===============================================================

    auto operator<<(std::ostream& os, frame_parser const& fp) -> std::ostream&
    {
        return os << fp.result_;
    }

}