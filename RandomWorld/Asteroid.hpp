//
//  Asteroid.hpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 13/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#ifndef Asteroid_hpp
#define Asteroid_hpp

#include "SFML/Graphics.hpp"
#include <stdio.h>

#include "ICollidable.h"
#include "Actor.hpp"

class Asteroid : public Actor
{
    const sf::Color COLOR = sf::Color(78, 81, 86);
public:
    void render(sf::RenderWindow *window, float xOffset, float yOffset);
    void update(float delta);
    
    bool collisionWith(ICollidable* c);
    
    Asteroid(int x, int y, int size) : Actor(x, y, size)
    {
        this->sprite = new sf::CircleShape(size);
        (dynamic_cast<sf::CircleShape*>(sprite))->setFillColor(COLOR);
        (dynamic_cast<sf::CircleShape*>(sprite))->setPosition(x, y);
        this->health = size;
        
        std::cout << "H " << health << " R " << getRadius() << std::endl;
    }
};


#endif /* Asteroid_hpp */
