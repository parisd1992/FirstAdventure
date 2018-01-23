//
//  Player.hpp
//  FirstAdventure
//
//  Created by David Paris on 23/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Room.hpp"

class Player
{
private:
    Room* room_;
    
public:
    Player(Room* room) : room_{room}
    {}
    
    void setRoom(Room* room)
    {
        room_ = room;
    }
    
    Room* getRoom()
    {
        return room_;
    }
};

#endif /* Player_hpp */
