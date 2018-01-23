//
//  Exit.hpp
//  FirstAdventure
//
//  Created by David Paris on 23/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef Exit_hpp
#define Exit_hpp

#include <stdio.h>
#include <string>

class Room;

class Exit
{
private:
    std::string direction_;
    Room* to_;
    
public:
    Exit(Room* to, std::string direction) : to_{to}, direction_{direction}
    {}
    
    Room* getExitRoom()
    {
        return to_;
    }
    
    std::string getDirection()
    {
        return direction_;
    }
    
    
    
};

#endif /* Exit_hpp */
