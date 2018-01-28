//
//  Game.cpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "Game.hpp"
#include "GameState.hpp"
#include "EntityChildren.hpp"
#include "ExitCommand.hpp"
#include "OpenCommand.hpp"
#include "UnlockCommand.hpp"
#include "WinCommand.hpp"
#include "AttackCommand.hpp"
#include "GameNotifier.hpp"
#include "TextNotifier.hpp"

void Game::runGame()
{
    while(!(state_->isOver_))
    {
        state_->runGame(*this);
    }
}

void Game::handleMessage(Notifier::Message message)
{
    state_->handleMessage(*this, message);
}

void Game::initialise()
{
    /******************
     * 1: Setup the notifiers if not already set up.  This is the Observer Pattern.
     ******************/
    
    if (!gameNotifier_)
    {
        gameNotifier_ = new GameNotifier(this);
        notificationEngine_->addNotifier(gameNotifier_);
    }
    
    if (!textNotifier_)
    {
        textNotifier_ = new TextNotifier(graphicsEngine_);
        notificationEngine_->addNotifier(textNotifier_);
    }
    
    //TODO: Below is complex and should come from a file.
    //TODO: Could create a builder to make creating entities simpler.
    
    /******************
     * 2: Setup the entities of the game.  DON'T FORGET TO ADD TO RESPECTIVE ARRAYS TO AVOID MEMORY LEAKS.
     ******************/
    
    //Rooms
    Entity* room1 = new Entity("a dark room");
    gameEntities_.emplace_back(room1);
    Entity* room2 = new Entity("a small room");
    gameEntities_.emplace_back(room2);
    Entity* room3 = new Entity("a big room");
    gameEntities_.emplace_back(room3);
    Entity* room4 = new Entity("a round room");
    gameEntities_.emplace_back(room4);
    Entity* room5 = new Entity("a black room");
    gameEntities_.emplace_back(room5);
    Entity* room6 = new Entity("a toilet");
    gameEntities_.emplace_back(room6);
    
    //Children
    EntityChildren* room1Children = new EntityChildren();
    gameChildren_.emplace_back(room1Children);
    EntityChildren* room2Children = new EntityChildren();
    gameChildren_.emplace_back(room2Children);
    EntityChildren* room3Children = new EntityChildren();
    gameChildren_.emplace_back(room3Children);
    EntityChildren* room4Children = new EntityChildren();
    gameChildren_.emplace_back(room4Children);
    EntityChildren* room5Children = new EntityChildren();
    gameChildren_.emplace_back(room5Children);
    EntityChildren* room6Children = new EntityChildren();
    gameChildren_.emplace_back(room6Children);
    
    room1->setChildren(room1Children);
    room2->setChildren(room2Children);
    room3->setChildren(room3Children);
    room4->setChildren(room4Children);
    room5->setChildren(room5Children);
    room6->setChildren(room6Children);
    
    //Room 1 locked exit to the Room 2 that needs r2Key to open
    Entity* r2Key = new Entity("a large key");
    gameEntities_.emplace_back(r2Key);
    ExitCommand* r1ExitToR2 = new ExitCommand(room2, "Go North");
    gameCommands_.emplace_back(r1ExitToR2);
    UnlockCommand* r1ToR2UnlockDoor = new UnlockCommand(r2Key, r1ExitToR2, "Unlock north door");
    gameCommands_.emplace_back(r1ToR2UnlockDoor);
    Entity* r1ToR2LockedDoor =  new Entity("a locked door to the north", nullptr, r1ToR2UnlockDoor, room1, nullptr);
    gameEntities_.emplace_back(r1ToR2LockedDoor);
    room1Children->addChild(r1ToR2LockedDoor);
    
    //Room 1 exit to Room 3
    ExitCommand* r1ExitToR3 = new ExitCommand(room3, "Go East");
    gameCommands_.emplace_back(r1ExitToR3);
    Entity* r1ToR3Door =  new Entity("a door to the east", nullptr, r1ExitToR3, room1, nullptr);
    gameEntities_.emplace_back(r1ToR3Door);
    room1Children->addChild(r1ToR3Door);
    
    //Room 1 exit to Room 5
    ExitCommand* r1ExitToR5 = new ExitCommand(room5, "Go West");
    gameCommands_.emplace_back(r1ExitToR5);
    Entity* r1ToR5Door =  new Entity("a passage to the west", nullptr, r1ExitToR5, room1, nullptr);
    gameEntities_.emplace_back(r1ToR5Door);
    room1Children->addChild(r1ToR5Door);
    
    //Room 2 Dragon and Winning Exit
    Stats* dragonStats = new Stats(100,100);
    gameStats_.emplace_back(dragonStats);
    AttackCommand* attackDragon = new AttackCommand("Attack Dragon");
    gameCommands_.emplace_back(attackDragon);
    Entity* dragon = new Entity("a hungry dragon", dragonStats, attackDragon, room2, nullptr);
    gameEntities_.emplace_back(dragon);
    attackDragon->setDefender(dragon);
    
    WinCommand* winCommand = new WinCommand("Escape");
    gameCommands_.emplace_back(winCommand);
    Entity* winningDoor = new Entity("a breach in the walls filled with light", nullptr, winCommand, room2, nullptr);
    gameEntities_.emplace_back(winningDoor);
    room2Children->addMultiLayeredChild(dragon, winningDoor);
    
    //Room 2 exit to Room 1
    ExitCommand* r2ExitToR1 = new ExitCommand(room1, "Go back");
    gameCommands_.emplace_back(r2ExitToR1);
    Entity* r2ToR1Door =  new Entity("the way you have come", nullptr, r2ExitToR1, room2, nullptr);
    gameEntities_.emplace_back(r2ToR1Door);
    room2Children->addChild(r2ToR1Door);
    
    //Room 3 exit to Room 4
    ExitCommand* r3ExitToR4 = new ExitCommand(room4, "Go East");
    gameCommands_.emplace_back(r3ExitToR4);
    Entity* r3ToR4Door =  new Entity("a tunnel to the east", nullptr, r3ExitToR4, room3, nullptr);
    gameEntities_.emplace_back(r3ToR4Door);
    room3Children->addChild(r3ToR4Door);
    
    //Room 3 exit to Room 1
    ExitCommand* r3ExitToR1 = new ExitCommand(room1, "Go back");
    gameCommands_.emplace_back(r3ExitToR1);
    Entity* r3ToR1Door =  new Entity("the way you have come", nullptr, r3ExitToR1, room3, nullptr);
    gameEntities_.emplace_back(r3ToR1Door);
    room3Children->addChild(r3ToR1Door);
    
    //Room 3 has a chest with the r2Key
    OpenCommand* openChestR3 = new OpenCommand(r2Key, "Open chest");
    gameCommands_.emplace_back(openChestR3);
    Entity* chestR3 = new Entity("a wooden chest", nullptr, openChestR3, room3, nullptr);
    gameEntities_.emplace_back(chestR3);
    room3Children->addChild(chestR3);
    
    //Room 4 exit to Room 3
    ExitCommand* r4ExitToR3 = new ExitCommand(room3, "Go back");
    gameCommands_.emplace_back(r4ExitToR3);
    Entity* r4ToR3Door =  new Entity("the way you have come", nullptr, r4ExitToR3, room4, nullptr);
    gameEntities_.emplace_back(r4ToR3Door);
    room4Children->addChild(r4ToR3Door);
    
    //Room 4 has a chest with the r6Key
    Entity* r6Key = new Entity("a tiny key");
    gameEntities_.emplace_back(r6Key);
    OpenCommand* openChestR4 = new OpenCommand(r6Key, "Open wooden chest");
    gameCommands_.emplace_back(openChestR4);
    Entity* chestR4 = new Entity("a wooden chest", nullptr, openChestR4, room4, nullptr);
    gameEntities_.emplace_back(chestR4);
    room4Children->addChild(chestR4);
    
    //Room 4 has a chest with a shield
    Stats* shieldStats = new Stats(100,1);
    gameStats_.emplace_back(shieldStats);
    Entity* shield = new Entity("a wooden shield");
    gameEntities_.emplace_back(shield);
    shield->setStats(shieldStats);
    OpenCommand* openShieldR4 = new OpenCommand(shield, "Open large chest");
    gameCommands_.emplace_back(openShieldR4);
    Entity* shieldChestR4 = new Entity("a large chest", nullptr, openShieldR4, room4, nullptr);
    gameEntities_.emplace_back(shieldChestR4);
    room4Children->addChild(shieldChestR4);
    
    //Room 5 exit to Room 1
    ExitCommand* r5ExitToR1 = new ExitCommand(room1, "Go back");
    gameCommands_.emplace_back(r5ExitToR1);
    Entity* r5ToR1Door = new Entity("the way you have come", nullptr, r5ExitToR1, room5, nullptr);
    gameEntities_.emplace_back(r5ToR1Door);
    room5Children->addChild(r5ToR1Door);
    
    //Room 5 locked exit to the Room 6 that needs r6Key to open
    ExitCommand* r5ExitToR6 = new ExitCommand(room6, "Go West");
    gameCommands_.emplace_back(r5ExitToR6);
    UnlockCommand* r5ToR6UnlockDoor = new UnlockCommand(r6Key, r5ExitToR6, "Unlock west door");
    gameCommands_.emplace_back(r5ToR6UnlockDoor);
    Entity* r5ToR6LockedDoor =  new Entity("a locked door to the west", nullptr, r5ToR6UnlockDoor, room5, nullptr);
    gameEntities_.emplace_back(r5ToR6LockedDoor);
    room5Children->addChild(r5ToR6LockedDoor);
    
    //Room 6 exit to Room 5
    ExitCommand* r6ExitToR5 = new ExitCommand(room5, "Go back");
    gameCommands_.emplace_back(r6ExitToR5);
    Entity* r6ToR5Door =  new Entity("the way you have come", nullptr, r6ExitToR5, room6, nullptr);
    gameEntities_.emplace_back(r6ToR5Door);
    room6Children->addChild(r6ToR5Door);
    
    //Room 6 has a chest with a sword
    Stats* swordStats = new Stats(1,100);
    gameStats_.emplace_back(swordStats);
    Entity* sword = new Entity("a steel sword");
    gameEntities_.emplace_back(sword);
    sword->setStats(swordStats);
    OpenCommand* openSwordR6 = new OpenCommand(sword, "Open large chest");
    gameCommands_.emplace_back(openSwordR6);
    Entity* swordChestR6 = new Entity("a large chest", nullptr, openSwordR6, room6, nullptr);
    gameEntities_.emplace_back(swordChestR6);
    room6Children->addChild(swordChestR6);
    
    //Main Character - starts in Room 1
    Stats* playerStats = new Stats(100,100);
    gameStats_.emplace_back(playerStats);
    EntityChildren* playerInventory = new EntityChildren();
    gameChildren_.emplace_back(playerInventory);
    AttackCommand* attackPlayer = new AttackCommand("Attack Player");
    gameCommands_.emplace_back(attackPlayer);
    Entity* player = new Entity("You", playerStats, attackPlayer, room1, playerInventory);
    gameEntities_.emplace_back(player);
    attackPlayer->setDefender(player);
    room1Children->addChild(player);
    
    /******************
     * 3: Update the renderable / controlable lists
     ******************/
    
    renderableEntities_[0] = new RenderableEntity(player, graphicsEngine_);
    controllableEntities_[0] = new ControllableEntity(player, manualControlEngine_);
    controllableEntities_[1] = new ControllableEntity(dragon, aiControlEngine_);
    
}

