# Contents
**[Project Goals](#project-goals)**<br>
**[Building and Running](#building-and-running)**<br>
**[Learning C++](#learning-c++)**<br>
**[Design Patterns](#design-patterns)**<br>
**[Improvements](#improvements)**<br>
**[Next Steps](#next-steps)**<br>

# Project Goals

- Create a reusable Text Adventure Game Engine in C++.
- Implement a simple text adventure game using the engine called 'First Adventure'.

The aim of this project is to practice C++11, design patterns and do some basic game development.  
As this is an education exercise, some of the code is purposefully over engineered and the implemented story simple.

### 'First Adventure' Story

You find yourself in a dungeon, trapped.  The door ahead is shut, yet there must be way to open it.
The question is, do you want to?  Are you ready to face what might be waiting on the other side?

Hint: Picking up a sword and a shield will help.

# Building and Running

Built and run on a Mac running macOS 10.13.2 (C++11).

To build and run you can either:

a. Checkout and import into XCode.

b. Checkout and run CMake in the folder containing the CMakeLists.txt file to create a Makefile.
Then navigate to the Makefile and run Make to create an executable.

Follow the ingame instructions to navigate through the game.

# Learning C++

It's been really fun learning C++ over the past few weeks.

My favourite part has been the freedom and control it gives to developers when doing pretty much anything.

I enjoy the challenge of understanding how the compiler works, how my code is executed by the Operating System, and how I can make it more efficient whilst keeping it easy to understand.

### Why learn C++?

My day job focuses on building and designing high performant, scalable, fault tolerant, reusable systems in Java.

These systems are critical to the day-to-day running of the business.

With C++ I've seen for myself how much the Java Compiler hides from developers in terms of memory management, instance creation, and just about anything else.

With C++ I have a better understanding on what happens behind the scenes when coding in Java and how my OS runs my applications.

### Resources

- Learn C++ for Game Development by Bruce Sutherland (ISBN-13: 978-1430264576)
- Game Programming Patterns by Robert Nystrom (ISBN: 0990582906)

### Instance Creation


# Design Patterns
The code touches on a number of design patterns to help with resuability:

- Component (http://www.gameprogrammingpatterns.com/component.html)

The Entity class spans multiple domains (Command, Stats, EntityChildren) without coupling them to each other
[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/include/firstadventure/entity/Entity.hpp].
It is easy to create new and different entities with different functions (e.g. a dragon which can attack our player, or a sword which will help our player fight):

[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/src/Game.cpp]

The RenderableEntity and ControllableEntity classes are also examples.  They wrap Entity with new functionality without coupling.

- Command (http://www.gameprogrammingpatterns.com/command.html)

The Command class encapsulates requests as objects.
[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/include/firstadventure/entity/command/Command.hpp]

Be creating a new command implementation, users can add exciting new functionality to the game (e.g. battling dragons, opening doors).

- State (http://www.gameprogrammingpatterns.com/state.html)

The game is controlled through a number of GameStates (ready, playing, won, lost, quit).

[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/include/firstadventure/state/GameState.hpp]

- Observer (http://www.gameprogrammingpatterns.com/observer.html)

The NotificationEngine provides a 'subscriber' for observers (Notifiers) to attach to.

[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/include/firstadventure/engine/notification/NotificationEngine.hpp]

Different Notifier implementations can choose to handle messages differently (e.g. printing text to the screen or updating the game state). 

- Strategy (https://en.wikipedia.org/wiki/Strategy_pattern)

The ControlEngine implementations provide different control strategies.  One is user driven, the other AI.

[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/include/firstadventure/engine/control/ControlEngine.hpp]

- Object Pool (http://www.gameprogrammingpatterns.com/object-pool.html)

The TextNotifier reuses an Entity to sent its messages
[https://github.com/parisd1992/FirstAdventure/blob/master/FirstAdventure/include/firstadventure/engine/notification/TextNotifier.hpp]

# Improvements

With code I think that the simplest solution is often the best one.
There are a number of design and structural improvements which could be made to the code.
Most of these are marked out with TODO comments.
As this is an education exercise, these improvements are beyond the scope of this project.

# Next Steps

### Engine and Implementation Separatation.

The engine and implementation share the same codebase.

It would be exciting to package the engine as a separate product.

Users could easily make their own adventure games and explore the depths of their imagination.

See the section "Entity Initialisation and Memory Management" below for more details.

### Tests

Testing is a key aspect of developing a reusable system.

I would go so far as to say nothing is reusable without testing:

- If you want to resuse something, you need to know what it does; testing can answer that.
- If you don't have tests, how can you ensure what you are reusing works?

As this is an educational exercise focusing on learning C++ it was not included as part of the initial goals, however I would recommend developers devote as much time to testing as they do making their code clean and efficient.

The nature of the project lends itself well to adding Unit Testing and trying out some C++ frameworks.

We have already carried out Memory Leak testing using XCode Developer Tools.

Performance tests will be an interesting experiement, however optimal performance is not within the scope of this project.

### Entity Initialisation and Memory Management

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






