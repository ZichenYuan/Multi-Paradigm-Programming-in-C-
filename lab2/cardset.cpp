// The source file for cardset, defines operators

#include "cardset.h"
using namespace std;

// print function
template <typename R, typename S>
void CardSet<R, S>::print(std::ostream& os, size_t per_line) const {
    size_t count = 0;
    for (const auto& card : cards) {
        os << card << "  ";
        if (++count % per_line == 0) {
            os << "\n";
        }
    }
    if (count % per_line != 0) {
        os << std::endl;
    }
}

//is_empty function
template<typename R, typename S>
bool CardSet<R,S>::isEmpty() {
    return cards.empty();
}

//overloaded shift operator
template<typename R, typename S>
CardSet<R,S> & CardSet<R,S>::operator>> (CardSet<R,S> & other) {
    if (cards.size() == 0){
        throw std::runtime_error("CardSet is empty");
    }
    other.cards.push_back(cards.back());
    cards.pop_back();
    return *this;
}


