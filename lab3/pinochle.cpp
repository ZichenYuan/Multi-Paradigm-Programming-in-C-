#include "pinochle.h"

// Overloaded output stream operator for PinochleRank
// This function converts a PinochleRank enum value to its corresponding string representation.
std::ostream &operator<<(std::ostream& os, const PinochleRank& rank) {
    switch (rank) {
        case PinochleRank::Nine: 
            os << "9";
            break;
        case PinochleRank::Jack: 
            os << "J";
            break;
        case PinochleRank::Queen: 
            os << "Q";
            break;
        case PinochleRank::King: 
            os << "K";
            break;
        case PinochleRank::Ten: 
            os << "10";
            break;
        case PinochleRank::Ace: 
            os << "A";
            break;
        case PinochleRank::Undefined:
        default: 
            os << "?";
            break;
    }
    return os;
}

// Overloaded prefix increment operator for PinochleRank
// This function increments the PinochleRank enum value to the next rank.
PinochleRank& operator++(PinochleRank& rank) {
    switch (rank) {
        case PinochleRank::Nine: 
            rank = PinochleRank::Jack;
            break;
        case PinochleRank::Jack: 
            rank = PinochleRank::Queen;
            break;
        case PinochleRank::Queen: 
            rank = PinochleRank::King;
            break;
        case PinochleRank::King: 
            rank = PinochleRank::Ten;
            break;
        case PinochleRank::Ten: 
            rank = PinochleRank::Ace;
            break;
        case PinochleRank::Ace: 
            rank = PinochleRank::Undefined;
            break;
        case PinochleRank::Undefined:
        default:
            break;
    }
    return rank;
}

// Constructor for PinochleDeck
// This function initializes a PinochleDeck object by creating two copies of each card for each rank and suit.
PinochleDeck::PinochleDeck(){
    for (PinochleRank i = PinochleRank::Nine; i != PinochleRank::Undefined; ++i) {
        for (Suit j = Suit::Clubs; j != Suit::Undefined; ++j) {
            // Pinochle decks contain two copies of each card
            this->cards.push_back(Card<PinochleRank, Suit>(i, j));
            this->cards.push_back(Card<PinochleRank, Suit>(i, j));
        }
    }
}
