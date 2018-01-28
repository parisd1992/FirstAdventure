//
//  ManualControlEngine.hpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef ManualControlEngine_hpp
#define ManualControlEngine_hpp

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <iostream>

#include "ControlEngine.hpp"
#include "NotificationEngine.hpp"
#include "Command.hpp"

using namespace std;

class ManualControlEngine : public ControlEngine
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
    ManualControlEngine(NotificationEngine* notifier) : notifier_{notifier} {}
    ~ManualControlEngine() {}
    
    void control(Entity& entity);
};

#endif /* ManualControlEngine_hpp */
