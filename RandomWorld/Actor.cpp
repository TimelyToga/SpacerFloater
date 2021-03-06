//
//  Actor.cpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 09/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#include "Actor.hpp"

Actor::Actor(int x, int y) :
    ICollidable()
{
    direction = sf::Vector2f(0, -1);
    setPosition(sf::Vector2f(x, y));
}

Actor::Actor(int x, int y, int size) :
ICollidable()
{
    direction = sf::Vector2f(0, -1);
    setRadius(size);
    setPosition(sf::Vector2f(x, y));
}

void Actor::rotate(float degrees)
{
    (dynamic_cast<sf::ConvexShape*> (sprite))->rotate(degrees);
    auto radians = degrees * PI / 180;
    auto newAngle = atan2(direction.y, direction.x) + radians;
    
//    auto newAngleDegrees = newAngle * 180 / PI;
    
    auto newX = cos(newAngle);
    auto newY = sin(newAngle);
    
    direction = sf::Vector2f(newX, newY);
}

void Actor::recenterSprite()
{
    sprite->setPosition(*getPosition());
}

bool Actor::getIsDead()
{
    return isDead;
}
