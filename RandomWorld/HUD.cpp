//
//  HUD.cpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 15/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#include "HUD.hpp"


HUD::HUD(GameModel* model) :
    font(),
    fps()
{
    this->model = model;
    
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        throw "Fuck";
    }
    
    fps.setFont(font);
    fps.setPosition(10, 10);
    fps.setCharacterSize(charSize);
    fps.setFillColor(sf::Color::White);
}

void HUD::update(float delta)
{
    fps.setString(std::to_string(model->getCurFPS()) + BASE_FPS_STRING);
}

void HUD::render(sf::RenderWindow* window, float xOffset, float yOffset)
{
    // Update according to View
    float zoom = window->getView().getSize().x / window->getDefaultView().getSize().x;
    fps.setCharacterSize(zoom * charSize);
    window->draw(fps);
}
