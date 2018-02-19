//
//  ExitCommand.hpp
//  FirstAdventure
//
//  Created by David Paris on 25/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef ExitCommand_hpp
#define ExitCommand_hpp

#include <stdio.h>

#include "Command.hpp"

/**
  Implementation of Command that changes an entities parent.  Used to simulate 'exiting' a room.
 **/
class ExitCommand : public Command
{
private:
    string verb_;
    Entity* exitTo_;
    
public:
    ExitCommand(Entity* exitTo, string verb) : exitTo_{exitTo}, verb_{verb}
    {
        
    }
    
    virtual string getVerb();
    virtual void execute(Entity& entity, NotificationEngine& notifier);
};

#endif /* ExitCommand_hpp */
