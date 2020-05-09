#include "minecraft/nbt/impl.hpp"

#include "list_service.hpp"

#include <boost/functional/hash.hpp>

namespace minecraft::nbt
{
    impl::impl()
    : storage_provider()
    , string_service< impl >()
    , hash_table_service< impl >(1)
    , root_object_()
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

        void on_compound_start() override
        {
            current_element_.type = tag_type::Compound;
            push(std::move(current_element_));
        }

        void on_key(std::string_view key) override { current_element_.name = impl_.acquire_string(key); }

        void on_string(std::string_view value) override
        {
            auto ref      = impl_.acquire_string(value);
            auto stacktop = tos();
            if (stacktop->type == tag_type::List)
            {
                auto &list = stacktop->data.ref_;
                assert(list_service::get_type(&impl_, list) == tag_type::String);
                list = list_service::append(&impl_, list, data_ref(tag_type::String, atom { .ref_ = ref }));
            }
            else if (stacktop->type == tag_type::Compound)
            {
                current_element_.type      = tag_type::String;
                current_element_.data.ref_ = ref;
                swap2(std::move(current_element_));
            }
            else
                assert(!"logic error");
        }

        void on_byte(std::int8_t) override { assert(!"not implemented"); }

        void on_short(std::int16_t) override { assert(!"not implemented"); }
        void on_int(std::int32_t) override { assert(!"not implemented"); }
        void on_long(std::int64_t value) override
        {
            auto stacktop = tos();
            if (stacktop->type == tag_type::List)
            {
                auto &list = stacktop->data.ref_;
                assert(list_service::get_type(&impl_, list) == tag_type::Long);
                list = list_service::append(&impl_, list, data_ref(tag_type::Long, atom { .long_ = value }));
            }
            else if (stacktop->type == tag_type::Compound)
            {
                current_element_.type       = tag_type::Long;
                current_element_.data.long_ = value;
                swap2(std::move(current_element_));
            }
            else
                assert(!"logic error");
        }

        void on_float(float) override { assert(!"not implemented"); }
        void on_double(double) override { assert(!"not implemented"); }
        void on_end(std::size_t elements) override
        {
            if (stack_.empty())
            {
                assert(elements == 0);
                return;
            }

            auto e = pop();
            assert(e.type == tag_type::Compound);
            auto &cmp = e.data.ref_;
            assert(cmp == invalid_offset());
            cmp = impl_.to_offset(impl_.new_compound(impl_.compound_advise_buckets(elements)));
            while (elements--)
            {
                auto item = pop();
                impl_.compound_set(cmp, item.name, data_ref(item.type, std::move(item.data)));
            }
            if (stack_.empty())
            {
                impl_.root_object_ = data_ref(e.type, std::move(e.data));
            }
            else
            {
                push(std::move(e));
            }
        }
        void on_list(tag_type tag, std::size_t length) override
        {
            auto ref      = impl_.to_offset(list_service::new_list(&impl_, tag, length));
            auto stacktop = tos();
            if (stacktop->type == tag_type::List)
            {
                auto &list = stacktop->data.ref_;
                assert(list_service::get_type(&impl_, list) == tag_type::List);
                list = list_service::append(&impl_, list, data_ref(tag_type::List, atom { .ref_ = ref }));
            }
            else if (stacktop->type == tag_type::Compound)
            {
                current_element_.type      = tag_type::List;
                current_element_.data.ref_ = ref;
                swap2(std::move(current_element_));
            }
            else
                assert(!"logic error");
        }
        void on_list_end(std::size_t) override {}
        void on_integral_list(tag_type, const_byte_span) override { assert(!"not implemented"); }

      private:
        struct element
        {
            atom     data = atom { .ref_ = invalid_offset() };
            offset   name = invalid_offset();
            tag_type type = tag_type::End;

            element()
            : data { .ref_ = invalid_offset() }
            , name { invalid_offset() }
            , type { tag_type::End }
            {
            }

            element(element &&r)
            : data(r.data)
            , name(r.name)
            , type(r.type)
            {
                r.data.ref_ = invalid_offset();
                r.name      = invalid_offset();
                r.type      = tag_type::End;
            }

            element &operator=(element &&r)
            {
                data        = r.data;
                name        = r.name;
                type        = r.type;
                r.data.ref_ = invalid_offset();
                r.name      = invalid_offset();
                r.type      = tag_type::End;
                return *this;
            }
        };

        element current_element_;

        element *push(element ref)
        {
            stack_.push_back(std::move(ref));
            return &stack_.back();
        }

        element *tos()
        {
            assert(not stack_.empty());
            return &stack_.back();
        }

        /// push e on to the stack under the current top - i.e. insert just under tos
        element *swap2(element e)
        {
            auto p = push(std::move(*tos()));
            --p;
            *p = std::move(e);
            return p;
        }

        element pop()
        {
            assert(not stack_.empty());
            auto ref = std::move(stack_.back());
            stack_.pop_back();
            return ref;
        }

      private:
        impl &                 impl_;
        std::vector< element > stack_;
    };

    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, impl &target, error_code &ec)
    {
        if (ec)
            return first;

        auto parser  = impl_parse_handler(target);
        auto context = parse_context(parser);
        first        = parse_value(first, last, context);

        return first;
    }

    void pretty_print(std::ostream &os, impl *self)
    {
        auto &root = self->root_object_;
        pretty_print(os, self, root);
    }

}   // namespace minecraft::nbt