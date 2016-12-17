//
//  IRenderable.h
//  RandomWorld
//
//  Created by Timothy Blumberg on 15/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#ifndef IRenderable_h
#define IRenderable_h

class IRenderable
{
public:
    virtual void render(sf::RenderWindow *window, float xOffset, float yOffset) = 0;
};

#endif /* IRenderable_h */
