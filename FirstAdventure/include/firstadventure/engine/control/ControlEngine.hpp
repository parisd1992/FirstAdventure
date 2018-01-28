//
//  ControlEngine.hpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef ControlEngine_hpp
#define ControlEngine_hpp

#include <stdio.h>
#include "Entity.hpp"

/*
 ControlEngine controls an entity.
 Different implementations allow the Strategy Pattern (https://en.wikipedia.org/wiki/Strategy_pattern)
 */

class ControlEngine
{
public:
    virtual ~ControlEngine() {}
    virtual void control(Entity& entity) = 0;
};

#endif /* ControlEngine_hpp */
