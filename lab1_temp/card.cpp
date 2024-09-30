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

#endif // TEMPLATE_HEADERS_INCLUDE_SOURCE