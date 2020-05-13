#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct redstone_wire
{enum class east_type : std::uint8_t
{
up,
side,
none
} east = east_type::none;
enum class north_type : std::uint8_t
{
up,
side,
none
} north = north_type::none;
std::uint8_t power = 0;
enum class south_type : std::uint8_t
{
up,
side,
none
} south = south_type::none;
enum class west_type : std::uint8_t
{
up,
side,
none
} west = west_type::none;
constexpr block_id_type to_id() const {
switch (east)
{
case east_type::up:
switch (north)
{
case north_type::up:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2056;
case west_type::side:
return 2057;
case west_type::none:
return 2058;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2059;
case west_type::side:
return 2060;
case west_type::none:
return 2061;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2062;
case west_type::side:
return 2063;
case west_type::none:
return 2064;
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2065;
case west_type::side:
return 2066;
case west_type::none:
return 2067;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2068;
case west_type::side:
return 2069;
case west_type::none:
return 2070;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2071;
case west_type::side:
return 2072;
case west_type::none:
return 2073;
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2074;
case west_type::side:
return 2075;
case west_type::none:
return 2076;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2077;
case west_type::side:
return 2078;
case west_type::none:
return 2079;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2080;
case west_type::side:
return 2081;
case west_type::none:
return 2082;
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2083;
case west_type::side:
return 2084;
case west_type::none:
return 2085;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2086;
case west_type::side:
return 2087;
case west_type::none:
return 2088;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2089;
case west_type::side:
return 2090;
case west_type::none:
return 2091;
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2092;
case west_type::side:
return 2093;
case west_type::none:
return 2094;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2095;
case west_type::side:
return 2096;
case west_type::none:
return 2097;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2098;
case west_type::side:
return 2099;
case west_type::none:
return 2100;
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2101;
case west_type::side:
return 2102;
case west_type::none:
return 2103;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2104;
case west_type::side:
return 2105;
case west_type::none:
return 2106;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2107;
case west_type::side:
return 2108;
case west_type::none:
return 2109;
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2110;
case west_type::side:
return 2111;
case west_type::none:
return 2112;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2113;
case west_type::side:
return 2114;
case west_type::none:
return 2115;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2116;
case west_type::side:
return 2117;
case west_type::none:
return 2118;
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2119;
case west_type::side:
return 2120;
case west_type::none:
return 2121;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2122;
case west_type::side:
return 2123;
case west_type::none:
return 2124;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2125;
case west_type::side:
return 2126;
case west_type::none:
return 2127;
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2128;
case west_type::side:
return 2129;
case west_type::none:
return 2130;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2131;
case west_type::side:
return 2132;
case west_type::none:
return 2133;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2134;
case west_type::side:
return 2135;
case west_type::none:
return 2136;
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2137;
case west_type::side:
return 2138;
case west_type::none:
return 2139;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2140;
case west_type::side:
return 2141;
case west_type::none:
return 2142;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2143;
case west_type::side:
return 2144;
case west_type::none:
return 2145;
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2146;
case west_type::side:
return 2147;
case west_type::none:
return 2148;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2149;
case west_type::side:
return 2150;
case west_type::none:
return 2151;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2152;
case west_type::side:
return 2153;
case west_type::none:
return 2154;
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2155;
case west_type::side:
return 2156;
case west_type::none:
return 2157;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2158;
case west_type::side:
return 2159;
case west_type::none:
return 2160;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2161;
case west_type::side:
return 2162;
case west_type::none:
return 2163;
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2164;
case west_type::side:
return 2165;
case west_type::none:
return 2166;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2167;
case west_type::side:
return 2168;
case west_type::none:
return 2169;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2170;
case west_type::side:
return 2171;
case west_type::none:
return 2172;
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2173;
case west_type::side:
return 2174;
case west_type::none:
return 2175;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2176;
case west_type::side:
return 2177;
case west_type::none:
return 2178;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2179;
case west_type::side:
return 2180;
case west_type::none:
return 2181;
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2182;
case west_type::side:
return 2183;
case west_type::none:
return 2184;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2185;
case west_type::side:
return 2186;
case west_type::none:
return 2187;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2188;
case west_type::side:
return 2189;
case west_type::none:
return 2190;
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2191;
case west_type::side:
return 2192;
case west_type::none:
return 2193;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2194;
case west_type::side:
return 2195;
case west_type::none:
return 2196;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2197;
case west_type::side:
return 2198;
case west_type::none:
return 2199;
}
}
}
case north_type::side:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2200;
case west_type::side:
return 2201;
case west_type::none:
return 2202;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2203;
case west_type::side:
return 2204;
case west_type::none:
return 2205;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2206;
case west_type::side:
return 2207;
case west_type::none:
return 2208;
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2209;
case west_type::side:
return 2210;
case west_type::none:
return 2211;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2212;
case west_type::side:
return 2213;
case west_type::none:
return 2214;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2215;
case west_type::side:
return 2216;
case west_type::none:
return 2217;
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2218;
case west_type::side:
return 2219;
case west_type::none:
return 2220;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2221;
case west_type::side:
return 2222;
case west_type::none:
return 2223;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2224;
case west_type::side:
return 2225;
case west_type::none:
return 2226;
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2227;
case west_type::side:
return 2228;
case west_type::none:
return 2229;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2230;
case west_type::side:
return 2231;
case west_type::none:
return 2232;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2233;
case west_type::side:
return 2234;
case west_type::none:
return 2235;
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2236;
case west_type::side:
return 2237;
case west_type::none:
return 2238;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2239;
case west_type::side:
return 2240;
case west_type::none:
return 2241;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2242;
case west_type::side:
return 2243;
case west_type::none:
return 2244;
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2245;
case west_type::side:
return 2246;
case west_type::none:
return 2247;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2248;
case west_type::side:
return 2249;
case west_type::none:
return 2250;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2251;
case west_type::side:
return 2252;
case west_type::none:
return 2253;
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2254;
case west_type::side:
return 2255;
case west_type::none:
return 2256;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2257;
case west_type::side:
return 2258;
case west_type::none:
return 2259;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2260;
case west_type::side:
return 2261;
case west_type::none:
return 2262;
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2263;
case west_type::side:
return 2264;
case west_type::none:
return 2265;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2266;
case west_type::side:
return 2267;
case west_type::none:
return 2268;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2269;
case west_type::side:
return 2270;
case west_type::none:
return 2271;
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2272;
case west_type::side:
return 2273;
case west_type::none:
return 2274;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2275;
case west_type::side:
return 2276;
case west_type::none:
return 2277;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2278;
case west_type::side:
return 2279;
case west_type::none:
return 2280;
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2281;
case west_type::side:
return 2282;
case west_type::none:
return 2283;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2284;
case west_type::side:
return 2285;
case west_type::none:
return 2286;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2287;
case west_type::side:
return 2288;
case west_type::none:
return 2289;
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2290;
case west_type::side:
return 2291;
case west_type::none:
return 2292;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2293;
case west_type::side:
return 2294;
case west_type::none:
return 2295;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2296;
case west_type::side:
return 2297;
case west_type::none:
return 2298;
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2299;
case west_type::side:
return 2300;
case west_type::none:
return 2301;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2302;
case west_type::side:
return 2303;
case west_type::none:
return 2304;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2305;
case west_type::side:
return 2306;
case west_type::none:
return 2307;
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2308;
case west_type::side:
return 2309;
case west_type::none:
return 2310;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2311;
case west_type::side:
return 2312;
case west_type::none:
return 2313;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2314;
case west_type::side:
return 2315;
case west_type::none:
return 2316;
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2317;
case west_type::side:
return 2318;
case west_type::none:
return 2319;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2320;
case west_type::side:
return 2321;
case west_type::none:
return 2322;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2323;
case west_type::side:
return 2324;
case west_type::none:
return 2325;
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2326;
case west_type::side:
return 2327;
case west_type::none:
return 2328;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2329;
case west_type::side:
return 2330;
case west_type::none:
return 2331;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2332;
case west_type::side:
return 2333;
case west_type::none:
return 2334;
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2335;
case west_type::side:
return 2336;
case west_type::none:
return 2337;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2338;
case west_type::side:
return 2339;
case west_type::none:
return 2340;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2341;
case west_type::side:
return 2342;
case west_type::none:
return 2343;
}
}
}
case north_type::none:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2344;
case west_type::side:
return 2345;
case west_type::none:
return 2346;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2347;
case west_type::side:
return 2348;
case west_type::none:
return 2349;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2350;
case west_type::side:
return 2351;
case west_type::none:
return 2352;
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2353;
case west_type::side:
return 2354;
case west_type::none:
return 2355;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2356;
case west_type::side:
return 2357;
case west_type::none:
return 2358;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2359;
case west_type::side:
return 2360;
case west_type::none:
return 2361;
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2362;
case west_type::side:
return 2363;
case west_type::none:
return 2364;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2365;
case west_type::side:
return 2366;
case west_type::none:
return 2367;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2368;
case west_type::side:
return 2369;
case west_type::none:
return 2370;
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2371;
case west_type::side:
return 2372;
case west_type::none:
return 2373;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2374;
case west_type::side:
return 2375;
case west_type::none:
return 2376;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2377;
case west_type::side:
return 2378;
case west_type::none:
return 2379;
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2380;
case west_type::side:
return 2381;
case west_type::none:
return 2382;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2383;
case west_type::side:
return 2384;
case west_type::none:
return 2385;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2386;
case west_type::side:
return 2387;
case west_type::none:
return 2388;
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2389;
case west_type::side:
return 2390;
case west_type::none:
return 2391;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2392;
case west_type::side:
return 2393;
case west_type::none:
return 2394;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2395;
case west_type::side:
return 2396;
case west_type::none:
return 2397;
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2398;
case west_type::side:
return 2399;
case west_type::none:
return 2400;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2401;
case west_type::side:
return 2402;
case west_type::none:
return 2403;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2404;
case west_type::side:
return 2405;
case west_type::none:
return 2406;
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2407;
case west_type::side:
return 2408;
case west_type::none:
return 2409;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2410;
case west_type::side:
return 2411;
case west_type::none:
return 2412;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2413;
case west_type::side:
return 2414;
case west_type::none:
return 2415;
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2416;
case west_type::side:
return 2417;
case west_type::none:
return 2418;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2419;
case west_type::side:
return 2420;
case west_type::none:
return 2421;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2422;
case west_type::side:
return 2423;
case west_type::none:
return 2424;
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2425;
case west_type::side:
return 2426;
case west_type::none:
return 2427;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2428;
case west_type::side:
return 2429;
case west_type::none:
return 2430;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2431;
case west_type::side:
return 2432;
case west_type::none:
return 2433;
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2434;
case west_type::side:
return 2435;
case west_type::none:
return 2436;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2437;
case west_type::side:
return 2438;
case west_type::none:
return 2439;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2440;
case west_type::side:
return 2441;
case west_type::none:
return 2442;
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2443;
case west_type::side:
return 2444;
case west_type::none:
return 2445;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2446;
case west_type::side:
return 2447;
case west_type::none:
return 2448;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2449;
case west_type::side:
return 2450;
case west_type::none:
return 2451;
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2452;
case west_type::side:
return 2453;
case west_type::none:
return 2454;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2455;
case west_type::side:
return 2456;
case west_type::none:
return 2457;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2458;
case west_type::side:
return 2459;
case west_type::none:
return 2460;
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2461;
case west_type::side:
return 2462;
case west_type::none:
return 2463;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2464;
case west_type::side:
return 2465;
case west_type::none:
return 2466;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2467;
case west_type::side:
return 2468;
case west_type::none:
return 2469;
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2470;
case west_type::side:
return 2471;
case west_type::none:
return 2472;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2473;
case west_type::side:
return 2474;
case west_type::none:
return 2475;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2476;
case west_type::side:
return 2477;
case west_type::none:
return 2478;
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2479;
case west_type::side:
return 2480;
case west_type::none:
return 2481;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2482;
case west_type::side:
return 2483;
case west_type::none:
return 2484;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2485;
case west_type::side:
return 2486;
case west_type::none:
return 2487;
}
}
}
}
case east_type::side:
switch (north)
{
case north_type::up:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2488;
case west_type::side:
return 2489;
case west_type::none:
return 2490;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2491;
case west_type::side:
return 2492;
case west_type::none:
return 2493;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2494;
case west_type::side:
return 2495;
case west_type::none:
return 2496;
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2497;
case west_type::side:
return 2498;
case west_type::none:
return 2499;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2500;
case west_type::side:
return 2501;
case west_type::none:
return 2502;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2503;
case west_type::side:
return 2504;
case west_type::none:
return 2505;
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2506;
case west_type::side:
return 2507;
case west_type::none:
return 2508;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2509;
case west_type::side:
return 2510;
case west_type::none:
return 2511;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2512;
case west_type::side:
return 2513;
case west_type::none:
return 2514;
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2515;
case west_type::side:
return 2516;
case west_type::none:
return 2517;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2518;
case west_type::side:
return 2519;
case west_type::none:
return 2520;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2521;
case west_type::side:
return 2522;
case west_type::none:
return 2523;
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2524;
case west_type::side:
return 2525;
case west_type::none:
return 2526;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2527;
case west_type::side:
return 2528;
case west_type::none:
return 2529;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2530;
case west_type::side:
return 2531;
case west_type::none:
return 2532;
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2533;
case west_type::side:
return 2534;
case west_type::none:
return 2535;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2536;
case west_type::side:
return 2537;
case west_type::none:
return 2538;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2539;
case west_type::side:
return 2540;
case west_type::none:
return 2541;
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2542;
case west_type::side:
return 2543;
case west_type::none:
return 2544;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2545;
case west_type::side:
return 2546;
case west_type::none:
return 2547;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2548;
case west_type::side:
return 2549;
case west_type::none:
return 2550;
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2551;
case west_type::side:
return 2552;
case west_type::none:
return 2553;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2554;
case west_type::side:
return 2555;
case west_type::none:
return 2556;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2557;
case west_type::side:
return 2558;
case west_type::none:
return 2559;
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2560;
case west_type::side:
return 2561;
case west_type::none:
return 2562;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2563;
case west_type::side:
return 2564;
case west_type::none:
return 2565;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2566;
case west_type::side:
return 2567;
case west_type::none:
return 2568;
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2569;
case west_type::side:
return 2570;
case west_type::none:
return 2571;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2572;
case west_type::side:
return 2573;
case west_type::none:
return 2574;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2575;
case west_type::side:
return 2576;
case west_type::none:
return 2577;
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2578;
case west_type::side:
return 2579;
case west_type::none:
return 2580;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2581;
case west_type::side:
return 2582;
case west_type::none:
return 2583;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2584;
case west_type::side:
return 2585;
case west_type::none:
return 2586;
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2587;
case west_type::side:
return 2588;
case west_type::none:
return 2589;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2590;
case west_type::side:
return 2591;
case west_type::none:
return 2592;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2593;
case west_type::side:
return 2594;
case west_type::none:
return 2595;
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2596;
case west_type::side:
return 2597;
case west_type::none:
return 2598;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2599;
case west_type::side:
return 2600;
case west_type::none:
return 2601;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2602;
case west_type::side:
return 2603;
case west_type::none:
return 2604;
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2605;
case west_type::side:
return 2606;
case west_type::none:
return 2607;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2608;
case west_type::side:
return 2609;
case west_type::none:
return 2610;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2611;
case west_type::side:
return 2612;
case west_type::none:
return 2613;
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2614;
case west_type::side:
return 2615;
case west_type::none:
return 2616;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2617;
case west_type::side:
return 2618;
case west_type::none:
return 2619;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2620;
case west_type::side:
return 2621;
case west_type::none:
return 2622;
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2623;
case west_type::side:
return 2624;
case west_type::none:
return 2625;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2626;
case west_type::side:
return 2627;
case west_type::none:
return 2628;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2629;
case west_type::side:
return 2630;
case west_type::none:
return 2631;
}
}
}
case north_type::side:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2632;
case west_type::side:
return 2633;
case west_type::none:
return 2634;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2635;
case west_type::side:
return 2636;
case west_type::none:
return 2637;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2638;
case west_type::side:
return 2639;
case west_type::none:
return 2640;
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2641;
case west_type::side:
return 2642;
case west_type::none:
return 2643;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2644;
case west_type::side:
return 2645;
case west_type::none:
return 2646;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2647;
case west_type::side:
return 2648;
case west_type::none:
return 2649;
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2650;
case west_type::side:
return 2651;
case west_type::none:
return 2652;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2653;
case west_type::side:
return 2654;
case west_type::none:
return 2655;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2656;
case west_type::side:
return 2657;
case west_type::none:
return 2658;
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2659;
case west_type::side:
return 2660;
case west_type::none:
return 2661;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2662;
case west_type::side:
return 2663;
case west_type::none:
return 2664;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2665;
case west_type::side:
return 2666;
case west_type::none:
return 2667;
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2668;
case west_type::side:
return 2669;
case west_type::none:
return 2670;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2671;
case west_type::side:
return 2672;
case west_type::none:
return 2673;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2674;
case west_type::side:
return 2675;
case west_type::none:
return 2676;
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2677;
case west_type::side:
return 2678;
case west_type::none:
return 2679;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2680;
case west_type::side:
return 2681;
case west_type::none:
return 2682;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2683;
case west_type::side:
return 2684;
case west_type::none:
return 2685;
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2686;
case west_type::side:
return 2687;
case west_type::none:
return 2688;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2689;
case west_type::side:
return 2690;
case west_type::none:
return 2691;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2692;
case west_type::side:
return 2693;
case west_type::none:
return 2694;
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2695;
case west_type::side:
return 2696;
case west_type::none:
return 2697;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2698;
case west_type::side:
return 2699;
case west_type::none:
return 2700;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2701;
case west_type::side:
return 2702;
case west_type::none:
return 2703;
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2704;
case west_type::side:
return 2705;
case west_type::none:
return 2706;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2707;
case west_type::side:
return 2708;
case west_type::none:
return 2709;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2710;
case west_type::side:
return 2711;
case west_type::none:
return 2712;
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2713;
case west_type::side:
return 2714;
case west_type::none:
return 2715;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2716;
case west_type::side:
return 2717;
case west_type::none:
return 2718;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2719;
case west_type::side:
return 2720;
case west_type::none:
return 2721;
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2722;
case west_type::side:
return 2723;
case west_type::none:
return 2724;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2725;
case west_type::side:
return 2726;
case west_type::none:
return 2727;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2728;
case west_type::side:
return 2729;
case west_type::none:
return 2730;
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2731;
case west_type::side:
return 2732;
case west_type::none:
return 2733;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2734;
case west_type::side:
return 2735;
case west_type::none:
return 2736;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2737;
case west_type::side:
return 2738;
case west_type::none:
return 2739;
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2740;
case west_type::side:
return 2741;
case west_type::none:
return 2742;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2743;
case west_type::side:
return 2744;
case west_type::none:
return 2745;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2746;
case west_type::side:
return 2747;
case west_type::none:
return 2748;
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2749;
case west_type::side:
return 2750;
case west_type::none:
return 2751;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2752;
case west_type::side:
return 2753;
case west_type::none:
return 2754;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2755;
case west_type::side:
return 2756;
case west_type::none:
return 2757;
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2758;
case west_type::side:
return 2759;
case west_type::none:
return 2760;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2761;
case west_type::side:
return 2762;
case west_type::none:
return 2763;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2764;
case west_type::side:
return 2765;
case west_type::none:
return 2766;
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2767;
case west_type::side:
return 2768;
case west_type::none:
return 2769;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2770;
case west_type::side:
return 2771;
case west_type::none:
return 2772;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2773;
case west_type::side:
return 2774;
case west_type::none:
return 2775;
}
}
}
case north_type::none:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2776;
case west_type::side:
return 2777;
case west_type::none:
return 2778;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2779;
case west_type::side:
return 2780;
case west_type::none:
return 2781;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2782;
case west_type::side:
return 2783;
case west_type::none:
return 2784;
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2785;
case west_type::side:
return 2786;
case west_type::none:
return 2787;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2788;
case west_type::side:
return 2789;
case west_type::none:
return 2790;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2791;
case west_type::side:
return 2792;
case west_type::none:
return 2793;
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2794;
case west_type::side:
return 2795;
case west_type::none:
return 2796;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2797;
case west_type::side:
return 2798;
case west_type::none:
return 2799;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2800;
case west_type::side:
return 2801;
case west_type::none:
return 2802;
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2803;
case west_type::side:
return 2804;
case west_type::none:
return 2805;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2806;
case west_type::side:
return 2807;
case west_type::none:
return 2808;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2809;
case west_type::side:
return 2810;
case west_type::none:
return 2811;
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2812;
case west_type::side:
return 2813;
case west_type::none:
return 2814;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2815;
case west_type::side:
return 2816;
case west_type::none:
return 2817;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2818;
case west_type::side:
return 2819;
case west_type::none:
return 2820;
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2821;
case west_type::side:
return 2822;
case west_type::none:
return 2823;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2824;
case west_type::side:
return 2825;
case west_type::none:
return 2826;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2827;
case west_type::side:
return 2828;
case west_type::none:
return 2829;
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2830;
case west_type::side:
return 2831;
case west_type::none:
return 2832;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2833;
case west_type::side:
return 2834;
case west_type::none:
return 2835;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2836;
case west_type::side:
return 2837;
case west_type::none:
return 2838;
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2839;
case west_type::side:
return 2840;
case west_type::none:
return 2841;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2842;
case west_type::side:
return 2843;
case west_type::none:
return 2844;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2845;
case west_type::side:
return 2846;
case west_type::none:
return 2847;
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2848;
case west_type::side:
return 2849;
case west_type::none:
return 2850;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2851;
case west_type::side:
return 2852;
case west_type::none:
return 2853;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2854;
case west_type::side:
return 2855;
case west_type::none:
return 2856;
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2857;
case west_type::side:
return 2858;
case west_type::none:
return 2859;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2860;
case west_type::side:
return 2861;
case west_type::none:
return 2862;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2863;
case west_type::side:
return 2864;
case west_type::none:
return 2865;
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2866;
case west_type::side:
return 2867;
case west_type::none:
return 2868;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2869;
case west_type::side:
return 2870;
case west_type::none:
return 2871;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2872;
case west_type::side:
return 2873;
case west_type::none:
return 2874;
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2875;
case west_type::side:
return 2876;
case west_type::none:
return 2877;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2878;
case west_type::side:
return 2879;
case west_type::none:
return 2880;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2881;
case west_type::side:
return 2882;
case west_type::none:
return 2883;
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2884;
case west_type::side:
return 2885;
case west_type::none:
return 2886;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2887;
case west_type::side:
return 2888;
case west_type::none:
return 2889;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2890;
case west_type::side:
return 2891;
case west_type::none:
return 2892;
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2893;
case west_type::side:
return 2894;
case west_type::none:
return 2895;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2896;
case west_type::side:
return 2897;
case west_type::none:
return 2898;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2899;
case west_type::side:
return 2900;
case west_type::none:
return 2901;
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2902;
case west_type::side:
return 2903;
case west_type::none:
return 2904;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2905;
case west_type::side:
return 2906;
case west_type::none:
return 2907;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2908;
case west_type::side:
return 2909;
case west_type::none:
return 2910;
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2911;
case west_type::side:
return 2912;
case west_type::none:
return 2913;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2914;
case west_type::side:
return 2915;
case west_type::none:
return 2916;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2917;
case west_type::side:
return 2918;
case west_type::none:
return 2919;
}
}
}
}
case east_type::none:
switch (north)
{
case north_type::up:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2920;
case west_type::side:
return 2921;
case west_type::none:
return 2922;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2923;
case west_type::side:
return 2924;
case west_type::none:
return 2925;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2926;
case west_type::side:
return 2927;
case west_type::none:
return 2928;
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2929;
case west_type::side:
return 2930;
case west_type::none:
return 2931;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2932;
case west_type::side:
return 2933;
case west_type::none:
return 2934;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2935;
case west_type::side:
return 2936;
case west_type::none:
return 2937;
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2938;
case west_type::side:
return 2939;
case west_type::none:
return 2940;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2941;
case west_type::side:
return 2942;
case west_type::none:
return 2943;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2944;
case west_type::side:
return 2945;
case west_type::none:
return 2946;
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2947;
case west_type::side:
return 2948;
case west_type::none:
return 2949;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2950;
case west_type::side:
return 2951;
case west_type::none:
return 2952;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2953;
case west_type::side:
return 2954;
case west_type::none:
return 2955;
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2956;
case west_type::side:
return 2957;
case west_type::none:
return 2958;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2959;
case west_type::side:
return 2960;
case west_type::none:
return 2961;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2962;
case west_type::side:
return 2963;
case west_type::none:
return 2964;
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2965;
case west_type::side:
return 2966;
case west_type::none:
return 2967;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2968;
case west_type::side:
return 2969;
case west_type::none:
return 2970;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2971;
case west_type::side:
return 2972;
case west_type::none:
return 2973;
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2974;
case west_type::side:
return 2975;
case west_type::none:
return 2976;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2977;
case west_type::side:
return 2978;
case west_type::none:
return 2979;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2980;
case west_type::side:
return 2981;
case west_type::none:
return 2982;
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2983;
case west_type::side:
return 2984;
case west_type::none:
return 2985;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2986;
case west_type::side:
return 2987;
case west_type::none:
return 2988;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2989;
case west_type::side:
return 2990;
case west_type::none:
return 2991;
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 2992;
case west_type::side:
return 2993;
case west_type::none:
return 2994;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 2995;
case west_type::side:
return 2996;
case west_type::none:
return 2997;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 2998;
case west_type::side:
return 2999;
case west_type::none:
return 3000;
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3001;
case west_type::side:
return 3002;
case west_type::none:
return 3003;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3004;
case west_type::side:
return 3005;
case west_type::none:
return 3006;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3007;
case west_type::side:
return 3008;
case west_type::none:
return 3009;
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3010;
case west_type::side:
return 3011;
case west_type::none:
return 3012;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3013;
case west_type::side:
return 3014;
case west_type::none:
return 3015;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3016;
case west_type::side:
return 3017;
case west_type::none:
return 3018;
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3019;
case west_type::side:
return 3020;
case west_type::none:
return 3021;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3022;
case west_type::side:
return 3023;
case west_type::none:
return 3024;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3025;
case west_type::side:
return 3026;
case west_type::none:
return 3027;
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3028;
case west_type::side:
return 3029;
case west_type::none:
return 3030;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3031;
case west_type::side:
return 3032;
case west_type::none:
return 3033;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3034;
case west_type::side:
return 3035;
case west_type::none:
return 3036;
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3037;
case west_type::side:
return 3038;
case west_type::none:
return 3039;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3040;
case west_type::side:
return 3041;
case west_type::none:
return 3042;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3043;
case west_type::side:
return 3044;
case west_type::none:
return 3045;
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3046;
case west_type::side:
return 3047;
case west_type::none:
return 3048;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3049;
case west_type::side:
return 3050;
case west_type::none:
return 3051;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3052;
case west_type::side:
return 3053;
case west_type::none:
return 3054;
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3055;
case west_type::side:
return 3056;
case west_type::none:
return 3057;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3058;
case west_type::side:
return 3059;
case west_type::none:
return 3060;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3061;
case west_type::side:
return 3062;
case west_type::none:
return 3063;
}
}
}
case north_type::side:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3064;
case west_type::side:
return 3065;
case west_type::none:
return 3066;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3067;
case west_type::side:
return 3068;
case west_type::none:
return 3069;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3070;
case west_type::side:
return 3071;
case west_type::none:
return 3072;
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3073;
case west_type::side:
return 3074;
case west_type::none:
return 3075;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3076;
case west_type::side:
return 3077;
case west_type::none:
return 3078;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3079;
case west_type::side:
return 3080;
case west_type::none:
return 3081;
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3082;
case west_type::side:
return 3083;
case west_type::none:
return 3084;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3085;
case west_type::side:
return 3086;
case west_type::none:
return 3087;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3088;
case west_type::side:
return 3089;
case west_type::none:
return 3090;
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3091;
case west_type::side:
return 3092;
case west_type::none:
return 3093;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3094;
case west_type::side:
return 3095;
case west_type::none:
return 3096;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3097;
case west_type::side:
return 3098;
case west_type::none:
return 3099;
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3100;
case west_type::side:
return 3101;
case west_type::none:
return 3102;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3103;
case west_type::side:
return 3104;
case west_type::none:
return 3105;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3106;
case west_type::side:
return 3107;
case west_type::none:
return 3108;
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3109;
case west_type::side:
return 3110;
case west_type::none:
return 3111;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3112;
case west_type::side:
return 3113;
case west_type::none:
return 3114;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3115;
case west_type::side:
return 3116;
case west_type::none:
return 3117;
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3118;
case west_type::side:
return 3119;
case west_type::none:
return 3120;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3121;
case west_type::side:
return 3122;
case west_type::none:
return 3123;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3124;
case west_type::side:
return 3125;
case west_type::none:
return 3126;
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3127;
case west_type::side:
return 3128;
case west_type::none:
return 3129;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3130;
case west_type::side:
return 3131;
case west_type::none:
return 3132;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3133;
case west_type::side:
return 3134;
case west_type::none:
return 3135;
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3136;
case west_type::side:
return 3137;
case west_type::none:
return 3138;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3139;
case west_type::side:
return 3140;
case west_type::none:
return 3141;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3142;
case west_type::side:
return 3143;
case west_type::none:
return 3144;
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3145;
case west_type::side:
return 3146;
case west_type::none:
return 3147;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3148;
case west_type::side:
return 3149;
case west_type::none:
return 3150;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3151;
case west_type::side:
return 3152;
case west_type::none:
return 3153;
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3154;
case west_type::side:
return 3155;
case west_type::none:
return 3156;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3157;
case west_type::side:
return 3158;
case west_type::none:
return 3159;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3160;
case west_type::side:
return 3161;
case west_type::none:
return 3162;
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3163;
case west_type::side:
return 3164;
case west_type::none:
return 3165;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3166;
case west_type::side:
return 3167;
case west_type::none:
return 3168;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3169;
case west_type::side:
return 3170;
case west_type::none:
return 3171;
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3172;
case west_type::side:
return 3173;
case west_type::none:
return 3174;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3175;
case west_type::side:
return 3176;
case west_type::none:
return 3177;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3178;
case west_type::side:
return 3179;
case west_type::none:
return 3180;
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3181;
case west_type::side:
return 3182;
case west_type::none:
return 3183;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3184;
case west_type::side:
return 3185;
case west_type::none:
return 3186;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3187;
case west_type::side:
return 3188;
case west_type::none:
return 3189;
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3190;
case west_type::side:
return 3191;
case west_type::none:
return 3192;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3193;
case west_type::side:
return 3194;
case west_type::none:
return 3195;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3196;
case west_type::side:
return 3197;
case west_type::none:
return 3198;
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3199;
case west_type::side:
return 3200;
case west_type::none:
return 3201;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3202;
case west_type::side:
return 3203;
case west_type::none:
return 3204;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3205;
case west_type::side:
return 3206;
case west_type::none:
return 3207;
}
}
}
case north_type::none:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3208;
case west_type::side:
return 3209;
case west_type::none:
return 3210;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3211;
case west_type::side:
return 3212;
case west_type::none:
return 3213;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3214;
case west_type::side:
return 3215;
case west_type::none:
return 3216;
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3217;
case west_type::side:
return 3218;
case west_type::none:
return 3219;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3220;
case west_type::side:
return 3221;
case west_type::none:
return 3222;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3223;
case west_type::side:
return 3224;
case west_type::none:
return 3225;
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3226;
case west_type::side:
return 3227;
case west_type::none:
return 3228;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3229;
case west_type::side:
return 3230;
case west_type::none:
return 3231;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3232;
case west_type::side:
return 3233;
case west_type::none:
return 3234;
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3235;
case west_type::side:
return 3236;
case west_type::none:
return 3237;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3238;
case west_type::side:
return 3239;
case west_type::none:
return 3240;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3241;
case west_type::side:
return 3242;
case west_type::none:
return 3243;
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3244;
case west_type::side:
return 3245;
case west_type::none:
return 3246;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3247;
case west_type::side:
return 3248;
case west_type::none:
return 3249;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3250;
case west_type::side:
return 3251;
case west_type::none:
return 3252;
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3253;
case west_type::side:
return 3254;
case west_type::none:
return 3255;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3256;
case west_type::side:
return 3257;
case west_type::none:
return 3258;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3259;
case west_type::side:
return 3260;
case west_type::none:
return 3261;
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3262;
case west_type::side:
return 3263;
case west_type::none:
return 3264;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3265;
case west_type::side:
return 3266;
case west_type::none:
return 3267;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3268;
case west_type::side:
return 3269;
case west_type::none:
return 3270;
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3271;
case west_type::side:
return 3272;
case west_type::none:
return 3273;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3274;
case west_type::side:
return 3275;
case west_type::none:
return 3276;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3277;
case west_type::side:
return 3278;
case west_type::none:
return 3279;
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3280;
case west_type::side:
return 3281;
case west_type::none:
return 3282;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3283;
case west_type::side:
return 3284;
case west_type::none:
return 3285;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3286;
case west_type::side:
return 3287;
case west_type::none:
return 3288;
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3289;
case west_type::side:
return 3290;
case west_type::none:
return 3291;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3292;
case west_type::side:
return 3293;
case west_type::none:
return 3294;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3295;
case west_type::side:
return 3296;
case west_type::none:
return 3297;
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3298;
case west_type::side:
return 3299;
case west_type::none:
return 3300;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3301;
case west_type::side:
return 3302;
case west_type::none:
return 3303;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3304;
case west_type::side:
return 3305;
case west_type::none:
return 3306;
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3307;
case west_type::side:
return 3308;
case west_type::none:
return 3309;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3310;
case west_type::side:
return 3311;
case west_type::none:
return 3312;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3313;
case west_type::side:
return 3314;
case west_type::none:
return 3315;
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3316;
case west_type::side:
return 3317;
case west_type::none:
return 3318;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3319;
case west_type::side:
return 3320;
case west_type::none:
return 3321;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3322;
case west_type::side:
return 3323;
case west_type::none:
return 3324;
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3325;
case west_type::side:
return 3326;
case west_type::none:
return 3327;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3328;
case west_type::side:
return 3329;
case west_type::none:
return 3330;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3331;
case west_type::side:
return 3332;
case west_type::none:
return 3333;
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3334;
case west_type::side:
return 3335;
case west_type::none:
return 3336;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3337;
case west_type::side:
return 3338;
case west_type::none:
return 3339;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3340;
case west_type::side:
return 3341;
case west_type::none:
return 3342;
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return 3343;
case west_type::side:
return 3344;
case west_type::none:
return 3345;
}
case south_type::side:
switch (west)
{
case west_type::up:
return 3346;
case west_type::side:
return 3347;
case west_type::none:
return 3348;
}
case south_type::none:
switch (west)
{
case west_type::up:
return 3349;
case west_type::side:
return 3350;
case west_type::none:
return 3351;
}
}
}
}
}
}
constexpr static redstone_wire from_id(block_id_type id)
{
switch (id)
{
case 2056:
return {.east = east_type::up, .north = north_type::up, .power = 0, .south = south_type::up, .west = west_type::up};
case 2057:
return {.east = east_type::up, .north = north_type::up, .power = 0, .south = south_type::up, .west = west_type::side};
case 2058:
return {.east = east_type::up, .north = north_type::up, .power = 0, .south = south_type::up, .west = west_type::none};
case 2059:
return {.east = east_type::up, .north = north_type::up, .power = 0, .south = south_type::side, .west = west_type::up};
case 2060:
return {.east = east_type::up, .north = north_type::up, .power = 0, .south = south_type::side, .west = west_type::side};
case 2061:
return {.east = east_type::up, .north = north_type::up, .power = 0, .south = south_type::side, .west = west_type::none};
case 2062:
return {.east = east_type::up, .north = north_type::up, .power = 0, .south = south_type::none, .west = west_type::up};
case 2063:
return {.east = east_type::up, .north = north_type::up, .power = 0, .south = south_type::none, .west = west_type::side};
case 2064:
return {.east = east_type::up, .north = north_type::up, .power = 0, .south = south_type::none, .west = west_type::none};
case 2065:
return {.east = east_type::up, .north = north_type::up, .power = 1, .south = south_type::up, .west = west_type::up};
case 2066:
return {.east = east_type::up, .north = north_type::up, .power = 1, .south = south_type::up, .west = west_type::side};
case 2067:
return {.east = east_type::up, .north = north_type::up, .power = 1, .south = south_type::up, .west = west_type::none};
case 2068:
return {.east = east_type::up, .north = north_type::up, .power = 1, .south = south_type::side, .west = west_type::up};
case 2069:
return {.east = east_type::up, .north = north_type::up, .power = 1, .south = south_type::side, .west = west_type::side};
case 2070:
return {.east = east_type::up, .north = north_type::up, .power = 1, .south = south_type::side, .west = west_type::none};
case 2071:
return {.east = east_type::up, .north = north_type::up, .power = 1, .south = south_type::none, .west = west_type::up};
case 2072:
return {.east = east_type::up, .north = north_type::up, .power = 1, .south = south_type::none, .west = west_type::side};
case 2073:
return {.east = east_type::up, .north = north_type::up, .power = 1, .south = south_type::none, .west = west_type::none};
case 2074:
return {.east = east_type::up, .north = north_type::up, .power = 2, .south = south_type::up, .west = west_type::up};
case 2075:
return {.east = east_type::up, .north = north_type::up, .power = 2, .south = south_type::up, .west = west_type::side};
case 2076:
return {.east = east_type::up, .north = north_type::up, .power = 2, .south = south_type::up, .west = west_type::none};
case 2077:
return {.east = east_type::up, .north = north_type::up, .power = 2, .south = south_type::side, .west = west_type::up};
case 2078:
return {.east = east_type::up, .north = north_type::up, .power = 2, .south = south_type::side, .west = west_type::side};
case 2079:
return {.east = east_type::up, .north = north_type::up, .power = 2, .south = south_type::side, .west = west_type::none};
case 2080:
return {.east = east_type::up, .north = north_type::up, .power = 2, .south = south_type::none, .west = west_type::up};
case 2081:
return {.east = east_type::up, .north = north_type::up, .power = 2, .south = south_type::none, .west = west_type::side};
case 2082:
return {.east = east_type::up, .north = north_type::up, .power = 2, .south = south_type::none, .west = west_type::none};
case 2083:
return {.east = east_type::up, .north = north_type::up, .power = 3, .south = south_type::up, .west = west_type::up};
case 2084:
return {.east = east_type::up, .north = north_type::up, .power = 3, .south = south_type::up, .west = west_type::side};
case 2085:
return {.east = east_type::up, .north = north_type::up, .power = 3, .south = south_type::up, .west = west_type::none};
case 2086:
return {.east = east_type::up, .north = north_type::up, .power = 3, .south = south_type::side, .west = west_type::up};
case 2087:
return {.east = east_type::up, .north = north_type::up, .power = 3, .south = south_type::side, .west = west_type::side};
case 2088:
return {.east = east_type::up, .north = north_type::up, .power = 3, .south = south_type::side, .west = west_type::none};
case 2089:
return {.east = east_type::up, .north = north_type::up, .power = 3, .south = south_type::none, .west = west_type::up};
case 2090:
return {.east = east_type::up, .north = north_type::up, .power = 3, .south = south_type::none, .west = west_type::side};
case 2091:
return {.east = east_type::up, .north = north_type::up, .power = 3, .south = south_type::none, .west = west_type::none};
case 2092:
return {.east = east_type::up, .north = north_type::up, .power = 4, .south = south_type::up, .west = west_type::up};
case 2093:
return {.east = east_type::up, .north = north_type::up, .power = 4, .south = south_type::up, .west = west_type::side};
case 2094:
return {.east = east_type::up, .north = north_type::up, .power = 4, .south = south_type::up, .west = west_type::none};
case 2095:
return {.east = east_type::up, .north = north_type::up, .power = 4, .south = south_type::side, .west = west_type::up};
case 2096:
return {.east = east_type::up, .north = north_type::up, .power = 4, .south = south_type::side, .west = west_type::side};
case 2097:
return {.east = east_type::up, .north = north_type::up, .power = 4, .south = south_type::side, .west = west_type::none};
case 2098:
return {.east = east_type::up, .north = north_type::up, .power = 4, .south = south_type::none, .west = west_type::up};
case 2099:
return {.east = east_type::up, .north = north_type::up, .power = 4, .south = south_type::none, .west = west_type::side};
case 2100:
return {.east = east_type::up, .north = north_type::up, .power = 4, .south = south_type::none, .west = west_type::none};
case 2101:
return {.east = east_type::up, .north = north_type::up, .power = 5, .south = south_type::up, .west = west_type::up};
case 2102:
return {.east = east_type::up, .north = north_type::up, .power = 5, .south = south_type::up, .west = west_type::side};
case 2103:
return {.east = east_type::up, .north = north_type::up, .power = 5, .south = south_type::up, .west = west_type::none};
case 2104:
return {.east = east_type::up, .north = north_type::up, .power = 5, .south = south_type::side, .west = west_type::up};
case 2105:
return {.east = east_type::up, .north = north_type::up, .power = 5, .south = south_type::side, .west = west_type::side};
case 2106:
return {.east = east_type::up, .north = north_type::up, .power = 5, .south = south_type::side, .west = west_type::none};
case 2107:
return {.east = east_type::up, .north = north_type::up, .power = 5, .south = south_type::none, .west = west_type::up};
case 2108:
return {.east = east_type::up, .north = north_type::up, .power = 5, .south = south_type::none, .west = west_type::side};
case 2109:
return {.east = east_type::up, .north = north_type::up, .power = 5, .south = south_type::none, .west = west_type::none};
case 2110:
return {.east = east_type::up, .north = north_type::up, .power = 6, .south = south_type::up, .west = west_type::up};
case 2111:
return {.east = east_type::up, .north = north_type::up, .power = 6, .south = south_type::up, .west = west_type::side};
case 2112:
return {.east = east_type::up, .north = north_type::up, .power = 6, .south = south_type::up, .west = west_type::none};
case 2113:
return {.east = east_type::up, .north = north_type::up, .power = 6, .south = south_type::side, .west = west_type::up};
case 2114:
return {.east = east_type::up, .north = north_type::up, .power = 6, .south = south_type::side, .west = west_type::side};
case 2115:
return {.east = east_type::up, .north = north_type::up, .power = 6, .south = south_type::side, .west = west_type::none};
case 2116:
return {.east = east_type::up, .north = north_type::up, .power = 6, .south = south_type::none, .west = west_type::up};
case 2117:
return {.east = east_type::up, .north = north_type::up, .power = 6, .south = south_type::none, .west = west_type::side};
case 2118:
return {.east = east_type::up, .north = north_type::up, .power = 6, .south = south_type::none, .west = west_type::none};
case 2119:
return {.east = east_type::up, .north = north_type::up, .power = 7, .south = south_type::up, .west = west_type::up};
case 2120:
return {.east = east_type::up, .north = north_type::up, .power = 7, .south = south_type::up, .west = west_type::side};
case 2121:
return {.east = east_type::up, .north = north_type::up, .power = 7, .south = south_type::up, .west = west_type::none};
case 2122:
return {.east = east_type::up, .north = north_type::up, .power = 7, .south = south_type::side, .west = west_type::up};
case 2123:
return {.east = east_type::up, .north = north_type::up, .power = 7, .south = south_type::side, .west = west_type::side};
case 2124:
return {.east = east_type::up, .north = north_type::up, .power = 7, .south = south_type::side, .west = west_type::none};
case 2125:
return {.east = east_type::up, .north = north_type::up, .power = 7, .south = south_type::none, .west = west_type::up};
case 2126:
return {.east = east_type::up, .north = north_type::up, .power = 7, .south = south_type::none, .west = west_type::side};
case 2127:
return {.east = east_type::up, .north = north_type::up, .power = 7, .south = south_type::none, .west = west_type::none};
case 2128:
return {.east = east_type::up, .north = north_type::up, .power = 8, .south = south_type::up, .west = west_type::up};
case 2129:
return {.east = east_type::up, .north = north_type::up, .power = 8, .south = south_type::up, .west = west_type::side};
case 2130:
return {.east = east_type::up, .north = north_type::up, .power = 8, .south = south_type::up, .west = west_type::none};
case 2131:
return {.east = east_type::up, .north = north_type::up, .power = 8, .south = south_type::side, .west = west_type::up};
case 2132:
return {.east = east_type::up, .north = north_type::up, .power = 8, .south = south_type::side, .west = west_type::side};
case 2133:
return {.east = east_type::up, .north = north_type::up, .power = 8, .south = south_type::side, .west = west_type::none};
case 2134:
return {.east = east_type::up, .north = north_type::up, .power = 8, .south = south_type::none, .west = west_type::up};
case 2135:
return {.east = east_type::up, .north = north_type::up, .power = 8, .south = south_type::none, .west = west_type::side};
case 2136:
return {.east = east_type::up, .north = north_type::up, .power = 8, .south = south_type::none, .west = west_type::none};
case 2137:
return {.east = east_type::up, .north = north_type::up, .power = 9, .south = south_type::up, .west = west_type::up};
case 2138:
return {.east = east_type::up, .north = north_type::up, .power = 9, .south = south_type::up, .west = west_type::side};
case 2139:
return {.east = east_type::up, .north = north_type::up, .power = 9, .south = south_type::up, .west = west_type::none};
case 2140:
return {.east = east_type::up, .north = north_type::up, .power = 9, .south = south_type::side, .west = west_type::up};
case 2141:
return {.east = east_type::up, .north = north_type::up, .power = 9, .south = south_type::side, .west = west_type::side};
case 2142:
return {.east = east_type::up, .north = north_type::up, .power = 9, .south = south_type::side, .west = west_type::none};
case 2143:
return {.east = east_type::up, .north = north_type::up, .power = 9, .south = south_type::none, .west = west_type::up};
case 2144:
return {.east = east_type::up, .north = north_type::up, .power = 9, .south = south_type::none, .west = west_type::side};
case 2145:
return {.east = east_type::up, .north = north_type::up, .power = 9, .south = south_type::none, .west = west_type::none};
case 2146:
return {.east = east_type::up, .north = north_type::up, .power = 10, .south = south_type::up, .west = west_type::up};
case 2147:
return {.east = east_type::up, .north = north_type::up, .power = 10, .south = south_type::up, .west = west_type::side};
case 2148:
return {.east = east_type::up, .north = north_type::up, .power = 10, .south = south_type::up, .west = west_type::none};
case 2149:
return {.east = east_type::up, .north = north_type::up, .power = 10, .south = south_type::side, .west = west_type::up};
case 2150:
return {.east = east_type::up, .north = north_type::up, .power = 10, .south = south_type::side, .west = west_type::side};
case 2151:
return {.east = east_type::up, .north = north_type::up, .power = 10, .south = south_type::side, .west = west_type::none};
case 2152:
return {.east = east_type::up, .north = north_type::up, .power = 10, .south = south_type::none, .west = west_type::up};
case 2153:
return {.east = east_type::up, .north = north_type::up, .power = 10, .south = south_type::none, .west = west_type::side};
case 2154:
return {.east = east_type::up, .north = north_type::up, .power = 10, .south = south_type::none, .west = west_type::none};
case 2155:
return {.east = east_type::up, .north = north_type::up, .power = 11, .south = south_type::up, .west = west_type::up};
case 2156:
return {.east = east_type::up, .north = north_type::up, .power = 11, .south = south_type::up, .west = west_type::side};
case 2157:
return {.east = east_type::up, .north = north_type::up, .power = 11, .south = south_type::up, .west = west_type::none};
case 2158:
return {.east = east_type::up, .north = north_type::up, .power = 11, .south = south_type::side, .west = west_type::up};
case 2159:
return {.east = east_type::up, .north = north_type::up, .power = 11, .south = south_type::side, .west = west_type::side};
case 2160:
return {.east = east_type::up, .north = north_type::up, .power = 11, .south = south_type::side, .west = west_type::none};
case 2161:
return {.east = east_type::up, .north = north_type::up, .power = 11, .south = south_type::none, .west = west_type::up};
case 2162:
return {.east = east_type::up, .north = north_type::up, .power = 11, .south = south_type::none, .west = west_type::side};
case 2163:
return {.east = east_type::up, .north = north_type::up, .power = 11, .south = south_type::none, .west = west_type::none};
case 2164:
return {.east = east_type::up, .north = north_type::up, .power = 12, .south = south_type::up, .west = west_type::up};
case 2165:
return {.east = east_type::up, .north = north_type::up, .power = 12, .south = south_type::up, .west = west_type::side};
case 2166:
return {.east = east_type::up, .north = north_type::up, .power = 12, .south = south_type::up, .west = west_type::none};
case 2167:
return {.east = east_type::up, .north = north_type::up, .power = 12, .south = south_type::side, .west = west_type::up};
case 2168:
return {.east = east_type::up, .north = north_type::up, .power = 12, .south = south_type::side, .west = west_type::side};
case 2169:
return {.east = east_type::up, .north = north_type::up, .power = 12, .south = south_type::side, .west = west_type::none};
case 2170:
return {.east = east_type::up, .north = north_type::up, .power = 12, .south = south_type::none, .west = west_type::up};
case 2171:
return {.east = east_type::up, .north = north_type::up, .power = 12, .south = south_type::none, .west = west_type::side};
case 2172:
return {.east = east_type::up, .north = north_type::up, .power = 12, .south = south_type::none, .west = west_type::none};
case 2173:
return {.east = east_type::up, .north = north_type::up, .power = 13, .south = south_type::up, .west = west_type::up};
case 2174:
return {.east = east_type::up, .north = north_type::up, .power = 13, .south = south_type::up, .west = west_type::side};
case 2175:
return {.east = east_type::up, .north = north_type::up, .power = 13, .south = south_type::up, .west = west_type::none};
case 2176:
return {.east = east_type::up, .north = north_type::up, .power = 13, .south = south_type::side, .west = west_type::up};
case 2177:
return {.east = east_type::up, .north = north_type::up, .power = 13, .south = south_type::side, .west = west_type::side};
case 2178:
return {.east = east_type::up, .north = north_type::up, .power = 13, .south = south_type::side, .west = west_type::none};
case 2179:
return {.east = east_type::up, .north = north_type::up, .power = 13, .south = south_type::none, .west = west_type::up};
case 2180:
return {.east = east_type::up, .north = north_type::up, .power = 13, .south = south_type::none, .west = west_type::side};
case 2181:
return {.east = east_type::up, .north = north_type::up, .power = 13, .south = south_type::none, .west = west_type::none};
case 2182:
return {.east = east_type::up, .north = north_type::up, .power = 14, .south = south_type::up, .west = west_type::up};
case 2183:
return {.east = east_type::up, .north = north_type::up, .power = 14, .south = south_type::up, .west = west_type::side};
case 2184:
return {.east = east_type::up, .north = north_type::up, .power = 14, .south = south_type::up, .west = west_type::none};
case 2185:
return {.east = east_type::up, .north = north_type::up, .power = 14, .south = south_type::side, .west = west_type::up};
case 2186:
return {.east = east_type::up, .north = north_type::up, .power = 14, .south = south_type::side, .west = west_type::side};
case 2187:
return {.east = east_type::up, .north = north_type::up, .power = 14, .south = south_type::side, .west = west_type::none};
case 2188:
return {.east = east_type::up, .north = north_type::up, .power = 14, .south = south_type::none, .west = west_type::up};
case 2189:
return {.east = east_type::up, .north = north_type::up, .power = 14, .south = south_type::none, .west = west_type::side};
case 2190:
return {.east = east_type::up, .north = north_type::up, .power = 14, .south = south_type::none, .west = west_type::none};
case 2191:
return {.east = east_type::up, .north = north_type::up, .power = 15, .south = south_type::up, .west = west_type::up};
case 2192:
return {.east = east_type::up, .north = north_type::up, .power = 15, .south = south_type::up, .west = west_type::side};
case 2193:
return {.east = east_type::up, .north = north_type::up, .power = 15, .south = south_type::up, .west = west_type::none};
case 2194:
return {.east = east_type::up, .north = north_type::up, .power = 15, .south = south_type::side, .west = west_type::up};
case 2195:
return {.east = east_type::up, .north = north_type::up, .power = 15, .south = south_type::side, .west = west_type::side};
case 2196:
return {.east = east_type::up, .north = north_type::up, .power = 15, .south = south_type::side, .west = west_type::none};
case 2197:
return {.east = east_type::up, .north = north_type::up, .power = 15, .south = south_type::none, .west = west_type::up};
case 2198:
return {.east = east_type::up, .north = north_type::up, .power = 15, .south = south_type::none, .west = west_type::side};
case 2199:
return {.east = east_type::up, .north = north_type::up, .power = 15, .south = south_type::none, .west = west_type::none};
case 2200:
return {.east = east_type::up, .north = north_type::side, .power = 0, .south = south_type::up, .west = west_type::up};
case 2201:
return {.east = east_type::up, .north = north_type::side, .power = 0, .south = south_type::up, .west = west_type::side};
case 2202:
return {.east = east_type::up, .north = north_type::side, .power = 0, .south = south_type::up, .west = west_type::none};
case 2203:
return {.east = east_type::up, .north = north_type::side, .power = 0, .south = south_type::side, .west = west_type::up};
case 2204:
return {.east = east_type::up, .north = north_type::side, .power = 0, .south = south_type::side, .west = west_type::side};
case 2205:
return {.east = east_type::up, .north = north_type::side, .power = 0, .south = south_type::side, .west = west_type::none};
case 2206:
return {.east = east_type::up, .north = north_type::side, .power = 0, .south = south_type::none, .west = west_type::up};
case 2207:
return {.east = east_type::up, .north = north_type::side, .power = 0, .south = south_type::none, .west = west_type::side};
case 2208:
return {.east = east_type::up, .north = north_type::side, .power = 0, .south = south_type::none, .west = west_type::none};
case 2209:
return {.east = east_type::up, .north = north_type::side, .power = 1, .south = south_type::up, .west = west_type::up};
case 2210:
return {.east = east_type::up, .north = north_type::side, .power = 1, .south = south_type::up, .west = west_type::side};
case 2211:
return {.east = east_type::up, .north = north_type::side, .power = 1, .south = south_type::up, .west = west_type::none};
case 2212:
return {.east = east_type::up, .north = north_type::side, .power = 1, .south = south_type::side, .west = west_type::up};
case 2213:
return {.east = east_type::up, .north = north_type::side, .power = 1, .south = south_type::side, .west = west_type::side};
case 2214:
return {.east = east_type::up, .north = north_type::side, .power = 1, .south = south_type::side, .west = west_type::none};
case 2215:
return {.east = east_type::up, .north = north_type::side, .power = 1, .south = south_type::none, .west = west_type::up};
case 2216:
return {.east = east_type::up, .north = north_type::side, .power = 1, .south = south_type::none, .west = west_type::side};
case 2217:
return {.east = east_type::up, .north = north_type::side, .power = 1, .south = south_type::none, .west = west_type::none};
case 2218:
return {.east = east_type::up, .north = north_type::side, .power = 2, .south = south_type::up, .west = west_type::up};
case 2219:
return {.east = east_type::up, .north = north_type::side, .power = 2, .south = south_type::up, .west = west_type::side};
case 2220:
return {.east = east_type::up, .north = north_type::side, .power = 2, .south = south_type::up, .west = west_type::none};
case 2221:
return {.east = east_type::up, .north = north_type::side, .power = 2, .south = south_type::side, .west = west_type::up};
case 2222:
return {.east = east_type::up, .north = north_type::side, .power = 2, .south = south_type::side, .west = west_type::side};
case 2223:
return {.east = east_type::up, .north = north_type::side, .power = 2, .south = south_type::side, .west = west_type::none};
case 2224:
return {.east = east_type::up, .north = north_type::side, .power = 2, .south = south_type::none, .west = west_type::up};
case 2225:
return {.east = east_type::up, .north = north_type::side, .power = 2, .south = south_type::none, .west = west_type::side};
case 2226:
return {.east = east_type::up, .north = north_type::side, .power = 2, .south = south_type::none, .west = west_type::none};
case 2227:
return {.east = east_type::up, .north = north_type::side, .power = 3, .south = south_type::up, .west = west_type::up};
case 2228:
return {.east = east_type::up, .north = north_type::side, .power = 3, .south = south_type::up, .west = west_type::side};
case 2229:
return {.east = east_type::up, .north = north_type::side, .power = 3, .south = south_type::up, .west = west_type::none};
case 2230:
return {.east = east_type::up, .north = north_type::side, .power = 3, .south = south_type::side, .west = west_type::up};
case 2231:
return {.east = east_type::up, .north = north_type::side, .power = 3, .south = south_type::side, .west = west_type::side};
case 2232:
return {.east = east_type::up, .north = north_type::side, .power = 3, .south = south_type::side, .west = west_type::none};
case 2233:
return {.east = east_type::up, .north = north_type::side, .power = 3, .south = south_type::none, .west = west_type::up};
case 2234:
return {.east = east_type::up, .north = north_type::side, .power = 3, .south = south_type::none, .west = west_type::side};
case 2235:
return {.east = east_type::up, .north = north_type::side, .power = 3, .south = south_type::none, .west = west_type::none};
case 2236:
return {.east = east_type::up, .north = north_type::side, .power = 4, .south = south_type::up, .west = west_type::up};
case 2237:
return {.east = east_type::up, .north = north_type::side, .power = 4, .south = south_type::up, .west = west_type::side};
case 2238:
return {.east = east_type::up, .north = north_type::side, .power = 4, .south = south_type::up, .west = west_type::none};
case 2239:
return {.east = east_type::up, .north = north_type::side, .power = 4, .south = south_type::side, .west = west_type::up};
case 2240:
return {.east = east_type::up, .north = north_type::side, .power = 4, .south = south_type::side, .west = west_type::side};
case 2241:
return {.east = east_type::up, .north = north_type::side, .power = 4, .south = south_type::side, .west = west_type::none};
case 2242:
return {.east = east_type::up, .north = north_type::side, .power = 4, .south = south_type::none, .west = west_type::up};
case 2243:
return {.east = east_type::up, .north = north_type::side, .power = 4, .south = south_type::none, .west = west_type::side};
case 2244:
return {.east = east_type::up, .north = north_type::side, .power = 4, .south = south_type::none, .west = west_type::none};
case 2245:
return {.east = east_type::up, .north = north_type::side, .power = 5, .south = south_type::up, .west = west_type::up};
case 2246:
return {.east = east_type::up, .north = north_type::side, .power = 5, .south = south_type::up, .west = west_type::side};
case 2247:
return {.east = east_type::up, .north = north_type::side, .power = 5, .south = south_type::up, .west = west_type::none};
case 2248:
return {.east = east_type::up, .north = north_type::side, .power = 5, .south = south_type::side, .west = west_type::up};
case 2249:
return {.east = east_type::up, .north = north_type::side, .power = 5, .south = south_type::side, .west = west_type::side};
case 2250:
return {.east = east_type::up, .north = north_type::side, .power = 5, .south = south_type::side, .west = west_type::none};
case 2251:
return {.east = east_type::up, .north = north_type::side, .power = 5, .south = south_type::none, .west = west_type::up};
case 2252:
return {.east = east_type::up, .north = north_type::side, .power = 5, .south = south_type::none, .west = west_type::side};
case 2253:
return {.east = east_type::up, .north = north_type::side, .power = 5, .south = south_type::none, .west = west_type::none};
case 2254:
return {.east = east_type::up, .north = north_type::side, .power = 6, .south = south_type::up, .west = west_type::up};
case 2255:
return {.east = east_type::up, .north = north_type::side, .power = 6, .south = south_type::up, .west = west_type::side};
case 2256:
return {.east = east_type::up, .north = north_type::side, .power = 6, .south = south_type::up, .west = west_type::none};
case 2257:
return {.east = east_type::up, .north = north_type::side, .power = 6, .south = south_type::side, .west = west_type::up};
case 2258:
return {.east = east_type::up, .north = north_type::side, .power = 6, .south = south_type::side, .west = west_type::side};
case 2259:
return {.east = east_type::up, .north = north_type::side, .power = 6, .south = south_type::side, .west = west_type::none};
case 2260:
return {.east = east_type::up, .north = north_type::side, .power = 6, .south = south_type::none, .west = west_type::up};
case 2261:
return {.east = east_type::up, .north = north_type::side, .power = 6, .south = south_type::none, .west = west_type::side};
case 2262:
return {.east = east_type::up, .north = north_type::side, .power = 6, .south = south_type::none, .west = west_type::none};
case 2263:
return {.east = east_type::up, .north = north_type::side, .power = 7, .south = south_type::up, .west = west_type::up};
case 2264:
return {.east = east_type::up, .north = north_type::side, .power = 7, .south = south_type::up, .west = west_type::side};
case 2265:
return {.east = east_type::up, .north = north_type::side, .power = 7, .south = south_type::up, .west = west_type::none};
case 2266:
return {.east = east_type::up, .north = north_type::side, .power = 7, .south = south_type::side, .west = west_type::up};
case 2267:
return {.east = east_type::up, .north = north_type::side, .power = 7, .south = south_type::side, .west = west_type::side};
case 2268:
return {.east = east_type::up, .north = north_type::side, .power = 7, .south = south_type::side, .west = west_type::none};
case 2269:
return {.east = east_type::up, .north = north_type::side, .power = 7, .south = south_type::none, .west = west_type::up};
case 2270:
return {.east = east_type::up, .north = north_type::side, .power = 7, .south = south_type::none, .west = west_type::side};
case 2271:
return {.east = east_type::up, .north = north_type::side, .power = 7, .south = south_type::none, .west = west_type::none};
case 2272:
return {.east = east_type::up, .north = north_type::side, .power = 8, .south = south_type::up, .west = west_type::up};
case 2273:
return {.east = east_type::up, .north = north_type::side, .power = 8, .south = south_type::up, .west = west_type::side};
case 2274:
return {.east = east_type::up, .north = north_type::side, .power = 8, .south = south_type::up, .west = west_type::none};
case 2275:
return {.east = east_type::up, .north = north_type::side, .power = 8, .south = south_type::side, .west = west_type::up};
case 2276:
return {.east = east_type::up, .north = north_type::side, .power = 8, .south = south_type::side, .west = west_type::side};
case 2277:
return {.east = east_type::up, .north = north_type::side, .power = 8, .south = south_type::side, .west = west_type::none};
case 2278:
return {.east = east_type::up, .north = north_type::side, .power = 8, .south = south_type::none, .west = west_type::up};
case 2279:
return {.east = east_type::up, .north = north_type::side, .power = 8, .south = south_type::none, .west = west_type::side};
case 2280:
return {.east = east_type::up, .north = north_type::side, .power = 8, .south = south_type::none, .west = west_type::none};
case 2281:
return {.east = east_type::up, .north = north_type::side, .power = 9, .south = south_type::up, .west = west_type::up};
case 2282:
return {.east = east_type::up, .north = north_type::side, .power = 9, .south = south_type::up, .west = west_type::side};
case 2283:
return {.east = east_type::up, .north = north_type::side, .power = 9, .south = south_type::up, .west = west_type::none};
case 2284:
return {.east = east_type::up, .north = north_type::side, .power = 9, .south = south_type::side, .west = west_type::up};
case 2285:
return {.east = east_type::up, .north = north_type::side, .power = 9, .south = south_type::side, .west = west_type::side};
case 2286:
return {.east = east_type::up, .north = north_type::side, .power = 9, .south = south_type::side, .west = west_type::none};
case 2287:
return {.east = east_type::up, .north = north_type::side, .power = 9, .south = south_type::none, .west = west_type::up};
case 2288:
return {.east = east_type::up, .north = north_type::side, .power = 9, .south = south_type::none, .west = west_type::side};
case 2289:
return {.east = east_type::up, .north = north_type::side, .power = 9, .south = south_type::none, .west = west_type::none};
case 2290:
return {.east = east_type::up, .north = north_type::side, .power = 10, .south = south_type::up, .west = west_type::up};
case 2291:
return {.east = east_type::up, .north = north_type::side, .power = 10, .south = south_type::up, .west = west_type::side};
case 2292:
return {.east = east_type::up, .north = north_type::side, .power = 10, .south = south_type::up, .west = west_type::none};
case 2293:
return {.east = east_type::up, .north = north_type::side, .power = 10, .south = south_type::side, .west = west_type::up};
case 2294:
return {.east = east_type::up, .north = north_type::side, .power = 10, .south = south_type::side, .west = west_type::side};
case 2295:
return {.east = east_type::up, .north = north_type::side, .power = 10, .south = south_type::side, .west = west_type::none};
case 2296:
return {.east = east_type::up, .north = north_type::side, .power = 10, .south = south_type::none, .west = west_type::up};
case 2297:
return {.east = east_type::up, .north = north_type::side, .power = 10, .south = south_type::none, .west = west_type::side};
case 2298:
return {.east = east_type::up, .north = north_type::side, .power = 10, .south = south_type::none, .west = west_type::none};
case 2299:
return {.east = east_type::up, .north = north_type::side, .power = 11, .south = south_type::up, .west = west_type::up};
case 2300:
return {.east = east_type::up, .north = north_type::side, .power = 11, .south = south_type::up, .west = west_type::side};
case 2301:
return {.east = east_type::up, .north = north_type::side, .power = 11, .south = south_type::up, .west = west_type::none};
case 2302:
return {.east = east_type::up, .north = north_type::side, .power = 11, .south = south_type::side, .west = west_type::up};
case 2303:
return {.east = east_type::up, .north = north_type::side, .power = 11, .south = south_type::side, .west = west_type::side};
case 2304:
return {.east = east_type::up, .north = north_type::side, .power = 11, .south = south_type::side, .west = west_type::none};
case 2305:
return {.east = east_type::up, .north = north_type::side, .power = 11, .south = south_type::none, .west = west_type::up};
case 2306:
return {.east = east_type::up, .north = north_type::side, .power = 11, .south = south_type::none, .west = west_type::side};
case 2307:
return {.east = east_type::up, .north = north_type::side, .power = 11, .south = south_type::none, .west = west_type::none};
case 2308:
return {.east = east_type::up, .north = north_type::side, .power = 12, .south = south_type::up, .west = west_type::up};
case 2309:
return {.east = east_type::up, .north = north_type::side, .power = 12, .south = south_type::up, .west = west_type::side};
case 2310:
return {.east = east_type::up, .north = north_type::side, .power = 12, .south = south_type::up, .west = west_type::none};
case 2311:
return {.east = east_type::up, .north = north_type::side, .power = 12, .south = south_type::side, .west = west_type::up};
case 2312:
return {.east = east_type::up, .north = north_type::side, .power = 12, .south = south_type::side, .west = west_type::side};
case 2313:
return {.east = east_type::up, .north = north_type::side, .power = 12, .south = south_type::side, .west = west_type::none};
case 2314:
return {.east = east_type::up, .north = north_type::side, .power = 12, .south = south_type::none, .west = west_type::up};
case 2315:
return {.east = east_type::up, .north = north_type::side, .power = 12, .south = south_type::none, .west = west_type::side};
case 2316:
return {.east = east_type::up, .north = north_type::side, .power = 12, .south = south_type::none, .west = west_type::none};
case 2317:
return {.east = east_type::up, .north = north_type::side, .power = 13, .south = south_type::up, .west = west_type::up};
case 2318:
return {.east = east_type::up, .north = north_type::side, .power = 13, .south = south_type::up, .west = west_type::side};
case 2319:
return {.east = east_type::up, .north = north_type::side, .power = 13, .south = south_type::up, .west = west_type::none};
case 2320:
return {.east = east_type::up, .north = north_type::side, .power = 13, .south = south_type::side, .west = west_type::up};
case 2321:
return {.east = east_type::up, .north = north_type::side, .power = 13, .south = south_type::side, .west = west_type::side};
case 2322:
return {.east = east_type::up, .north = north_type::side, .power = 13, .south = south_type::side, .west = west_type::none};
case 2323:
return {.east = east_type::up, .north = north_type::side, .power = 13, .south = south_type::none, .west = west_type::up};
case 2324:
return {.east = east_type::up, .north = north_type::side, .power = 13, .south = south_type::none, .west = west_type::side};
case 2325:
return {.east = east_type::up, .north = north_type::side, .power = 13, .south = south_type::none, .west = west_type::none};
case 2326:
return {.east = east_type::up, .north = north_type::side, .power = 14, .south = south_type::up, .west = west_type::up};
case 2327:
return {.east = east_type::up, .north = north_type::side, .power = 14, .south = south_type::up, .west = west_type::side};
case 2328:
return {.east = east_type::up, .north = north_type::side, .power = 14, .south = south_type::up, .west = west_type::none};
case 2329:
return {.east = east_type::up, .north = north_type::side, .power = 14, .south = south_type::side, .west = west_type::up};
case 2330:
return {.east = east_type::up, .north = north_type::side, .power = 14, .south = south_type::side, .west = west_type::side};
case 2331:
return {.east = east_type::up, .north = north_type::side, .power = 14, .south = south_type::side, .west = west_type::none};
case 2332:
return {.east = east_type::up, .north = north_type::side, .power = 14, .south = south_type::none, .west = west_type::up};
case 2333:
return {.east = east_type::up, .north = north_type::side, .power = 14, .south = south_type::none, .west = west_type::side};
case 2334:
return {.east = east_type::up, .north = north_type::side, .power = 14, .south = south_type::none, .west = west_type::none};
case 2335:
return {.east = east_type::up, .north = north_type::side, .power = 15, .south = south_type::up, .west = west_type::up};
case 2336:
return {.east = east_type::up, .north = north_type::side, .power = 15, .south = south_type::up, .west = west_type::side};
case 2337:
return {.east = east_type::up, .north = north_type::side, .power = 15, .south = south_type::up, .west = west_type::none};
case 2338:
return {.east = east_type::up, .north = north_type::side, .power = 15, .south = south_type::side, .west = west_type::up};
case 2339:
return {.east = east_type::up, .north = north_type::side, .power = 15, .south = south_type::side, .west = west_type::side};
case 2340:
return {.east = east_type::up, .north = north_type::side, .power = 15, .south = south_type::side, .west = west_type::none};
case 2341:
return {.east = east_type::up, .north = north_type::side, .power = 15, .south = south_type::none, .west = west_type::up};
case 2342:
return {.east = east_type::up, .north = north_type::side, .power = 15, .south = south_type::none, .west = west_type::side};
case 2343:
return {.east = east_type::up, .north = north_type::side, .power = 15, .south = south_type::none, .west = west_type::none};
case 2344:
return {.east = east_type::up, .north = north_type::none, .power = 0, .south = south_type::up, .west = west_type::up};
case 2345:
return {.east = east_type::up, .north = north_type::none, .power = 0, .south = south_type::up, .west = west_type::side};
case 2346:
return {.east = east_type::up, .north = north_type::none, .power = 0, .south = south_type::up, .west = west_type::none};
case 2347:
return {.east = east_type::up, .north = north_type::none, .power = 0, .south = south_type::side, .west = west_type::up};
case 2348:
return {.east = east_type::up, .north = north_type::none, .power = 0, .south = south_type::side, .west = west_type::side};
case 2349:
return {.east = east_type::up, .north = north_type::none, .power = 0, .south = south_type::side, .west = west_type::none};
case 2350:
return {.east = east_type::up, .north = north_type::none, .power = 0, .south = south_type::none, .west = west_type::up};
case 2351:
return {.east = east_type::up, .north = north_type::none, .power = 0, .south = south_type::none, .west = west_type::side};
case 2352:
return {.east = east_type::up, .north = north_type::none, .power = 0, .south = south_type::none, .west = west_type::none};
case 2353:
return {.east = east_type::up, .north = north_type::none, .power = 1, .south = south_type::up, .west = west_type::up};
case 2354:
return {.east = east_type::up, .north = north_type::none, .power = 1, .south = south_type::up, .west = west_type::side};
case 2355:
return {.east = east_type::up, .north = north_type::none, .power = 1, .south = south_type::up, .west = west_type::none};
case 2356:
return {.east = east_type::up, .north = north_type::none, .power = 1, .south = south_type::side, .west = west_type::up};
case 2357:
return {.east = east_type::up, .north = north_type::none, .power = 1, .south = south_type::side, .west = west_type::side};
case 2358:
return {.east = east_type::up, .north = north_type::none, .power = 1, .south = south_type::side, .west = west_type::none};
case 2359:
return {.east = east_type::up, .north = north_type::none, .power = 1, .south = south_type::none, .west = west_type::up};
case 2360:
return {.east = east_type::up, .north = north_type::none, .power = 1, .south = south_type::none, .west = west_type::side};
case 2361:
return {.east = east_type::up, .north = north_type::none, .power = 1, .south = south_type::none, .west = west_type::none};
case 2362:
return {.east = east_type::up, .north = north_type::none, .power = 2, .south = south_type::up, .west = west_type::up};
case 2363:
return {.east = east_type::up, .north = north_type::none, .power = 2, .south = south_type::up, .west = west_type::side};
case 2364:
return {.east = east_type::up, .north = north_type::none, .power = 2, .south = south_type::up, .west = west_type::none};
case 2365:
return {.east = east_type::up, .north = north_type::none, .power = 2, .south = south_type::side, .west = west_type::up};
case 2366:
return {.east = east_type::up, .north = north_type::none, .power = 2, .south = south_type::side, .west = west_type::side};
case 2367:
return {.east = east_type::up, .north = north_type::none, .power = 2, .south = south_type::side, .west = west_type::none};
case 2368:
return {.east = east_type::up, .north = north_type::none, .power = 2, .south = south_type::none, .west = west_type::up};
case 2369:
return {.east = east_type::up, .north = north_type::none, .power = 2, .south = south_type::none, .west = west_type::side};
case 2370:
return {.east = east_type::up, .north = north_type::none, .power = 2, .south = south_type::none, .west = west_type::none};
case 2371:
return {.east = east_type::up, .north = north_type::none, .power = 3, .south = south_type::up, .west = west_type::up};
case 2372:
return {.east = east_type::up, .north = north_type::none, .power = 3, .south = south_type::up, .west = west_type::side};
case 2373:
return {.east = east_type::up, .north = north_type::none, .power = 3, .south = south_type::up, .west = west_type::none};
case 2374:
return {.east = east_type::up, .north = north_type::none, .power = 3, .south = south_type::side, .west = west_type::up};
case 2375:
return {.east = east_type::up, .north = north_type::none, .power = 3, .south = south_type::side, .west = west_type::side};
case 2376:
return {.east = east_type::up, .north = north_type::none, .power = 3, .south = south_type::side, .west = west_type::none};
case 2377:
return {.east = east_type::up, .north = north_type::none, .power = 3, .south = south_type::none, .west = west_type::up};
case 2378:
return {.east = east_type::up, .north = north_type::none, .power = 3, .south = south_type::none, .west = west_type::side};
case 2379:
return {.east = east_type::up, .north = north_type::none, .power = 3, .south = south_type::none, .west = west_type::none};
case 2380:
return {.east = east_type::up, .north = north_type::none, .power = 4, .south = south_type::up, .west = west_type::up};
case 2381:
return {.east = east_type::up, .north = north_type::none, .power = 4, .south = south_type::up, .west = west_type::side};
case 2382:
return {.east = east_type::up, .north = north_type::none, .power = 4, .south = south_type::up, .west = west_type::none};
case 2383:
return {.east = east_type::up, .north = north_type::none, .power = 4, .south = south_type::side, .west = west_type::up};
case 2384:
return {.east = east_type::up, .north = north_type::none, .power = 4, .south = south_type::side, .west = west_type::side};
case 2385:
return {.east = east_type::up, .north = north_type::none, .power = 4, .south = south_type::side, .west = west_type::none};
case 2386:
return {.east = east_type::up, .north = north_type::none, .power = 4, .south = south_type::none, .west = west_type::up};
case 2387:
return {.east = east_type::up, .north = north_type::none, .power = 4, .south = south_type::none, .west = west_type::side};
case 2388:
return {.east = east_type::up, .north = north_type::none, .power = 4, .south = south_type::none, .west = west_type::none};
case 2389:
return {.east = east_type::up, .north = north_type::none, .power = 5, .south = south_type::up, .west = west_type::up};
case 2390:
return {.east = east_type::up, .north = north_type::none, .power = 5, .south = south_type::up, .west = west_type::side};
case 2391:
return {.east = east_type::up, .north = north_type::none, .power = 5, .south = south_type::up, .west = west_type::none};
case 2392:
return {.east = east_type::up, .north = north_type::none, .power = 5, .south = south_type::side, .west = west_type::up};
case 2393:
return {.east = east_type::up, .north = north_type::none, .power = 5, .south = south_type::side, .west = west_type::side};
case 2394:
return {.east = east_type::up, .north = north_type::none, .power = 5, .south = south_type::side, .west = west_type::none};
case 2395:
return {.east = east_type::up, .north = north_type::none, .power = 5, .south = south_type::none, .west = west_type::up};
case 2396:
return {.east = east_type::up, .north = north_type::none, .power = 5, .south = south_type::none, .west = west_type::side};
case 2397:
return {.east = east_type::up, .north = north_type::none, .power = 5, .south = south_type::none, .west = west_type::none};
case 2398:
return {.east = east_type::up, .north = north_type::none, .power = 6, .south = south_type::up, .west = west_type::up};
case 2399:
return {.east = east_type::up, .north = north_type::none, .power = 6, .south = south_type::up, .west = west_type::side};
case 2400:
return {.east = east_type::up, .north = north_type::none, .power = 6, .south = south_type::up, .west = west_type::none};
case 2401:
return {.east = east_type::up, .north = north_type::none, .power = 6, .south = south_type::side, .west = west_type::up};
case 2402:
return {.east = east_type::up, .north = north_type::none, .power = 6, .south = south_type::side, .west = west_type::side};
case 2403:
return {.east = east_type::up, .north = north_type::none, .power = 6, .south = south_type::side, .west = west_type::none};
case 2404:
return {.east = east_type::up, .north = north_type::none, .power = 6, .south = south_type::none, .west = west_type::up};
case 2405:
return {.east = east_type::up, .north = north_type::none, .power = 6, .south = south_type::none, .west = west_type::side};
case 2406:
return {.east = east_type::up, .north = north_type::none, .power = 6, .south = south_type::none, .west = west_type::none};
case 2407:
return {.east = east_type::up, .north = north_type::none, .power = 7, .south = south_type::up, .west = west_type::up};
case 2408:
return {.east = east_type::up, .north = north_type::none, .power = 7, .south = south_type::up, .west = west_type::side};
case 2409:
return {.east = east_type::up, .north = north_type::none, .power = 7, .south = south_type::up, .west = west_type::none};
case 2410:
return {.east = east_type::up, .north = north_type::none, .power = 7, .south = south_type::side, .west = west_type::up};
case 2411:
return {.east = east_type::up, .north = north_type::none, .power = 7, .south = south_type::side, .west = west_type::side};
case 2412:
return {.east = east_type::up, .north = north_type::none, .power = 7, .south = south_type::side, .west = west_type::none};
case 2413:
return {.east = east_type::up, .north = north_type::none, .power = 7, .south = south_type::none, .west = west_type::up};
case 2414:
return {.east = east_type::up, .north = north_type::none, .power = 7, .south = south_type::none, .west = west_type::side};
case 2415:
return {.east = east_type::up, .north = north_type::none, .power = 7, .south = south_type::none, .west = west_type::none};
case 2416:
return {.east = east_type::up, .north = north_type::none, .power = 8, .south = south_type::up, .west = west_type::up};
case 2417:
return {.east = east_type::up, .north = north_type::none, .power = 8, .south = south_type::up, .west = west_type::side};
case 2418:
return {.east = east_type::up, .north = north_type::none, .power = 8, .south = south_type::up, .west = west_type::none};
case 2419:
return {.east = east_type::up, .north = north_type::none, .power = 8, .south = south_type::side, .west = west_type::up};
case 2420:
return {.east = east_type::up, .north = north_type::none, .power = 8, .south = south_type::side, .west = west_type::side};
case 2421:
return {.east = east_type::up, .north = north_type::none, .power = 8, .south = south_type::side, .west = west_type::none};
case 2422:
return {.east = east_type::up, .north = north_type::none, .power = 8, .south = south_type::none, .west = west_type::up};
case 2423:
return {.east = east_type::up, .north = north_type::none, .power = 8, .south = south_type::none, .west = west_type::side};
case 2424:
return {.east = east_type::up, .north = north_type::none, .power = 8, .south = south_type::none, .west = west_type::none};
case 2425:
return {.east = east_type::up, .north = north_type::none, .power = 9, .south = south_type::up, .west = west_type::up};
case 2426:
return {.east = east_type::up, .north = north_type::none, .power = 9, .south = south_type::up, .west = west_type::side};
case 2427:
return {.east = east_type::up, .north = north_type::none, .power = 9, .south = south_type::up, .west = west_type::none};
case 2428:
return {.east = east_type::up, .north = north_type::none, .power = 9, .south = south_type::side, .west = west_type::up};
case 2429:
return {.east = east_type::up, .north = north_type::none, .power = 9, .south = south_type::side, .west = west_type::side};
case 2430:
return {.east = east_type::up, .north = north_type::none, .power = 9, .south = south_type::side, .west = west_type::none};
case 2431:
return {.east = east_type::up, .north = north_type::none, .power = 9, .south = south_type::none, .west = west_type::up};
case 2432:
return {.east = east_type::up, .north = north_type::none, .power = 9, .south = south_type::none, .west = west_type::side};
case 2433:
return {.east = east_type::up, .north = north_type::none, .power = 9, .south = south_type::none, .west = west_type::none};
case 2434:
return {.east = east_type::up, .north = north_type::none, .power = 10, .south = south_type::up, .west = west_type::up};
case 2435:
return {.east = east_type::up, .north = north_type::none, .power = 10, .south = south_type::up, .west = west_type::side};
case 2436:
return {.east = east_type::up, .north = north_type::none, .power = 10, .south = south_type::up, .west = west_type::none};
case 2437:
return {.east = east_type::up, .north = north_type::none, .power = 10, .south = south_type::side, .west = west_type::up};
case 2438:
return {.east = east_type::up, .north = north_type::none, .power = 10, .south = south_type::side, .west = west_type::side};
case 2439:
return {.east = east_type::up, .north = north_type::none, .power = 10, .south = south_type::side, .west = west_type::none};
case 2440:
return {.east = east_type::up, .north = north_type::none, .power = 10, .south = south_type::none, .west = west_type::up};
case 2441:
return {.east = east_type::up, .north = north_type::none, .power = 10, .south = south_type::none, .west = west_type::side};
case 2442:
return {.east = east_type::up, .north = north_type::none, .power = 10, .south = south_type::none, .west = west_type::none};
case 2443:
return {.east = east_type::up, .north = north_type::none, .power = 11, .south = south_type::up, .west = west_type::up};
case 2444:
return {.east = east_type::up, .north = north_type::none, .power = 11, .south = south_type::up, .west = west_type::side};
case 2445:
return {.east = east_type::up, .north = north_type::none, .power = 11, .south = south_type::up, .west = west_type::none};
case 2446:
return {.east = east_type::up, .north = north_type::none, .power = 11, .south = south_type::side, .west = west_type::up};
case 2447:
return {.east = east_type::up, .north = north_type::none, .power = 11, .south = south_type::side, .west = west_type::side};
case 2448:
return {.east = east_type::up, .north = north_type::none, .power = 11, .south = south_type::side, .west = west_type::none};
case 2449:
return {.east = east_type::up, .north = north_type::none, .power = 11, .south = south_type::none, .west = west_type::up};
case 2450:
return {.east = east_type::up, .north = north_type::none, .power = 11, .south = south_type::none, .west = west_type::side};
case 2451:
return {.east = east_type::up, .north = north_type::none, .power = 11, .south = south_type::none, .west = west_type::none};
case 2452:
return {.east = east_type::up, .north = north_type::none, .power = 12, .south = south_type::up, .west = west_type::up};
case 2453:
return {.east = east_type::up, .north = north_type::none, .power = 12, .south = south_type::up, .west = west_type::side};
case 2454:
return {.east = east_type::up, .north = north_type::none, .power = 12, .south = south_type::up, .west = west_type::none};
case 2455:
return {.east = east_type::up, .north = north_type::none, .power = 12, .south = south_type::side, .west = west_type::up};
case 2456:
return {.east = east_type::up, .north = north_type::none, .power = 12, .south = south_type::side, .west = west_type::side};
case 2457:
return {.east = east_type::up, .north = north_type::none, .power = 12, .south = south_type::side, .west = west_type::none};
case 2458:
return {.east = east_type::up, .north = north_type::none, .power = 12, .south = south_type::none, .west = west_type::up};
case 2459:
return {.east = east_type::up, .north = north_type::none, .power = 12, .south = south_type::none, .west = west_type::side};
case 2460:
return {.east = east_type::up, .north = north_type::none, .power = 12, .south = south_type::none, .west = west_type::none};
case 2461:
return {.east = east_type::up, .north = north_type::none, .power = 13, .south = south_type::up, .west = west_type::up};
case 2462:
return {.east = east_type::up, .north = north_type::none, .power = 13, .south = south_type::up, .west = west_type::side};
case 2463:
return {.east = east_type::up, .north = north_type::none, .power = 13, .south = south_type::up, .west = west_type::none};
case 2464:
return {.east = east_type::up, .north = north_type::none, .power = 13, .south = south_type::side, .west = west_type::up};
case 2465:
return {.east = east_type::up, .north = north_type::none, .power = 13, .south = south_type::side, .west = west_type::side};
case 2466:
return {.east = east_type::up, .north = north_type::none, .power = 13, .south = south_type::side, .west = west_type::none};
case 2467:
return {.east = east_type::up, .north = north_type::none, .power = 13, .south = south_type::none, .west = west_type::up};
case 2468:
return {.east = east_type::up, .north = north_type::none, .power = 13, .south = south_type::none, .west = west_type::side};
case 2469:
return {.east = east_type::up, .north = north_type::none, .power = 13, .south = south_type::none, .west = west_type::none};
case 2470:
return {.east = east_type::up, .north = north_type::none, .power = 14, .south = south_type::up, .west = west_type::up};
case 2471:
return {.east = east_type::up, .north = north_type::none, .power = 14, .south = south_type::up, .west = west_type::side};
case 2472:
return {.east = east_type::up, .north = north_type::none, .power = 14, .south = south_type::up, .west = west_type::none};
case 2473:
return {.east = east_type::up, .north = north_type::none, .power = 14, .south = south_type::side, .west = west_type::up};
case 2474:
return {.east = east_type::up, .north = north_type::none, .power = 14, .south = south_type::side, .west = west_type::side};
case 2475:
return {.east = east_type::up, .north = north_type::none, .power = 14, .south = south_type::side, .west = west_type::none};
case 2476:
return {.east = east_type::up, .north = north_type::none, .power = 14, .south = south_type::none, .west = west_type::up};
case 2477:
return {.east = east_type::up, .north = north_type::none, .power = 14, .south = south_type::none, .west = west_type::side};
case 2478:
return {.east = east_type::up, .north = north_type::none, .power = 14, .south = south_type::none, .west = west_type::none};
case 2479:
return {.east = east_type::up, .north = north_type::none, .power = 15, .south = south_type::up, .west = west_type::up};
case 2480:
return {.east = east_type::up, .north = north_type::none, .power = 15, .south = south_type::up, .west = west_type::side};
case 2481:
return {.east = east_type::up, .north = north_type::none, .power = 15, .south = south_type::up, .west = west_type::none};
case 2482:
return {.east = east_type::up, .north = north_type::none, .power = 15, .south = south_type::side, .west = west_type::up};
case 2483:
return {.east = east_type::up, .north = north_type::none, .power = 15, .south = south_type::side, .west = west_type::side};
case 2484:
return {.east = east_type::up, .north = north_type::none, .power = 15, .south = south_type::side, .west = west_type::none};
case 2485:
return {.east = east_type::up, .north = north_type::none, .power = 15, .south = south_type::none, .west = west_type::up};
case 2486:
return {.east = east_type::up, .north = north_type::none, .power = 15, .south = south_type::none, .west = west_type::side};
case 2487:
return {.east = east_type::up, .north = north_type::none, .power = 15, .south = south_type::none, .west = west_type::none};
case 2488:
return {.east = east_type::side, .north = north_type::up, .power = 0, .south = south_type::up, .west = west_type::up};
case 2489:
return {.east = east_type::side, .north = north_type::up, .power = 0, .south = south_type::up, .west = west_type::side};
case 2490:
return {.east = east_type::side, .north = north_type::up, .power = 0, .south = south_type::up, .west = west_type::none};
case 2491:
return {.east = east_type::side, .north = north_type::up, .power = 0, .south = south_type::side, .west = west_type::up};
case 2492:
return {.east = east_type::side, .north = north_type::up, .power = 0, .south = south_type::side, .west = west_type::side};
case 2493:
return {.east = east_type::side, .north = north_type::up, .power = 0, .south = south_type::side, .west = west_type::none};
case 2494:
return {.east = east_type::side, .north = north_type::up, .power = 0, .south = south_type::none, .west = west_type::up};
case 2495:
return {.east = east_type::side, .north = north_type::up, .power = 0, .south = south_type::none, .west = west_type::side};
case 2496:
return {.east = east_type::side, .north = north_type::up, .power = 0, .south = south_type::none, .west = west_type::none};
case 2497:
return {.east = east_type::side, .north = north_type::up, .power = 1, .south = south_type::up, .west = west_type::up};
case 2498:
return {.east = east_type::side, .north = north_type::up, .power = 1, .south = south_type::up, .west = west_type::side};
case 2499:
return {.east = east_type::side, .north = north_type::up, .power = 1, .south = south_type::up, .west = west_type::none};
case 2500:
return {.east = east_type::side, .north = north_type::up, .power = 1, .south = south_type::side, .west = west_type::up};
case 2501:
return {.east = east_type::side, .north = north_type::up, .power = 1, .south = south_type::side, .west = west_type::side};
case 2502:
return {.east = east_type::side, .north = north_type::up, .power = 1, .south = south_type::side, .west = west_type::none};
case 2503:
return {.east = east_type::side, .north = north_type::up, .power = 1, .south = south_type::none, .west = west_type::up};
case 2504:
return {.east = east_type::side, .north = north_type::up, .power = 1, .south = south_type::none, .west = west_type::side};
case 2505:
return {.east = east_type::side, .north = north_type::up, .power = 1, .south = south_type::none, .west = west_type::none};
case 2506:
return {.east = east_type::side, .north = north_type::up, .power = 2, .south = south_type::up, .west = west_type::up};
case 2507:
return {.east = east_type::side, .north = north_type::up, .power = 2, .south = south_type::up, .west = west_type::side};
case 2508:
return {.east = east_type::side, .north = north_type::up, .power = 2, .south = south_type::up, .west = west_type::none};
case 2509:
return {.east = east_type::side, .north = north_type::up, .power = 2, .south = south_type::side, .west = west_type::up};
case 2510:
return {.east = east_type::side, .north = north_type::up, .power = 2, .south = south_type::side, .west = west_type::side};
case 2511:
return {.east = east_type::side, .north = north_type::up, .power = 2, .south = south_type::side, .west = west_type::none};
case 2512:
return {.east = east_type::side, .north = north_type::up, .power = 2, .south = south_type::none, .west = west_type::up};
case 2513:
return {.east = east_type::side, .north = north_type::up, .power = 2, .south = south_type::none, .west = west_type::side};
case 2514:
return {.east = east_type::side, .north = north_type::up, .power = 2, .south = south_type::none, .west = west_type::none};
case 2515:
return {.east = east_type::side, .north = north_type::up, .power = 3, .south = south_type::up, .west = west_type::up};
case 2516:
return {.east = east_type::side, .north = north_type::up, .power = 3, .south = south_type::up, .west = west_type::side};
case 2517:
return {.east = east_type::side, .north = north_type::up, .power = 3, .south = south_type::up, .west = west_type::none};
case 2518:
return {.east = east_type::side, .north = north_type::up, .power = 3, .south = south_type::side, .west = west_type::up};
case 2519:
return {.east = east_type::side, .north = north_type::up, .power = 3, .south = south_type::side, .west = west_type::side};
case 2520:
return {.east = east_type::side, .north = north_type::up, .power = 3, .south = south_type::side, .west = west_type::none};
case 2521:
return {.east = east_type::side, .north = north_type::up, .power = 3, .south = south_type::none, .west = west_type::up};
case 2522:
return {.east = east_type::side, .north = north_type::up, .power = 3, .south = south_type::none, .west = west_type::side};
case 2523:
return {.east = east_type::side, .north = north_type::up, .power = 3, .south = south_type::none, .west = west_type::none};
case 2524:
return {.east = east_type::side, .north = north_type::up, .power = 4, .south = south_type::up, .west = west_type::up};
case 2525:
return {.east = east_type::side, .north = north_type::up, .power = 4, .south = south_type::up, .west = west_type::side};
case 2526:
return {.east = east_type::side, .north = north_type::up, .power = 4, .south = south_type::up, .west = west_type::none};
case 2527:
return {.east = east_type::side, .north = north_type::up, .power = 4, .south = south_type::side, .west = west_type::up};
case 2528:
return {.east = east_type::side, .north = north_type::up, .power = 4, .south = south_type::side, .west = west_type::side};
case 2529:
return {.east = east_type::side, .north = north_type::up, .power = 4, .south = south_type::side, .west = west_type::none};
case 2530:
return {.east = east_type::side, .north = north_type::up, .power = 4, .south = south_type::none, .west = west_type::up};
case 2531:
return {.east = east_type::side, .north = north_type::up, .power = 4, .south = south_type::none, .west = west_type::side};
case 2532:
return {.east = east_type::side, .north = north_type::up, .power = 4, .south = south_type::none, .west = west_type::none};
case 2533:
return {.east = east_type::side, .north = north_type::up, .power = 5, .south = south_type::up, .west = west_type::up};
case 2534:
return {.east = east_type::side, .north = north_type::up, .power = 5, .south = south_type::up, .west = west_type::side};
case 2535:
return {.east = east_type::side, .north = north_type::up, .power = 5, .south = south_type::up, .west = west_type::none};
case 2536:
return {.east = east_type::side, .north = north_type::up, .power = 5, .south = south_type::side, .west = west_type::up};
case 2537:
return {.east = east_type::side, .north = north_type::up, .power = 5, .south = south_type::side, .west = west_type::side};
case 2538:
return {.east = east_type::side, .north = north_type::up, .power = 5, .south = south_type::side, .west = west_type::none};
case 2539:
return {.east = east_type::side, .north = north_type::up, .power = 5, .south = south_type::none, .west = west_type::up};
case 2540:
return {.east = east_type::side, .north = north_type::up, .power = 5, .south = south_type::none, .west = west_type::side};
case 2541:
return {.east = east_type::side, .north = north_type::up, .power = 5, .south = south_type::none, .west = west_type::none};
case 2542:
return {.east = east_type::side, .north = north_type::up, .power = 6, .south = south_type::up, .west = west_type::up};
case 2543:
return {.east = east_type::side, .north = north_type::up, .power = 6, .south = south_type::up, .west = west_type::side};
case 2544:
return {.east = east_type::side, .north = north_type::up, .power = 6, .south = south_type::up, .west = west_type::none};
case 2545:
return {.east = east_type::side, .north = north_type::up, .power = 6, .south = south_type::side, .west = west_type::up};
case 2546:
return {.east = east_type::side, .north = north_type::up, .power = 6, .south = south_type::side, .west = west_type::side};
case 2547:
return {.east = east_type::side, .north = north_type::up, .power = 6, .south = south_type::side, .west = west_type::none};
case 2548:
return {.east = east_type::side, .north = north_type::up, .power = 6, .south = south_type::none, .west = west_type::up};
case 2549:
return {.east = east_type::side, .north = north_type::up, .power = 6, .south = south_type::none, .west = west_type::side};
case 2550:
return {.east = east_type::side, .north = north_type::up, .power = 6, .south = south_type::none, .west = west_type::none};
case 2551:
return {.east = east_type::side, .north = north_type::up, .power = 7, .south = south_type::up, .west = west_type::up};
case 2552:
return {.east = east_type::side, .north = north_type::up, .power = 7, .south = south_type::up, .west = west_type::side};
case 2553:
return {.east = east_type::side, .north = north_type::up, .power = 7, .south = south_type::up, .west = west_type::none};
case 2554:
return {.east = east_type::side, .north = north_type::up, .power = 7, .south = south_type::side, .west = west_type::up};
case 2555:
return {.east = east_type::side, .north = north_type::up, .power = 7, .south = south_type::side, .west = west_type::side};
case 2556:
return {.east = east_type::side, .north = north_type::up, .power = 7, .south = south_type::side, .west = west_type::none};
case 2557:
return {.east = east_type::side, .north = north_type::up, .power = 7, .south = south_type::none, .west = west_type::up};
case 2558:
return {.east = east_type::side, .north = north_type::up, .power = 7, .south = south_type::none, .west = west_type::side};
case 2559:
return {.east = east_type::side, .north = north_type::up, .power = 7, .south = south_type::none, .west = west_type::none};
case 2560:
return {.east = east_type::side, .north = north_type::up, .power = 8, .south = south_type::up, .west = west_type::up};
case 2561:
return {.east = east_type::side, .north = north_type::up, .power = 8, .south = south_type::up, .west = west_type::side};
case 2562:
return {.east = east_type::side, .north = north_type::up, .power = 8, .south = south_type::up, .west = west_type::none};
case 2563:
return {.east = east_type::side, .north = north_type::up, .power = 8, .south = south_type::side, .west = west_type::up};
case 2564:
return {.east = east_type::side, .north = north_type::up, .power = 8, .south = south_type::side, .west = west_type::side};
case 2565:
return {.east = east_type::side, .north = north_type::up, .power = 8, .south = south_type::side, .west = west_type::none};
case 2566:
return {.east = east_type::side, .north = north_type::up, .power = 8, .south = south_type::none, .west = west_type::up};
case 2567:
return {.east = east_type::side, .north = north_type::up, .power = 8, .south = south_type::none, .west = west_type::side};
case 2568:
return {.east = east_type::side, .north = north_type::up, .power = 8, .south = south_type::none, .west = west_type::none};
case 2569:
return {.east = east_type::side, .north = north_type::up, .power = 9, .south = south_type::up, .west = west_type::up};
case 2570:
return {.east = east_type::side, .north = north_type::up, .power = 9, .south = south_type::up, .west = west_type::side};
case 2571:
return {.east = east_type::side, .north = north_type::up, .power = 9, .south = south_type::up, .west = west_type::none};
case 2572:
return {.east = east_type::side, .north = north_type::up, .power = 9, .south = south_type::side, .west = west_type::up};
case 2573:
return {.east = east_type::side, .north = north_type::up, .power = 9, .south = south_type::side, .west = west_type::side};
case 2574:
return {.east = east_type::side, .north = north_type::up, .power = 9, .south = south_type::side, .west = west_type::none};
case 2575:
return {.east = east_type::side, .north = north_type::up, .power = 9, .south = south_type::none, .west = west_type::up};
case 2576:
return {.east = east_type::side, .north = north_type::up, .power = 9, .south = south_type::none, .west = west_type::side};
case 2577:
return {.east = east_type::side, .north = north_type::up, .power = 9, .south = south_type::none, .west = west_type::none};
case 2578:
return {.east = east_type::side, .north = north_type::up, .power = 10, .south = south_type::up, .west = west_type::up};
case 2579:
return {.east = east_type::side, .north = north_type::up, .power = 10, .south = south_type::up, .west = west_type::side};
case 2580:
return {.east = east_type::side, .north = north_type::up, .power = 10, .south = south_type::up, .west = west_type::none};
case 2581:
return {.east = east_type::side, .north = north_type::up, .power = 10, .south = south_type::side, .west = west_type::up};
case 2582:
return {.east = east_type::side, .north = north_type::up, .power = 10, .south = south_type::side, .west = west_type::side};
case 2583:
return {.east = east_type::side, .north = north_type::up, .power = 10, .south = south_type::side, .west = west_type::none};
case 2584:
return {.east = east_type::side, .north = north_type::up, .power = 10, .south = south_type::none, .west = west_type::up};
case 2585:
return {.east = east_type::side, .north = north_type::up, .power = 10, .south = south_type::none, .west = west_type::side};
case 2586:
return {.east = east_type::side, .north = north_type::up, .power = 10, .south = south_type::none, .west = west_type::none};
case 2587:
return {.east = east_type::side, .north = north_type::up, .power = 11, .south = south_type::up, .west = west_type::up};
case 2588:
return {.east = east_type::side, .north = north_type::up, .power = 11, .south = south_type::up, .west = west_type::side};
case 2589:
return {.east = east_type::side, .north = north_type::up, .power = 11, .south = south_type::up, .west = west_type::none};
case 2590:
return {.east = east_type::side, .north = north_type::up, .power = 11, .south = south_type::side, .west = west_type::up};
case 2591:
return {.east = east_type::side, .north = north_type::up, .power = 11, .south = south_type::side, .west = west_type::side};
case 2592:
return {.east = east_type::side, .north = north_type::up, .power = 11, .south = south_type::side, .west = west_type::none};
case 2593:
return {.east = east_type::side, .north = north_type::up, .power = 11, .south = south_type::none, .west = west_type::up};
case 2594:
return {.east = east_type::side, .north = north_type::up, .power = 11, .south = south_type::none, .west = west_type::side};
case 2595:
return {.east = east_type::side, .north = north_type::up, .power = 11, .south = south_type::none, .west = west_type::none};
case 2596:
return {.east = east_type::side, .north = north_type::up, .power = 12, .south = south_type::up, .west = west_type::up};
case 2597:
return {.east = east_type::side, .north = north_type::up, .power = 12, .south = south_type::up, .west = west_type::side};
case 2598:
return {.east = east_type::side, .north = north_type::up, .power = 12, .south = south_type::up, .west = west_type::none};
case 2599:
return {.east = east_type::side, .north = north_type::up, .power = 12, .south = south_type::side, .west = west_type::up};
case 2600:
return {.east = east_type::side, .north = north_type::up, .power = 12, .south = south_type::side, .west = west_type::side};
case 2601:
return {.east = east_type::side, .north = north_type::up, .power = 12, .south = south_type::side, .west = west_type::none};
case 2602:
return {.east = east_type::side, .north = north_type::up, .power = 12, .south = south_type::none, .west = west_type::up};
case 2603:
return {.east = east_type::side, .north = north_type::up, .power = 12, .south = south_type::none, .west = west_type::side};
case 2604:
return {.east = east_type::side, .north = north_type::up, .power = 12, .south = south_type::none, .west = west_type::none};
case 2605:
return {.east = east_type::side, .north = north_type::up, .power = 13, .south = south_type::up, .west = west_type::up};
case 2606:
return {.east = east_type::side, .north = north_type::up, .power = 13, .south = south_type::up, .west = west_type::side};
case 2607:
return {.east = east_type::side, .north = north_type::up, .power = 13, .south = south_type::up, .west = west_type::none};
case 2608:
return {.east = east_type::side, .north = north_type::up, .power = 13, .south = south_type::side, .west = west_type::up};
case 2609:
return {.east = east_type::side, .north = north_type::up, .power = 13, .south = south_type::side, .west = west_type::side};
case 2610:
return {.east = east_type::side, .north = north_type::up, .power = 13, .south = south_type::side, .west = west_type::none};
case 2611:
return {.east = east_type::side, .north = north_type::up, .power = 13, .south = south_type::none, .west = west_type::up};
case 2612:
return {.east = east_type::side, .north = north_type::up, .power = 13, .south = south_type::none, .west = west_type::side};
case 2613:
return {.east = east_type::side, .north = north_type::up, .power = 13, .south = south_type::none, .west = west_type::none};
case 2614:
return {.east = east_type::side, .north = north_type::up, .power = 14, .south = south_type::up, .west = west_type::up};
case 2615:
return {.east = east_type::side, .north = north_type::up, .power = 14, .south = south_type::up, .west = west_type::side};
case 2616:
return {.east = east_type::side, .north = north_type::up, .power = 14, .south = south_type::up, .west = west_type::none};
case 2617:
return {.east = east_type::side, .north = north_type::up, .power = 14, .south = south_type::side, .west = west_type::up};
case 2618:
return {.east = east_type::side, .north = north_type::up, .power = 14, .south = south_type::side, .west = west_type::side};
case 2619:
return {.east = east_type::side, .north = north_type::up, .power = 14, .south = south_type::side, .west = west_type::none};
case 2620:
return {.east = east_type::side, .north = north_type::up, .power = 14, .south = south_type::none, .west = west_type::up};
case 2621:
return {.east = east_type::side, .north = north_type::up, .power = 14, .south = south_type::none, .west = west_type::side};
case 2622:
return {.east = east_type::side, .north = north_type::up, .power = 14, .south = south_type::none, .west = west_type::none};
case 2623:
return {.east = east_type::side, .north = north_type::up, .power = 15, .south = south_type::up, .west = west_type::up};
case 2624:
return {.east = east_type::side, .north = north_type::up, .power = 15, .south = south_type::up, .west = west_type::side};
case 2625:
return {.east = east_type::side, .north = north_type::up, .power = 15, .south = south_type::up, .west = west_type::none};
case 2626:
return {.east = east_type::side, .north = north_type::up, .power = 15, .south = south_type::side, .west = west_type::up};
case 2627:
return {.east = east_type::side, .north = north_type::up, .power = 15, .south = south_type::side, .west = west_type::side};
case 2628:
return {.east = east_type::side, .north = north_type::up, .power = 15, .south = south_type::side, .west = west_type::none};
case 2629:
return {.east = east_type::side, .north = north_type::up, .power = 15, .south = south_type::none, .west = west_type::up};
case 2630:
return {.east = east_type::side, .north = north_type::up, .power = 15, .south = south_type::none, .west = west_type::side};
case 2631:
return {.east = east_type::side, .north = north_type::up, .power = 15, .south = south_type::none, .west = west_type::none};
case 2632:
return {.east = east_type::side, .north = north_type::side, .power = 0, .south = south_type::up, .west = west_type::up};
case 2633:
return {.east = east_type::side, .north = north_type::side, .power = 0, .south = south_type::up, .west = west_type::side};
case 2634:
return {.east = east_type::side, .north = north_type::side, .power = 0, .south = south_type::up, .west = west_type::none};
case 2635:
return {.east = east_type::side, .north = north_type::side, .power = 0, .south = south_type::side, .west = west_type::up};
case 2636:
return {.east = east_type::side, .north = north_type::side, .power = 0, .south = south_type::side, .west = west_type::side};
case 2637:
return {.east = east_type::side, .north = north_type::side, .power = 0, .south = south_type::side, .west = west_type::none};
case 2638:
return {.east = east_type::side, .north = north_type::side, .power = 0, .south = south_type::none, .west = west_type::up};
case 2639:
return {.east = east_type::side, .north = north_type::side, .power = 0, .south = south_type::none, .west = west_type::side};
case 2640:
return {.east = east_type::side, .north = north_type::side, .power = 0, .south = south_type::none, .west = west_type::none};
case 2641:
return {.east = east_type::side, .north = north_type::side, .power = 1, .south = south_type::up, .west = west_type::up};
case 2642:
return {.east = east_type::side, .north = north_type::side, .power = 1, .south = south_type::up, .west = west_type::side};
case 2643:
return {.east = east_type::side, .north = north_type::side, .power = 1, .south = south_type::up, .west = west_type::none};
case 2644:
return {.east = east_type::side, .north = north_type::side, .power = 1, .south = south_type::side, .west = west_type::up};
case 2645:
return {.east = east_type::side, .north = north_type::side, .power = 1, .south = south_type::side, .west = west_type::side};
case 2646:
return {.east = east_type::side, .north = north_type::side, .power = 1, .south = south_type::side, .west = west_type::none};
case 2647:
return {.east = east_type::side, .north = north_type::side, .power = 1, .south = south_type::none, .west = west_type::up};
case 2648:
return {.east = east_type::side, .north = north_type::side, .power = 1, .south = south_type::none, .west = west_type::side};
case 2649:
return {.east = east_type::side, .north = north_type::side, .power = 1, .south = south_type::none, .west = west_type::none};
case 2650:
return {.east = east_type::side, .north = north_type::side, .power = 2, .south = south_type::up, .west = west_type::up};
case 2651:
return {.east = east_type::side, .north = north_type::side, .power = 2, .south = south_type::up, .west = west_type::side};
case 2652:
return {.east = east_type::side, .north = north_type::side, .power = 2, .south = south_type::up, .west = west_type::none};
case 2653:
return {.east = east_type::side, .north = north_type::side, .power = 2, .south = south_type::side, .west = west_type::up};
case 2654:
return {.east = east_type::side, .north = north_type::side, .power = 2, .south = south_type::side, .west = west_type::side};
case 2655:
return {.east = east_type::side, .north = north_type::side, .power = 2, .south = south_type::side, .west = west_type::none};
case 2656:
return {.east = east_type::side, .north = north_type::side, .power = 2, .south = south_type::none, .west = west_type::up};
case 2657:
return {.east = east_type::side, .north = north_type::side, .power = 2, .south = south_type::none, .west = west_type::side};
case 2658:
return {.east = east_type::side, .north = north_type::side, .power = 2, .south = south_type::none, .west = west_type::none};
case 2659:
return {.east = east_type::side, .north = north_type::side, .power = 3, .south = south_type::up, .west = west_type::up};
case 2660:
return {.east = east_type::side, .north = north_type::side, .power = 3, .south = south_type::up, .west = west_type::side};
case 2661:
return {.east = east_type::side, .north = north_type::side, .power = 3, .south = south_type::up, .west = west_type::none};
case 2662:
return {.east = east_type::side, .north = north_type::side, .power = 3, .south = south_type::side, .west = west_type::up};
case 2663:
return {.east = east_type::side, .north = north_type::side, .power = 3, .south = south_type::side, .west = west_type::side};
case 2664:
return {.east = east_type::side, .north = north_type::side, .power = 3, .south = south_type::side, .west = west_type::none};
case 2665:
return {.east = east_type::side, .north = north_type::side, .power = 3, .south = south_type::none, .west = west_type::up};
case 2666:
return {.east = east_type::side, .north = north_type::side, .power = 3, .south = south_type::none, .west = west_type::side};
case 2667:
return {.east = east_type::side, .north = north_type::side, .power = 3, .south = south_type::none, .west = west_type::none};
case 2668:
return {.east = east_type::side, .north = north_type::side, .power = 4, .south = south_type::up, .west = west_type::up};
case 2669:
return {.east = east_type::side, .north = north_type::side, .power = 4, .south = south_type::up, .west = west_type::side};
case 2670:
return {.east = east_type::side, .north = north_type::side, .power = 4, .south = south_type::up, .west = west_type::none};
case 2671:
return {.east = east_type::side, .north = north_type::side, .power = 4, .south = south_type::side, .west = west_type::up};
case 2672:
return {.east = east_type::side, .north = north_type::side, .power = 4, .south = south_type::side, .west = west_type::side};
case 2673:
return {.east = east_type::side, .north = north_type::side, .power = 4, .south = south_type::side, .west = west_type::none};
case 2674:
return {.east = east_type::side, .north = north_type::side, .power = 4, .south = south_type::none, .west = west_type::up};
case 2675:
return {.east = east_type::side, .north = north_type::side, .power = 4, .south = south_type::none, .west = west_type::side};
case 2676:
return {.east = east_type::side, .north = north_type::side, .power = 4, .south = south_type::none, .west = west_type::none};
case 2677:
return {.east = east_type::side, .north = north_type::side, .power = 5, .south = south_type::up, .west = west_type::up};
case 2678:
return {.east = east_type::side, .north = north_type::side, .power = 5, .south = south_type::up, .west = west_type::side};
case 2679:
return {.east = east_type::side, .north = north_type::side, .power = 5, .south = south_type::up, .west = west_type::none};
case 2680:
return {.east = east_type::side, .north = north_type::side, .power = 5, .south = south_type::side, .west = west_type::up};
case 2681:
return {.east = east_type::side, .north = north_type::side, .power = 5, .south = south_type::side, .west = west_type::side};
case 2682:
return {.east = east_type::side, .north = north_type::side, .power = 5, .south = south_type::side, .west = west_type::none};
case 2683:
return {.east = east_type::side, .north = north_type::side, .power = 5, .south = south_type::none, .west = west_type::up};
case 2684:
return {.east = east_type::side, .north = north_type::side, .power = 5, .south = south_type::none, .west = west_type::side};
case 2685:
return {.east = east_type::side, .north = north_type::side, .power = 5, .south = south_type::none, .west = west_type::none};
case 2686:
return {.east = east_type::side, .north = north_type::side, .power = 6, .south = south_type::up, .west = west_type::up};
case 2687:
return {.east = east_type::side, .north = north_type::side, .power = 6, .south = south_type::up, .west = west_type::side};
case 2688:
return {.east = east_type::side, .north = north_type::side, .power = 6, .south = south_type::up, .west = west_type::none};
case 2689:
return {.east = east_type::side, .north = north_type::side, .power = 6, .south = south_type::side, .west = west_type::up};
case 2690:
return {.east = east_type::side, .north = north_type::side, .power = 6, .south = south_type::side, .west = west_type::side};
case 2691:
return {.east = east_type::side, .north = north_type::side, .power = 6, .south = south_type::side, .west = west_type::none};
case 2692:
return {.east = east_type::side, .north = north_type::side, .power = 6, .south = south_type::none, .west = west_type::up};
case 2693:
return {.east = east_type::side, .north = north_type::side, .power = 6, .south = south_type::none, .west = west_type::side};
case 2694:
return {.east = east_type::side, .north = north_type::side, .power = 6, .south = south_type::none, .west = west_type::none};
case 2695:
return {.east = east_type::side, .north = north_type::side, .power = 7, .south = south_type::up, .west = west_type::up};
case 2696:
return {.east = east_type::side, .north = north_type::side, .power = 7, .south = south_type::up, .west = west_type::side};
case 2697:
return {.east = east_type::side, .north = north_type::side, .power = 7, .south = south_type::up, .west = west_type::none};
case 2698:
return {.east = east_type::side, .north = north_type::side, .power = 7, .south = south_type::side, .west = west_type::up};
case 2699:
return {.east = east_type::side, .north = north_type::side, .power = 7, .south = south_type::side, .west = west_type::side};
case 2700:
return {.east = east_type::side, .north = north_type::side, .power = 7, .south = south_type::side, .west = west_type::none};
case 2701:
return {.east = east_type::side, .north = north_type::side, .power = 7, .south = south_type::none, .west = west_type::up};
case 2702:
return {.east = east_type::side, .north = north_type::side, .power = 7, .south = south_type::none, .west = west_type::side};
case 2703:
return {.east = east_type::side, .north = north_type::side, .power = 7, .south = south_type::none, .west = west_type::none};
case 2704:
return {.east = east_type::side, .north = north_type::side, .power = 8, .south = south_type::up, .west = west_type::up};
case 2705:
return {.east = east_type::side, .north = north_type::side, .power = 8, .south = south_type::up, .west = west_type::side};
case 2706:
return {.east = east_type::side, .north = north_type::side, .power = 8, .south = south_type::up, .west = west_type::none};
case 2707:
return {.east = east_type::side, .north = north_type::side, .power = 8, .south = south_type::side, .west = west_type::up};
case 2708:
return {.east = east_type::side, .north = north_type::side, .power = 8, .south = south_type::side, .west = west_type::side};
case 2709:
return {.east = east_type::side, .north = north_type::side, .power = 8, .south = south_type::side, .west = west_type::none};
case 2710:
return {.east = east_type::side, .north = north_type::side, .power = 8, .south = south_type::none, .west = west_type::up};
case 2711:
return {.east = east_type::side, .north = north_type::side, .power = 8, .south = south_type::none, .west = west_type::side};
case 2712:
return {.east = east_type::side, .north = north_type::side, .power = 8, .south = south_type::none, .west = west_type::none};
case 2713:
return {.east = east_type::side, .north = north_type::side, .power = 9, .south = south_type::up, .west = west_type::up};
case 2714:
return {.east = east_type::side, .north = north_type::side, .power = 9, .south = south_type::up, .west = west_type::side};
case 2715:
return {.east = east_type::side, .north = north_type::side, .power = 9, .south = south_type::up, .west = west_type::none};
case 2716:
return {.east = east_type::side, .north = north_type::side, .power = 9, .south = south_type::side, .west = west_type::up};
case 2717:
return {.east = east_type::side, .north = north_type::side, .power = 9, .south = south_type::side, .west = west_type::side};
case 2718:
return {.east = east_type::side, .north = north_type::side, .power = 9, .south = south_type::side, .west = west_type::none};
case 2719:
return {.east = east_type::side, .north = north_type::side, .power = 9, .south = south_type::none, .west = west_type::up};
case 2720:
return {.east = east_type::side, .north = north_type::side, .power = 9, .south = south_type::none, .west = west_type::side};
case 2721:
return {.east = east_type::side, .north = north_type::side, .power = 9, .south = south_type::none, .west = west_type::none};
case 2722:
return {.east = east_type::side, .north = north_type::side, .power = 10, .south = south_type::up, .west = west_type::up};
case 2723:
return {.east = east_type::side, .north = north_type::side, .power = 10, .south = south_type::up, .west = west_type::side};
case 2724:
return {.east = east_type::side, .north = north_type::side, .power = 10, .south = south_type::up, .west = west_type::none};
case 2725:
return {.east = east_type::side, .north = north_type::side, .power = 10, .south = south_type::side, .west = west_type::up};
case 2726:
return {.east = east_type::side, .north = north_type::side, .power = 10, .south = south_type::side, .west = west_type::side};
case 2727:
return {.east = east_type::side, .north = north_type::side, .power = 10, .south = south_type::side, .west = west_type::none};
case 2728:
return {.east = east_type::side, .north = north_type::side, .power = 10, .south = south_type::none, .west = west_type::up};
case 2729:
return {.east = east_type::side, .north = north_type::side, .power = 10, .south = south_type::none, .west = west_type::side};
case 2730:
return {.east = east_type::side, .north = north_type::side, .power = 10, .south = south_type::none, .west = west_type::none};
case 2731:
return {.east = east_type::side, .north = north_type::side, .power = 11, .south = south_type::up, .west = west_type::up};
case 2732:
return {.east = east_type::side, .north = north_type::side, .power = 11, .south = south_type::up, .west = west_type::side};
case 2733:
return {.east = east_type::side, .north = north_type::side, .power = 11, .south = south_type::up, .west = west_type::none};
case 2734:
return {.east = east_type::side, .north = north_type::side, .power = 11, .south = south_type::side, .west = west_type::up};
case 2735:
return {.east = east_type::side, .north = north_type::side, .power = 11, .south = south_type::side, .west = west_type::side};
case 2736:
return {.east = east_type::side, .north = north_type::side, .power = 11, .south = south_type::side, .west = west_type::none};
case 2737:
return {.east = east_type::side, .north = north_type::side, .power = 11, .south = south_type::none, .west = west_type::up};
case 2738:
return {.east = east_type::side, .north = north_type::side, .power = 11, .south = south_type::none, .west = west_type::side};
case 2739:
return {.east = east_type::side, .north = north_type::side, .power = 11, .south = south_type::none, .west = west_type::none};
case 2740:
return {.east = east_type::side, .north = north_type::side, .power = 12, .south = south_type::up, .west = west_type::up};
case 2741:
return {.east = east_type::side, .north = north_type::side, .power = 12, .south = south_type::up, .west = west_type::side};
case 2742:
return {.east = east_type::side, .north = north_type::side, .power = 12, .south = south_type::up, .west = west_type::none};
case 2743:
return {.east = east_type::side, .north = north_type::side, .power = 12, .south = south_type::side, .west = west_type::up};
case 2744:
return {.east = east_type::side, .north = north_type::side, .power = 12, .south = south_type::side, .west = west_type::side};
case 2745:
return {.east = east_type::side, .north = north_type::side, .power = 12, .south = south_type::side, .west = west_type::none};
case 2746:
return {.east = east_type::side, .north = north_type::side, .power = 12, .south = south_type::none, .west = west_type::up};
case 2747:
return {.east = east_type::side, .north = north_type::side, .power = 12, .south = south_type::none, .west = west_type::side};
case 2748:
return {.east = east_type::side, .north = north_type::side, .power = 12, .south = south_type::none, .west = west_type::none};
case 2749:
return {.east = east_type::side, .north = north_type::side, .power = 13, .south = south_type::up, .west = west_type::up};
case 2750:
return {.east = east_type::side, .north = north_type::side, .power = 13, .south = south_type::up, .west = west_type::side};
case 2751:
return {.east = east_type::side, .north = north_type::side, .power = 13, .south = south_type::up, .west = west_type::none};
case 2752:
return {.east = east_type::side, .north = north_type::side, .power = 13, .south = south_type::side, .west = west_type::up};
case 2753:
return {.east = east_type::side, .north = north_type::side, .power = 13, .south = south_type::side, .west = west_type::side};
case 2754:
return {.east = east_type::side, .north = north_type::side, .power = 13, .south = south_type::side, .west = west_type::none};
case 2755:
return {.east = east_type::side, .north = north_type::side, .power = 13, .south = south_type::none, .west = west_type::up};
case 2756:
return {.east = east_type::side, .north = north_type::side, .power = 13, .south = south_type::none, .west = west_type::side};
case 2757:
return {.east = east_type::side, .north = north_type::side, .power = 13, .south = south_type::none, .west = west_type::none};
case 2758:
return {.east = east_type::side, .north = north_type::side, .power = 14, .south = south_type::up, .west = west_type::up};
case 2759:
return {.east = east_type::side, .north = north_type::side, .power = 14, .south = south_type::up, .west = west_type::side};
case 2760:
return {.east = east_type::side, .north = north_type::side, .power = 14, .south = south_type::up, .west = west_type::none};
case 2761:
return {.east = east_type::side, .north = north_type::side, .power = 14, .south = south_type::side, .west = west_type::up};
case 2762:
return {.east = east_type::side, .north = north_type::side, .power = 14, .south = south_type::side, .west = west_type::side};
case 2763:
return {.east = east_type::side, .north = north_type::side, .power = 14, .south = south_type::side, .west = west_type::none};
case 2764:
return {.east = east_type::side, .north = north_type::side, .power = 14, .south = south_type::none, .west = west_type::up};
case 2765:
return {.east = east_type::side, .north = north_type::side, .power = 14, .south = south_type::none, .west = west_type::side};
case 2766:
return {.east = east_type::side, .north = north_type::side, .power = 14, .south = south_type::none, .west = west_type::none};
case 2767:
return {.east = east_type::side, .north = north_type::side, .power = 15, .south = south_type::up, .west = west_type::up};
case 2768:
return {.east = east_type::side, .north = north_type::side, .power = 15, .south = south_type::up, .west = west_type::side};
case 2769:
return {.east = east_type::side, .north = north_type::side, .power = 15, .south = south_type::up, .west = west_type::none};
case 2770:
return {.east = east_type::side, .north = north_type::side, .power = 15, .south = south_type::side, .west = west_type::up};
case 2771:
return {.east = east_type::side, .north = north_type::side, .power = 15, .south = south_type::side, .west = west_type::side};
case 2772:
return {.east = east_type::side, .north = north_type::side, .power = 15, .south = south_type::side, .west = west_type::none};
case 2773:
return {.east = east_type::side, .north = north_type::side, .power = 15, .south = south_type::none, .west = west_type::up};
case 2774:
return {.east = east_type::side, .north = north_type::side, .power = 15, .south = south_type::none, .west = west_type::side};
case 2775:
return {.east = east_type::side, .north = north_type::side, .power = 15, .south = south_type::none, .west = west_type::none};
case 2776:
return {.east = east_type::side, .north = north_type::none, .power = 0, .south = south_type::up, .west = west_type::up};
case 2777:
return {.east = east_type::side, .north = north_type::none, .power = 0, .south = south_type::up, .west = west_type::side};
case 2778:
return {.east = east_type::side, .north = north_type::none, .power = 0, .south = south_type::up, .west = west_type::none};
case 2779:
return {.east = east_type::side, .north = north_type::none, .power = 0, .south = south_type::side, .west = west_type::up};
case 2780:
return {.east = east_type::side, .north = north_type::none, .power = 0, .south = south_type::side, .west = west_type::side};
case 2781:
return {.east = east_type::side, .north = north_type::none, .power = 0, .south = south_type::side, .west = west_type::none};
case 2782:
return {.east = east_type::side, .north = north_type::none, .power = 0, .south = south_type::none, .west = west_type::up};
case 2783:
return {.east = east_type::side, .north = north_type::none, .power = 0, .south = south_type::none, .west = west_type::side};
case 2784:
return {.east = east_type::side, .north = north_type::none, .power = 0, .south = south_type::none, .west = west_type::none};
case 2785:
return {.east = east_type::side, .north = north_type::none, .power = 1, .south = south_type::up, .west = west_type::up};
case 2786:
return {.east = east_type::side, .north = north_type::none, .power = 1, .south = south_type::up, .west = west_type::side};
case 2787:
return {.east = east_type::side, .north = north_type::none, .power = 1, .south = south_type::up, .west = west_type::none};
case 2788:
return {.east = east_type::side, .north = north_type::none, .power = 1, .south = south_type::side, .west = west_type::up};
case 2789:
return {.east = east_type::side, .north = north_type::none, .power = 1, .south = south_type::side, .west = west_type::side};
case 2790:
return {.east = east_type::side, .north = north_type::none, .power = 1, .south = south_type::side, .west = west_type::none};
case 2791:
return {.east = east_type::side, .north = north_type::none, .power = 1, .south = south_type::none, .west = west_type::up};
case 2792:
return {.east = east_type::side, .north = north_type::none, .power = 1, .south = south_type::none, .west = west_type::side};
case 2793:
return {.east = east_type::side, .north = north_type::none, .power = 1, .south = south_type::none, .west = west_type::none};
case 2794:
return {.east = east_type::side, .north = north_type::none, .power = 2, .south = south_type::up, .west = west_type::up};
case 2795:
return {.east = east_type::side, .north = north_type::none, .power = 2, .south = south_type::up, .west = west_type::side};
case 2796:
return {.east = east_type::side, .north = north_type::none, .power = 2, .south = south_type::up, .west = west_type::none};
case 2797:
return {.east = east_type::side, .north = north_type::none, .power = 2, .south = south_type::side, .west = west_type::up};
case 2798:
return {.east = east_type::side, .north = north_type::none, .power = 2, .south = south_type::side, .west = west_type::side};
case 2799:
return {.east = east_type::side, .north = north_type::none, .power = 2, .south = south_type::side, .west = west_type::none};
case 2800:
return {.east = east_type::side, .north = north_type::none, .power = 2, .south = south_type::none, .west = west_type::up};
case 2801:
return {.east = east_type::side, .north = north_type::none, .power = 2, .south = south_type::none, .west = west_type::side};
case 2802:
return {.east = east_type::side, .north = north_type::none, .power = 2, .south = south_type::none, .west = west_type::none};
case 2803:
return {.east = east_type::side, .north = north_type::none, .power = 3, .south = south_type::up, .west = west_type::up};
case 2804:
return {.east = east_type::side, .north = north_type::none, .power = 3, .south = south_type::up, .west = west_type::side};
case 2805:
return {.east = east_type::side, .north = north_type::none, .power = 3, .south = south_type::up, .west = west_type::none};
case 2806:
return {.east = east_type::side, .north = north_type::none, .power = 3, .south = south_type::side, .west = west_type::up};
case 2807:
return {.east = east_type::side, .north = north_type::none, .power = 3, .south = south_type::side, .west = west_type::side};
case 2808:
return {.east = east_type::side, .north = north_type::none, .power = 3, .south = south_type::side, .west = west_type::none};
case 2809:
return {.east = east_type::side, .north = north_type::none, .power = 3, .south = south_type::none, .west = west_type::up};
case 2810:
return {.east = east_type::side, .north = north_type::none, .power = 3, .south = south_type::none, .west = west_type::side};
case 2811:
return {.east = east_type::side, .north = north_type::none, .power = 3, .south = south_type::none, .west = west_type::none};
case 2812:
return {.east = east_type::side, .north = north_type::none, .power = 4, .south = south_type::up, .west = west_type::up};
case 2813:
return {.east = east_type::side, .north = north_type::none, .power = 4, .south = south_type::up, .west = west_type::side};
case 2814:
return {.east = east_type::side, .north = north_type::none, .power = 4, .south = south_type::up, .west = west_type::none};
case 2815:
return {.east = east_type::side, .north = north_type::none, .power = 4, .south = south_type::side, .west = west_type::up};
case 2816:
return {.east = east_type::side, .north = north_type::none, .power = 4, .south = south_type::side, .west = west_type::side};
case 2817:
return {.east = east_type::side, .north = north_type::none, .power = 4, .south = south_type::side, .west = west_type::none};
case 2818:
return {.east = east_type::side, .north = north_type::none, .power = 4, .south = south_type::none, .west = west_type::up};
case 2819:
return {.east = east_type::side, .north = north_type::none, .power = 4, .south = south_type::none, .west = west_type::side};
case 2820:
return {.east = east_type::side, .north = north_type::none, .power = 4, .south = south_type::none, .west = west_type::none};
case 2821:
return {.east = east_type::side, .north = north_type::none, .power = 5, .south = south_type::up, .west = west_type::up};
case 2822:
return {.east = east_type::side, .north = north_type::none, .power = 5, .south = south_type::up, .west = west_type::side};
case 2823:
return {.east = east_type::side, .north = north_type::none, .power = 5, .south = south_type::up, .west = west_type::none};
case 2824:
return {.east = east_type::side, .north = north_type::none, .power = 5, .south = south_type::side, .west = west_type::up};
case 2825:
return {.east = east_type::side, .north = north_type::none, .power = 5, .south = south_type::side, .west = west_type::side};
case 2826:
return {.east = east_type::side, .north = north_type::none, .power = 5, .south = south_type::side, .west = west_type::none};
case 2827:
return {.east = east_type::side, .north = north_type::none, .power = 5, .south = south_type::none, .west = west_type::up};
case 2828:
return {.east = east_type::side, .north = north_type::none, .power = 5, .south = south_type::none, .west = west_type::side};
case 2829:
return {.east = east_type::side, .north = north_type::none, .power = 5, .south = south_type::none, .west = west_type::none};
case 2830:
return {.east = east_type::side, .north = north_type::none, .power = 6, .south = south_type::up, .west = west_type::up};
case 2831:
return {.east = east_type::side, .north = north_type::none, .power = 6, .south = south_type::up, .west = west_type::side};
case 2832:
return {.east = east_type::side, .north = north_type::none, .power = 6, .south = south_type::up, .west = west_type::none};
case 2833:
return {.east = east_type::side, .north = north_type::none, .power = 6, .south = south_type::side, .west = west_type::up};
case 2834:
return {.east = east_type::side, .north = north_type::none, .power = 6, .south = south_type::side, .west = west_type::side};
case 2835:
return {.east = east_type::side, .north = north_type::none, .power = 6, .south = south_type::side, .west = west_type::none};
case 2836:
return {.east = east_type::side, .north = north_type::none, .power = 6, .south = south_type::none, .west = west_type::up};
case 2837:
return {.east = east_type::side, .north = north_type::none, .power = 6, .south = south_type::none, .west = west_type::side};
case 2838:
return {.east = east_type::side, .north = north_type::none, .power = 6, .south = south_type::none, .west = west_type::none};
case 2839:
return {.east = east_type::side, .north = north_type::none, .power = 7, .south = south_type::up, .west = west_type::up};
case 2840:
return {.east = east_type::side, .north = north_type::none, .power = 7, .south = south_type::up, .west = west_type::side};
case 2841:
return {.east = east_type::side, .north = north_type::none, .power = 7, .south = south_type::up, .west = west_type::none};
case 2842:
return {.east = east_type::side, .north = north_type::none, .power = 7, .south = south_type::side, .west = west_type::up};
case 2843:
return {.east = east_type::side, .north = north_type::none, .power = 7, .south = south_type::side, .west = west_type::side};
case 2844:
return {.east = east_type::side, .north = north_type::none, .power = 7, .south = south_type::side, .west = west_type::none};
case 2845:
return {.east = east_type::side, .north = north_type::none, .power = 7, .south = south_type::none, .west = west_type::up};
case 2846:
return {.east = east_type::side, .north = north_type::none, .power = 7, .south = south_type::none, .west = west_type::side};
case 2847:
return {.east = east_type::side, .north = north_type::none, .power = 7, .south = south_type::none, .west = west_type::none};
case 2848:
return {.east = east_type::side, .north = north_type::none, .power = 8, .south = south_type::up, .west = west_type::up};
case 2849:
return {.east = east_type::side, .north = north_type::none, .power = 8, .south = south_type::up, .west = west_type::side};
case 2850:
return {.east = east_type::side, .north = north_type::none, .power = 8, .south = south_type::up, .west = west_type::none};
case 2851:
return {.east = east_type::side, .north = north_type::none, .power = 8, .south = south_type::side, .west = west_type::up};
case 2852:
return {.east = east_type::side, .north = north_type::none, .power = 8, .south = south_type::side, .west = west_type::side};
case 2853:
return {.east = east_type::side, .north = north_type::none, .power = 8, .south = south_type::side, .west = west_type::none};
case 2854:
return {.east = east_type::side, .north = north_type::none, .power = 8, .south = south_type::none, .west = west_type::up};
case 2855:
return {.east = east_type::side, .north = north_type::none, .power = 8, .south = south_type::none, .west = west_type::side};
case 2856:
return {.east = east_type::side, .north = north_type::none, .power = 8, .south = south_type::none, .west = west_type::none};
case 2857:
return {.east = east_type::side, .north = north_type::none, .power = 9, .south = south_type::up, .west = west_type::up};
case 2858:
return {.east = east_type::side, .north = north_type::none, .power = 9, .south = south_type::up, .west = west_type::side};
case 2859:
return {.east = east_type::side, .north = north_type::none, .power = 9, .south = south_type::up, .west = west_type::none};
case 2860:
return {.east = east_type::side, .north = north_type::none, .power = 9, .south = south_type::side, .west = west_type::up};
case 2861:
return {.east = east_type::side, .north = north_type::none, .power = 9, .south = south_type::side, .west = west_type::side};
case 2862:
return {.east = east_type::side, .north = north_type::none, .power = 9, .south = south_type::side, .west = west_type::none};
case 2863:
return {.east = east_type::side, .north = north_type::none, .power = 9, .south = south_type::none, .west = west_type::up};
case 2864:
return {.east = east_type::side, .north = north_type::none, .power = 9, .south = south_type::none, .west = west_type::side};
case 2865:
return {.east = east_type::side, .north = north_type::none, .power = 9, .south = south_type::none, .west = west_type::none};
case 2866:
return {.east = east_type::side, .north = north_type::none, .power = 10, .south = south_type::up, .west = west_type::up};
case 2867:
return {.east = east_type::side, .north = north_type::none, .power = 10, .south = south_type::up, .west = west_type::side};
case 2868:
return {.east = east_type::side, .north = north_type::none, .power = 10, .south = south_type::up, .west = west_type::none};
case 2869:
return {.east = east_type::side, .north = north_type::none, .power = 10, .south = south_type::side, .west = west_type::up};
case 2870:
return {.east = east_type::side, .north = north_type::none, .power = 10, .south = south_type::side, .west = west_type::side};
case 2871:
return {.east = east_type::side, .north = north_type::none, .power = 10, .south = south_type::side, .west = west_type::none};
case 2872:
return {.east = east_type::side, .north = north_type::none, .power = 10, .south = south_type::none, .west = west_type::up};
case 2873:
return {.east = east_type::side, .north = north_type::none, .power = 10, .south = south_type::none, .west = west_type::side};
case 2874:
return {.east = east_type::side, .north = north_type::none, .power = 10, .south = south_type::none, .west = west_type::none};
case 2875:
return {.east = east_type::side, .north = north_type::none, .power = 11, .south = south_type::up, .west = west_type::up};
case 2876:
return {.east = east_type::side, .north = north_type::none, .power = 11, .south = south_type::up, .west = west_type::side};
case 2877:
return {.east = east_type::side, .north = north_type::none, .power = 11, .south = south_type::up, .west = west_type::none};
case 2878:
return {.east = east_type::side, .north = north_type::none, .power = 11, .south = south_type::side, .west = west_type::up};
case 2879:
return {.east = east_type::side, .north = north_type::none, .power = 11, .south = south_type::side, .west = west_type::side};
case 2880:
return {.east = east_type::side, .north = north_type::none, .power = 11, .south = south_type::side, .west = west_type::none};
case 2881:
return {.east = east_type::side, .north = north_type::none, .power = 11, .south = south_type::none, .west = west_type::up};
case 2882:
return {.east = east_type::side, .north = north_type::none, .power = 11, .south = south_type::none, .west = west_type::side};
case 2883:
return {.east = east_type::side, .north = north_type::none, .power = 11, .south = south_type::none, .west = west_type::none};
case 2884:
return {.east = east_type::side, .north = north_type::none, .power = 12, .south = south_type::up, .west = west_type::up};
case 2885:
return {.east = east_type::side, .north = north_type::none, .power = 12, .south = south_type::up, .west = west_type::side};
case 2886:
return {.east = east_type::side, .north = north_type::none, .power = 12, .south = south_type::up, .west = west_type::none};
case 2887:
return {.east = east_type::side, .north = north_type::none, .power = 12, .south = south_type::side, .west = west_type::up};
case 2888:
return {.east = east_type::side, .north = north_type::none, .power = 12, .south = south_type::side, .west = west_type::side};
case 2889:
return {.east = east_type::side, .north = north_type::none, .power = 12, .south = south_type::side, .west = west_type::none};
case 2890:
return {.east = east_type::side, .north = north_type::none, .power = 12, .south = south_type::none, .west = west_type::up};
case 2891:
return {.east = east_type::side, .north = north_type::none, .power = 12, .south = south_type::none, .west = west_type::side};
case 2892:
return {.east = east_type::side, .north = north_type::none, .power = 12, .south = south_type::none, .west = west_type::none};
case 2893:
return {.east = east_type::side, .north = north_type::none, .power = 13, .south = south_type::up, .west = west_type::up};
case 2894:
return {.east = east_type::side, .north = north_type::none, .power = 13, .south = south_type::up, .west = west_type::side};
case 2895:
return {.east = east_type::side, .north = north_type::none, .power = 13, .south = south_type::up, .west = west_type::none};
case 2896:
return {.east = east_type::side, .north = north_type::none, .power = 13, .south = south_type::side, .west = west_type::up};
case 2897:
return {.east = east_type::side, .north = north_type::none, .power = 13, .south = south_type::side, .west = west_type::side};
case 2898:
return {.east = east_type::side, .north = north_type::none, .power = 13, .south = south_type::side, .west = west_type::none};
case 2899:
return {.east = east_type::side, .north = north_type::none, .power = 13, .south = south_type::none, .west = west_type::up};
case 2900:
return {.east = east_type::side, .north = north_type::none, .power = 13, .south = south_type::none, .west = west_type::side};
case 2901:
return {.east = east_type::side, .north = north_type::none, .power = 13, .south = south_type::none, .west = west_type::none};
case 2902:
return {.east = east_type::side, .north = north_type::none, .power = 14, .south = south_type::up, .west = west_type::up};
case 2903:
return {.east = east_type::side, .north = north_type::none, .power = 14, .south = south_type::up, .west = west_type::side};
case 2904:
return {.east = east_type::side, .north = north_type::none, .power = 14, .south = south_type::up, .west = west_type::none};
case 2905:
return {.east = east_type::side, .north = north_type::none, .power = 14, .south = south_type::side, .west = west_type::up};
case 2906:
return {.east = east_type::side, .north = north_type::none, .power = 14, .south = south_type::side, .west = west_type::side};
case 2907:
return {.east = east_type::side, .north = north_type::none, .power = 14, .south = south_type::side, .west = west_type::none};
case 2908:
return {.east = east_type::side, .north = north_type::none, .power = 14, .south = south_type::none, .west = west_type::up};
case 2909:
return {.east = east_type::side, .north = north_type::none, .power = 14, .south = south_type::none, .west = west_type::side};
case 2910:
return {.east = east_type::side, .north = north_type::none, .power = 14, .south = south_type::none, .west = west_type::none};
case 2911:
return {.east = east_type::side, .north = north_type::none, .power = 15, .south = south_type::up, .west = west_type::up};
case 2912:
return {.east = east_type::side, .north = north_type::none, .power = 15, .south = south_type::up, .west = west_type::side};
case 2913:
return {.east = east_type::side, .north = north_type::none, .power = 15, .south = south_type::up, .west = west_type::none};
case 2914:
return {.east = east_type::side, .north = north_type::none, .power = 15, .south = south_type::side, .west = west_type::up};
case 2915:
return {.east = east_type::side, .north = north_type::none, .power = 15, .south = south_type::side, .west = west_type::side};
case 2916:
return {.east = east_type::side, .north = north_type::none, .power = 15, .south = south_type::side, .west = west_type::none};
case 2917:
return {.east = east_type::side, .north = north_type::none, .power = 15, .south = south_type::none, .west = west_type::up};
case 2918:
return {.east = east_type::side, .north = north_type::none, .power = 15, .south = south_type::none, .west = west_type::side};
case 2919:
return {.east = east_type::side, .north = north_type::none, .power = 15, .south = south_type::none, .west = west_type::none};
case 2920:
return {.east = east_type::none, .north = north_type::up, .power = 0, .south = south_type::up, .west = west_type::up};
case 2921:
return {.east = east_type::none, .north = north_type::up, .power = 0, .south = south_type::up, .west = west_type::side};
case 2922:
return {.east = east_type::none, .north = north_type::up, .power = 0, .south = south_type::up, .west = west_type::none};
case 2923:
return {.east = east_type::none, .north = north_type::up, .power = 0, .south = south_type::side, .west = west_type::up};
case 2924:
return {.east = east_type::none, .north = north_type::up, .power = 0, .south = south_type::side, .west = west_type::side};
case 2925:
return {.east = east_type::none, .north = north_type::up, .power = 0, .south = south_type::side, .west = west_type::none};
case 2926:
return {.east = east_type::none, .north = north_type::up, .power = 0, .south = south_type::none, .west = west_type::up};
case 2927:
return {.east = east_type::none, .north = north_type::up, .power = 0, .south = south_type::none, .west = west_type::side};
case 2928:
return {.east = east_type::none, .north = north_type::up, .power = 0, .south = south_type::none, .west = west_type::none};
case 2929:
return {.east = east_type::none, .north = north_type::up, .power = 1, .south = south_type::up, .west = west_type::up};
case 2930:
return {.east = east_type::none, .north = north_type::up, .power = 1, .south = south_type::up, .west = west_type::side};
case 2931:
return {.east = east_type::none, .north = north_type::up, .power = 1, .south = south_type::up, .west = west_type::none};
case 2932:
return {.east = east_type::none, .north = north_type::up, .power = 1, .south = south_type::side, .west = west_type::up};
case 2933:
return {.east = east_type::none, .north = north_type::up, .power = 1, .south = south_type::side, .west = west_type::side};
case 2934:
return {.east = east_type::none, .north = north_type::up, .power = 1, .south = south_type::side, .west = west_type::none};
case 2935:
return {.east = east_type::none, .north = north_type::up, .power = 1, .south = south_type::none, .west = west_type::up};
case 2936:
return {.east = east_type::none, .north = north_type::up, .power = 1, .south = south_type::none, .west = west_type::side};
case 2937:
return {.east = east_type::none, .north = north_type::up, .power = 1, .south = south_type::none, .west = west_type::none};
case 2938:
return {.east = east_type::none, .north = north_type::up, .power = 2, .south = south_type::up, .west = west_type::up};
case 2939:
return {.east = east_type::none, .north = north_type::up, .power = 2, .south = south_type::up, .west = west_type::side};
case 2940:
return {.east = east_type::none, .north = north_type::up, .power = 2, .south = south_type::up, .west = west_type::none};
case 2941:
return {.east = east_type::none, .north = north_type::up, .power = 2, .south = south_type::side, .west = west_type::up};
case 2942:
return {.east = east_type::none, .north = north_type::up, .power = 2, .south = south_type::side, .west = west_type::side};
case 2943:
return {.east = east_type::none, .north = north_type::up, .power = 2, .south = south_type::side, .west = west_type::none};
case 2944:
return {.east = east_type::none, .north = north_type::up, .power = 2, .south = south_type::none, .west = west_type::up};
case 2945:
return {.east = east_type::none, .north = north_type::up, .power = 2, .south = south_type::none, .west = west_type::side};
case 2946:
return {.east = east_type::none, .north = north_type::up, .power = 2, .south = south_type::none, .west = west_type::none};
case 2947:
return {.east = east_type::none, .north = north_type::up, .power = 3, .south = south_type::up, .west = west_type::up};
case 2948:
return {.east = east_type::none, .north = north_type::up, .power = 3, .south = south_type::up, .west = west_type::side};
case 2949:
return {.east = east_type::none, .north = north_type::up, .power = 3, .south = south_type::up, .west = west_type::none};
case 2950:
return {.east = east_type::none, .north = north_type::up, .power = 3, .south = south_type::side, .west = west_type::up};
case 2951:
return {.east = east_type::none, .north = north_type::up, .power = 3, .south = south_type::side, .west = west_type::side};
case 2952:
return {.east = east_type::none, .north = north_type::up, .power = 3, .south = south_type::side, .west = west_type::none};
case 2953:
return {.east = east_type::none, .north = north_type::up, .power = 3, .south = south_type::none, .west = west_type::up};
case 2954:
return {.east = east_type::none, .north = north_type::up, .power = 3, .south = south_type::none, .west = west_type::side};
case 2955:
return {.east = east_type::none, .north = north_type::up, .power = 3, .south = south_type::none, .west = west_type::none};
case 2956:
return {.east = east_type::none, .north = north_type::up, .power = 4, .south = south_type::up, .west = west_type::up};
case 2957:
return {.east = east_type::none, .north = north_type::up, .power = 4, .south = south_type::up, .west = west_type::side};
case 2958:
return {.east = east_type::none, .north = north_type::up, .power = 4, .south = south_type::up, .west = west_type::none};
case 2959:
return {.east = east_type::none, .north = north_type::up, .power = 4, .south = south_type::side, .west = west_type::up};
case 2960:
return {.east = east_type::none, .north = north_type::up, .power = 4, .south = south_type::side, .west = west_type::side};
case 2961:
return {.east = east_type::none, .north = north_type::up, .power = 4, .south = south_type::side, .west = west_type::none};
case 2962:
return {.east = east_type::none, .north = north_type::up, .power = 4, .south = south_type::none, .west = west_type::up};
case 2963:
return {.east = east_type::none, .north = north_type::up, .power = 4, .south = south_type::none, .west = west_type::side};
case 2964:
return {.east = east_type::none, .north = north_type::up, .power = 4, .south = south_type::none, .west = west_type::none};
case 2965:
return {.east = east_type::none, .north = north_type::up, .power = 5, .south = south_type::up, .west = west_type::up};
case 2966:
return {.east = east_type::none, .north = north_type::up, .power = 5, .south = south_type::up, .west = west_type::side};
case 2967:
return {.east = east_type::none, .north = north_type::up, .power = 5, .south = south_type::up, .west = west_type::none};
case 2968:
return {.east = east_type::none, .north = north_type::up, .power = 5, .south = south_type::side, .west = west_type::up};
case 2969:
return {.east = east_type::none, .north = north_type::up, .power = 5, .south = south_type::side, .west = west_type::side};
case 2970:
return {.east = east_type::none, .north = north_type::up, .power = 5, .south = south_type::side, .west = west_type::none};
case 2971:
return {.east = east_type::none, .north = north_type::up, .power = 5, .south = south_type::none, .west = west_type::up};
case 2972:
return {.east = east_type::none, .north = north_type::up, .power = 5, .south = south_type::none, .west = west_type::side};
case 2973:
return {.east = east_type::none, .north = north_type::up, .power = 5, .south = south_type::none, .west = west_type::none};
case 2974:
return {.east = east_type::none, .north = north_type::up, .power = 6, .south = south_type::up, .west = west_type::up};
case 2975:
return {.east = east_type::none, .north = north_type::up, .power = 6, .south = south_type::up, .west = west_type::side};
case 2976:
return {.east = east_type::none, .north = north_type::up, .power = 6, .south = south_type::up, .west = west_type::none};
case 2977:
return {.east = east_type::none, .north = north_type::up, .power = 6, .south = south_type::side, .west = west_type::up};
case 2978:
return {.east = east_type::none, .north = north_type::up, .power = 6, .south = south_type::side, .west = west_type::side};
case 2979:
return {.east = east_type::none, .north = north_type::up, .power = 6, .south = south_type::side, .west = west_type::none};
case 2980:
return {.east = east_type::none, .north = north_type::up, .power = 6, .south = south_type::none, .west = west_type::up};
case 2981:
return {.east = east_type::none, .north = north_type::up, .power = 6, .south = south_type::none, .west = west_type::side};
case 2982:
return {.east = east_type::none, .north = north_type::up, .power = 6, .south = south_type::none, .west = west_type::none};
case 2983:
return {.east = east_type::none, .north = north_type::up, .power = 7, .south = south_type::up, .west = west_type::up};
case 2984:
return {.east = east_type::none, .north = north_type::up, .power = 7, .south = south_type::up, .west = west_type::side};
case 2985:
return {.east = east_type::none, .north = north_type::up, .power = 7, .south = south_type::up, .west = west_type::none};
case 2986:
return {.east = east_type::none, .north = north_type::up, .power = 7, .south = south_type::side, .west = west_type::up};
case 2987:
return {.east = east_type::none, .north = north_type::up, .power = 7, .south = south_type::side, .west = west_type::side};
case 2988:
return {.east = east_type::none, .north = north_type::up, .power = 7, .south = south_type::side, .west = west_type::none};
case 2989:
return {.east = east_type::none, .north = north_type::up, .power = 7, .south = south_type::none, .west = west_type::up};
case 2990:
return {.east = east_type::none, .north = north_type::up, .power = 7, .south = south_type::none, .west = west_type::side};
case 2991:
return {.east = east_type::none, .north = north_type::up, .power = 7, .south = south_type::none, .west = west_type::none};
case 2992:
return {.east = east_type::none, .north = north_type::up, .power = 8, .south = south_type::up, .west = west_type::up};
case 2993:
return {.east = east_type::none, .north = north_type::up, .power = 8, .south = south_type::up, .west = west_type::side};
case 2994:
return {.east = east_type::none, .north = north_type::up, .power = 8, .south = south_type::up, .west = west_type::none};
case 2995:
return {.east = east_type::none, .north = north_type::up, .power = 8, .south = south_type::side, .west = west_type::up};
case 2996:
return {.east = east_type::none, .north = north_type::up, .power = 8, .south = south_type::side, .west = west_type::side};
case 2997:
return {.east = east_type::none, .north = north_type::up, .power = 8, .south = south_type::side, .west = west_type::none};
case 2998:
return {.east = east_type::none, .north = north_type::up, .power = 8, .south = south_type::none, .west = west_type::up};
case 2999:
return {.east = east_type::none, .north = north_type::up, .power = 8, .south = south_type::none, .west = west_type::side};
case 3000:
return {.east = east_type::none, .north = north_type::up, .power = 8, .south = south_type::none, .west = west_type::none};
case 3001:
return {.east = east_type::none, .north = north_type::up, .power = 9, .south = south_type::up, .west = west_type::up};
case 3002:
return {.east = east_type::none, .north = north_type::up, .power = 9, .south = south_type::up, .west = west_type::side};
case 3003:
return {.east = east_type::none, .north = north_type::up, .power = 9, .south = south_type::up, .west = west_type::none};
case 3004:
return {.east = east_type::none, .north = north_type::up, .power = 9, .south = south_type::side, .west = west_type::up};
case 3005:
return {.east = east_type::none, .north = north_type::up, .power = 9, .south = south_type::side, .west = west_type::side};
case 3006:
return {.east = east_type::none, .north = north_type::up, .power = 9, .south = south_type::side, .west = west_type::none};
case 3007:
return {.east = east_type::none, .north = north_type::up, .power = 9, .south = south_type::none, .west = west_type::up};
case 3008:
return {.east = east_type::none, .north = north_type::up, .power = 9, .south = south_type::none, .west = west_type::side};
case 3009:
return {.east = east_type::none, .north = north_type::up, .power = 9, .south = south_type::none, .west = west_type::none};
case 3010:
return {.east = east_type::none, .north = north_type::up, .power = 10, .south = south_type::up, .west = west_type::up};
case 3011:
return {.east = east_type::none, .north = north_type::up, .power = 10, .south = south_type::up, .west = west_type::side};
case 3012:
return {.east = east_type::none, .north = north_type::up, .power = 10, .south = south_type::up, .west = west_type::none};
case 3013:
return {.east = east_type::none, .north = north_type::up, .power = 10, .south = south_type::side, .west = west_type::up};
case 3014:
return {.east = east_type::none, .north = north_type::up, .power = 10, .south = south_type::side, .west = west_type::side};
case 3015:
return {.east = east_type::none, .north = north_type::up, .power = 10, .south = south_type::side, .west = west_type::none};
case 3016:
return {.east = east_type::none, .north = north_type::up, .power = 10, .south = south_type::none, .west = west_type::up};
case 3017:
return {.east = east_type::none, .north = north_type::up, .power = 10, .south = south_type::none, .west = west_type::side};
case 3018:
return {.east = east_type::none, .north = north_type::up, .power = 10, .south = south_type::none, .west = west_type::none};
case 3019:
return {.east = east_type::none, .north = north_type::up, .power = 11, .south = south_type::up, .west = west_type::up};
case 3020:
return {.east = east_type::none, .north = north_type::up, .power = 11, .south = south_type::up, .west = west_type::side};
case 3021:
return {.east = east_type::none, .north = north_type::up, .power = 11, .south = south_type::up, .west = west_type::none};
case 3022:
return {.east = east_type::none, .north = north_type::up, .power = 11, .south = south_type::side, .west = west_type::up};
case 3023:
return {.east = east_type::none, .north = north_type::up, .power = 11, .south = south_type::side, .west = west_type::side};
case 3024:
return {.east = east_type::none, .north = north_type::up, .power = 11, .south = south_type::side, .west = west_type::none};
case 3025:
return {.east = east_type::none, .north = north_type::up, .power = 11, .south = south_type::none, .west = west_type::up};
case 3026:
return {.east = east_type::none, .north = north_type::up, .power = 11, .south = south_type::none, .west = west_type::side};
case 3027:
return {.east = east_type::none, .north = north_type::up, .power = 11, .south = south_type::none, .west = west_type::none};
case 3028:
return {.east = east_type::none, .north = north_type::up, .power = 12, .south = south_type::up, .west = west_type::up};
case 3029:
return {.east = east_type::none, .north = north_type::up, .power = 12, .south = south_type::up, .west = west_type::side};
case 3030:
return {.east = east_type::none, .north = north_type::up, .power = 12, .south = south_type::up, .west = west_type::none};
case 3031:
return {.east = east_type::none, .north = north_type::up, .power = 12, .south = south_type::side, .west = west_type::up};
case 3032:
return {.east = east_type::none, .north = north_type::up, .power = 12, .south = south_type::side, .west = west_type::side};
case 3033:
return {.east = east_type::none, .north = north_type::up, .power = 12, .south = south_type::side, .west = west_type::none};
case 3034:
return {.east = east_type::none, .north = north_type::up, .power = 12, .south = south_type::none, .west = west_type::up};
case 3035:
return {.east = east_type::none, .north = north_type::up, .power = 12, .south = south_type::none, .west = west_type::side};
case 3036:
return {.east = east_type::none, .north = north_type::up, .power = 12, .south = south_type::none, .west = west_type::none};
case 3037:
return {.east = east_type::none, .north = north_type::up, .power = 13, .south = south_type::up, .west = west_type::up};
case 3038:
return {.east = east_type::none, .north = north_type::up, .power = 13, .south = south_type::up, .west = west_type::side};
case 3039:
return {.east = east_type::none, .north = north_type::up, .power = 13, .south = south_type::up, .west = west_type::none};
case 3040:
return {.east = east_type::none, .north = north_type::up, .power = 13, .south = south_type::side, .west = west_type::up};
case 3041:
return {.east = east_type::none, .north = north_type::up, .power = 13, .south = south_type::side, .west = west_type::side};
case 3042:
return {.east = east_type::none, .north = north_type::up, .power = 13, .south = south_type::side, .west = west_type::none};
case 3043:
return {.east = east_type::none, .north = north_type::up, .power = 13, .south = south_type::none, .west = west_type::up};
case 3044:
return {.east = east_type::none, .north = north_type::up, .power = 13, .south = south_type::none, .west = west_type::side};
case 3045:
return {.east = east_type::none, .north = north_type::up, .power = 13, .south = south_type::none, .west = west_type::none};
case 3046:
return {.east = east_type::none, .north = north_type::up, .power = 14, .south = south_type::up, .west = west_type::up};
case 3047:
return {.east = east_type::none, .north = north_type::up, .power = 14, .south = south_type::up, .west = west_type::side};
case 3048:
return {.east = east_type::none, .north = north_type::up, .power = 14, .south = south_type::up, .west = west_type::none};
case 3049:
return {.east = east_type::none, .north = north_type::up, .power = 14, .south = south_type::side, .west = west_type::up};
case 3050:
return {.east = east_type::none, .north = north_type::up, .power = 14, .south = south_type::side, .west = west_type::side};
case 3051:
return {.east = east_type::none, .north = north_type::up, .power = 14, .south = south_type::side, .west = west_type::none};
case 3052:
return {.east = east_type::none, .north = north_type::up, .power = 14, .south = south_type::none, .west = west_type::up};
case 3053:
return {.east = east_type::none, .north = north_type::up, .power = 14, .south = south_type::none, .west = west_type::side};
case 3054:
return {.east = east_type::none, .north = north_type::up, .power = 14, .south = south_type::none, .west = west_type::none};
case 3055:
return {.east = east_type::none, .north = north_type::up, .power = 15, .south = south_type::up, .west = west_type::up};
case 3056:
return {.east = east_type::none, .north = north_type::up, .power = 15, .south = south_type::up, .west = west_type::side};
case 3057:
return {.east = east_type::none, .north = north_type::up, .power = 15, .south = south_type::up, .west = west_type::none};
case 3058:
return {.east = east_type::none, .north = north_type::up, .power = 15, .south = south_type::side, .west = west_type::up};
case 3059:
return {.east = east_type::none, .north = north_type::up, .power = 15, .south = south_type::side, .west = west_type::side};
case 3060:
return {.east = east_type::none, .north = north_type::up, .power = 15, .south = south_type::side, .west = west_type::none};
case 3061:
return {.east = east_type::none, .north = north_type::up, .power = 15, .south = south_type::none, .west = west_type::up};
case 3062:
return {.east = east_type::none, .north = north_type::up, .power = 15, .south = south_type::none, .west = west_type::side};
case 3063:
return {.east = east_type::none, .north = north_type::up, .power = 15, .south = south_type::none, .west = west_type::none};
case 3064:
return {.east = east_type::none, .north = north_type::side, .power = 0, .south = south_type::up, .west = west_type::up};
case 3065:
return {.east = east_type::none, .north = north_type::side, .power = 0, .south = south_type::up, .west = west_type::side};
case 3066:
return {.east = east_type::none, .north = north_type::side, .power = 0, .south = south_type::up, .west = west_type::none};
case 3067:
return {.east = east_type::none, .north = north_type::side, .power = 0, .south = south_type::side, .west = west_type::up};
case 3068:
return {.east = east_type::none, .north = north_type::side, .power = 0, .south = south_type::side, .west = west_type::side};
case 3069:
return {.east = east_type::none, .north = north_type::side, .power = 0, .south = south_type::side, .west = west_type::none};
case 3070:
return {.east = east_type::none, .north = north_type::side, .power = 0, .south = south_type::none, .west = west_type::up};
case 3071:
return {.east = east_type::none, .north = north_type::side, .power = 0, .south = south_type::none, .west = west_type::side};
case 3072:
return {.east = east_type::none, .north = north_type::side, .power = 0, .south = south_type::none, .west = west_type::none};
case 3073:
return {.east = east_type::none, .north = north_type::side, .power = 1, .south = south_type::up, .west = west_type::up};
case 3074:
return {.east = east_type::none, .north = north_type::side, .power = 1, .south = south_type::up, .west = west_type::side};
case 3075:
return {.east = east_type::none, .north = north_type::side, .power = 1, .south = south_type::up, .west = west_type::none};
case 3076:
return {.east = east_type::none, .north = north_type::side, .power = 1, .south = south_type::side, .west = west_type::up};
case 3077:
return {.east = east_type::none, .north = north_type::side, .power = 1, .south = south_type::side, .west = west_type::side};
case 3078:
return {.east = east_type::none, .north = north_type::side, .power = 1, .south = south_type::side, .west = west_type::none};
case 3079:
return {.east = east_type::none, .north = north_type::side, .power = 1, .south = south_type::none, .west = west_type::up};
case 3080:
return {.east = east_type::none, .north = north_type::side, .power = 1, .south = south_type::none, .west = west_type::side};
case 3081:
return {.east = east_type::none, .north = north_type::side, .power = 1, .south = south_type::none, .west = west_type::none};
case 3082:
return {.east = east_type::none, .north = north_type::side, .power = 2, .south = south_type::up, .west = west_type::up};
case 3083:
return {.east = east_type::none, .north = north_type::side, .power = 2, .south = south_type::up, .west = west_type::side};
case 3084:
return {.east = east_type::none, .north = north_type::side, .power = 2, .south = south_type::up, .west = west_type::none};
case 3085:
return {.east = east_type::none, .north = north_type::side, .power = 2, .south = south_type::side, .west = west_type::up};
case 3086:
return {.east = east_type::none, .north = north_type::side, .power = 2, .south = south_type::side, .west = west_type::side};
case 3087:
return {.east = east_type::none, .north = north_type::side, .power = 2, .south = south_type::side, .west = west_type::none};
case 3088:
return {.east = east_type::none, .north = north_type::side, .power = 2, .south = south_type::none, .west = west_type::up};
case 3089:
return {.east = east_type::none, .north = north_type::side, .power = 2, .south = south_type::none, .west = west_type::side};
case 3090:
return {.east = east_type::none, .north = north_type::side, .power = 2, .south = south_type::none, .west = west_type::none};
case 3091:
return {.east = east_type::none, .north = north_type::side, .power = 3, .south = south_type::up, .west = west_type::up};
case 3092:
return {.east = east_type::none, .north = north_type::side, .power = 3, .south = south_type::up, .west = west_type::side};
case 3093:
return {.east = east_type::none, .north = north_type::side, .power = 3, .south = south_type::up, .west = west_type::none};
case 3094:
return {.east = east_type::none, .north = north_type::side, .power = 3, .south = south_type::side, .west = west_type::up};
case 3095:
return {.east = east_type::none, .north = north_type::side, .power = 3, .south = south_type::side, .west = west_type::side};
case 3096:
return {.east = east_type::none, .north = north_type::side, .power = 3, .south = south_type::side, .west = west_type::none};
case 3097:
return {.east = east_type::none, .north = north_type::side, .power = 3, .south = south_type::none, .west = west_type::up};
case 3098:
return {.east = east_type::none, .north = north_type::side, .power = 3, .south = south_type::none, .west = west_type::side};
case 3099:
return {.east = east_type::none, .north = north_type::side, .power = 3, .south = south_type::none, .west = west_type::none};
case 3100:
return {.east = east_type::none, .north = north_type::side, .power = 4, .south = south_type::up, .west = west_type::up};
case 3101:
return {.east = east_type::none, .north = north_type::side, .power = 4, .south = south_type::up, .west = west_type::side};
case 3102:
return {.east = east_type::none, .north = north_type::side, .power = 4, .south = south_type::up, .west = west_type::none};
case 3103:
return {.east = east_type::none, .north = north_type::side, .power = 4, .south = south_type::side, .west = west_type::up};
case 3104:
return {.east = east_type::none, .north = north_type::side, .power = 4, .south = south_type::side, .west = west_type::side};
case 3105:
return {.east = east_type::none, .north = north_type::side, .power = 4, .south = south_type::side, .west = west_type::none};
case 3106:
return {.east = east_type::none, .north = north_type::side, .power = 4, .south = south_type::none, .west = west_type::up};
case 3107:
return {.east = east_type::none, .north = north_type::side, .power = 4, .south = south_type::none, .west = west_type::side};
case 3108:
return {.east = east_type::none, .north = north_type::side, .power = 4, .south = south_type::none, .west = west_type::none};
case 3109:
return {.east = east_type::none, .north = north_type::side, .power = 5, .south = south_type::up, .west = west_type::up};
case 3110:
return {.east = east_type::none, .north = north_type::side, .power = 5, .south = south_type::up, .west = west_type::side};
case 3111:
return {.east = east_type::none, .north = north_type::side, .power = 5, .south = south_type::up, .west = west_type::none};
case 3112:
return {.east = east_type::none, .north = north_type::side, .power = 5, .south = south_type::side, .west = west_type::up};
case 3113:
return {.east = east_type::none, .north = north_type::side, .power = 5, .south = south_type::side, .west = west_type::side};
case 3114:
return {.east = east_type::none, .north = north_type::side, .power = 5, .south = south_type::side, .west = west_type::none};
case 3115:
return {.east = east_type::none, .north = north_type::side, .power = 5, .south = south_type::none, .west = west_type::up};
case 3116:
return {.east = east_type::none, .north = north_type::side, .power = 5, .south = south_type::none, .west = west_type::side};
case 3117:
return {.east = east_type::none, .north = north_type::side, .power = 5, .south = south_type::none, .west = west_type::none};
case 3118:
return {.east = east_type::none, .north = north_type::side, .power = 6, .south = south_type::up, .west = west_type::up};
case 3119:
return {.east = east_type::none, .north = north_type::side, .power = 6, .south = south_type::up, .west = west_type::side};
case 3120:
return {.east = east_type::none, .north = north_type::side, .power = 6, .south = south_type::up, .west = west_type::none};
case 3121:
return {.east = east_type::none, .north = north_type::side, .power = 6, .south = south_type::side, .west = west_type::up};
case 3122:
return {.east = east_type::none, .north = north_type::side, .power = 6, .south = south_type::side, .west = west_type::side};
case 3123:
return {.east = east_type::none, .north = north_type::side, .power = 6, .south = south_type::side, .west = west_type::none};
case 3124:
return {.east = east_type::none, .north = north_type::side, .power = 6, .south = south_type::none, .west = west_type::up};
case 3125:
return {.east = east_type::none, .north = north_type::side, .power = 6, .south = south_type::none, .west = west_type::side};
case 3126:
return {.east = east_type::none, .north = north_type::side, .power = 6, .south = south_type::none, .west = west_type::none};
case 3127:
return {.east = east_type::none, .north = north_type::side, .power = 7, .south = south_type::up, .west = west_type::up};
case 3128:
return {.east = east_type::none, .north = north_type::side, .power = 7, .south = south_type::up, .west = west_type::side};
case 3129:
return {.east = east_type::none, .north = north_type::side, .power = 7, .south = south_type::up, .west = west_type::none};
case 3130:
return {.east = east_type::none, .north = north_type::side, .power = 7, .south = south_type::side, .west = west_type::up};
case 3131:
return {.east = east_type::none, .north = north_type::side, .power = 7, .south = south_type::side, .west = west_type::side};
case 3132:
return {.east = east_type::none, .north = north_type::side, .power = 7, .south = south_type::side, .west = west_type::none};
case 3133:
return {.east = east_type::none, .north = north_type::side, .power = 7, .south = south_type::none, .west = west_type::up};
case 3134:
return {.east = east_type::none, .north = north_type::side, .power = 7, .south = south_type::none, .west = west_type::side};
case 3135:
return {.east = east_type::none, .north = north_type::side, .power = 7, .south = south_type::none, .west = west_type::none};
case 3136:
return {.east = east_type::none, .north = north_type::side, .power = 8, .south = south_type::up, .west = west_type::up};
case 3137:
return {.east = east_type::none, .north = north_type::side, .power = 8, .south = south_type::up, .west = west_type::side};
case 3138:
return {.east = east_type::none, .north = north_type::side, .power = 8, .south = south_type::up, .west = west_type::none};
case 3139:
return {.east = east_type::none, .north = north_type::side, .power = 8, .south = south_type::side, .west = west_type::up};
case 3140:
return {.east = east_type::none, .north = north_type::side, .power = 8, .south = south_type::side, .west = west_type::side};
case 3141:
return {.east = east_type::none, .north = north_type::side, .power = 8, .south = south_type::side, .west = west_type::none};
case 3142:
return {.east = east_type::none, .north = north_type::side, .power = 8, .south = south_type::none, .west = west_type::up};
case 3143:
return {.east = east_type::none, .north = north_type::side, .power = 8, .south = south_type::none, .west = west_type::side};
case 3144:
return {.east = east_type::none, .north = north_type::side, .power = 8, .south = south_type::none, .west = west_type::none};
case 3145:
return {.east = east_type::none, .north = north_type::side, .power = 9, .south = south_type::up, .west = west_type::up};
case 3146:
return {.east = east_type::none, .north = north_type::side, .power = 9, .south = south_type::up, .west = west_type::side};
case 3147:
return {.east = east_type::none, .north = north_type::side, .power = 9, .south = south_type::up, .west = west_type::none};
case 3148:
return {.east = east_type::none, .north = north_type::side, .power = 9, .south = south_type::side, .west = west_type::up};
case 3149:
return {.east = east_type::none, .north = north_type::side, .power = 9, .south = south_type::side, .west = west_type::side};
case 3150:
return {.east = east_type::none, .north = north_type::side, .power = 9, .south = south_type::side, .west = west_type::none};
case 3151:
return {.east = east_type::none, .north = north_type::side, .power = 9, .south = south_type::none, .west = west_type::up};
case 3152:
return {.east = east_type::none, .north = north_type::side, .power = 9, .south = south_type::none, .west = west_type::side};
case 3153:
return {.east = east_type::none, .north = north_type::side, .power = 9, .south = south_type::none, .west = west_type::none};
case 3154:
return {.east = east_type::none, .north = north_type::side, .power = 10, .south = south_type::up, .west = west_type::up};
case 3155:
return {.east = east_type::none, .north = north_type::side, .power = 10, .south = south_type::up, .west = west_type::side};
case 3156:
return {.east = east_type::none, .north = north_type::side, .power = 10, .south = south_type::up, .west = west_type::none};
case 3157:
return {.east = east_type::none, .north = north_type::side, .power = 10, .south = south_type::side, .west = west_type::up};
case 3158:
return {.east = east_type::none, .north = north_type::side, .power = 10, .south = south_type::side, .west = west_type::side};
case 3159:
return {.east = east_type::none, .north = north_type::side, .power = 10, .south = south_type::side, .west = west_type::none};
case 3160:
return {.east = east_type::none, .north = north_type::side, .power = 10, .south = south_type::none, .west = west_type::up};
case 3161:
return {.east = east_type::none, .north = north_type::side, .power = 10, .south = south_type::none, .west = west_type::side};
case 3162:
return {.east = east_type::none, .north = north_type::side, .power = 10, .south = south_type::none, .west = west_type::none};
case 3163:
return {.east = east_type::none, .north = north_type::side, .power = 11, .south = south_type::up, .west = west_type::up};
case 3164:
return {.east = east_type::none, .north = north_type::side, .power = 11, .south = south_type::up, .west = west_type::side};
case 3165:
return {.east = east_type::none, .north = north_type::side, .power = 11, .south = south_type::up, .west = west_type::none};
case 3166:
return {.east = east_type::none, .north = north_type::side, .power = 11, .south = south_type::side, .west = west_type::up};
case 3167:
return {.east = east_type::none, .north = north_type::side, .power = 11, .south = south_type::side, .west = west_type::side};
case 3168:
return {.east = east_type::none, .north = north_type::side, .power = 11, .south = south_type::side, .west = west_type::none};
case 3169:
return {.east = east_type::none, .north = north_type::side, .power = 11, .south = south_type::none, .west = west_type::up};
case 3170:
return {.east = east_type::none, .north = north_type::side, .power = 11, .south = south_type::none, .west = west_type::side};
case 3171:
return {.east = east_type::none, .north = north_type::side, .power = 11, .south = south_type::none, .west = west_type::none};
case 3172:
return {.east = east_type::none, .north = north_type::side, .power = 12, .south = south_type::up, .west = west_type::up};
case 3173:
return {.east = east_type::none, .north = north_type::side, .power = 12, .south = south_type::up, .west = west_type::side};
case 3174:
return {.east = east_type::none, .north = north_type::side, .power = 12, .south = south_type::up, .west = west_type::none};
case 3175:
return {.east = east_type::none, .north = north_type::side, .power = 12, .south = south_type::side, .west = west_type::up};
case 3176:
return {.east = east_type::none, .north = north_type::side, .power = 12, .south = south_type::side, .west = west_type::side};
case 3177:
return {.east = east_type::none, .north = north_type::side, .power = 12, .south = south_type::side, .west = west_type::none};
case 3178:
return {.east = east_type::none, .north = north_type::side, .power = 12, .south = south_type::none, .west = west_type::up};
case 3179:
return {.east = east_type::none, .north = north_type::side, .power = 12, .south = south_type::none, .west = west_type::side};
case 3180:
return {.east = east_type::none, .north = north_type::side, .power = 12, .south = south_type::none, .west = west_type::none};
case 3181:
return {.east = east_type::none, .north = north_type::side, .power = 13, .south = south_type::up, .west = west_type::up};
case 3182:
return {.east = east_type::none, .north = north_type::side, .power = 13, .south = south_type::up, .west = west_type::side};
case 3183:
return {.east = east_type::none, .north = north_type::side, .power = 13, .south = south_type::up, .west = west_type::none};
case 3184:
return {.east = east_type::none, .north = north_type::side, .power = 13, .south = south_type::side, .west = west_type::up};
case 3185:
return {.east = east_type::none, .north = north_type::side, .power = 13, .south = south_type::side, .west = west_type::side};
case 3186:
return {.east = east_type::none, .north = north_type::side, .power = 13, .south = south_type::side, .west = west_type::none};
case 3187:
return {.east = east_type::none, .north = north_type::side, .power = 13, .south = south_type::none, .west = west_type::up};
case 3188:
return {.east = east_type::none, .north = north_type::side, .power = 13, .south = south_type::none, .west = west_type::side};
case 3189:
return {.east = east_type::none, .north = north_type::side, .power = 13, .south = south_type::none, .west = west_type::none};
case 3190:
return {.east = east_type::none, .north = north_type::side, .power = 14, .south = south_type::up, .west = west_type::up};
case 3191:
return {.east = east_type::none, .north = north_type::side, .power = 14, .south = south_type::up, .west = west_type::side};
case 3192:
return {.east = east_type::none, .north = north_type::side, .power = 14, .south = south_type::up, .west = west_type::none};
case 3193:
return {.east = east_type::none, .north = north_type::side, .power = 14, .south = south_type::side, .west = west_type::up};
case 3194:
return {.east = east_type::none, .north = north_type::side, .power = 14, .south = south_type::side, .west = west_type::side};
case 3195:
return {.east = east_type::none, .north = north_type::side, .power = 14, .south = south_type::side, .west = west_type::none};
case 3196:
return {.east = east_type::none, .north = north_type::side, .power = 14, .south = south_type::none, .west = west_type::up};
case 3197:
return {.east = east_type::none, .north = north_type::side, .power = 14, .south = south_type::none, .west = west_type::side};
case 3198:
return {.east = east_type::none, .north = north_type::side, .power = 14, .south = south_type::none, .west = west_type::none};
case 3199:
return {.east = east_type::none, .north = north_type::side, .power = 15, .south = south_type::up, .west = west_type::up};
case 3200:
return {.east = east_type::none, .north = north_type::side, .power = 15, .south = south_type::up, .west = west_type::side};
case 3201:
return {.east = east_type::none, .north = north_type::side, .power = 15, .south = south_type::up, .west = west_type::none};
case 3202:
return {.east = east_type::none, .north = north_type::side, .power = 15, .south = south_type::side, .west = west_type::up};
case 3203:
return {.east = east_type::none, .north = north_type::side, .power = 15, .south = south_type::side, .west = west_type::side};
case 3204:
return {.east = east_type::none, .north = north_type::side, .power = 15, .south = south_type::side, .west = west_type::none};
case 3205:
return {.east = east_type::none, .north = north_type::side, .power = 15, .south = south_type::none, .west = west_type::up};
case 3206:
return {.east = east_type::none, .north = north_type::side, .power = 15, .south = south_type::none, .west = west_type::side};
case 3207:
return {.east = east_type::none, .north = north_type::side, .power = 15, .south = south_type::none, .west = west_type::none};
case 3208:
return {.east = east_type::none, .north = north_type::none, .power = 0, .south = south_type::up, .west = west_type::up};
case 3209:
return {.east = east_type::none, .north = north_type::none, .power = 0, .south = south_type::up, .west = west_type::side};
case 3210:
return {.east = east_type::none, .north = north_type::none, .power = 0, .south = south_type::up, .west = west_type::none};
case 3211:
return {.east = east_type::none, .north = north_type::none, .power = 0, .south = south_type::side, .west = west_type::up};
case 3212:
return {.east = east_type::none, .north = north_type::none, .power = 0, .south = south_type::side, .west = west_type::side};
case 3213:
return {.east = east_type::none, .north = north_type::none, .power = 0, .south = south_type::side, .west = west_type::none};
case 3214:
return {.east = east_type::none, .north = north_type::none, .power = 0, .south = south_type::none, .west = west_type::up};
case 3215:
return {.east = east_type::none, .north = north_type::none, .power = 0, .south = south_type::none, .west = west_type::side};
case 3216:
return {.east = east_type::none, .north = north_type::none, .power = 0, .south = south_type::none, .west = west_type::none};
case 3217:
return {.east = east_type::none, .north = north_type::none, .power = 1, .south = south_type::up, .west = west_type::up};
case 3218:
return {.east = east_type::none, .north = north_type::none, .power = 1, .south = south_type::up, .west = west_type::side};
case 3219:
return {.east = east_type::none, .north = north_type::none, .power = 1, .south = south_type::up, .west = west_type::none};
case 3220:
return {.east = east_type::none, .north = north_type::none, .power = 1, .south = south_type::side, .west = west_type::up};
case 3221:
return {.east = east_type::none, .north = north_type::none, .power = 1, .south = south_type::side, .west = west_type::side};
case 3222:
return {.east = east_type::none, .north = north_type::none, .power = 1, .south = south_type::side, .west = west_type::none};
case 3223:
return {.east = east_type::none, .north = north_type::none, .power = 1, .south = south_type::none, .west = west_type::up};
case 3224:
return {.east = east_type::none, .north = north_type::none, .power = 1, .south = south_type::none, .west = west_type::side};
case 3225:
return {.east = east_type::none, .north = north_type::none, .power = 1, .south = south_type::none, .west = west_type::none};
case 3226:
return {.east = east_type::none, .north = north_type::none, .power = 2, .south = south_type::up, .west = west_type::up};
case 3227:
return {.east = east_type::none, .north = north_type::none, .power = 2, .south = south_type::up, .west = west_type::side};
case 3228:
return {.east = east_type::none, .north = north_type::none, .power = 2, .south = south_type::up, .west = west_type::none};
case 3229:
return {.east = east_type::none, .north = north_type::none, .power = 2, .south = south_type::side, .west = west_type::up};
case 3230:
return {.east = east_type::none, .north = north_type::none, .power = 2, .south = south_type::side, .west = west_type::side};
case 3231:
return {.east = east_type::none, .north = north_type::none, .power = 2, .south = south_type::side, .west = west_type::none};
case 3232:
return {.east = east_type::none, .north = north_type::none, .power = 2, .south = south_type::none, .west = west_type::up};
case 3233:
return {.east = east_type::none, .north = north_type::none, .power = 2, .south = south_type::none, .west = west_type::side};
case 3234:
return {.east = east_type::none, .north = north_type::none, .power = 2, .south = south_type::none, .west = west_type::none};
case 3235:
return {.east = east_type::none, .north = north_type::none, .power = 3, .south = south_type::up, .west = west_type::up};
case 3236:
return {.east = east_type::none, .north = north_type::none, .power = 3, .south = south_type::up, .west = west_type::side};
case 3237:
return {.east = east_type::none, .north = north_type::none, .power = 3, .south = south_type::up, .west = west_type::none};
case 3238:
return {.east = east_type::none, .north = north_type::none, .power = 3, .south = south_type::side, .west = west_type::up};
case 3239:
return {.east = east_type::none, .north = north_type::none, .power = 3, .south = south_type::side, .west = west_type::side};
case 3240:
return {.east = east_type::none, .north = north_type::none, .power = 3, .south = south_type::side, .west = west_type::none};
case 3241:
return {.east = east_type::none, .north = north_type::none, .power = 3, .south = south_type::none, .west = west_type::up};
case 3242:
return {.east = east_type::none, .north = north_type::none, .power = 3, .south = south_type::none, .west = west_type::side};
case 3243:
return {.east = east_type::none, .north = north_type::none, .power = 3, .south = south_type::none, .west = west_type::none};
case 3244:
return {.east = east_type::none, .north = north_type::none, .power = 4, .south = south_type::up, .west = west_type::up};
case 3245:
return {.east = east_type::none, .north = north_type::none, .power = 4, .south = south_type::up, .west = west_type::side};
case 3246:
return {.east = east_type::none, .north = north_type::none, .power = 4, .south = south_type::up, .west = west_type::none};
case 3247:
return {.east = east_type::none, .north = north_type::none, .power = 4, .south = south_type::side, .west = west_type::up};
case 3248:
return {.east = east_type::none, .north = north_type::none, .power = 4, .south = south_type::side, .west = west_type::side};
case 3249:
return {.east = east_type::none, .north = north_type::none, .power = 4, .south = south_type::side, .west = west_type::none};
case 3250:
return {.east = east_type::none, .north = north_type::none, .power = 4, .south = south_type::none, .west = west_type::up};
case 3251:
return {.east = east_type::none, .north = north_type::none, .power = 4, .south = south_type::none, .west = west_type::side};
case 3252:
return {.east = east_type::none, .north = north_type::none, .power = 4, .south = south_type::none, .west = west_type::none};
case 3253:
return {.east = east_type::none, .north = north_type::none, .power = 5, .south = south_type::up, .west = west_type::up};
case 3254:
return {.east = east_type::none, .north = north_type::none, .power = 5, .south = south_type::up, .west = west_type::side};
case 3255:
return {.east = east_type::none, .north = north_type::none, .power = 5, .south = south_type::up, .west = west_type::none};
case 3256:
return {.east = east_type::none, .north = north_type::none, .power = 5, .south = south_type::side, .west = west_type::up};
case 3257:
return {.east = east_type::none, .north = north_type::none, .power = 5, .south = south_type::side, .west = west_type::side};
case 3258:
return {.east = east_type::none, .north = north_type::none, .power = 5, .south = south_type::side, .west = west_type::none};
case 3259:
return {.east = east_type::none, .north = north_type::none, .power = 5, .south = south_type::none, .west = west_type::up};
case 3260:
return {.east = east_type::none, .north = north_type::none, .power = 5, .south = south_type::none, .west = west_type::side};
case 3261:
return {.east = east_type::none, .north = north_type::none, .power = 5, .south = south_type::none, .west = west_type::none};
case 3262:
return {.east = east_type::none, .north = north_type::none, .power = 6, .south = south_type::up, .west = west_type::up};
case 3263:
return {.east = east_type::none, .north = north_type::none, .power = 6, .south = south_type::up, .west = west_type::side};
case 3264:
return {.east = east_type::none, .north = north_type::none, .power = 6, .south = south_type::up, .west = west_type::none};
case 3265:
return {.east = east_type::none, .north = north_type::none, .power = 6, .south = south_type::side, .west = west_type::up};
case 3266:
return {.east = east_type::none, .north = north_type::none, .power = 6, .south = south_type::side, .west = west_type::side};
case 3267:
return {.east = east_type::none, .north = north_type::none, .power = 6, .south = south_type::side, .west = west_type::none};
case 3268:
return {.east = east_type::none, .north = north_type::none, .power = 6, .south = south_type::none, .west = west_type::up};
case 3269:
return {.east = east_type::none, .north = north_type::none, .power = 6, .south = south_type::none, .west = west_type::side};
case 3270:
return {.east = east_type::none, .north = north_type::none, .power = 6, .south = south_type::none, .west = west_type::none};
case 3271:
return {.east = east_type::none, .north = north_type::none, .power = 7, .south = south_type::up, .west = west_type::up};
case 3272:
return {.east = east_type::none, .north = north_type::none, .power = 7, .south = south_type::up, .west = west_type::side};
case 3273:
return {.east = east_type::none, .north = north_type::none, .power = 7, .south = south_type::up, .west = west_type::none};
case 3274:
return {.east = east_type::none, .north = north_type::none, .power = 7, .south = south_type::side, .west = west_type::up};
case 3275:
return {.east = east_type::none, .north = north_type::none, .power = 7, .south = south_type::side, .west = west_type::side};
case 3276:
return {.east = east_type::none, .north = north_type::none, .power = 7, .south = south_type::side, .west = west_type::none};
case 3277:
return {.east = east_type::none, .north = north_type::none, .power = 7, .south = south_type::none, .west = west_type::up};
case 3278:
return {.east = east_type::none, .north = north_type::none, .power = 7, .south = south_type::none, .west = west_type::side};
case 3279:
return {.east = east_type::none, .north = north_type::none, .power = 7, .south = south_type::none, .west = west_type::none};
case 3280:
return {.east = east_type::none, .north = north_type::none, .power = 8, .south = south_type::up, .west = west_type::up};
case 3281:
return {.east = east_type::none, .north = north_type::none, .power = 8, .south = south_type::up, .west = west_type::side};
case 3282:
return {.east = east_type::none, .north = north_type::none, .power = 8, .south = south_type::up, .west = west_type::none};
case 3283:
return {.east = east_type::none, .north = north_type::none, .power = 8, .south = south_type::side, .west = west_type::up};
case 3284:
return {.east = east_type::none, .north = north_type::none, .power = 8, .south = south_type::side, .west = west_type::side};
case 3285:
return {.east = east_type::none, .north = north_type::none, .power = 8, .south = south_type::side, .west = west_type::none};
case 3286:
return {.east = east_type::none, .north = north_type::none, .power = 8, .south = south_type::none, .west = west_type::up};
case 3287:
return {.east = east_type::none, .north = north_type::none, .power = 8, .south = south_type::none, .west = west_type::side};
case 3288:
return {.east = east_type::none, .north = north_type::none, .power = 8, .south = south_type::none, .west = west_type::none};
case 3289:
return {.east = east_type::none, .north = north_type::none, .power = 9, .south = south_type::up, .west = west_type::up};
case 3290:
return {.east = east_type::none, .north = north_type::none, .power = 9, .south = south_type::up, .west = west_type::side};
case 3291:
return {.east = east_type::none, .north = north_type::none, .power = 9, .south = south_type::up, .west = west_type::none};
case 3292:
return {.east = east_type::none, .north = north_type::none, .power = 9, .south = south_type::side, .west = west_type::up};
case 3293:
return {.east = east_type::none, .north = north_type::none, .power = 9, .south = south_type::side, .west = west_type::side};
case 3294:
return {.east = east_type::none, .north = north_type::none, .power = 9, .south = south_type::side, .west = west_type::none};
case 3295:
return {.east = east_type::none, .north = north_type::none, .power = 9, .south = south_type::none, .west = west_type::up};
case 3296:
return {.east = east_type::none, .north = north_type::none, .power = 9, .south = south_type::none, .west = west_type::side};
case 3297:
return {.east = east_type::none, .north = north_type::none, .power = 9, .south = south_type::none, .west = west_type::none};
case 3298:
return {.east = east_type::none, .north = north_type::none, .power = 10, .south = south_type::up, .west = west_type::up};
case 3299:
return {.east = east_type::none, .north = north_type::none, .power = 10, .south = south_type::up, .west = west_type::side};
case 3300:
return {.east = east_type::none, .north = north_type::none, .power = 10, .south = south_type::up, .west = west_type::none};
case 3301:
return {.east = east_type::none, .north = north_type::none, .power = 10, .south = south_type::side, .west = west_type::up};
case 3302:
return {.east = east_type::none, .north = north_type::none, .power = 10, .south = south_type::side, .west = west_type::side};
case 3303:
return {.east = east_type::none, .north = north_type::none, .power = 10, .south = south_type::side, .west = west_type::none};
case 3304:
return {.east = east_type::none, .north = north_type::none, .power = 10, .south = south_type::none, .west = west_type::up};
case 3305:
return {.east = east_type::none, .north = north_type::none, .power = 10, .south = south_type::none, .west = west_type::side};
case 3306:
return {.east = east_type::none, .north = north_type::none, .power = 10, .south = south_type::none, .west = west_type::none};
case 3307:
return {.east = east_type::none, .north = north_type::none, .power = 11, .south = south_type::up, .west = west_type::up};
case 3308:
return {.east = east_type::none, .north = north_type::none, .power = 11, .south = south_type::up, .west = west_type::side};
case 3309:
return {.east = east_type::none, .north = north_type::none, .power = 11, .south = south_type::up, .west = west_type::none};
case 3310:
return {.east = east_type::none, .north = north_type::none, .power = 11, .south = south_type::side, .west = west_type::up};
case 3311:
return {.east = east_type::none, .north = north_type::none, .power = 11, .south = south_type::side, .west = west_type::side};
case 3312:
return {.east = east_type::none, .north = north_type::none, .power = 11, .south = south_type::side, .west = west_type::none};
case 3313:
return {.east = east_type::none, .north = north_type::none, .power = 11, .south = south_type::none, .west = west_type::up};
case 3314:
return {.east = east_type::none, .north = north_type::none, .power = 11, .south = south_type::none, .west = west_type::side};
case 3315:
return {.east = east_type::none, .north = north_type::none, .power = 11, .south = south_type::none, .west = west_type::none};
case 3316:
return {.east = east_type::none, .north = north_type::none, .power = 12, .south = south_type::up, .west = west_type::up};
case 3317:
return {.east = east_type::none, .north = north_type::none, .power = 12, .south = south_type::up, .west = west_type::side};
case 3318:
return {.east = east_type::none, .north = north_type::none, .power = 12, .south = south_type::up, .west = west_type::none};
case 3319:
return {.east = east_type::none, .north = north_type::none, .power = 12, .south = south_type::side, .west = west_type::up};
case 3320:
return {.east = east_type::none, .north = north_type::none, .power = 12, .south = south_type::side, .west = west_type::side};
case 3321:
return {.east = east_type::none, .north = north_type::none, .power = 12, .south = south_type::side, .west = west_type::none};
case 3322:
return {.east = east_type::none, .north = north_type::none, .power = 12, .south = south_type::none, .west = west_type::up};
case 3323:
return {.east = east_type::none, .north = north_type::none, .power = 12, .south = south_type::none, .west = west_type::side};
case 3324:
return {.east = east_type::none, .north = north_type::none, .power = 12, .south = south_type::none, .west = west_type::none};
case 3325:
return {.east = east_type::none, .north = north_type::none, .power = 13, .south = south_type::up, .west = west_type::up};
case 3326:
return {.east = east_type::none, .north = north_type::none, .power = 13, .south = south_type::up, .west = west_type::side};
case 3327:
return {.east = east_type::none, .north = north_type::none, .power = 13, .south = south_type::up, .west = west_type::none};
case 3328:
return {.east = east_type::none, .north = north_type::none, .power = 13, .south = south_type::side, .west = west_type::up};
case 3329:
return {.east = east_type::none, .north = north_type::none, .power = 13, .south = south_type::side, .west = west_type::side};
case 3330:
return {.east = east_type::none, .north = north_type::none, .power = 13, .south = south_type::side, .west = west_type::none};
case 3331:
return {.east = east_type::none, .north = north_type::none, .power = 13, .south = south_type::none, .west = west_type::up};
case 3332:
return {.east = east_type::none, .north = north_type::none, .power = 13, .south = south_type::none, .west = west_type::side};
case 3333:
return {.east = east_type::none, .north = north_type::none, .power = 13, .south = south_type::none, .west = west_type::none};
case 3334:
return {.east = east_type::none, .north = north_type::none, .power = 14, .south = south_type::up, .west = west_type::up};
case 3335:
return {.east = east_type::none, .north = north_type::none, .power = 14, .south = south_type::up, .west = west_type::side};
case 3336:
return {.east = east_type::none, .north = north_type::none, .power = 14, .south = south_type::up, .west = west_type::none};
case 3337:
return {.east = east_type::none, .north = north_type::none, .power = 14, .south = south_type::side, .west = west_type::up};
case 3338:
return {.east = east_type::none, .north = north_type::none, .power = 14, .south = south_type::side, .west = west_type::side};
case 3339:
return {.east = east_type::none, .north = north_type::none, .power = 14, .south = south_type::side, .west = west_type::none};
case 3340:
return {.east = east_type::none, .north = north_type::none, .power = 14, .south = south_type::none, .west = west_type::up};
case 3341:
return {.east = east_type::none, .north = north_type::none, .power = 14, .south = south_type::none, .west = west_type::side};
case 3342:
return {.east = east_type::none, .north = north_type::none, .power = 14, .south = south_type::none, .west = west_type::none};
case 3343:
return {.east = east_type::none, .north = north_type::none, .power = 15, .south = south_type::up, .west = west_type::up};
case 3344:
return {.east = east_type::none, .north = north_type::none, .power = 15, .south = south_type::up, .west = west_type::side};
case 3345:
return {.east = east_type::none, .north = north_type::none, .power = 15, .south = south_type::up, .west = west_type::none};
case 3346:
return {.east = east_type::none, .north = north_type::none, .power = 15, .south = south_type::side, .west = west_type::up};
case 3347:
return {.east = east_type::none, .north = north_type::none, .power = 15, .south = south_type::side, .west = west_type::side};
case 3348:
return {.east = east_type::none, .north = north_type::none, .power = 15, .south = south_type::side, .west = west_type::none};
case 3349:
return {.east = east_type::none, .north = north_type::none, .power = 15, .south = south_type::none, .west = west_type::up};
case 3350:
return {.east = east_type::none, .north = north_type::none, .power = 15, .south = south_type::none, .west = west_type::side};
case 3351:
return {.east = east_type::none, .north = north_type::none, .power = 15, .south = south_type::none, .west = west_type::none};
}}
constexpr std::string_view to_string() const
{switch (east)
{
case east_type::up:
switch (north)
{
case north_type::up:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:0:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:0:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:0:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:0:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:0:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:0:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:0:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:0:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:0:none:none";
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:1:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:1:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:1:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:1:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:1:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:1:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:1:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:1:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:1:none:none";
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:2:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:2:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:2:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:2:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:2:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:2:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:2:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:2:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:2:none:none";
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:3:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:3:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:3:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:3:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:3:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:3:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:3:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:3:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:3:none:none";
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:4:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:4:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:4:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:4:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:4:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:4:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:4:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:4:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:4:none:none";
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:5:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:5:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:5:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:5:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:5:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:5:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:5:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:5:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:5:none:none";
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:6:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:6:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:6:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:6:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:6:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:6:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:6:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:6:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:6:none:none";
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:7:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:7:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:7:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:7:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:7:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:7:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:7:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:7:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:7:none:none";
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:8:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:8:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:8:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:8:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:8:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:8:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:8:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:8:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:8:none:none";
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:9:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:9:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:9:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:9:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:9:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:9:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:9:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:9:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:9:none:none";
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:10:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:10:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:10:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:10:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:10:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:10:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:10:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:10:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:10:none:none";
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:11:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:11:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:11:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:11:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:11:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:11:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:11:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:11:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:11:none:none";
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:12:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:12:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:12:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:12:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:12:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:12:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:12:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:12:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:12:none:none";
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:13:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:13:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:13:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:13:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:13:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:13:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:13:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:13:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:13:none:none";
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:14:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:14:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:14:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:14:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:14:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:14:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:14:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:14:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:14:none:none";
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:15:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:15:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:15:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:15:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:15:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:15:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:up:15:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:up:15:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:up:15:none:none";
}
}
}
case north_type::side:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:0:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:0:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:0:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:0:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:0:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:0:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:0:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:0:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:0:none:none";
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:1:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:1:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:1:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:1:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:1:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:1:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:1:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:1:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:1:none:none";
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:2:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:2:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:2:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:2:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:2:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:2:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:2:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:2:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:2:none:none";
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:3:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:3:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:3:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:3:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:3:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:3:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:3:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:3:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:3:none:none";
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:4:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:4:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:4:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:4:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:4:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:4:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:4:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:4:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:4:none:none";
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:5:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:5:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:5:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:5:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:5:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:5:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:5:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:5:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:5:none:none";
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:6:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:6:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:6:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:6:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:6:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:6:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:6:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:6:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:6:none:none";
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:7:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:7:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:7:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:7:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:7:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:7:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:7:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:7:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:7:none:none";
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:8:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:8:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:8:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:8:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:8:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:8:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:8:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:8:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:8:none:none";
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:9:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:9:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:9:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:9:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:9:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:9:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:9:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:9:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:9:none:none";
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:10:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:10:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:10:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:10:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:10:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:10:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:10:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:10:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:10:none:none";
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:11:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:11:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:11:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:11:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:11:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:11:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:11:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:11:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:11:none:none";
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:12:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:12:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:12:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:12:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:12:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:12:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:12:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:12:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:12:none:none";
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:13:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:13:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:13:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:13:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:13:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:13:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:13:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:13:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:13:none:none";
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:14:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:14:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:14:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:14:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:14:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:14:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:14:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:14:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:14:none:none";
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:15:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:15:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:15:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:15:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:15:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:15:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:side:15:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:side:15:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:side:15:none:none";
}
}
}
case north_type::none:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:0:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:0:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:0:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:0:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:0:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:0:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:0:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:0:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:0:none:none";
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:1:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:1:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:1:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:1:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:1:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:1:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:1:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:1:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:1:none:none";
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:2:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:2:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:2:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:2:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:2:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:2:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:2:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:2:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:2:none:none";
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:3:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:3:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:3:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:3:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:3:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:3:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:3:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:3:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:3:none:none";
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:4:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:4:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:4:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:4:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:4:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:4:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:4:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:4:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:4:none:none";
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:5:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:5:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:5:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:5:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:5:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:5:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:5:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:5:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:5:none:none";
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:6:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:6:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:6:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:6:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:6:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:6:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:6:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:6:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:6:none:none";
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:7:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:7:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:7:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:7:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:7:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:7:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:7:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:7:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:7:none:none";
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:8:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:8:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:8:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:8:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:8:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:8:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:8:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:8:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:8:none:none";
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:9:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:9:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:9:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:9:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:9:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:9:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:9:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:9:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:9:none:none";
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:10:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:10:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:10:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:10:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:10:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:10:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:10:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:10:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:10:none:none";
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:11:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:11:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:11:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:11:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:11:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:11:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:11:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:11:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:11:none:none";
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:12:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:12:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:12:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:12:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:12:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:12:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:12:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:12:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:12:none:none";
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:13:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:13:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:13:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:13:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:13:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:13:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:13:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:13:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:13:none:none";
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:14:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:14:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:14:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:14:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:14:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:14:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:14:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:14:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:14:none:none";
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:15:up:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:15:up:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:15:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:15:side:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:15:side:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:15:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:up:none:15:none:up";
case west_type::side:
return "minecraft:redstone_wire:up:none:15:none:side";
case west_type::none:
return "minecraft:redstone_wire:up:none:15:none:none";
}
}
}
}
case east_type::side:
switch (north)
{
case north_type::up:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:0:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:0:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:0:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:0:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:0:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:0:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:0:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:0:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:0:none:none";
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:1:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:1:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:1:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:1:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:1:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:1:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:1:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:1:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:1:none:none";
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:2:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:2:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:2:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:2:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:2:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:2:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:2:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:2:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:2:none:none";
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:3:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:3:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:3:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:3:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:3:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:3:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:3:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:3:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:3:none:none";
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:4:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:4:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:4:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:4:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:4:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:4:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:4:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:4:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:4:none:none";
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:5:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:5:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:5:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:5:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:5:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:5:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:5:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:5:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:5:none:none";
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:6:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:6:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:6:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:6:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:6:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:6:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:6:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:6:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:6:none:none";
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:7:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:7:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:7:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:7:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:7:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:7:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:7:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:7:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:7:none:none";
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:8:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:8:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:8:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:8:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:8:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:8:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:8:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:8:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:8:none:none";
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:9:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:9:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:9:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:9:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:9:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:9:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:9:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:9:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:9:none:none";
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:10:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:10:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:10:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:10:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:10:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:10:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:10:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:10:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:10:none:none";
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:11:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:11:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:11:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:11:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:11:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:11:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:11:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:11:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:11:none:none";
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:12:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:12:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:12:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:12:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:12:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:12:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:12:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:12:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:12:none:none";
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:13:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:13:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:13:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:13:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:13:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:13:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:13:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:13:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:13:none:none";
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:14:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:14:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:14:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:14:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:14:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:14:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:14:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:14:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:14:none:none";
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:15:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:15:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:15:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:15:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:15:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:15:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:up:15:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:up:15:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:up:15:none:none";
}
}
}
case north_type::side:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:0:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:0:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:0:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:0:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:0:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:0:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:0:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:0:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:0:none:none";
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:1:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:1:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:1:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:1:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:1:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:1:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:1:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:1:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:1:none:none";
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:2:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:2:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:2:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:2:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:2:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:2:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:2:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:2:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:2:none:none";
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:3:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:3:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:3:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:3:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:3:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:3:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:3:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:3:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:3:none:none";
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:4:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:4:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:4:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:4:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:4:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:4:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:4:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:4:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:4:none:none";
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:5:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:5:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:5:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:5:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:5:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:5:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:5:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:5:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:5:none:none";
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:6:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:6:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:6:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:6:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:6:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:6:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:6:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:6:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:6:none:none";
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:7:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:7:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:7:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:7:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:7:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:7:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:7:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:7:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:7:none:none";
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:8:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:8:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:8:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:8:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:8:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:8:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:8:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:8:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:8:none:none";
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:9:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:9:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:9:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:9:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:9:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:9:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:9:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:9:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:9:none:none";
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:10:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:10:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:10:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:10:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:10:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:10:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:10:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:10:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:10:none:none";
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:11:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:11:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:11:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:11:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:11:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:11:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:11:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:11:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:11:none:none";
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:12:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:12:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:12:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:12:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:12:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:12:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:12:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:12:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:12:none:none";
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:13:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:13:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:13:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:13:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:13:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:13:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:13:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:13:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:13:none:none";
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:14:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:14:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:14:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:14:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:14:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:14:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:14:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:14:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:14:none:none";
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:15:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:15:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:15:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:15:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:15:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:15:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:side:15:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:side:15:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:side:15:none:none";
}
}
}
case north_type::none:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:0:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:0:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:0:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:0:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:0:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:0:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:0:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:0:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:0:none:none";
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:1:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:1:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:1:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:1:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:1:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:1:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:1:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:1:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:1:none:none";
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:2:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:2:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:2:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:2:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:2:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:2:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:2:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:2:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:2:none:none";
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:3:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:3:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:3:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:3:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:3:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:3:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:3:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:3:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:3:none:none";
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:4:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:4:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:4:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:4:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:4:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:4:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:4:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:4:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:4:none:none";
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:5:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:5:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:5:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:5:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:5:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:5:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:5:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:5:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:5:none:none";
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:6:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:6:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:6:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:6:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:6:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:6:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:6:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:6:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:6:none:none";
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:7:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:7:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:7:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:7:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:7:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:7:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:7:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:7:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:7:none:none";
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:8:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:8:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:8:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:8:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:8:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:8:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:8:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:8:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:8:none:none";
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:9:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:9:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:9:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:9:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:9:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:9:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:9:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:9:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:9:none:none";
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:10:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:10:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:10:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:10:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:10:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:10:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:10:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:10:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:10:none:none";
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:11:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:11:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:11:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:11:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:11:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:11:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:11:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:11:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:11:none:none";
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:12:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:12:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:12:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:12:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:12:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:12:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:12:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:12:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:12:none:none";
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:13:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:13:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:13:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:13:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:13:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:13:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:13:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:13:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:13:none:none";
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:14:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:14:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:14:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:14:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:14:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:14:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:14:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:14:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:14:none:none";
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:15:up:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:15:up:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:15:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:15:side:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:15:side:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:15:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:side:none:15:none:up";
case west_type::side:
return "minecraft:redstone_wire:side:none:15:none:side";
case west_type::none:
return "minecraft:redstone_wire:side:none:15:none:none";
}
}
}
}
case east_type::none:
switch (north)
{
case north_type::up:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:0:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:0:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:0:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:0:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:0:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:0:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:0:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:0:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:0:none:none";
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:1:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:1:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:1:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:1:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:1:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:1:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:1:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:1:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:1:none:none";
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:2:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:2:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:2:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:2:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:2:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:2:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:2:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:2:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:2:none:none";
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:3:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:3:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:3:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:3:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:3:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:3:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:3:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:3:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:3:none:none";
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:4:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:4:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:4:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:4:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:4:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:4:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:4:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:4:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:4:none:none";
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:5:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:5:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:5:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:5:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:5:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:5:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:5:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:5:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:5:none:none";
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:6:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:6:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:6:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:6:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:6:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:6:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:6:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:6:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:6:none:none";
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:7:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:7:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:7:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:7:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:7:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:7:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:7:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:7:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:7:none:none";
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:8:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:8:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:8:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:8:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:8:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:8:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:8:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:8:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:8:none:none";
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:9:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:9:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:9:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:9:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:9:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:9:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:9:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:9:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:9:none:none";
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:10:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:10:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:10:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:10:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:10:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:10:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:10:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:10:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:10:none:none";
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:11:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:11:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:11:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:11:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:11:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:11:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:11:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:11:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:11:none:none";
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:12:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:12:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:12:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:12:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:12:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:12:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:12:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:12:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:12:none:none";
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:13:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:13:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:13:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:13:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:13:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:13:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:13:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:13:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:13:none:none";
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:14:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:14:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:14:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:14:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:14:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:14:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:14:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:14:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:14:none:none";
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:15:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:15:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:15:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:15:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:15:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:15:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:up:15:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:up:15:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:up:15:none:none";
}
}
}
case north_type::side:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:0:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:0:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:0:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:0:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:0:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:0:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:0:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:0:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:0:none:none";
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:1:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:1:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:1:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:1:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:1:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:1:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:1:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:1:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:1:none:none";
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:2:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:2:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:2:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:2:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:2:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:2:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:2:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:2:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:2:none:none";
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:3:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:3:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:3:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:3:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:3:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:3:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:3:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:3:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:3:none:none";
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:4:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:4:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:4:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:4:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:4:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:4:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:4:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:4:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:4:none:none";
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:5:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:5:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:5:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:5:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:5:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:5:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:5:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:5:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:5:none:none";
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:6:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:6:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:6:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:6:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:6:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:6:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:6:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:6:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:6:none:none";
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:7:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:7:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:7:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:7:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:7:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:7:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:7:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:7:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:7:none:none";
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:8:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:8:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:8:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:8:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:8:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:8:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:8:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:8:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:8:none:none";
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:9:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:9:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:9:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:9:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:9:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:9:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:9:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:9:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:9:none:none";
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:10:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:10:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:10:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:10:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:10:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:10:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:10:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:10:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:10:none:none";
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:11:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:11:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:11:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:11:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:11:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:11:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:11:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:11:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:11:none:none";
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:12:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:12:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:12:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:12:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:12:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:12:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:12:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:12:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:12:none:none";
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:13:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:13:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:13:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:13:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:13:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:13:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:13:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:13:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:13:none:none";
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:14:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:14:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:14:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:14:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:14:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:14:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:14:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:14:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:14:none:none";
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:15:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:15:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:15:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:15:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:15:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:15:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:side:15:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:side:15:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:side:15:none:none";
}
}
}
case north_type::none:
switch (power)
{
case 0:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:0:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:0:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:0:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:0:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:0:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:0:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:0:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:0:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:0:none:none";
}
}
case 1:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:1:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:1:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:1:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:1:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:1:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:1:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:1:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:1:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:1:none:none";
}
}
case 2:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:2:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:2:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:2:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:2:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:2:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:2:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:2:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:2:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:2:none:none";
}
}
case 3:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:3:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:3:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:3:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:3:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:3:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:3:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:3:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:3:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:3:none:none";
}
}
case 4:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:4:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:4:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:4:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:4:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:4:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:4:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:4:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:4:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:4:none:none";
}
}
case 5:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:5:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:5:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:5:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:5:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:5:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:5:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:5:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:5:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:5:none:none";
}
}
case 6:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:6:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:6:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:6:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:6:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:6:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:6:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:6:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:6:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:6:none:none";
}
}
case 7:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:7:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:7:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:7:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:7:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:7:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:7:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:7:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:7:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:7:none:none";
}
}
case 8:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:8:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:8:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:8:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:8:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:8:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:8:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:8:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:8:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:8:none:none";
}
}
case 9:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:9:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:9:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:9:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:9:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:9:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:9:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:9:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:9:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:9:none:none";
}
}
case 10:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:10:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:10:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:10:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:10:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:10:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:10:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:10:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:10:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:10:none:none";
}
}
case 11:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:11:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:11:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:11:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:11:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:11:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:11:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:11:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:11:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:11:none:none";
}
}
case 12:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:12:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:12:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:12:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:12:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:12:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:12:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:12:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:12:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:12:none:none";
}
}
case 13:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:13:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:13:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:13:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:13:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:13:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:13:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:13:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:13:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:13:none:none";
}
}
case 14:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:14:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:14:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:14:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:14:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:14:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:14:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:14:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:14:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:14:none:none";
}
}
case 15:
switch (south)
{
case south_type::up:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:15:up:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:15:up:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:15:up:none";
}
case south_type::side:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:15:side:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:15:side:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:15:side:none";
}
case south_type::none:
switch (west)
{
case west_type::up:
return "minecraft:redstone_wire:none:none:15:none:up";
case west_type::side:
return "minecraft:redstone_wire:none:none:15:none:side";
case west_type::none:
return "minecraft:redstone_wire:none:none:15:none:none";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
