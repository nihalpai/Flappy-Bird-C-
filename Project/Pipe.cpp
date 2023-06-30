// Pipe.cpp
#include "Pipe.hpp"
#include <stdlib.h> // for rand()

using namespace std;
using namespace sf;

vector<Sprite> Pipe::screenpipes;

Pipe::Pipe() {
    
}

// creates upper and lower pipes
void Pipe::generatePipes(const Texture& texture, int gap) {
    int r = rand() % 275 + 75;
    
    Sprite pipeL;
    pipeL.setTexture(texture);
    pipeL.setPosition(1000, r + gap);
    pipeL.setScale(2, 2);

    Sprite pipeU;
    pipeU.setTexture(texture);
    pipeU.setPosition(1000, r);
    pipeU.setScale(2, -2);

    // adds pipes to the screen
    screenpipes.push_back(pipeL);
    screenpipes.push_back(pipeU);
}

// moves all pipes on screen
void Pipe::movePipes(float speed) {
    for (auto& pipe : screenpipes) {
        pipe.move(-speed, 0);
    }
}

// removes pipes that are not visible
void Pipe::removeOffscreenPipes() {
    auto end_itr = screenpipes.begin();

    for (; end_itr != screenpipes.end(); end_itr++) {
        if (end_itr->getPosition().x > -104) {
            break;
        }
    }

    screenpipes.erase(Pipe::screenpipes.begin(), end_itr);
}
