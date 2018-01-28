//
//  NotificationEngine.hpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef NotificationEngine_hpp
#define NotificationEngine_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "Notifier.hpp"

class NotificationEngine
{
private:
    std::vector<Notifier*> notifiers_;
    
    
public:
    NotificationEngine()
    {
        
    }
    
    virtual ~NotificationEngine()
    {
        
    }
    
    void notify(Notifier::Message message);
    
    void addNotifier(Notifier* notifier);
    void removeNotifier(Notifier* notifier);

};

#endif /* NotificationEngine_hpp */
