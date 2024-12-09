#include "goFishGame.h"

const int SUCCESS = 0;

//constructor
template<> //template specialization
GoFishGame<Suit, HoldEmRank, HoldEmDeck>::GoFishGame(int argc, const char* argv[]): Game(argc, argv) {
    // erase the string for deck name
    playerNames.erase(playerNames.begin());
    numPlayer = playerNames.size();

    std::cout << "Using HoldEm deck, rank 2 ~ A correspond to 0 ~ 12" << std::endl;
    playerHands.resize(numPlayer);
    //one playerbook for each player indicating the completed book of that player
    playerBooks.resize(numPlayer);
    deck = HoldEmDeck();

    for(HoldEmRank i = HoldEmRank::Two; i!=HoldEmRank::Undefined; ++i) {
        int cnt = std::count_if(deck.begin(), deck.end(), [i](const auto &curCard){
            return curCard.getRank() == i;
        });
        if (cnt < 4){
            throw std::invalid_argument("Deck doesn't have at least 4 of each cards");
        }
    }
}

template<> //template specialization
GoFishGame<Suit, PinochleRank, PinochleDeck>::GoFishGame(int argc, const char* argv[]): Game(argc, argv){
    // erase the string for deck name
    playerNames.erase(playerNames.begin());
    numPlayer = playerNames.size();

    std::cout << "Using Pinochle deck, rank 9 ~ A correspond to 0 ~ 5" << std::endl;
    playerHands.resize(numPlayer);
    playerBooks.resize(numPlayer);
    deck = PinochleDeck();

    for(PinochleRank i = PinochleRank::Nine; i!=PinochleRank::Undefined; ++i) {
        int cnt = std::count_if(deck.begin(), deck.end(), [i](const auto &curCard){
            return curCard.getRank() == i;
        });
        if (cnt < 4){
            throw std::invalid_argument("Deck doesn't have at least 4 of each cards");
        }
    }
}

template<> //template specialization
GoFishGame<UnoColor, UnoRank, UnoDeck>::GoFishGame(int argc, const char* argv[]): Game(argc, argv){
    // erase the string for deck name
    playerNames.erase(playerNames.begin());
    numPlayer = playerNames.size();
    std::cout << "Using Uno deck, rank zero ~ blank correspond to 0 ~ 15" << std::endl;

    playerHands.resize(numPlayer);
    playerBooks.resize(numPlayer);
    deck = UnoDeck();

    for(UnoRank i = UnoRank::zero; i!= UnoRank::Undefined; ++i) {
        int cnt = std::count_if(deck.begin(), deck.end(), [i](const auto &curCard){
            return curCard.getRank() == i;
        });
        if (cnt < 4){
            std::cout << "uno rank doesn't have 4 cards: " <<  i  << std::endl;
            throw std::invalid_argument("Deck doesn't have at least 4 of each cards");
        }
    }
}

template<typename S, typename R, typename D>
int GoFishGame<S, R, D>::play() {
    deal();

    //collect possible books
    for (int i = 1; i <= numPlayer; i++) {
        while (collect_books(i)){}
    }

    bool game = true;
    int round =1;

    std::cout << "end of collecting books" << std::endl;

    while (game) {
        std::cout << "Round: " << round << std::endl;

        for (int i = 1; i <= numPlayer; i++) {
            bool temp = turn(i);
            while (temp) {
                temp = turn(i);
            }
        }

        int nonEmptyCnt = 0;
        bool handsEmpty = true;
        for (int i = 1; i <= numPlayer; i++) {
            std::cout << "Player " << i << ": " << playerNames[i-1] << std::endl;
            std::cout << "Number of books collected: " << playerBooks[i-1].size() << std::endl;
            if (!playerHands[i - 1].isEmpty()){
                nonEmptyCnt++;
                handsEmpty = false;
            }
        }
        std::cout << std::endl;

        //check termination condition
        // TODO double check
        if ((deck.isEmpty() && handsEmpty) || nonEmptyCnt <2) {
            game = false;
            std::cout << "The game will be terminated at round " << round << std::endl;
        }
        
        round++;
    }
    // which players made the most books
    int maxSize = 0;
    std::vector<int> maxIdx;
    for (int i = 1; i <= numPlayer; i++) {
        int curSize = playerBooks[i-1].size();
        if (curSize > maxSize) {
            maxSize = curSize;
            maxIdx.clear();
            maxIdx.push_back(i);
        } else if (curSize == maxSize) {
            maxIdx.push_back(i);
        }
    }

    for (auto i: maxIdx) {
        std::cout << "Player " << i << ": " << playerNames[i-1] << " ";
    }

    std::cout << " collected the most books" << std::endl;
    return SUCCESS;
}

