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

void TextNotifier::notify(Message message)
{
    switch(message.type)
    {
        case(Notifier::MessageType::WIN):
        {
            //we won!
            cout << message.message << endl;
            break;
        }
        case(Notifier::MessageType::LOOSE):
        {
            //we lost!
            cout << message.message << endl;
            break;
        }
        case(Notifier::MessageType::TEXT):
        {
            cout << message.message << endl;
            break;
        }
        default:
        {
            cout << message.message << endl;
        }
    }
}
