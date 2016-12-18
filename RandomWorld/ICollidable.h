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
#include <iostream>

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
    
    void setRadius(int radius)
    {
        auto deltaR = this->radius - radius;
        this->radius = radius;
        translate(deltaR, deltaR);
        resetCenter();
    }
    
    sf::Vector2f* getPosition()
    {
        return &position;
    }
    
    void setPosition(sf::Vector2f position)
    {
        this->position = position;
        resetCenter();
    }
    
    sf::Vector2f getCenter()
    {
        return center;
    }
    
    void translate(sf::Vector2f translation)
    {
        translate(translation.x, translation.y);
    }
    
    void translate(float x, float y)
    {
        position.x += x;
        position.y += y;
    }
    
    void takeDamage(float amount){
        health -= amount;
        std::cout << "Health: " << health << std::endl;
    }
    
protected:
    float health;
private:
    sf::Vector2f position;
    sf::Vector2f center;
    int radius;

    
    void resetCenter(){
        center = sf::Vector2f(position.x + radius, position.y + radius);
    }
};

#endif /* ICollidable_h */
