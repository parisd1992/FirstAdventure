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

class Game
{
    friend class PlayGameState;
    
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
    
    //we need these to keep track of all the objects created by the game
    //so we can delete them and avoid memory leaks
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
    
    void initialise();
    void deactivate();
    void reset();

    void runGame();
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
