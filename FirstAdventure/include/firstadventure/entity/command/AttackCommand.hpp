//
//  AttackCommand.hpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef AttackCommand_hpp
#define AttackCommand_hpp

#include <stdio.h>
#include "Command.hpp"

class AttackCommand : public Command
{
private:
    string verb_;
    Entity* defender_;
    
    bool isDefenderDead_{false};
    
    int getStrength(Entity& entity);
    int getHealth(Entity& entity);
    
public:
    AttackCommand(string verb) : verb_{verb}
    {
        
    }
    
    void setDefender(Entity* entity)
    {
        defender_ = entity;
    }
    
    virtual string getVerb();
    virtual void execute(Entity& entity, NotificationEngine& notifier);
};

#endif /* AttackCommand_hpp */
