//
//  ControllableEntity.hpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef ControllableEntity_hpp
#define ControllableEntity_hpp

#include <stdio.h>
#include "Entity.hpp"
#include "ControlEngine.hpp"

/*
Wraps an Entity with a ControlEngine for controlling.  Another example of the Component Pattern.
*/
class ControllableEntity
{
private:
    Entity* entity_;
    ControlEngine* controlEngine_;
    
public:
    ControllableEntity(Entity* entity, ControlEngine* controlEngine)
    : entity_{entity}, controlEngine_{controlEngine}
    {}
    
    Entity* getEntity();
    void control();
    
};

#endif /* ControllableEntity_hpp */
