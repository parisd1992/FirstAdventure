//
//  CommandEngine.cpp
//  FirstAdventure
//
//  Created by David Paris on 26/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "CommandEngine.hpp"
#include "EntityChildren.hpp"

CommandEngine::CommandMap* CommandEngine::generateCommands(Entity &entity)
{
    commandMap_.clear();
    
    Entity* parent = entity.getParentEntity();
    
    if (parent)
    {
        EntityChildren* children = parent->getChildren();
                
        for(int i = 0; i < children->numberOfChildren(); i++)
        {
            if(children->getChild(i) != &entity)
            {
                commandMap_.emplace(to_string(i+1), children->getChild(i)->getCommand());
            }
        }
    }
    
    return &commandMap_;
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
        notifier.notify(Notifier::Message(Notifier::MessageType::TEXT, "You do nothing..."));
    }
    
    commandMap_.clear();
}



