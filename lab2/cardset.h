/**
 * @class CardSet
 * @brief Represents a collection of cards that can be managed and manipulated.
 * 
 * This class provides a base for storing and operating on a set of cards, 
 * including functionality to check if the set is empty, print the cards, and 
 * transfer cards between sets using the overloaded operator>>.
 * 
 * The CardSet class uses template parameters R and S, allowing for flexible 
 * card representation (e.g., integer ranks, character suits, etc.). It can 
 * be extended to represent more specific types of card collections, such as a 
 * deck of cards or a player's hand.
 * 
 * @tparam R Rank type of the card (e.g., int, enum, etc.)
 * @tparam S Suit type of the card (e.g., char, enum, etc.)
 */

#ifndef CARDSET_H
#define CARDSET_H

#include <vector>
#include "card.h"

template <typename R, typename S>
class CardSet {
protected:
    // vector to hold card obj
    std::vector<Card<R, S>> cards;

public:
    // default constructor
    CardSet<R, S>() = default;

    // virtual destructor
    virtual ~CardSet();

    // declare print functions
    void print(std::ostream& os, size_t per_line = 4);

    // Checks whether the CardSet is empty
    bool isEmpty();

    //Overloaded operator for transferring cards from one CardSet to another.
    CardSet<R,S> & operator>> (CardSet<R,S> & other);

    // Copy constructor(default), create deep copy of the cards
    CardSet(const CardSet<R, S> & other) = default;

    // Get a pointer to the class protected vector data member
    static std::vector<Card<R, S> > CardSet<R, S>::* getCardsPtr();

};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "cardset.cpp"
#endif

#endif // CARDSET_H
