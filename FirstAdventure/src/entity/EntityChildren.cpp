//
//  EntityChildren.cpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "EntityChildren.hpp"


EntityChildren::~EntityChildren()
{
    //TODO: this seems extrememly inefficient
    //We are going to iterate through each child node and remove it
    //Until there are no child nodes left.
    //Remember a child node can have multiple layers, so removing the top layer does not mean
    //the node was completely removed.
    
    while(numberOfChildren())
    {
        //remove the children in reverse order
        for (int i = numberOfChildren()-1 ; i >= 0 ; i--)
        {
            Entity* child = getChild(i);
            removeChild(child);
        }
    }
}

Entity* EntityChildren::getChild(int index)
{
    if (index < childNodes_.size() && childNodes_[index])
    {
        return childNodes_[index]->peakChild();
    }
    return nullptr;
}

void EntityChildren::addChild(Entity *entity)
{    
    childNodes_.size();
    childNodes_.push_back(new EntityChildNode(entity));
}

void EntityChildren::addChild(Entity *entity, int index)
{
    if(index < childNodes_.size() && childNodes_[index])
    {
        childNodes_[index]->appendChild(entity);
    }
    else
    {
        childNodes_.insert(childNodes_.begin()+index, new EntityChildNode(entity));
    }
}

void EntityChildren::addMultiLayeredChild(Entity *child1, Entity *child2)
{
    EntityChildNode* childNode = new EntityChildNode(child1);
    childNode->appendChild(child2);
    childNodes_.push_back(childNode);
}

void EntityChildren::removeChild(Entity *entity)
{
    for(auto iter = childNodes_.begin() ; iter != childNodes_.end() ; iter++)
    {
        if (*iter)
        {
            if((*iter)->peakChild() == entity)
            {
                Entity* newTop = (*iter)->popChild();
                
                if (!newTop)
                {
                    delete (*iter);
                    childNodes_.erase(iter);
                }
                break;
            }
        }
    }
}

void EntityChildren::removeChild(int index)
{
    if(childNodes_[index])
    {
        Entity* newTop = childNodes_[index]->popChild();
        
        if (!newTop)
        {
            delete (childNodes_[index]);
            childNodes_.erase(childNodes_.begin() + index);
        }
    }
}
