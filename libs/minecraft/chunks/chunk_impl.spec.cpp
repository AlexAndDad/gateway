#include "chunk_impl.hpp"
#include "minecraft/posix/mmap.hpp"
#include "minecraft/testing/chunk_data.spec.ipp"

#include <catch2/catch.hpp>
using namespace minecraft;
namespace posix = minecraft::posix;
namespace fs    = minecraft::fs;

TEST_CASE("minecraft::chunks::chunk_data_impl")
{
    auto m = mmap(
        posix::open(fs::path(minecraft::testing::chunk_data_bin_filename)));

    auto first = m.begin();
    auto last  = m.end();

    first += 0x127b;

    auto c    = chunks::chunk_impl();
    auto next = parse(first, last, c);
    CHECK(next < last);
}