//
// Created by rhodges on 11/05/2020.
//

#ifndef GATEWAY_VALUE_PARSE_HANDLER_HPP
#define GATEWAY_VALUE_PARSE_HANDLER_HPP

#include "parse_context.hpp"
#include "value.hpp"

namespace minecraft::nbt
{
    namespace parsing
    {
        struct unexpected_value : parse_failure
        {
            unexpected_value(tag_type expected, tag_type actual)
            : parse_failure(error::unexpected_value,
                            fmt::format("Expected tag {0}, is actually {1}", expected, actual)) {};
        };

        struct expected_one : parse_failure
        {
            expected_one(std::size_t actual)
                : parse_failure(error::expected_one,
                                fmt::format("Expected one tag. Actually have {0}", actual)) {};
        };
    }   // namespace parsing

    struct parser_element
    {
        template < class T >
        parser_element(std::string n, T &&v)
        : k(std::move(n))
        , v(std::forward< T >(v))
        {
        }

        string k;
        value  v;
    };

    struct parse_stack
    {
        parse_stack()
        : impl_()
        {
        }

        parser_element *push(parser_element ref)
        {
            impl_.push_back(std::move(ref));
            return &impl_.back();
        }

        parser_element *tos()
        {
            if (impl_.empty())
                return nullptr;
            return &impl_.back();
        }

        parser_element pop()
        {
            assert(not impl_.empty());
            auto ref = std::move(impl_.back());
            impl_.pop_back();
            return ref;
        }

        /// Place all items in the stack into a compound and return it.
        /// If the stack is empty, return a null object
        /// \return ptr<compound_impl>
        auto to_compound() -> compound
        {
            auto result = compound();
            result.reserve(impl_.size());
            for (auto &[k, v] : impl_)
                result.emplace(std::move(k), std::move(v));
            impl_.clear();
            return result;
        }

        auto to_list() -> list
        {
            auto type = End;
            for (auto &[k, v] : impl_)
            {
                auto t = v.type();
                if (type == End)
                    type = t;
                else if (type != t)
                    throw std::runtime_error("tags not all same type");
            }

            if (type == End)
                throw std::runtime_error("cannot determine list type");

            auto result = list(type);
            result.reserve(impl_.size());
            for (auto &[k, v] : impl_)
                result.push_back(std::move(v));
            impl_.clear();
            return result;
        }

        /// Return the number of elements on the stack
        /// \return
        std::size_t size() const { return impl_.size(); }

      private:
        std::vector< parser_element > impl_;
    };

    class value_parse_handler final
    : public parse_handler
    , public parse_stack
    {
        std::string              name_;
        std::size_t              compound_depth_      = 0;
        static const std::size_t compound_depth_limit = 255;

      public:
        explicit value_parse_handler();

        void on_compound_start() override;
        void on_key(std::string_view key) override;
        void on_string(std::string_view s) override;

        template < class T >
        void on_arithmetic(T const &x)
        {
            handle_element({ std::move(name_), x });
        }

        void on_byte(std::int8_t const &x) override { on_arithmetic(x); }
        void on_short(std::int16_t const &x) override { on_arithmetic(x); }
        void on_int(std::int32_t const &x) override { on_arithmetic(x); }
        void on_long(std::int64_t const &x) override { on_arithmetic(x); }
        void on_float(float const &x) override { on_arithmetic(x); }
        void on_double(double const &x) override { on_arithmetic(x); }
        void on_end(std::size_t elements) override;
        void on_list(tag_type tag, std::size_t length) override;
        void on_list_end(std::size_t n) override;
        void handle_element(parser_element elem);
        void on_integral_list(tag_type type, const_byte_span bs) override;

        //
        // value extraction
        //

        /// remove the single un-named compound from top of stack
        /// @pre size() == 1
        /// @pre tos()->v.is(Compound)
        /// @post size() == 0
        /// \return the topmost compound
        /// @exception thrown if preconditions not met
        compound expect_single_compound();
    };   // namespace minecraft::nbt

}   // namespace minecraft::nbt

#endif   // GATEWAY_VALUE_PARSE_HANDLER_HPP
