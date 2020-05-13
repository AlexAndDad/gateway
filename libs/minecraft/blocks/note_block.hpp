#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct note_block
{enum class instrument_type : std::uint16_t
{
harp,
basedrum,
snare,
hat,
bass,
flute,
bell,
guitar,
chime,
xylophone,
iron_xylophone,
cow_bell,
didgeridoo,
bit,
banjo,
pling
} instrument = instrument_type::harp;
std::uint16_t note = 0;
bool powered = false;
constexpr block_id_type to_id() const {
switch (instrument)
{
case instrument_type::harp:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 248;
case false:
return 249;
}
case 1:
switch (powered)
{
case true:
return 250;
case false:
return 251;
}
case 2:
switch (powered)
{
case true:
return 252;
case false:
return 253;
}
case 3:
switch (powered)
{
case true:
return 254;
case false:
return 255;
}
case 4:
switch (powered)
{
case true:
return 256;
case false:
return 257;
}
case 5:
switch (powered)
{
case true:
return 258;
case false:
return 259;
}
case 6:
switch (powered)
{
case true:
return 260;
case false:
return 261;
}
case 7:
switch (powered)
{
case true:
return 262;
case false:
return 263;
}
case 8:
switch (powered)
{
case true:
return 264;
case false:
return 265;
}
case 9:
switch (powered)
{
case true:
return 266;
case false:
return 267;
}
case 10:
switch (powered)
{
case true:
return 268;
case false:
return 269;
}
case 11:
switch (powered)
{
case true:
return 270;
case false:
return 271;
}
case 12:
switch (powered)
{
case true:
return 272;
case false:
return 273;
}
case 13:
switch (powered)
{
case true:
return 274;
case false:
return 275;
}
case 14:
switch (powered)
{
case true:
return 276;
case false:
return 277;
}
case 15:
switch (powered)
{
case true:
return 278;
case false:
return 279;
}
case 16:
switch (powered)
{
case true:
return 280;
case false:
return 281;
}
case 17:
switch (powered)
{
case true:
return 282;
case false:
return 283;
}
case 18:
switch (powered)
{
case true:
return 284;
case false:
return 285;
}
case 19:
switch (powered)
{
case true:
return 286;
case false:
return 287;
}
case 20:
switch (powered)
{
case true:
return 288;
case false:
return 289;
}
case 21:
switch (powered)
{
case true:
return 290;
case false:
return 291;
}
case 22:
switch (powered)
{
case true:
return 292;
case false:
return 293;
}
case 23:
switch (powered)
{
case true:
return 294;
case false:
return 295;
}
case 24:
switch (powered)
{
case true:
return 296;
case false:
return 297;
}
}
case instrument_type::basedrum:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 298;
case false:
return 299;
}
case 1:
switch (powered)
{
case true:
return 300;
case false:
return 301;
}
case 2:
switch (powered)
{
case true:
return 302;
case false:
return 303;
}
case 3:
switch (powered)
{
case true:
return 304;
case false:
return 305;
}
case 4:
switch (powered)
{
case true:
return 306;
case false:
return 307;
}
case 5:
switch (powered)
{
case true:
return 308;
case false:
return 309;
}
case 6:
switch (powered)
{
case true:
return 310;
case false:
return 311;
}
case 7:
switch (powered)
{
case true:
return 312;
case false:
return 313;
}
case 8:
switch (powered)
{
case true:
return 314;
case false:
return 315;
}
case 9:
switch (powered)
{
case true:
return 316;
case false:
return 317;
}
case 10:
switch (powered)
{
case true:
return 318;
case false:
return 319;
}
case 11:
switch (powered)
{
case true:
return 320;
case false:
return 321;
}
case 12:
switch (powered)
{
case true:
return 322;
case false:
return 323;
}
case 13:
switch (powered)
{
case true:
return 324;
case false:
return 325;
}
case 14:
switch (powered)
{
case true:
return 326;
case false:
return 327;
}
case 15:
switch (powered)
{
case true:
return 328;
case false:
return 329;
}
case 16:
switch (powered)
{
case true:
return 330;
case false:
return 331;
}
case 17:
switch (powered)
{
case true:
return 332;
case false:
return 333;
}
case 18:
switch (powered)
{
case true:
return 334;
case false:
return 335;
}
case 19:
switch (powered)
{
case true:
return 336;
case false:
return 337;
}
case 20:
switch (powered)
{
case true:
return 338;
case false:
return 339;
}
case 21:
switch (powered)
{
case true:
return 340;
case false:
return 341;
}
case 22:
switch (powered)
{
case true:
return 342;
case false:
return 343;
}
case 23:
switch (powered)
{
case true:
return 344;
case false:
return 345;
}
case 24:
switch (powered)
{
case true:
return 346;
case false:
return 347;
}
}
case instrument_type::snare:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 348;
case false:
return 349;
}
case 1:
switch (powered)
{
case true:
return 350;
case false:
return 351;
}
case 2:
switch (powered)
{
case true:
return 352;
case false:
return 353;
}
case 3:
switch (powered)
{
case true:
return 354;
case false:
return 355;
}
case 4:
switch (powered)
{
case true:
return 356;
case false:
return 357;
}
case 5:
switch (powered)
{
case true:
return 358;
case false:
return 359;
}
case 6:
switch (powered)
{
case true:
return 360;
case false:
return 361;
}
case 7:
switch (powered)
{
case true:
return 362;
case false:
return 363;
}
case 8:
switch (powered)
{
case true:
return 364;
case false:
return 365;
}
case 9:
switch (powered)
{
case true:
return 366;
case false:
return 367;
}
case 10:
switch (powered)
{
case true:
return 368;
case false:
return 369;
}
case 11:
switch (powered)
{
case true:
return 370;
case false:
return 371;
}
case 12:
switch (powered)
{
case true:
return 372;
case false:
return 373;
}
case 13:
switch (powered)
{
case true:
return 374;
case false:
return 375;
}
case 14:
switch (powered)
{
case true:
return 376;
case false:
return 377;
}
case 15:
switch (powered)
{
case true:
return 378;
case false:
return 379;
}
case 16:
switch (powered)
{
case true:
return 380;
case false:
return 381;
}
case 17:
switch (powered)
{
case true:
return 382;
case false:
return 383;
}
case 18:
switch (powered)
{
case true:
return 384;
case false:
return 385;
}
case 19:
switch (powered)
{
case true:
return 386;
case false:
return 387;
}
case 20:
switch (powered)
{
case true:
return 388;
case false:
return 389;
}
case 21:
switch (powered)
{
case true:
return 390;
case false:
return 391;
}
case 22:
switch (powered)
{
case true:
return 392;
case false:
return 393;
}
case 23:
switch (powered)
{
case true:
return 394;
case false:
return 395;
}
case 24:
switch (powered)
{
case true:
return 396;
case false:
return 397;
}
}
case instrument_type::hat:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 398;
case false:
return 399;
}
case 1:
switch (powered)
{
case true:
return 400;
case false:
return 401;
}
case 2:
switch (powered)
{
case true:
return 402;
case false:
return 403;
}
case 3:
switch (powered)
{
case true:
return 404;
case false:
return 405;
}
case 4:
switch (powered)
{
case true:
return 406;
case false:
return 407;
}
case 5:
switch (powered)
{
case true:
return 408;
case false:
return 409;
}
case 6:
switch (powered)
{
case true:
return 410;
case false:
return 411;
}
case 7:
switch (powered)
{
case true:
return 412;
case false:
return 413;
}
case 8:
switch (powered)
{
case true:
return 414;
case false:
return 415;
}
case 9:
switch (powered)
{
case true:
return 416;
case false:
return 417;
}
case 10:
switch (powered)
{
case true:
return 418;
case false:
return 419;
}
case 11:
switch (powered)
{
case true:
return 420;
case false:
return 421;
}
case 12:
switch (powered)
{
case true:
return 422;
case false:
return 423;
}
case 13:
switch (powered)
{
case true:
return 424;
case false:
return 425;
}
case 14:
switch (powered)
{
case true:
return 426;
case false:
return 427;
}
case 15:
switch (powered)
{
case true:
return 428;
case false:
return 429;
}
case 16:
switch (powered)
{
case true:
return 430;
case false:
return 431;
}
case 17:
switch (powered)
{
case true:
return 432;
case false:
return 433;
}
case 18:
switch (powered)
{
case true:
return 434;
case false:
return 435;
}
case 19:
switch (powered)
{
case true:
return 436;
case false:
return 437;
}
case 20:
switch (powered)
{
case true:
return 438;
case false:
return 439;
}
case 21:
switch (powered)
{
case true:
return 440;
case false:
return 441;
}
case 22:
switch (powered)
{
case true:
return 442;
case false:
return 443;
}
case 23:
switch (powered)
{
case true:
return 444;
case false:
return 445;
}
case 24:
switch (powered)
{
case true:
return 446;
case false:
return 447;
}
}
case instrument_type::bass:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 448;
case false:
return 449;
}
case 1:
switch (powered)
{
case true:
return 450;
case false:
return 451;
}
case 2:
switch (powered)
{
case true:
return 452;
case false:
return 453;
}
case 3:
switch (powered)
{
case true:
return 454;
case false:
return 455;
}
case 4:
switch (powered)
{
case true:
return 456;
case false:
return 457;
}
case 5:
switch (powered)
{
case true:
return 458;
case false:
return 459;
}
case 6:
switch (powered)
{
case true:
return 460;
case false:
return 461;
}
case 7:
switch (powered)
{
case true:
return 462;
case false:
return 463;
}
case 8:
switch (powered)
{
case true:
return 464;
case false:
return 465;
}
case 9:
switch (powered)
{
case true:
return 466;
case false:
return 467;
}
case 10:
switch (powered)
{
case true:
return 468;
case false:
return 469;
}
case 11:
switch (powered)
{
case true:
return 470;
case false:
return 471;
}
case 12:
switch (powered)
{
case true:
return 472;
case false:
return 473;
}
case 13:
switch (powered)
{
case true:
return 474;
case false:
return 475;
}
case 14:
switch (powered)
{
case true:
return 476;
case false:
return 477;
}
case 15:
switch (powered)
{
case true:
return 478;
case false:
return 479;
}
case 16:
switch (powered)
{
case true:
return 480;
case false:
return 481;
}
case 17:
switch (powered)
{
case true:
return 482;
case false:
return 483;
}
case 18:
switch (powered)
{
case true:
return 484;
case false:
return 485;
}
case 19:
switch (powered)
{
case true:
return 486;
case false:
return 487;
}
case 20:
switch (powered)
{
case true:
return 488;
case false:
return 489;
}
case 21:
switch (powered)
{
case true:
return 490;
case false:
return 491;
}
case 22:
switch (powered)
{
case true:
return 492;
case false:
return 493;
}
case 23:
switch (powered)
{
case true:
return 494;
case false:
return 495;
}
case 24:
switch (powered)
{
case true:
return 496;
case false:
return 497;
}
}
case instrument_type::flute:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 498;
case false:
return 499;
}
case 1:
switch (powered)
{
case true:
return 500;
case false:
return 501;
}
case 2:
switch (powered)
{
case true:
return 502;
case false:
return 503;
}
case 3:
switch (powered)
{
case true:
return 504;
case false:
return 505;
}
case 4:
switch (powered)
{
case true:
return 506;
case false:
return 507;
}
case 5:
switch (powered)
{
case true:
return 508;
case false:
return 509;
}
case 6:
switch (powered)
{
case true:
return 510;
case false:
return 511;
}
case 7:
switch (powered)
{
case true:
return 512;
case false:
return 513;
}
case 8:
switch (powered)
{
case true:
return 514;
case false:
return 515;
}
case 9:
switch (powered)
{
case true:
return 516;
case false:
return 517;
}
case 10:
switch (powered)
{
case true:
return 518;
case false:
return 519;
}
case 11:
switch (powered)
{
case true:
return 520;
case false:
return 521;
}
case 12:
switch (powered)
{
case true:
return 522;
case false:
return 523;
}
case 13:
switch (powered)
{
case true:
return 524;
case false:
return 525;
}
case 14:
switch (powered)
{
case true:
return 526;
case false:
return 527;
}
case 15:
switch (powered)
{
case true:
return 528;
case false:
return 529;
}
case 16:
switch (powered)
{
case true:
return 530;
case false:
return 531;
}
case 17:
switch (powered)
{
case true:
return 532;
case false:
return 533;
}
case 18:
switch (powered)
{
case true:
return 534;
case false:
return 535;
}
case 19:
switch (powered)
{
case true:
return 536;
case false:
return 537;
}
case 20:
switch (powered)
{
case true:
return 538;
case false:
return 539;
}
case 21:
switch (powered)
{
case true:
return 540;
case false:
return 541;
}
case 22:
switch (powered)
{
case true:
return 542;
case false:
return 543;
}
case 23:
switch (powered)
{
case true:
return 544;
case false:
return 545;
}
case 24:
switch (powered)
{
case true:
return 546;
case false:
return 547;
}
}
case instrument_type::bell:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 548;
case false:
return 549;
}
case 1:
switch (powered)
{
case true:
return 550;
case false:
return 551;
}
case 2:
switch (powered)
{
case true:
return 552;
case false:
return 553;
}
case 3:
switch (powered)
{
case true:
return 554;
case false:
return 555;
}
case 4:
switch (powered)
{
case true:
return 556;
case false:
return 557;
}
case 5:
switch (powered)
{
case true:
return 558;
case false:
return 559;
}
case 6:
switch (powered)
{
case true:
return 560;
case false:
return 561;
}
case 7:
switch (powered)
{
case true:
return 562;
case false:
return 563;
}
case 8:
switch (powered)
{
case true:
return 564;
case false:
return 565;
}
case 9:
switch (powered)
{
case true:
return 566;
case false:
return 567;
}
case 10:
switch (powered)
{
case true:
return 568;
case false:
return 569;
}
case 11:
switch (powered)
{
case true:
return 570;
case false:
return 571;
}
case 12:
switch (powered)
{
case true:
return 572;
case false:
return 573;
}
case 13:
switch (powered)
{
case true:
return 574;
case false:
return 575;
}
case 14:
switch (powered)
{
case true:
return 576;
case false:
return 577;
}
case 15:
switch (powered)
{
case true:
return 578;
case false:
return 579;
}
case 16:
switch (powered)
{
case true:
return 580;
case false:
return 581;
}
case 17:
switch (powered)
{
case true:
return 582;
case false:
return 583;
}
case 18:
switch (powered)
{
case true:
return 584;
case false:
return 585;
}
case 19:
switch (powered)
{
case true:
return 586;
case false:
return 587;
}
case 20:
switch (powered)
{
case true:
return 588;
case false:
return 589;
}
case 21:
switch (powered)
{
case true:
return 590;
case false:
return 591;
}
case 22:
switch (powered)
{
case true:
return 592;
case false:
return 593;
}
case 23:
switch (powered)
{
case true:
return 594;
case false:
return 595;
}
case 24:
switch (powered)
{
case true:
return 596;
case false:
return 597;
}
}
case instrument_type::guitar:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 598;
case false:
return 599;
}
case 1:
switch (powered)
{
case true:
return 600;
case false:
return 601;
}
case 2:
switch (powered)
{
case true:
return 602;
case false:
return 603;
}
case 3:
switch (powered)
{
case true:
return 604;
case false:
return 605;
}
case 4:
switch (powered)
{
case true:
return 606;
case false:
return 607;
}
case 5:
switch (powered)
{
case true:
return 608;
case false:
return 609;
}
case 6:
switch (powered)
{
case true:
return 610;
case false:
return 611;
}
case 7:
switch (powered)
{
case true:
return 612;
case false:
return 613;
}
case 8:
switch (powered)
{
case true:
return 614;
case false:
return 615;
}
case 9:
switch (powered)
{
case true:
return 616;
case false:
return 617;
}
case 10:
switch (powered)
{
case true:
return 618;
case false:
return 619;
}
case 11:
switch (powered)
{
case true:
return 620;
case false:
return 621;
}
case 12:
switch (powered)
{
case true:
return 622;
case false:
return 623;
}
case 13:
switch (powered)
{
case true:
return 624;
case false:
return 625;
}
case 14:
switch (powered)
{
case true:
return 626;
case false:
return 627;
}
case 15:
switch (powered)
{
case true:
return 628;
case false:
return 629;
}
case 16:
switch (powered)
{
case true:
return 630;
case false:
return 631;
}
case 17:
switch (powered)
{
case true:
return 632;
case false:
return 633;
}
case 18:
switch (powered)
{
case true:
return 634;
case false:
return 635;
}
case 19:
switch (powered)
{
case true:
return 636;
case false:
return 637;
}
case 20:
switch (powered)
{
case true:
return 638;
case false:
return 639;
}
case 21:
switch (powered)
{
case true:
return 640;
case false:
return 641;
}
case 22:
switch (powered)
{
case true:
return 642;
case false:
return 643;
}
case 23:
switch (powered)
{
case true:
return 644;
case false:
return 645;
}
case 24:
switch (powered)
{
case true:
return 646;
case false:
return 647;
}
}
case instrument_type::chime:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 648;
case false:
return 649;
}
case 1:
switch (powered)
{
case true:
return 650;
case false:
return 651;
}
case 2:
switch (powered)
{
case true:
return 652;
case false:
return 653;
}
case 3:
switch (powered)
{
case true:
return 654;
case false:
return 655;
}
case 4:
switch (powered)
{
case true:
return 656;
case false:
return 657;
}
case 5:
switch (powered)
{
case true:
return 658;
case false:
return 659;
}
case 6:
switch (powered)
{
case true:
return 660;
case false:
return 661;
}
case 7:
switch (powered)
{
case true:
return 662;
case false:
return 663;
}
case 8:
switch (powered)
{
case true:
return 664;
case false:
return 665;
}
case 9:
switch (powered)
{
case true:
return 666;
case false:
return 667;
}
case 10:
switch (powered)
{
case true:
return 668;
case false:
return 669;
}
case 11:
switch (powered)
{
case true:
return 670;
case false:
return 671;
}
case 12:
switch (powered)
{
case true:
return 672;
case false:
return 673;
}
case 13:
switch (powered)
{
case true:
return 674;
case false:
return 675;
}
case 14:
switch (powered)
{
case true:
return 676;
case false:
return 677;
}
case 15:
switch (powered)
{
case true:
return 678;
case false:
return 679;
}
case 16:
switch (powered)
{
case true:
return 680;
case false:
return 681;
}
case 17:
switch (powered)
{
case true:
return 682;
case false:
return 683;
}
case 18:
switch (powered)
{
case true:
return 684;
case false:
return 685;
}
case 19:
switch (powered)
{
case true:
return 686;
case false:
return 687;
}
case 20:
switch (powered)
{
case true:
return 688;
case false:
return 689;
}
case 21:
switch (powered)
{
case true:
return 690;
case false:
return 691;
}
case 22:
switch (powered)
{
case true:
return 692;
case false:
return 693;
}
case 23:
switch (powered)
{
case true:
return 694;
case false:
return 695;
}
case 24:
switch (powered)
{
case true:
return 696;
case false:
return 697;
}
}
case instrument_type::xylophone:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 698;
case false:
return 699;
}
case 1:
switch (powered)
{
case true:
return 700;
case false:
return 701;
}
case 2:
switch (powered)
{
case true:
return 702;
case false:
return 703;
}
case 3:
switch (powered)
{
case true:
return 704;
case false:
return 705;
}
case 4:
switch (powered)
{
case true:
return 706;
case false:
return 707;
}
case 5:
switch (powered)
{
case true:
return 708;
case false:
return 709;
}
case 6:
switch (powered)
{
case true:
return 710;
case false:
return 711;
}
case 7:
switch (powered)
{
case true:
return 712;
case false:
return 713;
}
case 8:
switch (powered)
{
case true:
return 714;
case false:
return 715;
}
case 9:
switch (powered)
{
case true:
return 716;
case false:
return 717;
}
case 10:
switch (powered)
{
case true:
return 718;
case false:
return 719;
}
case 11:
switch (powered)
{
case true:
return 720;
case false:
return 721;
}
case 12:
switch (powered)
{
case true:
return 722;
case false:
return 723;
}
case 13:
switch (powered)
{
case true:
return 724;
case false:
return 725;
}
case 14:
switch (powered)
{
case true:
return 726;
case false:
return 727;
}
case 15:
switch (powered)
{
case true:
return 728;
case false:
return 729;
}
case 16:
switch (powered)
{
case true:
return 730;
case false:
return 731;
}
case 17:
switch (powered)
{
case true:
return 732;
case false:
return 733;
}
case 18:
switch (powered)
{
case true:
return 734;
case false:
return 735;
}
case 19:
switch (powered)
{
case true:
return 736;
case false:
return 737;
}
case 20:
switch (powered)
{
case true:
return 738;
case false:
return 739;
}
case 21:
switch (powered)
{
case true:
return 740;
case false:
return 741;
}
case 22:
switch (powered)
{
case true:
return 742;
case false:
return 743;
}
case 23:
switch (powered)
{
case true:
return 744;
case false:
return 745;
}
case 24:
switch (powered)
{
case true:
return 746;
case false:
return 747;
}
}
case instrument_type::iron_xylophone:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 748;
case false:
return 749;
}
case 1:
switch (powered)
{
case true:
return 750;
case false:
return 751;
}
case 2:
switch (powered)
{
case true:
return 752;
case false:
return 753;
}
case 3:
switch (powered)
{
case true:
return 754;
case false:
return 755;
}
case 4:
switch (powered)
{
case true:
return 756;
case false:
return 757;
}
case 5:
switch (powered)
{
case true:
return 758;
case false:
return 759;
}
case 6:
switch (powered)
{
case true:
return 760;
case false:
return 761;
}
case 7:
switch (powered)
{
case true:
return 762;
case false:
return 763;
}
case 8:
switch (powered)
{
case true:
return 764;
case false:
return 765;
}
case 9:
switch (powered)
{
case true:
return 766;
case false:
return 767;
}
case 10:
switch (powered)
{
case true:
return 768;
case false:
return 769;
}
case 11:
switch (powered)
{
case true:
return 770;
case false:
return 771;
}
case 12:
switch (powered)
{
case true:
return 772;
case false:
return 773;
}
case 13:
switch (powered)
{
case true:
return 774;
case false:
return 775;
}
case 14:
switch (powered)
{
case true:
return 776;
case false:
return 777;
}
case 15:
switch (powered)
{
case true:
return 778;
case false:
return 779;
}
case 16:
switch (powered)
{
case true:
return 780;
case false:
return 781;
}
case 17:
switch (powered)
{
case true:
return 782;
case false:
return 783;
}
case 18:
switch (powered)
{
case true:
return 784;
case false:
return 785;
}
case 19:
switch (powered)
{
case true:
return 786;
case false:
return 787;
}
case 20:
switch (powered)
{
case true:
return 788;
case false:
return 789;
}
case 21:
switch (powered)
{
case true:
return 790;
case false:
return 791;
}
case 22:
switch (powered)
{
case true:
return 792;
case false:
return 793;
}
case 23:
switch (powered)
{
case true:
return 794;
case false:
return 795;
}
case 24:
switch (powered)
{
case true:
return 796;
case false:
return 797;
}
}
case instrument_type::cow_bell:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 798;
case false:
return 799;
}
case 1:
switch (powered)
{
case true:
return 800;
case false:
return 801;
}
case 2:
switch (powered)
{
case true:
return 802;
case false:
return 803;
}
case 3:
switch (powered)
{
case true:
return 804;
case false:
return 805;
}
case 4:
switch (powered)
{
case true:
return 806;
case false:
return 807;
}
case 5:
switch (powered)
{
case true:
return 808;
case false:
return 809;
}
case 6:
switch (powered)
{
case true:
return 810;
case false:
return 811;
}
case 7:
switch (powered)
{
case true:
return 812;
case false:
return 813;
}
case 8:
switch (powered)
{
case true:
return 814;
case false:
return 815;
}
case 9:
switch (powered)
{
case true:
return 816;
case false:
return 817;
}
case 10:
switch (powered)
{
case true:
return 818;
case false:
return 819;
}
case 11:
switch (powered)
{
case true:
return 820;
case false:
return 821;
}
case 12:
switch (powered)
{
case true:
return 822;
case false:
return 823;
}
case 13:
switch (powered)
{
case true:
return 824;
case false:
return 825;
}
case 14:
switch (powered)
{
case true:
return 826;
case false:
return 827;
}
case 15:
switch (powered)
{
case true:
return 828;
case false:
return 829;
}
case 16:
switch (powered)
{
case true:
return 830;
case false:
return 831;
}
case 17:
switch (powered)
{
case true:
return 832;
case false:
return 833;
}
case 18:
switch (powered)
{
case true:
return 834;
case false:
return 835;
}
case 19:
switch (powered)
{
case true:
return 836;
case false:
return 837;
}
case 20:
switch (powered)
{
case true:
return 838;
case false:
return 839;
}
case 21:
switch (powered)
{
case true:
return 840;
case false:
return 841;
}
case 22:
switch (powered)
{
case true:
return 842;
case false:
return 843;
}
case 23:
switch (powered)
{
case true:
return 844;
case false:
return 845;
}
case 24:
switch (powered)
{
case true:
return 846;
case false:
return 847;
}
}
case instrument_type::didgeridoo:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 848;
case false:
return 849;
}
case 1:
switch (powered)
{
case true:
return 850;
case false:
return 851;
}
case 2:
switch (powered)
{
case true:
return 852;
case false:
return 853;
}
case 3:
switch (powered)
{
case true:
return 854;
case false:
return 855;
}
case 4:
switch (powered)
{
case true:
return 856;
case false:
return 857;
}
case 5:
switch (powered)
{
case true:
return 858;
case false:
return 859;
}
case 6:
switch (powered)
{
case true:
return 860;
case false:
return 861;
}
case 7:
switch (powered)
{
case true:
return 862;
case false:
return 863;
}
case 8:
switch (powered)
{
case true:
return 864;
case false:
return 865;
}
case 9:
switch (powered)
{
case true:
return 866;
case false:
return 867;
}
case 10:
switch (powered)
{
case true:
return 868;
case false:
return 869;
}
case 11:
switch (powered)
{
case true:
return 870;
case false:
return 871;
}
case 12:
switch (powered)
{
case true:
return 872;
case false:
return 873;
}
case 13:
switch (powered)
{
case true:
return 874;
case false:
return 875;
}
case 14:
switch (powered)
{
case true:
return 876;
case false:
return 877;
}
case 15:
switch (powered)
{
case true:
return 878;
case false:
return 879;
}
case 16:
switch (powered)
{
case true:
return 880;
case false:
return 881;
}
case 17:
switch (powered)
{
case true:
return 882;
case false:
return 883;
}
case 18:
switch (powered)
{
case true:
return 884;
case false:
return 885;
}
case 19:
switch (powered)
{
case true:
return 886;
case false:
return 887;
}
case 20:
switch (powered)
{
case true:
return 888;
case false:
return 889;
}
case 21:
switch (powered)
{
case true:
return 890;
case false:
return 891;
}
case 22:
switch (powered)
{
case true:
return 892;
case false:
return 893;
}
case 23:
switch (powered)
{
case true:
return 894;
case false:
return 895;
}
case 24:
switch (powered)
{
case true:
return 896;
case false:
return 897;
}
}
case instrument_type::bit:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 898;
case false:
return 899;
}
case 1:
switch (powered)
{
case true:
return 900;
case false:
return 901;
}
case 2:
switch (powered)
{
case true:
return 902;
case false:
return 903;
}
case 3:
switch (powered)
{
case true:
return 904;
case false:
return 905;
}
case 4:
switch (powered)
{
case true:
return 906;
case false:
return 907;
}
case 5:
switch (powered)
{
case true:
return 908;
case false:
return 909;
}
case 6:
switch (powered)
{
case true:
return 910;
case false:
return 911;
}
case 7:
switch (powered)
{
case true:
return 912;
case false:
return 913;
}
case 8:
switch (powered)
{
case true:
return 914;
case false:
return 915;
}
case 9:
switch (powered)
{
case true:
return 916;
case false:
return 917;
}
case 10:
switch (powered)
{
case true:
return 918;
case false:
return 919;
}
case 11:
switch (powered)
{
case true:
return 920;
case false:
return 921;
}
case 12:
switch (powered)
{
case true:
return 922;
case false:
return 923;
}
case 13:
switch (powered)
{
case true:
return 924;
case false:
return 925;
}
case 14:
switch (powered)
{
case true:
return 926;
case false:
return 927;
}
case 15:
switch (powered)
{
case true:
return 928;
case false:
return 929;
}
case 16:
switch (powered)
{
case true:
return 930;
case false:
return 931;
}
case 17:
switch (powered)
{
case true:
return 932;
case false:
return 933;
}
case 18:
switch (powered)
{
case true:
return 934;
case false:
return 935;
}
case 19:
switch (powered)
{
case true:
return 936;
case false:
return 937;
}
case 20:
switch (powered)
{
case true:
return 938;
case false:
return 939;
}
case 21:
switch (powered)
{
case true:
return 940;
case false:
return 941;
}
case 22:
switch (powered)
{
case true:
return 942;
case false:
return 943;
}
case 23:
switch (powered)
{
case true:
return 944;
case false:
return 945;
}
case 24:
switch (powered)
{
case true:
return 946;
case false:
return 947;
}
}
case instrument_type::banjo:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 948;
case false:
return 949;
}
case 1:
switch (powered)
{
case true:
return 950;
case false:
return 951;
}
case 2:
switch (powered)
{
case true:
return 952;
case false:
return 953;
}
case 3:
switch (powered)
{
case true:
return 954;
case false:
return 955;
}
case 4:
switch (powered)
{
case true:
return 956;
case false:
return 957;
}
case 5:
switch (powered)
{
case true:
return 958;
case false:
return 959;
}
case 6:
switch (powered)
{
case true:
return 960;
case false:
return 961;
}
case 7:
switch (powered)
{
case true:
return 962;
case false:
return 963;
}
case 8:
switch (powered)
{
case true:
return 964;
case false:
return 965;
}
case 9:
switch (powered)
{
case true:
return 966;
case false:
return 967;
}
case 10:
switch (powered)
{
case true:
return 968;
case false:
return 969;
}
case 11:
switch (powered)
{
case true:
return 970;
case false:
return 971;
}
case 12:
switch (powered)
{
case true:
return 972;
case false:
return 973;
}
case 13:
switch (powered)
{
case true:
return 974;
case false:
return 975;
}
case 14:
switch (powered)
{
case true:
return 976;
case false:
return 977;
}
case 15:
switch (powered)
{
case true:
return 978;
case false:
return 979;
}
case 16:
switch (powered)
{
case true:
return 980;
case false:
return 981;
}
case 17:
switch (powered)
{
case true:
return 982;
case false:
return 983;
}
case 18:
switch (powered)
{
case true:
return 984;
case false:
return 985;
}
case 19:
switch (powered)
{
case true:
return 986;
case false:
return 987;
}
case 20:
switch (powered)
{
case true:
return 988;
case false:
return 989;
}
case 21:
switch (powered)
{
case true:
return 990;
case false:
return 991;
}
case 22:
switch (powered)
{
case true:
return 992;
case false:
return 993;
}
case 23:
switch (powered)
{
case true:
return 994;
case false:
return 995;
}
case 24:
switch (powered)
{
case true:
return 996;
case false:
return 997;
}
}
case instrument_type::pling:
switch (note)
{
case 0:
switch (powered)
{
case true:
return 998;
case false:
return 999;
}
case 1:
switch (powered)
{
case true:
return 1000;
case false:
return 1001;
}
case 2:
switch (powered)
{
case true:
return 1002;
case false:
return 1003;
}
case 3:
switch (powered)
{
case true:
return 1004;
case false:
return 1005;
}
case 4:
switch (powered)
{
case true:
return 1006;
case false:
return 1007;
}
case 5:
switch (powered)
{
case true:
return 1008;
case false:
return 1009;
}
case 6:
switch (powered)
{
case true:
return 1010;
case false:
return 1011;
}
case 7:
switch (powered)
{
case true:
return 1012;
case false:
return 1013;
}
case 8:
switch (powered)
{
case true:
return 1014;
case false:
return 1015;
}
case 9:
switch (powered)
{
case true:
return 1016;
case false:
return 1017;
}
case 10:
switch (powered)
{
case true:
return 1018;
case false:
return 1019;
}
case 11:
switch (powered)
{
case true:
return 1020;
case false:
return 1021;
}
case 12:
switch (powered)
{
case true:
return 1022;
case false:
return 1023;
}
case 13:
switch (powered)
{
case true:
return 1024;
case false:
return 1025;
}
case 14:
switch (powered)
{
case true:
return 1026;
case false:
return 1027;
}
case 15:
switch (powered)
{
case true:
return 1028;
case false:
return 1029;
}
case 16:
switch (powered)
{
case true:
return 1030;
case false:
return 1031;
}
case 17:
switch (powered)
{
case true:
return 1032;
case false:
return 1033;
}
case 18:
switch (powered)
{
case true:
return 1034;
case false:
return 1035;
}
case 19:
switch (powered)
{
case true:
return 1036;
case false:
return 1037;
}
case 20:
switch (powered)
{
case true:
return 1038;
case false:
return 1039;
}
case 21:
switch (powered)
{
case true:
return 1040;
case false:
return 1041;
}
case 22:
switch (powered)
{
case true:
return 1042;
case false:
return 1043;
}
case 23:
switch (powered)
{
case true:
return 1044;
case false:
return 1045;
}
case 24:
switch (powered)
{
case true:
return 1046;
case false:
return 1047;
}
}
}
}
constexpr static note_block from_id(block_id_type id)
{
switch (id)
{
case 248:
return {.instrument = instrument_type::harp, .note = 0, .powered = true};
case 249:
return {.instrument = instrument_type::harp, .note = 0, .powered = false};
case 250:
return {.instrument = instrument_type::harp, .note = 1, .powered = true};
case 251:
return {.instrument = instrument_type::harp, .note = 1, .powered = false};
case 252:
return {.instrument = instrument_type::harp, .note = 2, .powered = true};
case 253:
return {.instrument = instrument_type::harp, .note = 2, .powered = false};
case 254:
return {.instrument = instrument_type::harp, .note = 3, .powered = true};
case 255:
return {.instrument = instrument_type::harp, .note = 3, .powered = false};
case 256:
return {.instrument = instrument_type::harp, .note = 4, .powered = true};
case 257:
return {.instrument = instrument_type::harp, .note = 4, .powered = false};
case 258:
return {.instrument = instrument_type::harp, .note = 5, .powered = true};
case 259:
return {.instrument = instrument_type::harp, .note = 5, .powered = false};
case 260:
return {.instrument = instrument_type::harp, .note = 6, .powered = true};
case 261:
return {.instrument = instrument_type::harp, .note = 6, .powered = false};
case 262:
return {.instrument = instrument_type::harp, .note = 7, .powered = true};
case 263:
return {.instrument = instrument_type::harp, .note = 7, .powered = false};
case 264:
return {.instrument = instrument_type::harp, .note = 8, .powered = true};
case 265:
return {.instrument = instrument_type::harp, .note = 8, .powered = false};
case 266:
return {.instrument = instrument_type::harp, .note = 9, .powered = true};
case 267:
return {.instrument = instrument_type::harp, .note = 9, .powered = false};
case 268:
return {.instrument = instrument_type::harp, .note = 10, .powered = true};
case 269:
return {.instrument = instrument_type::harp, .note = 10, .powered = false};
case 270:
return {.instrument = instrument_type::harp, .note = 11, .powered = true};
case 271:
return {.instrument = instrument_type::harp, .note = 11, .powered = false};
case 272:
return {.instrument = instrument_type::harp, .note = 12, .powered = true};
case 273:
return {.instrument = instrument_type::harp, .note = 12, .powered = false};
case 274:
return {.instrument = instrument_type::harp, .note = 13, .powered = true};
case 275:
return {.instrument = instrument_type::harp, .note = 13, .powered = false};
case 276:
return {.instrument = instrument_type::harp, .note = 14, .powered = true};
case 277:
return {.instrument = instrument_type::harp, .note = 14, .powered = false};
case 278:
return {.instrument = instrument_type::harp, .note = 15, .powered = true};
case 279:
return {.instrument = instrument_type::harp, .note = 15, .powered = false};
case 280:
return {.instrument = instrument_type::harp, .note = 16, .powered = true};
case 281:
return {.instrument = instrument_type::harp, .note = 16, .powered = false};
case 282:
return {.instrument = instrument_type::harp, .note = 17, .powered = true};
case 283:
return {.instrument = instrument_type::harp, .note = 17, .powered = false};
case 284:
return {.instrument = instrument_type::harp, .note = 18, .powered = true};
case 285:
return {.instrument = instrument_type::harp, .note = 18, .powered = false};
case 286:
return {.instrument = instrument_type::harp, .note = 19, .powered = true};
case 287:
return {.instrument = instrument_type::harp, .note = 19, .powered = false};
case 288:
return {.instrument = instrument_type::harp, .note = 20, .powered = true};
case 289:
return {.instrument = instrument_type::harp, .note = 20, .powered = false};
case 290:
return {.instrument = instrument_type::harp, .note = 21, .powered = true};
case 291:
return {.instrument = instrument_type::harp, .note = 21, .powered = false};
case 292:
return {.instrument = instrument_type::harp, .note = 22, .powered = true};
case 293:
return {.instrument = instrument_type::harp, .note = 22, .powered = false};
case 294:
return {.instrument = instrument_type::harp, .note = 23, .powered = true};
case 295:
return {.instrument = instrument_type::harp, .note = 23, .powered = false};
case 296:
return {.instrument = instrument_type::harp, .note = 24, .powered = true};
case 297:
return {.instrument = instrument_type::harp, .note = 24, .powered = false};
case 298:
return {.instrument = instrument_type::basedrum, .note = 0, .powered = true};
case 299:
return {.instrument = instrument_type::basedrum, .note = 0, .powered = false};
case 300:
return {.instrument = instrument_type::basedrum, .note = 1, .powered = true};
case 301:
return {.instrument = instrument_type::basedrum, .note = 1, .powered = false};
case 302:
return {.instrument = instrument_type::basedrum, .note = 2, .powered = true};
case 303:
return {.instrument = instrument_type::basedrum, .note = 2, .powered = false};
case 304:
return {.instrument = instrument_type::basedrum, .note = 3, .powered = true};
case 305:
return {.instrument = instrument_type::basedrum, .note = 3, .powered = false};
case 306:
return {.instrument = instrument_type::basedrum, .note = 4, .powered = true};
case 307:
return {.instrument = instrument_type::basedrum, .note = 4, .powered = false};
case 308:
return {.instrument = instrument_type::basedrum, .note = 5, .powered = true};
case 309:
return {.instrument = instrument_type::basedrum, .note = 5, .powered = false};
case 310:
return {.instrument = instrument_type::basedrum, .note = 6, .powered = true};
case 311:
return {.instrument = instrument_type::basedrum, .note = 6, .powered = false};
case 312:
return {.instrument = instrument_type::basedrum, .note = 7, .powered = true};
case 313:
return {.instrument = instrument_type::basedrum, .note = 7, .powered = false};
case 314:
return {.instrument = instrument_type::basedrum, .note = 8, .powered = true};
case 315:
return {.instrument = instrument_type::basedrum, .note = 8, .powered = false};
case 316:
return {.instrument = instrument_type::basedrum, .note = 9, .powered = true};
case 317:
return {.instrument = instrument_type::basedrum, .note = 9, .powered = false};
case 318:
return {.instrument = instrument_type::basedrum, .note = 10, .powered = true};
case 319:
return {.instrument = instrument_type::basedrum, .note = 10, .powered = false};
case 320:
return {.instrument = instrument_type::basedrum, .note = 11, .powered = true};
case 321:
return {.instrument = instrument_type::basedrum, .note = 11, .powered = false};
case 322:
return {.instrument = instrument_type::basedrum, .note = 12, .powered = true};
case 323:
return {.instrument = instrument_type::basedrum, .note = 12, .powered = false};
case 324:
return {.instrument = instrument_type::basedrum, .note = 13, .powered = true};
case 325:
return {.instrument = instrument_type::basedrum, .note = 13, .powered = false};
case 326:
return {.instrument = instrument_type::basedrum, .note = 14, .powered = true};
case 327:
return {.instrument = instrument_type::basedrum, .note = 14, .powered = false};
case 328:
return {.instrument = instrument_type::basedrum, .note = 15, .powered = true};
case 329:
return {.instrument = instrument_type::basedrum, .note = 15, .powered = false};
case 330:
return {.instrument = instrument_type::basedrum, .note = 16, .powered = true};
case 331:
return {.instrument = instrument_type::basedrum, .note = 16, .powered = false};
case 332:
return {.instrument = instrument_type::basedrum, .note = 17, .powered = true};
case 333:
return {.instrument = instrument_type::basedrum, .note = 17, .powered = false};
case 334:
return {.instrument = instrument_type::basedrum, .note = 18, .powered = true};
case 335:
return {.instrument = instrument_type::basedrum, .note = 18, .powered = false};
case 336:
return {.instrument = instrument_type::basedrum, .note = 19, .powered = true};
case 337:
return {.instrument = instrument_type::basedrum, .note = 19, .powered = false};
case 338:
return {.instrument = instrument_type::basedrum, .note = 20, .powered = true};
case 339:
return {.instrument = instrument_type::basedrum, .note = 20, .powered = false};
case 340:
return {.instrument = instrument_type::basedrum, .note = 21, .powered = true};
case 341:
return {.instrument = instrument_type::basedrum, .note = 21, .powered = false};
case 342:
return {.instrument = instrument_type::basedrum, .note = 22, .powered = true};
case 343:
return {.instrument = instrument_type::basedrum, .note = 22, .powered = false};
case 344:
return {.instrument = instrument_type::basedrum, .note = 23, .powered = true};
case 345:
return {.instrument = instrument_type::basedrum, .note = 23, .powered = false};
case 346:
return {.instrument = instrument_type::basedrum, .note = 24, .powered = true};
case 347:
return {.instrument = instrument_type::basedrum, .note = 24, .powered = false};
case 348:
return {.instrument = instrument_type::snare, .note = 0, .powered = true};
case 349:
return {.instrument = instrument_type::snare, .note = 0, .powered = false};
case 350:
return {.instrument = instrument_type::snare, .note = 1, .powered = true};
case 351:
return {.instrument = instrument_type::snare, .note = 1, .powered = false};
case 352:
return {.instrument = instrument_type::snare, .note = 2, .powered = true};
case 353:
return {.instrument = instrument_type::snare, .note = 2, .powered = false};
case 354:
return {.instrument = instrument_type::snare, .note = 3, .powered = true};
case 355:
return {.instrument = instrument_type::snare, .note = 3, .powered = false};
case 356:
return {.instrument = instrument_type::snare, .note = 4, .powered = true};
case 357:
return {.instrument = instrument_type::snare, .note = 4, .powered = false};
case 358:
return {.instrument = instrument_type::snare, .note = 5, .powered = true};
case 359:
return {.instrument = instrument_type::snare, .note = 5, .powered = false};
case 360:
return {.instrument = instrument_type::snare, .note = 6, .powered = true};
case 361:
return {.instrument = instrument_type::snare, .note = 6, .powered = false};
case 362:
return {.instrument = instrument_type::snare, .note = 7, .powered = true};
case 363:
return {.instrument = instrument_type::snare, .note = 7, .powered = false};
case 364:
return {.instrument = instrument_type::snare, .note = 8, .powered = true};
case 365:
return {.instrument = instrument_type::snare, .note = 8, .powered = false};
case 366:
return {.instrument = instrument_type::snare, .note = 9, .powered = true};
case 367:
return {.instrument = instrument_type::snare, .note = 9, .powered = false};
case 368:
return {.instrument = instrument_type::snare, .note = 10, .powered = true};
case 369:
return {.instrument = instrument_type::snare, .note = 10, .powered = false};
case 370:
return {.instrument = instrument_type::snare, .note = 11, .powered = true};
case 371:
return {.instrument = instrument_type::snare, .note = 11, .powered = false};
case 372:
return {.instrument = instrument_type::snare, .note = 12, .powered = true};
case 373:
return {.instrument = instrument_type::snare, .note = 12, .powered = false};
case 374:
return {.instrument = instrument_type::snare, .note = 13, .powered = true};
case 375:
return {.instrument = instrument_type::snare, .note = 13, .powered = false};
case 376:
return {.instrument = instrument_type::snare, .note = 14, .powered = true};
case 377:
return {.instrument = instrument_type::snare, .note = 14, .powered = false};
case 378:
return {.instrument = instrument_type::snare, .note = 15, .powered = true};
case 379:
return {.instrument = instrument_type::snare, .note = 15, .powered = false};
case 380:
return {.instrument = instrument_type::snare, .note = 16, .powered = true};
case 381:
return {.instrument = instrument_type::snare, .note = 16, .powered = false};
case 382:
return {.instrument = instrument_type::snare, .note = 17, .powered = true};
case 383:
return {.instrument = instrument_type::snare, .note = 17, .powered = false};
case 384:
return {.instrument = instrument_type::snare, .note = 18, .powered = true};
case 385:
return {.instrument = instrument_type::snare, .note = 18, .powered = false};
case 386:
return {.instrument = instrument_type::snare, .note = 19, .powered = true};
case 387:
return {.instrument = instrument_type::snare, .note = 19, .powered = false};
case 388:
return {.instrument = instrument_type::snare, .note = 20, .powered = true};
case 389:
return {.instrument = instrument_type::snare, .note = 20, .powered = false};
case 390:
return {.instrument = instrument_type::snare, .note = 21, .powered = true};
case 391:
return {.instrument = instrument_type::snare, .note = 21, .powered = false};
case 392:
return {.instrument = instrument_type::snare, .note = 22, .powered = true};
case 393:
return {.instrument = instrument_type::snare, .note = 22, .powered = false};
case 394:
return {.instrument = instrument_type::snare, .note = 23, .powered = true};
case 395:
return {.instrument = instrument_type::snare, .note = 23, .powered = false};
case 396:
return {.instrument = instrument_type::snare, .note = 24, .powered = true};
case 397:
return {.instrument = instrument_type::snare, .note = 24, .powered = false};
case 398:
return {.instrument = instrument_type::hat, .note = 0, .powered = true};
case 399:
return {.instrument = instrument_type::hat, .note = 0, .powered = false};
case 400:
return {.instrument = instrument_type::hat, .note = 1, .powered = true};
case 401:
return {.instrument = instrument_type::hat, .note = 1, .powered = false};
case 402:
return {.instrument = instrument_type::hat, .note = 2, .powered = true};
case 403:
return {.instrument = instrument_type::hat, .note = 2, .powered = false};
case 404:
return {.instrument = instrument_type::hat, .note = 3, .powered = true};
case 405:
return {.instrument = instrument_type::hat, .note = 3, .powered = false};
case 406:
return {.instrument = instrument_type::hat, .note = 4, .powered = true};
case 407:
return {.instrument = instrument_type::hat, .note = 4, .powered = false};
case 408:
return {.instrument = instrument_type::hat, .note = 5, .powered = true};
case 409:
return {.instrument = instrument_type::hat, .note = 5, .powered = false};
case 410:
return {.instrument = instrument_type::hat, .note = 6, .powered = true};
case 411:
return {.instrument = instrument_type::hat, .note = 6, .powered = false};
case 412:
return {.instrument = instrument_type::hat, .note = 7, .powered = true};
case 413:
return {.instrument = instrument_type::hat, .note = 7, .powered = false};
case 414:
return {.instrument = instrument_type::hat, .note = 8, .powered = true};
case 415:
return {.instrument = instrument_type::hat, .note = 8, .powered = false};
case 416:
return {.instrument = instrument_type::hat, .note = 9, .powered = true};
case 417:
return {.instrument = instrument_type::hat, .note = 9, .powered = false};
case 418:
return {.instrument = instrument_type::hat, .note = 10, .powered = true};
case 419:
return {.instrument = instrument_type::hat, .note = 10, .powered = false};
case 420:
return {.instrument = instrument_type::hat, .note = 11, .powered = true};
case 421:
return {.instrument = instrument_type::hat, .note = 11, .powered = false};
case 422:
return {.instrument = instrument_type::hat, .note = 12, .powered = true};
case 423:
return {.instrument = instrument_type::hat, .note = 12, .powered = false};
case 424:
return {.instrument = instrument_type::hat, .note = 13, .powered = true};
case 425:
return {.instrument = instrument_type::hat, .note = 13, .powered = false};
case 426:
return {.instrument = instrument_type::hat, .note = 14, .powered = true};
case 427:
return {.instrument = instrument_type::hat, .note = 14, .powered = false};
case 428:
return {.instrument = instrument_type::hat, .note = 15, .powered = true};
case 429:
return {.instrument = instrument_type::hat, .note = 15, .powered = false};
case 430:
return {.instrument = instrument_type::hat, .note = 16, .powered = true};
case 431:
return {.instrument = instrument_type::hat, .note = 16, .powered = false};
case 432:
return {.instrument = instrument_type::hat, .note = 17, .powered = true};
case 433:
return {.instrument = instrument_type::hat, .note = 17, .powered = false};
case 434:
return {.instrument = instrument_type::hat, .note = 18, .powered = true};
case 435:
return {.instrument = instrument_type::hat, .note = 18, .powered = false};
case 436:
return {.instrument = instrument_type::hat, .note = 19, .powered = true};
case 437:
return {.instrument = instrument_type::hat, .note = 19, .powered = false};
case 438:
return {.instrument = instrument_type::hat, .note = 20, .powered = true};
case 439:
return {.instrument = instrument_type::hat, .note = 20, .powered = false};
case 440:
return {.instrument = instrument_type::hat, .note = 21, .powered = true};
case 441:
return {.instrument = instrument_type::hat, .note = 21, .powered = false};
case 442:
return {.instrument = instrument_type::hat, .note = 22, .powered = true};
case 443:
return {.instrument = instrument_type::hat, .note = 22, .powered = false};
case 444:
return {.instrument = instrument_type::hat, .note = 23, .powered = true};
case 445:
return {.instrument = instrument_type::hat, .note = 23, .powered = false};
case 446:
return {.instrument = instrument_type::hat, .note = 24, .powered = true};
case 447:
return {.instrument = instrument_type::hat, .note = 24, .powered = false};
case 448:
return {.instrument = instrument_type::bass, .note = 0, .powered = true};
case 449:
return {.instrument = instrument_type::bass, .note = 0, .powered = false};
case 450:
return {.instrument = instrument_type::bass, .note = 1, .powered = true};
case 451:
return {.instrument = instrument_type::bass, .note = 1, .powered = false};
case 452:
return {.instrument = instrument_type::bass, .note = 2, .powered = true};
case 453:
return {.instrument = instrument_type::bass, .note = 2, .powered = false};
case 454:
return {.instrument = instrument_type::bass, .note = 3, .powered = true};
case 455:
return {.instrument = instrument_type::bass, .note = 3, .powered = false};
case 456:
return {.instrument = instrument_type::bass, .note = 4, .powered = true};
case 457:
return {.instrument = instrument_type::bass, .note = 4, .powered = false};
case 458:
return {.instrument = instrument_type::bass, .note = 5, .powered = true};
case 459:
return {.instrument = instrument_type::bass, .note = 5, .powered = false};
case 460:
return {.instrument = instrument_type::bass, .note = 6, .powered = true};
case 461:
return {.instrument = instrument_type::bass, .note = 6, .powered = false};
case 462:
return {.instrument = instrument_type::bass, .note = 7, .powered = true};
case 463:
return {.instrument = instrument_type::bass, .note = 7, .powered = false};
case 464:
return {.instrument = instrument_type::bass, .note = 8, .powered = true};
case 465:
return {.instrument = instrument_type::bass, .note = 8, .powered = false};
case 466:
return {.instrument = instrument_type::bass, .note = 9, .powered = true};
case 467:
return {.instrument = instrument_type::bass, .note = 9, .powered = false};
case 468:
return {.instrument = instrument_type::bass, .note = 10, .powered = true};
case 469:
return {.instrument = instrument_type::bass, .note = 10, .powered = false};
case 470:
return {.instrument = instrument_type::bass, .note = 11, .powered = true};
case 471:
return {.instrument = instrument_type::bass, .note = 11, .powered = false};
case 472:
return {.instrument = instrument_type::bass, .note = 12, .powered = true};
case 473:
return {.instrument = instrument_type::bass, .note = 12, .powered = false};
case 474:
return {.instrument = instrument_type::bass, .note = 13, .powered = true};
case 475:
return {.instrument = instrument_type::bass, .note = 13, .powered = false};
case 476:
return {.instrument = instrument_type::bass, .note = 14, .powered = true};
case 477:
return {.instrument = instrument_type::bass, .note = 14, .powered = false};
case 478:
return {.instrument = instrument_type::bass, .note = 15, .powered = true};
case 479:
return {.instrument = instrument_type::bass, .note = 15, .powered = false};
case 480:
return {.instrument = instrument_type::bass, .note = 16, .powered = true};
case 481:
return {.instrument = instrument_type::bass, .note = 16, .powered = false};
case 482:
return {.instrument = instrument_type::bass, .note = 17, .powered = true};
case 483:
return {.instrument = instrument_type::bass, .note = 17, .powered = false};
case 484:
return {.instrument = instrument_type::bass, .note = 18, .powered = true};
case 485:
return {.instrument = instrument_type::bass, .note = 18, .powered = false};
case 486:
return {.instrument = instrument_type::bass, .note = 19, .powered = true};
case 487:
return {.instrument = instrument_type::bass, .note = 19, .powered = false};
case 488:
return {.instrument = instrument_type::bass, .note = 20, .powered = true};
case 489:
return {.instrument = instrument_type::bass, .note = 20, .powered = false};
case 490:
return {.instrument = instrument_type::bass, .note = 21, .powered = true};
case 491:
return {.instrument = instrument_type::bass, .note = 21, .powered = false};
case 492:
return {.instrument = instrument_type::bass, .note = 22, .powered = true};
case 493:
return {.instrument = instrument_type::bass, .note = 22, .powered = false};
case 494:
return {.instrument = instrument_type::bass, .note = 23, .powered = true};
case 495:
return {.instrument = instrument_type::bass, .note = 23, .powered = false};
case 496:
return {.instrument = instrument_type::bass, .note = 24, .powered = true};
case 497:
return {.instrument = instrument_type::bass, .note = 24, .powered = false};
case 498:
return {.instrument = instrument_type::flute, .note = 0, .powered = true};
case 499:
return {.instrument = instrument_type::flute, .note = 0, .powered = false};
case 500:
return {.instrument = instrument_type::flute, .note = 1, .powered = true};
case 501:
return {.instrument = instrument_type::flute, .note = 1, .powered = false};
case 502:
return {.instrument = instrument_type::flute, .note = 2, .powered = true};
case 503:
return {.instrument = instrument_type::flute, .note = 2, .powered = false};
case 504:
return {.instrument = instrument_type::flute, .note = 3, .powered = true};
case 505:
return {.instrument = instrument_type::flute, .note = 3, .powered = false};
case 506:
return {.instrument = instrument_type::flute, .note = 4, .powered = true};
case 507:
return {.instrument = instrument_type::flute, .note = 4, .powered = false};
case 508:
return {.instrument = instrument_type::flute, .note = 5, .powered = true};
case 509:
return {.instrument = instrument_type::flute, .note = 5, .powered = false};
case 510:
return {.instrument = instrument_type::flute, .note = 6, .powered = true};
case 511:
return {.instrument = instrument_type::flute, .note = 6, .powered = false};
case 512:
return {.instrument = instrument_type::flute, .note = 7, .powered = true};
case 513:
return {.instrument = instrument_type::flute, .note = 7, .powered = false};
case 514:
return {.instrument = instrument_type::flute, .note = 8, .powered = true};
case 515:
return {.instrument = instrument_type::flute, .note = 8, .powered = false};
case 516:
return {.instrument = instrument_type::flute, .note = 9, .powered = true};
case 517:
return {.instrument = instrument_type::flute, .note = 9, .powered = false};
case 518:
return {.instrument = instrument_type::flute, .note = 10, .powered = true};
case 519:
return {.instrument = instrument_type::flute, .note = 10, .powered = false};
case 520:
return {.instrument = instrument_type::flute, .note = 11, .powered = true};
case 521:
return {.instrument = instrument_type::flute, .note = 11, .powered = false};
case 522:
return {.instrument = instrument_type::flute, .note = 12, .powered = true};
case 523:
return {.instrument = instrument_type::flute, .note = 12, .powered = false};
case 524:
return {.instrument = instrument_type::flute, .note = 13, .powered = true};
case 525:
return {.instrument = instrument_type::flute, .note = 13, .powered = false};
case 526:
return {.instrument = instrument_type::flute, .note = 14, .powered = true};
case 527:
return {.instrument = instrument_type::flute, .note = 14, .powered = false};
case 528:
return {.instrument = instrument_type::flute, .note = 15, .powered = true};
case 529:
return {.instrument = instrument_type::flute, .note = 15, .powered = false};
case 530:
return {.instrument = instrument_type::flute, .note = 16, .powered = true};
case 531:
return {.instrument = instrument_type::flute, .note = 16, .powered = false};
case 532:
return {.instrument = instrument_type::flute, .note = 17, .powered = true};
case 533:
return {.instrument = instrument_type::flute, .note = 17, .powered = false};
case 534:
return {.instrument = instrument_type::flute, .note = 18, .powered = true};
case 535:
return {.instrument = instrument_type::flute, .note = 18, .powered = false};
case 536:
return {.instrument = instrument_type::flute, .note = 19, .powered = true};
case 537:
return {.instrument = instrument_type::flute, .note = 19, .powered = false};
case 538:
return {.instrument = instrument_type::flute, .note = 20, .powered = true};
case 539:
return {.instrument = instrument_type::flute, .note = 20, .powered = false};
case 540:
return {.instrument = instrument_type::flute, .note = 21, .powered = true};
case 541:
return {.instrument = instrument_type::flute, .note = 21, .powered = false};
case 542:
return {.instrument = instrument_type::flute, .note = 22, .powered = true};
case 543:
return {.instrument = instrument_type::flute, .note = 22, .powered = false};
case 544:
return {.instrument = instrument_type::flute, .note = 23, .powered = true};
case 545:
return {.instrument = instrument_type::flute, .note = 23, .powered = false};
case 546:
return {.instrument = instrument_type::flute, .note = 24, .powered = true};
case 547:
return {.instrument = instrument_type::flute, .note = 24, .powered = false};
case 548:
return {.instrument = instrument_type::bell, .note = 0, .powered = true};
case 549:
return {.instrument = instrument_type::bell, .note = 0, .powered = false};
case 550:
return {.instrument = instrument_type::bell, .note = 1, .powered = true};
case 551:
return {.instrument = instrument_type::bell, .note = 1, .powered = false};
case 552:
return {.instrument = instrument_type::bell, .note = 2, .powered = true};
case 553:
return {.instrument = instrument_type::bell, .note = 2, .powered = false};
case 554:
return {.instrument = instrument_type::bell, .note = 3, .powered = true};
case 555:
return {.instrument = instrument_type::bell, .note = 3, .powered = false};
case 556:
return {.instrument = instrument_type::bell, .note = 4, .powered = true};
case 557:
return {.instrument = instrument_type::bell, .note = 4, .powered = false};
case 558:
return {.instrument = instrument_type::bell, .note = 5, .powered = true};
case 559:
return {.instrument = instrument_type::bell, .note = 5, .powered = false};
case 560:
return {.instrument = instrument_type::bell, .note = 6, .powered = true};
case 561:
return {.instrument = instrument_type::bell, .note = 6, .powered = false};
case 562:
return {.instrument = instrument_type::bell, .note = 7, .powered = true};
case 563:
return {.instrument = instrument_type::bell, .note = 7, .powered = false};
case 564:
return {.instrument = instrument_type::bell, .note = 8, .powered = true};
case 565:
return {.instrument = instrument_type::bell, .note = 8, .powered = false};
case 566:
return {.instrument = instrument_type::bell, .note = 9, .powered = true};
case 567:
return {.instrument = instrument_type::bell, .note = 9, .powered = false};
case 568:
return {.instrument = instrument_type::bell, .note = 10, .powered = true};
case 569:
return {.instrument = instrument_type::bell, .note = 10, .powered = false};
case 570:
return {.instrument = instrument_type::bell, .note = 11, .powered = true};
case 571:
return {.instrument = instrument_type::bell, .note = 11, .powered = false};
case 572:
return {.instrument = instrument_type::bell, .note = 12, .powered = true};
case 573:
return {.instrument = instrument_type::bell, .note = 12, .powered = false};
case 574:
return {.instrument = instrument_type::bell, .note = 13, .powered = true};
case 575:
return {.instrument = instrument_type::bell, .note = 13, .powered = false};
case 576:
return {.instrument = instrument_type::bell, .note = 14, .powered = true};
case 577:
return {.instrument = instrument_type::bell, .note = 14, .powered = false};
case 578:
return {.instrument = instrument_type::bell, .note = 15, .powered = true};
case 579:
return {.instrument = instrument_type::bell, .note = 15, .powered = false};
case 580:
return {.instrument = instrument_type::bell, .note = 16, .powered = true};
case 581:
return {.instrument = instrument_type::bell, .note = 16, .powered = false};
case 582:
return {.instrument = instrument_type::bell, .note = 17, .powered = true};
case 583:
return {.instrument = instrument_type::bell, .note = 17, .powered = false};
case 584:
return {.instrument = instrument_type::bell, .note = 18, .powered = true};
case 585:
return {.instrument = instrument_type::bell, .note = 18, .powered = false};
case 586:
return {.instrument = instrument_type::bell, .note = 19, .powered = true};
case 587:
return {.instrument = instrument_type::bell, .note = 19, .powered = false};
case 588:
return {.instrument = instrument_type::bell, .note = 20, .powered = true};
case 589:
return {.instrument = instrument_type::bell, .note = 20, .powered = false};
case 590:
return {.instrument = instrument_type::bell, .note = 21, .powered = true};
case 591:
return {.instrument = instrument_type::bell, .note = 21, .powered = false};
case 592:
return {.instrument = instrument_type::bell, .note = 22, .powered = true};
case 593:
return {.instrument = instrument_type::bell, .note = 22, .powered = false};
case 594:
return {.instrument = instrument_type::bell, .note = 23, .powered = true};
case 595:
return {.instrument = instrument_type::bell, .note = 23, .powered = false};
case 596:
return {.instrument = instrument_type::bell, .note = 24, .powered = true};
case 597:
return {.instrument = instrument_type::bell, .note = 24, .powered = false};
case 598:
return {.instrument = instrument_type::guitar, .note = 0, .powered = true};
case 599:
return {.instrument = instrument_type::guitar, .note = 0, .powered = false};
case 600:
return {.instrument = instrument_type::guitar, .note = 1, .powered = true};
case 601:
return {.instrument = instrument_type::guitar, .note = 1, .powered = false};
case 602:
return {.instrument = instrument_type::guitar, .note = 2, .powered = true};
case 603:
return {.instrument = instrument_type::guitar, .note = 2, .powered = false};
case 604:
return {.instrument = instrument_type::guitar, .note = 3, .powered = true};
case 605:
return {.instrument = instrument_type::guitar, .note = 3, .powered = false};
case 606:
return {.instrument = instrument_type::guitar, .note = 4, .powered = true};
case 607:
return {.instrument = instrument_type::guitar, .note = 4, .powered = false};
case 608:
return {.instrument = instrument_type::guitar, .note = 5, .powered = true};
case 609:
return {.instrument = instrument_type::guitar, .note = 5, .powered = false};
case 610:
return {.instrument = instrument_type::guitar, .note = 6, .powered = true};
case 611:
return {.instrument = instrument_type::guitar, .note = 6, .powered = false};
case 612:
return {.instrument = instrument_type::guitar, .note = 7, .powered = true};
case 613:
return {.instrument = instrument_type::guitar, .note = 7, .powered = false};
case 614:
return {.instrument = instrument_type::guitar, .note = 8, .powered = true};
case 615:
return {.instrument = instrument_type::guitar, .note = 8, .powered = false};
case 616:
return {.instrument = instrument_type::guitar, .note = 9, .powered = true};
case 617:
return {.instrument = instrument_type::guitar, .note = 9, .powered = false};
case 618:
return {.instrument = instrument_type::guitar, .note = 10, .powered = true};
case 619:
return {.instrument = instrument_type::guitar, .note = 10, .powered = false};
case 620:
return {.instrument = instrument_type::guitar, .note = 11, .powered = true};
case 621:
return {.instrument = instrument_type::guitar, .note = 11, .powered = false};
case 622:
return {.instrument = instrument_type::guitar, .note = 12, .powered = true};
case 623:
return {.instrument = instrument_type::guitar, .note = 12, .powered = false};
case 624:
return {.instrument = instrument_type::guitar, .note = 13, .powered = true};
case 625:
return {.instrument = instrument_type::guitar, .note = 13, .powered = false};
case 626:
return {.instrument = instrument_type::guitar, .note = 14, .powered = true};
case 627:
return {.instrument = instrument_type::guitar, .note = 14, .powered = false};
case 628:
return {.instrument = instrument_type::guitar, .note = 15, .powered = true};
case 629:
return {.instrument = instrument_type::guitar, .note = 15, .powered = false};
case 630:
return {.instrument = instrument_type::guitar, .note = 16, .powered = true};
case 631:
return {.instrument = instrument_type::guitar, .note = 16, .powered = false};
case 632:
return {.instrument = instrument_type::guitar, .note = 17, .powered = true};
case 633:
return {.instrument = instrument_type::guitar, .note = 17, .powered = false};
case 634:
return {.instrument = instrument_type::guitar, .note = 18, .powered = true};
case 635:
return {.instrument = instrument_type::guitar, .note = 18, .powered = false};
case 636:
return {.instrument = instrument_type::guitar, .note = 19, .powered = true};
case 637:
return {.instrument = instrument_type::guitar, .note = 19, .powered = false};
case 638:
return {.instrument = instrument_type::guitar, .note = 20, .powered = true};
case 639:
return {.instrument = instrument_type::guitar, .note = 20, .powered = false};
case 640:
return {.instrument = instrument_type::guitar, .note = 21, .powered = true};
case 641:
return {.instrument = instrument_type::guitar, .note = 21, .powered = false};
case 642:
return {.instrument = instrument_type::guitar, .note = 22, .powered = true};
case 643:
return {.instrument = instrument_type::guitar, .note = 22, .powered = false};
case 644:
return {.instrument = instrument_type::guitar, .note = 23, .powered = true};
case 645:
return {.instrument = instrument_type::guitar, .note = 23, .powered = false};
case 646:
return {.instrument = instrument_type::guitar, .note = 24, .powered = true};
case 647:
return {.instrument = instrument_type::guitar, .note = 24, .powered = false};
case 648:
return {.instrument = instrument_type::chime, .note = 0, .powered = true};
case 649:
return {.instrument = instrument_type::chime, .note = 0, .powered = false};
case 650:
return {.instrument = instrument_type::chime, .note = 1, .powered = true};
case 651:
return {.instrument = instrument_type::chime, .note = 1, .powered = false};
case 652:
return {.instrument = instrument_type::chime, .note = 2, .powered = true};
case 653:
return {.instrument = instrument_type::chime, .note = 2, .powered = false};
case 654:
return {.instrument = instrument_type::chime, .note = 3, .powered = true};
case 655:
return {.instrument = instrument_type::chime, .note = 3, .powered = false};
case 656:
return {.instrument = instrument_type::chime, .note = 4, .powered = true};
case 657:
return {.instrument = instrument_type::chime, .note = 4, .powered = false};
case 658:
return {.instrument = instrument_type::chime, .note = 5, .powered = true};
case 659:
return {.instrument = instrument_type::chime, .note = 5, .powered = false};
case 660:
return {.instrument = instrument_type::chime, .note = 6, .powered = true};
case 661:
return {.instrument = instrument_type::chime, .note = 6, .powered = false};
case 662:
return {.instrument = instrument_type::chime, .note = 7, .powered = true};
case 663:
return {.instrument = instrument_type::chime, .note = 7, .powered = false};
case 664:
return {.instrument = instrument_type::chime, .note = 8, .powered = true};
case 665:
return {.instrument = instrument_type::chime, .note = 8, .powered = false};
case 666:
return {.instrument = instrument_type::chime, .note = 9, .powered = true};
case 667:
return {.instrument = instrument_type::chime, .note = 9, .powered = false};
case 668:
return {.instrument = instrument_type::chime, .note = 10, .powered = true};
case 669:
return {.instrument = instrument_type::chime, .note = 10, .powered = false};
case 670:
return {.instrument = instrument_type::chime, .note = 11, .powered = true};
case 671:
return {.instrument = instrument_type::chime, .note = 11, .powered = false};
case 672:
return {.instrument = instrument_type::chime, .note = 12, .powered = true};
case 673:
return {.instrument = instrument_type::chime, .note = 12, .powered = false};
case 674:
return {.instrument = instrument_type::chime, .note = 13, .powered = true};
case 675:
return {.instrument = instrument_type::chime, .note = 13, .powered = false};
case 676:
return {.instrument = instrument_type::chime, .note = 14, .powered = true};
case 677:
return {.instrument = instrument_type::chime, .note = 14, .powered = false};
case 678:
return {.instrument = instrument_type::chime, .note = 15, .powered = true};
case 679:
return {.instrument = instrument_type::chime, .note = 15, .powered = false};
case 680:
return {.instrument = instrument_type::chime, .note = 16, .powered = true};
case 681:
return {.instrument = instrument_type::chime, .note = 16, .powered = false};
case 682:
return {.instrument = instrument_type::chime, .note = 17, .powered = true};
case 683:
return {.instrument = instrument_type::chime, .note = 17, .powered = false};
case 684:
return {.instrument = instrument_type::chime, .note = 18, .powered = true};
case 685:
return {.instrument = instrument_type::chime, .note = 18, .powered = false};
case 686:
return {.instrument = instrument_type::chime, .note = 19, .powered = true};
case 687:
return {.instrument = instrument_type::chime, .note = 19, .powered = false};
case 688:
return {.instrument = instrument_type::chime, .note = 20, .powered = true};
case 689:
return {.instrument = instrument_type::chime, .note = 20, .powered = false};
case 690:
return {.instrument = instrument_type::chime, .note = 21, .powered = true};
case 691:
return {.instrument = instrument_type::chime, .note = 21, .powered = false};
case 692:
return {.instrument = instrument_type::chime, .note = 22, .powered = true};
case 693:
return {.instrument = instrument_type::chime, .note = 22, .powered = false};
case 694:
return {.instrument = instrument_type::chime, .note = 23, .powered = true};
case 695:
return {.instrument = instrument_type::chime, .note = 23, .powered = false};
case 696:
return {.instrument = instrument_type::chime, .note = 24, .powered = true};
case 697:
return {.instrument = instrument_type::chime, .note = 24, .powered = false};
case 698:
return {.instrument = instrument_type::xylophone, .note = 0, .powered = true};
case 699:
return {.instrument = instrument_type::xylophone, .note = 0, .powered = false};
case 700:
return {.instrument = instrument_type::xylophone, .note = 1, .powered = true};
case 701:
return {.instrument = instrument_type::xylophone, .note = 1, .powered = false};
case 702:
return {.instrument = instrument_type::xylophone, .note = 2, .powered = true};
case 703:
return {.instrument = instrument_type::xylophone, .note = 2, .powered = false};
case 704:
return {.instrument = instrument_type::xylophone, .note = 3, .powered = true};
case 705:
return {.instrument = instrument_type::xylophone, .note = 3, .powered = false};
case 706:
return {.instrument = instrument_type::xylophone, .note = 4, .powered = true};
case 707:
return {.instrument = instrument_type::xylophone, .note = 4, .powered = false};
case 708:
return {.instrument = instrument_type::xylophone, .note = 5, .powered = true};
case 709:
return {.instrument = instrument_type::xylophone, .note = 5, .powered = false};
case 710:
return {.instrument = instrument_type::xylophone, .note = 6, .powered = true};
case 711:
return {.instrument = instrument_type::xylophone, .note = 6, .powered = false};
case 712:
return {.instrument = instrument_type::xylophone, .note = 7, .powered = true};
case 713:
return {.instrument = instrument_type::xylophone, .note = 7, .powered = false};
case 714:
return {.instrument = instrument_type::xylophone, .note = 8, .powered = true};
case 715:
return {.instrument = instrument_type::xylophone, .note = 8, .powered = false};
case 716:
return {.instrument = instrument_type::xylophone, .note = 9, .powered = true};
case 717:
return {.instrument = instrument_type::xylophone, .note = 9, .powered = false};
case 718:
return {.instrument = instrument_type::xylophone, .note = 10, .powered = true};
case 719:
return {.instrument = instrument_type::xylophone, .note = 10, .powered = false};
case 720:
return {.instrument = instrument_type::xylophone, .note = 11, .powered = true};
case 721:
return {.instrument = instrument_type::xylophone, .note = 11, .powered = false};
case 722:
return {.instrument = instrument_type::xylophone, .note = 12, .powered = true};
case 723:
return {.instrument = instrument_type::xylophone, .note = 12, .powered = false};
case 724:
return {.instrument = instrument_type::xylophone, .note = 13, .powered = true};
case 725:
return {.instrument = instrument_type::xylophone, .note = 13, .powered = false};
case 726:
return {.instrument = instrument_type::xylophone, .note = 14, .powered = true};
case 727:
return {.instrument = instrument_type::xylophone, .note = 14, .powered = false};
case 728:
return {.instrument = instrument_type::xylophone, .note = 15, .powered = true};
case 729:
return {.instrument = instrument_type::xylophone, .note = 15, .powered = false};
case 730:
return {.instrument = instrument_type::xylophone, .note = 16, .powered = true};
case 731:
return {.instrument = instrument_type::xylophone, .note = 16, .powered = false};
case 732:
return {.instrument = instrument_type::xylophone, .note = 17, .powered = true};
case 733:
return {.instrument = instrument_type::xylophone, .note = 17, .powered = false};
case 734:
return {.instrument = instrument_type::xylophone, .note = 18, .powered = true};
case 735:
return {.instrument = instrument_type::xylophone, .note = 18, .powered = false};
case 736:
return {.instrument = instrument_type::xylophone, .note = 19, .powered = true};
case 737:
return {.instrument = instrument_type::xylophone, .note = 19, .powered = false};
case 738:
return {.instrument = instrument_type::xylophone, .note = 20, .powered = true};
case 739:
return {.instrument = instrument_type::xylophone, .note = 20, .powered = false};
case 740:
return {.instrument = instrument_type::xylophone, .note = 21, .powered = true};
case 741:
return {.instrument = instrument_type::xylophone, .note = 21, .powered = false};
case 742:
return {.instrument = instrument_type::xylophone, .note = 22, .powered = true};
case 743:
return {.instrument = instrument_type::xylophone, .note = 22, .powered = false};
case 744:
return {.instrument = instrument_type::xylophone, .note = 23, .powered = true};
case 745:
return {.instrument = instrument_type::xylophone, .note = 23, .powered = false};
case 746:
return {.instrument = instrument_type::xylophone, .note = 24, .powered = true};
case 747:
return {.instrument = instrument_type::xylophone, .note = 24, .powered = false};
case 748:
return {.instrument = instrument_type::iron_xylophone, .note = 0, .powered = true};
case 749:
return {.instrument = instrument_type::iron_xylophone, .note = 0, .powered = false};
case 750:
return {.instrument = instrument_type::iron_xylophone, .note = 1, .powered = true};
case 751:
return {.instrument = instrument_type::iron_xylophone, .note = 1, .powered = false};
case 752:
return {.instrument = instrument_type::iron_xylophone, .note = 2, .powered = true};
case 753:
return {.instrument = instrument_type::iron_xylophone, .note = 2, .powered = false};
case 754:
return {.instrument = instrument_type::iron_xylophone, .note = 3, .powered = true};
case 755:
return {.instrument = instrument_type::iron_xylophone, .note = 3, .powered = false};
case 756:
return {.instrument = instrument_type::iron_xylophone, .note = 4, .powered = true};
case 757:
return {.instrument = instrument_type::iron_xylophone, .note = 4, .powered = false};
case 758:
return {.instrument = instrument_type::iron_xylophone, .note = 5, .powered = true};
case 759:
return {.instrument = instrument_type::iron_xylophone, .note = 5, .powered = false};
case 760:
return {.instrument = instrument_type::iron_xylophone, .note = 6, .powered = true};
case 761:
return {.instrument = instrument_type::iron_xylophone, .note = 6, .powered = false};
case 762:
return {.instrument = instrument_type::iron_xylophone, .note = 7, .powered = true};
case 763:
return {.instrument = instrument_type::iron_xylophone, .note = 7, .powered = false};
case 764:
return {.instrument = instrument_type::iron_xylophone, .note = 8, .powered = true};
case 765:
return {.instrument = instrument_type::iron_xylophone, .note = 8, .powered = false};
case 766:
return {.instrument = instrument_type::iron_xylophone, .note = 9, .powered = true};
case 767:
return {.instrument = instrument_type::iron_xylophone, .note = 9, .powered = false};
case 768:
return {.instrument = instrument_type::iron_xylophone, .note = 10, .powered = true};
case 769:
return {.instrument = instrument_type::iron_xylophone, .note = 10, .powered = false};
case 770:
return {.instrument = instrument_type::iron_xylophone, .note = 11, .powered = true};
case 771:
return {.instrument = instrument_type::iron_xylophone, .note = 11, .powered = false};
case 772:
return {.instrument = instrument_type::iron_xylophone, .note = 12, .powered = true};
case 773:
return {.instrument = instrument_type::iron_xylophone, .note = 12, .powered = false};
case 774:
return {.instrument = instrument_type::iron_xylophone, .note = 13, .powered = true};
case 775:
return {.instrument = instrument_type::iron_xylophone, .note = 13, .powered = false};
case 776:
return {.instrument = instrument_type::iron_xylophone, .note = 14, .powered = true};
case 777:
return {.instrument = instrument_type::iron_xylophone, .note = 14, .powered = false};
case 778:
return {.instrument = instrument_type::iron_xylophone, .note = 15, .powered = true};
case 779:
return {.instrument = instrument_type::iron_xylophone, .note = 15, .powered = false};
case 780:
return {.instrument = instrument_type::iron_xylophone, .note = 16, .powered = true};
case 781:
return {.instrument = instrument_type::iron_xylophone, .note = 16, .powered = false};
case 782:
return {.instrument = instrument_type::iron_xylophone, .note = 17, .powered = true};
case 783:
return {.instrument = instrument_type::iron_xylophone, .note = 17, .powered = false};
case 784:
return {.instrument = instrument_type::iron_xylophone, .note = 18, .powered = true};
case 785:
return {.instrument = instrument_type::iron_xylophone, .note = 18, .powered = false};
case 786:
return {.instrument = instrument_type::iron_xylophone, .note = 19, .powered = true};
case 787:
return {.instrument = instrument_type::iron_xylophone, .note = 19, .powered = false};
case 788:
return {.instrument = instrument_type::iron_xylophone, .note = 20, .powered = true};
case 789:
return {.instrument = instrument_type::iron_xylophone, .note = 20, .powered = false};
case 790:
return {.instrument = instrument_type::iron_xylophone, .note = 21, .powered = true};
case 791:
return {.instrument = instrument_type::iron_xylophone, .note = 21, .powered = false};
case 792:
return {.instrument = instrument_type::iron_xylophone, .note = 22, .powered = true};
case 793:
return {.instrument = instrument_type::iron_xylophone, .note = 22, .powered = false};
case 794:
return {.instrument = instrument_type::iron_xylophone, .note = 23, .powered = true};
case 795:
return {.instrument = instrument_type::iron_xylophone, .note = 23, .powered = false};
case 796:
return {.instrument = instrument_type::iron_xylophone, .note = 24, .powered = true};
case 797:
return {.instrument = instrument_type::iron_xylophone, .note = 24, .powered = false};
case 798:
return {.instrument = instrument_type::cow_bell, .note = 0, .powered = true};
case 799:
return {.instrument = instrument_type::cow_bell, .note = 0, .powered = false};
case 800:
return {.instrument = instrument_type::cow_bell, .note = 1, .powered = true};
case 801:
return {.instrument = instrument_type::cow_bell, .note = 1, .powered = false};
case 802:
return {.instrument = instrument_type::cow_bell, .note = 2, .powered = true};
case 803:
return {.instrument = instrument_type::cow_bell, .note = 2, .powered = false};
case 804:
return {.instrument = instrument_type::cow_bell, .note = 3, .powered = true};
case 805:
return {.instrument = instrument_type::cow_bell, .note = 3, .powered = false};
case 806:
return {.instrument = instrument_type::cow_bell, .note = 4, .powered = true};
case 807:
return {.instrument = instrument_type::cow_bell, .note = 4, .powered = false};
case 808:
return {.instrument = instrument_type::cow_bell, .note = 5, .powered = true};
case 809:
return {.instrument = instrument_type::cow_bell, .note = 5, .powered = false};
case 810:
return {.instrument = instrument_type::cow_bell, .note = 6, .powered = true};
case 811:
return {.instrument = instrument_type::cow_bell, .note = 6, .powered = false};
case 812:
return {.instrument = instrument_type::cow_bell, .note = 7, .powered = true};
case 813:
return {.instrument = instrument_type::cow_bell, .note = 7, .powered = false};
case 814:
return {.instrument = instrument_type::cow_bell, .note = 8, .powered = true};
case 815:
return {.instrument = instrument_type::cow_bell, .note = 8, .powered = false};
case 816:
return {.instrument = instrument_type::cow_bell, .note = 9, .powered = true};
case 817:
return {.instrument = instrument_type::cow_bell, .note = 9, .powered = false};
case 818:
return {.instrument = instrument_type::cow_bell, .note = 10, .powered = true};
case 819:
return {.instrument = instrument_type::cow_bell, .note = 10, .powered = false};
case 820:
return {.instrument = instrument_type::cow_bell, .note = 11, .powered = true};
case 821:
return {.instrument = instrument_type::cow_bell, .note = 11, .powered = false};
case 822:
return {.instrument = instrument_type::cow_bell, .note = 12, .powered = true};
case 823:
return {.instrument = instrument_type::cow_bell, .note = 12, .powered = false};
case 824:
return {.instrument = instrument_type::cow_bell, .note = 13, .powered = true};
case 825:
return {.instrument = instrument_type::cow_bell, .note = 13, .powered = false};
case 826:
return {.instrument = instrument_type::cow_bell, .note = 14, .powered = true};
case 827:
return {.instrument = instrument_type::cow_bell, .note = 14, .powered = false};
case 828:
return {.instrument = instrument_type::cow_bell, .note = 15, .powered = true};
case 829:
return {.instrument = instrument_type::cow_bell, .note = 15, .powered = false};
case 830:
return {.instrument = instrument_type::cow_bell, .note = 16, .powered = true};
case 831:
return {.instrument = instrument_type::cow_bell, .note = 16, .powered = false};
case 832:
return {.instrument = instrument_type::cow_bell, .note = 17, .powered = true};
case 833:
return {.instrument = instrument_type::cow_bell, .note = 17, .powered = false};
case 834:
return {.instrument = instrument_type::cow_bell, .note = 18, .powered = true};
case 835:
return {.instrument = instrument_type::cow_bell, .note = 18, .powered = false};
case 836:
return {.instrument = instrument_type::cow_bell, .note = 19, .powered = true};
case 837:
return {.instrument = instrument_type::cow_bell, .note = 19, .powered = false};
case 838:
return {.instrument = instrument_type::cow_bell, .note = 20, .powered = true};
case 839:
return {.instrument = instrument_type::cow_bell, .note = 20, .powered = false};
case 840:
return {.instrument = instrument_type::cow_bell, .note = 21, .powered = true};
case 841:
return {.instrument = instrument_type::cow_bell, .note = 21, .powered = false};
case 842:
return {.instrument = instrument_type::cow_bell, .note = 22, .powered = true};
case 843:
return {.instrument = instrument_type::cow_bell, .note = 22, .powered = false};
case 844:
return {.instrument = instrument_type::cow_bell, .note = 23, .powered = true};
case 845:
return {.instrument = instrument_type::cow_bell, .note = 23, .powered = false};
case 846:
return {.instrument = instrument_type::cow_bell, .note = 24, .powered = true};
case 847:
return {.instrument = instrument_type::cow_bell, .note = 24, .powered = false};
case 848:
return {.instrument = instrument_type::didgeridoo, .note = 0, .powered = true};
case 849:
return {.instrument = instrument_type::didgeridoo, .note = 0, .powered = false};
case 850:
return {.instrument = instrument_type::didgeridoo, .note = 1, .powered = true};
case 851:
return {.instrument = instrument_type::didgeridoo, .note = 1, .powered = false};
case 852:
return {.instrument = instrument_type::didgeridoo, .note = 2, .powered = true};
case 853:
return {.instrument = instrument_type::didgeridoo, .note = 2, .powered = false};
case 854:
return {.instrument = instrument_type::didgeridoo, .note = 3, .powered = true};
case 855:
return {.instrument = instrument_type::didgeridoo, .note = 3, .powered = false};
case 856:
return {.instrument = instrument_type::didgeridoo, .note = 4, .powered = true};
case 857:
return {.instrument = instrument_type::didgeridoo, .note = 4, .powered = false};
case 858:
return {.instrument = instrument_type::didgeridoo, .note = 5, .powered = true};
case 859:
return {.instrument = instrument_type::didgeridoo, .note = 5, .powered = false};
case 860:
return {.instrument = instrument_type::didgeridoo, .note = 6, .powered = true};
case 861:
return {.instrument = instrument_type::didgeridoo, .note = 6, .powered = false};
case 862:
return {.instrument = instrument_type::didgeridoo, .note = 7, .powered = true};
case 863:
return {.instrument = instrument_type::didgeridoo, .note = 7, .powered = false};
case 864:
return {.instrument = instrument_type::didgeridoo, .note = 8, .powered = true};
case 865:
return {.instrument = instrument_type::didgeridoo, .note = 8, .powered = false};
case 866:
return {.instrument = instrument_type::didgeridoo, .note = 9, .powered = true};
case 867:
return {.instrument = instrument_type::didgeridoo, .note = 9, .powered = false};
case 868:
return {.instrument = instrument_type::didgeridoo, .note = 10, .powered = true};
case 869:
return {.instrument = instrument_type::didgeridoo, .note = 10, .powered = false};
case 870:
return {.instrument = instrument_type::didgeridoo, .note = 11, .powered = true};
case 871:
return {.instrument = instrument_type::didgeridoo, .note = 11, .powered = false};
case 872:
return {.instrument = instrument_type::didgeridoo, .note = 12, .powered = true};
case 873:
return {.instrument = instrument_type::didgeridoo, .note = 12, .powered = false};
case 874:
return {.instrument = instrument_type::didgeridoo, .note = 13, .powered = true};
case 875:
return {.instrument = instrument_type::didgeridoo, .note = 13, .powered = false};
case 876:
return {.instrument = instrument_type::didgeridoo, .note = 14, .powered = true};
case 877:
return {.instrument = instrument_type::didgeridoo, .note = 14, .powered = false};
case 878:
return {.instrument = instrument_type::didgeridoo, .note = 15, .powered = true};
case 879:
return {.instrument = instrument_type::didgeridoo, .note = 15, .powered = false};
case 880:
return {.instrument = instrument_type::didgeridoo, .note = 16, .powered = true};
case 881:
return {.instrument = instrument_type::didgeridoo, .note = 16, .powered = false};
case 882:
return {.instrument = instrument_type::didgeridoo, .note = 17, .powered = true};
case 883:
return {.instrument = instrument_type::didgeridoo, .note = 17, .powered = false};
case 884:
return {.instrument = instrument_type::didgeridoo, .note = 18, .powered = true};
case 885:
return {.instrument = instrument_type::didgeridoo, .note = 18, .powered = false};
case 886:
return {.instrument = instrument_type::didgeridoo, .note = 19, .powered = true};
case 887:
return {.instrument = instrument_type::didgeridoo, .note = 19, .powered = false};
case 888:
return {.instrument = instrument_type::didgeridoo, .note = 20, .powered = true};
case 889:
return {.instrument = instrument_type::didgeridoo, .note = 20, .powered = false};
case 890:
return {.instrument = instrument_type::didgeridoo, .note = 21, .powered = true};
case 891:
return {.instrument = instrument_type::didgeridoo, .note = 21, .powered = false};
case 892:
return {.instrument = instrument_type::didgeridoo, .note = 22, .powered = true};
case 893:
return {.instrument = instrument_type::didgeridoo, .note = 22, .powered = false};
case 894:
return {.instrument = instrument_type::didgeridoo, .note = 23, .powered = true};
case 895:
return {.instrument = instrument_type::didgeridoo, .note = 23, .powered = false};
case 896:
return {.instrument = instrument_type::didgeridoo, .note = 24, .powered = true};
case 897:
return {.instrument = instrument_type::didgeridoo, .note = 24, .powered = false};
case 898:
return {.instrument = instrument_type::bit, .note = 0, .powered = true};
case 899:
return {.instrument = instrument_type::bit, .note = 0, .powered = false};
case 900:
return {.instrument = instrument_type::bit, .note = 1, .powered = true};
case 901:
return {.instrument = instrument_type::bit, .note = 1, .powered = false};
case 902:
return {.instrument = instrument_type::bit, .note = 2, .powered = true};
case 903:
return {.instrument = instrument_type::bit, .note = 2, .powered = false};
case 904:
return {.instrument = instrument_type::bit, .note = 3, .powered = true};
case 905:
return {.instrument = instrument_type::bit, .note = 3, .powered = false};
case 906:
return {.instrument = instrument_type::bit, .note = 4, .powered = true};
case 907:
return {.instrument = instrument_type::bit, .note = 4, .powered = false};
case 908:
return {.instrument = instrument_type::bit, .note = 5, .powered = true};
case 909:
return {.instrument = instrument_type::bit, .note = 5, .powered = false};
case 910:
return {.instrument = instrument_type::bit, .note = 6, .powered = true};
case 911:
return {.instrument = instrument_type::bit, .note = 6, .powered = false};
case 912:
return {.instrument = instrument_type::bit, .note = 7, .powered = true};
case 913:
return {.instrument = instrument_type::bit, .note = 7, .powered = false};
case 914:
return {.instrument = instrument_type::bit, .note = 8, .powered = true};
case 915:
return {.instrument = instrument_type::bit, .note = 8, .powered = false};
case 916:
return {.instrument = instrument_type::bit, .note = 9, .powered = true};
case 917:
return {.instrument = instrument_type::bit, .note = 9, .powered = false};
case 918:
return {.instrument = instrument_type::bit, .note = 10, .powered = true};
case 919:
return {.instrument = instrument_type::bit, .note = 10, .powered = false};
case 920:
return {.instrument = instrument_type::bit, .note = 11, .powered = true};
case 921:
return {.instrument = instrument_type::bit, .note = 11, .powered = false};
case 922:
return {.instrument = instrument_type::bit, .note = 12, .powered = true};
case 923:
return {.instrument = instrument_type::bit, .note = 12, .powered = false};
case 924:
return {.instrument = instrument_type::bit, .note = 13, .powered = true};
case 925:
return {.instrument = instrument_type::bit, .note = 13, .powered = false};
case 926:
return {.instrument = instrument_type::bit, .note = 14, .powered = true};
case 927:
return {.instrument = instrument_type::bit, .note = 14, .powered = false};
case 928:
return {.instrument = instrument_type::bit, .note = 15, .powered = true};
case 929:
return {.instrument = instrument_type::bit, .note = 15, .powered = false};
case 930:
return {.instrument = instrument_type::bit, .note = 16, .powered = true};
case 931:
return {.instrument = instrument_type::bit, .note = 16, .powered = false};
case 932:
return {.instrument = instrument_type::bit, .note = 17, .powered = true};
case 933:
return {.instrument = instrument_type::bit, .note = 17, .powered = false};
case 934:
return {.instrument = instrument_type::bit, .note = 18, .powered = true};
case 935:
return {.instrument = instrument_type::bit, .note = 18, .powered = false};
case 936:
return {.instrument = instrument_type::bit, .note = 19, .powered = true};
case 937:
return {.instrument = instrument_type::bit, .note = 19, .powered = false};
case 938:
return {.instrument = instrument_type::bit, .note = 20, .powered = true};
case 939:
return {.instrument = instrument_type::bit, .note = 20, .powered = false};
case 940:
return {.instrument = instrument_type::bit, .note = 21, .powered = true};
case 941:
return {.instrument = instrument_type::bit, .note = 21, .powered = false};
case 942:
return {.instrument = instrument_type::bit, .note = 22, .powered = true};
case 943:
return {.instrument = instrument_type::bit, .note = 22, .powered = false};
case 944:
return {.instrument = instrument_type::bit, .note = 23, .powered = true};
case 945:
return {.instrument = instrument_type::bit, .note = 23, .powered = false};
case 946:
return {.instrument = instrument_type::bit, .note = 24, .powered = true};
case 947:
return {.instrument = instrument_type::bit, .note = 24, .powered = false};
case 948:
return {.instrument = instrument_type::banjo, .note = 0, .powered = true};
case 949:
return {.instrument = instrument_type::banjo, .note = 0, .powered = false};
case 950:
return {.instrument = instrument_type::banjo, .note = 1, .powered = true};
case 951:
return {.instrument = instrument_type::banjo, .note = 1, .powered = false};
case 952:
return {.instrument = instrument_type::banjo, .note = 2, .powered = true};
case 953:
return {.instrument = instrument_type::banjo, .note = 2, .powered = false};
case 954:
return {.instrument = instrument_type::banjo, .note = 3, .powered = true};
case 955:
return {.instrument = instrument_type::banjo, .note = 3, .powered = false};
case 956:
return {.instrument = instrument_type::banjo, .note = 4, .powered = true};
case 957:
return {.instrument = instrument_type::banjo, .note = 4, .powered = false};
case 958:
return {.instrument = instrument_type::banjo, .note = 5, .powered = true};
case 959:
return {.instrument = instrument_type::banjo, .note = 5, .powered = false};
case 960:
return {.instrument = instrument_type::banjo, .note = 6, .powered = true};
case 961:
return {.instrument = instrument_type::banjo, .note = 6, .powered = false};
case 962:
return {.instrument = instrument_type::banjo, .note = 7, .powered = true};
case 963:
return {.instrument = instrument_type::banjo, .note = 7, .powered = false};
case 964:
return {.instrument = instrument_type::banjo, .note = 8, .powered = true};
case 965:
return {.instrument = instrument_type::banjo, .note = 8, .powered = false};
case 966:
return {.instrument = instrument_type::banjo, .note = 9, .powered = true};
case 967:
return {.instrument = instrument_type::banjo, .note = 9, .powered = false};
case 968:
return {.instrument = instrument_type::banjo, .note = 10, .powered = true};
case 969:
return {.instrument = instrument_type::banjo, .note = 10, .powered = false};
case 970:
return {.instrument = instrument_type::banjo, .note = 11, .powered = true};
case 971:
return {.instrument = instrument_type::banjo, .note = 11, .powered = false};
case 972:
return {.instrument = instrument_type::banjo, .note = 12, .powered = true};
case 973:
return {.instrument = instrument_type::banjo, .note = 12, .powered = false};
case 974:
return {.instrument = instrument_type::banjo, .note = 13, .powered = true};
case 975:
return {.instrument = instrument_type::banjo, .note = 13, .powered = false};
case 976:
return {.instrument = instrument_type::banjo, .note = 14, .powered = true};
case 977:
return {.instrument = instrument_type::banjo, .note = 14, .powered = false};
case 978:
return {.instrument = instrument_type::banjo, .note = 15, .powered = true};
case 979:
return {.instrument = instrument_type::banjo, .note = 15, .powered = false};
case 980:
return {.instrument = instrument_type::banjo, .note = 16, .powered = true};
case 981:
return {.instrument = instrument_type::banjo, .note = 16, .powered = false};
case 982:
return {.instrument = instrument_type::banjo, .note = 17, .powered = true};
case 983:
return {.instrument = instrument_type::banjo, .note = 17, .powered = false};
case 984:
return {.instrument = instrument_type::banjo, .note = 18, .powered = true};
case 985:
return {.instrument = instrument_type::banjo, .note = 18, .powered = false};
case 986:
return {.instrument = instrument_type::banjo, .note = 19, .powered = true};
case 987:
return {.instrument = instrument_type::banjo, .note = 19, .powered = false};
case 988:
return {.instrument = instrument_type::banjo, .note = 20, .powered = true};
case 989:
return {.instrument = instrument_type::banjo, .note = 20, .powered = false};
case 990:
return {.instrument = instrument_type::banjo, .note = 21, .powered = true};
case 991:
return {.instrument = instrument_type::banjo, .note = 21, .powered = false};
case 992:
return {.instrument = instrument_type::banjo, .note = 22, .powered = true};
case 993:
return {.instrument = instrument_type::banjo, .note = 22, .powered = false};
case 994:
return {.instrument = instrument_type::banjo, .note = 23, .powered = true};
case 995:
return {.instrument = instrument_type::banjo, .note = 23, .powered = false};
case 996:
return {.instrument = instrument_type::banjo, .note = 24, .powered = true};
case 997:
return {.instrument = instrument_type::banjo, .note = 24, .powered = false};
case 998:
return {.instrument = instrument_type::pling, .note = 0, .powered = true};
case 999:
return {.instrument = instrument_type::pling, .note = 0, .powered = false};
case 1000:
return {.instrument = instrument_type::pling, .note = 1, .powered = true};
case 1001:
return {.instrument = instrument_type::pling, .note = 1, .powered = false};
case 1002:
return {.instrument = instrument_type::pling, .note = 2, .powered = true};
case 1003:
return {.instrument = instrument_type::pling, .note = 2, .powered = false};
case 1004:
return {.instrument = instrument_type::pling, .note = 3, .powered = true};
case 1005:
return {.instrument = instrument_type::pling, .note = 3, .powered = false};
case 1006:
return {.instrument = instrument_type::pling, .note = 4, .powered = true};
case 1007:
return {.instrument = instrument_type::pling, .note = 4, .powered = false};
case 1008:
return {.instrument = instrument_type::pling, .note = 5, .powered = true};
case 1009:
return {.instrument = instrument_type::pling, .note = 5, .powered = false};
case 1010:
return {.instrument = instrument_type::pling, .note = 6, .powered = true};
case 1011:
return {.instrument = instrument_type::pling, .note = 6, .powered = false};
case 1012:
return {.instrument = instrument_type::pling, .note = 7, .powered = true};
case 1013:
return {.instrument = instrument_type::pling, .note = 7, .powered = false};
case 1014:
return {.instrument = instrument_type::pling, .note = 8, .powered = true};
case 1015:
return {.instrument = instrument_type::pling, .note = 8, .powered = false};
case 1016:
return {.instrument = instrument_type::pling, .note = 9, .powered = true};
case 1017:
return {.instrument = instrument_type::pling, .note = 9, .powered = false};
case 1018:
return {.instrument = instrument_type::pling, .note = 10, .powered = true};
case 1019:
return {.instrument = instrument_type::pling, .note = 10, .powered = false};
case 1020:
return {.instrument = instrument_type::pling, .note = 11, .powered = true};
case 1021:
return {.instrument = instrument_type::pling, .note = 11, .powered = false};
case 1022:
return {.instrument = instrument_type::pling, .note = 12, .powered = true};
case 1023:
return {.instrument = instrument_type::pling, .note = 12, .powered = false};
case 1024:
return {.instrument = instrument_type::pling, .note = 13, .powered = true};
case 1025:
return {.instrument = instrument_type::pling, .note = 13, .powered = false};
case 1026:
return {.instrument = instrument_type::pling, .note = 14, .powered = true};
case 1027:
return {.instrument = instrument_type::pling, .note = 14, .powered = false};
case 1028:
return {.instrument = instrument_type::pling, .note = 15, .powered = true};
case 1029:
return {.instrument = instrument_type::pling, .note = 15, .powered = false};
case 1030:
return {.instrument = instrument_type::pling, .note = 16, .powered = true};
case 1031:
return {.instrument = instrument_type::pling, .note = 16, .powered = false};
case 1032:
return {.instrument = instrument_type::pling, .note = 17, .powered = true};
case 1033:
return {.instrument = instrument_type::pling, .note = 17, .powered = false};
case 1034:
return {.instrument = instrument_type::pling, .note = 18, .powered = true};
case 1035:
return {.instrument = instrument_type::pling, .note = 18, .powered = false};
case 1036:
return {.instrument = instrument_type::pling, .note = 19, .powered = true};
case 1037:
return {.instrument = instrument_type::pling, .note = 19, .powered = false};
case 1038:
return {.instrument = instrument_type::pling, .note = 20, .powered = true};
case 1039:
return {.instrument = instrument_type::pling, .note = 20, .powered = false};
case 1040:
return {.instrument = instrument_type::pling, .note = 21, .powered = true};
case 1041:
return {.instrument = instrument_type::pling, .note = 21, .powered = false};
case 1042:
return {.instrument = instrument_type::pling, .note = 22, .powered = true};
case 1043:
return {.instrument = instrument_type::pling, .note = 22, .powered = false};
case 1044:
return {.instrument = instrument_type::pling, .note = 23, .powered = true};
case 1045:
return {.instrument = instrument_type::pling, .note = 23, .powered = false};
case 1046:
return {.instrument = instrument_type::pling, .note = 24, .powered = true};
case 1047:
return {.instrument = instrument_type::pling, .note = 24, .powered = false};
}}
constexpr std::string_view to_string() const
{switch (instrument)
{
case instrument_type::harp:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:harp:0:true";
case false:
return "minecraft:note_block:harp:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:harp:1:true";
case false:
return "minecraft:note_block:harp:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:harp:2:true";
case false:
return "minecraft:note_block:harp:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:harp:3:true";
case false:
return "minecraft:note_block:harp:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:harp:4:true";
case false:
return "minecraft:note_block:harp:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:harp:5:true";
case false:
return "minecraft:note_block:harp:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:harp:6:true";
case false:
return "minecraft:note_block:harp:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:harp:7:true";
case false:
return "minecraft:note_block:harp:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:harp:8:true";
case false:
return "minecraft:note_block:harp:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:harp:9:true";
case false:
return "minecraft:note_block:harp:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:harp:10:true";
case false:
return "minecraft:note_block:harp:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:harp:11:true";
case false:
return "minecraft:note_block:harp:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:harp:12:true";
case false:
return "minecraft:note_block:harp:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:harp:13:true";
case false:
return "minecraft:note_block:harp:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:harp:14:true";
case false:
return "minecraft:note_block:harp:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:harp:15:true";
case false:
return "minecraft:note_block:harp:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:harp:16:true";
case false:
return "minecraft:note_block:harp:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:harp:17:true";
case false:
return "minecraft:note_block:harp:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:harp:18:true";
case false:
return "minecraft:note_block:harp:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:harp:19:true";
case false:
return "minecraft:note_block:harp:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:harp:20:true";
case false:
return "minecraft:note_block:harp:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:harp:21:true";
case false:
return "minecraft:note_block:harp:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:harp:22:true";
case false:
return "minecraft:note_block:harp:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:harp:23:true";
case false:
return "minecraft:note_block:harp:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:harp:24:true";
case false:
return "minecraft:note_block:harp:24:false";
}
}
case instrument_type::basedrum:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:0:true";
case false:
return "minecraft:note_block:basedrum:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:1:true";
case false:
return "minecraft:note_block:basedrum:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:2:true";
case false:
return "minecraft:note_block:basedrum:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:3:true";
case false:
return "minecraft:note_block:basedrum:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:4:true";
case false:
return "minecraft:note_block:basedrum:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:5:true";
case false:
return "minecraft:note_block:basedrum:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:6:true";
case false:
return "minecraft:note_block:basedrum:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:7:true";
case false:
return "minecraft:note_block:basedrum:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:8:true";
case false:
return "minecraft:note_block:basedrum:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:9:true";
case false:
return "minecraft:note_block:basedrum:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:10:true";
case false:
return "minecraft:note_block:basedrum:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:11:true";
case false:
return "minecraft:note_block:basedrum:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:12:true";
case false:
return "minecraft:note_block:basedrum:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:13:true";
case false:
return "minecraft:note_block:basedrum:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:14:true";
case false:
return "minecraft:note_block:basedrum:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:15:true";
case false:
return "minecraft:note_block:basedrum:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:16:true";
case false:
return "minecraft:note_block:basedrum:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:17:true";
case false:
return "minecraft:note_block:basedrum:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:18:true";
case false:
return "minecraft:note_block:basedrum:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:19:true";
case false:
return "minecraft:note_block:basedrum:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:20:true";
case false:
return "minecraft:note_block:basedrum:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:21:true";
case false:
return "minecraft:note_block:basedrum:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:22:true";
case false:
return "minecraft:note_block:basedrum:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:23:true";
case false:
return "minecraft:note_block:basedrum:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:basedrum:24:true";
case false:
return "minecraft:note_block:basedrum:24:false";
}
}
case instrument_type::snare:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:snare:0:true";
case false:
return "minecraft:note_block:snare:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:snare:1:true";
case false:
return "minecraft:note_block:snare:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:snare:2:true";
case false:
return "minecraft:note_block:snare:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:snare:3:true";
case false:
return "minecraft:note_block:snare:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:snare:4:true";
case false:
return "minecraft:note_block:snare:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:snare:5:true";
case false:
return "minecraft:note_block:snare:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:snare:6:true";
case false:
return "minecraft:note_block:snare:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:snare:7:true";
case false:
return "minecraft:note_block:snare:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:snare:8:true";
case false:
return "minecraft:note_block:snare:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:snare:9:true";
case false:
return "minecraft:note_block:snare:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:snare:10:true";
case false:
return "minecraft:note_block:snare:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:snare:11:true";
case false:
return "minecraft:note_block:snare:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:snare:12:true";
case false:
return "minecraft:note_block:snare:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:snare:13:true";
case false:
return "minecraft:note_block:snare:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:snare:14:true";
case false:
return "minecraft:note_block:snare:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:snare:15:true";
case false:
return "minecraft:note_block:snare:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:snare:16:true";
case false:
return "minecraft:note_block:snare:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:snare:17:true";
case false:
return "minecraft:note_block:snare:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:snare:18:true";
case false:
return "minecraft:note_block:snare:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:snare:19:true";
case false:
return "minecraft:note_block:snare:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:snare:20:true";
case false:
return "minecraft:note_block:snare:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:snare:21:true";
case false:
return "minecraft:note_block:snare:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:snare:22:true";
case false:
return "minecraft:note_block:snare:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:snare:23:true";
case false:
return "minecraft:note_block:snare:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:snare:24:true";
case false:
return "minecraft:note_block:snare:24:false";
}
}
case instrument_type::hat:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:hat:0:true";
case false:
return "minecraft:note_block:hat:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:hat:1:true";
case false:
return "minecraft:note_block:hat:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:hat:2:true";
case false:
return "minecraft:note_block:hat:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:hat:3:true";
case false:
return "minecraft:note_block:hat:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:hat:4:true";
case false:
return "minecraft:note_block:hat:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:hat:5:true";
case false:
return "minecraft:note_block:hat:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:hat:6:true";
case false:
return "minecraft:note_block:hat:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:hat:7:true";
case false:
return "minecraft:note_block:hat:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:hat:8:true";
case false:
return "minecraft:note_block:hat:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:hat:9:true";
case false:
return "minecraft:note_block:hat:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:hat:10:true";
case false:
return "minecraft:note_block:hat:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:hat:11:true";
case false:
return "minecraft:note_block:hat:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:hat:12:true";
case false:
return "minecraft:note_block:hat:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:hat:13:true";
case false:
return "minecraft:note_block:hat:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:hat:14:true";
case false:
return "minecraft:note_block:hat:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:hat:15:true";
case false:
return "minecraft:note_block:hat:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:hat:16:true";
case false:
return "minecraft:note_block:hat:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:hat:17:true";
case false:
return "minecraft:note_block:hat:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:hat:18:true";
case false:
return "minecraft:note_block:hat:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:hat:19:true";
case false:
return "minecraft:note_block:hat:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:hat:20:true";
case false:
return "minecraft:note_block:hat:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:hat:21:true";
case false:
return "minecraft:note_block:hat:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:hat:22:true";
case false:
return "minecraft:note_block:hat:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:hat:23:true";
case false:
return "minecraft:note_block:hat:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:hat:24:true";
case false:
return "minecraft:note_block:hat:24:false";
}
}
case instrument_type::bass:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:bass:0:true";
case false:
return "minecraft:note_block:bass:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:bass:1:true";
case false:
return "minecraft:note_block:bass:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:bass:2:true";
case false:
return "minecraft:note_block:bass:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:bass:3:true";
case false:
return "minecraft:note_block:bass:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:bass:4:true";
case false:
return "minecraft:note_block:bass:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:bass:5:true";
case false:
return "minecraft:note_block:bass:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:bass:6:true";
case false:
return "minecraft:note_block:bass:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:bass:7:true";
case false:
return "minecraft:note_block:bass:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:bass:8:true";
case false:
return "minecraft:note_block:bass:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:bass:9:true";
case false:
return "minecraft:note_block:bass:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:bass:10:true";
case false:
return "minecraft:note_block:bass:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:bass:11:true";
case false:
return "minecraft:note_block:bass:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:bass:12:true";
case false:
return "minecraft:note_block:bass:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:bass:13:true";
case false:
return "minecraft:note_block:bass:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:bass:14:true";
case false:
return "minecraft:note_block:bass:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:bass:15:true";
case false:
return "minecraft:note_block:bass:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:bass:16:true";
case false:
return "minecraft:note_block:bass:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:bass:17:true";
case false:
return "minecraft:note_block:bass:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:bass:18:true";
case false:
return "minecraft:note_block:bass:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:bass:19:true";
case false:
return "minecraft:note_block:bass:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:bass:20:true";
case false:
return "minecraft:note_block:bass:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:bass:21:true";
case false:
return "minecraft:note_block:bass:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:bass:22:true";
case false:
return "minecraft:note_block:bass:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:bass:23:true";
case false:
return "minecraft:note_block:bass:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:bass:24:true";
case false:
return "minecraft:note_block:bass:24:false";
}
}
case instrument_type::flute:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:flute:0:true";
case false:
return "minecraft:note_block:flute:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:flute:1:true";
case false:
return "minecraft:note_block:flute:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:flute:2:true";
case false:
return "minecraft:note_block:flute:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:flute:3:true";
case false:
return "minecraft:note_block:flute:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:flute:4:true";
case false:
return "minecraft:note_block:flute:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:flute:5:true";
case false:
return "minecraft:note_block:flute:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:flute:6:true";
case false:
return "minecraft:note_block:flute:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:flute:7:true";
case false:
return "minecraft:note_block:flute:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:flute:8:true";
case false:
return "minecraft:note_block:flute:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:flute:9:true";
case false:
return "minecraft:note_block:flute:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:flute:10:true";
case false:
return "minecraft:note_block:flute:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:flute:11:true";
case false:
return "minecraft:note_block:flute:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:flute:12:true";
case false:
return "minecraft:note_block:flute:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:flute:13:true";
case false:
return "minecraft:note_block:flute:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:flute:14:true";
case false:
return "minecraft:note_block:flute:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:flute:15:true";
case false:
return "minecraft:note_block:flute:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:flute:16:true";
case false:
return "minecraft:note_block:flute:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:flute:17:true";
case false:
return "minecraft:note_block:flute:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:flute:18:true";
case false:
return "minecraft:note_block:flute:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:flute:19:true";
case false:
return "minecraft:note_block:flute:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:flute:20:true";
case false:
return "minecraft:note_block:flute:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:flute:21:true";
case false:
return "minecraft:note_block:flute:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:flute:22:true";
case false:
return "minecraft:note_block:flute:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:flute:23:true";
case false:
return "minecraft:note_block:flute:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:flute:24:true";
case false:
return "minecraft:note_block:flute:24:false";
}
}
case instrument_type::bell:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:bell:0:true";
case false:
return "minecraft:note_block:bell:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:bell:1:true";
case false:
return "minecraft:note_block:bell:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:bell:2:true";
case false:
return "minecraft:note_block:bell:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:bell:3:true";
case false:
return "minecraft:note_block:bell:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:bell:4:true";
case false:
return "minecraft:note_block:bell:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:bell:5:true";
case false:
return "minecraft:note_block:bell:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:bell:6:true";
case false:
return "minecraft:note_block:bell:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:bell:7:true";
case false:
return "minecraft:note_block:bell:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:bell:8:true";
case false:
return "minecraft:note_block:bell:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:bell:9:true";
case false:
return "minecraft:note_block:bell:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:bell:10:true";
case false:
return "minecraft:note_block:bell:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:bell:11:true";
case false:
return "minecraft:note_block:bell:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:bell:12:true";
case false:
return "minecraft:note_block:bell:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:bell:13:true";
case false:
return "minecraft:note_block:bell:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:bell:14:true";
case false:
return "minecraft:note_block:bell:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:bell:15:true";
case false:
return "minecraft:note_block:bell:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:bell:16:true";
case false:
return "minecraft:note_block:bell:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:bell:17:true";
case false:
return "minecraft:note_block:bell:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:bell:18:true";
case false:
return "minecraft:note_block:bell:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:bell:19:true";
case false:
return "minecraft:note_block:bell:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:bell:20:true";
case false:
return "minecraft:note_block:bell:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:bell:21:true";
case false:
return "minecraft:note_block:bell:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:bell:22:true";
case false:
return "minecraft:note_block:bell:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:bell:23:true";
case false:
return "minecraft:note_block:bell:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:bell:24:true";
case false:
return "minecraft:note_block:bell:24:false";
}
}
case instrument_type::guitar:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:0:true";
case false:
return "minecraft:note_block:guitar:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:1:true";
case false:
return "minecraft:note_block:guitar:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:2:true";
case false:
return "minecraft:note_block:guitar:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:3:true";
case false:
return "minecraft:note_block:guitar:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:4:true";
case false:
return "minecraft:note_block:guitar:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:5:true";
case false:
return "minecraft:note_block:guitar:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:6:true";
case false:
return "minecraft:note_block:guitar:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:7:true";
case false:
return "minecraft:note_block:guitar:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:8:true";
case false:
return "minecraft:note_block:guitar:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:9:true";
case false:
return "minecraft:note_block:guitar:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:10:true";
case false:
return "minecraft:note_block:guitar:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:11:true";
case false:
return "minecraft:note_block:guitar:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:12:true";
case false:
return "minecraft:note_block:guitar:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:13:true";
case false:
return "minecraft:note_block:guitar:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:14:true";
case false:
return "minecraft:note_block:guitar:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:15:true";
case false:
return "minecraft:note_block:guitar:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:16:true";
case false:
return "minecraft:note_block:guitar:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:17:true";
case false:
return "minecraft:note_block:guitar:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:18:true";
case false:
return "minecraft:note_block:guitar:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:19:true";
case false:
return "minecraft:note_block:guitar:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:20:true";
case false:
return "minecraft:note_block:guitar:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:21:true";
case false:
return "minecraft:note_block:guitar:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:22:true";
case false:
return "minecraft:note_block:guitar:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:23:true";
case false:
return "minecraft:note_block:guitar:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:guitar:24:true";
case false:
return "minecraft:note_block:guitar:24:false";
}
}
case instrument_type::chime:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:chime:0:true";
case false:
return "minecraft:note_block:chime:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:chime:1:true";
case false:
return "minecraft:note_block:chime:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:chime:2:true";
case false:
return "minecraft:note_block:chime:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:chime:3:true";
case false:
return "minecraft:note_block:chime:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:chime:4:true";
case false:
return "minecraft:note_block:chime:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:chime:5:true";
case false:
return "minecraft:note_block:chime:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:chime:6:true";
case false:
return "minecraft:note_block:chime:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:chime:7:true";
case false:
return "minecraft:note_block:chime:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:chime:8:true";
case false:
return "minecraft:note_block:chime:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:chime:9:true";
case false:
return "minecraft:note_block:chime:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:chime:10:true";
case false:
return "minecraft:note_block:chime:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:chime:11:true";
case false:
return "minecraft:note_block:chime:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:chime:12:true";
case false:
return "minecraft:note_block:chime:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:chime:13:true";
case false:
return "minecraft:note_block:chime:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:chime:14:true";
case false:
return "minecraft:note_block:chime:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:chime:15:true";
case false:
return "minecraft:note_block:chime:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:chime:16:true";
case false:
return "minecraft:note_block:chime:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:chime:17:true";
case false:
return "minecraft:note_block:chime:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:chime:18:true";
case false:
return "minecraft:note_block:chime:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:chime:19:true";
case false:
return "minecraft:note_block:chime:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:chime:20:true";
case false:
return "minecraft:note_block:chime:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:chime:21:true";
case false:
return "minecraft:note_block:chime:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:chime:22:true";
case false:
return "minecraft:note_block:chime:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:chime:23:true";
case false:
return "minecraft:note_block:chime:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:chime:24:true";
case false:
return "minecraft:note_block:chime:24:false";
}
}
case instrument_type::xylophone:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:0:true";
case false:
return "minecraft:note_block:xylophone:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:1:true";
case false:
return "minecraft:note_block:xylophone:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:2:true";
case false:
return "minecraft:note_block:xylophone:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:3:true";
case false:
return "minecraft:note_block:xylophone:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:4:true";
case false:
return "minecraft:note_block:xylophone:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:5:true";
case false:
return "minecraft:note_block:xylophone:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:6:true";
case false:
return "minecraft:note_block:xylophone:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:7:true";
case false:
return "minecraft:note_block:xylophone:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:8:true";
case false:
return "minecraft:note_block:xylophone:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:9:true";
case false:
return "minecraft:note_block:xylophone:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:10:true";
case false:
return "minecraft:note_block:xylophone:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:11:true";
case false:
return "minecraft:note_block:xylophone:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:12:true";
case false:
return "minecraft:note_block:xylophone:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:13:true";
case false:
return "minecraft:note_block:xylophone:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:14:true";
case false:
return "minecraft:note_block:xylophone:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:15:true";
case false:
return "minecraft:note_block:xylophone:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:16:true";
case false:
return "minecraft:note_block:xylophone:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:17:true";
case false:
return "minecraft:note_block:xylophone:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:18:true";
case false:
return "minecraft:note_block:xylophone:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:19:true";
case false:
return "minecraft:note_block:xylophone:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:20:true";
case false:
return "minecraft:note_block:xylophone:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:21:true";
case false:
return "minecraft:note_block:xylophone:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:22:true";
case false:
return "minecraft:note_block:xylophone:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:23:true";
case false:
return "minecraft:note_block:xylophone:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:xylophone:24:true";
case false:
return "minecraft:note_block:xylophone:24:false";
}
}
case instrument_type::iron_xylophone:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:0:true";
case false:
return "minecraft:note_block:iron_xylophone:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:1:true";
case false:
return "minecraft:note_block:iron_xylophone:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:2:true";
case false:
return "minecraft:note_block:iron_xylophone:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:3:true";
case false:
return "minecraft:note_block:iron_xylophone:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:4:true";
case false:
return "minecraft:note_block:iron_xylophone:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:5:true";
case false:
return "minecraft:note_block:iron_xylophone:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:6:true";
case false:
return "minecraft:note_block:iron_xylophone:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:7:true";
case false:
return "minecraft:note_block:iron_xylophone:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:8:true";
case false:
return "minecraft:note_block:iron_xylophone:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:9:true";
case false:
return "minecraft:note_block:iron_xylophone:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:10:true";
case false:
return "minecraft:note_block:iron_xylophone:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:11:true";
case false:
return "minecraft:note_block:iron_xylophone:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:12:true";
case false:
return "minecraft:note_block:iron_xylophone:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:13:true";
case false:
return "minecraft:note_block:iron_xylophone:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:14:true";
case false:
return "minecraft:note_block:iron_xylophone:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:15:true";
case false:
return "minecraft:note_block:iron_xylophone:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:16:true";
case false:
return "minecraft:note_block:iron_xylophone:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:17:true";
case false:
return "minecraft:note_block:iron_xylophone:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:18:true";
case false:
return "minecraft:note_block:iron_xylophone:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:19:true";
case false:
return "minecraft:note_block:iron_xylophone:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:20:true";
case false:
return "minecraft:note_block:iron_xylophone:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:21:true";
case false:
return "minecraft:note_block:iron_xylophone:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:22:true";
case false:
return "minecraft:note_block:iron_xylophone:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:23:true";
case false:
return "minecraft:note_block:iron_xylophone:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:iron_xylophone:24:true";
case false:
return "minecraft:note_block:iron_xylophone:24:false";
}
}
case instrument_type::cow_bell:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:0:true";
case false:
return "minecraft:note_block:cow_bell:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:1:true";
case false:
return "minecraft:note_block:cow_bell:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:2:true";
case false:
return "minecraft:note_block:cow_bell:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:3:true";
case false:
return "minecraft:note_block:cow_bell:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:4:true";
case false:
return "minecraft:note_block:cow_bell:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:5:true";
case false:
return "minecraft:note_block:cow_bell:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:6:true";
case false:
return "minecraft:note_block:cow_bell:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:7:true";
case false:
return "minecraft:note_block:cow_bell:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:8:true";
case false:
return "minecraft:note_block:cow_bell:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:9:true";
case false:
return "minecraft:note_block:cow_bell:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:10:true";
case false:
return "minecraft:note_block:cow_bell:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:11:true";
case false:
return "minecraft:note_block:cow_bell:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:12:true";
case false:
return "minecraft:note_block:cow_bell:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:13:true";
case false:
return "minecraft:note_block:cow_bell:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:14:true";
case false:
return "minecraft:note_block:cow_bell:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:15:true";
case false:
return "minecraft:note_block:cow_bell:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:16:true";
case false:
return "minecraft:note_block:cow_bell:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:17:true";
case false:
return "minecraft:note_block:cow_bell:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:18:true";
case false:
return "minecraft:note_block:cow_bell:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:19:true";
case false:
return "minecraft:note_block:cow_bell:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:20:true";
case false:
return "minecraft:note_block:cow_bell:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:21:true";
case false:
return "minecraft:note_block:cow_bell:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:22:true";
case false:
return "minecraft:note_block:cow_bell:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:23:true";
case false:
return "minecraft:note_block:cow_bell:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:cow_bell:24:true";
case false:
return "minecraft:note_block:cow_bell:24:false";
}
}
case instrument_type::didgeridoo:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:0:true";
case false:
return "minecraft:note_block:didgeridoo:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:1:true";
case false:
return "minecraft:note_block:didgeridoo:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:2:true";
case false:
return "minecraft:note_block:didgeridoo:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:3:true";
case false:
return "minecraft:note_block:didgeridoo:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:4:true";
case false:
return "minecraft:note_block:didgeridoo:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:5:true";
case false:
return "minecraft:note_block:didgeridoo:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:6:true";
case false:
return "minecraft:note_block:didgeridoo:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:7:true";
case false:
return "minecraft:note_block:didgeridoo:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:8:true";
case false:
return "minecraft:note_block:didgeridoo:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:9:true";
case false:
return "minecraft:note_block:didgeridoo:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:10:true";
case false:
return "minecraft:note_block:didgeridoo:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:11:true";
case false:
return "minecraft:note_block:didgeridoo:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:12:true";
case false:
return "minecraft:note_block:didgeridoo:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:13:true";
case false:
return "minecraft:note_block:didgeridoo:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:14:true";
case false:
return "minecraft:note_block:didgeridoo:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:15:true";
case false:
return "minecraft:note_block:didgeridoo:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:16:true";
case false:
return "minecraft:note_block:didgeridoo:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:17:true";
case false:
return "minecraft:note_block:didgeridoo:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:18:true";
case false:
return "minecraft:note_block:didgeridoo:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:19:true";
case false:
return "minecraft:note_block:didgeridoo:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:20:true";
case false:
return "minecraft:note_block:didgeridoo:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:21:true";
case false:
return "minecraft:note_block:didgeridoo:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:22:true";
case false:
return "minecraft:note_block:didgeridoo:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:23:true";
case false:
return "minecraft:note_block:didgeridoo:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:didgeridoo:24:true";
case false:
return "minecraft:note_block:didgeridoo:24:false";
}
}
case instrument_type::bit:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:bit:0:true";
case false:
return "minecraft:note_block:bit:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:bit:1:true";
case false:
return "minecraft:note_block:bit:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:bit:2:true";
case false:
return "minecraft:note_block:bit:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:bit:3:true";
case false:
return "minecraft:note_block:bit:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:bit:4:true";
case false:
return "minecraft:note_block:bit:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:bit:5:true";
case false:
return "minecraft:note_block:bit:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:bit:6:true";
case false:
return "minecraft:note_block:bit:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:bit:7:true";
case false:
return "minecraft:note_block:bit:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:bit:8:true";
case false:
return "minecraft:note_block:bit:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:bit:9:true";
case false:
return "minecraft:note_block:bit:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:bit:10:true";
case false:
return "minecraft:note_block:bit:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:bit:11:true";
case false:
return "minecraft:note_block:bit:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:bit:12:true";
case false:
return "minecraft:note_block:bit:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:bit:13:true";
case false:
return "minecraft:note_block:bit:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:bit:14:true";
case false:
return "minecraft:note_block:bit:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:bit:15:true";
case false:
return "minecraft:note_block:bit:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:bit:16:true";
case false:
return "minecraft:note_block:bit:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:bit:17:true";
case false:
return "minecraft:note_block:bit:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:bit:18:true";
case false:
return "minecraft:note_block:bit:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:bit:19:true";
case false:
return "minecraft:note_block:bit:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:bit:20:true";
case false:
return "minecraft:note_block:bit:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:bit:21:true";
case false:
return "minecraft:note_block:bit:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:bit:22:true";
case false:
return "minecraft:note_block:bit:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:bit:23:true";
case false:
return "minecraft:note_block:bit:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:bit:24:true";
case false:
return "minecraft:note_block:bit:24:false";
}
}
case instrument_type::banjo:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:0:true";
case false:
return "minecraft:note_block:banjo:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:1:true";
case false:
return "minecraft:note_block:banjo:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:2:true";
case false:
return "minecraft:note_block:banjo:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:3:true";
case false:
return "minecraft:note_block:banjo:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:4:true";
case false:
return "minecraft:note_block:banjo:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:5:true";
case false:
return "minecraft:note_block:banjo:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:6:true";
case false:
return "minecraft:note_block:banjo:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:7:true";
case false:
return "minecraft:note_block:banjo:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:8:true";
case false:
return "minecraft:note_block:banjo:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:9:true";
case false:
return "minecraft:note_block:banjo:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:10:true";
case false:
return "minecraft:note_block:banjo:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:11:true";
case false:
return "minecraft:note_block:banjo:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:12:true";
case false:
return "minecraft:note_block:banjo:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:13:true";
case false:
return "minecraft:note_block:banjo:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:14:true";
case false:
return "minecraft:note_block:banjo:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:15:true";
case false:
return "minecraft:note_block:banjo:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:16:true";
case false:
return "minecraft:note_block:banjo:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:17:true";
case false:
return "minecraft:note_block:banjo:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:18:true";
case false:
return "minecraft:note_block:banjo:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:19:true";
case false:
return "minecraft:note_block:banjo:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:20:true";
case false:
return "minecraft:note_block:banjo:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:21:true";
case false:
return "minecraft:note_block:banjo:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:22:true";
case false:
return "minecraft:note_block:banjo:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:23:true";
case false:
return "minecraft:note_block:banjo:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:banjo:24:true";
case false:
return "minecraft:note_block:banjo:24:false";
}
}
case instrument_type::pling:
switch (note)
{
case 0:
switch (powered)
{
case true:
return "minecraft:note_block:pling:0:true";
case false:
return "minecraft:note_block:pling:0:false";
}
case 1:
switch (powered)
{
case true:
return "minecraft:note_block:pling:1:true";
case false:
return "minecraft:note_block:pling:1:false";
}
case 2:
switch (powered)
{
case true:
return "minecraft:note_block:pling:2:true";
case false:
return "minecraft:note_block:pling:2:false";
}
case 3:
switch (powered)
{
case true:
return "minecraft:note_block:pling:3:true";
case false:
return "minecraft:note_block:pling:3:false";
}
case 4:
switch (powered)
{
case true:
return "minecraft:note_block:pling:4:true";
case false:
return "minecraft:note_block:pling:4:false";
}
case 5:
switch (powered)
{
case true:
return "minecraft:note_block:pling:5:true";
case false:
return "minecraft:note_block:pling:5:false";
}
case 6:
switch (powered)
{
case true:
return "minecraft:note_block:pling:6:true";
case false:
return "minecraft:note_block:pling:6:false";
}
case 7:
switch (powered)
{
case true:
return "minecraft:note_block:pling:7:true";
case false:
return "minecraft:note_block:pling:7:false";
}
case 8:
switch (powered)
{
case true:
return "minecraft:note_block:pling:8:true";
case false:
return "minecraft:note_block:pling:8:false";
}
case 9:
switch (powered)
{
case true:
return "minecraft:note_block:pling:9:true";
case false:
return "minecraft:note_block:pling:9:false";
}
case 10:
switch (powered)
{
case true:
return "minecraft:note_block:pling:10:true";
case false:
return "minecraft:note_block:pling:10:false";
}
case 11:
switch (powered)
{
case true:
return "minecraft:note_block:pling:11:true";
case false:
return "minecraft:note_block:pling:11:false";
}
case 12:
switch (powered)
{
case true:
return "minecraft:note_block:pling:12:true";
case false:
return "minecraft:note_block:pling:12:false";
}
case 13:
switch (powered)
{
case true:
return "minecraft:note_block:pling:13:true";
case false:
return "minecraft:note_block:pling:13:false";
}
case 14:
switch (powered)
{
case true:
return "minecraft:note_block:pling:14:true";
case false:
return "minecraft:note_block:pling:14:false";
}
case 15:
switch (powered)
{
case true:
return "minecraft:note_block:pling:15:true";
case false:
return "minecraft:note_block:pling:15:false";
}
case 16:
switch (powered)
{
case true:
return "minecraft:note_block:pling:16:true";
case false:
return "minecraft:note_block:pling:16:false";
}
case 17:
switch (powered)
{
case true:
return "minecraft:note_block:pling:17:true";
case false:
return "minecraft:note_block:pling:17:false";
}
case 18:
switch (powered)
{
case true:
return "minecraft:note_block:pling:18:true";
case false:
return "minecraft:note_block:pling:18:false";
}
case 19:
switch (powered)
{
case true:
return "minecraft:note_block:pling:19:true";
case false:
return "minecraft:note_block:pling:19:false";
}
case 20:
switch (powered)
{
case true:
return "minecraft:note_block:pling:20:true";
case false:
return "minecraft:note_block:pling:20:false";
}
case 21:
switch (powered)
{
case true:
return "minecraft:note_block:pling:21:true";
case false:
return "minecraft:note_block:pling:21:false";
}
case 22:
switch (powered)
{
case true:
return "minecraft:note_block:pling:22:true";
case false:
return "minecraft:note_block:pling:22:false";
}
case 23:
switch (powered)
{
case true:
return "minecraft:note_block:pling:23:true";
case false:
return "minecraft:note_block:pling:23:false";
}
case 24:
switch (powered)
{
case true:
return "minecraft:note_block:pling:24:true";
case false:
return "minecraft:note_block:pling:24:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
