//
//  ReadyGameState.hpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef ReadyGameState_hpp
#define ReadyGameState_hpp

#include <stdio.h>
#include "GameState.hpp"

class ReadyGameState : public GameState
{
public:
    virtual ~ReadyGameState() {}
    
    void handleMessage(Game& game, Notifier::Message message);
    void runGame(Game& game);
};

#endif /* ReadyGameState_hpp */
