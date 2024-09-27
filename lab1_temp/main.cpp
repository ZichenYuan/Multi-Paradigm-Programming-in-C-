#include "texas.h"
#include "pinochle.h"

const int SUCCESS =0;
const int FAILURE = 1;

int main(){
    PinochleDeck pinochle_deck1;
    PinochleDeck pinochle_deck2;
    TexasDeck texas_deck;

    try {
        // Shuffle both decks
        pinochle_deck1.shuffle();
        pinochle_deck2.shuffle();

        std::cout << "Shuffled First Pinochle Deck:" << std::endl;
        pinochle_deck1.print(std::cout);
        std::cout << std::endl;

        std::cout << "Shuffled Second Pinochle Deck (to be collected):" << std::endl;
        pinochle_deck2.print(std::cout);
        std::cout << std::endl;

        // Collect all cards from the second Pinochle deck to the first
        pinochle_deck1.collect(pinochle_deck2);

        std::cout << "First Pinochle Deck after collecting cards from the second deck:" << std::endl;
        pinochle_deck1.print(std::cout);
        std::cout << std::endl;

        std::cout << "Second Pinochle Deck after transferring all cards:" << std::endl;
        pinochle_deck2.print(std::cout);
        std::cout << std::endl;

    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
        return FAILURE;
    } catch (...) {
        std::cerr << "An unexpected error occurred." << std::endl;
        return FAILURE;
    }

    return SUCCESS;
}