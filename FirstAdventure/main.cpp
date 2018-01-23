//
//  main.cpp
//  FirstAdventure
//
//  Created by David Paris on 22/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//


#include <iostream>
#include <string>
#include "Player.hpp"
#include "Exit.hpp"
#include "Room.hpp"

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
    
    //set up
    Room room1("Room1");
    Room room2("Room2");
    
    Exit r1ToR2(&room2, "North");
    Exit r2ToR1(&room1, "South");
    
    room1.setExit(&r1ToR2);
    room2.setExit(&r2ToR1);
    
    Player player(&room1);
    
    while(true)
    {
        //TODO: this is rendering
        cout << "You are in " << player.getRoom()->getDescription() << endl;
        cout << "There is an exit to the " << player.getRoom()->getExit()->getDirection() << endl;
        cout << "Where will you go?" << endl;
        
        //TODO: this is handling input
        std::string direction;
        cin >> direction;
        
        //TODO: this is updating the game
        if (direction.compare(player.getRoom()->getExit()->getDirection()) == 0)
        {
            player.setRoom(player.getRoom()->getExit()->getExitRoom());
        }
        else
        {
            cout << "I don't know what to do..." << endl;
        }
        
        cout << endl << endl;
    }
    
    
    
    
    
    return 0;
}
