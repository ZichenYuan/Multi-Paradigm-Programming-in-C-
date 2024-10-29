/**
 * @class Deck
 * @brief Represents a deck of cards that inherits from the CardSet class.
 * 
 * This class provides functionality to shuffle a deck of cards and 
 * collect cards from another card set. It utilizes template parameters 
 * R and S to allow for flexible card representation.
 * 
 * @tparam R Rank type of the card (e.g., int, enum, etc.)
 * @tparam S Suit type of the card (e.g., char, enum, etc.)
 */

#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <random>
#include <algorithm>

#include "cardset.h"


template <typename R, typename S>
class Deck : public CardSet<R, S> {
    public:
    Deck() {}
    ~Deck() {}
    void shuffle(){
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(this->cards.begin(), this->cards.end(), g);
    }

    void collect(CardSet<R, S> &cardset){
        try{
            while (!cardset.isEmpty()){
                cardset >> *this;
            }
        }
        catch (std::runtime_error &e){
            std::cout << e.what() << std::endl;
        }
    }
};

#endif // DECK_H