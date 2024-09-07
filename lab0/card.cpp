#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE  // Ensure this only compiles when the flag is defined

#include <iostream>
#include "card.h"

//Template shift
template < typename R, typename S >
std::ostream& operator<<(std::ostream& os, const Card< R, S >& card) {
    os << card.rank << " of " << card.suit; 
    return os;
}

#endif // TEMPLATE_HEADERS_INCLUDE_SOURCE