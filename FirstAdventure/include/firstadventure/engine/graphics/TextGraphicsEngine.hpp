//
//  TextGraphicsEngine.hpp
//  FirstAdventure
//
//  Created by David Paris on 26/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef TextGraphicsEngine_hpp
#define TextGraphicsEngine_hpp

#include <stdio.h>
#include "GraphicsEngine.hpp"

/*
 Renders Entities as ascii text to the console.
 */
class TextGraphicsEngine : public GraphicsEngine
{
public:
    ~TextGraphicsEngine()
    {
        
    }
    
    void render(Entity& entity);
    
};

#endif /* TextGraphicsEngine_hpp */
