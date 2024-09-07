#ifndef DECK_H
#define DECK_H
#include <iostream>

class Deck {
public:
    virtual void print(std::ostream& os) = 0;
    virtual ~Deck() = default;
};


#endif