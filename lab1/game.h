// Header file for game base class
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

class Game {
    protected:
        std::vector<std::string> playerNames;
    public:
        Game(int argc, char* argv[]);

        virtual int play() = 1;

        virtual ~Game() {};
        
}

#endif