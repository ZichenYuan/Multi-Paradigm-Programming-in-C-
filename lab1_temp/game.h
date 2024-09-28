// Header file for game base class
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <string>

class Game {
    protected:
        std::vector<std::string> playerNames;
    public:
        Game(int argc, const char* argv[]);

        virtual int play() = 0;

        virtual ~Game() {};

        int endGamePrompt();
        
};

#endif