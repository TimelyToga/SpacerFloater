//
//  AsteroidField.hpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 12/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#ifndef AsteroidField_hpp
#define AsteroidField_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Actor.hpp"
#include <noise/noise.h>

using namespace noise;

class AsteroidField : public Actor
{
    const int spacing = 600;
    const int asteroidSize = 5;
    const sf::Color color = sf::Color::Magenta;
public:
    AsteroidField(int screenX, int screenY);
    int getSpacing();
    
    // Actor methods
    void render(sf::RenderWindow *window, float xOffset, float yOffset);
    void update(float delta);
    bool collisionWith(ICollidable* c) { return true;}
private:
    float halfXScreenSize, halfYScreenSize;
};

#endif /* AsteroidField_hpp */
