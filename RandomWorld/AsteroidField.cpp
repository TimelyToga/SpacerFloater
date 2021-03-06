//
//  AsteroidField.cpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 12/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#include "AsteroidField.hpp"
#include <tgmath.h>
#include <iostream>

AsteroidField::AsteroidField(int screenX, int screenY) : Actor(0, 0)
{
    this->halfXScreenSize = screenX * 4;
    this->halfYScreenSize = screenY * 4;
    
}

int AsteroidField::getSpacing()
{
    return this->spacing;
}

void AsteroidField::render(sf::RenderWindow *window, float xOffset, float yOffset)
{
    auto xPosDelta = fmod(xOffset, spacing);
    auto yPosDelta = fmod(yOffset, spacing);
    
    auto minX = xOffset - window->getView().getSize().x;
    auto maxX = xOffset + (window->getView().getSize().x + spacing);
    
    auto minY = yOffset - window->getView().getSize().x;
    auto maxY = yOffset + (2 * halfYScreenSize + spacing);
    
//    printf("(%f, %f)->(%f, %f)\n", minX, minY, maxX, maxY);

    sf::Transform curTransform;
    curTransform.translate(-xOffset, -yOffset);
    
    for(auto x = minX; x <= maxX; x += spacing)
    {
        for(auto y = minY; y <= maxY; y += spacing)
        {
            auto m_x = x - xPosDelta;
            auto m_y = y - yPosDelta;
            
            sf::CircleShape curAsteroid(asteroidSize);
            curAsteroid.setPosition(m_x - (asteroidSize / 2),
                                    m_y - (asteroidSize / 2));
            curAsteroid.setFillColor(color);
            
            window->draw(curAsteroid, curTransform);
        }
    }
}

void AsteroidField::update(float delta)
{
    // Nothing
}
