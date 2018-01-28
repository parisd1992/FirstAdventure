#http://derekmolloy.ie/hello-world-introductions-to-cmake/

#specify minimum make version
cmake_minimum_required(VERSION 3.10.2)

#c++11
set(CMAKE_CXX_STANDARD 11)

#specify project name
project (FirstAdventure)

#Bring the headers into the project
include_directories(
    include/firstadventure/
    include/firstadventure/state
    include/firstadventure/engine
    include/firstadventure/engine/notification
    include/firstadventure/engine/control
    include/firstadventure/engine/graphics
    include/firstadventure/entity
    include/firstadventure/entity/command)

#Specify the source files using the file(GLOB...) wildcard:
file(GLOB_RECURSE SOURCES "src/*.cpp")

#build executable
add_executable(firstAdventureGame ${SOURCES})
