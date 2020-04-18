#include "polyfill/multibyte.hpp"

namespace polyfill
{
    void append(std::u16string const &source, std::u8string &target)
    {
        auto first = source.data();
        auto last  = first + source.size();
        utf8::utf16to8(first, last, back_inserter(target));
    }

    void convert(std::u16string const &source, std::u8string &target)
    {
        target.clear();
        append(source, target);
    }

    std::u8string to_utf8(std::u16string const &from)
    {
        std::u8string result;
        result.reserve(from.size());
        convert(from, result);
        return result;
    }

    void append(std::string const &source, std::u8string &target)
    {
        auto first = source.data();
        auto last  = first + source.size();
        target.append(first, last);

    }

    void convert(std::string const &source, std::u8string &target)
    {
        target.clear();
        append(source, target);
    }

    std::u8string to_utf8(std::string const& from)
    {
        auto result = std::u8string();
        append(from, result);
        return result;
    }

}   // namespace polyfill