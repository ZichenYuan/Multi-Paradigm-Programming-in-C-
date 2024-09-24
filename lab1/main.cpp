// Main function serves as the entry point for the program
// Create instances of the PinochleDeck and the TexasDeck
// Print the decks
#include "texas.h"     
#include "pinochle.h"  

const int SUCCESS = 0; 

int main() {
    PinochleDeck pinochle_deck;  // Create an instance of the PinochleDeck class
    TexasDeck texas_deck;        // Create an instance of the TexasDeck class

    // Print the Pinochle deck to the console
    std::cout << "Pinochle Deck:" << std::endl;
    pinochle_deck.print(std::cout);  // Call the print function of PinochleDeck to output the deck
    std::cout << std::endl;

    // Print the Texas deck to the console
    std::cout << "Texas Deck:" << std::endl;
    texas_deck.print(std::cout);     // Call the print function of TexasDeck to output the deck
    std::cout << std::endl;

    return SUCCESS;  
}
