#ifndef TEXAS_H
#define TEXAS_H

#include <vector>
#include "deck.h"
#include "card.h"
#include "cardsuit.h"

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

class TexasDeck: public Deck{
    private:
        std::vector<Card<TexasRank, Suit>> mycards;

    public:
        TexasDeck();

        //override
        void print(std::ostream& os) override;
};

#endif