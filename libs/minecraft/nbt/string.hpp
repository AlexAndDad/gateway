#pragma once
#include "minecraft/nbt/handle.hpp"

namespace minecraft::nbt
{

    /// public-facing string value object
    struct string : handle
    {
        using handle::handle;

        explicit string(std::string_view src, storage_ptr sp = {})
        : handle(std::move(sp))
        {
            assign(src);
        }

        void assign(std::string_view src)
        {
            auto new_str = [&] {
                if (src.size())
                {
                    ensure_storage();
                    return storage_->acquire_string(src);
                }
                else
                    return -1;
            };

            auto old = std::exchange(offset_, new_str());
            if (not invalid_offset(old))
                storage_->release_string(old);
        }

        auto view() const -> std::string_view
        {
            if (offset_ < 0)
                return { nullptr, 0 };
            auto sh = storage_->from_offset< string_header >(offset_);
            return { sh->data(), sh->size() };
        }

      private:
        friend bool operator==(string const &a, string const &b) { return a.view() == b.view(); }

        friend bool operator==(string const &a, std::string_view const &b) { return a.view() == b; }
    };

}   // namespace minecraft::nbt