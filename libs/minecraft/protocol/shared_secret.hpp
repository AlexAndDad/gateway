#pragma once
#include "minecraft/net.hpp"
#include "minecraft/parse_error.hpp"

#include <array>
#include <cstdint>
#include <optional>
#include <initializer_list>

namespace minecraft::protocol
{
    struct shared_secret
    {
        enum : std::size_t
        {
            required_size_value = 16
        };

        using storage_type   = std::array< char, required_size_value >;
        using value_type     = storage_type ::value_type;
        using iterator       = storage_type ::iterator;
        using const_iterator = storage_type ::const_iterator;

        constexpr shared_secret()
        : opt_val_()
        {
        }

        template < class Char, std::enable_if_t< std::is_convertible_v<Char, value_type> > * = nullptr >
        constexpr shared_secret(std::initializer_list< Char > list)
        : opt_val_()
        {
            if (list.size() == required_size())
                assign(list.begin(), list.end());
            else if (list.size() != 0)
                throw system_error(error_code(error::invalid_shared_secret));
        }

        /// Generate the shared secret
        /// @post has_value() == true
        auto generate() -> void;

        template < class Iter >
        void assign(Iter first, Iter last)
        {
            auto val = storage_type {};
            std::copy(first, last, val.begin());
            opt_val_.emplace(val);
        }

        constexpr bool has_value() const { return opt_val_.has_value(); }

        auto begin() const -> const_iterator
        {
            assert(opt_val_.has_value());
            return opt_val_->begin();
        }

        auto end() const -> const_iterator
        {
            assert(opt_val_.has_value());
            return opt_val_->end();
        }

        auto data() const -> value_type const *
        {
            assert(opt_val_.has_value());
            return opt_val_->data();
        }

        auto data() -> value_type *
        {
            assert(opt_val_.has_value());
            return opt_val_->data();
        }

        auto size() const -> std::size_t
        {
            assert(opt_val_.has_value());
            return opt_val_->size();
        }

        constexpr static std::size_t required_size() { return required_size_value; }

      private:
        std::optional< storage_type > opt_val_;
    };

    inline auto buffer(shared_secret const &secret)
    {
        return secret.has_value() ? net::const_buffer(secret.data(), secret.size()) : net::const_buffer(nullptr, 0);
    }

    inline auto buffer(shared_secret &secret)
    {
        return secret.has_value() ? net::mutable_buffer(secret.data(), secret.size()) : net::mutable_buffer(nullptr, 0);
    }

    template < class Iter >
    error_code &parse(Iter &first, Iter last, shared_secret &target, error_code &ec)
    {
        if (ec.failed())
            return ec;

        auto const dist = std::distance(first, last);
        if (dist != shared_secret::required_size())
            ec = error::invalid_shared_secret;
        else
        {
            target.assign(first, last);
            first += dist;
        }
        return ec;
    }

    template < class Container >
    error_code &compose(shared_secret const &item, Container &target)
    {
        assert(item.has_value());
        target.insert(target.back(), item.begin(), item.end());
    }

}   // namespace minecraft::protocol