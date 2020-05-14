#pragma once

#include <utility>
#include <vector>

namespace polyfill::printers
{
    struct identity
    {
        template < class Arg >
        Arg &&operator()(Arg &&arg) const
        {
            return std::forward< Arg >(arg);
        }
    };

    template < class T, class Transform >
    struct vector_printer
    {
        vector_printer(const std::vector< T > &vector, Transform transform)
        : vector(vector)
        , transform_(std::move(transform))
        {
        }

        template < class Stream >
        friend Stream &operator<<(Stream &stream, const vector_printer< T, Transform > &self)
        {
            auto number = 0;
            for (auto &item : self.vector)
                stream << number++ << ": " << self.transform_(item) << "\n";
            return stream;
        }

      private:
        const std::vector< T > &vector;
        Transform               transform_;
    };

    template < class T, class Transform = identity >
    vector_printer< T, Transform > print(const std::vector< T > &vector, Transform transform = Transform())
    {
        return vector_printer< T, Transform >(vector, std::move(transform));
    }

}   // namespace polyfill::printers