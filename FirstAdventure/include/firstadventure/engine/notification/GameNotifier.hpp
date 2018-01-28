//
//  GameNotifier.hpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef GameNotifier_hpp
#define GameNotifier_hpp

#include <stdio.h>
#include "Notifier.hpp"
#include "Game.hpp"

class GameNotifier : public Notifier
{
private:
    Game* game_;
    
public:
    GameNotifier(Game* game) : game_{game}
    {
    }
    
    ~GameNotifier()
    {
    }
    
    void onNotify(Message message);
};

#endif /* GameNotifier_hpp */
