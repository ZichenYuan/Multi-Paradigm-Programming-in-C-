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

template<typename R, typename S>
typename CardSet<R,S>::card_iter  CardSet<R,S>::begin() {
    return cards.begin();
}

template<typename R, typename S>
typename CardSet<R,S>::card_iter  CardSet<R,S>::end() {
    return cards.end();
}

template<typename R, typename S>
void CardSet<R,S>::sort() {
    std::sort(begin(), end(), rankBasedCompare<R,S>);
}

template<typename R, typename S>
void CardSet<R, S>::add_cards(CardSet<R, S> &other) {
    cards.insert(cards.end(), other.begin(), other.end());
}

template<typename R, typename S>
void CardSet<R,S>::collect(CardSet<R, S> &other) {
    std::move(other.begin(), other.end(), std::back_inserter(cards));
    other.cards.clear();
}

template<typename R, typename S>
void CardSet<R,S>::collect_if(CardSet<R, S> &deck, std::function<bool(card_type&)> predicate){
    std::vector<card_type> toAdd;
    std::copy_if(deck.begin(), deck.end(), back_inserter(toAdd), predicate);
    cards.insert(cards.end(), toAdd.begin(), toAdd.end());
    auto end = std::remove_if(deck.begin(), deck.end(), predicate);
    deck.cards.erase(end, deck.end());
}

template<typename R, typename S>
bool CardSet<R, S>::request(CardSet<R, S> &other, R rank) {
    auto found = std::find_if(other.begin(), other.end(), [rank](const card_type &other_card){
        return rank == other_card.getRank();
    });

    if (found != other.end()) {
        cards.push_back(std::move(*found));
        other.cards.erase(found);
        return true;
    }
    return false;
}