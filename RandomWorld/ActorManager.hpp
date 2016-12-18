//
//  ActorManager.hpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 13/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#include "Actor.hpp"
#include "IRenderable.h"
#include "IUpdatable.h"
#include <vector>

#ifndef ActorManager_hpp
#define ActorManager_hpp

class ActorManager : IUpdatable
{
public:
    ActorManager();
    void render(sf::RenderWindow *window, float xOffset, float yOffset);
    void update(float delta);
    void addActor(Actor* a);
    int numActors();
private:
    std::vector<Actor*> actors;
};

#include <stdio.h>

#endif /* ActorManager_hpp */
