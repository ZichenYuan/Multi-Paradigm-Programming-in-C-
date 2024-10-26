// source file for Texas HoldEm Game class, derived from 
// base class game, and defines operations of Texas HoldEm game

#include "texasGame.h"

const int SUCCESS = 0;
std::ostream& operator<<(std::ostream& os, const HoldEmHandRank& rank) {
    switch (rank) {
        case HoldEmHandRank::xhigh:
            os << "X High";
            break;
        case HoldEmHandRank::pair:
            os << "Pair";
            break;
        case HoldEmHandRank::twopair:
            os << "Two Pair";
            break;
        case HoldEmHandRank::threeofakind:
            os << "Three of a Kind";
            break;
        case HoldEmHandRank::straight:
            os << "Straight";
            break;
        case HoldEmHandRank::flush:
            os << "Flush";
            break;
        case HoldEmHandRank::fullhouse:
            os << "Full House";
            break;
        case HoldEmHandRank::fourofakind:
            os << "Four of a Kind";
            break;
        case HoldEmHandRank::straightflush:
            os << "Straight Flush";
            break;
        default:
            os << "Undefined";
            break;
    }
    return os;
}


HoldEmGame::HoldEmGame(int argc, const char* argv[])
    : Game(argc, argv) {
        playerHands.resize(argc-2);
}

void HoldEmGame::deal(){
    switch (state)
    {
    case HoldEmState::preflop:
        // Deal two cards to each player
        for (int i = 0; i < 2; ++i)
        {
            for (auto playerHand = playerHands.begin(); playerHand != playerHands.end(); ++playerHand)
            {
                deck >> *playerHand;
            }
        }
        state = HoldEmState::flop;
        break;
    case HoldEmState::flop:
        // Deal three cards from the deck to the board member variable
        for (int i = 0; i < 3; ++i)
        {
            deck >> shared;
        }
        state = HoldEmState::turn;
        break;
    case HoldEmState::turn:
        // Deal one card from the deck to the board member variable
        deck >> shared;
        state = HoldEmState::river;
        break;
    case HoldEmState::river:
        // Deal one community card to the board
        deck >> shared;
        state = HoldEmState::undefined;
        break;
    default:
        // Deal with undefined states
        break;
    }

}

void HoldEmGame::printPlayerHands(){
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

void HoldEmGame::collectAll(){
    auto playerHand = playerHands.begin();
    while(playerHand != playerHands.end()){
        deck.collect(*playerHand);
    }
}


int HoldEmGame::play(){
    while(true){
        // (1) call the deck's shuffle member function;
        deck.shuffle();

        // (2) set the value of the HoldEmState protected member variable to be HoldEmState::preflop,
        state = HoldEmState::preflop;

        // (3) call the deal member function to deal two cards to each player's hand,
        deal();

        // (4) print out each player's name and the cards in their hand to the standard output stream,
        printPlayerHands();

        // (5) call the deal member function again to deal three cards to the board member variable, 
        deal();

        // (6) print out the string "BOARD (flop):" and then the cards in the board member variable, 
        std::cout << "BOARD (flop):" << std::endl;
        shared.print(std::cout);

        // (7) call the deal member function again to deal the fourth card to the board member variable,
        deal();

        // (8) print out the string "BOARD (turn):" and then the cards in the board member variable, 
        std::cout << "BOARD (turn):" << std::endl;
        shared.print(std::cout);

        // (9) call the deal member function again to deal the fifth and final card to the board member variable, 
        deal();

        // (10) print out the string "BOARD (river):" and then the cards in the board member variable,
        std::cout << "BOARD (river):" << std::endl;
        shared.print(std::cout);

        // (11) use the deck's collect member function repeatedly to move the cards back out of each player's hand into the deck,
        // (12) use the deck's collect member function to move the cards back out of the board into the deck,
        collectAll();

        // (13) print a string to the standard output stream that asks the user whether or not to end the game, 
        // (14) read in a string from the standard input stream - 
        // if that string is "yes" the member function should return a value to indicate success, 
        // and otherwise it should repeat the sequence of steps.
        if (endGamePrompt()){
            return SUCCESS;
        }
        std::cout << "Starting a new game" << std::endl;
    }
}
