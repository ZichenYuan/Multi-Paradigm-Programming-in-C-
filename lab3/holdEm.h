#ifndef TEXAS_H
#define TEXAS_H

#include <vector>
#include "deck.h"
#include "card.h"
#include "cardsuit.h"


/**
 * @enum HoldEmRank
 * @brief Represents the ranks used in a standard Texas Hold'em deck.
 * 
 * The HoldEmRank enumeration defines the standard ranks used in Texas Hold'em poker: 
 * Two through Ace. An additional value, `Undefined`, is used to indicate an uninitialized 
 * or unknown rank.
 */

enum class HoldEmRank {
    Two = 0,
    Three = 1,
    Four = 2,
    Five = 3,
    Six = 4,
    Seven = 5,
    Eight = 6,
    Nine = 7,
    Ten = 8,
    Jack = 9,
    Queen = 10,
    King = 11,
    Ace = 12, 
    Undefined
};

std::ostream& operator<<(std::ostream& os, const HoldEmRank& rank);
HoldEmRank& operator++(HoldEmRank& rank);
HoldEmRank operator+(HoldEmRank rank, int value);

class HoldEmDeck: public Deck<HoldEmRank, Suit>{
    public:
        HoldEmDeck();
};

#endif
