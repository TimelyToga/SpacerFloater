    //
//  MainGame.cpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 09/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#include <chrono>
#include <iostream>

#include "MainGame.hpp"

MainGame::MainGame(sf::ContextSettings settings, int x, int y) :
    window(sf::VideoMode(x, y), "Space Miner", sf::Style::Default, settings),
    player(0, 0),
    aField(x, y),
    aManager(),
    cManager(&player),
    model(),
    hud(&model)
{
    this->X_SCREEN_SIZE = x;
    this->Y_SCREEN_SIZE = y;
    
    // Initialize the window in the upper left corner of the screen
    window.setPosition(sf::Vector2i(0, 0));
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        throw new Exception;
    }
    
    sf::View gameView(sf::FloatRect(0, 0, x, y));
    gameView.zoom(2 );
    window.setView(gameView);
    
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    xOffset = -X_SCREEN_SIZE / 2;
    yOffset = -Y_SCREEN_SIZE / 2;
    
    // Create some asteroids
//    createSomeAsteroids(200);
    auto asteroid = new Asteroid(100, 100, 100);
    
    aManager.addActor(asteroid);
    cManager.addCollidable(asteroid);
    
    
    // Set up ActorManager
    aManager.addActor(&player);
    aManager.addActor(&aField);
    
    std::cout << "Hello" << std::endl;
}

void MainGame::init()
{
}

void MainGame::run()
{
    // Time measurement
    std::chrono::seconds oneSecond(1);
    auto mSecond = std::chrono::microseconds(oneSecond).count();
    
    auto prev_time = std::chrono::high_resolution_clock::now();
    auto cur_time = std::chrono::high_resolution_clock::now();
    
    while(window.isOpen())
    {
        processWindowEvents();
        
        // Main Game Loop
        simulate(0.1);
        render();
        
        {
            // Timing Actions
            using namespace std::chrono;
            
            cur_time = high_resolution_clock::now();
            auto difference = duration_cast<microseconds>(cur_time - prev_time);
            
            if(difference.count() > mSecond)
            {
                // TODO: Change UPS --> FPS
                model.setCurFPS(updates);
                
                // Reset for next loop
                prev_time = cur_time;
                updates = 0;
            }
        }
        
        updates++;
    }
}

// Update the game state
void MainGame::simulate(float delta)
{
    
    // Update all the things
    aManager.update(delta);
    cManager.update(delta);
    hud.update(delta);
    
    // Update camera
    sf::Vector2f distanceToPlayer = sf::Vector2f(xOffset - player.getPosition()->x
                                                + (X_SCREEN_SIZE / 2),
                                                 yOffset - player.getPosition()->y + (Y_SCREEN_SIZE / 2));
    
    auto cameraMovement = distanceToPlayer * cameraClenching;
    
    xOffset -= cameraMovement.x;
    yOffset -= cameraMovement.y;
    
//    printf("P(%f, %f); D(%f, %f); O(%f, %f)\n", player.getPosition().x, player.getPosition().y, distanceToPlayer.x, distanceToPlayer.y, xOffset, yOffset);
}

void MainGame::render()
{
    // Clear the window before everything
    window.clear();
    
    debugRendering();
    
    aManager.render(&window, xOffset, yOffset);
    hud.render(&window, xOffset, yOffset);
    
    // Show the window or something?
    window.display();
}

void MainGame::debugRendering()
{
    // Render Origin
    if(SHOW_ORIGIN)
    {
        sf::Transform t;
        t.translate(-xOffset, -yOffset);
        
        sf::RectangleShape vert(sf::Vector2f(60, 3));
        vert.setFillColor(sf::Color::White);
        vert.rotate(90);
        vert.setPosition(0, -30);
        window.draw(vert, t);
        
        sf::RectangleShape hor(sf::Vector2f(60, 3));
        hor.setFillColor(sf::Color::White);
        hor.setPosition(-30, 0);
        window.draw(hor, t);
    }
    
    if(SHOW_OFFSET)
    {
        // Render Offset
        sf::CircleShape offset(5);
        offset.setPosition(X_SCREEN_SIZE / 2, Y_SCREEN_SIZE / 2);
        offset.setFillColor(sf::Color::Yellow);
        window.draw(offset);
    }
}

void MainGame::processWindowEvents()
{
    // Process events
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        
        // Escape pressed: exit
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window.close();
        }
    }
}

void MainGame::createSomeAsteroids(int num)
{
    int spacing = 500;
    int defaultMargin = 200;
    int bounds = (sqrt(num) * (spacing + defaultMargin)) / 2;
    
    int maxPos = bounds, minPos = -maxPos;
    int minSize = 50, maxSize = 200;
    
    std::cout << "Position bounds: " << minPos << ", " << maxPos << std::endl;
    
    std::uniform_int_distribution<int> posDist(minPos, maxPos);
    std::uniform_int_distribution<int> sizeDist(minSize, maxSize);

    std::mt19937 rgen = *model.getRandGenerator();
    
    for(int a = 0; a < num; a++)
    {
        auto asteroid = new Asteroid(posDist(rgen),
                                     posDist(rgen),
                                     sizeDist(rgen));
        
        aManager.addActor(asteroid);
        cManager.addCollidable(asteroid);
    }
}
