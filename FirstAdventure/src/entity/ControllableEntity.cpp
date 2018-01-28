//
//  ControllableEntity.cpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "ControllableEntity.hpp"

void ControllableEntity::control()
{
    controlEngine_->control(*entity_);
}

Entity* ControllableEntity::getEntity()
{
    return entity_;
}

