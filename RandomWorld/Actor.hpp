//
//  Actor.hpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 09/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#ifndef Actor_hpp
#define Actor_hpp

#include "math.h"
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "IUpdatable.h"
#include "ICollidable.h"
#include "IRenderable.h"
#include "DEFINITIONS.c"


class Actor : public IUpdatable, public ICollidable, public IRenderable
{
protected:
    sf::Shape* sprite;
    sf::Vector2f direction;
    
    void recenterSprite();
    bool isDead;
public:
    Actor(int x, int y);
    Actor(int x, int y, int radius);
    
    // Base class methods
    void rotate(float degrees);
    bool getIsDead();
};

#endif /* Actor_hpp */
