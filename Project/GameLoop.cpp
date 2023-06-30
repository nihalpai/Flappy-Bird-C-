// GameLoop.cpp
#include "GameLoop.hpp"

using namespace sf;
using namespace std;

// constructor setting up the game window and initial game state
GameLoop::GameLoop() : window(VideoMode(1000, 600), "Flappy Bird") {

    // limit the framerate and disable key repeat
    window.setFramerateLimit(50);
    window.setKeyRepeatEnabled(false);
    srand(time(0));  // Set random seed

    // call to initialize game state
    ::initializeGame(window, game, flappy, pipes, resources);
}

// function to handle user events
void GameLoop::handleEvents() {

    Event event;
    while (window.pollEvent(event)) {
        // handle window close event
        if (event.type == Event::Closed) {
            window.close();
        }
        // hqandle flapping event (spacebar press)
        else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {

            // if the game state is waiting, start the game
            if (game.gameState == waiting) {
                game.gameState = started;
            }
            // if the game has started, make the bird flap
            if (game.gameState == started) {

                flappy.v = -8;  // update bird's velocity
                resources.sounds.hop.play();  // play hopping sound
            }
        // handle game restart event (pressing 'C' when game is over)
        } else if (event.type == Event::KeyPressed && event.key.code == Keyboard::C && game.gameState == gameover) {

            // teset game state
            game.gameState = waiting;
            flappy.sprite.setPosition(250, 300);  // teset bird position
            game.score = 0;  // reset score
            Pipe::screenpipes.clear();  // clear pipes
        }
    }
}

// function to update game state
void GameLoop::update() {

    // set flappy bird texture
    flappy.sprite.setTexture(resources.textures.flappy[1]);
    
    // update score and highscore text
    game.scoreText.setString(to_string(game.score));
    game.highscoreText.setString("HI " + to_string(game.highscore));

    // get flappy bird's position and dimensions
    float fx = flappy.sprite.getPosition().x;
    float fy = flappy.sprite.getPosition().y;
    float fw = 34 * flappy.sprite.getScale().x;
    float fh = 24 * flappy.sprite.getScale().y;

    // update flappy bird's frame for animation
    if (game.gameState == waiting || game.gameState == started) {
        
        if (game.frames % 6 == 0) {
            flappy.frame += 1;
        }
        if (flappy.frame == 3) {
            flappy.frame = 0;
        }
    }

    // set flappy bird's texture based on frame
    flappy.sprite.setTexture(resources.textures.flappy[flappy.frame]);

    // handle bird movement
    if (game.gameState == started) {

        flappy.sprite.move(0, flappy.v);
        flappy.v += 0.5;  // apply gravity to bird's vertical velocity
    }

    // handle bird collision with top and bottom of window
    if (game.gameState == started) {

        if (fy < 0) {
            flappy.sprite.setPosition(250, 0);
            flappy.v = 0;
        } 
        else if (fy > 600) {
            flappy.v = 0;
            game.gameState = gameover;
            resources.sounds.dishk.play();  // play crash sound
        }
    }

    // score update and highscore check
    for (vector<Sprite>::iterator itr = Pipe::screenpipes.begin(); itr != Pipe::screenpipes.end(); itr++) {
        
        if (game.gameState == started && (*itr).getPosition().x == 250) {
            game.score++;  // Increase score
            resources.sounds.ching.play();  // play score sound

            if (game.score > game.highscore) {
                game.highscore = game.score;  // update highscore
            }

            break;
        }
    }

    // generate new pipes every 90 frames
    if (game.gameState == started && game.frames % 90 == 0) {
        pipes.generatePipes(resources.textures.pipe, 200);
    }

    // move pipes
    if (game.gameState == started) {
        pipes.movePipes(3.0);
    }

    // remove offscreen pipes
    pipes.removeOffscreenPipes();

    // handle bird collision with pipes
    if (game.gameState == started) {
        for (vector<Sprite>::iterator itr = Pipe::screenpipes.begin(); itr != Pipe::screenpipes.end(); itr++) {

            float px, py, pw, ph;

            // get pipe's position and dimensions
            if ((*itr).getScale().y > 0) {
                px = (*itr).getPosition().x;
                py = (*itr).getPosition().y;
                pw = 52 * (*itr).getScale().x;
                ph = 320 * (*itr).getScale().y;
            } else {
                pw = 52 * (*itr).getScale().x;
                ph = -320 * (*itr).getScale().y;
                px = (*itr).getPosition().x;
                py = (*itr).getPosition().y - ph;
            }

            // if collision happens, set the game state to gameover and play crash sound
            if (collides(fx, fy, fw, fh, px, py, pw, ph)) {
                game.gameState = gameover;
                resources.sounds.dishk.play();  // Play crash sound
            }
        }
    }

    game.frames++;  // increase frame count
}

// function to render current game state
void GameLoop::render() {

    // clear the window and draw background
    window.clear();
    window.draw(game.background[0]);
    window.draw(game.background[1]);
    window.draw(game.background[2]);
    window.draw(flappy.sprite);  // draw flappy bird

    // draw pipes
    for (vector<Sprite>::iterator itr = Pipe::screenpipes.begin(); itr != Pipe::screenpipes.end(); itr++) {

        window.draw(*itr);
    }

    // draw score and highscore text
    window.draw(game.scoreText);
    window.draw(game.highscoreText);

    // if gameover, draw gameover text and 'Press C to continue' text
    if (game.gameState == gameover) {
        window.draw(game.gameover);

        if (game.frames % 60 < 30) {
            window.draw(game.pressC);
        }
    }
    window.display();  // display all changes to window
}

// main game loop function
void GameLoop::run() {

    // as long as the game window is open, handle events, update the game state, and render the game state
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}
