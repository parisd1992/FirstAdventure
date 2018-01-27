//
//  Entity.hpp
//  FirstAdventure
//
//  Created by David Paris on 25/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <string>

class Command;

//Entity class is the main game object.
//It holds a number of components.
class Entity
{
public:
    static const int MAX_CHILDREN = 4;

private:
    std::string description_;
    Command* command_;
    Entity* parent_;
    Entity* children_[MAX_CHILDREN] = { nullptr, nullptr, nullptr, nullptr };
    
    int children{0};
    
public:
    Entity(std::string description, Command* command, Entity* parent)
        : description_{description}, command_{command}, parent_{parent}
    {
    }
    
    std::string getDescription()
    {
        return description_;
    }
    
    Command* getCommand()
    {
        return command_;
    }
    
    void setParentEntity(Entity* newParent)
    {
        parent_ = newParent;
    }
    
    Entity* getParentEntity()
    {
        return parent_;
    }
    
    void addChild(Entity* child)
    {
        children_[children++ % MAX_CHILDREN] = child;
    }
    
    Entity* getChildren(int i)
    {
        return children_[i];
    }
};

#endif /* Entity_hpp */
