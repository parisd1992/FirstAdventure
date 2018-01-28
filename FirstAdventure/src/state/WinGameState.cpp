//
//  WinGameState.cpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "WinGameState.hpp"
#include "ReadyGameState.hpp"
#include "QuitGameState.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;

ReadyGameState GameState::readyGameState_;
QuitGameState GameState::quitGameState_;

void WinGameState::runGame(Game& game)
{
    
    cout << "Congratlulations! You Have escaped the Dungeon" << endl;
    cout << endl;
    cout << "Type any key to start again..." << endl;
    cout << "Type exit to quit..." << endl;
    
    string input;
    cin >> input;
    
    if(input.compare("exit") == 0)
    {
        game.getNotificationEngine()->notify(Notifier::Message(Notifier::MessageType::QUIT, input));
    }
    else
    {
        game.getNotificationEngine()->notify(Notifier::Message(Notifier::MessageType::START, input));
    }
}

void WinGameState::handleMessage(Game& game, Notifier::Message message)
{
    if (Notifier::MessageType::START == message.type)
    {
        game.reset();
        game.setState(&GameState::readyGameState_);
    }
    
    if (Notifier::MessageType::QUIT == message.type)
    {
        game.setState(&GameState::quitGameState_);
    }
}
