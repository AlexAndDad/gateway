#pragma once

#include <zlib.h>

namespace minecraft::protocol::compression
{
    struct result
    {
        WISE_ENUM_MEMBER((event, int), (ok, Z_OK), (stream_end, Z_STREAM_END), (need_dict, Z_NEED_DICT))

        WISE_ENUM_MEMBER((error, int),
                         (system, Z_ERRNO),
                         (stream, Z_STREAM_ERROR),
                         (data, Z_DATA_ERROR),
                         (mem, Z_MEM_ERROR),
                         (buf, Z_BUF_ERROR),
                         (version, Z_VERSION_ERROR))
    };

    inline error_category const &event_result_category()
    {
        static const struct cat : error_category
        {
            const char *name() const noexcept override { return "compression event"; }

            std::string message(int ev) const override
            {
                switch (static_cast< result::event >(ev))
                {
                case result::ok:
                    return "ok";
                case result::stream_end:
                    return "stream end";
                case result::need_dict:
                    return "need dict";
                }
                return std::string("unexpected event code: " + std::to_string(ev));
            }

            bool failed(int ev) const noexcept override { return false; }

        } cat_;
        return cat_;
    }

    inline error_category const &event_error_category()
    {
        static const struct cat : error_category
        {
            const char *name() const noexcept override { return "compression error"; }

            std::string message(int code) const override
            {
                switch (static_cast< result::error >(code))
                {
                case result::error::version:
                    return "version mismatch";
                case result::error::data:
                    return "bad data";
                case result::error::stream:
                    return "bad stream";
                case result::error::buf:
                    return "buffer error";
                case result::error::mem:
                    return "memory";
                case result::error::system:
                    return "system error";
                }
                return std::string("unexpected error code: " + std::to_string(code));
            }
        } cat_;
        return cat_;
    }

    inline constexpr bool is_event(int res)
    {
        constexpr auto &array = wise_enum::range< result::event >;
        return std::find_if(array.begin(), array.end(), [res](auto &&elem) { return elem.value == res; }) !=
               array.end();
    }

    inline constexpr bool is_error(int res)
    {
        constexpr auto &array = wise_enum::range< result::error >;
        return std::find_if(array.begin(), array.end(), [res](auto &&elem) { return elem.value == res; }) !=
               array.end();
    }

    inline auto to_error_code(int res) -> error_code
    {
        if (res == result::ok)
            return error_code();

        if (is_event(res))
            return error_code(res, event_result_category());

        assert(is_error(res));

        return error_code(res, event_error_category());
    }

    inline auto throw_if_not_ok(int res) -> int
    {
        if (res != result::event::ok)
            throw system_error(to_error_code(res));
        return res;
    }

}   // namespace minecraft::protocol::compression