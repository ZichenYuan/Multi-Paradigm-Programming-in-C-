#include "uno.h"

// operator<< for Color
std::ostream& operator<<(std::ostream& os, const UnoColor& color) {
    switch (color) {
        case UnoColor::red:       
            os << "Red";
            break;
        case UnoColor::blue:      
            os << "Blue";
            break;
        case UnoColor::green:    
            os << "Green";
            break;
        case UnoColor::yellow:    
            os << "Yellow";
            break;
        case UnoColor::black:    
            os << "Black";
            break;
        case UnoColor::Undefined: 
        default:               
            os << "?";
            break;
    }
    return os;
}

// Overload operator<< for UnoRank
std::ostream& operator<<(std::ostream& os, const UnoRank& rank) {
    switch (rank) {
        case UnoRank::zero:    
            os << "0";
            break;
        case UnoRank::one:     
            os << "1";
            break;
        case UnoRank::two:     
            os << "2";
            break;
        case UnoRank::three:   
            os << "3";
            break;
        case UnoRank::four:    
            os << "4";
            break;
        case UnoRank::five:    
            os << "5";
            break;
        case UnoRank::six:     
            os << "6";
            break;
        case UnoRank::seven:   
            os << "7";
            break;
        case UnoRank::eight:   
            os << "8";
            break;
        case UnoRank::nine:    
            os << "9";
            break;
        case UnoRank::skip:    
            os << "Skip";
            break;
        case UnoRank::reverse: 
            os << "Reverse";
            break;
        case UnoRank::drawtwo: 
            os << "Draw Two";
            break;
        case UnoRank::drawfour:
            os << "Draw Four";
            break;
        case UnoRank::wild:    
            os << "Wild";
            break;
        case UnoRank::blank:   
            os << "Blank";
            break;
        case UnoRank::Undefined:
            
        default:               
            os << "?";
            break;
    }
    return os;
}

// Overload operator++ for Color
UnoColor& operator++(UnoColor& color) {
    switch (color) {
        case UnoColor::red:       
            color = UnoColor::blue;
            break;
        case UnoColor::blue:      
            color = UnoColor::green;
            break;
        case UnoColor::green:     
            color = UnoColor::yellow;
            break;
        case UnoColor::yellow:    
            color = UnoColor::black;
            break;
        case UnoColor::black:     
            color = UnoColor::Undefined;
            break;
        case UnoColor::Undefined: 
        default:               
            break;
    }
    return color;
}

// Overload operator++ for UnoRank
UnoRank& operator++(UnoRank& rank) {
    switch (rank) {
        case UnoRank::zero:    
            rank = UnoRank::one;
            break;
        case UnoRank::one:      
            rank = UnoRank::two;
            break;
        case UnoRank::two:     
            rank = UnoRank::three;
            break;
        case UnoRank::three:   
            rank = UnoRank::four;
            break;
        case UnoRank::four:    
            rank = UnoRank::five;
            break;
        case UnoRank::five:    
            rank = UnoRank::six;
            break;
        case UnoRank::six:     
            rank = UnoRank::seven;
            break;
        case UnoRank::seven:   
            rank = UnoRank::eight;
            break;
        case UnoRank::eight:   
            rank = UnoRank::nine;
            break;
        case UnoRank::nine:    
            rank = UnoRank::skip;
            break;
        case UnoRank::skip:    
            rank = UnoRank::reverse;
            break;
        case UnoRank::reverse: 
            rank = UnoRank::drawtwo;
            break;
        case UnoRank::drawtwo: 
            rank = UnoRank::drawfour;
            break;
        case UnoRank::drawfour:
            rank = UnoRank::wild;
            break;
        case UnoRank::wild:    
            rank = UnoRank::blank;
            break;
        case UnoRank::blank:   
            rank = UnoRank::Undefined;
            break;
        case UnoRank::Undefined:

        default:               
            break;
    }
    return rank;
}


// Default constructor for UnoDeck class
// one red, one blue, one green, and one yellow card of rank zero;
// two red, two blue, two green, and two yellow cards of each rank one through drawtwo; and
// four black cards of each rank drawfour through blank.
const int FOUR_CARDS = 4;
UnoDeck::UnoDeck() {
    for (UnoColor c = UnoColor::red; c != UnoColor::black; ++c) {
        Card<UnoRank, UnoColor> unoCard(UnoRank::zero, c);
        cards.push_back(unoCard);
    }

    for (UnoRank i= UnoRank::one; i!=UnoRank::drawfour; ++i){
        for (UnoColor c = UnoColor::red; c != UnoColor::black; ++c) {
            Card<UnoRank, UnoColor> unoCard(i, c);
            cards.push_back(unoCard);
            cards.push_back(unoCard);
        }
    }

    for (UnoRank i= UnoRank::drawfour; i!=UnoRank::Undefined; ++i){
        Card<UnoRank, UnoColor> unoCard(i, UnoColor::black);
        for (int j = 0; j < FOUR_CARDS; ++j) {
            cards.push_back(unoCard);
        }
    }
}