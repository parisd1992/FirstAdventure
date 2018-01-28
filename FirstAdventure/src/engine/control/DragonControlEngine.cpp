//
//  DragonControlEngine.cpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "DragonControlEngine.hpp"
#include "EntityChildren.hpp"

void DragonControlEngine::generateCommands(Entity& entity)
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
}

void DragonControlEngine::chooseCommand(Entity& entity)
{
    for(auto iter = commandMap_.begin() ; iter != commandMap_.end() ; iter++)
    {
        if (iter->second->getVerb().find("Attack") != string::npos)
        {
            notifier_->notify(Notifier::Message(Notifier::MessageType::TEXT, "The Dragon ATTACKS!"));
            executeCommand(entity, iter->first);
            break;
        }
    }
}

void DragonControlEngine::executeCommand(Entity& entity, CommandID ID)
{
    auto commandIterator = commandMap_.find(ID);
    if (commandIterator != commandMap_.end())
    {
        commandIterator->second->execute(entity, *notifier_);
    }
}


void DragonControlEngine::control(Entity &entity)
{
    generateCommands(entity);
    chooseCommand(entity);
}
