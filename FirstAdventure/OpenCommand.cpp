//
//  OpenCommand.cpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "OpenCommand.hpp"

string OpenCommand::getVerb()
{
    return verb_;
}

void OpenCommand::execute(Entity &entity, Notifier &notifier)
{
    if(!isOpen_)
    {
        entity.addChild(item_);
        notifier.notify(entity.getDescription() + " obtain " + item_->getDescription());
        
        isOpen_ = true;
    }
    else
    {
        notifier.notify("It's already open...");
    }
    
    //TODO - how do we remove this chest ?
}
