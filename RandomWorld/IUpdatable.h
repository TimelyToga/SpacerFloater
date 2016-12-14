//
//  IUpdatable.h
//  RandomWorld
//
//  Created by Timothy Blumberg on 14/12/16.
//  Copyright © 2016 Timothy Blumberg. All rights reserved.
//

#ifndef IUpdatable_h
#define IUpdatable_h

class IUpdatable
{
public:
    virtual void update(float delta) = 0;
};

#endif /* IUpdatable_h */
