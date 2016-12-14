//
//  ICollidable.h: Defines an interface for objects that are indeed collidable
//  RandomWorld
//
//  Created by Timothy Blumberg on 14/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#ifndef ICollidable_h
#define ICollidable_h

#include "SFML/Graphics.hpp"

class ICollidable
{
public:
    // Virtuals
    virtual bool collisionWith(ICollidable* c) = 0;
    
    
    // Basic Implementation
    int getRadius()
    {
        return radius;
    }
    
    sf::Vector2f getPosition()
    {
        return position;
    }
    
    void translate(sf::Vector2f translation)
    {
        position += translation;
    }
    
protected:
    int radius;
    sf::Vector2f position;
};

#endif /* ICollidable_h */
