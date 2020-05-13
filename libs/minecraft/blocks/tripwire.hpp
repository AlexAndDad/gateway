#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct tripwire
{bool attached = false;
bool disarmed = false;
bool east = false;
bool north = false;
bool powered = false;
bool south = false;
bool west = false;
constexpr block_id_type to_id() const {
switch (attached)
{
case true:
switch (disarmed)
{
case true:
switch (east)
{
case true:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5259;
case false:
return 5260;
}
case false:
switch (west)
{
case true:
return 5261;
case false:
return 5262;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5263;
case false:
return 5264;
}
case false:
switch (west)
{
case true:
return 5265;
case false:
return 5266;
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5267;
case false:
return 5268;
}
case false:
switch (west)
{
case true:
return 5269;
case false:
return 5270;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5271;
case false:
return 5272;
}
case false:
switch (west)
{
case true:
return 5273;
case false:
return 5274;
}
}
}
}
case false:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5275;
case false:
return 5276;
}
case false:
switch (west)
{
case true:
return 5277;
case false:
return 5278;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5279;
case false:
return 5280;
}
case false:
switch (west)
{
case true:
return 5281;
case false:
return 5282;
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5283;
case false:
return 5284;
}
case false:
switch (west)
{
case true:
return 5285;
case false:
return 5286;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5287;
case false:
return 5288;
}
case false:
switch (west)
{
case true:
return 5289;
case false:
return 5290;
}
}
}
}
}
case false:
switch (east)
{
case true:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5291;
case false:
return 5292;
}
case false:
switch (west)
{
case true:
return 5293;
case false:
return 5294;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5295;
case false:
return 5296;
}
case false:
switch (west)
{
case true:
return 5297;
case false:
return 5298;
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5299;
case false:
return 5300;
}
case false:
switch (west)
{
case true:
return 5301;
case false:
return 5302;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5303;
case false:
return 5304;
}
case false:
switch (west)
{
case true:
return 5305;
case false:
return 5306;
}
}
}
}
case false:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5307;
case false:
return 5308;
}
case false:
switch (west)
{
case true:
return 5309;
case false:
return 5310;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5311;
case false:
return 5312;
}
case false:
switch (west)
{
case true:
return 5313;
case false:
return 5314;
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5315;
case false:
return 5316;
}
case false:
switch (west)
{
case true:
return 5317;
case false:
return 5318;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5319;
case false:
return 5320;
}
case false:
switch (west)
{
case true:
return 5321;
case false:
return 5322;
}
}
}
}
}
}
case false:
switch (disarmed)
{
case true:
switch (east)
{
case true:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5323;
case false:
return 5324;
}
case false:
switch (west)
{
case true:
return 5325;
case false:
return 5326;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5327;
case false:
return 5328;
}
case false:
switch (west)
{
case true:
return 5329;
case false:
return 5330;
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5331;
case false:
return 5332;
}
case false:
switch (west)
{
case true:
return 5333;
case false:
return 5334;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5335;
case false:
return 5336;
}
case false:
switch (west)
{
case true:
return 5337;
case false:
return 5338;
}
}
}
}
case false:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5339;
case false:
return 5340;
}
case false:
switch (west)
{
case true:
return 5341;
case false:
return 5342;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5343;
case false:
return 5344;
}
case false:
switch (west)
{
case true:
return 5345;
case false:
return 5346;
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5347;
case false:
return 5348;
}
case false:
switch (west)
{
case true:
return 5349;
case false:
return 5350;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5351;
case false:
return 5352;
}
case false:
switch (west)
{
case true:
return 5353;
case false:
return 5354;
}
}
}
}
}
case false:
switch (east)
{
case true:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5355;
case false:
return 5356;
}
case false:
switch (west)
{
case true:
return 5357;
case false:
return 5358;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5359;
case false:
return 5360;
}
case false:
switch (west)
{
case true:
return 5361;
case false:
return 5362;
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5363;
case false:
return 5364;
}
case false:
switch (west)
{
case true:
return 5365;
case false:
return 5366;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5367;
case false:
return 5368;
}
case false:
switch (west)
{
case true:
return 5369;
case false:
return 5370;
}
}
}
}
case false:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5371;
case false:
return 5372;
}
case false:
switch (west)
{
case true:
return 5373;
case false:
return 5374;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5375;
case false:
return 5376;
}
case false:
switch (west)
{
case true:
return 5377;
case false:
return 5378;
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return 5379;
case false:
return 5380;
}
case false:
switch (west)
{
case true:
return 5381;
case false:
return 5382;
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return 5383;
case false:
return 5384;
}
case false:
switch (west)
{
case true:
return 5385;
case false:
return 5386;
}
}
}
}
}
}
}
}
constexpr static tripwire from_id(block_id_type id)
{
switch (id)
{
case 5259:
return {.attached = true, .disarmed = true, .east = true, .north = true, .powered = true, .south = true, .west = true};
case 5260:
return {.attached = true, .disarmed = true, .east = true, .north = true, .powered = true, .south = true, .west = false};
case 5261:
return {.attached = true, .disarmed = true, .east = true, .north = true, .powered = true, .south = false, .west = true};
case 5262:
return {.attached = true, .disarmed = true, .east = true, .north = true, .powered = true, .south = false, .west = false};
case 5263:
return {.attached = true, .disarmed = true, .east = true, .north = true, .powered = false, .south = true, .west = true};
case 5264:
return {.attached = true, .disarmed = true, .east = true, .north = true, .powered = false, .south = true, .west = false};
case 5265:
return {.attached = true, .disarmed = true, .east = true, .north = true, .powered = false, .south = false, .west = true};
case 5266:
return {.attached = true, .disarmed = true, .east = true, .north = true, .powered = false, .south = false, .west = false};
case 5267:
return {.attached = true, .disarmed = true, .east = true, .north = false, .powered = true, .south = true, .west = true};
case 5268:
return {.attached = true, .disarmed = true, .east = true, .north = false, .powered = true, .south = true, .west = false};
case 5269:
return {.attached = true, .disarmed = true, .east = true, .north = false, .powered = true, .south = false, .west = true};
case 5270:
return {.attached = true, .disarmed = true, .east = true, .north = false, .powered = true, .south = false, .west = false};
case 5271:
return {.attached = true, .disarmed = true, .east = true, .north = false, .powered = false, .south = true, .west = true};
case 5272:
return {.attached = true, .disarmed = true, .east = true, .north = false, .powered = false, .south = true, .west = false};
case 5273:
return {.attached = true, .disarmed = true, .east = true, .north = false, .powered = false, .south = false, .west = true};
case 5274:
return {.attached = true, .disarmed = true, .east = true, .north = false, .powered = false, .south = false, .west = false};
case 5275:
return {.attached = true, .disarmed = true, .east = false, .north = true, .powered = true, .south = true, .west = true};
case 5276:
return {.attached = true, .disarmed = true, .east = false, .north = true, .powered = true, .south = true, .west = false};
case 5277:
return {.attached = true, .disarmed = true, .east = false, .north = true, .powered = true, .south = false, .west = true};
case 5278:
return {.attached = true, .disarmed = true, .east = false, .north = true, .powered = true, .south = false, .west = false};
case 5279:
return {.attached = true, .disarmed = true, .east = false, .north = true, .powered = false, .south = true, .west = true};
case 5280:
return {.attached = true, .disarmed = true, .east = false, .north = true, .powered = false, .south = true, .west = false};
case 5281:
return {.attached = true, .disarmed = true, .east = false, .north = true, .powered = false, .south = false, .west = true};
case 5282:
return {.attached = true, .disarmed = true, .east = false, .north = true, .powered = false, .south = false, .west = false};
case 5283:
return {.attached = true, .disarmed = true, .east = false, .north = false, .powered = true, .south = true, .west = true};
case 5284:
return {.attached = true, .disarmed = true, .east = false, .north = false, .powered = true, .south = true, .west = false};
case 5285:
return {.attached = true, .disarmed = true, .east = false, .north = false, .powered = true, .south = false, .west = true};
case 5286:
return {.attached = true, .disarmed = true, .east = false, .north = false, .powered = true, .south = false, .west = false};
case 5287:
return {.attached = true, .disarmed = true, .east = false, .north = false, .powered = false, .south = true, .west = true};
case 5288:
return {.attached = true, .disarmed = true, .east = false, .north = false, .powered = false, .south = true, .west = false};
case 5289:
return {.attached = true, .disarmed = true, .east = false, .north = false, .powered = false, .south = false, .west = true};
case 5290:
return {.attached = true, .disarmed = true, .east = false, .north = false, .powered = false, .south = false, .west = false};
case 5291:
return {.attached = true, .disarmed = false, .east = true, .north = true, .powered = true, .south = true, .west = true};
case 5292:
return {.attached = true, .disarmed = false, .east = true, .north = true, .powered = true, .south = true, .west = false};
case 5293:
return {.attached = true, .disarmed = false, .east = true, .north = true, .powered = true, .south = false, .west = true};
case 5294:
return {.attached = true, .disarmed = false, .east = true, .north = true, .powered = true, .south = false, .west = false};
case 5295:
return {.attached = true, .disarmed = false, .east = true, .north = true, .powered = false, .south = true, .west = true};
case 5296:
return {.attached = true, .disarmed = false, .east = true, .north = true, .powered = false, .south = true, .west = false};
case 5297:
return {.attached = true, .disarmed = false, .east = true, .north = true, .powered = false, .south = false, .west = true};
case 5298:
return {.attached = true, .disarmed = false, .east = true, .north = true, .powered = false, .south = false, .west = false};
case 5299:
return {.attached = true, .disarmed = false, .east = true, .north = false, .powered = true, .south = true, .west = true};
case 5300:
return {.attached = true, .disarmed = false, .east = true, .north = false, .powered = true, .south = true, .west = false};
case 5301:
return {.attached = true, .disarmed = false, .east = true, .north = false, .powered = true, .south = false, .west = true};
case 5302:
return {.attached = true, .disarmed = false, .east = true, .north = false, .powered = true, .south = false, .west = false};
case 5303:
return {.attached = true, .disarmed = false, .east = true, .north = false, .powered = false, .south = true, .west = true};
case 5304:
return {.attached = true, .disarmed = false, .east = true, .north = false, .powered = false, .south = true, .west = false};
case 5305:
return {.attached = true, .disarmed = false, .east = true, .north = false, .powered = false, .south = false, .west = true};
case 5306:
return {.attached = true, .disarmed = false, .east = true, .north = false, .powered = false, .south = false, .west = false};
case 5307:
return {.attached = true, .disarmed = false, .east = false, .north = true, .powered = true, .south = true, .west = true};
case 5308:
return {.attached = true, .disarmed = false, .east = false, .north = true, .powered = true, .south = true, .west = false};
case 5309:
return {.attached = true, .disarmed = false, .east = false, .north = true, .powered = true, .south = false, .west = true};
case 5310:
return {.attached = true, .disarmed = false, .east = false, .north = true, .powered = true, .south = false, .west = false};
case 5311:
return {.attached = true, .disarmed = false, .east = false, .north = true, .powered = false, .south = true, .west = true};
case 5312:
return {.attached = true, .disarmed = false, .east = false, .north = true, .powered = false, .south = true, .west = false};
case 5313:
return {.attached = true, .disarmed = false, .east = false, .north = true, .powered = false, .south = false, .west = true};
case 5314:
return {.attached = true, .disarmed = false, .east = false, .north = true, .powered = false, .south = false, .west = false};
case 5315:
return {.attached = true, .disarmed = false, .east = false, .north = false, .powered = true, .south = true, .west = true};
case 5316:
return {.attached = true, .disarmed = false, .east = false, .north = false, .powered = true, .south = true, .west = false};
case 5317:
return {.attached = true, .disarmed = false, .east = false, .north = false, .powered = true, .south = false, .west = true};
case 5318:
return {.attached = true, .disarmed = false, .east = false, .north = false, .powered = true, .south = false, .west = false};
case 5319:
return {.attached = true, .disarmed = false, .east = false, .north = false, .powered = false, .south = true, .west = true};
case 5320:
return {.attached = true, .disarmed = false, .east = false, .north = false, .powered = false, .south = true, .west = false};
case 5321:
return {.attached = true, .disarmed = false, .east = false, .north = false, .powered = false, .south = false, .west = true};
case 5322:
return {.attached = true, .disarmed = false, .east = false, .north = false, .powered = false, .south = false, .west = false};
case 5323:
return {.attached = false, .disarmed = true, .east = true, .north = true, .powered = true, .south = true, .west = true};
case 5324:
return {.attached = false, .disarmed = true, .east = true, .north = true, .powered = true, .south = true, .west = false};
case 5325:
return {.attached = false, .disarmed = true, .east = true, .north = true, .powered = true, .south = false, .west = true};
case 5326:
return {.attached = false, .disarmed = true, .east = true, .north = true, .powered = true, .south = false, .west = false};
case 5327:
return {.attached = false, .disarmed = true, .east = true, .north = true, .powered = false, .south = true, .west = true};
case 5328:
return {.attached = false, .disarmed = true, .east = true, .north = true, .powered = false, .south = true, .west = false};
case 5329:
return {.attached = false, .disarmed = true, .east = true, .north = true, .powered = false, .south = false, .west = true};
case 5330:
return {.attached = false, .disarmed = true, .east = true, .north = true, .powered = false, .south = false, .west = false};
case 5331:
return {.attached = false, .disarmed = true, .east = true, .north = false, .powered = true, .south = true, .west = true};
case 5332:
return {.attached = false, .disarmed = true, .east = true, .north = false, .powered = true, .south = true, .west = false};
case 5333:
return {.attached = false, .disarmed = true, .east = true, .north = false, .powered = true, .south = false, .west = true};
case 5334:
return {.attached = false, .disarmed = true, .east = true, .north = false, .powered = true, .south = false, .west = false};
case 5335:
return {.attached = false, .disarmed = true, .east = true, .north = false, .powered = false, .south = true, .west = true};
case 5336:
return {.attached = false, .disarmed = true, .east = true, .north = false, .powered = false, .south = true, .west = false};
case 5337:
return {.attached = false, .disarmed = true, .east = true, .north = false, .powered = false, .south = false, .west = true};
case 5338:
return {.attached = false, .disarmed = true, .east = true, .north = false, .powered = false, .south = false, .west = false};
case 5339:
return {.attached = false, .disarmed = true, .east = false, .north = true, .powered = true, .south = true, .west = true};
case 5340:
return {.attached = false, .disarmed = true, .east = false, .north = true, .powered = true, .south = true, .west = false};
case 5341:
return {.attached = false, .disarmed = true, .east = false, .north = true, .powered = true, .south = false, .west = true};
case 5342:
return {.attached = false, .disarmed = true, .east = false, .north = true, .powered = true, .south = false, .west = false};
case 5343:
return {.attached = false, .disarmed = true, .east = false, .north = true, .powered = false, .south = true, .west = true};
case 5344:
return {.attached = false, .disarmed = true, .east = false, .north = true, .powered = false, .south = true, .west = false};
case 5345:
return {.attached = false, .disarmed = true, .east = false, .north = true, .powered = false, .south = false, .west = true};
case 5346:
return {.attached = false, .disarmed = true, .east = false, .north = true, .powered = false, .south = false, .west = false};
case 5347:
return {.attached = false, .disarmed = true, .east = false, .north = false, .powered = true, .south = true, .west = true};
case 5348:
return {.attached = false, .disarmed = true, .east = false, .north = false, .powered = true, .south = true, .west = false};
case 5349:
return {.attached = false, .disarmed = true, .east = false, .north = false, .powered = true, .south = false, .west = true};
case 5350:
return {.attached = false, .disarmed = true, .east = false, .north = false, .powered = true, .south = false, .west = false};
case 5351:
return {.attached = false, .disarmed = true, .east = false, .north = false, .powered = false, .south = true, .west = true};
case 5352:
return {.attached = false, .disarmed = true, .east = false, .north = false, .powered = false, .south = true, .west = false};
case 5353:
return {.attached = false, .disarmed = true, .east = false, .north = false, .powered = false, .south = false, .west = true};
case 5354:
return {.attached = false, .disarmed = true, .east = false, .north = false, .powered = false, .south = false, .west = false};
case 5355:
return {.attached = false, .disarmed = false, .east = true, .north = true, .powered = true, .south = true, .west = true};
case 5356:
return {.attached = false, .disarmed = false, .east = true, .north = true, .powered = true, .south = true, .west = false};
case 5357:
return {.attached = false, .disarmed = false, .east = true, .north = true, .powered = true, .south = false, .west = true};
case 5358:
return {.attached = false, .disarmed = false, .east = true, .north = true, .powered = true, .south = false, .west = false};
case 5359:
return {.attached = false, .disarmed = false, .east = true, .north = true, .powered = false, .south = true, .west = true};
case 5360:
return {.attached = false, .disarmed = false, .east = true, .north = true, .powered = false, .south = true, .west = false};
case 5361:
return {.attached = false, .disarmed = false, .east = true, .north = true, .powered = false, .south = false, .west = true};
case 5362:
return {.attached = false, .disarmed = false, .east = true, .north = true, .powered = false, .south = false, .west = false};
case 5363:
return {.attached = false, .disarmed = false, .east = true, .north = false, .powered = true, .south = true, .west = true};
case 5364:
return {.attached = false, .disarmed = false, .east = true, .north = false, .powered = true, .south = true, .west = false};
case 5365:
return {.attached = false, .disarmed = false, .east = true, .north = false, .powered = true, .south = false, .west = true};
case 5366:
return {.attached = false, .disarmed = false, .east = true, .north = false, .powered = true, .south = false, .west = false};
case 5367:
return {.attached = false, .disarmed = false, .east = true, .north = false, .powered = false, .south = true, .west = true};
case 5368:
return {.attached = false, .disarmed = false, .east = true, .north = false, .powered = false, .south = true, .west = false};
case 5369:
return {.attached = false, .disarmed = false, .east = true, .north = false, .powered = false, .south = false, .west = true};
case 5370:
return {.attached = false, .disarmed = false, .east = true, .north = false, .powered = false, .south = false, .west = false};
case 5371:
return {.attached = false, .disarmed = false, .east = false, .north = true, .powered = true, .south = true, .west = true};
case 5372:
return {.attached = false, .disarmed = false, .east = false, .north = true, .powered = true, .south = true, .west = false};
case 5373:
return {.attached = false, .disarmed = false, .east = false, .north = true, .powered = true, .south = false, .west = true};
case 5374:
return {.attached = false, .disarmed = false, .east = false, .north = true, .powered = true, .south = false, .west = false};
case 5375:
return {.attached = false, .disarmed = false, .east = false, .north = true, .powered = false, .south = true, .west = true};
case 5376:
return {.attached = false, .disarmed = false, .east = false, .north = true, .powered = false, .south = true, .west = false};
case 5377:
return {.attached = false, .disarmed = false, .east = false, .north = true, .powered = false, .south = false, .west = true};
case 5378:
return {.attached = false, .disarmed = false, .east = false, .north = true, .powered = false, .south = false, .west = false};
case 5379:
return {.attached = false, .disarmed = false, .east = false, .north = false, .powered = true, .south = true, .west = true};
case 5380:
return {.attached = false, .disarmed = false, .east = false, .north = false, .powered = true, .south = true, .west = false};
case 5381:
return {.attached = false, .disarmed = false, .east = false, .north = false, .powered = true, .south = false, .west = true};
case 5382:
return {.attached = false, .disarmed = false, .east = false, .north = false, .powered = true, .south = false, .west = false};
case 5383:
return {.attached = false, .disarmed = false, .east = false, .north = false, .powered = false, .south = true, .west = true};
case 5384:
return {.attached = false, .disarmed = false, .east = false, .north = false, .powered = false, .south = true, .west = false};
case 5385:
return {.attached = false, .disarmed = false, .east = false, .north = false, .powered = false, .south = false, .west = true};
case 5386:
return {.attached = false, .disarmed = false, .east = false, .north = false, .powered = false, .south = false, .west = false};
}}
constexpr std::string_view to_string() const
{switch (attached)
{
case true:
switch (disarmed)
{
case true:
switch (east)
{
case true:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:true:true:true:true:true";
case false:
return "minecraft:tripwire:true:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:true:true:true:false:true";
case false:
return "minecraft:tripwire:true:true:true:true:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:true:true:false:true:true";
case false:
return "minecraft:tripwire:true:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:true:true:false:false:true";
case false:
return "minecraft:tripwire:true:true:true:true:false:false:false";
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:true:false:true:true:true";
case false:
return "minecraft:tripwire:true:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:true:false:true:false:true";
case false:
return "minecraft:tripwire:true:true:true:false:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:true:false:false:true:true";
case false:
return "minecraft:tripwire:true:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:true:false:false:false:true";
case false:
return "minecraft:tripwire:true:true:true:false:false:false:false";
}
}
}
}
case false:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:false:true:true:true:true";
case false:
return "minecraft:tripwire:true:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:false:true:true:false:true";
case false:
return "minecraft:tripwire:true:true:false:true:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:false:true:false:true:true";
case false:
return "minecraft:tripwire:true:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:false:true:false:false:true";
case false:
return "minecraft:tripwire:true:true:false:true:false:false:false";
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:false:false:true:true:true";
case false:
return "minecraft:tripwire:true:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:false:false:true:false:true";
case false:
return "minecraft:tripwire:true:true:false:false:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:false:false:false:true:true";
case false:
return "minecraft:tripwire:true:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:true:false:false:false:false:true";
case false:
return "minecraft:tripwire:true:true:false:false:false:false:false";
}
}
}
}
}
case false:
switch (east)
{
case true:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:true:true:true:true:true";
case false:
return "minecraft:tripwire:true:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:true:true:true:false:true";
case false:
return "minecraft:tripwire:true:false:true:true:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:true:true:false:true:true";
case false:
return "minecraft:tripwire:true:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:true:true:false:false:true";
case false:
return "minecraft:tripwire:true:false:true:true:false:false:false";
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:true:false:true:true:true";
case false:
return "minecraft:tripwire:true:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:true:false:true:false:true";
case false:
return "minecraft:tripwire:true:false:true:false:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:true:false:false:true:true";
case false:
return "minecraft:tripwire:true:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:true:false:false:false:true";
case false:
return "minecraft:tripwire:true:false:true:false:false:false:false";
}
}
}
}
case false:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:false:true:true:true:true";
case false:
return "minecraft:tripwire:true:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:false:true:true:false:true";
case false:
return "minecraft:tripwire:true:false:false:true:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:false:true:false:true:true";
case false:
return "minecraft:tripwire:true:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:false:true:false:false:true";
case false:
return "minecraft:tripwire:true:false:false:true:false:false:false";
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:false:false:true:true:true";
case false:
return "minecraft:tripwire:true:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:false:false:true:false:true";
case false:
return "minecraft:tripwire:true:false:false:false:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:false:false:false:true:true";
case false:
return "minecraft:tripwire:true:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:true:false:false:false:false:false:true";
case false:
return "minecraft:tripwire:true:false:false:false:false:false:false";
}
}
}
}
}
}
case false:
switch (disarmed)
{
case true:
switch (east)
{
case true:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:true:true:true:true:true";
case false:
return "minecraft:tripwire:false:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:true:true:true:false:true";
case false:
return "minecraft:tripwire:false:true:true:true:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:true:true:false:true:true";
case false:
return "minecraft:tripwire:false:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:true:true:false:false:true";
case false:
return "minecraft:tripwire:false:true:true:true:false:false:false";
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:true:false:true:true:true";
case false:
return "minecraft:tripwire:false:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:true:false:true:false:true";
case false:
return "minecraft:tripwire:false:true:true:false:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:true:false:false:true:true";
case false:
return "minecraft:tripwire:false:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:true:false:false:false:true";
case false:
return "minecraft:tripwire:false:true:true:false:false:false:false";
}
}
}
}
case false:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:false:true:true:true:true";
case false:
return "minecraft:tripwire:false:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:false:true:true:false:true";
case false:
return "minecraft:tripwire:false:true:false:true:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:false:true:false:true:true";
case false:
return "minecraft:tripwire:false:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:false:true:false:false:true";
case false:
return "minecraft:tripwire:false:true:false:true:false:false:false";
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:false:false:true:true:true";
case false:
return "minecraft:tripwire:false:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:false:false:true:false:true";
case false:
return "minecraft:tripwire:false:true:false:false:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:false:false:false:true:true";
case false:
return "minecraft:tripwire:false:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:true:false:false:false:false:true";
case false:
return "minecraft:tripwire:false:true:false:false:false:false:false";
}
}
}
}
}
case false:
switch (east)
{
case true:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:true:true:true:true:true";
case false:
return "minecraft:tripwire:false:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:true:true:true:false:true";
case false:
return "minecraft:tripwire:false:false:true:true:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:true:true:false:true:true";
case false:
return "minecraft:tripwire:false:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:true:true:false:false:true";
case false:
return "minecraft:tripwire:false:false:true:true:false:false:false";
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:true:false:true:true:true";
case false:
return "minecraft:tripwire:false:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:true:false:true:false:true";
case false:
return "minecraft:tripwire:false:false:true:false:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:true:false:false:true:true";
case false:
return "minecraft:tripwire:false:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:true:false:false:false:true";
case false:
return "minecraft:tripwire:false:false:true:false:false:false:false";
}
}
}
}
case false:
switch (north)
{
case true:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:false:true:true:true:true";
case false:
return "minecraft:tripwire:false:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:false:true:true:false:true";
case false:
return "minecraft:tripwire:false:false:false:true:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:false:true:false:true:true";
case false:
return "minecraft:tripwire:false:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:false:true:false:false:true";
case false:
return "minecraft:tripwire:false:false:false:true:false:false:false";
}
}
}
case false:
switch (powered)
{
case true:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:false:false:true:true:true";
case false:
return "minecraft:tripwire:false:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:false:false:true:false:true";
case false:
return "minecraft:tripwire:false:false:false:false:true:false:false";
}
}
case false:
switch (south)
{
case true:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:false:false:false:true:true";
case false:
return "minecraft:tripwire:false:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:tripwire:false:false:false:false:false:false:true";
case false:
return "minecraft:tripwire:false:false:false:false:false:false:false";
}
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
