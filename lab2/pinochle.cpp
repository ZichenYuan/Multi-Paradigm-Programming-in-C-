#include "pinochle.h"

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

//constructor 
PinochleDeck::PinochleDeck(){
    for (PinochleRank i = PinochleRank::Nine; i!=PinochleRank::Undefined;++i){
        for (Suit j = Suit::Clubs; j!=Suit::Undefined;++j){
            // mycards.push_back(Card(i,j));
            this->cards.push_back(Card<PinochleRank, Suit>(i, j));
            this->cards.push_back(Card<PinochleRank, Suit>(i, j));
        }
    }
}

// removed because print define in cardset base class
// void PinochleDeck::print(std::ostream& os){
//     int count = 0;
//     for (const auto& card: mycards) {
//         os << card << "  ";
//         if (++count % 4 == 0) {
//             os << "\n";
//         }
//     }
//     os << std::endl;
// }