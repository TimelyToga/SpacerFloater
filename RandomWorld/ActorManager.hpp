//
//  ActorManager.hpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 13/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#include "Actor.hpp"
#include <vector>

#ifndef ActorManager_hpp
#define ActorManager_hpp

class ActorManager
{
public:
    ActorManager();
    void render(sf::RenderWindow *window, float xOffset, float yOffset);
    void addActor(Actor* a);
private:
    std::vector<Actor*> actors;
};

#include <stdio.h>

#endif /* ActorManager_hpp */
