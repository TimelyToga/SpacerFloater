
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

#include "MainGame.hpp"
#include "Player.hpp"
#include "math.h"
#include <iostream>

#define DEBUG true

int main(int, char const**)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    MainGame game(settings, 1000.0, 700.0);
    game.run();

    return EXIT_SUCCESS;
}
