#pragma once

#include <vector>

namespace polyfill::printers
{
    template < class T >
    struct vector_printer
    {
        vector_printer(const std::vector< T > &vector)
        :vector(vector)
        {}

        template < class Stream >
        friend Stream &operator<<(Stream &stream, const vector_printer< T > &self)
        {
            auto number = 0;
            for (auto &item : self.vector)
                stream << number++ << ": " << item << "\n";
            return stream;
        }

      private:
        const std::vector< T > &vector;
    };

    template < class T >
    vector_printer< T > print(const std::vector< T > &vector)
    {
        return vector_printer< T >(vector, [](auto && arg){return arg;});
    }

    template < class T , class F>
    vector_printer< T > print(const std::vector< T > &vector, F transform_func)
    {
        return vector_printer< T >(vector,std::move(transform_func));
    }
}   // namespace polyfill::printers