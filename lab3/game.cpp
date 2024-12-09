// Defines the constructor for the base game class

#include "game.h"

Game::Game(int argc, const char* argv[]) {
    // Starting from index 2, skipping the program name and game name (argv[0] and argv[1])
    for (int i = 2; i < argc; ++i) {
        playerNames.push_back(std::string(argv[i]));  
    }
}



int Game::endGamePrompt(){
    std::string input;
    std::cout << "Do you want to end the game? (Type 'yes' to end): ";
    std::getline(std::cin, input);

    return (input == "yes");

}