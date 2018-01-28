//
//  UnlockCommand.hpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef UnlockCommand_hpp
#define UnlockCommand_hpp

#include <stdio.h>
#include "Command.hpp"

class UnlockCommand : public Command
{
private:
    string verb_;
    Entity* unlockItem_;
    Command* chainedCommand_;
    
    bool isUnlocked_{false};
    
public:
    UnlockCommand(Entity* unlockItem, Command* chainedCommand, string verb) :
            unlockItem_{unlockItem}, chainedCommand_{chainedCommand}, verb_{verb}
    {
        
    }
    
    virtual string getVerb();
    virtual void execute(Entity& entity, NotificationEngine& notifier);
};

#endif /* UnlockCommand_hpp */
