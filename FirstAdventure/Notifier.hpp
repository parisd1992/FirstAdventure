//
//  Notifier.hpp
//  FirstAdventure
//
//  Created by David Paris on 26/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef Notifier_hpp
#define Notifier_hpp

#include <stdio.h>
#include <string>

class Notifier
{
public:
    enum class MessageType
    {
        TEXT = 0,
        WIN,
        LOOSE
    };
    
    struct Message
    {
        Message(MessageType type, std::string message) : type(type), message(message)
        {}
        
        MessageType type;
        std::string message;
    };
    
public:
    ~Notifier()
    {
        
    }
    
    virtual void notify(Message message) = 0;
};

#endif /* Notifier_hpp */
