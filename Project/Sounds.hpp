// Sounds.hpp
#pragma once  // prevents multiple inclusions of the header
#include <SFML/Audio.hpp>  // SFML library for audio manipulation

using namespace sf;  

// structure storing the sounds and buffers used in the game
struct Sounds {
    SoundBuffer chingBuffer;  
    SoundBuffer hopBuffer;    
    SoundBuffer dishkBuffer;  
    Sound ching;  // sound object for 'ching'
    Sound hop;  // sound object for 'hop'
    Sound dishk;  // sound object for 'dishk'
};

