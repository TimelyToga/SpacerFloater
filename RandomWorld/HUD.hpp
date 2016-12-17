//
//  HUD.hpp
//  RandomWorld
//
//  Created by Timothy Blumberg on 15/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#ifndef HUD_hpp
#define HUD_hpp

#include <stdio.h>
#include "SFML/Graphics.hpp"
#include "IUpdatable.h"
#include "IRenderable.h"
#include "ResourcePath.hpp"
#include "GameModel.hpp"
#include <string>

class HUD : public IUpdatable, public IRenderable
{
    const std::string BASE_FPS_STRING = " FPS";
    
public:
    HUD(GameModel* model);
    void update(float delta);
    void render(sf::RenderWindow* window, float xOffset, float yOffset);
private:
    int fpsTextSize = 30;
    GameModel* model;
    sf::Text fps;
    sf::Font font;
};

#endif /* HUD_hpp */
