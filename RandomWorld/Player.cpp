//
//  Player.cpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 11/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "math.h"

#include "Player.hpp"
#include "utils.h"

void Player::render(sf::RenderWindow* window, float xOffset, float yOffset)
{
    this->setRadius(35);
    sf::CircleShape collisionBox(getRadius());
    collisionBox.setFillColor(sf::Color::Transparent);
    collisionBox.setPosition(getPosition()->x - getRadius(),
                             getPosition()->y - getRadius());
    collisionBox.setOutlineColor(sf::Color::Cyan);
    collisionBox.setOutlineThickness(2);
    
    sf::Transform offset;
    offset.translate(-xOffset, -yOffset);
    window->draw(collisionBox, offset);
    if(laserOn) window->draw(laser, offset);
    window->draw(*sprite, offset);
    
    // Laser helper
    sf::CircleShape lBall(5);
    lBall.setFillColor(sf::Color::White);
    lBall.setPosition(laserTip.x, laserTip.y);
    window->draw(lBall, offset);
}

void Player::update(float delta)
{
    sprite->setPosition(*getPosition());
    
    updateLaser(delta);
    handleUserInput();
    
    // Update physics
    acceleration = force / shipMass;
    
    sf::Vector2f deltaPos = acceleration * (delta*delta) + velocity * delta; //s(t)= a*t^2 + v*t
    velocity += acceleration * delta;
    translate(deltaPos);
    
    velocity *= speedDecay;
    
    // Force has been applied, remove it from future calculations
    force = sf::Vector2f(0,0);
    acceleration = sf::Vector2f(0,0);
}

void Player::handleUserInput()
{
    float altModifier = 1.0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)){
        altModifier *= 0.1;
    }
    
    float workingRotSpeed = altModifier * rotSpeed;
    
    // Handle Player rotation
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        laser.rotate(-workingRotSpeed);
        rotate(-workingRotSpeed);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        laser.rotate(workingRotSpeed);
        rotate(workingRotSpeed);
    }
    
    // Handle Thruster engagement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        powerThruster(true, altModifier);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        powerThruster(false, altModifier);
    }
    
    // Handle Laser firing
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        engageLaser(true);
    } else {
        engageLaser(false);
    }
}

void Player::updateLaser(float delta)
{
    laser.setPosition(getPosition()->x - (laserThickness / 2), getPosition()->y);

    laserTip = util::rayFromPoint(laser.getPosition(), laser.getRotation(), laserLength);
}

void Player::powerThruster(bool forward, float power)
{
    float magnitude = forward ? forwardCoef : backwardCoef;
    sf::Vector2f thrustVector = direction;
    thrustVector *= thrusterPower * magnitude * power;
    
    force += thrustVector;    
}

bool Player::collisionWith(ICollidable* c)
{
    if(laserOn)
    {
        std::cout << "Radius: " << c->getRadius() << " d: " << util::distanceTo(laserTip, c->getCenter()) << std::endl;
        // Check for asteroid collision with laser
        if(c->getRadius() >= util::distanceTo(laserTip,
                                              c->getCenter()))
        {
            c->takeDamage(laserDamage);
            std::cout << "DAMAGING ASTEROID! " << c->getRadius() << std::endl;
        }
    }
    auto distance = util::distanceTo(*getPosition(), *c->getPosition());
    auto minDistance = this->getRadius() + c->getRadius();
    return distance < minDistance;
}

void Player::engageLaser(bool laserOn)
{
    this->laserOn = laserOn;
}


// Getters / Setters
void Player::addFuel(int amount)
{
    this->fuel += amount;
}

void Player::alterHealth(int amount)
{
    this->health += amount;
}

int Player::getFuel()
{
    return fuel;
}

int Player::getHealth()
{
    return health;
}

bool Player::getLaserStatus()
{
    return laserOn;
}
