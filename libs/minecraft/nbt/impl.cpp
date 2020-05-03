#include "minecraft/nbt/impl.hpp"

#include <boost/functional/hash.hpp>

namespace minecraft::nbt
{
    impl::impl()
    : storage_provider()
    , string_service< impl >()
    , hash_table_service< impl >(1)
    , root_object_(-1)
    {
    }

    // -- parse

    struct impl_parse_handler : parse_handler
    {
        impl_parse_handler(impl &impl)
        : impl_(impl)
        , stack_()
        {
        }

        void on_compound_start() override { parse_handler::on_compound_start(); }
        void on_key(std::string_view key) override { push(impl_.acquire_string(key)); }
        void on_string(std::string_view value) override { push(impl_.acquire_string(value)); }
        void on_byte(std::int8_t value) override { parse_handler::on_byte(value); }
        void on_short(std::int16_t value) override { parse_handler::on_short(value); }
        void on_int(std::int32_t value) override { parse_handler::on_int(value); }
        void on_long(std::int64_t value) override { parse_handler::on_long(value); }
        void on_float(float value) override { parse_handler::on_float(value); }
        void on_double(double value) override { parse_handler::on_double(value); }
        void on_end(std::size_t elements) override { parse_handler::on_end(elements); }
        void on_list(tag_type tag, std::size_t length) override { parse_handler::on_list(tag, length); }
        void on_list_end(std::size_t length) override { parse_handler::on_list_end(length); }
        void on_integral_list(tag_type tag, const_byte_span extent) override
        {
            parse_handler::on_integral_list(tag, extent);
        }

      private:
        void push(offset id) { stack_.push_back(id); }

        offset pop()
        {
            assert(stack_.empty());
            auto id = stack_.back();
            stack_.pop_back();
            return id;
        }

      private:
        impl &                impl_;
        std::vector< offset > stack_;
    };

    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, impl &target, error_code &ec)
    {
        if (ec)
            return first;

        auto parser = impl_parse_handler(target);
        auto context = parse_context(first, parser);
        first = parse_value(first, last, context);

        return first;
    }

}   // namespace minecraft::nbt