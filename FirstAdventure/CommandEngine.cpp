//
//  CommandEngine.cpp
//  FirstAdventure
//
//  Created by David Paris on 26/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "CommandEngine.hpp"

void CommandEngine::generateCommands(Entity &entity, Notifier &notifier)
{
    Entity* parent = entity.getParentEntity();
    
    if (parent)
    {
        notifier.notify("What will you do? (Type a corresponding number)");
        
        for( int i = 0 ; i < Entity::MAX_CHILDREN ; i++)
        {
            Entity* child = parent->getChildren(i);
            
            if (child)
            {
                child->getCommand();
                commandMap_.emplace(to_string(i+1), child->getCommand());
                notifier.notify(to_string(i+1) + ": " + child->getCommand()->getVerb());
            }
        }
    }
}

void CommandEngine::executeCommand(Entity& entity, Notifier& notifier, CommandID ID)
{
    auto commandIterator = commandMap_.find(ID);
    if (commandIterator != commandMap_.end())
    {
        commandIterator->second->execute(entity, notifier);
    }
    else
    {
        notifier.notify("You do nothing...");
    }
    commandMap_.clear();
}



