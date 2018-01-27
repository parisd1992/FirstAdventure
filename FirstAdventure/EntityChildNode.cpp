//
//  EntityChildNode.cpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "EntityChildNode.hpp"

void EntityChildNode::appendChild(Entity* entity)
{
    if (!nextChild_)
    {
        nextChild_ = new EntityChildNode();
        nextChild_->child_ = entity;
    }
    else
    {
        nextChild_->appendChild(entity);
    }
}

Entity* EntityChildNode::peakChild()
{
    return child_;
}

Entity* EntityChildNode::popChild()
{
    if(nextChild_)
    {
        EntityChildNode* temp = nextChild_;
        child_ = nextChild_->child_;
        nextChild_ = nextChild_->nextChild_;
        delete temp;
        return child_;
    }
    
    child_ = nullptr;
    return child_;
}