/*
 Frees up the memory taken by the Game Entities and Components during a play through, so they can be reloaded when playing again.
 */
void Game::reset()
{
    //delete the game entities
    for(auto iter = gameEntities_.begin() ; iter != gameEntities_.end() ; iter++)
    {
        delete (*iter);
    }
    gameEntities_.erase(gameEntities_.begin(), gameEntities_.end());
    
    //delete the game children
    for(auto iter = gameChildren_.begin() ; iter != gameChildren_.end() ; iter++)
    {
        delete (*iter);
    }
    gameChildren_.erase(gameChildren_.begin(), gameChildren_.end());
    
    //delete the game commands
    for(auto iter = gameCommands_.begin() ; iter != gameCommands_.end() ; iter++)
    {
        delete (*iter);
    }
    gameCommands_.erase(gameCommands_.begin(), gameCommands_.end());
    
    //delete the game stats
    for(auto iter = gameStats_.begin() ; iter != gameStats_.end() ; iter++)
    {
        delete (*iter);
    }
    gameStats_.erase(gameStats_.begin(), gameStats_.end());
    
    //delete the renderable entities
    for(auto iter = renderableEntities_.begin() ; iter != renderableEntities_.end() ; iter++)
    {
        delete (*iter);
    }
    
    //delete the controllable entities
    for(auto iter = controllableEntities_.begin() ; iter != controllableEntities_.end() ; iter++)
    {
        delete (*iter);
    }
}

/*
 Frees up all the memory taken by the Game, including the Notifiers.
 */
void Game::deactivate()
{
    reset();
        
    //delete the notifiers
    notificationEngine_->removeNotifier(gameNotifier_);
    delete gameNotifier_;
    
    notificationEngine_->removeNotifier(textNotifier_);
    delete textNotifier_;
}



