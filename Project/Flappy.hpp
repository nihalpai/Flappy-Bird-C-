// Flappy.hpp

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

// Struct to represent the flappy bird character
struct Flappy {

   double v = 0;  // velocity
   int frame = 0;  // current animation frame
   Sprite sprite;  // sprite for flappy bird
};
