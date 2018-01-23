//
//  Room.hpp
//  FirstAdventure
//
//  Created by David Paris on 23/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

#include <stdio.h>
#include <string>

class Exit;

class Room
{
private:
    std::string description_;
    Exit* exit_;
    
public:
    Room(std::string description) : description_{description}
    {}
    
    void setExit(Exit* exit)
    {
        exit_ = exit;
    }
    
    Exit* getExit()
    {
        return exit_;
    }
    
    std::string getDescription()
    {
        return description_;
    }
    
};

#endif /* Room_hpp */
