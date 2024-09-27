#include "deck.h"

// shuffle function
// template <typename R, typename S>
// void Deck<R, S>::shuffle()
// {
//     // reference: https://stackoverflow.com/questions/38367976/do-stdrandom-device-and-stdmt19937-follow-an-uniform-distribution
//     std::random_device rd;
//     std::mt19937 g(rd());
//     std::shuffle(this->cards.begin(), this->cards.end(), g);
// }

// template <typename R, typename S>
// void Deck<R, S>::collect(CardSet<R, S> &cardset)
// {
//     try{
//         while (!cardset.is_empty()){
//             cardset >> *this;
//         }
//     }
//     catch (std::runtime_error &e){
//         std::cout << e.what() << std::endl;
//     }
// }