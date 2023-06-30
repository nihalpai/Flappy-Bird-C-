// Pipe.hpp

#ifndef PIPE_H     // header guard to prevent multiple inclusions of the pipe.h header 
#define PIPE_H

#include <SFML/Graphics.hpp>  
#include <vector>  

using namespace sf;
using namespace std;

// handles pipes in game
class Pipe {
public:

    static vector<Sprite> screenpipes;     // creates static vector names screenpipes of sprite class 

    Pipe(); 
    void generatePipes(const Texture& texture, int gap);  // spawns new pipes
    void movePipes(float speed);  // moves existing pipes
    void removeOffscreenPipes();  // clears offscreen pipes

};

#endif // PIPE_H
