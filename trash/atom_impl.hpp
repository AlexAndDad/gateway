
namespace minecraft::nbt
{
    template < class F >
    auto visit_atom(storage_provider *sp, F &&f, tag_type type, atom_storage &atom) -> decltype(auto)
    {
        switch (type)
        {
        case tag_type::End:
            return f(sp, atom.empty_);
        case tag_type::Byte:
            return f(sp, atom.byte_);
        case tag_type::Short:
            return f(sp, atom.short_);
        case tag_type::Int:
            return f(sp, atom.int_);
        case tag_type::Long:
            return f(sp, atom.long_);
        case tag_type::Float:
            return f(sp, atom.float_);
        case tag_type::Double:
            return f(sp, atom.double_);
        case tag_type::Byte_Array:
            return f(sp, atom.barray_);
        case tag_type::String:
            return f(sp, atom.str_);
        case tag_type::List:
            return f(sp, atom.list_);
        case tag_type::Compound:
            return f(sp, atom.cmp_);
        case tag_type::Int_Array:
            return f(sp, atom.iarray_);
        case tag_type::Long_Array:
            return f(sp, atom.larray_);
        }
        assert(!"logic error");
    }

    template<class F> 
    auto visit_atom(F&& f, tag_type type, atom_storage& atom) -> decltype(auto)
    {
        switch (type)
        {
        case tag_type::End:
            return f(atom.empty_);
        case tag_type::Byte:
            return f(atom.byte_);
        case tag_type::Short:
            return f(atom.short_);
        case tag_type::Int:
            return f(atom.int_);
        case tag_type::Long:
            return f(atom.long_);
        case tag_type::Float:
            return f(atom.float_);
        case tag_type::Double:
            return f(atom.double_);
        case tag_type::Byte_Array:
            return f(atom.barray_);
        case tag_type::String:
            return f(atom.str_);
        case tag_type::List:
            return f(atom.list_);
        case tag_type::Compound:
            return f(atom.cmp_);
        case tag_type::Int_Array:
            return f(atom.iarray_);
        case tag_type::Long_Array:
            return f(atom.larray_);
        }
        assert(!"logic error");
    }

    template<class F>
    auto visit_atom(F&& f, tag_type type, atom_storage const& atom) -> decltype(auto)
    {
        switch (type)
        {
        case tag_type::End:
            return f(atom.empty_);
        case tag_type::Byte:
            return f(atom.byte_);
        case tag_type::Short:
            return f(atom.short_);
        case tag_type::Int:
            return f(atom.int_);
        case tag_type::Long:
            return f(atom.long_);
        case tag_type::Float:
            return f(atom.float_);
        case tag_type::Double:
            return f(atom.double_);
        case tag_type::Byte_Array:
            return f(atom.barray_);
        case tag_type::String:
            return f(atom.str_);
        case tag_type::List:
            return f(atom.list_);
        case tag_type::Compound:
            return f(atom.cmp_);
        case tag_type::Int_Array:
            return f(atom.iarray_);
        case tag_type::Long_Array:
            return f(atom.larray_);
        }
        assert(!"logic error");
    }

    template < class Impl >
    void atom_variant< Impl >::assign_variant(ptr< string_impl > arg)
    {
        assert(type() == tag_type::End);
        type(tag_type::String);
        atom().str_ = arg.to_ref();
    }

    template < class Impl >
    void atom_variant< Impl >::assign_variant(ptr< compound_impl > arg)
    {
        assert(type() == tag_type::End);
        type(tag_type::Compound);
        atom().cmp_ = arg.to_ref();
    }

    template < class Impl >
    void atom_variant< Impl >::assign_variant(ptr< generic_list_impl > arg)
    {
        assert(type() == tag_type::End);
        type(tag_type::List);
        atom().list_ = arg.to_ref();
    }

    template < class Impl >
    void atom_variant< Impl >::assign_variant(ptr< basic_array_impl< std::int8_t > > arg)
    {
        assert(type() == tag_type::End);
        type(tag_type::Byte_Array);
        atom().barray_ = arg.to_ref();
    }

    template < class Impl >
    void atom_variant< Impl >::assign_variant(ptr< basic_array_impl< std::int32_t > > arg)
    {
        assert(type() == tag_type::End);
        type(tag_type::Int_Array);
        atom().iarray_ = arg.to_ref();
    }

    template < class Impl >
    void atom_variant< Impl >::assign_variant(ptr< basic_array_impl< std::int64_t > > arg)
    {
        assert(type() == tag_type::End);
        type(tag_type::Long_Array);
        atom().larray_ = arg.to_ref();
    }

    template < class Impl >
    void atom_variant< Impl >::assign_variant(std::int8_t const &val)
    {
        assert(type() == tag_type::End);
        type(tag_type::Byte);
        atom().byte_ = val;
    }
    template < class Impl >
    void atom_variant< Impl >::assign_variant(std::int16_t const &val)
    {
        assert(type() == tag_type::End);
        type(tag_type::Short);
        atom().short_ = val;
    }
    template < class Impl >
    void atom_variant< Impl >::assign_variant(std::int32_t const &val)
    {
        assert(type() == tag_type::End);
        type(tag_type::Int);
        atom().int_ = val;
    }
    template < class Impl >
    void atom_variant< Impl >::assign_variant(std::int64_t const &val)
    {
        assert(type() == tag_type::End);
        type(tag_type::Long);
        atom().long_ = val;
    }
    template < class Impl >
    void atom_variant< Impl >::assign_variant(double const &val)
    {
        assert(type() == tag_type::End);
        type(tag_type::Double);
        atom().double_ = val;
    }

    template < class Impl >
    void atom_variant< Impl >::assign_variant(float const &val)
    {
        assert(type() == tag_type::End);
        type(tag_type::Float);
        atom().float_ = val;
    }

}   // namespace minecraft::nbt