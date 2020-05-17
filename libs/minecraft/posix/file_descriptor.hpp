#pragma once
#include "minecraft/filesystem.hpp"
#include "minecraft/net.hpp"

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <utility>

namespace minecraft::posix
{
    inline auto validate_result(int h) -> int
    {
        if (h == -1)
            throw system_error(error_code(errno, system_category()));
        return h;
    }

    struct file_descriptor
    {
        constexpr file_descriptor()
        : handle_(invalid_handle())
        {
        }

        explicit constexpr file_descriptor(int h)
        : handle_(h)
        {
        }

        constexpr file_descriptor(file_descriptor &&other)
        : handle_(other.release())
        {
        }

        ~file_descriptor() { close(); }

        void close()
        {
            if (not invalid_handle(handle_))
                ::close(std::exchange(handle_, invalid_handle()));
        }

        int &      native_handle() { return handle_; }
        int const &native_handle() const { return handle_; }

        constexpr int release()
        {
            return std::exchange(handle_, invalid_handle());
        }

        static constexpr int  invalid_handle() { return -1; }
        static constexpr bool invalid_handle(int v)
        {
            return v == invalid_handle();
        }

        off_t size() const {
            struct stat s;
            validate_result(::fstat(handle_, &s));
            return s.st_size;
        }

        constexpr bool valid() const { return not invalid_handle(handle_); }

      private:
        int handle_;
    };

    enum access_flags
    {
        read       = O_RDONLY,
        write      = O_WRONLY,
        read_write = O_RDWR
    };


    inline auto open(fs::path const &p, access_flags flags = access_flags::read)
        -> file_descriptor
    {
        return file_descriptor(validate_result(::open(p.c_str(), flags)));
    }
}   // namespace minecraft::posix