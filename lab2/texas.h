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
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack = 11,
    Queen = 12,
    King = 13,
    Ace = 14, 
    Undefined = 0
};

std::ostream& operator<<(std::ostream& os, const TexasRank& rank);
TexasRank& operator++(TexasRank& rank);
TexasRank operator+(TexasRank rank, int value);

class TexasDeck: public Deck<TexasRank, Suit>{
    // private:
    //     std::vector<Card<TexasRank, Suit>> mycards;

    public:
        TexasDeck();

        //override
        // void print(std::ostream& os) override;
};

#endif
