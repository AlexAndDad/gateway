#include "frame_parser.hpp"

namespace minecraft
{
    void report_on(std::ostream& os, error_code const& ec)
    {
        os << "system error: " << ec.message() << " : code=" << ec.value() << " : category=" << ec.category().name();
    }

    // ===============================================================

    void report_on(std::ostream& os, incomplete const&)
    {
        os << "incomplete";
    }

    // ===============================================================

    void report_on(std::ostream& os, client_handshake const& ch)
    {
        os << "client handshake : "
              "protocol version=" << ch.protocol_version
              << " : server_address=" << ch.server_address
              << " : server_port=" << ch.server_port
              << " : next_state=" << wise_enum::to_string(ch.next_state);
    }

    // ===============================================================

    void report_on(std::ostream& os, uncompressed_header const& uh)
    {
        os << "uncompressed header: length=" << uh.length << " : id=" << wise_enum::to_string(uh.id);
    }


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