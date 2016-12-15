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
    this->radius = 35;
    sf::CircleShape collisionBox(radius);
    collisionBox.setFillColor(sf::Color::Transparent);
    collisionBox.setPosition(position.x - radius, position.y - radius);
    collisionBox.setOutlineColor(sf::Color::Cyan);
    collisionBox.setOutlineThickness(2);
    
    sf::Transform offset;
    offset.translate(-xOffset, -yOffset);
    window->draw(collisionBox, offset);
    window->draw(*sprite, offset);
}

void Player::update(float delta)
{
    (dynamic_cast<sf::ConvexShape*> (sprite))->setPosition(position);
    
    // Handle player rotation
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        rotate(-rotSpeed);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        rotate(rotSpeed);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        powerThruster(true);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        powerThruster(false);
    }
    
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

void Player::powerThruster(bool forward)
{
    float magnitude = forward ? forwardCoef : backwardCoef;
    sf::Vector2f thrustVector = direction;
    float directionMagnitude = sqrt(pow(thrustVector.x, 2) + pow(thrustVector.y, 2));
    thrustVector *= thrusterPower * magnitude;
    
    force += thrustVector;    
}

bool Player::collisionWith(ICollidable* c)
{
    auto distance = util::distanceTo(position, c->getPosition());
    auto minDistance = this->radius + c->getRadius();
    return distance < minDistance;
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
