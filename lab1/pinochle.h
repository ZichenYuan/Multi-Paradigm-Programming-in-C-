#ifndef PINOCHLE_DECK_H
#define PINOCHLE_DECK_H

#include <iostream>
#include <vector>
#include "deck.h"
#include "card.h"
#include "cardsuit.h"


enum class PinochleRank { 
    Nine, 
    Jack, 
    Queen, 
    King, 
    Ten, 
    Ace, 
    Undefined 
};

std::ostream& operator<<(std::ostream& os, const PinochleRank& rank);
PinochleRank& operator++(PinochleRank& rank);


//derivded class
class PinochleDeck: public Deck {
    private:
        std::vector< Card < PinochleRank, Suit > > mycards;

    public:
        PinochleDeck();
        void print(std::ostream& os);
};

#endif 