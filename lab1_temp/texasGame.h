/**
 * @enum HoldEmState
 * @brief Represents the different stages of a Texas Hold'em game.
 * 
 * This enumeration defines the various states of the game, including:
 * - `preflop`: The initial stage before any community cards are revealed.
 * - `flop`: The stage where the first three community cards are dealt.
 * - `turn`: The stage where the fourth community card is dealt.
 * - `river`: The final stage where the fifth community card is dealt.
 * - `undefined`: Represents an uninitialized or unknown state.
 */
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


/**
 * @class HoldEmGame
 * @brief Implements a Texas Hold'em poker game by extending the base Game class.
 * 
 * This class manages the state and logic of a Texas Hold'em game, including 
 * dealing cards, maintaining player hands, managing shared cards, and handling 
 * the different stages of the game. It provides a `play()` method that serves 
 * as the main game loop for running the game.
 */
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