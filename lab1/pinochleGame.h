#ifndef PINOCHLEGAME_H
#define PINOCHLEGAME_H

#include "game.h"  // Base class
#include "pinochle.h"  // Assume this is provided
#include "card.h"  // Assume this is provided
#include <vector>
#include <string>

class PinochleGame : public Game {
protected:
    PinochleDeck deck; 
    std::vector<Card<PinochleRank, Suit>> playerHands;  
    virtual void deal();

public:
    PinochleGame(int argc, const char* argv[]);
    virtual int play();
    virtual ~PinochleGame() {}
};

#endif
