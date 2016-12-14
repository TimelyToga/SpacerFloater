//
//  VectorUtils.cpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 14/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#include "VectorUtils.hpp"
#include <iostream>
#include "math.h"

void util::printf(sf::Vector2f v)
{
    std::printf("(%f, %f)\n", v.x, v.y);
}

float util::distanceTo(sf::Vector2f v1, sf::Vector2f v2)
{
    return sqrtf(pow((v1.x - v2.x) , 2) + pow((v1.y - v2.y) ,2));
}
