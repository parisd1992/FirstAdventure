//
//  Command.hpp
//  FirstAdventure
//
//  Created by David Paris on 25/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp

#include <stdio.h>
#include <string>

#include "NotificationEngine.hpp"
#include "Entity.hpp"


using namespace std;

class Entity;

/*
 A command is an action which can be taken by the game Entities.
 Based on the Command pattern (http://www.gameprogrammingpatterns.com/command.html)
*/

class Command
{
public:
    virtual ~Command()
    {
        
    }
    
    virtual string getVerb() = 0;
    virtual void execute(Entity& entity, NotificationEngine& notifier) = 0;
};

#endif /* Command_hpp */
