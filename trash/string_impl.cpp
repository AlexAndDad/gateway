#include "string_impl.hpp"
#include "error.hpp"
#include <boost/functional/hash.hpp>

namespace minecraft::nbt
{
    auto string_impl::new_(storage_provider *sp, std::string_view chars) -> ptr< string_impl >
    {
        if (chars.size() > std::numeric_limits<std::uint16_t>::max())
            throw system_error(error::logic_error::string_too_large);

        auto hash = std::size_t(0);
        boost::hash_combine(hash, sp->hash_poison());
        boost::hash_range(hash, chars.begin(), chars.end());

        auto size = string_impl::extent(chars.size());
        return ptr<string_impl>(sp, new (sp->alloc(size)) string_impl  (hash, chars));
    }


}   // namespace minecraft::nbt