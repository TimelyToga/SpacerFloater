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
    for (Actor* a : actors)
    {
        if(!a->getIsDead())
           {
               a->render(window, xOffset, yOffset);
           }
    }
}

void ActorManager::addActor(Actor* a)
{
    actors.push_back(a);
}

void ActorManager::update(float delta)
{
    for(Actor* a : actors)
    {
        if(!a->getIsDead())
        {
            a->update(delta);
        }
    }
}

int ActorManager::numActors()
{
    return (int) actors.size();
}
