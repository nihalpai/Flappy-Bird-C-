// Game.hpp

#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.hpp"

using namespace sf;

// Data structure for game status
struct Game {
   
   int score = 0;  // current score
   int highscore = 0;  // highest score reached
   int frames = 0;  // frame count
   GameState gameState = waiting;  // initial game state
   Sprite background[3];  // background sprites
   Sprite gameover;  // gameover sprite
   Text pressC;  // press C prompt text
   Text scoreText;  // current score text
   Text highscoreText;  // high score text
   Font font;  // font for text
};
