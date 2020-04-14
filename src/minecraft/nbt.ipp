
namespace minecraft::nbt
{
    template < class Iter >
    Iter encode(value const &arg, Iter iter)
    {
        auto visitor = [&iter](auto &element) { iter = encode(element, iter); };

        std::visit(visitor, arg.as_variant());
        return iter;
    }

    template<class Iter>
    Iter parse(Iter first, Iter last, value & arg, error_code& ec)
    {
        using minecraft::parse;
        auto tag = nbt_tag();
        auto current = parse(first, last, tag, ec);
        if (ec.failed())
            return first;

        switch(tag)
        {
        default:
            ec = error::invalid_nbt_tag;
            return first;
        case nbt_tag::TAG_end:
            arg = nbt_end();
        }
        return current;
    }

}   // namespace minecraft::nbt