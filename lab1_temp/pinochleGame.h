#ifndef PINOCHLEGAME_H
#define PINOCHLEGAME_H

#include "game.h"  // Base class
#include "pinochle.h"  // Assume this is provided
#include "card.h"  // Assume this is provided
#include <vector>
#include <iostream>
#include <string>

/**
 * @class PinochleGame
 * @brief Implements a specific game of Pinochle by extending the Game base class.
 * 
 * This class encapsulates the game logic for Pinochle, managing a Pinochle deck and
 * player hands. It provides methods for dealing cards, printing player hands, and 
 * collecting all cards back into the deck. The play method serves as the main entry 
 * point for running the game.
 */

class PinochleGame : public Game {
protected:
    PinochleDeck deck; 
    std::vector< CardSet<PinochleRank, Suit>> playerHands;  
    virtual void deal();

public:
    PinochleGame(int argc, const char* argv[]);
    void printPlayerHands();
    void collectAll();
    virtual int play();
    virtual ~PinochleGame() {};
};

#endif
