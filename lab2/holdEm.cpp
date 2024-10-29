// Source file for Texas Hold'Em. Defines necessary game logics and operators

#include "holdEm.h"

std::ostream& operator<<(std::ostream& os, const HoldEmRank& rank){
    switch(rank){
        case HoldEmRank::Two: 
            os << "2"; 
            break;
        case HoldEmRank::Three: 
            os << "3"; 
            break;
        case HoldEmRank::Four: 
            os << "4"; 
            break;
        case HoldEmRank::Five: 
            os << "5"; 
            break;
        case HoldEmRank::Six: 
            os << "6"; 
            break;
        case HoldEmRank::Seven: 
            os << "7"; 
            break;
        case HoldEmRank::Eight: 
            os << "8"; 
            break;
        case HoldEmRank::Nine: 
            os << "9"; 
            break;
        case HoldEmRank::Ten: 
            os << "10"; 
            break;
        case HoldEmRank::Jack: 
            os << "J"; 
            break;
        case HoldEmRank::Queen: 
            os << "Q"; 
            break;
        case HoldEmRank::King: 
            os << "K"; 
            break;
        case HoldEmRank::Ace: 
            os << "A"; 
            break;
        case HoldEmRank::Undefined:
        default:
            os << "?";
            break;
    }
    return os;
}

HoldEmRank& operator++(HoldEmRank& rank){
    switch (rank) {
        case HoldEmRank::Two: 
            rank = HoldEmRank::Three; 
            break;
        case HoldEmRank::Three: 
            rank = HoldEmRank::Four; 
            break;
        case HoldEmRank::Four: 
            rank = HoldEmRank::Five; 
            break;
        case HoldEmRank::Five: 
            rank = HoldEmRank::Six; 
            break;
        case HoldEmRank::Six: 
            rank = HoldEmRank::Seven; 
            break;
        case HoldEmRank::Seven: 
            rank = HoldEmRank::Eight; 
            break;
        case HoldEmRank::Eight: 
            rank = HoldEmRank::Nine; 
            break;
        case HoldEmRank::Nine: 
            rank = HoldEmRank::Ten; 
            break;
        case HoldEmRank::Ten: 
            rank = HoldEmRank::Jack; 
            break;
        case HoldEmRank::Jack: 
            rank = HoldEmRank::Queen; 
            break;
        case HoldEmRank::Queen: 
            rank = HoldEmRank::King; 
            break;
        case HoldEmRank::King: 
            rank = HoldEmRank::Ace; 
            break;
        case HoldEmRank::Ace: 
            rank = HoldEmRank::Undefined; 
            break;
        case HoldEmRank::Undefined:
        default: break;
    }
    return rank;
}

HoldEmRank operator+(HoldEmRank rank, int value) {
    int rankValue = static_cast<int>(rank);
    rankValue += value;

    
    if (rankValue > static_cast<int>(HoldEmRank::Ace) || rankValue < static_cast<int>(HoldEmRank::Two)) {
        return HoldEmRank::Undefined; 
    }

    return static_cast<HoldEmRank>(rankValue);
}

HoldEmDeck::HoldEmDeck(){
    for (HoldEmRank i = HoldEmRank::Two; i!=HoldEmRank::Undefined;++i){
        for (Suit j = Suit::Clubs; j!=Suit::Undefined;++j){
            // mycards.push_back(Card(i,j));
            this->cards.push_back(Card<HoldEmRank, Suit>(i, j));
        }
    }
}
