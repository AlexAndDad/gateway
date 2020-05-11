#pragma once

#include <string>
#include <string_view>

#include "minecraft/nbt/value.hpp"

namespace minecraft::nbt
{
    struct pretty_print_handler final : parse_handler
    {
        std::string      buffer;
        std::size_t      indent_;
        std::string_view current_key_;

        auto indent() const -> std::string { return std::string(indent_, ' '); }
        auto current_key() -> std::string_view
        {
            return std::exchange(current_key_, std::string_view());
        }

        void on_compound_start() override
        {
            buffer += fmt::format("{0}Compound('{1}')\n{0}{{\n", indent(), current_key());
            current_key_ = std::string_view();
            ++indent_;
        }

        void on_key(std::string_view value) override { current_key_ = value; }

        void on_string(std::string_view value) override
        {
            buffer += fmt::format("{0}String('{1}'): '{2}'\n", indent(), current_key(), value);
        }

        virtual void on_byte(std::int8_t value) override
        {
            buffer += fmt::format("{0}Byte('{1}'): {2}\n", indent(), current_key(), std::int32_t(value));
        }
        virtual void on_short(std::int16_t value) override
        {
            buffer += fmt::format("{0}Short('{1}'): {2}\n", indent(), current_key(), value);
        }
        virtual void on_int(std::int32_t value) override
        {
            buffer += fmt::format("{0}Int('{1}'): {2}\n", indent(), current_key(), value);
        }
        virtual void on_long(std::int64_t value) override
        {
            buffer += fmt::format("{0}Long('{1}'): {2}\n", indent(), current_key(), value);
        }
        virtual void on_float(float value) override
        {
            buffer += fmt::format("{0}Float('{1}'): {2}\n", indent(), current_key(), value);
        }
        virtual void on_double(double value) override
        {
            buffer += fmt::format("{0}Double('{1}'): {2}\n", indent(), current_key(), value);
        }

        virtual void on_list(tag_type tag, std::size_t length) override
        {
            buffer += fmt::format(
                "{0}List('{1}'): {3} of {2}\n{0}{{\n", indent(), current_key(), wise_enum::to_string(tag), length);
            ++indent_;
        }
        virtual void on_list_end(std::size_t length) override
        {
            --indent_;
            buffer += fmt::format("{}}} ({} entries)\n", indent(), length);
        }

        virtual void on_integral_list(tag_type tag, minecraft::const_byte_span extent) override {
            buffer += fmt::format("{0}{1}('{2}')(", indent(), wise_enum::to_string(tag), current_key());
            const char* sep = "";
            switch(tag)
            {
            default:
                assert(!"logic error");
            case tag_type::Byte_Array:
                for (auto& b : extent)
                {
                    buffer += fmt::format("{}{:02x}", sep, b);
                    sep = " ";
                }
                break;
            case tag_type::Int_Array:
                for (auto first = extent.begin() ; first < extent.end() ; first+=4)
                {
                    auto buf = boost::endian::big_int32_buf_at ();
                    std::memcpy(buf.data(), first, 4);
                    buffer += fmt::format("{}{:08x}", sep, buf.value());
                    sep = " ";
                }
                break;
            case tag_type::Long_Array:
                for (auto first = extent.begin() ; first < extent.end() ; first+=8)
                {
                    auto buf = boost::endian::big_int64_buf_at ();
                    std::memcpy(buf.data(), first, 8);
                    buffer += fmt::format("{}{:016x}", sep, buf.value());
                    sep = " ";
                }
                break;
            }
            buffer += ")\n";
        }

        void on_end(std::size_t elements) override
        {
            if (indent_)
            {
                --indent_;
                buffer += fmt::format("{}}} ({} elements)\n", indent(), elements);
            }
            else
            {
                buffer += "End";
            }
        }
    };
}