//Add a collect_books method to the GoFishGame class template that takes 
// a player number, checks if there is a 4-of-a-kind in that player's hand, 
// and returns a boolean value to indicate whether or not 4 cards of the same rank were found in it.

template<typename S, typename R, typename D>
bool GoFishGame<S, R, D>::collect_books(int playerNumber) {
    auto & curPlayerHand = playerHands[playerNumber-1];
    const int NUM_OF_A_KIND =4;
    R r = static_cast<R>(0);

    for(R r = static_cast<R>(0); r!= R::Undefined; ++r){
        int cnt = std::count_if(curPlayerHand.begin(), curPlayerHand.end(), [r](const typename CardSet<R,S>::card_type & card){
            return card.getRank() == r;
        });

        if (cnt == NUM_OF_A_KIND){

            std::cout<<"current player has four of a kind" <<std::endl;
            // call the collect_if function you defined in the CardSet class template,
            // to remove all cards of the appropriate rank from the player's hand 
            // and put them into the CardSet for the books that player has made.

            playerBooks[playerNumber-1].collect_if(curPlayerHand, [r](const typename CardSet<R,S>::card_type & card){
                return card.getRank() == r;
            });
            return true;
        }
    }
    return false;

}
template<typename S, typename R, typename D>
bool GoFishGame<S, R, D>::turn(int playerNumber) {
    for (int i = 0; i  < numPlayer; i++){
        std::cout << "Player " << i+1 << ": " << playerNames[i] << std::endl;
        std::cout << "Player Hands: ";
        for (auto iter = playerHands[i].begin(); iter != playerHands[i].end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
        std::cout<<"Player Books: ";
        for (auto iter = playerBooks[i].begin(); iter != playerBooks[i].end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Player " << playerNumber << " " << playerNames[playerNumber-1] << "'s turn: " << std::endl;

    bool valid = false;
    int requestedPlayer;
    int requestedRank;

    //TODO: add usage instruction
    while(!valid) {
        std::cout << "Which card rank to ask for? Enter an integer: ";
        while (true) {
            std::cin >> requestedRank;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Please enter an integer: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break; 
            }
        }
        std::cout << "Which player to ask from? Enter an integer: ";
       
        while (true) {
            std::cin >> requestedPlayer;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Please enter an integer: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break; 
            }
        }

        bool validRank = false;
        if (playerHands[playerNumber-1].isEmpty()){
            // if hand is empty, can request any card rank
            validRank = true;
        } else {
            for(auto itr = playerHands[playerNumber-1].begin(); itr != playerHands[playerNumber-1].end(); itr++) {
                if (static_cast<int>((*itr).getRank()) == requestedRank) {
                    validRank = true;
                }
            }
        }

        bool validPlayer = false;
        if (requestedPlayer > 0 && requestedPlayer <= numPlayer && !playerHands[requestedPlayer-1].isEmpty()){
            validPlayer = true;
        }

        if (validPlayer && validRank) {
            valid = true;
        } else {
            if (!validPlayer) {
                std::cout << "Player input failed" << std::endl;
            } else {
                std::cout << "Rank input failed" << std::endl;
            }
        }
    }

    // request cards
    bool requestStatus = playerHands[playerNumber - 1].request(playerHands[requestedPlayer - 1], static_cast<R>(requestedRank));

    if(requestStatus) {
        std:: cout << "Request is successful" << std::endl;
        while (collect_books(playerNumber)) {}
        return true;
    }

    if (!deck.isEmpty()){
        std::cout << "Request is not successful, Go fish" << std::endl;
        // if the card drawn is the requestedRank
        deck >> playerHands[playerNumber-1];

        //TODO ?
        if ((*(--playerHands[playerNumber - 1].end())).getRank() == static_cast<R>(requestedRank)){
            std::cout << "Successfully get requested rank: " << static_cast<R>(requestedRank) << std::endl;
            collect_books(playerNumber);
            return true;
        } else {
            std::cout << "Failed to get requested rank, got " << (*(--playerHands[playerNumber - 1].end())).getRank() <<  std::endl;
            return false;
        }
        
    } else {
        std::cout <<  "Request is not successful, you are out" << std::endl;
        deck.collect(playerHands[playerNumber - 1]);
        return false;
    }
}


const int SMALL_GAME = 5;
const int LARGE_GAME =7;

template<typename S, typename R, typename D>
void GoFishGame<S, R, D>::deal() {
    deck.shuffle();
    int cardNum;
    int playerNum = playerHands.size();
    if (playerNum > 2){
        cardNum = LARGE_GAME;
    } else {
        cardNum =  SMALL_GAME;
    }

    for (int i = 0; i < cardNum; ++i) {
        for (auto & playerHand: playerHands){
            if (!deck.isEmpty()){
                deck >> playerHand;
            }
        }
    }
}