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

float util::distanceTo(float x1, float y1, sf::Vector2f v2)
{
    return sqrtf(pow((x1 - v2.x) , 2) + pow((y1 - v2.y) ,2));
}

float util::distanceTo(float x1, float y1, float x2, float y2)
{
    return sqrtf(pow((x1 - x2) , 2) + pow((y1 - y2) ,2));
}

// Angle given in degrees
sf::Vector2f util::rayFromPoint(sf::Vector2f point, float angle, float magnitude)
{
    auto radians = angle * PI / 180;
    
    // Rotate first around origin
    float lX = magnitude * cos(radians);
    float lY = magnitude * sin(radians);
    
    // Offset to given point
    return sf::Vector2f(lX + point.x, lY + point.y);
}
