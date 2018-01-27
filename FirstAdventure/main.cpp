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
#include "UnlockCommand.hpp"
#include "AttackCommand.hpp"
#include "EntityChildren.hpp"
#include "WinCommand.hpp"

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
    
    TextNotifier storyNotifier;
    
    //Rooms
    EntityChildren room1Children;
    EntityChildren room2Children;
    EntityChildren room3Children;
    
    Entity room1("a dark, dusty room", nullptr, nullptr, nullptr, &room1Children);
    Entity room2("a small room", nullptr, nullptr, nullptr, &room2Children);
    Entity room3("a big room", nullptr, nullptr, nullptr, &room3Children);
    
    //Room 1 Exit
    ExitCommand exitToR2{&room2, "Go North"};
    Entity r1ToR2("an exit to the north", nullptr, &exitToR2, &room1, nullptr);
    room1Children.addChild(&r1ToR2);
    
    //Room 2 Exit
    ExitCommand exitToR1{&room1, "Go South"};
    Entity r2ToR1("an exit to the south", nullptr, &exitToR1, &room2, nullptr);
    room2Children.addChild(&r2ToR1);
    
    //Room 2 Chest
    Entity doorKey("a key", nullptr, nullptr, nullptr, nullptr);
    OpenCommand openChest(&doorKey, "Open chest");
    Entity chest("a wooden chest", nullptr, &openChest, &room2, nullptr);
    room2Children.addChild(&chest);
    
    //Room 2 Locked Door
    ExitCommand exitToR3{&room3, "Go North"};
    UnlockCommand unlockDoor(&doorKey, &exitToR3, "Unlock door");
    Entity lockedDoor("a locked door", nullptr, &unlockDoor, &room2, nullptr);
    room2Children.addChild(&lockedDoor);
    
    //Room 3 exit
    ExitCommand r3ExitToR2{&room2, "Go South"};
    Entity r3ToR2("an exit to the south", nullptr, &r3ExitToR2, &room3, nullptr);
    room3Children.addChild(&r3ToR2);
    
    //Room 3 dragon
    Stats dragonStats(1,1);
    AttackCommand dragonAttack("Attack Dragon");
    Entity dragon("a hungry dragon", &dragonStats, &dragonAttack, &room3, nullptr);
    dragonAttack.setDefender(&dragon);
    
    WinCommand winCommand("Exit");
    Entity winningDoor("an exit", nullptr, &winCommand, &room3, nullptr);
    room3Children.addMultiLayeredChild(&dragon, &winningDoor);
    
    Stats playerStats(100,100);
    EntityChildren playerInventory;
    AttackCommand playerAttack("Attack Player");
    Entity player("You", &playerStats, &playerAttack, &room1, &playerInventory);
    playerAttack.setDefender(&player);
    room1Children.addChild(&player);
    
    while(true)
    {
        //TODO: this is rendering
        graphicsEngine->render(player);
        
        //TODO: this is handling player input
        CommandEngine::CommandMap* playerCommandMap = commandEngine->generateCommands(player);
        
        if(playerCommandMap->size())
        {
            storyNotifier.notify(Notifier::Message(Notifier::MessageType::TEXT, "What will you do? (Type a corresponding number)"));
            
            for(auto iter = playerCommandMap->begin() ; iter != playerCommandMap->end() ; iter++)
            {
                storyNotifier.notify(Notifier::Message(Notifier::MessageType::TEXT,
                                                       iter->first + ": " + iter->second->getVerb()));
            }
            
            storyNotifier.notify(Notifier::Message(Notifier::MessageType::TEXT, ">>>"));
            
            std::string input;
            cin >> input;
            commandEngine->executeCommand(player, storyNotifier, input);
        }
        else
        {
            storyNotifier.notify(Notifier::Message(Notifier::MessageType::LOOSE, "You loose!"));
        }
        
        //TODO: this is handling AI input
        CommandEngine::CommandMap* dragonCommandMap = commandEngine->generateCommands(dragon);
        
        for(auto iter = dragonCommandMap->begin() ; iter != dragonCommandMap->end() ; iter++)
        {
            if (iter->second->getVerb().find("Attack") != string::npos)
            {
                storyNotifier.notify(Notifier::Message(Notifier::MessageType::TEXT, "The Dragon ATTACKS!"));
                commandEngine->executeCommand(dragon, storyNotifier, iter->first);
                break;
            }
        }
        
        cout << endl << endl;
    }
    
    
    
    
    
    return 0;
}
