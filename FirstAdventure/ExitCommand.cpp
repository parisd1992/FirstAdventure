//
//  ExitCommand.cpp
//  FirstAdventure
//
//  Created by David Paris on 25/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "ExitCommand.hpp"
#include "EntityChildren.hpp"


string ExitCommand::getVerb()
{
    return verb_;
}

void ExitCommand::execute(Entity& entity, Notifier& notifier)
{
    Entity* parent = entity.getParentEntity();
    parent->getChildren()->removeChild(&entity);
    
    entity.setParentEntity(exitTo_);
    
    exitTo_->getChildren()->addChild(&entity);
    
    notifier.notify(Notifier::Message(Notifier::MessageType::TEXT, entity.getDescription() + " " + getVerb()));
}
