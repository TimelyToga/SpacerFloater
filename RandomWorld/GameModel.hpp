//
//  GameModel.hpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 15/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#ifndef GameModel_hpp
#define GameModel_hpp

#include <stdio.h>
#include <random>

class GameModel
{
public:
    GameModel();
    
    void setCurFPS(int fps);
    int getCurFPS();
    void setZoom(float zoom);
    float getZoom();
    std::mt19937* getRandGenerator();
    //    void addHUDElement(HUDElement)
private:
    int curFPS = 0;
    float zoom = 0.0f;
    std::mt19937* rgen;
};

#endif /* GameModel_hpp */
