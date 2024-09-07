#include "texas.h"
#include "pinochle.h"

const int SUCCESS =0;

int main(){
    PinochleDeck pinochle_deck;
    TexasDeck texas_deck;

    std::cout << "Pinochle Deck:" << std::endl;
    pinochle_deck.print(std::cout);
    std::cout << std::endl;

    std::cout << "Texas Deck:" << std::endl;
    texas_deck.print(std::cout);
    std::cout << std::endl;

    return SUCCESS;
}