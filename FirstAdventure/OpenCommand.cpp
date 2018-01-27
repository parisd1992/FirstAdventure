//
//  OpenCommand.cpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "OpenCommand.hpp"
#include "EntityChildren.hpp"

string OpenCommand::getVerb()
{
    return verb_;
}

void OpenCommand::execute(Entity &entity, Notifier &notifier)
{
    if(!isOpen_)
    {
        if(item_)
        {
            entity.getChildren()->addChild(item_);
            notifier.notify(Notifier::Message(Notifier::MessageType::TEXT,
                                              entity.getDescription() + " obtain " + item_->getDescription()));
        }
        else
        {
            notifier.notify(Notifier::Message(Notifier::MessageType::TEXT, "It's empty!"));
        }
        
        isOpen_ = true;
    }
    else
    {
        notifier.notify(Notifier::Message(Notifier::MessageType::TEXT, "It's already open..."));
    }
    
    //TODO - how do we remove this chest ?
}
