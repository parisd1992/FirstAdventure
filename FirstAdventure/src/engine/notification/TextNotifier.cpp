//
//  TextNotifier.cpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include <iostream>
#include "TextNotifier.hpp"

using namespace std;

void TextNotifier::onNotify(Message message)
{
    switch(message.type)
    {
        case(Notifier::MessageType::WIN):
        case(Notifier::MessageType::LOOSE):
        case(Notifier::MessageType::START):
        case(Notifier::MessageType::TEXT):
        {
            textEntity_->setDescription(message.message);
            graphicsEngine_->render(*textEntity_);
            break;
        }
        default:
        {
            //do nothing
        }
    }
}
