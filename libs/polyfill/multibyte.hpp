#include <string>
#include <utf8cpp/utf8.h>

namespace polyfill
{
    //
    // from UTF16 to UTF8
    //
    void convert(std::u16string const &source, std::string &target);
    void convert(std::u16string const &source, std::u8string &target);

    void append(std::u16string const &source, std::u8string &target);

    std::u8string to_utf8(std::u16string const &from);

    //
    // From ASCII to UTF8
    //
    void convert(std::string const &source, std::u8string &target);

    void append(std::string const &source, std::u8string &target);

    std::u8string to_utf8(std::string const& from);
}   // namespace polyfill