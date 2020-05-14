#include "pretty_printer.hpp"

#include "list.hpp"
#include "value.hpp"

namespace minecraft::nbt
{
    std::ostream &operator<<(std::ostream &os, depth_printer const &dp)
    {
        static const char spaces[] = "          "
                                     "          "
                                     "          "
                                     "  ";
        constexpr auto nspaces = std::extent_v< decltype(spaces) >;

        if (dp.depth <= nspaces)
            os.write(spaces, dp.depth);
        else
        {
            static thread_local std::string buffer;
            buffer.clear();
            fmt::format_to(back_inserter(buffer), "...depth={}", dp.depth);
            auto diff = 32 - buffer.size();
            os.write(spaces, diff);
            os.write(buffer.data(), buffer.size());
        }
        return os;
    }

    auto pretty_print_visitor::deeper() -> pretty_print_visitor
    {
        auto result = *this;
        result.depth += 1;
        return result;
    }

    void pretty_print_visitor::operator()(std::string_view name, list const &arg)
    {
        fmt::print(os,
                   "{0}{1}TAG_List('{2}'): {3} entries"
                   "\n{1}{{",
                   sep,
                   indent(depth),
                   name,
                   arg.size());

        sep = "\n";

        arg.visit_all(deeper());

        fmt::print(os, "\n{0}}}", indent(depth));
    }

    void pretty_print_visitor::operator()(std::string_view name, byte_array const &value)
    {
        fmt::print(os, "{0}{1}TAG_Byte_Array('{2}'): [{3} bytes]", sep, indent(depth), name, value.size());
    }

    void pretty_print_visitor::operator()(std::string_view name, int_array const &value)
    {
        fmt::print(os, "{0}{1}TAG_Int_Array('{2}'): [{3} Ints]", sep, indent(depth), name, value.size());
    }

    void pretty_print_visitor::operator()(std::string_view name, long_array const &value)
    {
        fmt::print(os, "{0}{1}TAG_Long_Array('{2}'): [{3} Longs]", sep, indent(depth), name, value.size());
    }

    void pretty_print_visitor::operator()(std::string_view name, compound const &value)
    {
        fmt::print(os,
                   "{0}{1}TAG_Compound('{2}'): {3} entries"
                   "\n{1}{{",
                   sep,
                   indent(depth),
                   name,
                   value.size());

        sep             = "\n";
        auto next_depth = deeper();
        for (auto &entry : value)
        {
            auto visitor = [&](auto &val) { next_depth(entry.first, val); };
            visit(visitor, entry.second);
        }

        fmt::print(os, "\n{0}}}", indent(depth));
    }

    void pretty_print_visitor::operator()(std::string_view name, string const &value)
    {
        fmt::print(os, "{0}{1}TAG_String('{2}'): '{3}'", sep, indent(depth), name, value);
        sep = "\n";
    }

    void pretty_print_visitor::operator()(std::string_view name, const monostate &)
    {
        fmt::print(os, "{}{}TAG_End('{}')", sep, indent(depth), name);
    }


}   // namespace minecraft::nbt