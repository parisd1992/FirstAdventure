//
//  ExitCommand.cpp
//  FirstAdventure
//
//  Created by David Paris on 25/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "ExitCommand.hpp"


string ExitCommand::getVerb()
{
    return verb_;
}

void ExitCommand::execute(Entity& entity, Notifier& notifier)
{
    entity.setParentEntity(exitTo_);
    notifier.notify(entity.getDescription() + " " + getVerb());
}
