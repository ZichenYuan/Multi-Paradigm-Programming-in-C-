// Defines card, each card has rank and suit properties
// as defined by the template

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE  

#include <iostream>
#include "card.h"

//Template shift
template < typename R, typename S >
std::ostream& operator<<(std::ostream& os, const Card< R, S >& card) {
    os << card.rank << " of " << card.suit; 
    return os;
}

// Implementation of the rank base comparison
// True if first less than second
template <typename R, typename S>
bool rankBasedCompare(const Card<R, S>& card_1, const Card<R, S>& card_2){
    if (card_1.rank < card_2.rank) {
        return true;
    } else if (card_1.rank == card_2.rank) {
        return card_1.suit < card_2.suit;
    }
    return false;
}

// Implementation of the suit base comparison
template <typename R, typename S>
bool suitBasedCompare(const Card<R, S>& card_1, const Card<R, S>& card_2){
    if (card_1.suit < card_2.suit) {
        return true;
    } else if (card_1.suit == card_2.suit) {
        return card_1.rank < card_2.rank;
    }
    return false;
}

template <typename R, typename S>
bool operator ==(const Card<R, S>& lhs, const Card<R, S>& rhs) {
    return lhs.rank == rhs.rank && lhs.suit == rhs.suit;
};

#endif // TEMPLATE_HEADERS_INCLUDE_SOURCE
