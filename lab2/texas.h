#ifndef TEXAS_H
#define TEXAS_H

#include <vector>
#include "deck.h"
#include "card.h"
#include "cardsuit.h"


/**
 * @enum TexasRank
 * @brief Represents the ranks used in a standard Texas Hold'em deck.
 * 
 * The TexasRank enumeration defines the standard ranks used in Texas Hold'em poker: 
 * Two through Ace. An additional value, `Undefined`, is used to indicate an uninitialized 
 * or unknown rank.
 */

enum class TexasRank {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
    Undefined
};

std::ostream& operator<<(std::ostream& os, const TexasRank& rank);
TexasRank& operator++(TexasRank& rank);

class TexasDeck: public Deck<TexasRank, Suit>{
    // private:
    //     std::vector<Card<TexasRank, Suit>> mycards;

    public:
        TexasDeck();

        //override
        // void print(std::ostream& os) override;
};

#endif