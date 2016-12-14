//
//  Asteroid.cpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 13/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#include "Asteroid.hpp"

void Asteroid::render(sf::RenderWindow* window, float xOffset, float yOffset)
{
    sf::Transform offset;
    offset.translate(-xOffset, -yOffset);
    window->draw(*sprite, offset);
}

void Asteroid::update(float delta)
{
    sprite->setPosition(position);
}

bool Asteroid::collisionWith(ICollidable* c)
{
    return true;
}
