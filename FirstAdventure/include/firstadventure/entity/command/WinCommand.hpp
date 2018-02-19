//
//  WinCommand.hpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef WinCommand_hpp
#define WinCommand_hpp

#include <stdio.h>
#include "Command.hpp"

/**
 Implementation of Command that wins the game
 **/
class WinCommand : public Command
{
private:
    string verb_;
    
public:
    WinCommand(string verb) : verb_{verb}
    {
        
    }
    
    virtual string getVerb();
    virtual void execute(Entity& entity, NotificationEngine& notifier);
};


#endif /* WinCommand_hpp */
