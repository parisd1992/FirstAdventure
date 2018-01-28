//
//  RenderableEntity.cpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "RenderableEntity.hpp"

void RenderableEntity::render()
{
    graphicsEngine_->render(*entity_);
}
