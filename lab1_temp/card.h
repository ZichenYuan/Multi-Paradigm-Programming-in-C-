#ifndef CARD_H
#define CARD_H

#include <iostream>


template <typename R, typename S>
struct Card {
    R rank;
    S suit;

    // Constructor
    Card(R r, S s) : rank(r), suit(s) {}
};

template <typename R, typename S>
std::ostream& operator<<(std::ostream& os, const Card<R, S>& card);

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "card.cpp"  
#endif

#endif // CARD_H
