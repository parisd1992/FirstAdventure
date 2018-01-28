//
//  RenderableEntity.hpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef RenderableEntity_hpp
#define RenderableEntity_hpp

#include <stdio.h>
#include "Entity.hpp"
#include "GraphicsEngine.hpp"

/*
 Wraps an Entity with a GraphicsEngine for rendering.  Another example of the Component Pattern.
 */
class RenderableEntity
{
private:
    Entity* entity_;
    GraphicsEngine* graphicsEngine_;
    
public:
    RenderableEntity(Entity* entity, GraphicsEngine* graphicsEngine) : entity_{entity}, graphicsEngine_{graphicsEngine}
    {
        
    }
    
    void render();
};

#endif /* RenderableEntity_hpp */
