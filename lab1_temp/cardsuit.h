#ifndef SUIT_H
#define SUIT_H

#include <iostream>

enum class Suit{
    Clubs,
    Diamonds,
    Hearts,
    Spades,
    Undefined
};

std::ostream& operator<<(std::ostream& os, const Suit &Suit);
Suit& operator++(Suit& suit);

#endif