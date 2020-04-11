#pragma once

#include <variant>
#include <tuple>
#include "net.hpp"
#include "parse_error.hpp"
#include <wise_enum.h>

namespace minecraft {

    WISE_ENUM_CLASS((packet_id, std::int32_t), (client_handshake, 0));
    WISE_ENUM_CLASS((client_state, std::int32_t), (initial, 0), (status, 1), (login, 2));

    struct incomplete
    {

    };

    void
    report_on(std::ostream &os, incomplete const &);

    struct uncompressed_header
    {
        std::int32_t length;
        packet_id id;

        friend void
        report_on(std::ostream &os, uncompressed_header const &);
    };

    struct compressed_header
    {
        std::int32_t length;
        std::int32_t data_length;

    };

    struct client_handshake
    {
        std::int32_t protocol_version;
        std::string server_address;
        std::uint16_t server_port;
        client_state next_state;

        friend void
        report_on(std::ostream &os, client_handshake const &);

    };

    using frame_variant_base = std::variant<incomplete, error_code, client_handshake, uncompressed_header>;

    struct frame_variant
    : frame_variant_base
    {
        using frame_variant_base::frame_variant_base;

        auto
        complete() const
        {
            return not std::holds_alternative<incomplete>(as_variant());
        }

        auto
        as_variant() const -> frame_variant_base const &
        {
            return static_cast<frame_variant_base const &>(*this);
        }

        auto
        as_variant() -> frame_variant_base &
        {
            return static_cast<frame_variant_base &>(*this);
        }

        friend auto
        operator<<(std::ostream &os, frame_variant const &fv) -> std::ostream &;

        friend auto
        complete(frame_variant const &fv) -> bool
        {
            return fv.complete();
        }
    };

    struct frame_parser
    {
        template<class IterFirst,
        class IterLast>
        auto
        parse(IterFirst first, IterLast last) -> IterFirst;

        template<class I1, class I2>
        static auto
        parse(I1 first, I2 last, std::int32_t &result) -> I1;

        /// Parse the rest of the frame into the parser's result
        /// \tparam Iter
        /// \param first
        /// \param last
        /// \param header
        /// \return
        template<class Iter>
        auto
        parse(Iter first, Iter last, uncompressed_header header) -> Iter;

        template<class Iter>
        static auto
        parse(Iter first, Iter last, client_handshake &target) -> Iter;

        template<class Iter>
        static auto
        parse(Iter first, Iter last, std::uint16_t &target) -> Iter;

        template<class Iter>
        static auto
        parse(Iter first, Iter last, std::string &target, std::size_t char_limit = 32767) -> Iter;

        template<class Iter, class Enum>
        static auto
        parse(Iter first, Iter last, Enum &target) ->
        std::enable_if_t<std::is_enum_v<Enum>, Iter>
        {
            auto accum = std::underlying_type_t<Enum>();
            first = parse(first, last, accum);
            target = static_cast<Enum>(accum);
            return first;
        }

        bool
        compression_enabled() const
        {
            return compression_enabled_;
        }

        auto
        result() const -> frame_variant const &
        { return result_; }

        friend auto
        operator<<(std::ostream &os, frame_parser const &fp) -> std::ostream &;

    private:

        frame_variant result_;
        client_state state_ = client_state::initial;
        bool compression_enabled_ = false;
    };


    template<class IterFirst, class IterLast>
    auto
    frame_parser::parse(IterFirst first, IterLast last) -> IterFirst
    {
        auto failure = [first, this](auto &&x) {
            result_ = std::forward<decltype(x)>(x);
            return first;
        };

        try
        {
            std::int32_t packet_length;
            auto current = parse(first, last, packet_length);
            if (std::distance(current, last) < packet_length)
                return failure(incomplete());
            auto next = current + packet_length;

            auto success = [next]() {
                return next;
            };

            if (compression_enabled())
            {
                result_ = make_error_code(error::not_implemented);
            }
            else
            {
                auto pid = std::int32_t();
                current = parse(current, next, pid);

                auto header = uncompressed_header{packet_length, static_cast<packet_id>(pid)};
                result_ = header;
                current = parse(current, next, uncompressed_header{packet_length, static_cast<packet_id>(pid)});
            }

            return success();
        }
        catch (incomplete &i)
        {
            return failure(i);
        }
        catch (error_code &ec)
        {
            return failure(ec);
        }
    }

    template<class I1, class I2>
    auto
    frame_parser::parse(I1 first, I2 last, std::int32_t &result) -> I1
    {
        std::uint32_t accumulator = 0;
        auto success = [&] {
            result = accumulator;
            return first;
        };

        int shift = 0;
        while (first != last)
        {
            auto x = std::uint32_t(*first++);
            accumulator |= (x & 0x7fu) << shift;
            shift += 7;
            if (not(x & 0x80u))
                return success();
            if (shift > 28)
                throw make_error_code(error::invalid_varint);
        }
        throw incomplete();
    }

    template<class Iter>
    auto
    frame_parser::parse(Iter first, Iter last, uncompressed_header header) -> Iter
    {
        if (state_ == client_state::initial)
        {
            if (header.id == packet_id::client_handshake)
            {
                result_ = client_handshake();
                return parse(first, last, std::get<client_handshake>(result_.as_variant()));
            }
        }

        throw make_error_code(error::not_implemented);
    }

    template<class Iter>
    auto
    frame_parser::parse(Iter first, Iter last, client_handshake &target) -> Iter
    {
        first = parse(first, last, target.protocol_version);
        first = parse(first, last, target.server_address, 255);
        first = parse(first, last, target.server_port);
        first = parse(first, last, target.next_state);
        return first;
    }

    template<class Iter>
    auto
    frame_parser::parse(Iter first, Iter last, std::uint16_t &target) -> Iter
    {
        assert(std::distance(first, last) >= 2);

        auto convert = [](char c)
        {
            return static_cast<std::uint16_t>(std::uint16_t(static_cast<std::uint8_t>(c)));
        };
        auto h = convert(*first++) << 8;
        auto l = convert(*first++);
        target = h | l;
        return first;
    }

    template<class Iter>
    auto
    frame_parser::parse(Iter first, Iter last, std::string &target, std::size_t char_limit) -> Iter
    {
        auto size = std::int32_t();
        first = parse(first, last, size);

        const auto byte_limit = (char_limit * 4) + 3;
        if (size > byte_limit)
            throw make_error_code(error::invalid_string);

        target.reserve(size);
        while (first != last && size)
        {
            --size;
            target.push_back(*first++);
        }

        if (size)
            throw incomplete();

        return first;
    }


}