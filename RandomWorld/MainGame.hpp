//
//  MainGame.hpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 09/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#ifndef MainGame_hpp
#define MainGame_hpp

#include <stdio.h>
#include <random>
#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "AsteroidField.hpp"
#include "ActorManager.hpp"
#include "CollisionManager.hpp"
#include "HUD.hpp"
#include "GameModel.hpp"
#include "Asteroid.hpp"

class MainGame
{
    float cameraClenching = 0.04;
    float xOffset = 0, yOffset = 0;
    int X_SCREEN_SIZE, Y_SCREEN_SIZE;
    sf::RenderWindow window;
    Player player;
    AsteroidField aField;
    CollisionManager cManager;
    ActorManager aManager;
    GameModel model;
    HUD hud;
    
public:
    void init();
    void run();
    MainGame(sf::ContextSettings settings, int x = sf::VideoMode::getDesktopMode().width, int y = sf::VideoMode::getDesktopMode().height);
private:
    int updates;
    
    void render();
    void simulate(float delta);
    void processWindowEvents();
};

#endif /* MainGame_hpp */
