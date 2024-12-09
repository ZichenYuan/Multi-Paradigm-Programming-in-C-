#ifndef PINOCHLEGAME_H
#define PINOCHLEGAME_H

#include "game.h"  // Base class
#include "pinochle.h"  // Assume this is provided
#include "card.h"  // Assume this is provided
#include <vector>
#include <iostream>
#include <string>

// enum class for pinochle melds
enum class PinochleMelds {
    dix = 0,
    offsuitmarriage,
    fortyjacks,
    pinochle,
    insuitmarriage,
    sixtyqueens,
    eightykings,
    hundredaces,
    insuitrun,
    doublepinochle,
    fourhundredjacks,
    sixhundredqueens,
    eighthundredkings,
    thousandaces,
    insuitdoublerun
};

/**
* @brief print meld name and point value
* @param os the stream to print
* @param meld the meld to print
* @return std::ostream & the reference of the input stream
*/
std::ostream &operator<<(std::ostream &os, const PinochleMelds &meld);

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
private:
    bool hasOne(std::vector< Card<PinochleRank, Suit> > &cards, PinochleRank rank, Suit suit);
    bool hasTwo(std::vector< Card<PinochleRank, Suit> > &cards, PinochleRank rank, Suit suit);
    bool checkOneWholeSuite(std::vector< Card<PinochleRank, Suit> > &cards, PinochleRank rank);
    bool checkTwoWholeSuites(std::vector< Card<PinochleRank, Suit> > &cards, PinochleRank rank);
    void suit_independent_evaluation(const CardSet<PinochleRank, Suit>& playerHand, std::vector<PinochleMelds>& melds);
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
    
    // Static list, declare the meldname
    static const char* meldNames[];
    
    // Static list, declare the static array of point values for the PinochleMelds enum class
    static const unsigned int meldPoints[];
};

#endif
