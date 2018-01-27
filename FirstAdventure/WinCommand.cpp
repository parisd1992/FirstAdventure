//
//  WinCommand.cpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "WinCommand.hpp"

string WinCommand::getVerb()
{
    return verb_;
}

void WinCommand::execute(Entity &entity, Notifier &notifier)
{    
    //send
    notifier.notify(Notifier::Message(Notifier::MessageType::WIN, "You win!"));
}
