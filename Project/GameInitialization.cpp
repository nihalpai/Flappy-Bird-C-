// GameInitialization.cpp

#include "GameInitialization.hpp"

// Setup the game's initial state
void initializeGame(RenderWindow &window, Game &game, Flappy &flappy, Pipe &pipes, Resources &resources) {

    srand(time(0));  // set seed for randomness

    // flappy character setup
    flappy.sprite.setPosition(250, 300);
    flappy.sprite.setScale(2, 2);

    // load game resources and setup game elements
    game.font.loadFromFile("./fonts/flappy.ttf");
    game.background[0].setTexture(resources.textures.background);
    game.background[1].setTexture(resources.textures.background);
    game.background[2].setTexture(resources.textures.background);
    game.background[0].setScale(1.15625, 1.171875);
    game.background[1].setScale(1.15625, 1.171875);
    game.background[2].setScale(1.15625, 1.171875);
    game.background[1].setPosition(333, 0);
    game.background[2].setPosition(666, 0);
    game.gameover.setTexture(resources.textures.gameover);
    game.gameover.setOrigin(192 / 2, 42 / 2);
    game.gameover.setPosition(500, 125);
    game.gameover.setScale(2, 2);
    game.pressC.setString("Press C to continue");
    game.pressC.setFont(game.font);
    game.pressC.setFillColor(Color::White);
    game.pressC.setCharacterSize(50);
    game.pressC.setOrigin(game.pressC.getLocalBounds().width / 2, 0);
    game.pressC.setPosition(500, 250);
    game.scoreText.setFont(game.font);
    game.scoreText.setFillColor(Color::White);
    game.scoreText.setCharacterSize(75);
    game.scoreText.move(30, 0);
    game.highscoreText.setFont(game.font);
    game.highscoreText.setFillColor(Color::White);
    game.highscoreText.move(30, 80);
    resources.backgroundMusic.play();
}
