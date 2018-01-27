//
//  TextGraphicsEngine.cpp
//  FirstAdventure
//
//  Created by David Paris on 26/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "TextGraphicsEngine.hpp"
#include <string>
#include <iostream>


using namespace std;

void TextGraphicsEngine::render(Entity &entity)
{
    std::string name = entity.getDescription();
    Entity* parent = entity.getParentEntity();
    
    if (parent)
    {
        cout << name << " are in " << parent->getDescription() << endl;
        
        for( int i = 0 ; i < Entity::MAX_CHILDREN ; i++)
        {
            Entity* child = parent->getChildren(i);
            
            if (child)
            {
                cout << name << " see " << child->getDescription() << endl;
            }
        }
    }
    cout << endl;
}
