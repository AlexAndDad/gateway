#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
    using block_id_type = std::uint16_t;
    struct fire
    {
        std::uint8_t            age   = 0;
        bool                    east  = false;
        bool                    north = false;
        bool                    south = false;
        bool                    up    = false;
        bool                    west  = false;
        constexpr block_id_type to_id() const
        {
            switch (age)
            {
            case 0:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1439;
                                case false: return 1440;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1441;
                                case false: return 1442;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1443;
                                case false: return 1444;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1445;
                                case false: return 1446;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1447;
                                case false: return 1448;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1449;
                                case false: return 1450;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1451;
                                case false: return 1452;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1453;
                                case false: return 1454;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1455;
                                case false: return 1456;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1457;
                                case false: return 1458;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1459;
                                case false: return 1460;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1461;
                                case false: return 1462;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1463;
                                case false: return 1464;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1465;
                                case false: return 1466;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1467;
                                case false: return 1468;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1469;
                                case false: return 1470;
                                }
                            }
                        }
                    }
                }
            case 1:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1471;
                                case false: return 1472;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1473;
                                case false: return 1474;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1475;
                                case false: return 1476;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1477;
                                case false: return 1478;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1479;
                                case false: return 1480;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1481;
                                case false: return 1482;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1483;
                                case false: return 1484;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1485;
                                case false: return 1486;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1487;
                                case false: return 1488;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1489;
                                case false: return 1490;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1491;
                                case false: return 1492;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1493;
                                case false: return 1494;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1495;
                                case false: return 1496;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1497;
                                case false: return 1498;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1499;
                                case false: return 1500;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1501;
                                case false: return 1502;
                                }
                            }
                        }
                    }
                }
            case 2:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1503;
                                case false: return 1504;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1505;
                                case false: return 1506;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1507;
                                case false: return 1508;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1509;
                                case false: return 1510;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1511;
                                case false: return 1512;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1513;
                                case false: return 1514;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1515;
                                case false: return 1516;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1517;
                                case false: return 1518;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1519;
                                case false: return 1520;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1521;
                                case false: return 1522;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1523;
                                case false: return 1524;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1525;
                                case false: return 1526;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1527;
                                case false: return 1528;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1529;
                                case false: return 1530;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1531;
                                case false: return 1532;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1533;
                                case false: return 1534;
                                }
                            }
                        }
                    }
                }
            case 3:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1535;
                                case false: return 1536;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1537;
                                case false: return 1538;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1539;
                                case false: return 1540;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1541;
                                case false: return 1542;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1543;
                                case false: return 1544;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1545;
                                case false: return 1546;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1547;
                                case false: return 1548;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1549;
                                case false: return 1550;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1551;
                                case false: return 1552;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1553;
                                case false: return 1554;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1555;
                                case false: return 1556;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1557;
                                case false: return 1558;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1559;
                                case false: return 1560;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1561;
                                case false: return 1562;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1563;
                                case false: return 1564;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1565;
                                case false: return 1566;
                                }
                            }
                        }
                    }
                }
            case 4:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1567;
                                case false: return 1568;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1569;
                                case false: return 1570;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1571;
                                case false: return 1572;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1573;
                                case false: return 1574;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1575;
                                case false: return 1576;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1577;
                                case false: return 1578;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1579;
                                case false: return 1580;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1581;
                                case false: return 1582;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1583;
                                case false: return 1584;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1585;
                                case false: return 1586;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1587;
                                case false: return 1588;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1589;
                                case false: return 1590;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1591;
                                case false: return 1592;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1593;
                                case false: return 1594;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1595;
                                case false: return 1596;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1597;
                                case false: return 1598;
                                }
                            }
                        }
                    }
                }
            case 5:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1599;
                                case false: return 1600;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1601;
                                case false: return 1602;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1603;
                                case false: return 1604;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1605;
                                case false: return 1606;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1607;
                                case false: return 1608;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1609;
                                case false: return 1610;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1611;
                                case false: return 1612;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1613;
                                case false: return 1614;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1615;
                                case false: return 1616;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1617;
                                case false: return 1618;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1619;
                                case false: return 1620;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1621;
                                case false: return 1622;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1623;
                                case false: return 1624;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1625;
                                case false: return 1626;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1627;
                                case false: return 1628;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1629;
                                case false: return 1630;
                                }
                            }
                        }
                    }
                }
            case 6:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1631;
                                case false: return 1632;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1633;
                                case false: return 1634;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1635;
                                case false: return 1636;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1637;
                                case false: return 1638;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1639;
                                case false: return 1640;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1641;
                                case false: return 1642;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1643;
                                case false: return 1644;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1645;
                                case false: return 1646;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1647;
                                case false: return 1648;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1649;
                                case false: return 1650;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1651;
                                case false: return 1652;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1653;
                                case false: return 1654;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1655;
                                case false: return 1656;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1657;
                                case false: return 1658;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1659;
                                case false: return 1660;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1661;
                                case false: return 1662;
                                }
                            }
                        }
                    }
                }
            case 7:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1663;
                                case false: return 1664;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1665;
                                case false: return 1666;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1667;
                                case false: return 1668;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1669;
                                case false: return 1670;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1671;
                                case false: return 1672;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1673;
                                case false: return 1674;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1675;
                                case false: return 1676;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1677;
                                case false: return 1678;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1679;
                                case false: return 1680;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1681;
                                case false: return 1682;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1683;
                                case false: return 1684;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1685;
                                case false: return 1686;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1687;
                                case false: return 1688;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1689;
                                case false: return 1690;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1691;
                                case false: return 1692;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1693;
                                case false: return 1694;
                                }
                            }
                        }
                    }
                }
            case 8:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1695;
                                case false: return 1696;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1697;
                                case false: return 1698;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1699;
                                case false: return 1700;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1701;
                                case false: return 1702;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1703;
                                case false: return 1704;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1705;
                                case false: return 1706;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1707;
                                case false: return 1708;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1709;
                                case false: return 1710;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1711;
                                case false: return 1712;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1713;
                                case false: return 1714;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1715;
                                case false: return 1716;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1717;
                                case false: return 1718;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1719;
                                case false: return 1720;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1721;
                                case false: return 1722;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1723;
                                case false: return 1724;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1725;
                                case false: return 1726;
                                }
                            }
                        }
                    }
                }
            case 9:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1727;
                                case false: return 1728;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1729;
                                case false: return 1730;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1731;
                                case false: return 1732;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1733;
                                case false: return 1734;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1735;
                                case false: return 1736;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1737;
                                case false: return 1738;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1739;
                                case false: return 1740;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1741;
                                case false: return 1742;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1743;
                                case false: return 1744;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1745;
                                case false: return 1746;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1747;
                                case false: return 1748;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1749;
                                case false: return 1750;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1751;
                                case false: return 1752;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1753;
                                case false: return 1754;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1755;
                                case false: return 1756;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1757;
                                case false: return 1758;
                                }
                            }
                        }
                    }
                }
            case 10:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1759;
                                case false: return 1760;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1761;
                                case false: return 1762;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1763;
                                case false: return 1764;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1765;
                                case false: return 1766;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1767;
                                case false: return 1768;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1769;
                                case false: return 1770;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1771;
                                case false: return 1772;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1773;
                                case false: return 1774;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1775;
                                case false: return 1776;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1777;
                                case false: return 1778;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1779;
                                case false: return 1780;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1781;
                                case false: return 1782;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1783;
                                case false: return 1784;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1785;
                                case false: return 1786;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1787;
                                case false: return 1788;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1789;
                                case false: return 1790;
                                }
                            }
                        }
                    }
                }
            case 11:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1791;
                                case false: return 1792;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1793;
                                case false: return 1794;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1795;
                                case false: return 1796;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1797;
                                case false: return 1798;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1799;
                                case false: return 1800;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1801;
                                case false: return 1802;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1803;
                                case false: return 1804;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1805;
                                case false: return 1806;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1807;
                                case false: return 1808;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1809;
                                case false: return 1810;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1811;
                                case false: return 1812;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1813;
                                case false: return 1814;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1815;
                                case false: return 1816;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1817;
                                case false: return 1818;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1819;
                                case false: return 1820;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1821;
                                case false: return 1822;
                                }
                            }
                        }
                    }
                }
            case 12:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1823;
                                case false: return 1824;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1825;
                                case false: return 1826;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1827;
                                case false: return 1828;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1829;
                                case false: return 1830;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1831;
                                case false: return 1832;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1833;
                                case false: return 1834;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1835;
                                case false: return 1836;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1837;
                                case false: return 1838;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1839;
                                case false: return 1840;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1841;
                                case false: return 1842;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1843;
                                case false: return 1844;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1845;
                                case false: return 1846;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1847;
                                case false: return 1848;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1849;
                                case false: return 1850;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1851;
                                case false: return 1852;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1853;
                                case false: return 1854;
                                }
                            }
                        }
                    }
                }
            case 13:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1855;
                                case false: return 1856;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1857;
                                case false: return 1858;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1859;
                                case false: return 1860;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1861;
                                case false: return 1862;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1863;
                                case false: return 1864;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1865;
                                case false: return 1866;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1867;
                                case false: return 1868;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1869;
                                case false: return 1870;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1871;
                                case false: return 1872;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1873;
                                case false: return 1874;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1875;
                                case false: return 1876;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1877;
                                case false: return 1878;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1879;
                                case false: return 1880;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1881;
                                case false: return 1882;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1883;
                                case false: return 1884;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1885;
                                case false: return 1886;
                                }
                            }
                        }
                    }
                }
            case 14:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1887;
                                case false: return 1888;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1889;
                                case false: return 1890;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1891;
                                case false: return 1892;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1893;
                                case false: return 1894;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1895;
                                case false: return 1896;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1897;
                                case false: return 1898;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1899;
                                case false: return 1900;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1901;
                                case false: return 1902;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1903;
                                case false: return 1904;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1905;
                                case false: return 1906;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1907;
                                case false: return 1908;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1909;
                                case false: return 1910;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1911;
                                case false: return 1912;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1913;
                                case false: return 1914;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1915;
                                case false: return 1916;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1917;
                                case false: return 1918;
                                }
                            }
                        }
                    }
                }
            case 15:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1919;
                                case false: return 1920;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1921;
                                case false: return 1922;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1923;
                                case false: return 1924;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1925;
                                case false: return 1926;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1927;
                                case false: return 1928;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1929;
                                case false: return 1930;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1931;
                                case false: return 1932;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1933;
                                case false: return 1934;
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1935;
                                case false: return 1936;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1937;
                                case false: return 1938;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1939;
                                case false: return 1940;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1941;
                                case false: return 1942;
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1943;
                                case false: return 1944;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1945;
                                case false: return 1946;
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return 1947;
                                case false: return 1948;
                                }
                            case false:
                                switch (west)
                                {
                                case true: return 1949;
                                case false: return 1950;
                                }
                            }
                        }
                    }
                }
            }
        }
        constexpr static fire from_id(block_id_type id)
        {
            switch (id)
            {
            case 1439: return { .age = 0, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1440: return { .age = 0, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1441: return { .age = 0, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1442: return { .age = 0, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1443: return { .age = 0, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1444: return { .age = 0, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1445: return { .age = 0, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1446: return { .age = 0, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1447: return { .age = 0, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1448: return { .age = 0, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1449: return { .age = 0, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1450: return { .age = 0, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1451: return { .age = 0, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1452: return { .age = 0, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1453: return { .age = 0, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1454: return { .age = 0, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1455: return { .age = 0, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1456: return { .age = 0, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1457: return { .age = 0, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1458: return { .age = 0, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1459: return { .age = 0, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1460: return { .age = 0, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1461: return { .age = 0, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1462: return { .age = 0, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1463: return { .age = 0, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1464: return { .age = 0, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1465: return { .age = 0, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1466: return { .age = 0, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1467: return { .age = 0, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1468: return { .age = 0, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1469: return { .age = 0, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1470: return { .age = 0, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1471: return { .age = 1, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1472: return { .age = 1, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1473: return { .age = 1, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1474: return { .age = 1, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1475: return { .age = 1, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1476: return { .age = 1, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1477: return { .age = 1, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1478: return { .age = 1, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1479: return { .age = 1, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1480: return { .age = 1, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1481: return { .age = 1, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1482: return { .age = 1, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1483: return { .age = 1, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1484: return { .age = 1, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1485: return { .age = 1, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1486: return { .age = 1, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1487: return { .age = 1, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1488: return { .age = 1, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1489: return { .age = 1, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1490: return { .age = 1, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1491: return { .age = 1, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1492: return { .age = 1, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1493: return { .age = 1, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1494: return { .age = 1, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1495: return { .age = 1, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1496: return { .age = 1, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1497: return { .age = 1, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1498: return { .age = 1, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1499: return { .age = 1, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1500: return { .age = 1, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1501: return { .age = 1, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1502: return { .age = 1, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1503: return { .age = 2, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1504: return { .age = 2, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1505: return { .age = 2, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1506: return { .age = 2, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1507: return { .age = 2, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1508: return { .age = 2, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1509: return { .age = 2, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1510: return { .age = 2, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1511: return { .age = 2, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1512: return { .age = 2, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1513: return { .age = 2, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1514: return { .age = 2, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1515: return { .age = 2, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1516: return { .age = 2, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1517: return { .age = 2, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1518: return { .age = 2, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1519: return { .age = 2, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1520: return { .age = 2, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1521: return { .age = 2, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1522: return { .age = 2, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1523: return { .age = 2, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1524: return { .age = 2, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1525: return { .age = 2, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1526: return { .age = 2, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1527: return { .age = 2, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1528: return { .age = 2, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1529: return { .age = 2, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1530: return { .age = 2, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1531: return { .age = 2, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1532: return { .age = 2, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1533: return { .age = 2, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1534: return { .age = 2, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1535: return { .age = 3, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1536: return { .age = 3, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1537: return { .age = 3, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1538: return { .age = 3, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1539: return { .age = 3, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1540: return { .age = 3, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1541: return { .age = 3, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1542: return { .age = 3, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1543: return { .age = 3, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1544: return { .age = 3, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1545: return { .age = 3, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1546: return { .age = 3, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1547: return { .age = 3, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1548: return { .age = 3, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1549: return { .age = 3, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1550: return { .age = 3, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1551: return { .age = 3, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1552: return { .age = 3, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1553: return { .age = 3, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1554: return { .age = 3, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1555: return { .age = 3, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1556: return { .age = 3, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1557: return { .age = 3, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1558: return { .age = 3, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1559: return { .age = 3, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1560: return { .age = 3, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1561: return { .age = 3, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1562: return { .age = 3, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1563: return { .age = 3, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1564: return { .age = 3, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1565: return { .age = 3, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1566: return { .age = 3, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1567: return { .age = 4, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1568: return { .age = 4, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1569: return { .age = 4, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1570: return { .age = 4, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1571: return { .age = 4, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1572: return { .age = 4, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1573: return { .age = 4, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1574: return { .age = 4, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1575: return { .age = 4, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1576: return { .age = 4, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1577: return { .age = 4, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1578: return { .age = 4, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1579: return { .age = 4, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1580: return { .age = 4, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1581: return { .age = 4, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1582: return { .age = 4, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1583: return { .age = 4, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1584: return { .age = 4, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1585: return { .age = 4, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1586: return { .age = 4, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1587: return { .age = 4, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1588: return { .age = 4, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1589: return { .age = 4, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1590: return { .age = 4, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1591: return { .age = 4, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1592: return { .age = 4, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1593: return { .age = 4, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1594: return { .age = 4, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1595: return { .age = 4, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1596: return { .age = 4, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1597: return { .age = 4, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1598: return { .age = 4, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1599: return { .age = 5, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1600: return { .age = 5, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1601: return { .age = 5, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1602: return { .age = 5, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1603: return { .age = 5, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1604: return { .age = 5, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1605: return { .age = 5, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1606: return { .age = 5, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1607: return { .age = 5, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1608: return { .age = 5, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1609: return { .age = 5, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1610: return { .age = 5, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1611: return { .age = 5, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1612: return { .age = 5, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1613: return { .age = 5, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1614: return { .age = 5, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1615: return { .age = 5, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1616: return { .age = 5, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1617: return { .age = 5, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1618: return { .age = 5, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1619: return { .age = 5, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1620: return { .age = 5, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1621: return { .age = 5, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1622: return { .age = 5, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1623: return { .age = 5, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1624: return { .age = 5, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1625: return { .age = 5, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1626: return { .age = 5, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1627: return { .age = 5, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1628: return { .age = 5, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1629: return { .age = 5, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1630: return { .age = 5, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1631: return { .age = 6, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1632: return { .age = 6, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1633: return { .age = 6, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1634: return { .age = 6, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1635: return { .age = 6, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1636: return { .age = 6, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1637: return { .age = 6, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1638: return { .age = 6, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1639: return { .age = 6, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1640: return { .age = 6, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1641: return { .age = 6, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1642: return { .age = 6, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1643: return { .age = 6, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1644: return { .age = 6, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1645: return { .age = 6, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1646: return { .age = 6, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1647: return { .age = 6, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1648: return { .age = 6, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1649: return { .age = 6, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1650: return { .age = 6, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1651: return { .age = 6, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1652: return { .age = 6, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1653: return { .age = 6, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1654: return { .age = 6, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1655: return { .age = 6, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1656: return { .age = 6, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1657: return { .age = 6, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1658: return { .age = 6, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1659: return { .age = 6, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1660: return { .age = 6, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1661: return { .age = 6, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1662: return { .age = 6, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1663: return { .age = 7, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1664: return { .age = 7, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1665: return { .age = 7, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1666: return { .age = 7, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1667: return { .age = 7, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1668: return { .age = 7, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1669: return { .age = 7, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1670: return { .age = 7, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1671: return { .age = 7, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1672: return { .age = 7, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1673: return { .age = 7, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1674: return { .age = 7, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1675: return { .age = 7, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1676: return { .age = 7, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1677: return { .age = 7, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1678: return { .age = 7, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1679: return { .age = 7, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1680: return { .age = 7, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1681: return { .age = 7, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1682: return { .age = 7, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1683: return { .age = 7, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1684: return { .age = 7, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1685: return { .age = 7, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1686: return { .age = 7, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1687: return { .age = 7, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1688: return { .age = 7, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1689: return { .age = 7, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1690: return { .age = 7, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1691: return { .age = 7, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1692: return { .age = 7, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1693: return { .age = 7, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1694: return { .age = 7, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1695: return { .age = 8, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1696: return { .age = 8, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1697: return { .age = 8, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1698: return { .age = 8, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1699: return { .age = 8, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1700: return { .age = 8, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1701: return { .age = 8, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1702: return { .age = 8, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1703: return { .age = 8, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1704: return { .age = 8, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1705: return { .age = 8, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1706: return { .age = 8, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1707: return { .age = 8, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1708: return { .age = 8, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1709: return { .age = 8, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1710: return { .age = 8, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1711: return { .age = 8, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1712: return { .age = 8, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1713: return { .age = 8, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1714: return { .age = 8, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1715: return { .age = 8, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1716: return { .age = 8, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1717: return { .age = 8, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1718: return { .age = 8, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1719: return { .age = 8, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1720: return { .age = 8, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1721: return { .age = 8, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1722: return { .age = 8, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1723: return { .age = 8, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1724: return { .age = 8, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1725: return { .age = 8, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1726: return { .age = 8, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1727: return { .age = 9, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1728: return { .age = 9, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1729: return { .age = 9, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1730: return { .age = 9, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1731: return { .age = 9, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1732: return { .age = 9, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1733: return { .age = 9, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1734: return { .age = 9, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1735: return { .age = 9, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1736: return { .age = 9, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1737: return { .age = 9, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1738: return { .age = 9, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1739: return { .age = 9, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1740: return { .age = 9, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1741: return { .age = 9, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1742: return { .age = 9, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1743: return { .age = 9, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1744: return { .age = 9, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1745: return { .age = 9, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1746: return { .age = 9, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1747: return { .age = 9, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1748: return { .age = 9, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1749: return { .age = 9, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1750: return { .age = 9, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1751: return { .age = 9, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1752: return { .age = 9, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1753: return { .age = 9, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1754: return { .age = 9, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1755: return { .age = 9, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1756: return { .age = 9, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1757: return { .age = 9, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1758: return { .age = 9, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1759: return { .age = 10, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1760: return { .age = 10, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1761: return { .age = 10, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1762: return { .age = 10, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1763: return { .age = 10, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1764: return { .age = 10, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1765: return { .age = 10, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1766: return { .age = 10, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1767: return { .age = 10, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1768: return { .age = 10, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1769: return { .age = 10, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1770: return { .age = 10, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1771: return { .age = 10, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1772: return { .age = 10, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1773: return { .age = 10, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1774: return { .age = 10, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1775: return { .age = 10, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1776: return { .age = 10, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1777: return { .age = 10, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1778: return { .age = 10, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1779: return { .age = 10, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1780: return { .age = 10, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1781: return { .age = 10, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1782: return { .age = 10, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1783: return { .age = 10, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1784: return { .age = 10, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1785: return { .age = 10, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1786: return { .age = 10, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1787: return { .age = 10, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1788: return { .age = 10, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1789: return { .age = 10, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1790: return { .age = 10, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1791: return { .age = 11, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1792: return { .age = 11, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1793: return { .age = 11, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1794: return { .age = 11, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1795: return { .age = 11, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1796: return { .age = 11, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1797: return { .age = 11, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1798: return { .age = 11, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1799: return { .age = 11, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1800: return { .age = 11, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1801: return { .age = 11, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1802: return { .age = 11, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1803: return { .age = 11, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1804: return { .age = 11, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1805: return { .age = 11, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1806: return { .age = 11, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1807: return { .age = 11, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1808: return { .age = 11, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1809: return { .age = 11, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1810: return { .age = 11, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1811: return { .age = 11, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1812: return { .age = 11, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1813: return { .age = 11, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1814: return { .age = 11, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1815: return { .age = 11, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1816: return { .age = 11, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1817: return { .age = 11, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1818: return { .age = 11, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1819: return { .age = 11, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1820: return { .age = 11, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1821: return { .age = 11, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1822: return { .age = 11, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1823: return { .age = 12, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1824: return { .age = 12, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1825: return { .age = 12, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1826: return { .age = 12, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1827: return { .age = 12, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1828: return { .age = 12, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1829: return { .age = 12, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1830: return { .age = 12, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1831: return { .age = 12, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1832: return { .age = 12, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1833: return { .age = 12, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1834: return { .age = 12, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1835: return { .age = 12, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1836: return { .age = 12, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1837: return { .age = 12, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1838: return { .age = 12, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1839: return { .age = 12, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1840: return { .age = 12, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1841: return { .age = 12, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1842: return { .age = 12, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1843: return { .age = 12, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1844: return { .age = 12, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1845: return { .age = 12, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1846: return { .age = 12, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1847: return { .age = 12, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1848: return { .age = 12, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1849: return { .age = 12, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1850: return { .age = 12, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1851: return { .age = 12, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1852: return { .age = 12, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1853: return { .age = 12, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1854: return { .age = 12, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1855: return { .age = 13, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1856: return { .age = 13, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1857: return { .age = 13, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1858: return { .age = 13, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1859: return { .age = 13, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1860: return { .age = 13, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1861: return { .age = 13, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1862: return { .age = 13, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1863: return { .age = 13, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1864: return { .age = 13, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1865: return { .age = 13, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1866: return { .age = 13, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1867: return { .age = 13, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1868: return { .age = 13, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1869: return { .age = 13, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1870: return { .age = 13, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1871: return { .age = 13, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1872: return { .age = 13, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1873: return { .age = 13, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1874: return { .age = 13, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1875: return { .age = 13, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1876: return { .age = 13, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1877: return { .age = 13, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1878: return { .age = 13, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1879: return { .age = 13, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1880: return { .age = 13, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1881: return { .age = 13, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1882: return { .age = 13, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1883: return { .age = 13, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1884: return { .age = 13, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1885: return { .age = 13, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1886: return { .age = 13, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1887: return { .age = 14, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1888: return { .age = 14, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1889: return { .age = 14, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1890: return { .age = 14, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1891: return { .age = 14, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1892: return { .age = 14, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1893: return { .age = 14, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1894: return { .age = 14, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1895: return { .age = 14, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1896: return { .age = 14, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1897: return { .age = 14, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1898: return { .age = 14, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1899: return { .age = 14, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1900: return { .age = 14, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1901: return { .age = 14, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1902: return { .age = 14, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1903: return { .age = 14, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1904: return { .age = 14, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1905: return { .age = 14, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1906: return { .age = 14, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1907: return { .age = 14, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1908: return { .age = 14, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1909: return { .age = 14, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1910: return { .age = 14, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1911: return { .age = 14, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1912: return { .age = 14, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1913: return { .age = 14, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1914: return { .age = 14, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1915: return { .age = 14, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1916: return { .age = 14, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1917: return { .age = 14, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1918: return { .age = 14, .east = false, .north = false, .south = false, .up = false, .west = false };
            case 1919: return { .age = 15, .east = true, .north = true, .south = true, .up = true, .west = true };
            case 1920: return { .age = 15, .east = true, .north = true, .south = true, .up = true, .west = false };
            case 1921: return { .age = 15, .east = true, .north = true, .south = true, .up = false, .west = true };
            case 1922: return { .age = 15, .east = true, .north = true, .south = true, .up = false, .west = false };
            case 1923: return { .age = 15, .east = true, .north = true, .south = false, .up = true, .west = true };
            case 1924: return { .age = 15, .east = true, .north = true, .south = false, .up = true, .west = false };
            case 1925: return { .age = 15, .east = true, .north = true, .south = false, .up = false, .west = true };
            case 1926: return { .age = 15, .east = true, .north = true, .south = false, .up = false, .west = false };
            case 1927: return { .age = 15, .east = true, .north = false, .south = true, .up = true, .west = true };
            case 1928: return { .age = 15, .east = true, .north = false, .south = true, .up = true, .west = false };
            case 1929: return { .age = 15, .east = true, .north = false, .south = true, .up = false, .west = true };
            case 1930: return { .age = 15, .east = true, .north = false, .south = true, .up = false, .west = false };
            case 1931: return { .age = 15, .east = true, .north = false, .south = false, .up = true, .west = true };
            case 1932: return { .age = 15, .east = true, .north = false, .south = false, .up = true, .west = false };
            case 1933: return { .age = 15, .east = true, .north = false, .south = false, .up = false, .west = true };
            case 1934: return { .age = 15, .east = true, .north = false, .south = false, .up = false, .west = false };
            case 1935: return { .age = 15, .east = false, .north = true, .south = true, .up = true, .west = true };
            case 1936: return { .age = 15, .east = false, .north = true, .south = true, .up = true, .west = false };
            case 1937: return { .age = 15, .east = false, .north = true, .south = true, .up = false, .west = true };
            case 1938: return { .age = 15, .east = false, .north = true, .south = true, .up = false, .west = false };
            case 1939: return { .age = 15, .east = false, .north = true, .south = false, .up = true, .west = true };
            case 1940: return { .age = 15, .east = false, .north = true, .south = false, .up = true, .west = false };
            case 1941: return { .age = 15, .east = false, .north = true, .south = false, .up = false, .west = true };
            case 1942: return { .age = 15, .east = false, .north = true, .south = false, .up = false, .west = false };
            case 1943: return { .age = 15, .east = false, .north = false, .south = true, .up = true, .west = true };
            case 1944: return { .age = 15, .east = false, .north = false, .south = true, .up = true, .west = false };
            case 1945: return { .age = 15, .east = false, .north = false, .south = true, .up = false, .west = true };
            case 1946: return { .age = 15, .east = false, .north = false, .south = true, .up = false, .west = false };
            case 1947: return { .age = 15, .east = false, .north = false, .south = false, .up = true, .west = true };
            case 1948: return { .age = 15, .east = false, .north = false, .south = false, .up = true, .west = false };
            case 1949: return { .age = 15, .east = false, .north = false, .south = false, .up = false, .west = true };
            case 1950: return { .age = 15, .east = false, .north = false, .south = false, .up = false, .west = false };
            }
        }
        constexpr std::string_view to_string() const
        {
            switch (age)
            {
            case 0:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:true:true:true:true:true";
                                case false: return "minecraft:fire:0:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:true:true:true:false:true";
                                case false: return "minecraft:fire:0:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:true:true:false:true:true";
                                case false: return "minecraft:fire:0:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:true:true:false:false:true";
                                case false: return "minecraft:fire:0:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:true:false:true:true:true";
                                case false: return "minecraft:fire:0:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:true:false:true:false:true";
                                case false: return "minecraft:fire:0:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:true:false:false:true:true";
                                case false: return "minecraft:fire:0:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:true:false:false:false:true";
                                case false: return "minecraft:fire:0:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:false:true:true:true:true";
                                case false: return "minecraft:fire:0:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:false:true:true:false:true";
                                case false: return "minecraft:fire:0:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:false:true:false:true:true";
                                case false: return "minecraft:fire:0:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:false:true:false:false:true";
                                case false: return "minecraft:fire:0:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:false:false:true:true:true";
                                case false: return "minecraft:fire:0:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:false:false:true:false:true";
                                case false: return "minecraft:fire:0:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:false:false:false:true:true";
                                case false: return "minecraft:fire:0:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:0:false:false:false:false:true";
                                case false: return "minecraft:fire:0:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 1:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:true:true:true:true:true";
                                case false: return "minecraft:fire:1:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:true:true:true:false:true";
                                case false: return "minecraft:fire:1:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:true:true:false:true:true";
                                case false: return "minecraft:fire:1:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:true:true:false:false:true";
                                case false: return "minecraft:fire:1:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:true:false:true:true:true";
                                case false: return "minecraft:fire:1:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:true:false:true:false:true";
                                case false: return "minecraft:fire:1:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:true:false:false:true:true";
                                case false: return "minecraft:fire:1:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:true:false:false:false:true";
                                case false: return "minecraft:fire:1:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:false:true:true:true:true";
                                case false: return "minecraft:fire:1:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:false:true:true:false:true";
                                case false: return "minecraft:fire:1:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:false:true:false:true:true";
                                case false: return "minecraft:fire:1:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:false:true:false:false:true";
                                case false: return "minecraft:fire:1:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:false:false:true:true:true";
                                case false: return "minecraft:fire:1:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:false:false:true:false:true";
                                case false: return "minecraft:fire:1:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:false:false:false:true:true";
                                case false: return "minecraft:fire:1:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:1:false:false:false:false:true";
                                case false: return "minecraft:fire:1:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 2:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:true:true:true:true:true";
                                case false: return "minecraft:fire:2:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:true:true:true:false:true";
                                case false: return "minecraft:fire:2:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:true:true:false:true:true";
                                case false: return "minecraft:fire:2:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:true:true:false:false:true";
                                case false: return "minecraft:fire:2:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:true:false:true:true:true";
                                case false: return "minecraft:fire:2:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:true:false:true:false:true";
                                case false: return "minecraft:fire:2:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:true:false:false:true:true";
                                case false: return "minecraft:fire:2:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:true:false:false:false:true";
                                case false: return "minecraft:fire:2:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:false:true:true:true:true";
                                case false: return "minecraft:fire:2:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:false:true:true:false:true";
                                case false: return "minecraft:fire:2:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:false:true:false:true:true";
                                case false: return "minecraft:fire:2:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:false:true:false:false:true";
                                case false: return "minecraft:fire:2:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:false:false:true:true:true";
                                case false: return "minecraft:fire:2:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:false:false:true:false:true";
                                case false: return "minecraft:fire:2:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:false:false:false:true:true";
                                case false: return "minecraft:fire:2:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:2:false:false:false:false:true";
                                case false: return "minecraft:fire:2:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 3:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:true:true:true:true:true";
                                case false: return "minecraft:fire:3:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:true:true:true:false:true";
                                case false: return "minecraft:fire:3:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:true:true:false:true:true";
                                case false: return "minecraft:fire:3:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:true:true:false:false:true";
                                case false: return "minecraft:fire:3:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:true:false:true:true:true";
                                case false: return "minecraft:fire:3:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:true:false:true:false:true";
                                case false: return "minecraft:fire:3:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:true:false:false:true:true";
                                case false: return "minecraft:fire:3:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:true:false:false:false:true";
                                case false: return "minecraft:fire:3:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:false:true:true:true:true";
                                case false: return "minecraft:fire:3:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:false:true:true:false:true";
                                case false: return "minecraft:fire:3:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:false:true:false:true:true";
                                case false: return "minecraft:fire:3:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:false:true:false:false:true";
                                case false: return "minecraft:fire:3:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:false:false:true:true:true";
                                case false: return "minecraft:fire:3:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:false:false:true:false:true";
                                case false: return "minecraft:fire:3:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:false:false:false:true:true";
                                case false: return "minecraft:fire:3:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:3:false:false:false:false:true";
                                case false: return "minecraft:fire:3:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 4:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:true:true:true:true:true";
                                case false: return "minecraft:fire:4:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:true:true:true:false:true";
                                case false: return "minecraft:fire:4:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:true:true:false:true:true";
                                case false: return "minecraft:fire:4:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:true:true:false:false:true";
                                case false: return "minecraft:fire:4:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:true:false:true:true:true";
                                case false: return "minecraft:fire:4:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:true:false:true:false:true";
                                case false: return "minecraft:fire:4:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:true:false:false:true:true";
                                case false: return "minecraft:fire:4:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:true:false:false:false:true";
                                case false: return "minecraft:fire:4:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:false:true:true:true:true";
                                case false: return "minecraft:fire:4:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:false:true:true:false:true";
                                case false: return "minecraft:fire:4:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:false:true:false:true:true";
                                case false: return "minecraft:fire:4:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:false:true:false:false:true";
                                case false: return "minecraft:fire:4:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:false:false:true:true:true";
                                case false: return "minecraft:fire:4:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:false:false:true:false:true";
                                case false: return "minecraft:fire:4:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:false:false:false:true:true";
                                case false: return "minecraft:fire:4:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:4:false:false:false:false:true";
                                case false: return "minecraft:fire:4:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 5:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:true:true:true:true:true";
                                case false: return "minecraft:fire:5:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:true:true:true:false:true";
                                case false: return "minecraft:fire:5:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:true:true:false:true:true";
                                case false: return "minecraft:fire:5:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:true:true:false:false:true";
                                case false: return "minecraft:fire:5:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:true:false:true:true:true";
                                case false: return "minecraft:fire:5:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:true:false:true:false:true";
                                case false: return "minecraft:fire:5:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:true:false:false:true:true";
                                case false: return "minecraft:fire:5:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:true:false:false:false:true";
                                case false: return "minecraft:fire:5:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:false:true:true:true:true";
                                case false: return "minecraft:fire:5:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:false:true:true:false:true";
                                case false: return "minecraft:fire:5:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:false:true:false:true:true";
                                case false: return "minecraft:fire:5:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:false:true:false:false:true";
                                case false: return "minecraft:fire:5:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:false:false:true:true:true";
                                case false: return "minecraft:fire:5:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:false:false:true:false:true";
                                case false: return "minecraft:fire:5:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:false:false:false:true:true";
                                case false: return "minecraft:fire:5:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:5:false:false:false:false:true";
                                case false: return "minecraft:fire:5:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 6:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:true:true:true:true:true";
                                case false: return "minecraft:fire:6:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:true:true:true:false:true";
                                case false: return "minecraft:fire:6:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:true:true:false:true:true";
                                case false: return "minecraft:fire:6:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:true:true:false:false:true";
                                case false: return "minecraft:fire:6:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:true:false:true:true:true";
                                case false: return "minecraft:fire:6:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:true:false:true:false:true";
                                case false: return "minecraft:fire:6:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:true:false:false:true:true";
                                case false: return "minecraft:fire:6:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:true:false:false:false:true";
                                case false: return "minecraft:fire:6:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:false:true:true:true:true";
                                case false: return "minecraft:fire:6:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:false:true:true:false:true";
                                case false: return "minecraft:fire:6:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:false:true:false:true:true";
                                case false: return "minecraft:fire:6:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:false:true:false:false:true";
                                case false: return "minecraft:fire:6:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:false:false:true:true:true";
                                case false: return "minecraft:fire:6:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:false:false:true:false:true";
                                case false: return "minecraft:fire:6:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:false:false:false:true:true";
                                case false: return "minecraft:fire:6:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:6:false:false:false:false:true";
                                case false: return "minecraft:fire:6:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 7:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:true:true:true:true:true";
                                case false: return "minecraft:fire:7:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:true:true:true:false:true";
                                case false: return "minecraft:fire:7:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:true:true:false:true:true";
                                case false: return "minecraft:fire:7:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:true:true:false:false:true";
                                case false: return "minecraft:fire:7:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:true:false:true:true:true";
                                case false: return "minecraft:fire:7:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:true:false:true:false:true";
                                case false: return "minecraft:fire:7:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:true:false:false:true:true";
                                case false: return "minecraft:fire:7:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:true:false:false:false:true";
                                case false: return "minecraft:fire:7:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:false:true:true:true:true";
                                case false: return "minecraft:fire:7:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:false:true:true:false:true";
                                case false: return "minecraft:fire:7:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:false:true:false:true:true";
                                case false: return "minecraft:fire:7:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:false:true:false:false:true";
                                case false: return "minecraft:fire:7:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:false:false:true:true:true";
                                case false: return "minecraft:fire:7:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:false:false:true:false:true";
                                case false: return "minecraft:fire:7:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:false:false:false:true:true";
                                case false: return "minecraft:fire:7:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:7:false:false:false:false:true";
                                case false: return "minecraft:fire:7:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 8:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:true:true:true:true:true";
                                case false: return "minecraft:fire:8:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:true:true:true:false:true";
                                case false: return "minecraft:fire:8:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:true:true:false:true:true";
                                case false: return "minecraft:fire:8:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:true:true:false:false:true";
                                case false: return "minecraft:fire:8:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:true:false:true:true:true";
                                case false: return "minecraft:fire:8:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:true:false:true:false:true";
                                case false: return "minecraft:fire:8:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:true:false:false:true:true";
                                case false: return "minecraft:fire:8:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:true:false:false:false:true";
                                case false: return "minecraft:fire:8:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:false:true:true:true:true";
                                case false: return "minecraft:fire:8:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:false:true:true:false:true";
                                case false: return "minecraft:fire:8:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:false:true:false:true:true";
                                case false: return "minecraft:fire:8:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:false:true:false:false:true";
                                case false: return "minecraft:fire:8:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:false:false:true:true:true";
                                case false: return "minecraft:fire:8:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:false:false:true:false:true";
                                case false: return "minecraft:fire:8:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:false:false:false:true:true";
                                case false: return "minecraft:fire:8:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:8:false:false:false:false:true";
                                case false: return "minecraft:fire:8:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 9:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:true:true:true:true:true";
                                case false: return "minecraft:fire:9:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:true:true:true:false:true";
                                case false: return "minecraft:fire:9:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:true:true:false:true:true";
                                case false: return "minecraft:fire:9:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:true:true:false:false:true";
                                case false: return "minecraft:fire:9:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:true:false:true:true:true";
                                case false: return "minecraft:fire:9:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:true:false:true:false:true";
                                case false: return "minecraft:fire:9:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:true:false:false:true:true";
                                case false: return "minecraft:fire:9:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:true:false:false:false:true";
                                case false: return "minecraft:fire:9:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:false:true:true:true:true";
                                case false: return "minecraft:fire:9:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:false:true:true:false:true";
                                case false: return "minecraft:fire:9:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:false:true:false:true:true";
                                case false: return "minecraft:fire:9:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:false:true:false:false:true";
                                case false: return "minecraft:fire:9:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:false:false:true:true:true";
                                case false: return "minecraft:fire:9:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:false:false:true:false:true";
                                case false: return "minecraft:fire:9:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:false:false:false:true:true";
                                case false: return "minecraft:fire:9:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:9:false:false:false:false:true";
                                case false: return "minecraft:fire:9:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 10:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:true:true:true:true:true";
                                case false: return "minecraft:fire:10:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:true:true:true:false:true";
                                case false: return "minecraft:fire:10:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:true:true:false:true:true";
                                case false: return "minecraft:fire:10:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:true:true:false:false:true";
                                case false: return "minecraft:fire:10:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:true:false:true:true:true";
                                case false: return "minecraft:fire:10:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:true:false:true:false:true";
                                case false: return "minecraft:fire:10:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:true:false:false:true:true";
                                case false: return "minecraft:fire:10:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:true:false:false:false:true";
                                case false: return "minecraft:fire:10:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:false:true:true:true:true";
                                case false: return "minecraft:fire:10:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:false:true:true:false:true";
                                case false: return "minecraft:fire:10:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:false:true:false:true:true";
                                case false: return "minecraft:fire:10:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:false:true:false:false:true";
                                case false: return "minecraft:fire:10:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:false:false:true:true:true";
                                case false: return "minecraft:fire:10:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:false:false:true:false:true";
                                case false: return "minecraft:fire:10:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:false:false:false:true:true";
                                case false: return "minecraft:fire:10:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:10:false:false:false:false:true";
                                case false: return "minecraft:fire:10:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 11:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:true:true:true:true:true";
                                case false: return "minecraft:fire:11:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:true:true:true:false:true";
                                case false: return "minecraft:fire:11:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:true:true:false:true:true";
                                case false: return "minecraft:fire:11:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:true:true:false:false:true";
                                case false: return "minecraft:fire:11:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:true:false:true:true:true";
                                case false: return "minecraft:fire:11:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:true:false:true:false:true";
                                case false: return "minecraft:fire:11:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:true:false:false:true:true";
                                case false: return "minecraft:fire:11:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:true:false:false:false:true";
                                case false: return "minecraft:fire:11:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:false:true:true:true:true";
                                case false: return "minecraft:fire:11:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:false:true:true:false:true";
                                case false: return "minecraft:fire:11:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:false:true:false:true:true";
                                case false: return "minecraft:fire:11:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:false:true:false:false:true";
                                case false: return "minecraft:fire:11:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:false:false:true:true:true";
                                case false: return "minecraft:fire:11:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:false:false:true:false:true";
                                case false: return "minecraft:fire:11:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:false:false:false:true:true";
                                case false: return "minecraft:fire:11:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:11:false:false:false:false:true";
                                case false: return "minecraft:fire:11:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 12:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:true:true:true:true:true";
                                case false: return "minecraft:fire:12:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:true:true:true:false:true";
                                case false: return "minecraft:fire:12:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:true:true:false:true:true";
                                case false: return "minecraft:fire:12:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:true:true:false:false:true";
                                case false: return "minecraft:fire:12:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:true:false:true:true:true";
                                case false: return "minecraft:fire:12:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:true:false:true:false:true";
                                case false: return "minecraft:fire:12:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:true:false:false:true:true";
                                case false: return "minecraft:fire:12:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:true:false:false:false:true";
                                case false: return "minecraft:fire:12:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:false:true:true:true:true";
                                case false: return "minecraft:fire:12:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:false:true:true:false:true";
                                case false: return "minecraft:fire:12:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:false:true:false:true:true";
                                case false: return "minecraft:fire:12:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:false:true:false:false:true";
                                case false: return "minecraft:fire:12:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:false:false:true:true:true";
                                case false: return "minecraft:fire:12:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:false:false:true:false:true";
                                case false: return "minecraft:fire:12:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:false:false:false:true:true";
                                case false: return "minecraft:fire:12:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:12:false:false:false:false:true";
                                case false: return "minecraft:fire:12:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 13:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:true:true:true:true:true";
                                case false: return "minecraft:fire:13:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:true:true:true:false:true";
                                case false: return "minecraft:fire:13:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:true:true:false:true:true";
                                case false: return "minecraft:fire:13:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:true:true:false:false:true";
                                case false: return "minecraft:fire:13:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:true:false:true:true:true";
                                case false: return "minecraft:fire:13:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:true:false:true:false:true";
                                case false: return "minecraft:fire:13:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:true:false:false:true:true";
                                case false: return "minecraft:fire:13:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:true:false:false:false:true";
                                case false: return "minecraft:fire:13:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:false:true:true:true:true";
                                case false: return "minecraft:fire:13:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:false:true:true:false:true";
                                case false: return "minecraft:fire:13:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:false:true:false:true:true";
                                case false: return "minecraft:fire:13:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:false:true:false:false:true";
                                case false: return "minecraft:fire:13:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:false:false:true:true:true";
                                case false: return "minecraft:fire:13:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:false:false:true:false:true";
                                case false: return "minecraft:fire:13:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:false:false:false:true:true";
                                case false: return "minecraft:fire:13:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:13:false:false:false:false:true";
                                case false: return "minecraft:fire:13:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 14:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:true:true:true:true:true";
                                case false: return "minecraft:fire:14:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:true:true:true:false:true";
                                case false: return "minecraft:fire:14:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:true:true:false:true:true";
                                case false: return "minecraft:fire:14:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:true:true:false:false:true";
                                case false: return "minecraft:fire:14:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:true:false:true:true:true";
                                case false: return "minecraft:fire:14:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:true:false:true:false:true";
                                case false: return "minecraft:fire:14:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:true:false:false:true:true";
                                case false: return "minecraft:fire:14:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:true:false:false:false:true";
                                case false: return "minecraft:fire:14:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:false:true:true:true:true";
                                case false: return "minecraft:fire:14:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:false:true:true:false:true";
                                case false: return "minecraft:fire:14:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:false:true:false:true:true";
                                case false: return "minecraft:fire:14:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:false:true:false:false:true";
                                case false: return "minecraft:fire:14:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:false:false:true:true:true";
                                case false: return "minecraft:fire:14:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:false:false:true:false:true";
                                case false: return "minecraft:fire:14:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:false:false:false:true:true";
                                case false: return "minecraft:fire:14:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:14:false:false:false:false:true";
                                case false: return "minecraft:fire:14:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            case 15:
                switch (east)
                {
                case true:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:true:true:true:true:true";
                                case false: return "minecraft:fire:15:true:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:true:true:true:false:true";
                                case false: return "minecraft:fire:15:true:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:true:true:false:true:true";
                                case false: return "minecraft:fire:15:true:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:true:true:false:false:true";
                                case false: return "minecraft:fire:15:true:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:true:false:true:true:true";
                                case false: return "minecraft:fire:15:true:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:true:false:true:false:true";
                                case false: return "minecraft:fire:15:true:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:true:false:false:true:true";
                                case false: return "minecraft:fire:15:true:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:true:false:false:false:true";
                                case false: return "minecraft:fire:15:true:false:false:false:false";
                                }
                            }
                        }
                    }
                case false:
                    switch (north)
                    {
                    case true:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:false:true:true:true:true";
                                case false: return "minecraft:fire:15:false:true:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:false:true:true:false:true";
                                case false: return "minecraft:fire:15:false:true:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:false:true:false:true:true";
                                case false: return "minecraft:fire:15:false:true:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:false:true:false:false:true";
                                case false: return "minecraft:fire:15:false:true:false:false:false";
                                }
                            }
                        }
                    case false:
                        switch (south)
                        {
                        case true:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:false:false:true:true:true";
                                case false: return "minecraft:fire:15:false:false:true:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:false:false:true:false:true";
                                case false: return "minecraft:fire:15:false:false:true:false:false";
                                }
                            }
                        case false:
                            switch (up)
                            {
                            case true:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:false:false:false:true:true";
                                case false: return "minecraft:fire:15:false:false:false:true:false";
                                }
                            case false:
                                switch (west)
                                {
                                case true: return "minecraft:fire:15:false:false:false:false:true";
                                case false: return "minecraft:fire:15:false:false:false:false:false";
                                }
                            }
                        }
                    }
                }
            }
        }
    };
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
