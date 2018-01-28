//
//  TextGraphicsEngine.cpp
//  FirstAdventure
//
//  Created by David Paris on 26/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "TextGraphicsEngine.hpp"
#include "EntityChildren.hpp"
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
        
        EntityChildren* children = parent->getChildren();
        
        for(int i = 0; i < children->numberOfChildren(); i++)
        {
            if (children->getChild(i) != &entity)
            {
                cout << name << " see " << children->getChild(i)->getDescription() << endl;
            }
        }
        cout << "################################################################" << endl;
    }
    else
    {
        cout << entity.getDescription() << endl;
    }
    
    cout << endl;
}
