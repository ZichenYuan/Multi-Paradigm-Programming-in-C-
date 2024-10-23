/**
 * @class Game
 * @brief Abstract base class representing a generic game.
 * 
 * This class provides a framework for implementing various types of games.
 * It includes functionalities to initialize player names from command-line
 * arguments and provides a common interface for derived game classes to 
 * implement the `play` function.
 */
 
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