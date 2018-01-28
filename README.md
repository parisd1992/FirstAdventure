# Project Goals
A simple Text Adventure Game in C++ called 'First Adventure'.  

The aim of this project is to practice C++11, design patterns and do some basic game development.  
As this is an education exercise, some of the code is purposefully over engineered and inefficient.

# Building and Running

Built and run on a Mac running macOS 10.13.2.

To build and run you can:

a. Checkout and import into XCode.

b. Run CMake in the folder https://github.com/parisd1992/FirstAdventure/tree/master/FirstAdventure to create a Makefile.
Then run Make to create an executable which you can run.

# Design Patterns
The code touches on a number of design patterns:

- Component (http://www.gameprogrammingpatterns.com/component.html)

The Entity class spans multiple domains (Command, Stats, EntityChildren) without coupling them to each other
[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/include/firstadventure/entity/Entity.hpp]

The RenderableEntity and ControllableEntity classes are also examples.  They wrap Entity with new functionality without coupling.

- Command (http://www.gameprogrammingpatterns.com/command.html)

The Command class encapsulates requests as objects.
[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/include/firstadventure/entity/command/Command.hpp]

- State (http://www.gameprogrammingpatterns.com/state.html)

The game is controlled through a number of GameStates (ready, playing, won, lost, quit).

[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/include/firstadventure/state/GameState.hpp]

- Observer (http://www.gameprogrammingpatterns.com/observer.html)

The NotificationEngine provides a 'subscriber' for observers (Notifiers) to attach to.

[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/include/firstadventure/engine/notification/NotificationEngine.hpp]

- Strategy (https://en.wikipedia.org/wiki/Strategy_pattern)

The ControlEngine implementations provide different control strategies.  One is user driven, the other AI.

[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/include/firstadventure/engine/control/ControlEngine.hpp]

- Object Pool (http://www.gameprogrammingpatterns.com/object-pool.html)

The TextNotifier reuses an Entity to sent its messages
[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/include/firstadventure/engine/notification/TextNotifier.hpp]

# Improvements

There are a number of design and structural improvements which could be made to the code.  
Most of these are marked out as TODO comments.  
As this is an education exercise, these improvements are beyond the scope of this project.

# Next Steps

## Tests

The nature of the project lends itself well to adding Unit Testing and trying out some C++ frameworks.

We have already carried out Memory Leak testing using XCode Developer Tools.

Performance tests will be an interesting experiement, however optimal performance is not within the scope of this project.

## Entity Initialisation and Memory Management

The game entities are initialised in the Game class as part of the initialise() method.

[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/src/Game.cpp] 

Initialisation could be simplified using an Entity Builder class.

It should also be possible to create the Entities (and the game itself) from a file.

This will make the initialising code more accessible and easier to create new adventures.

Memory management of created Entities is challenging because they are created in the Game class initialise() method.

4 arrays were added to Game to store the individual Entities and its Components.

At the end of each play, the objects in the arrays are freed and memory returned back to the heap.

The advantage is that the story can easily be changed by updating what is created in initialise().

The disadvantage is that developmers must remember to add each created Entity and Component to the respective arrays to avoid leaks.

The code has been tested for leaks using XCode Developer Tools. 






