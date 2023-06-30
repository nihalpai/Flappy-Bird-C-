// GameLoop.hpp
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "Collisions.hpp"
#include "Sounds.hpp"
#include "Textures.hpp"
#include "Flappy.hpp"
#include "Game.hpp"
#include "GameState.hpp"
#include "Resources.hpp"
#include "GameInitialization.hpp"
#include "Pipe.hpp"

using namespace sf;

// Main class for handling the game loop
class GameLoop {
    
private:
    RenderWindow window;  // window to render game
    Resources resources;  // game resources
    Flappy flappy;  // Flappy Bird character
    Pipe pipes;  // pipes obstacles
    Game game;  // game state

public:

    GameLoop();  // constructor

    // Methods for handling game loop
    void handleEvents();  // handle user input and events
    void update();  // update game state
    void render();  // render game state
    void run();  // main game loop
};
