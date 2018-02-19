//
//  Stats.hpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef Stats_hpp
#define Stats_hpp

#include <stdio.h>

/**
 Defines a set of stats for an entity
 **/
class Stats
{
private:
    int health_;
    int strength_;
    
public:
    Stats() : health_{1}, strength_{1}
    {
        
    }
    
    Stats(int health, int strength) : health_{health}, strength_{strength}
    {
        
    }
    
    void setHealth(int health)
    {
        health_ = health;
    }
    
    int getHealth()
    {
        return health_;
    }
    
    int getStrength()
    {
        return strength_;
    }
};

#endif /* Stats_hpp */
