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
#include "Stats.hpp"

class Command;
class EntityChildren;

//Entity class is the main game object.
//It holds a number of components.
class Entity
{
private:
    std::string description_;
    Stats* stats_;
    Command* command_;
    Entity* parent_;
    EntityChildren* children_;
        
public:
    Entity()
    {
        description_ = "";
        stats_ = nullptr;
        command_ = nullptr;
        parent_ = nullptr;
        children_ = nullptr;
    }
    
    Entity(std::string description) : description_{description}
    {
        stats_ = nullptr;
        command_ = nullptr;
        parent_ = nullptr;
        children_ = nullptr;
    }
    
    Entity(std::string description, Stats* stats, Command* command, Entity* parent, EntityChildren* children)
    : description_{description}, stats_{stats}, command_{command}, parent_{parent}, children_{children}
    {

    }
    
    ~Entity();
    
    std::string getDescription()
    {
        return description_;
    }
    
    void setDescription(std::string description)
    {
        description_ = description;
    }
    
    Command* getCommand()
    {
        return command_;
    }
    
    void setCommand(Command* command)
    {
        command_ = command;
    }
    
    void setParentEntity(Entity* newParent)
    {
        parent_ = newParent;
    }
    
    Entity* getParentEntity()
    {
        return parent_;
    }
    
    Stats* getStats()
    {
        return stats_;
    }
    
    void setStats(Stats* stats)
    {
        stats_ = stats;
    }

    EntityChildren* getChildren()
    {
        return children_;
    }
    
    void setChildren(EntityChildren* children)
    {
        children_ = children;
    }
};

#endif /* Entity_hpp */
