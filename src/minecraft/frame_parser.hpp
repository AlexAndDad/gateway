#pragma once

#include <variant>
#include <tuple>
#include "net.hpp"
#include "parse_error.hpp"
#include "minecraft/packet_id.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/client/login_start.hpp"
#include "minecraft/client/handshake.hpp"

namespace minecraft {


    struct compressed_header
    {
        std::int32_t length;
        std::int32_t data_length;

    };



    using frame_variant_base = std::variant<incomplete, error_code, client::handshake, client::login_start>;

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
        parse_data(IterFirst first, IterLast last) -> IterFirst;


        template<class Iter>
        Iter
        parse_state_initial(Iter first, Iter last)
        {
            auto id = packet_id();
            first = parse(first, last, id);
            switch (id)
            {
            case packet_id::client_handshake:first = parse_specific<client::handshake>(first, last);
                break;
            default:throw make_error_code(error::invalid_packet);
            }
            return first;
        }

        template<class Iter>
        Iter
        parse_state_login(Iter first, Iter last)
        {
            auto id = login_packet_id();
            first = parse(first, last, id);
            switch (id)
            {
            case login_packet_id::login_start:first = parse_specific<client::login_start>(first, last);
                break;
            default:throw make_error_code(error::invalid_packet);
            }
            return first;
        }

        template<class Type, class Iter>
        Iter
        parse_specific(Iter first, Iter last)
        {
            result_ = Type();
            auto &target = std::get<Type>(result_.as_variant());
            using client::parse;
            return parse(first, last, target);
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

        void
        state(client_state newstate)
        {
            state_ = newstate;
        }

        client_state
        state() const
        {
            return state_;
        }

    private:

        frame_variant result_;
        client_state state_ = client_state::initial;
        bool compression_enabled_ = false;
    };


    template<class IterFirst, class IterLast>
    auto
    frame_parser::parse_data(IterFirst first, IterLast last) -> IterFirst
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
                switch (state_)
                {
                case client_state::initial:current = parse_state_initial(current, next);
                    break;
                case client_state::login:current = parse_state_login(current, next);
                    break;
                }
            }

            if (current != next)
                throw make_error_code(error::invalid_packet);


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




}