#include "compound.hpp"

namespace minecraft::nbt
{
    compound::compound(std::int32_t reserve, storage_ptr sp)
    : value_base(std::move(sp))
    , ref_(ensure_storage()->new_compound(reserve).to_ref())
    {
    }

    compound::~compound()
    {
        if (sp_ and ref_)
            delete_(ptr<compound_impl>(sp_.get(), ref_));
    }

    auto compound::ensure_ptr(std::int32_t reserve) -> ptr< compound_impl >
    {
        if (ref_.empty())
        {
            auto p = ensure_storage()->new_compound(reserve);
            ref_   = p.to_ref();
            return p;
        }
        else
        {
            assert(storage());
            /// @todo resize storage if too small
            return ref_.to_ptr(storage().get());
        }
    }

    auto compound::set(std::string_view key, std::string_view value) -> compound &
    {
        auto sp     = ensure_storage().get();
        auto self   = ensure_ptr();
        auto pkey   = sp->new_string(key);
        auto pvalue = sp->new_string(value);
        self->set(sp, pkey.to_ref(), pvalue.to_ref());
        return *this;
    }

    auto compound::set(std::string_view key, compound other) -> compound &
    {
        assert(other.storage());
        assert(other.storage() == storage());
        // can't insert ourselves
        assert(other.ref_ != ref_);
        assert(other.ref_);

        auto sp   = ensure_storage().get();
        auto self = ensure_ptr();
        auto pkey = sp->new_string(key);
        self->set(sp, pkey.to_ref(), std::move(other.ref_));
        return *this;
    }

    auto compound::size() const -> std::int32_t
    {
        if (!ref_)
            return 0;

        assert(sp_);
        return ptr< compound_impl >(sp_.get(), ref_)->size();
    }

    compound::compound(compound &&other)
    : value_base(std::move(other))
    , ref_(std::move(other.ref_))
    {
    }

    compound &compound::operator=(compound &&other)
    {
        auto tmp = std::move(other);
        swap(tmp);
        return *this;
    }

    auto pretty_print(compound const &cmp) -> pretty_printer
    {
        auto pp = pretty_printer { .sp = cmp.storage().get() };
        if (cmp.has_value())
            pp.vref = cmp.ref_;
        return pp;
    }

}   // namespace minecraft::nbt