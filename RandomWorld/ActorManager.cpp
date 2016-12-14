//
//  ActorManager.cpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 13/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#include "ActorManager.hpp"
#include "Actor.hpp"
#include <list>
#include "utils.h"
ActorManager::ActorManager()
{
    
}

void ActorManager::render(sf::RenderWindow *window, float xOffset, float yOffset)
{
    for (int a = 0; a < actors.size(); a++)
    {
        actors[a]->render(window, xOffset, yOffset);
    }
}

void ActorManager::addActor(Actor* a)
{
    actors.push_back(a);
}
