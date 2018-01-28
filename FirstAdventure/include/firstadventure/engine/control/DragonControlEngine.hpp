//
//  DragonControlEngine.hpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef DragonControlEngine_hpp
#define DragonControlEngine_hpp

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <iostream>

#include "ControlEngine.hpp"
#include "NotificationEngine.hpp"
#include "Command.hpp"

using namespace std;

class DragonControlEngine : public ControlEngine
{   
private:
    using CommandID = string;
    using CommandMap = unordered_map<CommandID, Command*>;
    
    CommandMap commandMap_;
    NotificationEngine* notifier_;
    
    void generateCommands(Entity& entity);
    void chooseCommand(Entity& entity);
    void executeCommand(Entity& entity, CommandID ID);
    
public:
    DragonControlEngine(NotificationEngine* notifier) : notifier_{notifier} {}
    ~DragonControlEngine() {}
    
    void control(Entity& entity);
};

#endif /* DragonControlEngine_hpp */
