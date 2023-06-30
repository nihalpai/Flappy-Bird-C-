// Textures.hpp
#pragma once  // prevents multiple inclusions of the header
#include <SFML/Graphics.hpp>  // SFML library for graphics manipulation

using namespace sf;  

// structure storing the textures used in the game
struct Textures {
    
    Texture flappy[3];  // array to hold the textures of flappy at different stages
    Texture pipe;  // texture for pipe
    Texture background;  // texture for background
    Texture gameover;  // texture for gameover screen
};