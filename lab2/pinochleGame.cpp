// Defines necessary operations to play Pinochle Game
// Source file for Pinochle Game class, derived from 
// base class game, and defines operations of pinochle game

#include "pinochleGame.h"

const int SUCCESS = 0;

// initialize the melds with different names
const char* PinochleGame::meldNames[] = {
    "dix", "offsuitmarriage", "fortyjacks", "pinochle", "insuitmarriage",
    "sixtyqueens", "eightykings", "hundredaces", "insuitrun", "doublepinochle",
    "fourhundredjacks", "sixhundredqueens", "eighthundredkings", "thousandaces", "insuitdoublerun"
};

// Initialize the static array of point values for the PinochleMelds enum class
const unsigned int PinochleGame::meldPoints[] = {
    10,   // dix
    20,   // offsuitmarriage
    40,   // fortyjacks
    40,   // pinochle
    40,   // insuitmarriage
    60,   // sixtyqueens
    80,   // eightykings
    100,  // hundredaces
    150,  // insuitrun
    300,  // doublepinochle
    400,  // fourhundredjacks
    600,  // sixhundredqueens
    800,  // eighthundredkings
    1000, // thousandaces
    1500  // insuitdoublerun
};

// Initialize playerHands with the number of players
// Initialize empty hands for each player
PinochleGame::PinochleGame(int argc, const char* argv[])
    : Game(argc, argv) {
        playerHands.resize(argc-2);
    }


//The deal member function repeatedly shift three cards (called a "packet") 
//from the deck to the hand of each player in turn 
// (i.e., the first three cards should be shifted into the first player's hand, 
// the next three cards should be shifted into the next player's hand, etc.)
// until all cards in the deck have been distributed to the players.
void PinochleGame::deal() {
    int playerCount = playerNames.size();
    int currentPlayer = 0;
    int packetSize = 3;
    while (!deck.isEmpty()) {
        for (int i = 0; i < packetSize && !deck.isEmpty(); ++i) {  // Deal packets of 3 cards
            deck >> playerHands[currentPlayer];
        }
        currentPlayer = (currentPlayer + 1) % playerCount;
    }
}

void PinochleGame::printPlayerHands(){
    auto playerName = playerNames.begin();
    auto playerHand = playerHands.begin();

    while(playerName != playerNames.end()){
        // print to output stream
        std::cout << "Name: " << *playerName << std::endl;
        (*playerHand).print(std::cout);
        std::cout << std::endl;
        ++playerName;
        ++playerHand;
    }
}
 
void PinochleGame::collectAll(){
    auto playerHand = playerHands.begin();
    while(playerHand != playerHands.end()){
        deck.collect(*playerHand);
    }
}


int PinochleGame::play(){
    while(true){
        // (1) call the deck's shuffle member function;
        deck.shuffle();

        // (2) call the deal member function to distribute the cards to the players; 
        deal();

        // (3) print out each player's name and then the cards in their hand to the standard output stream; 
        printPlayerHands();

        // (4) use the deck's collect member function repeatedly to move the cards back out of each player's hand into the deck; 
        collectAll();

        // (5) print a string to the standard output stream that asks the user whether or not to end the game; 
        // (6) read in a string from the standard input stream - if that string is "yes" the member function should return a value 
        // to indicate success, and otherwise it should repeat the sequence of steps.
        if (endGamePrompt()){
            return SUCCESS;
        }
        std::cout << "Starting a new game" << std::endl;
    }
}

/**
* @brief print meld name and point value
* @param os the stream to print
* @param meld the meld to print
* @return std::ostream & the reference of the input stream
*/
std::ostream &operator<<(std::ostream &os, const PinochleMelds &meld)
{
    os << PinochleGame::meldNames[static_cast<int>(meld)] << ": " << PinochleGame::meldPoints[static_cast<int>(meld)] << " points";;
    return os;
}