//
//  CollisionManager.cpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 14/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#include <iostream>

#include "CollisionManager.hpp"

CollisionManager::CollisionManager(Player* p) :
    collidables()
{
    this->player = p;
}

void CollisionManager::addCollidable(ICollidable* c)
{
    collidables.push_back(c);
}

void CollisionManager::update(float delta)
{
    // Only check if Anything collides with player
    for(int a = 0; a < collidables.size(); a++)
    {
        if(typeid(collidables[a]) == typeid(player))
        {
            continue;
        }
        
        if(player->collisionWith(collidables[a]))
        {
            // std::cout << "IS COLLIDING" << std::endl;
        }
    }
}
