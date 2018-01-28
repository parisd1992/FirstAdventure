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


/*
 An EntityChildNode has an Entity and a link to another EntityChildNode
 This allows you to set up multi layered (FIFO) EntityChildren
 
 For e.g. if you have a dragon defending an exit you can set up a room
 with a multilayered child node containing a dragon and the exit.
 
 If the dragon is killed and removed, the exit will automatically become
 the child node
 */
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
    
    ~EntityChildNode();
    
    void appendChild(Entity* entity);
    
    /*
     Returns the Entity at the top of the node
     */
    Entity* peakChild();
    
    /*
     Removes the Entity at the top of the node and makes
     the next linked Entity (if any) the new top.
     It returns the new Entity at the top of the node.
     */
    Entity* popChild();
};

#endif /* EntityChildNode_hpp */
