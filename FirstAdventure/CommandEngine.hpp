//
//  CommandEngine.hpp
//  FirstAdventure
//
//  Created by David Paris on 26/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef CommandEngine_hpp
#define CommandEngine_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

#include "Entity.hpp"
#include "Notifier.hpp"
#include "Command.hpp"

using namespace std;

class CommandEngine
{
public:
    using CommandID = string;
    using CommandMap = unordered_map<CommandID, Command*>;

private:
    CommandMap commandMap_;
    
    
public:
    ~CommandEngine()
    {
        
    }
    
    CommandMap* generateCommands(Entity& entity);
    void executeCommand(Entity& entity, Notifier& notifier, CommandID ID);
};

#endif /* CommandEngine_hpp */
