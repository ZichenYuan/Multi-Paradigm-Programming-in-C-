# Lab0

## Group Members
- Sunny Yuan (y.zichen@wustl.edu)
- Kathy Pan (kaiyun.p@wustl.edu)
- Samantha Zheng (samantha.z@wustl.edu)

## Error documentation
### Compile errors
Error Message:
``` 
card.cpp:8:15: note: ‘template<class R, class S> std::ostream& operator<<(std::ostream&, const Card<R, S>&)’ previously declared here
 std::ostream& operator<<(std::ostream& os, const Card< R, S >& card) {
               ^~~~~~~~
In file included from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2:
card.cpp:8:15: error: redefinition of ‘template<class R, class S> std::ostream& operator<<(std::ostream&, const Card<R, S>&)’
 std::ostream& operator<<(std::ostream& os, const Card< R, S >& card) {
               ^~~~~~~~
In file included from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2,
                 from card.h:17,
                 from card.cpp:2:
```
Problem found: Didn't use include guards --  `#ifndef CARD_H` and `#define CARD_H` to prevent multiple inclusions of the same header file. The problem is resolved after adding `#ifndef CARD_H`, `#define CARD_H`, and `#endif`.


Error message: 
```
pinochle.cpp:3:14: error: expected initializer before ‘&’ token
 std::ostream & operator<<(std::ostream& os, const PinochleRank& rank) {
              ^
make: *** [Makefile:60: lab0] Error 1
```
Problem found: Missing a `;` in header file when declaring PinochleDeck class. Problem is resolved after adding the `;`.


Error Message:
```
texas.cpp:4:50: error: ‘TexasRank’ does not name a type
 std::ostream& operator<<(std::ostream& os, const TexasRank& rank){
                                                  ^~~~~~~~~
texas.cpp: In function ‘std::ostream& operator<<(std::ostream&, const int&)’:
texas.cpp:6:14: error: ‘TexasRank’ has not been declared
         case TexasRank::Two:
              ^~~~~~~~~
texas.cpp:9:14: error: ‘TexasRank’ has not been declared
         case TexasRank::Three:
              ^~~~~~~~~
texas.cpp:12:14: error: ‘TexasRank’ has not been declared
         case TexasRank::Four:
              ^~~~~~~~~
texas.cpp:15:14: error: ‘TexasRank’ has not been declared
         case TexasRank::Five:
              ^~~~~~~~~
texas.cpp:18:14: error: ‘TexasRank’ has not been declared
         case TexasRank::Six:
              ^~~~~~~~~
texas.cpp:21:14: error: ‘TexasRank’ has not been declared
         case TexasRank::Seven:
              ^~~~~~~~~
texas.cpp:24:14: error: ‘TexasRank’ has not been declared
         case TexasRank::Eight:
              ^~~~~~~~~
texas.cpp:27:14: error: ‘TexasRank’ has not been declared
         case TexasRank::Nine:
              ^~~~~~~~~
texas.cpp:30:14: error: ‘TexasRank’ has not been declared
         case TexasRank::Ten:
              ^~~~~~~~~
texas.cpp:33:14: error: ‘TexasRank’ has not been declared
         case TexasRank::Jack:
              ^~~~~~~~~
texas.cpp:36:14: error: ‘TexasRank’ has not been declared
         case TexasRank::Queen:
              ^~~~~~~~~
texas.cpp:39:14: error: ‘TexasRank’ has not been declared
         case TexasRank::King:
              ^~~~~~~~~
texas.cpp:42:14: error: ‘TexasRank’ has not been declared
         case TexasRank::Ace:
              ^~~~~~~~~
texas.cpp:45:14: error: ‘TexasRank’ has not been declared
         case TexasRank::Undefined:
              ^~~~~~~~~
texas.cpp:50:1: warning: no return statement in function returning non-void [-Wreturn-type]
 }
 ^
texas.cpp: At global scope:
texas.cpp:53:1: error: ‘TexasRank’ does not name a type
 TexasRank& operator++(TexasRank& rank){
 ^~~~~~~~~
texas.cpp:100:1: error: ‘TexasDeck’ does not name a type
 TexasDeck::TexasDeck(){
 ^~~~~~~~~
```
Problem found: There is a typo in texas.h file, causing the header file to be unrecognized by the source file. After fixing the typo, `TexasDeck` and `TexasRank` become identifiable.

Error Message:
```
In file included from pinochle.h:6,
                 from main.cpp:2:
deck.h:3:7: error: redefinition of ‘class Deck’
 class Deck {
       ^~~~
In file included from texas.h:5,
                 from main.cpp:1:
deck.h:3:7: note: previous definition of ‘class Deck’
 class Deck {
       ^~~~
main.cpp: In function ‘int main()’:
main.cpp:7:18: error: cannot declare variable ‘pinochle_deck’ to be of abstract type ‘PinochleDeck’
     PinochleDeck pinochle_deck;
                  ^~~~~~~~~~~~~
In file included from main.cpp:2:
pinochle.h:26:7: note:   because the following virtual functions are pure within ‘PinochleDeck’:
 class PinochleDeck: public Deck {
       ^~~~~~~~~~~~
In file included from texas.h:5,
                 from main.cpp:1:
deck.h:5:18: note:      ‘virtual void Deck::print(std::ostream&) const’
     virtual void print(std::ostream& os) const = 0;
                  ^~~~~
main.cpp:8:15: error: cannot declare variable ‘texas_deck’ to be of abstract type ‘TexasDeck’
     TexasDeck texas_deck;
               ^~~~~~~~~~
In file included from main.cpp:1:
texas.h:29:7: note:   because the following virtual functions are pure within ‘TexasDeck’:
 class TexasDeck: public Deck{
       ^~~~~~~~~
In file included from texas.h:5,
                 from main.cpp:1:
deck.h:5:18: note:      ‘virtual void Deck::print(std::ostream&) const’
     virtual void print(std::ostream& os) const = 0;
                  ^~~~~
make: *** [Makefile:60: lab0] Error 1
```
Problem found: The derived classes (PinochleDeck and TexasDeck) are still considered abstract because they do not properly override the pure virtual function print from the Deck base class. Changed the header files that declared base class and derived class to make them match.