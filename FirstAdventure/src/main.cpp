//
//  main.cpp
//  FirstAdventure
//
//  Created by David Paris on 22/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//


#include <iostream>
#include <string>
#include <memory>

#include "NotificationEngine.hpp"
#include "Game.hpp"
#include "ReadyGameState.hpp"

using namespace std;


/*
 *
 *  Game Description:
 *
 *  You find yourself in a dungeon.  You must search for a key to escape, then battle a Dragon before you are free.
 *  Along the way you might pick up a sword and a shield.  If you do, it will make the battle with the dragon easier.
 *
 */
int main(int argc, const char * argv[]) {
    
    Game* game = new Game(&GameState::readyGameState_);
    game->runGame();
    
    delete game;

    return 0;
}
