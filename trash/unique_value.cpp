#include "unique_value.hpp"

#include "error.hpp"
#include "impl_parse_handler.hpp"
#include "parse_context.hpp"

#include <boost/smart_ptr/make_shared.hpp>

namespace minecraft::nbt
{
    namespace
    {
        template < class... Ts >
        struct overloaded : Ts...
        {
            using Ts::operator()...;
        };
        template < class... Ts >
        overloaded(Ts...) -> overloaded< Ts... >;
    }   // namespace

    unique_value::~unique_value()
    {
        if (storage_ and not value_.empty())
        {
            auto sp      = storage_.get();
            auto visitor = overloaded { [&]< class T >(ref< T > &r) { destroy_(sp, r); },
                                        [&](auto &val) { boost::ignore_unused(val); } };
            visit_atom(visitor, value_.type, value_.atom);
            value_.type = tag_type::End;
        }
    }

    auto unique_value::create_compound() -> unique_value &
    {
        destroy_state();
        ensure_storage();
        this->value_ = storage_->new_compound(1).to_ref();
        return *this;
    }

    auto unique_value::destroy_state() -> void
    {
        if (storage_)
            destroy_(storage_.get(), value_.type, value_.atom);
    }

    auto unique_value::ensure_storage() -> impl_type
    {
        if (not storage_)
            storage_ = boost::make_unique< impl >();
        return storage_;
    }

    auto unique_value::set(std::string_view name, std::string_view value) -> void
    {
        switch (value_.type)
        {
        case tag_type::End:
            ensure_storage();
            this->value_ = storage_->new_compound(1).to_ref();
            [[fallthrough]];
        case tag_type::Compound:
        {
            // ensure all allocations are done before realising the address of the enclosing compound
            auto pname  = storage_->new_string(name);
            auto pvalue = storage_->new_string(value);
            value_.as_compound(storage_.get())->set(storage_.get(), pname.to_ref(), pvalue.to_ref());
            break;
        }

        default:
            throw system_error(error::compound_required);
        }
    }

    auto unique_value::size() const -> std::int32_t
    {
        if (storage_ and not value_.empty())
        {
            auto sp      = storage_.get();
            auto visitor = overloaded { [&]< class T >(ref< T > const &r) {
                                           ref< T >r2      = r;
                                           return static_cast< std::int32_t >(r2.to_ptr(sp)->size());
                                       },
                                        [&](auto const &val) {
                                            boost::ignore_unused(val);
                                            return static_cast< std::int32_t >(1);
                                        },
                                        [](empty_item const &) { return static_cast< std::int32_t >(0); } };
            return visit_atom(visitor, value_.type, value_.atom);
        }
        else
            return 0;
    }

    auto pretty_print(unique_value const &uv) -> pretty_printer
    {
        return pretty_printer { .sp = uv.storage_.get(), .vref = uv.value_ };
    }

    auto parse(const_buffer_iterator first, const_buffer_iterator last, unique_value &val, error_code &ec)
        -> const_buffer_iterator
    {
        auto context = make_parse_context(impl_parse_handler(*val.ensure_storage()));
        auto next    = parse(first, last, context, ec);
        val.value_ = context.handler().to_compound(val.storage().get()).to_ref();
        return next;
    }

}   // namespace minecraft::nbt