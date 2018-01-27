//
//  OpenCommand.hpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef OpenCommand_hpp
#define OpenCommand_hpp

#include <stdio.h>

#include "Command.hpp"

class OpenCommand : public Command
{
private:
    string verb_;
    Entity* item_;
    bool isOpen_{false};
    
public:
    OpenCommand(Entity* item, string verb) : item_{item}, verb_{verb}
    {
        
    }
    
    virtual string getVerb();
    virtual void execute(Entity& entity, Notifier& notifier);
};

#endif /* OpenCommand_hpp */
