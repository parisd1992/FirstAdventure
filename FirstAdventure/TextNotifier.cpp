//
//  TextNotifier.cpp
//  FirstAdventure
//
//  Created by David Paris on 27/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include <iostream>
#include "TextNotifier.hpp"

using namespace std;

void TextNotifier::notify(Message message)
{
    cout << message << endl;
}
