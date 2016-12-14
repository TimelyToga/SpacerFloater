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

namespace util
{
    void printf(sf::Vector2f v);
    float distanceTo(sf::Vector2f v1, sf::Vector2f v2);
}

#endif /* VectorUtils_hpp */
