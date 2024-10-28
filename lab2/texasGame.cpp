// source file for Texas HoldEm Game class, derived from 
// base class game, and defines operations of Texas HoldEm game

#include "texasGame.h"
#include <algorithm>
#include <unordered_map>

HoldEmHandRank HoldEmGame::holdem_hand_evaluation(const CardSet<TexasRank, Suit>& playerHand) {
	auto cards = *CardSet<TexasRank, Suit>::getCardsPtr(playerHand);
	
	if (cards.size() != 7){
		return HoldEmHandRank::undefined;

	}
	HoldEmHandRank bestRank = HoldEmHandRank::xhigh;

	std::vector<std::vector<Card<TexasRank, Suit>>> possibleHands;
	for (size_t i = 0; i < cards.size(); ++i) {
        for (size_t j = i + 1; j < cards.size(); ++j) {
            std::vector<Card<TexasRank, Suit>> possibleHand;
            for (size_t k = 0; k < cards.size(); ++k) {
                if (k != i && k != j) {
                    possibleHand.push_back(cards[k]);
                }
            }
            possibleHands.push_back(possibleHand);
        }
    }
	for (const auto& hand : possibleHands) {
        HoldEmHandRank rank = evaluate_hand(hand);
        if (rank > bestRank) {
            bestRank = rank;
        }}
	return bestRank;
    
}

HoldEmHandRank HoldEmGame::evaluate_hand(const std::vector<Card<TexasRank, Suit>>& cards_value) {
	auto cards = cards_value;
	std::sort(cards.begin(), cards.end(), [](const Card<TexasRank, Suit>& a, const Card<TexasRank, Suit>& b) {
        if (a.getRank() != b.getRank()) return a.getRank() < b.getRank();
        return a.getSuit() < b.getSuit();
    });
	bool isFlush = std::all_of(cards.begin(), cards.end(), [&](const auto& card) {
	return card.getSuit() == cards[0].getSuit();	
			});
	
	bool isStraight = true;
	for (size_t i = 1; i < cards.size(); ++i) {
		if (cards[i].getRank() != static_cast<TexasRank>(cards[i - 1].getRank() + 1)) {
			isStraight = false;
			break;

	}
			}

	if (! isStraight && cards[0].getRank() == TexasRank::Two &&
			cards[1].getRank() == TexasRank::Three &&
			cards[2].getRank() == TexasRank::Four &&
			cards[3].getRank() == TexasRank::Five &&
			cards[4].getRank() == TexasRank::Ace) {
		isStraight = true;
	}

	if (isFlush && isStraight) {
		return HoldEmHandRank::straightflush;
	}

	std::unordered_map<TexasRank, int> rankCount;
	for (const auto& card : cards) {
		rankCount[card.getRank()]++;
	}
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

bool operator<(const HoldEmGame::PlayerHand& lhs, const HoldEmGame::PlayerHand& rhs) {
    if (lhs.rank != rhs.rank) {
        return lhs.rank < rhs.rank;
    }

    const auto& lhsCards = *CardSet<TexasRank, Suit>::getCardsPtr(lhs.hand);
    const auto& rhsCards = *CardSet<TexasRank, Suit>::getCardsPtr(rhs.hand);

    switch (lhs.rank) {
        case HoldEmHandRank::pair:
            if (lhsCards[0].getRank() != rhsCards[0].getRank()) {
                return lhsCards[0].getRank() < rhsCards[0].getRank();
            }
            for (size_t i = 1; i < lhsCards.size(); ++i) {
                if (lhsCards[i].getRank() != rhsCards[i].getRank()) {
                    return lhsCards[i].getRank() < rhsCards[i].getRank();
                }
            }
            break;

        case HoldEmHandRank::twopair:
            if (lhsCards[0].getRank() != rhsCards[0].getRank()) {
                return lhsCards[0].getRank() < rhsCards[0].getRank();
            }
            if (lhsCards[1].getRank() != rhsCards[1].getRank()) {
                return lhsCards[1].getRank() < rhsCards[1].getRank();
            }
            return lhsCards[2].getRank() < rhsCards[2].getRank();

        case HoldEmHandRank::threeofakind:
            return lhsCards[0].getRank() < rhsCards[0].getRank();

        case HoldEmHandRank::straight:
        case HoldEmHandRank::straightflush:
            return lhsCards.back().getRank() < rhsCards.back().getRank();

        case HoldEmHandRank::flush:
        case HoldEmHandRank::xhigh:
            for (size_t i = 0; i < lhsCards.size(); ++i) {
                if (lhsCards[i].getRank() != rhsCards[i].getRank()) {
                    return lhsCards[i].getRank() < rhsCards[i].getRank();
                }
            }
            break;

        case HoldEmHandRank::fullhouse:
            return lhsCards[0].getRank() < rhsCards[0].getRank();

        case HoldEmHandRank::fourofakind:
            return lhsCards[0].getRank() < rhsCards[0].getRank();

        default:
            return false;
    }
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
    for (auto &hand: playerHands) {
        while(!hand.isEmpty()){
            deck.collect(hand);
        }
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

	// (7) initiate the PlayerHand structs for each player
	std::vector<PlayerHand> playerEvaluations;
	auto playerName = playerNames.begin();
	for (const auto& playerHand : playerHands) {
		playerEvaluations.emplace_back(playerHand, *playerName, HoldEmHandRank::undefined);
		++playerName;
	}

	for (auto& playerEvaluation : playerEvaluations) {
            auto& hand = *CardSet<TexasRank, Suit>::getCardsPtr(playerEvaluation.hand);
auto& sharedCards = *CardSet<TexasRank, Suit>::getCardsPtr(shared);


            hand.insert(hand.end(), sharedCards.begin(), sharedCards.begin() + 3);
            playerEvaluation.rank = holdem_hand_evaluation(playerEvaluation.hand);
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
	

	// (12) Update players' hands to include all community cards
	for (auto& playerEvaluation : playerEvaluations) {
    		auto& hand = *CardSet<TexasRank, Suit>::getCardsPtr(playerEvaluation.hand);
		auto& sharedCards = *CardSet<TexasRank, Suit>::getCardsPtr(shared);

    		if (hand.size() > 2) {
        hand.erase(hand.begin() + 2, hand.end());
    } 
    		hand.insert(hand.end(), sharedCards.begin(), sharedCards.end());
}

	// (13) Evaluate each player's best hand
	for (auto& playerEvaluation : playerEvaluations) {
    		playerEvaluation.rank = holdem_hand_evaluation(playerEvaluation.hand);
	}
	// (14) sort players by their hand rank descendingly
	std::sort(playerEvaluations.rbegin(), playerEvaluations.rend());

	
	// (15) print out each player's name, complete hand and evaluated rank
	
	for (const auto& playerEvaluation : playerEvaluations) {
		std::cout << "Player " << playerEvaluation.name << std::endl;
		playerEvaluation.hand.print(std::cout);
		std::cout << "Rank: " << playerEvaluation.rank << std::endl;
		std::cout << std::endl;

	}

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
