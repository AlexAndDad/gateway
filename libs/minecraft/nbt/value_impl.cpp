#include "minecraft/nbt/value_impl.hpp"


#include <boost/core/demangle.hpp>
#include <boost/core/ignore_unused.hpp>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fmt/printf.h>

namespace minecraft::nbt
{
    struct print_context
    {
        const_buffer_iterator storage;
        std::string &         os;
        std::size_t           depth;

        std::string &indent() const
        {
            static const char buf[31] = "                              ";
            auto              n       = (std::min)(depth, std::size_t(30));
            os.append(buf, buf + n);
            return os;
        }
    };

    struct pretty_printer
    {
        pretty_printer(print_context ctx)
        : ctx(ctx)
        {
        }

        template<class...Args>
        void operator()(Args&&...)
        {
            boost::ignore_unused(ctx);

        }
/*
        void operator()(const value_impl &vi)
        {
            auto visitor = [&](auto const &value_atom) { (*this)(vi.name, value_atom); };

            visit(visitor, vi.value);
        }
*/
      private:
        /*
        template < class Atom >
        void operator()(string_atom const &name, Atom const &value)
        {
            boost::ignore_unused(name, value);
            auto &os    = ctx.indent();
            auto  sname = to_string(name, ctx.storage);
            os += boost::core::demangle(typeid(value).name()) + '(';
            os.append(sname.begin(), sname.end());
            os += ")\n";
        }

        void operator()(string_atom const &name, object_atom const &object)
        {
            fmt::format_to(back_inserter(ctx.indent()),
                           "TAG_Compound('{}'): {} {}\n",
                           to_string(name, ctx.storage),
                           object.items.size(),
                           (object.items.size() == 1) ? "entry" : "entries");
            fmt::format_to(back_inserter(ctx.indent()), "{{\n");
            ++ctx.depth;
            for (auto &v : object.items)
            {
                auto view = value_view(v, ctx.storage);
                (*this)(v);
            }
            --ctx.depth;
            fmt::format_to(back_inserter(ctx.indent()), "}}\n");
        }

        void operator()(string_atom const &name, string_atom const &value)
        {
            fmt::format_to(back_inserter(ctx.indent()),
                           "TAG_String('{}'): '{}'\n",
                           to_string(name, ctx.storage),
                           to_string(value, ctx.storage));
        }
*/
        print_context ctx;
    };


}   // namespace minecraft::nbt