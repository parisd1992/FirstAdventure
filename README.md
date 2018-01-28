# Project Goals
A simple Text Adventure Game in C++ called 'First Adventure'.  

The aim of this project is to practice C++, design patterns and do some basic game development.  
As this is an education exercise, some of the code is purposefully over engineered and inefficient.

# Design Patterns
The code touches on a number of design patterns:

- Component (http://www.gameprogrammingpatterns.com/component.html)
- Command (http://www.gameprogrammingpatterns.com/command.html)
- State (http://www.gameprogrammingpatterns.com/state.html)
- Observer (http://www.gameprogrammingpatterns.com/observer.html)
- Object Pool (http://www.gameprogrammingpatterns.com/object-pool.html)

# Improvements

There are a number of design and structural improvements which could be made to the code.  
Most of these are marked out as TODO comments.  
As this is an education exercise, these improvements are beyond the scope of this project.

# Next Steps

## Entity Initialisation

The game entities are initialised in the Game class as part of the initialise() method.

[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/src/Game.cpp] 

Initialisation could be simplified using an Entity Builder class.  
It should also be possible to create the Entities (and the game itself) from a file.
This will make the initialising code more accessible and easier to create new adventures.

## Entity Memory Management

Memory management of created Entities is challenging because they are created in the Game class initialise() method.
4 arrays were added to Game to store the individual Entities and its Components.
At the end of each play, these components are freed and memory returned back to the heap.
The advantage is that the story can easily be changed by updating what is created in initialise().
The disadvantage is that developments must remember to add each created Entity and Component to the respective arrays to avoid leaks.
The code has been tested for leaks using XCode Developer Tools. 






