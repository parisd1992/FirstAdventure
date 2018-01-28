//
//  GameState.hpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp

#include <stdio.h>
#include "NotificationEngine.hpp"
#include "GameState.hpp"

class Game;
class ReadyGameState;
class PlayGameState;
class WinGameState;
class LooseGameState;
class QuitGameState;

class GameState
{
public:
    static ReadyGameState readyGameState_;
    static PlayGameState playGameState_;
    static WinGameState winGameState_;
    static LooseGameState looseGameState_;
    static QuitGameState quitGameState_;
    
    bool isOver_{false};
    
    GameState()
    {
        
    }
    
    virtual ~GameState() {}
    
    virtual void handleMessage(Game& game, Notifier::Message message) {}
    virtual void runGame(Game& game) {}
};

#endif /* GameState_hpp */
