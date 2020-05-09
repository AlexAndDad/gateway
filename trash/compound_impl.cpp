#include "compound_impl.hpp"

#include "array_impl.hpp"
#include "ptr.hpp"

namespace minecraft::nbt
{
    //<editor-fold Description="basic_hash_node_storage< atom_storage >">

    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp, ref< string_impl > arg) -> void
    {
        destroy_(sp, type_, atom_);
        type_      = tag_type::String;
        atom_.str_ = std::move(arg);
    }

    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp, empty_item arg) -> void
    {
        destroy_(sp, type_, atom_);
        type_        = tag_type::End;
        atom_.empty_ = arg;
    }

    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp, std::string_view arg) -> void
    {
        auto pstr = string_impl::new_(sp, arg);
        set_value(sp, pstr.to_ref());
    }
    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp, ref< generic_list_impl > arg) -> void
    {
        destroy_(sp, type_, atom_);
        type_       = tag_type::List;
        atom_.list_ = std::move(arg);
    }
    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp, ref< compound_impl > arg) -> void
    {
        destroy_(sp, type_, atom_);
        type_      = tag_type::Compound;
        atom_.cmp_ = std::move(arg);
    }

    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp, ref< byte_array_impl > arg) -> void
    {
        destroy_(sp, type_, atom_);
        type_         = tag_type::Byte_Array;
        atom_.barray_ = std::move(arg);
    }
    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp, ref< long_array_impl > arg) -> void
    {
        destroy_(sp, type_, atom_);
        type_         = tag_type::Long_Array;
        atom_.larray_ = std::move(arg);
    }
    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp, ref< int_array_impl > arg) -> void
    {
        destroy_(sp, type_, atom_);
        type_         = tag_type::Int_Array;
        atom_.iarray_ = std::move(arg);
    }

    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp,

                                                            std::int8_t value) -> void
    {
        destroy_(sp, type_, atom_);
        type_       = tag_type::Byte;
        atom_.byte_ = std::move(value);
    }

    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp, std::int16_t value) -> void
    {
        destroy_(sp, type_, atom_);
        type_        = tag_type::Short;
        atom_.short_ = std::move(value);
    }

    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp, std::int32_t value) -> void
    {
        destroy_(sp, type_, atom_);
        type_      = tag_type::Int;
        atom_.int_ = std::move(value);
    }
    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp, std::int64_t value) -> void
    {
        destroy_(sp, type_, atom_);
        type_       = tag_type::Long;
        atom_.long_ = std::move(value);
    }

    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp, float value) -> void
    {
        destroy_(sp, type_, atom_);
        type_        = tag_type::Float;
        atom_.float_ = value;
    }

    auto basic_hash_node_storage< atom_storage >::set_value(storage_provider *sp, double value) -> void
    {
        destroy_(sp, type_, atom_);
        type_         = tag_type::Double;
        atom_.double_ = value;
    }

    void basic_hash_node_storage< atom_storage >::destroy(storage_provider *sp)
    {
        assert(next_.empty());
        destroy_(sp, key_);
        destroy_(sp, type_, atom_);
        type_ = tag_type::End;
    }

    //</editor-fold>

    auto compound_impl::new_(storage_provider *sp, std::int32_t capacity) -> ptr< compound_impl >
    {
        return ptr< compound_impl >(sp, new (sp->alloc(sizeof(compound_impl))) compound_impl(sp, capacity));
    }

    auto delete_(ptr< compound_impl > pcmp) -> void
    {
        pcmp->destroy(pcmp.storage());
        pcmp.storage()->free(pcmp.get(), sizeof(*pcmp));
    }

    auto compound_impl::set(storage_provider *sp, ref< string_impl > key, empty_item value) -> void
    {
        assert(!key.empty());

        auto pself = ptr<super>(sp, this);
        auto pbucket = acquire_node(pself, key);
        assert(pbucket->has_key());
        assert(not pbucket->has_value());
        pbucket->set_value(sp, value);
    }

    auto compound_impl::set(storage_provider *sp, ref< string_impl > key, std::int8_t value) -> void
    {
        assert(!key.empty());

        auto pself = ptr<super>(sp, this);
        auto pbucket = acquire_node(pself, key);
        assert(pbucket->has_key());
        assert(not pbucket->has_value());
        pbucket->set_value(sp, value);
    }

    auto compound_impl::set(storage_provider *sp, ref< string_impl > key, std::int16_t value) -> void
    {
        assert(!key.empty());

        auto pself = ptr<super>(sp, this);
        auto pbucket = acquire_node(pself, key);
        assert(pbucket->has_key());
        assert(not pbucket->has_value());
        pbucket->set_value(sp, value);
    }
    auto compound_impl::set(storage_provider *sp, ref< string_impl > key, std::int32_t value) -> void
    {
        assert(!key.empty());

        auto pself = ptr<super>(sp, this);
        auto pbucket = acquire_node(pself, key);
        assert(pbucket->has_key());
        assert(not pbucket->has_value());
        pbucket->set_value(sp, value);
    }
    auto compound_impl::set(storage_provider *sp, ref< string_impl > key, std::int64_t value) -> void
    {
        assert(!key.empty());

        auto pself = ptr<super>(sp, this);
        auto pbucket = acquire_node(pself, key);
        assert(pbucket->has_key());
        assert(not pbucket->has_value());
        pbucket->set_value(sp, value);
    }
    auto compound_impl::set(storage_provider *sp, ref< string_impl > key, float value) -> void
    {
        assert(!key.empty());

        auto pself = ptr<super>(sp, this);
        auto pbucket = acquire_node(pself, key);
        assert(pbucket->has_key());
        assert(not pbucket->has_value());
        pbucket->set_value(sp, value);
    }
    auto compound_impl::set(storage_provider *sp, ref< string_impl > key, double value) -> void
    {
        assert(!key.empty());

        auto pself = ptr<super>(sp, this);
        auto pbucket = acquire_node(pself, key);
        assert(pbucket->has_key());
        assert(not pbucket->has_value());
        pbucket->set_value(sp, value);
    }
}   // namespace minecraft::nbt
