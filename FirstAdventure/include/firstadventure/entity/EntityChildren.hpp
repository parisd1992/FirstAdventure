//
//  EntityChildren.hpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef EntityChildren_hpp
#define EntityChildren_hpp

#include <stdio.h>
#include <vector>
#include "EntityChildNode.hpp"

class Entity;


class EntityChildren
{
private:
    std::vector<EntityChildNode*> childNodes_;
    
public:
    EntityChildren()
    {
    }
    
    ~EntityChildren();
    
    size_t numberOfChildren()
    {
        return childNodes_.size();
    }
    
    Entity* getChild(int index);
    
    void addChild(Entity* entity);
    void addChild(Entity* entity, int index);
    
    /*
     This adds a child node with 2 layers.  Child 1 is the top layer
     and will appear first.  Child 2 is the top layer and will take the place
     of Child 1 if Child 1 is removed using any of the removeChild() methods
     */
    void addMultiLayeredChild(Entity* child1, Entity* child2);
    
    void removeChild(Entity* entity);
    void removeChild(int index);
};


#endif /* EntityChildren_hpp */
