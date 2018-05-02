# First Adventure

![Alt text](screenshots/FirstAdventure_OpeningTitle.png?raw=true "Opening Title")

First Adventure is a text adventure game engine and game in C++ with support for a text battle system, character stats progression, enemy AI and scenario based story progression.

### Story

You find yourself in a dungeon, trapped.  The door ahead is shut, yet there must be way to open it.
The question is, do you want to?  Are you ready to face what might be waiting on the other side?

Hint: Picking up a sword and a shield will help.

# Contents
**[Project Goals](#project-goals)**<br>
**[Building and Running](#building-and-running)**<br>
**[Screenshots](#screenshots)**<br>
**[Learning C++](#learning-c++)**<br>
**[Design Patterns](#design-patterns)**<br>
**[Improvements](#improvements)**<br>
**[Next Steps](#next-steps)**<br>

# Project Goals

- Practice C++.
- Create a Text Adventure Game Engine in C++ using reusable design patterns.
- Implement a simple text adventure game using the engine called 'First Adventure'.

The aim of this project is to practice C++11, design patterns and do some basic game development.  
As this is an education exercise, some of the code is purposefully over engineered and the implemented story simple.

# Building and Running

Built and run on a Mac running macOS 10.13.2 (C++11).

To build and run you can either:

a. Checkout and import into XCode.

b. Checkout and run CMake in the folder containing the CMakeLists.txt file to create a Makefile.
Then navigate to the Makefile and run Make to create an executable.

Follow the ingame instructions to navigate through the game.

# Screenshots

### Your First Choice

![Alt text](screenshots/FirstAdventure_FirstChoice.png?raw=true "Your first choice")

### You need a key to unlock some doors!

![Alt text](screenshots/FirstAdventure_UnlockingDoorsWithoutKey.png?raw=true "You need a key to unlock some doors!")

### Good thing you can open chests and pick up items

![Alt text](screenshots/FirstAdventure_PickingUpItems.png?raw=true "Good thing you can open chests and pick up items")

### If you've found the right key you can unlock doors

![Alt text](screenshots/FirstAdventure_UnlockingDoorsWithKey.png?raw=true "Now you can unlock the doors")

### But do you really want to?  Lucky we found that shield...

![Alt text](screenshots/FirstAdventure_AttackingDragons.png?raw=true "But do you really want to?  Lucky we found that shield...")



# Learning C++

It's been really fun learning C++ over the past few weeks.

My favourite part has been the freedom and control it gives to developers when doing pretty much anything (see "Instance Creation On Stack vs Heap" for an example).

I enjoy the challenge of understanding how the compiler works, how my code is executed by the Operating System, and how I can make it more efficient whilst keeping it easy to understand.

### Why learn C++?

My day job focuses on building and designing high performant, scalable, fault tolerant, reusable systems in Java.

These systems are critical to the day-to-day running of the business.

Through C++ I've seen how much the Java Compiler hides from developers in terms of memory management, instance creation, and just about anything else.

C++ has provided a better understanding on what happens behind the scenes when coding in Java and how my OS runs my applications.

### Resources

- Learn C++ for Game Development by Bruce Sutherland (ISBN-13: 978-1430264576)
- Game Programming Patterns by Robert Nystrom (ISBN: 0990582906)

### Instance Creation On Stack vs Heap

It was interesting to understand the different ways C++ let's you create objects and manage their memory; a fundamental concept for an object oriented language.

This was something I did not think about when writing Java code.

(Note: I'm assuming a basic understanding of memory management in Java / Operating Systems -e.g. what is the heap, stack, pass by reference, pass by value)

In Java you create an instance of a class as:

<pre>
MyClass myInstance = new MyClass();
</pre>

- What does this mean?

Java is actually creating a reference that points to an instance (an area of memory) of MyClass on the heap.

This is why you can change the field values of an instance inside a method, even though Java is 'pass-by-value':
https://www.journaldev.com/4098/java-heap-space-vs-stack-memory

In other words, myInstance points to an instance (an area of memory) of MyClass on the heap.

C++ uses pointer notation to define that:

<pre>
MyClass* myInstance = new MyClass();
</pre>

Read as: myInstance is a pointer to an instance of MyClass (on the heap).

That means we can create instances of MyClass that are not on the heap:

<pre>
MyClass myInstanceOnStack; //creates an instance of MyClass on the stack
</pre>

The memory taken up by myInstanceOnStack will be freed once the method that creates this instance is out of scope.

- So?

If an instance is created on the stack, we can access it directly without having to 'dereference' the pointer (this could be faster).

If you create an instance on the stack in a method, you should not return it from the creating method.

Larger instances should be created on the heap because there is generally more space.

If you create an instance on the heap, you need to free the memory yourself (smart pointers can help here).


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

# Potential Future Work

With code I think that the simplest solution is often the best one.
There are a number of design and structural improvements which could be made to the code.
Most of these are marked out with TODO comments.
As this is an education exercise, these improvements are beyond the scope of this project.

### Engine and Implementation Separation.

The engine and implementation share the same codebase.

It would be exciting to package the engine as a separate product.

Users could easily make their own adventure games and explore the depths of their imagination.

See the section "Tests" and "Entity Initialisation and Memory Management" below for more details.

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






