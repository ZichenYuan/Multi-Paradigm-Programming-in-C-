// source file for Texas HoldEm Game class, derived from 
// base class game, and defines operations of Texas HoldEm game

#include "holdEmGame.h"
#include <algorithm>
#include <unordered_map>

// evaluate the best hand rank for a hand
HoldEmHandRank HoldEmGame::holdem_hand_evaluation(const CardSet<HoldEmRank, Suit>& playerHand) {
 // obtain a reference to the player's cards ny calling getCardsPtr
    auto cards = *CardSet<HoldEmRank, Suit>::getCardsPtr(playerHand);
 
    // check if the player has 5, 6, or 7 cards otherwise the hand rank is undefined
 if (cards.size() != 5) {
        return HoldEmHandRank::undefined;
    }

    // initialize the best rank to be the lowest possible rank
 HoldEmHandRank bestRank = HoldEmHandRank::xhigh;

    HoldEmHandRank rank = evaluate_hand(cards);
    return rank;
    
}

HoldEmHandRank HoldEmGame::evaluate_hand(const std::vector<Card<HoldEmRank, Suit>>& cards_value) {
 auto cards = cards_value;

    // sort the cards
 std::sort(cards.begin(), cards.end(), [](const Card<HoldEmRank, Suit>& a, const Card<HoldEmRank, Suit>& b) {
        if (a.getRank() != b.getRank()) return a.getRank() < b.getRank();
        return a.getSuit() < b.getSuit();
    });

    // check for flush
 bool isFlush = std::all_of(cards.begin(), cards.end(), [&](const auto& card) {
 return card.getSuit() == cards[0].getSuit(); 
   });
 
    // check for straight
 bool isStraight = true;
 for (size_t i = 1; i < cards.size(); ++i) {
  if (cards[i].getRank() != static_cast<HoldEmRank>(cards[i - 1].getRank() + 1)) {
   isStraight = false;
   break;
        }
 }

    // check for edge case straight A2345
 if (! isStraight && cards[0].getRank() == HoldEmRank::Two &&
   cards[1].getRank() == HoldEmRank::Three &&
   cards[2].getRank() == HoldEmRank::Four &&
   cards[3].getRank() == HoldEmRank::Five &&
   cards[4].getRank() == HoldEmRank::Ace) {
  isStraight = true;
 }

    // check for straight flush
 if (isFlush && isStraight) {
  return HoldEmHandRank::straightflush;
 }

    // count the number of cards of one rank
 std::unordered_map<HoldEmRank, int> rankCount;
 for (const auto& card : cards) {
  rankCount[card.getRank()]++;
 }

    // check for 4, 3 of a kind or pair by rank counts
 bool hasFourOfAKind = false;
 bool hasThreeOfAKind = false;
 bool hasPair = false;
 int pairCount = 0;
 for (const auto& entry: rankCount) {
      int count = entry.second;
        if (count == 4) hasFourOfAKind = true;
     else if (count == 3) hasThreeOfAKind = true;
     else if (count == 2) pairCount++;
}
 
    // compute the highest rank considering precedence and check results
 if (isFlush && isStraight) return HoldEmHandRank::straightflush;
 if (hasFourOfAKind) return HoldEmHandRank::fourofakind;
 if (hasThreeOfAKind && pairCount >= 1) return HoldEmHandRank::fullhouse;
 if (isFlush) return HoldEmHandRank::flush;
 if (isStraight) return HoldEmHandRank::straight;
 if (hasThreeOfAKind) return HoldEmHandRank::threeofakind;
 if (pairCount >= 2) return HoldEmHandRank::twopair;
 if (pairCount == 1) return HoldEmHandRank::pair;

 return HoldEmHandRank::xhigh;
}
const int SUCCESS = 0;

// print the rank value by overloading the output stream operator
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

// allow comparing PlayerHand structs by overloading the < operator
bool operator<(const HoldEmGame::PlayerHand& lhs, const HoldEmGame::PlayerHand& rhs) {
    // compare by rank
    if (lhs.rank != rhs.rank) {
        return lhs.rank < rhs.rank;
    }

    // get the cards from each player's hand
    const auto& lhsCards = *CardSet<HoldEmRank, Suit>::getCardsPtr(lhs.hand);
    const auto& rhsCards = *CardSet<HoldEmRank, Suit>::getCardsPtr(rhs.hand);

    // sort cards in descending order to compare
    std::vector<Card<HoldEmRank, Suit>> sortedLhs = lhsCards;
    std::vector<Card<HoldEmRank, Suit>> sortedRhs = rhsCards;

    std::sort(sortedLhs.begin(), sortedLhs.end(), [](const Card<HoldEmRank, Suit>& a, const Card<HoldEmRank, Suit>& b) {
        return a.getRank() > b.getRank();
    });
    std::sort(sortedRhs.begin(), sortedRhs.end(), [](const Card<HoldEmRank, Suit>& a, const Card<HoldEmRank, Suit>& b) {
        return a.getRank() > b.getRank();
    });

    for (size_t i = 0; i < sortedLhs.size(); ++i) {
        if (sortedLhs[i].getRank() != sortedRhs[i].getRank()) {
            return sortedLhs[i].getRank() < sortedRhs[i].getRank();
        }
    }

    // all cards equal
    return false;
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
    // collect cards from each player
    for (auto &hand: playerHands) {
        if(!hand.isEmpty()){
            deck.collect(hand);
        }
 // clear the player's hand after collect
 CardSet<HoldEmRank, Suit>::getCardsPtr(hand)->clear();
    }
    // collect shared cards
    deck.collect(shared);
    // clear the shared cards after collect
    CardSet<HoldEmRank, Suit>::getCardsPtr(shared)->clear();
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

     // (7) initiate the PlayerHand structs for each player
     std::vector<PlayerHand> playerEvaluations;
     auto playerName = playerNames.begin();
     for (const auto& playerHand : playerHands) {
      playerEvaluations.emplace_back(playerHand, *playerName, HoldEmHandRank::undefined);
      ++playerName;
     }

     for (auto& playerEvaluation : playerEvaluations) {
            auto& hand = *CardSet<HoldEmRank, Suit>::getCardsPtr(playerEvaluation.hand);
            auto& sharedCards = *CardSet<HoldEmRank, Suit>::getCardsPtr(shared);

            hand.insert(hand.end(), sharedCards.begin(), sharedCards.begin() + 3);
            playerEvaluation.rank = holdem_hand_evaluation(playerEvaluation.hand);
        }

        std::sort(playerEvaluations.rbegin(), playerEvaluations.rend());
        std::cout << "\nPlayer rankings after the flop:\n";
        for (const auto& playerEvaluation : playerEvaluations) {
            std::cout << "Player " << playerEvaluation.name << std::endl;
            playerEvaluation.hand.print(std::cout);
            std::cout << "Rank: " << playerEvaluation.rank << std::endl;
            std::cout << std::endl;
        }
 

 
 

        // (8) call the deal member function again to deal the fourth card to the board member variable,
        deal();

        // (9) print out the string "BOARD (turn):" and then the cards in the board member variable, 
        std::cout << "BOARD (turn):" << std::endl;
        shared.print(std::cout);

        // (10) call the deal member function again to deal the fifth and final card to the board member variable, 
        deal();

        // (11) print out the string "BOARD (river):" and then the cards in the board member variable,
        std::cout << "BOARD (river):" << std::endl;
        shared.print(std::cout);
 
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