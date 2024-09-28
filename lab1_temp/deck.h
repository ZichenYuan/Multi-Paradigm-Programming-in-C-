#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <random>
#include <algorithm>

#include "cardset.h"



// class Deck {
// public:
//     virtual void print(std::ostream& os) = 0;
//     virtual ~Deck() = default;
// };

template <typename R, typename S>
class Deck : public CardSet<R, S> {
    public:
    Deck() {}
    ~Deck() {}
    // TODO: should define in deck.cpp
    void shuffle(){
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(this->cards.begin(), this->cards.end(), g);
    }

    // TODO: should define in deck.cpp
    void collect(CardSet<R, S> &cardset){
        try{
            while (!cardset.isEmpty()){
                cardset >> *this;
            }
        }
        catch (std::runtime_error &e){
            std::cout << e.what() << std::endl;
        }
    }
};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "deck.cpp"
#endif

#endif // DECK_H