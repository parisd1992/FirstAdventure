//
//  EntityChildNode.hpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef EntityChildNode_hpp
#define EntityChildNode_hpp

#include <stdio.h>
#include "Entity.hpp"

class EntityChildNode
{
public:
    
private:
    Entity* child_{NULL};
    EntityChildNode* nextChild_{NULL};
    
public:
    EntityChildNode()
    {}
    
    EntityChildNode(Entity* child) : child_{child}
    {
    }
    
    void appendChild(Entity* entity);
    Entity* peakChild();
    Entity* popChild();
};

#endif /* EntityChildNode_hpp */
