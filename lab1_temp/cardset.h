#ifndef CARDSET_H
#define CARDSET_H

#include <vector>
#include "card.h"

template <typename R, typename S>
class CardSet {
protected:
    std::vector<Card<R, S>> cards;

public:
    void print(std::ostream& os, size_t per_line = 4);

    bool isEmpty();

    CardSet<R,S> & operator>> (CardSet<R,S> & other);
    
};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "cardset.cpp"
#endif

#endif // CARDSET_H