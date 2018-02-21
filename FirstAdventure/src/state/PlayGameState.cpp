//
//  PlayGameState.cpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "GameState.hpp"
#include "PlayGameState.hpp"
#include "WinGameState.hpp"
#include "LooseGameState.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;

WinGameState GameState::winGameState_;
LooseGameState GameState::looseGameState_;

/**
 Plays the game.  This is the game loop.
 **/
void PlayGameState::runGame(Game& game)
{
    //render any renderable entities
    for(auto iter = game.renderableEntities_.begin() ; iter != game.renderableEntities_.end() ; iter++ )
    {
        (*iter)->render();
    }
    
    //control any controllable entities
    for(auto iter = game.controllableEntities_.begin() ; iter !=  game.controllableEntities_.end() ; iter++ )
    {
        //TODO there are no checks to see if an entity is still alive (i.e. controllable).
        (*iter)->control();
    }
}

void PlayGameState::handleMessage(Game& game, Notifier::Message message)
{
    if (Notifier::MessageType::WIN == message.type)
    {
        game.setState(&GameState::winGameState_);
    }
    
    if (Notifier::MessageType::LOOSE == message.type)
    {
        game.setState(&GameState::looseGameState_);
    }
}
