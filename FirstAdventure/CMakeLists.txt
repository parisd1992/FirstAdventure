#http://derekmolloy.ie/hello-world-introductions-to-cmake/

#specify minimum make version
cmake_minimum_required(VERSION 3.10.2)
#c++11
set(CMAKE_CXX_STANDARD 11)

#specify project name
project (FirstAdventure)

#Specify the source files using the file(GLOB...) wildcard:
file(GLOB SOURCES "*.cpp")

#build executable
add_executable(firstAdventureGame ${SOURCES})