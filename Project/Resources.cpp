// Resources.cpp
#include "Resources.hpp"

// Resources constructor that loads the sounds and textures
Resources::Resources() {

    // load sounds
    sounds.chingBuffer.loadFromFile("./audio/score.wav");
    sounds.hopBuffer.loadFromFile("./audio/flap.wav");
    sounds.dishkBuffer.loadFromFile("./audio/crash.wav");
    
    // set the sound buffers to corresponding sounds
    sounds.ching.setBuffer(sounds.chingBuffer);
    sounds.hop.setBuffer(sounds.hopBuffer);
    sounds.dishk.setBuffer(sounds.dishkBuffer);


    // background music
    backgroundMusic.openFromFile("./audio/background_music.wav");
    backgroundMusic.setLoop(true);


    // load textures
    textures.background.loadFromFile("./images/background.png");
    textures.pipe.loadFromFile("./images/pipe.png");
    textures.gameover.loadFromFile("./images/gameover.png");

    // load the textures of flappy at different stages
    textures.flappy[0].loadFromFile("./images/flappy1.png");
    textures.flappy[1].loadFromFile("./images/flappy2.png");
    textures.flappy[2].loadFromFile("./images/flappy3.png");
}