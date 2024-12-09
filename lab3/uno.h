#include <iostream>
#include "deck.h"

enum class UnoColor {
    red, blue, green, yellow, black, Undefined
};

enum class UnoRank {
    zero = 0, 
    one = 1, 
    two = 2, 
    three = 3, 
    four = 4, 
    five = 5, 
    six = 6, 
    seven = 7, 
    eight = 8, 
    nine = 9, 
    skip = 10, 
    reverse = 11, 
    drawtwo = 12, 
    drawfour = 13, 
    wild = 14, 
    blank = 15, 
    Undefined
};

std::ostream& operator<<(std::ostream& os, const UnoColor& color); 
std::ostream& operator<<(std::ostream& os, const UnoRank& rank);
UnoColor& operator++(UnoColor& color);
UnoRank& operator++(UnoRank& rank);


class UnoDeck: public Deck < UnoRank, UnoColor>
{
    public:
        UnoDeck();
};