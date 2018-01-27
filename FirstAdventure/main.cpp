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

#include "Entity.hpp"
#include "ExitCommand.hpp"
#include "OpenCommand.hpp"
#include "TextGraphicsEngine.hpp"
#include "CommandEngine.hpp"
#include "TextNotifier.hpp"

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
    unique_ptr<TextGraphicsEngine> graphicsEngine = make_unique<TextGraphicsEngine>();
    unique_ptr<CommandEngine> commandEngine = make_unique<CommandEngine>();
    
    TextNotifier textNotifier;
    
    //Rooms
    Entity room1("a dark, dusty room", nullptr, nullptr);
    Entity room2("a small room", nullptr, nullptr);
    
    //Room 1 Exit
    ExitCommand exitToR2{&room2, "Go North"};
    Entity r1ToR2("an exit to the north", &exitToR2, &room1);
    room1.addChild(&r1ToR2);
    
    //Room 2 Exit
    ExitCommand exitToR1{&room1, "Go South"};
    Entity r2ToR1("an exit to the south", &exitToR1, &room2);
    room2.addChild(&r2ToR1);
    
    //Room 2 Chest
    Entity doorKey("a key", nullptr, nullptr);
    OpenCommand openChest(&doorKey, "Open chest");
    Entity chest("a wooden chest", &openChest, &room2);
    room2.addChild(&chest);
    
    //Room 2 Locked Door
    //TODO
    
    Entity player("You", nullptr, &room1);
    
    while(true)
    {
        //TODO: this is rendering
        graphicsEngine->render(player);
        
        //TODO: this is handling input
        commandEngine->generateCommands(player, textNotifier);
        std::string input;
        cin >> input;
        commandEngine->executeCommand(player, textNotifier, input);
        
        //TODO: this is updating the game
       
        
        cout << endl << endl;
    }
    
    
    
    
    
    return 0;
}
