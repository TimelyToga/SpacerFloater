//
//  Actor.hpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 09/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#ifndef Actor_hpp
#define Actor_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "IUpdatable.h"
#include "ICollidable.h"


class Actor : public IUpdatable, public ICollidable
{
protected:
    sf::Shape* sprite;
    sf::Vector2f direction;
public:
    Actor(int x, int y);
    
    virtual void render(sf::RenderWindow *window, float xOffset, float yOffset) = 0;
    
    // Base class methods
    void rotate(float degrees);
};

#endif /* Actor_hpp */
