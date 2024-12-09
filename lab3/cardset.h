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
#include <functional>

template <typename R, typename S>
class CardSet {
protected:
    // vector to hold card obj
    std::vector<Card<R, S>> cards;

public:

    // type specifier for iterator of cardSet
    typedef typename std::vector<Card<R, S> >::iterator card_iter;
    typedef Card<R, S> card_type;

    // default constructor
    CardSet<R, S>() = default;

    // virtual destructor
    virtual ~CardSet() = default;

    // declare print functions
    void print(std::ostream& os, size_t per_line = 4) const;

    // Checks whether the CardSet is empty
    bool isEmpty();

    //Overloaded operator for transferring cards from one CardSet to another.
    CardSet<R,S> & operator>> (CardSet<R,S> & other);

    // Copy constructor(default), create deep copy of the cards
    CardSet(const CardSet<R, S> & other) = default;


    // get a pointer to the class protected vector data member (lab2)
    // static std::vector<Card<R, S>>* getCardsPtr(CardSet<R, S>& instance) {
    //     return &instance.cards;
    // }

    // static const std::vector<Card<R, S>>* getCardsPtr(const CardSet<R, S>& instance) {
    //     return &instance.cards;
    // }

    // New accessor of iterators
    card_iter begin();
    card_iter end();

    void sort();

    void add_cards(CardSet<R, S> &other);

    void collect(CardSet<R, S> &other);

    void collect_if(CardSet<R, S> &deck, std::function<bool(card_type&)> predicate);

    bool request(CardSet<R, S> &other, R rank);

    // access the card by index
    Card<R, S>& operator[](std::size_t index) { return cards[index]; }
    const Card<R, S>& operator[](std::size_t index) const { return cards[index]; }

    // get the size of the cardset
    std::size_t size() const { return cards.size(); }
};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "cardset.cpp"
#endif

#endif // CARDSET_H
