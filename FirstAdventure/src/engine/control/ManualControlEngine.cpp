//
//  ManualControlEngine.cpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "ManualControlEngine.hpp"
#include "EntityChildren.hpp"

void ManualControlEngine::generateCommands(Entity& entity)
{
    commandMap_.clear();
    
    Entity* parent = entity.getParentEntity();
    
    if (parent)
    {
        EntityChildren* children = 
        
        for(int i = 0; i < children->numberOfChildren(); i++)
        {
            if(children->getChild(i) != &entity)
            {
                commandMap_.emplace(to_string(i+1), children->getChild(i)->getCommand());
            }
        }
    }
}

void ManualControlEngine::chooseCommand(Entity& entity)
{
    if(commandMap_.size())
    {
        notifier_->notify(Notifier::Message(Notifier::MessageType::TEXT, "What will you do? (Type a corresponding number)"));
        
        for(auto iter = commandMap_.begin() ; iter != commandMap_.end() ; iter++)
        {
            notifier_->notify(Notifier::Message(Notifier::MessageType::TEXT,
                                                   iter->first + ": " + iter->second->getVerb()));
        }
        
        notifier_->notify(Notifier::Message(Notifier::MessageType::TEXT, ">>>"));
        
        string input;
        cin >> input;
        executeCommand(entity, input);
    }
    else
    {
        notifier_->notify(Notifier::Message(Notifier::MessageType::LOOSE, "You loose!"));
    }
}

void ManualControlEngine::executeCommand(Entity& entity, CommandID ID)
{
    auto commandIterator = commandMap_.find(ID);
    if (commandIterator != commandMap_.end())
    {
        commandIterator->second->execute(entity, *notifier_);
    }
    else
    {
        notifier_->notify(Notifier::Message(Notifier::MessageType::TEXT, "You do nothing..."));
    }
}


void ManualControlEngine::control(Entity &entity)
{
    generateCommands(entity);
    chooseCommand(entity);
}
