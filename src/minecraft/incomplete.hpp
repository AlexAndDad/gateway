//
// Created by rhodges on 12/04/2020.
//

#pragma once

#include<exception>
#include<ostream>

namespace minecraft {
    struct incomplete
    {
        friend void
        report_on(std::ostream &os, incomplete const &);
    };

}