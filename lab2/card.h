// Header file for card, 

#ifndef CARD_H
#define CARD_H

#include <iostream>


template <typename R, typename S>
struct Card {
    R rank;
    S suit;

    // Constructor
    Card(R r, S s) : rank(r), suit(s) {}

    // accessor
    R getRank() const { return rank; }
    S getSuit() const { return suit; }
};

template <typename R, typename S>
std::ostream& operator<<(std::ostream& os, const Card<R, S>& card);

// Compare the rank of two cards, return true if first card is less than or equal to the second
template <typename R, typename S>
bool rankBasedCompare(const Card<R, S>& card_1, const Card<R, S>& card_2);

// Compared the suit of cards, return true if first card is less than or equal to the second
template <typename R, typename S>
bool suitBasedCompare(const Card<R, S>& card_1, const Card<R, S>& card_2);

template <typename R, typename S>
bool operator ==(const Card<R, S>& lhs, const Card<R, S>& rhs);

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "card.cpp"  
#endif

#endif // CARD_H
