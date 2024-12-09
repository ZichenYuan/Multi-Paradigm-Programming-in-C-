#ifndef SUIT_H
#define SUIT_H

#include <iostream>

/**
 * @enum Suit
 * @brief Represents the suits of a standard deck of playing cards.
 * 
 * This enumeration defines the four traditional suits used in card games: 
 * Clubs, Diamonds, Hearts, and Spades. It also includes an additional value, 
 * `Undefined`, for representing an uninitialized or unknown suit.
 */
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