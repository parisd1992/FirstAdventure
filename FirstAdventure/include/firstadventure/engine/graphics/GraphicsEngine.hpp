//
//  GraphicsEngine.hpp
//  FirstAdventure
//
//  Created by David Paris on 26/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef GraphicsEngine_hpp
#define GraphicsEngine_hpp

#include <stdio.h>
#include "Entity.hpp"

/*
 Interface that renders an Entity to the screen
 */
class GraphicsEngine
{
public:
    virtual ~GraphicsEngine()
    {
        
    }
    
    virtual void render(Entity& entity) = 0;
};

#endif /* GraphicsEngine_hpp */
