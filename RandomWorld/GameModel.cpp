//
//  GameModel.cpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 15/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#include "GameModel.hpp"

GameModel::GameModel()
{
    std::random_device rd;
    this->rgen = new std::mt19937(rd());
}

void GameModel::setCurFPS(int fps)
{
    this->curFPS = fps;
}

int GameModel::getCurFPS()
{
    return curFPS;
}

void GameModel::setZoom(float zoom)
{
    this->zoom = zoom;
}

float GameModel::getZoom()
{
    return zoom;
}

std::mt19937* GameModel::getRandGenerator()
{
    return rgen;
}
