#include "generic_list_impl.hpp"

#include "error.hpp"
#include "ref.hpp"
#include "storage_provider.hpp"
#include "value_ref.hpp"
#include "visit.hpp"

namespace minecraft::nbt
{
    generic_list_impl::generic_list_impl(storage_provider *sp, tag_type type, std::int32_t capacity)
    : capacity_(capacity)
    , size_(0)
    , data_()
    , type_(type)
    {
        // allocate the storage
        visit_data(sp, [&]< class Type >(ptr< Type > pdummy) {
            assert(!pdummy);
            constexpr auto elem_size = sizeof(*pdummy);
            auto           blocks    = elem_size * capacity_;
            auto           p         = sp->alloc(blocks);
            data_                    = ref< void >(sp->to_offset(p));
        });
    }

    void generic_list_impl::init(ptr< generic_list_impl > p)
    {
        auto sp  = p.storage();
        p->data_ = ref< void >(sp->to_offset(sp->alloc(p->data_extent(sp))));
    }

    auto generic_list_impl::data_extent(storage_provider *sp) -> std::size_t
    {
        auto visitor = [&]< class Impl >(ptr< Impl > p) { return sizeof(*p) * this->capacity_; };

        return visit_data(sp, visitor);
    }

    ptr< generic_list_impl > generic_list_impl::new_(storage_provider *sp, tag_type type, std::int32_t capacity)
    {
        auto p = reinterpret_cast< generic_list_impl * >(sp->alloc(sizeof(generic_list_impl)));
        return ptr< generic_list_impl >(sp, new (p) generic_list_impl(sp, type, capacity));
    }

    void delete_(ptr< generic_list_impl > plist)
    {
        destroy_(plist);
        plist.storage()->free(plist.get(), sizeof(*plist));
    }

    void destroy_(ptr< generic_list_impl > plist)
    {
        auto visitor = [plist]< class Type >(ptr< Type > pdata) {
            if (pdata)
            {
                pdata.storage()->free(&*pdata, sizeof(*pdata) * plist->capacity_);
                plist->data_.reset();
            }
        };
        plist->visit_data(plist.storage(), visitor);
    }

    //

    namespace
    {
        template < class T, class F >
        void static_visit_atom(F &&, value_ref &)
        {
        }
    }   // namespace

    template < class T >
    T *generic_list_impl::capacity_check(storage_provider *sp)
    {
        auto plist = ptr(sp, &data_).cast< T >();

        if (size_ == capacity_)
        {
            auto new_cap = std::min(8, (capacity_ * 3) / 2);
            auto pv      = sp->alloc(sizeof(*plist) * new_cap);
            auto pnew    = ptr(sp, new (pv) T());

            auto first = plist.get();
            auto last  = first + this->size_;
            auto to    = pnew.get();
            while (first != last)
                *to++ = std::move(*first++);
            sp->free(plist.get(), sizeof(*plist) * capacity_);
            this->data_     = ptr< void >(sp, pnew.get()).to_ref();
            this->capacity_ = new_cap;
            plist           = pnew;
        }
        return plist.get();
    }

    auto generic_list_impl::append(storage_provider *sp, ref< generic_list_impl > arg) -> void {
        if (type_ != tag_type::List)
            throw system_error(error::wrong_value_type);

        auto p     = capacity_check< ref< generic_list_impl > >(sp);
        p[size_++] = std::move(arg);
    }

    auto generic_list_impl::append(storage_provider *sp, ref< string_impl > rstr) -> void
    {
        if (type_ != tag_type::String)
            throw system_error(error::wrong_value_type);

        auto p     = capacity_check< ref< string_impl > >(sp);
        p[size_++] = std::move(rstr);
    }

    auto generic_list_impl::append(storage_provider *sp, std::int64_t const &arg) -> void
    {
        if (type_ != tag_type::Long)
            throw system_error(error::wrong_value_type);

        auto p     = capacity_check< std::int64_t >(sp);
        p[size_++] = arg;
    }

}   // namespace minecraft::nbt