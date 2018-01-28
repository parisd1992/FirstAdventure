//
//  LooseGameState.hpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef LooseGameState_hpp
#define LooseGameState_hpp

#include <stdio.h>
#include "GameState.hpp"

class LooseGameState : public GameState
{
public:
    ~LooseGameState() {}
    
    void handleMessage(Game& game, Notifier::Message message);
    void runGame(Game& game);
};

#endif /* LooseGameState_hpp */
