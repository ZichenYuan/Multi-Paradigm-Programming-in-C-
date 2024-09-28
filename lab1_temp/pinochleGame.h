// header file for Pinochle Game class, derived from 
// base class game, and defines operations of pinochle game

#ifndef PINOCHLEGAME_H
#define PINOCHLEGAME_H

#include "game.h"  // Base class
#include "pinochle.h"  // Assume this is provided
#include "card.h"  // Assume this is provided
#include <vector>
#include <iostream>
#include <string>


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
