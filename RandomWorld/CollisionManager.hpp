//
//  CollisionManager.hpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 14/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#ifndef CollisionManager_hpp
#define CollisionManager_hpp

#include <stdio.h>
#include <vector>

#include "ICollidable.h"
#include "Player.hpp"
#include "IUpdatable.h"

class CollisionManager : IUpdatable
{
public:
    CollisionManager(Player* p);
    void addCollidable(ICollidable* c);
    void update(float delta);
    
private:
    Player* player;
    std::vector<ICollidable*> collidables;
};

#endif /* CollisionManager_hpp */
