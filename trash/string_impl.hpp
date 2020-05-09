#pragma once
#include "ref.hpp"

#include <string_view>

namespace minecraft::nbt
{
    struct string_impl
    {
        string_impl(std::uint32_t hash, std::string_view source)
        : hash_(hash)
        , length_(source.size())
        {
            std::memcpy(data_, source.data(), length_);
        }

        static auto extent(std::size_t chars) -> std::size_t
        {
            return sizeof(string_impl) + std::max(std::size_t(1), chars - 1) * sizeof(char);
        }

        auto extent() const -> std::size_t { return extent(length_); }

        static ptr< string_impl > new_(storage_provider *sp, std::string_view chars);

        auto size() const -> std::uint16_t { return length_; }
        auto hash() const -> std::uint32_t { return hash_; }
        auto data() const -> const char * { return data_; }

        auto operator==(string_impl const &r) const
        {
            if (this == &r)
                return true;
            if (length_ != r.length_)
                return false;
            return std::memcmp(data_, r.data_, length_) == 0;
        }

        void destroy(storage_provider* ) {}

      private:
        std::uint32_t hash_;
        std::uint16_t length_;
        char          data_[1];

        friend auto to_string(ptr< string_impl > pstr) -> std::string_view
        {
            if (pstr)
                return std::string_view(pstr->data_, pstr->length_);
            else
                return std::string_view("");
        }
    };

    inline void destroy_(ptr< string_impl >) {}

    inline void delete_(ptr< string_impl > pstr)
    {
        if (pstr)
        {
            auto sp = pstr.storage();
            pstr->destroy(sp);
            sp->free(pstr.get(), pstr->extent());
        }
    }
}   // namespace minecraft::nbt