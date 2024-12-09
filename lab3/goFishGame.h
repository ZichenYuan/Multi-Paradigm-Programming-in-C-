#include "cardsuit.h"
#include "holdEm.h"
#include <type_traits>
#include "game.h"
#include "uno.h"
#include "pinochle.h"
#include <limits> // for std::numeric_limits
#include <sstream>

//the suit type, the rank type, and a deck type
template<typename S = Suit, typename R = HoldEmRank, typename D = HoldEmDeck>

class GoFishGame: public Game {
    static_assert(std::is_base_of<CardSet<R, S>, D>::value, "Deck must be derived from CardSet<Suit, Rank>");
    public:
        GoFishGame(int argc, const char* argv[]);
        virtual ~GoFishGame() = default;
        virtual int play();
        bool collect_books(int playerNumber);
    protected:
        D deck;
        std::vector<CardSet<R, S>> playerHands;
        std::vector<CardSet<R, S>> playerBooks;
        // virtual void deal();
        bool turn(int playerNumber);
        void deal();
    private:
        int numPlayer;
};