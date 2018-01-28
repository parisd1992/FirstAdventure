//
//  NotificationEngine.cpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "NotificationEngine.hpp"

void NotificationEngine::notify(Notifier::Message message)
{
    for(auto iter = notifiers_.begin() ; iter != notifiers_.end() ; iter++)
    {
        if(*iter)
        {
            (*iter)->onNotify(message);
        }
    }
}

void NotificationEngine::addNotifier(Notifier *notifier)
{
    notifiers_.emplace_back(notifier);
}

void NotificationEngine::removeNotifier(Notifier *notifier)
{
    for(auto iter = notifiers_.begin() ; iter != notifiers_.end() ; iter++)
    {
        if (*iter)
        {
            if((*iter) == notifier)
            {
                notifiers_.erase(iter);
                break;
            }
        }
    }
}
