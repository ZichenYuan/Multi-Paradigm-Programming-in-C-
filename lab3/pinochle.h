#ifndef PINOCHLE_DECK_H
#define PINOCHLE_DECK_H

#include <iostream>
#include <vector>
#include "deck.h"
#include "card.h"
#include "cardsuit.h"


/**
 * @enum PinochleRank
 * @brief Represents the ranks used in a Pinochle deck.
 * 
 * The Pinochle deck uses a unique set of card ranks, including: Nine, Jack, Queen, 
 * King, Ten, and Ace. An additional value, `Undefined`, is used to indicate an 
 * uninitialized or unknown rank.
 */

enum class PinochleRank { 
    Nine = 0, 
    Ten = 1, 
    Jack = 2, 
    Queen = 3, 
    King = 4, 
    Ace = 5, 
    Undefined 
};

std::ostream& operator<<(std::ostream& os, const PinochleRank& rank);
PinochleRank& operator++(PinochleRank& rank);


/**
 * @class PinochleDeck
 * @brief Represents a specialized deck of Pinochle cards.
 * 
 * PinochleDeck is a derived class from `Deck` that uses PinochleRank for ranks 
 * and Suit for suits. A standard Pinochle deck contains two copies of each rank and 
 * suit combination, resulting in a 48-card deck. This class provides functionality 
 * specific to a Pinochle game.
 */
class PinochleDeck: public Deck<PinochleRank, Suit> {
    public:
        PinochleDeck();
};

#endif 