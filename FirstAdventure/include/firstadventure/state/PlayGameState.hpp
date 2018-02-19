//
//  PlayGameState.hpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef PlayGameState_hpp
#define PlayGameState_hpp

#include <stdio.h>
#include "GameState.hpp"

/**
 State when the game is being played
 **/
class PlayGameState : public GameState
{
public:
    virtual ~PlayGameState() {}
    
    void handleMessage(Game& game, Notifier::Message message);
    void runGame(Game& game);
};

#endif /* PlayGameState_hpp */
