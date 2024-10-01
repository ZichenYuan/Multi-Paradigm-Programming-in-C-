/**
 * @file main.cpp
 * @brief Entry point for the card game application.
 * 
 * This file contains the main function, which acts as the starting point for the program.
 * 
 * The game types supported are:
 *  - "Pinochle"
 *  - "HoldEm"
 * 
 * Return codes:
 *  - 0: Success
 *  - 1: Incorrect usage of command-line arguments
 *  - 2: Unknown game type
 *  - 3: Game creation failed
 * 
 * @param argc The number of command-line arguments
 * @param argv The array of command-line arguments
 * @return An integer status code representing success or failure
 */
 
 #include "game.h"
#include "pinochleGame.h"
#include "texasGame.h"
#include <memory>
#include <iostream>
#include <string>

const int SUCCESS = 0;
const int ERROR_INCORRECT_USAGE = 1;
const int ERROR_UNKNOWN_GAME_TYPE = 2;
const int ERROR_GAME_CREATION_FAILED = 3;

std::shared_ptr<Game> create(int argc, const char *argv[]);

int main(int argc, const char *argv[]) {
    // Check for enough arguments
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <GameName> <Player1> <Player2> ..." << std::endl;
        return ERROR_INCORRECT_USAGE;
    }

    std::string gameName = argv[1];

    // Check for Pinochle game type and ensure exactly four player names
    if (gameName == "Pinochle") {
        if (argc != 6) { // 1 for executable name, 1 for game name, 4 for player names
            std::cout << "Usage: " << argv[0] << " Pinochle <Player1> <Player2> <Player3> <Player4>" << std::endl;
            return ERROR_INCORRECT_USAGE;
        }
    }
    // Check for "HoldEm" game type and ensure there are 2 ~ 9 players
    else if (gameName == "HoldEm") {
        if (argc < 4 || argc > 11) { // 1 for executable name, 1 for game name, 2-9 for player names
            std::cout << "Usage: " << argv[0] << " HoldEm <Player1> <Player2> [<Player3> ... <Player9>]" << std::endl;
            return ERROR_INCORRECT_USAGE;
        }
    }
    // Return statement, if game type is unknown
    else {
        std::cerr << "Error: Unknown game type \"" << gameName << "\"." << std::endl;
        return ERROR_UNKNOWN_GAME_TYPE;
    }

    // Create the game using the factory function
    std::shared_ptr<Game> game = create(argc, argv);

    // Check if the game was created successfully
    if (game) {
        return game->play(); // Start the game and return the result
    } else {
        std::cerr << "Error: Game creation failed." << std::endl;
        return ERROR_GAME_CREATION_FAILED;
    }
}

// Factory function implementation
std::shared_ptr<Game> create(int argc, const char *argv[]) {
    std::shared_ptr<Game> game;

    std::string gameName = argv[1];
    if (gameName == "Pinochle") {
        game = std::make_shared<PinochleGame>(argc, argv);
    } else if (gameName == "HoldEm") {
        game = std::make_shared<HoldEmGame>(argc, argv);
    }

    return game;
}
