//
//  Player.hpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 11/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "SFML/Graphics.hpp"

#include "Actor.hpp"
#include "ICollidable.h"

class Player : public Actor
{
    int shipWidth = 40;
    int shipHeight = 70;
    float rotSpeed = 2;
    
    // Thruster
    float shipMass = 10; // kg
    float thrusterPower = 110;
    float speedDecay = .993;
    float forwardCoef = 1.0;
    float backwardCoef = -0.5;
    
    // Laser
    float laserLength = 200;
    float laserThickness = 3;
    float laserDamage = 0.2;
    sf::Vector2f laserTip;
    const sf::Color LASER_COLOR = sf::Color(94, 212, 255);
    sf::RectangleShape laser;
    
public:
    void render(sf::RenderWindow *window, float xOffset, float yOffset);
    void update(float delta);
    void powerThruster(bool forward, float power);
    
    // ICollidable
    bool collisionWith(ICollidable* c);
    
    // Getters / Setters
    void addFuel(int amount);
    void alterHealth(int amount);
    int getFuel();
    int getHealth();
    bool getLaserStatus();
    
    Player(int x, int y)
    : Actor(x, y), velocity(0, 0)
    {
        sprite = new sf::ConvexShape;
        (dynamic_cast<sf::ConvexShape*> (sprite))->setOrigin(sf::Vector2f(0, shipHeight / 2));
        
        // Player specific initialization
        (dynamic_cast<sf::ConvexShape*> (sprite))->setPointCount(3);
        (dynamic_cast<sf::ConvexShape*> (sprite))->setPoint(0, sf::Vector2f(0, 0));
        (dynamic_cast<sf::ConvexShape*> (sprite))->setPoint(1, sf::Vector2f(-shipWidth / 2, shipHeight));
        (dynamic_cast<sf::ConvexShape*> (sprite))->setPoint(2, sf::Vector2f(shipWidth / 2, shipHeight));
        
        (dynamic_cast<sf::ConvexShape*> (sprite))->setPosition(x, y);
        
        (dynamic_cast<sf::ConvexShape*> (sprite))->setFillColor(sf::Color::Cyan);
        
        // Set up Laser
        laser = sf::RectangleShape(sf::Vector2f(laserLength, laserThickness));
        laser.rotate(-90);
        laser.setPosition(x - (laserThickness / 2), y);
        laser.setFillColor(LASER_COLOR);
    }
private:
    sf::Vector2f force;
    sf::Vector2f acceleration;
    sf::Vector2f velocity;
    
    int fuel;
    int health = 100;
    bool laserOn;
    
    void handleUserInput();
    void engageLaser(bool laserOn);
    void updateLaser(float delta);
};

#endif /* Player_hpp */
