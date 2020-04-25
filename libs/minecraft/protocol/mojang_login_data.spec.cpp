#include "minecraft/protocol/mojang_login_data.hpp"

#include <catch2/catch.hpp>
#include <boost/json.hpp>


using namespace std::literals;

TEST_CASE("minecraft::protocol")
{
    auto test_data =
        "{\"id\":\"638004c70bdd42fe9310a4101c23bd39\",\"name\":\"MadMongo38\",\"properties\":[{\"name\":\"textures\","
        "\"value\":"
        "\"eyJ0aW1lc3RhbXAiOjE1ODc4NDA0OTYxMTYsInByb2ZpbGVJZCI6IjYzODAwNGM3MGJkZDQyZmU5MzEwYTQxMDFjMjNiZDM5IiwicHJvZmls"
        "ZU5hbWUiOiJNYWRNb25nbzM4IiwidGV4dHVyZXMiOnt9fQ==\",\"signature\":\"lxRTruDcs0a+lJNBZtVCPV53b+Z+bOn2GtQSXHKhD+"
        "DIoiv+zAD53qkG/DcdqFTlJHcKQVgDo65i2Upnggn9Fgbi5ykIq4TPeglJWRF1JeuI82lU2LwbNbGXKgSsfj3mRsY1iQjapfCO8Pz5fCZ/"
        "jVNo22BWzEsD8ue5arFwFhDuDhvCKBCW0FV40JUDoAZOrMWug5lg5AoiU+WLw/3e2yj0lEQV8IixaV39qPN/q47gnC/"
        "A6NHd2DU5P0KDwbYi9gOdkJRLhhXQXTJ9mzTB1P4TuED/neJRVSsRkUrhkKGW7Q9arERZ1XgU6pHPySD5sYxliMBD3/"
        "OCEUmGrakYmJ2UrWv25bXogEieslj9sdwL/kgKHhGvvyxsYGcF0DeDeY3/"
        "kIGoNf5wp2KF74XBazXWAM68yzQywlEWL1DJwpxCOnr4Fsg1mBrduHwFgcMelFXTMjxqMRpP3EW6rdaO+"
        "Cm89g0qe5sHHELw3EgD8sp7a43x7jboqEigKdLnmWjmn1uyGxIxiChmOhMtdmf/"
        "UVztrYZAgUIJHnUhHK+9VUIRUtcH8VOXfjAZwaYjJhrthh7LNzXE46tPfcgZbYJdeTOHZoIKD3G6qAfWp7ztpi/yNXyv2rdp/"
        "gCQkO3v6GCgjWZIrpDpzzRMmHZkmP/+sm2pxVBVdrO4Dg8uREWCLDY=\"}]}"s;

    minecraft::error_code ec;

    auto response = minecraft::protocol::mojang_login_data(boost::json::parse(test_data, ec));

    CHECK(response.id == "638004c70bdd42fe9310a4101c23bd39");
    CHECK(minecraft::protocol::insert_dashes(response.id) == "638004c7-0bdd-42fe-9310-a4101c23bd39");
    CHECK(response.name == "MadMongo38");
    CHECK(minecraft::protocol::easy_value(response.properties)[0]["name"] == "textures");
}
