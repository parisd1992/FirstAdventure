//
//  QuitGameState.hpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef QuitGameState_hpp
#define QuitGameState_hpp

#include <stdio.h>
#include "GameState.hpp"

class QuitGameState : public GameState
{
public:
    virtual ~QuitGameState() {}
    
    void handleMessage(Game& game, Notifier::Message message);
    void runGame(Game& game);
};


#endif /* QuitGameState_hpp */
