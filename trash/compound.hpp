#pragma once
#include "compound_impl.hpp"
#include "impl.hpp"
#include "ptr.hpp"
#include "string.hpp"
#include "value_base.hpp"
#include "pretty_printer.hpp"

namespace minecraft::nbt
{
    struct pretty_printer;

    struct compound : value_base
    {
        compound(std::int32_t reserve = 1, storage_ptr sp = {});
        compound(compound &&other);
        compound(compound const &other) = delete;
        compound &operator              =(compound &&other);
        compound &operator=(compound const &other) = delete;
        ~compound();

        void swap(compound &other) noexcept
        {
            using std::swap;
            swap(sp_, other.sp_);
            swap(ref_, other.ref_);
        }

        auto has_value() const -> bool { return ref_; }

        auto set(std::string_view key, std::string_view value) -> compound &;
        auto set(std::string_view key, compound other) -> compound &;

        auto size() const -> std::int32_t;

      private:

        friend auto pretty_print(compound const& cmp) -> pretty_printer;

      private:
        auto ensure_ptr(std::int32_t reserve = 1) -> ptr< compound_impl >;

      private:
        ref< compound_impl > ref_;
    };


}   // namespace minecraft::nbt