//
//  WinGameState.hpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef WinGameState_hpp
#define WinGameState_hpp

#include <stdio.h>
#include "GameState.hpp"

/**
 State when the game is won
 **/
class WinGameState : public GameState
{
public:
    ~WinGameState() {}
    
    void handleMessage(Game& game, Notifier::Message message);
    void runGame(Game& game);
};

#endif /* WinGameState_hpp */
