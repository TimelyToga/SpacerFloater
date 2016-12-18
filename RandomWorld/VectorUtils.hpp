//
//  VectorUtils.hpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 14/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#ifndef VectorUtils_hpp
#define VectorUtils_hpp

#include <stdio.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "DEFINITIONS.c"

namespace util
{
    void printf(sf::Vector2f v);
    float distanceTo(sf::Vector2f v1, sf::Vector2f v2);
    float distanceTo(float x1, float y1, sf::Vector2f v2);
    float distanceTo(float x1, float y1, float x2, float y2);
    sf::Vector2f rayFromPoint(sf::Vector2f point, float angle, float magnitude);
}

#endif /* VectorUtils_hpp */
