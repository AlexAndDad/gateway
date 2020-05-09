
#include "array_impl.hpp"
#include "ptr.hpp"

namespace minecraft::nbt
{
    template < class F >
    auto compound_impl::visit_elements(storage_provider *sp, F &&f) -> void
    {
        auto pbase = ptr(sp, this->buckets(sp).data());
        for (auto count = this->capacity(); count--; pbase += 1)
            if (pbase->has_key())
            {
                visit_atom([&f, key = pbase->key()](auto &&value) { f(key, value); }, pbase->type(), pbase->atom());
                for(auto pnext = pbase->next().to_ptr(sp) ; pnext ; pnext = pnext->next().to_ptr(sp))
                    visit_atom([&f, key = pnext->key()](auto &&value) { f(key, value); }, pnext->type(), pnext->atom());
            }
    }

    template<class T>
    auto compound_impl::set(storage_provider *sp, ref< string_impl > key, ref< T > value) -> void
    {
        assert(!key.empty());
        assert(!value.empty());

        auto pself = ptr<super>(sp, this);

        auto pbucket = acquire_node(pself, key);
        assert(pbucket->has_key());

        if(pbucket->has_value())
            destroy_(sp, pbucket->type(), pbucket->atom());
        assert(not pbucket->has_value());
        pbucket->set_value(sp, std::move(value));
    }


}   // namespace minecraft::nbt
