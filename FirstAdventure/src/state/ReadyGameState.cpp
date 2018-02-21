//
//  ReadyGameState.cpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "GameState.hpp"
#include "ReadyGameState.hpp"
#include "PlayGameState.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;

PlayGameState GameState::playGameState_;

/**
 Loads the game and gets it ready for play
 **/
void ReadyGameState::runGame(Game& game)
{
    
    cout << " _______ _________ _______  _______ _________   _______  ______            _______  _       _________          _______  _______  " << endl;
    cout << "(  ____ \\__   __/(  ____ )(  ____ \\__   __/  (  ___  )(  __  \\ |\\     /|(  ____ \( (    /|\\__   __/|\\     /|(  ____ )(  ____ \\ " << endl;
    cout << "| (    \\/   ) (   | (    )|| (    \\/   ) (     | (   ) || (  \\  )| )   ( || (    \\/|  \\  ( |   ) (   | )   ( || (    )|| (    \\/ " << endl;
    cout << "| (__       | |   | (____)|| (_____    | |     | (___) || |   ) || |   | || (__    |   \\ | |   | |   | |   | || (____)|| (__     " << endl;
    cout << "|  __)      | |   |     __)(_____  )   | |     |  ___  || |   | |( (   ) )|  __)   | (\\ \\) |   | |   | |   | ||     __)|  __)    " << endl;
    cout << "| (         | |   | (\\ (         ) |   | |     | (   ) || |   ) | \\ \\_/ / | (      | | \\   |   | |   | |   | || (\\ (   | (       " << endl;
    cout << "| )      ___) (___| ) \\ \\__/\\____) |   | |     | )   ( || (__/  )  \\   /  | (____/\\| )  \\  |   | |   | (___) || ) \\ \\__| (____/\\ " << endl;
    cout << "|/       \\_______/|/   \\__/\\_______)   )_(     |/     \\|(______/    \\_/   (_______/|/    )_)   )_(   (_______)|/   \\__/(_______/ " << endl;
    cout << endl;
    
    //initialise the game here
    game.initialise();
    
    cout << "You find yourself in a dungeon, trapped.  The door ahead is shut, yet there must be way to open it."<< endl;
    cout << "The question is, do you want to?  Are you ready to face what might be waiting on the other side?"<< endl;
    cout << "Type any key to start" << endl;
    
    string input;
    cin >> input;
    
    game.getNotificationEngine()->notify(Notifier::Message(Notifier::MessageType::START, input));
}

void ReadyGameState::handleMessage(Game& game, Notifier::Message message)
{
    if (Notifier::MessageType::START == message.type)
    {
        game.setState(&GameState::playGameState_);
    }
}
