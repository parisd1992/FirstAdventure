//
//  Game.hpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <array>
#include <vector>

#include "RenderableEntity.hpp"
#include "ControllableEntity.hpp"
#include "NotificationEngine.hpp"
#include "TextGraphicsEngine.hpp"
#include "ManualControlEngine.hpp"
#include "DragonControlEngine.hpp"
#include "Notifier.hpp"

class GameState;

/*
 The Game class is responsbile for creating and running the game and its state.
 It uses the State Pattern (http://www.gameprogrammingpatterns.com/state.html) to control the games state via the GameState class.
 
 The class has a NotificationEngine component which acts as the 'Subscriber' in the Observer Pattern.
 The Notifiers (and their implementations) are the 'Observers'.  See here: http://www.gameprogrammingpatterns.com/observer.html.
 */

class Game
{
    friend class PlayGameState; //so PlayGameState can access the game renerable and controllable entities
    
private:
    static const unsigned int MAX_RENDERABLE_ENTITIES = 1;
    static const unsigned int MAX_CONTROLLABLE_ENTITIES = 2;

private:
    GameState* state_;
    
    NotificationEngine* notificationEngine_;
    Notifier* gameNotifier_{nullptr};
    Notifier* textNotifier_{nullptr};
    
    GraphicsEngine* graphicsEngine_;
    ControlEngine* manualControlEngine_;
    ControlEngine* aiControlEngine_;
    
    std::array<RenderableEntity*, MAX_RENDERABLE_ENTITIES> renderableEntities_;
    std::array<ControllableEntity*, MAX_CONTROLLABLE_ENTITIES> controllableEntities_;
    
    //we need these lists to keep track of all the objects created by the game in initialise()
    //so we can delete them and avoid memory leaks
    //WHEN CREATING NEW ENTITIES AND COMPONENTS YOU MUST ADD THEM TO THEIR RESPECTIVE LISTS!!
    std::vector<Entity*> gameEntities_;
    std::vector<Command*> gameCommands_;
    std::vector<Stats*> gameStats_;
    std::vector<EntityChildren*> gameChildren_;
    

public:
    Game(GameState* state) : state_{state}
    {
        notificationEngine_ = new NotificationEngine();
    
        graphicsEngine_ = new TextGraphicsEngine();
        manualControlEngine_ = new ManualControlEngine(notificationEngine_);
        aiControlEngine_ = new DragonControlEngine(notificationEngine_);
    }
    
    ~Game()
    {
        deactivate();
        
        delete graphicsEngine_;
        delete manualControlEngine_;
        delete aiControlEngine_;
        
        delete notificationEngine_;
    }
    
    /*
     Initialises the Entities and Components that make up the game.
     */
    void initialise();
    
    /*
     Frees up the memory taken by the Game Entities and Components during a play through, so they can be reloaded when playing again.
     */
    void reset();
    
    /*
     Frees up all the memory taken by the Game, including the Notifiers.
     */
    void deactivate();

    /*
     Runs the game
     */
    void runGame();
    
    /*
     Forwards a message to the notification engine
     */
    void handleMessage(Notifier::Message message);
    
    NotificationEngine* getNotificationEngine()
    {
        return notificationEngine_;
    }
    
    void setState(GameState* gameState)
    {
        state_ = gameState;
    }
};

#endif /* Game_hpp */
