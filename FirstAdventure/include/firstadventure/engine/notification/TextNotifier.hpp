//
//  TextNotifier.hpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#ifndef TextNotifier_hpp
#define TextNotifier_hpp

#include <stdio.h>
#include "Notifier.hpp"
#include "GraphicsEngine.hpp"

class TextNotifier : public Notifier
{
private:
    GraphicsEngine* graphicsEngine_;
    Entity* textEntity_;

public:
    TextNotifier(GraphicsEngine* graphicsEngine) : graphicsEngine_{graphicsEngine}
    {
        //object pool - repurposing the same Entity for rendering
        textEntity_ = new Entity();
    }
    
    virtual ~TextNotifier()
    {
        delete textEntity_;
    }
    
    void onNotify(Message message);
};

#endif /* TextNotifier_hpp */
