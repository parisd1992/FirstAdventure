//
//  QuitGameState.cpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "QuitGameState.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;

void QuitGameState::runGame(Game& game)
{
    cout << "You have choosen to quit!" << endl;
    isOver_ = true;
}

void QuitGameState::handleMessage(Game& game, Notifier::Message message)
{
}
