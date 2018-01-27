//
//  UnlockCommand.cpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "UnlockCommand.hpp"
#include "EntityChildren.hpp"

string UnlockCommand::getVerb()
{
    return verb_;
}

void UnlockCommand::execute(Entity &entity, Notifier &notifier)
{
    if (!isUnlocked_)
    {
        EntityChildren* children = entity.getChildren();
        
        int i = 0;
        
        while(children->getChild(i) != nullptr)
        {
            if (children->getChild(i) == unlockItem_)
            {
                isUnlocked_ = true;
                break;
            }
            
            i++;
        }
        
        if(isUnlocked_)
        {
            notifier.notify(Notifier::Message(Notifier::MessageType::TEXT, "It unlocks with " + unlockItem_->getDescription()));
            
            if(chainedCommand_)
            {
                chainedCommand_->execute(entity, notifier);
            }
        }
        else
        {
            notifier
            .notify(Notifier::Message(Notifier::MessageType::TEXT, "It needs " + unlockItem_->getDescription() + " to unlock"));
        }
    }
    else
    {
        notifier.notify(Notifier::Message(Notifier::MessageType::TEXT, "It's already unlocked..."));
        
        if(chainedCommand_)
        {
            chainedCommand_->execute(entity, notifier);
        }
    }
    
    
}
