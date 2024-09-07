
#include <iostream>
#include "cardsuit.h"

std::ostream &operator<<(std::ostream& os, const Suit& suit){
    switch(suit){
        case Suit::Clubs:
            os << "C";
            break;
        case Suit::Diamonds:
            os << "D";
            break;
        case Suit::Hearts:
            os << "H";
            break;
        case Suit::Spades:
            os << "S";
            break;
        case Suit::Undefined:
        default:
            os << "?";
            break;
    }
    return os;
}

Suit& operator++(Suit& suit){
     switch (suit) {
        case Suit::Clubs:
            suit = Suit::Diamonds;
            break;
        case Suit::Diamonds:
            suit = Suit::Hearts;
            break;
        case Suit::Hearts:
            suit = Suit::Spades;
            break;
        case Suit::Spades:
            suit = Suit::Undefined;
            break;
        case Suit::Undefined:
        default:
            // Stay the same if undefined
            break;
    }
    return suit;
}
