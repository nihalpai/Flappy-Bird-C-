# Flappy-Bird-C-


This is the compile command:

g++ -std=c++14 -I/usr/local/Cellar/sfml/2.5.1_2/include -c main.cpp
g++ -std=c++14 -I/usr/local/Cellar/sfml/2.5.1_2/include -c Collisions.cpp
g++ -std=c++14 -I/usr/local/Cellar/sfml/2.5.1_2/include -c Resources.cpp
g++ -std=c++14 -I/usr/local/Cellar/sfml/2.5.1_2/include -c GameInitialization.cpp
g++ -std=c++14 -I/usr/local/Cellar/sfml/2.5.1_2/include -c Pipe.cpp
g++ -std=c++14 -I/usr/local/Cellar/sfml/2.5.1_2/include -c GameLoop.cpp
g++ main.o Collisions.o Resources.o GameInitialization.o Pipe.o GameLoop.o -o main -L/usr/local/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio



This is the run command:

./main
