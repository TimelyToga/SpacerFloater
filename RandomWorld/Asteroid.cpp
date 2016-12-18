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
    // Draw Center
    sf::CircleShape c(5);
    c.setPosition(getCenter());
    c.setFillColor(sf::Color::Red);
    
    sf::Transform offset;
    offset.translate(-xOffset, -yOffset);
    window->draw(*sprite, offset);
    window->draw(c, offset);
    
    sf::Vertex line[] =
    {
        sf::Vertex(getCenter()),
        sf::Vertex(*getPosition())
    };
    
    window->draw(line, 2, sf::Lines, offset);
}

void Asteroid::update(float delta)
{
    if(health < 0)
    {
        isDead = true;
    }
    
    // Update radius to health
    setRadius(health);
    (dynamic_cast<sf::CircleShape*>(sprite))->setRadius(health);
    
    sprite->setPosition(*this->getPosition());
    
    std::cout << getPosition()->x << ", " << getPosition()->y << std::endl;
}

bool Asteroid::collisionWith(ICollidable* c)
{
    return true;
}
