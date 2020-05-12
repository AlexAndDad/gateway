#include "printer.hpp"

#include "list.hpp"
#include "value.hpp"

namespace minecraft::nbt
{
    void print_visitor::operator()(list const &arg)
    {
        fmt::print(os, "[List ");
        arg.visit_all(*this);
        fmt::print(os, "]");
    }

    void print_visitor::operator()(byte_array const &value) { fmt::print(os, "[Byte_Array {}]", value.size()); }

    void print_visitor::operator()(int_array const &value) { fmt::print(os, "[Int_Array {}]", value.size()); }

    void print_visitor::operator()(long_array const &value) { fmt::print(os, "[Long_Array {}]", value.size()); }

    void print_visitor::operator()(compound const &value)
    {
        fmt::print(os, "[Compound [size {}] ", value.size());
        for (auto &[k, v] : value)
            (*this)(k, v);
        fmt::print(os, "]");
    }

    void print_visitor::operator()(string const &value) { fmt::print(os, "[String '{}']", value); }

    void print_visitor::operator()(const monostate &) { fmt::print(os, "[End]"); }

    void print_visitor::operator()(const value &v)
    {
        visit(*this, v.as_variant());
    }

}   // namespace minecraft::nbt