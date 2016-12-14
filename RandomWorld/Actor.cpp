//
//  Actor.cpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 09/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#include "Actor.hpp"
#include "math.h"
#include <iostream>

#define PI 3.14159265

Actor::Actor(int x, int y) :
    ICollidable()
{
    direction = sf::Vector2f(0, -1);
    position = sf::Vector2f(x, y);
}

void Actor::rotate(float degrees)
{
    (dynamic_cast<sf::ConvexShape*> (sprite))->rotate(degrees);
    auto radians = degrees * PI / 180;
    auto newAngle = atan2(direction.y, direction.x) + radians;
    
    auto newAngleDegrees = newAngle * 180 / PI;
    
    auto newX = cos(newAngle);
    auto newY = sin(newAngle);
    
    direction = sf::Vector2f(newX, newY);
}
