// header file for Texas HoldEm Game class, derived from 
// base class game, and defines operations of Texas HoldEm game


#include "game.h"  // Base class
#include "texas.h"  
#include "cardset.h"  
#include <vector>
#include <string>

enum class HoldEmState {
    preflop = 0,
    flop = 1,
    turn = 2,
    river = 3,
    undefined = 4
};

class HoldEmGame : public Game {
protected:
    // The current state of the game
    HoldEmState state;

    // The Hold 'Em deck
    TexasDeck deck;
    
    std::vector<CardSet<TexasRank, Suit>> playerHands; 
    CardSet<TexasRank, Suit> shared;  // The shared board of cards

    // Protected method to deal cards
    virtual void deal();

public:
    HoldEmGame(int argc, const char* argv[]);
    void printPlayerHands();
    void collectAll();
    virtual int play();
    virtual ~HoldEmGame() {}
};