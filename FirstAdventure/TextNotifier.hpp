//
//  TextNotifier.hpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef TextNotifier_hpp
#define TextNotifier_hpp

#include <stdio.h>
#include "Notifier.hpp"

class TextNotifier : public Notifier
{
public:
    ~TextNotifier()
    {
        
    }
    
    void notify(Message message);
};

#endif /* TextNotifier_hpp */
