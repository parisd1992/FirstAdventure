//
//  AttackCommand.cpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include <cstdlib>
#include "AttackCommand.hpp"
#include "Stats.hpp"
#include "EntityChildren.hpp"

string AttackCommand::getVerb()
{
    return verb_;
}

void AttackCommand::execute(Entity &entity, NotificationEngine &notifier)
{
    int attackerStrength = getStrength(entity);
    int attackerHealth = getHealth(entity);
    int defenderStrength = getHealth(*defender_);
    
    int damage = attackerStrength + (rand() % attackerHealth) - (rand() % defenderStrength);
    
    if (damage < 0)
        damage = 0;
    
    defender_->getStats()->setHealth(defender_->getStats()->getHealth() - damage);
    notifier.notify(Notifier::Message(Notifier::MessageType::TEXT, to_string(damage) + " damage!"));
    
    if(getHealth(*defender_) <= 0)
    {
        notifier.notify(Notifier::Message(Notifier::MessageType::TEXT, defender_->getDescription() + " is dead!"));
        defender_->getParentEntity()->getChildren()->removeChild(defender_);
        defender_->setParentEntity(nullptr);
    }
}

int AttackCommand::getStrength(Entity &entity)
{
    int strength = 0;
    
    if(entity.getStats())
    {
        strength += entity.getStats()->getStrength();
    }
    
    EntityChildren* children = entity.getChildren();
    
    if (children)
    {
        for(int i = 0; i < children->numberOfChildren(); i++)
        {
            if(children->getChild(i)->getStats())
            {
                strength += children->getChild(i)->getStats()->getStrength();
            }
        }
    }
    
    return strength;
}

int AttackCommand::getHealth(Entity &entity)
{
    int health = 0;
    
    if(entity.getStats())
    {
        health += entity.getStats()->getHealth();
    }
    
    EntityChildren* children = entity.getChildren();
    
    if (children)
    {
        for(int i = 0; i < children->numberOfChildren(); i++)
        {
            if(children->getChild(i)->getStats())
            {
                health += children->getChild(i)->getStats()->getHealth();
            }
        }
    }
    
    
    return health;
}


