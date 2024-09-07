#include "texas.h"

std::ostream& operator<<(std::ostream& os, const TexasRank& rank){
    switch(rank){
        case TexasRank::Two: 
            os << "2"; 
            break;
        case TexasRank::Three: 
            os << "3"; 
            break;
        case TexasRank::Four: 
            os << "4"; 
            break;
        case TexasRank::Five: 
            os << "5"; 
            break;
        case TexasRank::Six: 
            os << "6"; 
            break;
        case TexasRank::Seven: 
            os << "7"; 
            break;
        case TexasRank::Eight: 
            os << "8"; 
            break;
        case TexasRank::Nine: 
            os << "9"; 
            break;
        case TexasRank::Ten: 
            os << "10"; 
            break;
        case TexasRank::Jack: 
            os << "J"; 
            break;
        case TexasRank::Queen: 
            os << "Q"; 
            break;
        case TexasRank::King: 
            os << "K"; 
            break;
        case TexasRank::Ace: 
            os << "A"; 
            break;
        case TexasRank::Undefined:
        default:
            os << "?";
            break;
    }
    return os;
}

TexasRank& operator++(TexasRank& rank){
    switch (rank) {
        case TexasRank::Two: 
            rank = TexasRank::Three; 
            break;
        case TexasRank::Three: 
            rank = TexasRank::Four; 
            break;
        case TexasRank::Four: 
            rank = TexasRank::Five; 
            break;
        case TexasRank::Five: 
            rank = TexasRank::Six; 
            break;
        case TexasRank::Six: 
            rank = TexasRank::Seven; 
            break;
        case TexasRank::Seven: 
            rank = TexasRank::Eight; 
            break;
        case TexasRank::Eight: 
            rank = TexasRank::Nine; 
            break;
        case TexasRank::Nine: 
            rank = TexasRank::Ten; 
            break;
        case TexasRank::Ten: 
            rank = TexasRank::Jack; 
            break;
        case TexasRank::Jack: 
            rank = TexasRank::Queen; 
            break;
        case TexasRank::Queen: 
            rank = TexasRank::King; 
            break;
        case TexasRank::King: 
            rank = TexasRank::Ace; 
            break;
        case TexasRank::Ace: 
            rank = TexasRank::Undefined; 
            break;
        case TexasRank::Undefined:
        default: break;
    }
    return rank;
}


TexasDeck::TexasDeck(){
    for (TexasRank i = TexasRank::Two; i!=TexasRank::Undefined;++i){
        for (Suit j = Suit::Clubs; j!=Suit::Undefined;++j){
            mycards.push_back(Card(i,j));
        }
    }
}

void TexasDeck::print(std::ostream& os){
    int count = 0;
    for (const auto& card: mycards) {
        os << card << " ";
        if (++count % 4 == 0) {
            os << "\n";
        }
    }
    os << std::endl;
}