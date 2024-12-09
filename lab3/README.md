# Lab3
## Group Members
- Sunny Yuan (y.zichen@wustl.edu)

## Error documentation
### Compile errors
```
[y.zichen@shell lab3]$ make
g++ -o lab3 -DUNIX   -DTEMPLATE_HEADERS_INCLUDE_SOURCE cardsuit.cpp pinochle.cpp holdEm.cpp main.cpp game.cpp pinochleGame.cpp holdEmGame.cpp uno.cpp goFishGame.cpp 
main.cpp: In function ‘std::shared_ptr<Game> create(int, const char**)’:
main.cpp:117:45: error: invalid conversion from ‘int’ to ‘const char**’ [-fpermissive]
             const char** newArgv = new_argv(argc, argv);
                                             ^~~~
main.cpp:86:35: note:   initializing argument 1 of ‘const char** new_argv(const char**, int&)’
 const char** new_argv(const char *argv[], int &argc) {
                       ~~~~~~~~~~~~^~~~~~
main.cpp:117:51: error: invalid conversion from ‘const char**’ to ‘int’ [-fpermissive]
             const char** newArgv = new_argv(argc, argv);
                                                   ^~~~
main.cpp:86:48: note:   initializing argument 2 of ‘const char** new_argv(const char**, int&)’
 const char** new_argv(const char *argv[], int &argc) {
                                           ~~~~~^~~~
main.cpp:117:51: error: cannot bind rvalue ‘(int)argv’ to ‘int&’
             const char** newArgv = new_argv(argc, argv);
                                                   ^~~~
```

Solution: Swapping the order of argc and argv when inputting the two arguments to fit the function definition.


```
[y.zichen@shell lab3]$ make
g++ -o lab3 -DUNIX   -DTEMPLATE_HEADERS_INCLUDE_SOURCE cardsuit.cpp pinochle.cpp holdEm.cpp main.cpp game.cpp pinochleGame.cpp holdEmGame.cpp uno.cpp goFishGame.cpp 
/tmp/cc9BHLeI.o:(.rodata._ZTV10GoFishGameI8UnoColor7UnoRank7UnoDeckE[_ZTV10GoFishGameI8UnoColor7UnoRank7UnoDeckE]+0x18): undefined reference to `GoFishGame<UnoColor, UnoRank, UnoDeck>::~GoFishGame()'
/tmp/cc9BHLeI.o:(.rodata._ZTV10GoFishGameI8UnoColor7UnoRank7UnoDeckE[_ZTV10GoFishGameI8UnoColor7UnoRank7UnoDeckE]+0x20): undefined reference to `GoFishGame<UnoColor, UnoRank, UnoDeck>::~GoFishGame()'
/tmp/cc9BHLeI.o:(.rodata._ZTV10GoFishGameI4Suit12PinochleRank12PinochleDeckE[_ZTV10GoFishGameI4Suit12PinochleRank12PinochleDeckE]+0x18): undefined reference to `GoFishGame<Suit, PinochleRank, PinochleDeck>::~GoFishGame()'
/tmp/cc9BHLeI.o:(.rodata._ZTV10GoFishGameI4Suit12PinochleRank12PinochleDeckE[_ZTV10GoFishGameI4Suit12PinochleRank12PinochleDeckE]+0x20): undefined reference to `GoFishGame<Suit, PinochleRank, PinochleDeck>::~GoFishGame()'
/tmp/cc9BHLeI.o:(.rodata._ZTV10GoFishGameI4Suit10HoldEmRank10HoldEmDeckE[_ZTV10GoFishGameI4Suit10HoldEmRank10HoldEmDeckE]+0x18): undefined reference to `GoFishGame<Suit, HoldEmRank, HoldEmDeck>::~GoFishGame()'
/tmp/cc9BHLeI.o:(.rodata._ZTV10GoFishGameI4Suit10HoldEmRank10HoldEmDeckE[_ZTV10GoFishGameI4Suit10HoldEmRank10HoldEmDeckE]+0x20): undefined reference to `GoFishGame<Suit, HoldEmRank, HoldEmDeck>::~GoFishGame()'
collect2: error: ld returned 1 exit status
make: *** [Makefile:60: lab3] Error 1
```
Solution: Solved by let destructor equal to default. Didn't define destructor correctly.

### Runtime errors
```
[y.zichen@shell lab3]$ ./lab3 GoFish HoldEm A1 B2 C3 D4 E5
Segmentation fault (core dumped)
```
Solution: Didn't initialize playerBooks in constructor. Solved by allocating the playerBooks vector in the constructor.


```
[y.zichen@shell lab3]$ ./lab3 GoFis HoldEm  A1 B2 C3 D4 E5
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from? Enter an integer: passed initial check
Which card rank to ask for? Enter an integer: Which player to ask from^C
```
Solution: Used packages to stop the abnormal behaviors.
```
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
```

### Final Output

#### Test (Exceptions)
```
[y.zichen@shell lab3]$ ./lab3 GoFish A1 B2 C3 D4 E5
A1Exception occurred: Valid Decks for GoFish are HoldEm, Pinochle or Uno
terminate called after throwing an instance of 'std::exception'
```

```
[y.zichen@shell lab3]$ ./lab3 GoFis HoldEm  A1 B2 C3 D4 E5
Error: Unknown game type "GoFis".
[y.zichen@shell lab3]$ ./lab3 GoFish HoldEm A1 
Usage: ./lab3 GoFish <Player1> <Player2> [<Player3> ... <Player5>]
GoFish needs 2-5 players.
```

#### Pinochle
```
PinochleUsing Pinochle deck, rank 9 ~ A correspond to 0 ~ 5
current player has four of a kind
current player has four of a kind
end of collecting books
Round: 1
Player 1: A1
Player Hands: Q of C Q of S 9 of C 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C Q of H A of S A of D 9 of C A of H 10 of S 
Player Books: 
Player 3: C3
Player Hands: K of H K of S 9 of H Q of C A of H A of C Q of H 
Player Books: 
Player 4: D4
Player Hands: 9 of D A of C K of D 9 of S K of S 10 of H K of C 
Player Books: 
Player 5: E5
Player Hands: Q of D Q of D K of D 
Player Books: J of C J of S J of H J of H 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: 2
Which player to ask from? Enter an integer: 2
Request is successful
Player 1: A1
Player Hands: Q of C Q of S 9 of C Q of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C A of S A of D 9 of C A of H 10 of S 
Player Books: 
Player 3: C3
Player Hands: K of H K of S 9 of H Q of C A of H A of C Q of H 
Player Books: 
Player 4: D4
Player Hands: 9 of D A of C K of D 9 of S K of S 10 of H K of C 
Player Books: 
Player 5: E5
Player Hands: Q of D Q of D K of D 
Player Books: J of C J of S J of H J of H 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: 2
Which player to ask from? Enter an integer: 4
Request is not successful, Go fish
Failed to get requested rank, gotK
Player 1: A1
Player Hands: Q of C Q of S 9 of C Q of H K of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C A of S A of D 9 of C A of H 10 of S 
Player Books: 
Player 3: C3
Player Hands: K of H K of S 9 of H Q of C A of H A of C Q of H 
Player Books: 
Player 4: D4
Player Hands: 9 of D A of C K of D 9 of S K of S 10 of H K of C 
Player Books: 
Player 5: E5
Player Hands: Q of D Q of D K of D 
Player Books: J of C J of S J of H J of H 
Player 2 B2's turn: 
Which card rank to ask for? Enter an integer: 5
Which player to ask from? Enter an integer: 4
Request is successful
current player has four of a kind
Player 1: A1
Player Hands: Q of C Q of S 9 of C Q of H K of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C 9 of C 10 of S 
Player Books: A of S A of D A of H A of C 
Player 3: C3
Player Hands: K of H K of S 9 of H Q of C A of H A of C Q of H 
Player Books: 
Player 4: D4
Player Hands: 9 of D K of D 9 of S K of S 10 of H K of C 
Player Books: 
Player 5: E5
Player Hands: Q of D Q of D K of D 
Player Books: J of C J of S J of H J of H 
Player 2 B2's turn: 
Which card rank to ask for? Enter an integer: 4
Which player to ask from? Enter an integer: 5
Request is not successful, Go fish
Failed to get requested rank, got9
Player 1: A1
Player Hands: Q of C Q of S 9 of C Q of H K of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C 9 of C 10 of S 9 of S 
Player Books: A of S A of D A of H A of C 
Player 3: C3
Player Hands: K of H K of S 9 of H Q of C A of H A of C Q of H 
Player Books: 
Player 4: D4
Player Hands: 9 of D K of D 9 of S K of S 10 of H K of C 
Player Books: 
Player 5: E5
Player Hands: Q of D Q of D K of D 
Player Books: J of C J of S J of H J of H 
Player 3 C3's turn: 
Which card rank to ask for? Enter an integer: 3
Which player to ask from? Enter an integer: 5
Request is successful
Player 1: A1
Player Hands: Q of C Q of S 9 of C Q of H K of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C 9 of C 10 of S 9 of S 
Player Books: A of S A of D A of H A of C 
Player 3: C3
Player Hands: K of H K of S 9 of H Q of C A of H A of C Q of H K of D 
Player Books: 
Player 4: D4
Player Hands: 9 of D K of D 9 of S K of S 10 of H K of C 
Player Books: 
Player 5: E5
Player Hands: Q of D Q of D 
Player Books: J of C J of S J of H J of H 
Player 3 C3's turn: 
Which card rank to ask for? Enter an integer: 3
Which player to ask from? Enter an integer: 4
Request is successful
current player has four of a kind
Player 1: A1
Player Hands: Q of C Q of S 9 of C Q of H K of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C 9 of C 10 of S 9 of S 
Player Books: A of S A of D A of H A of C 
Player 3: C3
Player Hands: 9 of H Q of C A of H A of C Q of H 
Player Books: K of H K of S K of D K of D 
Player 4: D4
Player Hands: 9 of D 9 of S K of S 10 of H K of C 
Player Books: 
Player 5: E5
Player Hands: Q of D Q of D 
Player Books: J of C J of S J of H J of H 
Player 3 C3's turn: 
Which card rank to ask for? Enter an integer: 5
Which player to ask from? Enter an integer: 1
Request is not successful, Go fish
Failed to get requested rank, got10
Player 1: A1
Player Hands: Q of C Q of S 9 of C Q of H K of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C 9 of C 10 of S 9 of S 
Player Books: A of S A of D A of H A of C 
Player 3: C3
Player Hands: 9 of H Q of C A of H A of C Q of H 10 of S 
Player Books: K of H K of S K of D K of D 
Player 4: D4
Player Hands: 9 of D 9 of S K of S 10 of H K of C 
Player Books: 
Player 5: E5
Player Hands: Q of D Q of D 
Player Books: J of C J of S J of H J of H 
Player 4 D4's turn: 
Which card rank to ask for? Enter an integer: 0
Which player to ask from? Enter an integer: 1
Request is successful
Player 1: A1
Player Hands: Q of C Q of S Q of H K of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C 9 of C 10 of S 9 of S 
Player Books: A of S A of D A of H A of C 
Player 3: C3
Player Hands: 9 of H Q of C A of H A of C Q of H 10 of S 
Player Books: K of H K of S K of D K of D 
Player 4: D4
Player Hands: 9 of D 9 of S K of S 10 of H K of C 9 of C 
Player Books: 
Player 5: E5
Player Hands: Q of D Q of D 
Player Books: J of C J of S J of H J of H 
Player 4 D4's turn: 
Which card rank to ask for? Enter an integer: 0
Which player to ask from? Enter an integer: 5
Request is not successful, Go fish
Successfully get requested rank: 9
current player has four of a kind
Player 1: A1
Player Hands: Q of C Q of S Q of H K of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C 9 of C 10 of S 9 of S 
Player Books: A of S A of D A of H A of C 
Player 3: C3
Player Hands: 9 of H Q of C A of H A of C Q of H 10 of S 
Player Books: K of H K of S K of D K of D 
Player 4: D4
Player Hands: K of S 10 of H K of C 
Player Books: 9 of D 9 of S 9 of C 9 of H 
Player 5: E5
Player Hands: Q of D Q of D 
Player Books: J of C J of S J of H J of H 
Player 4 D4's turn: 
Which card rank to ask for? Enter an integer: 3
Which player to ask from? Enter an integer: 5
Request is not successful, Go fish
Successfully get requested rank: K
Player 1: A1
Player Hands: Q of C Q of S Q of H K of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C 9 of C 10 of S 9 of S 
Player Books: A of S A of D A of H A of C 
Player 3: C3
Player Hands: 9 of H Q of C A of H A of C Q of H 10 of S 
Player Books: K of H K of S K of D K of D 
Player 4: D4
Player Hands: K of S 10 of H K of C K of C 
Player Books: 9 of D 9 of S 9 of C 9 of H 
Player 5: E5
Player Hands: Q of D Q of D 
Player Books: J of C J of S J of H J of H 
Player 4 D4's turn: 
Which card rank to ask for? Enter an integer: 3
Which player to ask from? Enter an integer: 1
Request is successful
current player has four of a kind
Player 1: A1
Player Hands: Q of C Q of S Q of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C 9 of C 10 of S 9 of S 
Player Books: A of S A of D A of H A of C 
Player 3: C3
Player Hands: 9 of H Q of C A of H A of C Q of H 10 of S 
Player Books: K of H K of S K of D K of D 
Player 4: D4
Player Hands: 10 of H 
Player Books: 9 of D 9 of S 9 of C 9 of H K of S K of C K of C K of H 
Player 5: E5
Player Hands: Q of D Q of D 
Player Books: J of C J of S J of H J of H 
Player 4 D4's turn: 
Which card rank to ask for? Enter an integer: 4
Which player to ask from? Enter an integer: 5
Request is not successful, Go fish
Successfully get requested rank: 10
Player 1: A1
Player Hands: Q of C Q of S Q of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C 9 of C 10 of S 9 of S 
Player Books: A of S A of D A of H A of C 
Player 3: C3
Player Hands: 9 of H Q of C A of H A of C Q of H 10 of S 
Player Books: K of H K of S K of D K of D 
Player 4: D4
Player Hands: 10 of H 10 of H 
Player Books: 9 of D 9 of S 9 of C 9 of H K of S K of C K of C K of H 
Player 5: E5
Player Hands: Q of D Q of D 
Player Books: J of C J of S J of H J of H 
Player 4 D4's turn: 
Which card rank to ask for? Enter an integer: 4
Which player to ask from? Enter an integer: 5
Request is not successful, Go fish
Failed to get requested rank, gotQ
Player 1: A1
Player Hands: Q of C Q of S Q of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C 9 of C 10 of S 9 of S 
Player Books: A of S A of D A of H A of C 
Player 3: C3
Player Hands: 9 of H Q of C A of H A of C Q of H 10 of S 
Player Books: K of H K of S K of D K of D 
Player 4: D4
Player Hands: 10 of H 10 of H Q of S 
Player Books: 9 of D 9 of S 9 of C 9 of H K of S K of C K of C K of H 
Player 5: E5
Player Hands: Q of D Q of D 
Player Books: J of C J of S J of H J of H 
Player 5 E5's turn: 
Which card rank to ask for? Enter an integer: 2
Which player to ask from? Enter an integer: 4
Request is successful
Player 1: A1
Player Hands: Q of C Q of S Q of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C 9 of C 10 of S 9 of S 
Player Books: A of S A of D A of H A of C 
Player 3: C3
Player Hands: 9 of H Q of C A of H A of C Q of H 10 of S 
Player Books: K of H K of S K of D K of D 
Player 4: D4
Player Hands: 10 of H 10 of H 
Player Books: 9 of D 9 of S 9 of C 9 of H K of S K of C K of C K of H 
Player 5: E5
Player Hands: Q of D Q of D Q of S 
Player Books: J of C J of S J of H J of H 
Player 5 E5's turn: 
Which card rank to ask for? Enter an integer: 2
Which player to ask from? Enter an integer: 3
Request is successful
current player has four of a kind
Player 1: A1
Player Hands: Q of C Q of S Q of H 
Player Books: J of C J of D J of D J of S 
Player 2: B2
Player Hands: 10 of C 9 of C 10 of S 9 of S 
Player Books: A of S A of D A of H A of C 
Player 3: C3
Player Hands: 9 of H A of H A of C Q of H 10 of S 
Player Books: K of H K of S K of D K of D 
Player 4: D4
Player Hands: 10 of H 10 of H 
Player Books: 9 of D 9 of S 9 of C 9 of H K of S K of C K of C K of H 
Player 5: E5
Player Hands: 
Player Books: J of C J of S J of H J of H Q of D Q of D Q of S Q of C 
Player 5 E5's turn: 
Which card rank to ask for? Enter an integer: 1
Which player to ask from? Enter an integer: 1
rank input failed
Which card rank to ask for? Enter an integer: ^C
[y.zichen@shell lab3]$ ./lab3 GoFish Pinochle A1 B2 C3 D4 E5
game name is goFish
inside create
GoFish
PinochleUsing Pinochle deck, rank 9 ~ A correspond to 0 ~ 5
end of collecting books
Round: 1
Player 1: A1
Player Hands: 9 of C 10 of D 9 of S 10 of S Q of H 9 of D K of D 
Player Books: 
Player 2: B2
Player Hands: K of C 9 of H 10 of D J of S Q of S K of S 10 of H 
Player Books: 
Player 3: C3
Player Hands: J of D K of D A of H A of C 9 of H A of S 10 of C 
Player Books: 
Player 4: D4
Player Hands: J of S K of S Q of C Q of D Q of S A of D A of S 
Player Books: 
Player 5: E5
Player Hands: Q of C J of C Q of H A of H K of C J of H J of C 
Player Books: 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: ^C
[y.zichen@shell lab3]$ make
g++ -o lab3 -DUNIX   -DTEMPLATE_HEADERS_INCLUDE_SOURCE cardsuit.cpp pinochle.cpp holdEm.cpp main.cpp game.cpp pinochleGame.cpp holdEmGame.cpp uno.cpp goFishGame.cpp 
[y.zichen@shell lab3]$ ./lab3 GoFish Pinochle A1 B2 C3 D4 E5
PinochleUsing Pinochle deck, rank 9 ~ A correspond to 0 ~ 5
current player has four of a kind
end of collecting books
Round: 1
Player 1: A1
Player Hands: J of D A of S 10 of S 9 of D K of D 9 of C Q of D 
Player Books: 
Player 2: B2
Player Hands: 10 of S A of H A of S 
Player Books: K of D K of C K of H K of S 
Player 3: C3
Player Hands: 9 of S A of D Q of S Q of D J of S Q of S A of H 
Player Books: 
Player 4: D4
Player Hands: Q of C 10 of C Q of H J of C J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 9 of D 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: 0
Which player to ask from? Enter an integer: 3
Request is successful
Player 1: A1
Player Hands: J of D A of S 10 of S 9 of D K of D 9 of C Q of D 9 of S 
Player Books: 
Player 2: B2
Player Hands: 10 of S A of H A of S 
Player Books: K of D K of C K of H K of S 
Player 3: C3
Player Hands: A of D Q of S Q of D J of S Q of S A of H 
Player Books: 
Player 4: D4
Player Hands: Q of C 10 of C Q of H J of C J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 9 of D 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: 0
Which player to ask from? Enter an integer: 5
Request is successful
current player has four of a kind
Player 1: A1
Player Hands: J of D A of S 10 of S K of D Q of D 
Player Books: 9 of D 9 of C 9 of S 9 of D 
Player 2: B2
Player Hands: 10 of S A of H A of S 
Player Books: K of D K of C K of H K of S 
Player 3: C3
Player Hands: A of D Q of S Q of D J of S Q of S A of H 
Player Books: 
Player 4: D4
Player Hands: Q of C 10 of C Q of H J of C J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: 0
Which player to ask from? Enter an integer: 2
Rank input failed
Which card rank to ask for? Enter an integer: 2
Which player to ask from? Enter an integer: 5
Request is not successful, Go fish
Successfully get requested rank: J
Player 1: A1
Player Hands: J of D A of S 10 of S K of D Q of D J of S 
Player Books: 9 of D 9 of C 9 of S 9 of D 
Player 2: B2
Player Hands: 10 of S A of H A of S 
Player Books: K of D K of C K of H K of S 
Player 3: C3
Player Hands: A of D Q of S Q of D J of S Q of S A of H 
Player Books: 
Player 4: D4
Player Hands: Q of C 10 of C Q of H J of C J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: 2
Which player to ask from? Enter an integer: 3
Request is successful
Player 1: A1
Player Hands: J of D A of S 10 of S K of D Q of D J of S J of S 
Player Books: 9 of D 9 of C 9 of S 9 of D 
Player 2: B2
Player Hands: 10 of S A of H A of S 
Player Books: K of D K of C K of H K of S 
Player 3: C3
Player Hands: A of D Q of S Q of D Q of S A of H 
Player Books: 
Player 4: D4
Player Hands: Q of C 10 of C Q of H J of C J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: 2
Which player to ask from? Enter an integer: 4
Request is successful
current player has four of a kind
Player 1: A1
Player Hands: A of S 10 of S K of D Q of D 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S A of H A of S 
Player Books: K of D K of C K of H K of S 
Player 3: C3
Player Hands: A of D Q of S Q of D Q of S A of H 
Player Books: 
Player 4: D4
Player Hands: Q of C 10 of C Q of H J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: 1
Which player to ask from? Enter an integer: 3
Request is not successful, Go fish
Failed to get requested rank, got J
Player 1: A1
Player Hands: A of S 10 of S K of D Q of D J of D 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S A of H A of S 
Player Books: K of D K of C K of H K of S 
Player 3: C3
Player Hands: A of D Q of S Q of D Q of S A of H 
Player Books: 
Player 4: D4
Player Hands: Q of C 10 of C Q of H J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 2 B2's turn: 
Which card rank to ask for? Enter an integer: 5
Which player to ask from? Enter an integer: 1
Request is successful
Player 1: A1
Player Hands: 10 of S K of D Q of D J of D 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S A of H A of S A of S 
Player Books: K of D K of C K of H K of S 
Player 3: C3
Player Hands: A of D Q of S Q of D Q of S A of H 
Player Books: 
Player 4: D4
Player Hands: Q of C 10 of C Q of H J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 2 B2's turn: 
Which card rank to ask for? Enter an integer: 5
Which player to ask from? Enter an integer: 3
Request is successful
current player has four of a kind
Player 1: A1
Player Hands: 10 of S K of D Q of D J of D 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: Q of S Q of D Q of S A of H 
Player Books: 
Player 4: D4
Player Hands: Q of C 10 of C Q of H J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 2 B2's turn: 
Which card rank to ask for? Enter an integer: 1
Which player to ask from? Enter an integer: 1
Request is successful
Player 1: A1
Player Hands: K of D Q of D J of D 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: Q of S Q of D Q of S A of H 
Player Books: 
Player 4: D4
Player Hands: Q of C 10 of C Q of H J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 2 B2's turn: 
Which card rank to ask for? Enter an integer: 1
Which player to ask from? Enter an integer: 1
Request is not successful, Go fish
Successfully get requested rank: 10
Player 1: A1
Player Hands: K of D Q of D J of D 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 10 of H 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: Q of S Q of D Q of S A of H 
Player Books: 
Player 4: D4
Player Hands: Q of C 10 of C Q of H J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 2 B2's turn: 
Which card rank to ask for? Enter an integer: 1
Which player to ask from? Enter an integer: 3
Request is not successful, Go fish
Failed to get requested rank, got A
Player 1: A1
Player Hands: K of D Q of D J of D 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 10 of H A of C 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: Q of S Q of D Q of S A of H 
Player Books: 
Player 4: D4
Player Hands: Q of C 10 of C Q of H J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 3 C3's turn: 
Which card rank to ask for? Enter an integer: 3
Which player to ask from? Enter an integer: 4
Request is successful
current player has four of a kind
Player 1: A1
Player Hands: K of D Q of D J of D 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 10 of H A of C 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: A of H 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C Q of H J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 3 C3's turn: 
Which card rank to ask for? Enter an integer: 5
Which player to ask from? Enter an integer: 1
Request is not successful, Go fish
Failed to get requested rank, got K
Player 1: A1
Player Hands: K of D Q of D J of D 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 10 of H A of C 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: A of H K of S 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C Q of H J of H J of H 10 of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 4 D4's turn: 
Which card rank to ask for? Enter an integer: 2
Which player to ask from? Enter an integer: 1
Request is successful
Player 1: A1
Player Hands: K of D Q of D 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 10 of H A of C 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: A of H K of S 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C Q of H J of H J of H 10 of D J of D 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 4 D4's turn: 
Which card rank to ask for? Enter an integer: 2
Which player to ask from? Enter an integer: 5
Request is not successful, Go fish
Failed to get requested rank, got 9
Player 1: A1
Player Hands: K of D Q of D 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 10 of H A of C 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: A of H K of S 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C Q of H J of H J of H 10 of D J of D 9 of C 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C 
Player Books: 
Player 5 E5's turn: 
Which card rank to ask for? Enter an integer: 3
Which player to ask from? Enter an integer: 4
Request is successful
Player 1: A1
Player Hands: K of D Q of D 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 10 of H A of C 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: A of H K of S 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C J of H J of H 10 of D J of D 9 of C 
Player Books: 
Player 5: E5
Player Hands: Q of H 10 of D 10 of H 9 of H K of H Q of C Q of H 
Player Books: 
Player 5 E5's turn: 
Which card rank to ask for? Enter an integer: 3
Which player to ask from? Enter an integer: 1
Request is successful
current player has four of a kind
Player 1: A1
Player Hands: K of D 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 10 of H A of C 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: A of H K of S 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C J of H J of H 10 of D J of D 9 of C 
Player Books: 
Player 5: E5
Player Hands: 10 of D 10 of H 9 of H K of H 
Player Books: Q of H Q of C Q of H Q of D 
Player 5 E5's turn: 
Which card rank to ask for? Enter an integer: 3
Which player to ask from? Enter an integer: 1
Rank input failed
Which card rank to ask for? Enter an integer: 4
Which player to ask from? Enter an integer: 1
Request is successful
Player 1: A1
Player Hands: 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 10 of H A of C 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: A of H K of S 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C J of H J of H 10 of D J of D 9 of C 
Player Books: 
Player 5: E5
Player Hands: 10 of D 10 of H 9 of H K of H K of D 
Player Books: Q of H Q of C Q of H Q of D 
Player 5 E5's turn: 
Which card rank to ask for? Enter an integer: 4
Which player to ask from? Enter an integer: 4
Request is not successful, Go fish
Failed to get requested rank, got J
Player 1: A1
Number of books collected: 8
Player 2: B2
Number of books collected: 8
Player 3: C3
Number of books collected: 4
Player 4: D4
Number of books collected: 0
Player 5: E5
Number of books collected: 4

Round: 2
Player 1: A1
Player Hands: 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 10 of H A of C 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: A of H K of S 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C J of H J of H 10 of D J of D 9 of C 
Player Books: 
Player 5: E5
Player Hands: 10 of D 10 of H 9 of H K of H K of D J of C 
Player Books: Q of H Q of C Q of H Q of D 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: 0
Which player to ask from? Enter an integer: 3
Request is not successful, Go fish
Successfully get requested rank: 9
Player 1: A1
Player Hands: 9 of S 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 10 of H A of C 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: A of H K of S 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C J of H J of H 10 of D J of D 9 of C 
Player Books: 
Player 5: E5
Player Hands: 10 of D 10 of H 9 of H K of H K of D J of C 
Player Books: Q of H Q of C Q of H Q of D 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: 0
Which player to ask from? Enter an integer: 5
Request is successful
Player 1: A1
Player Hands: 9 of S 9 of H 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 10 of H A of C 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: A of H K of S 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C J of H J of H 10 of D J of D 9 of C 
Player Books: 
Player 5: E5
Player Hands: 10 of D 10 of H K of H K of D J of C 
Player Books: Q of H Q of C Q of H Q of D 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: 0
Which player to ask from? Enter an integer: 2
Request is not successful, Go fish
Failed to get requested rank, got K
Player 1: A1
Player Hands: 9 of S 9 of H K of C 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: 10 of S 10 of S 10 of H A of C 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 
Player 3: C3
Player Hands: A of H K of S 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C J of H J of H 10 of D J of D 9 of C 
Player Books: 
Player 5: E5
Player Hands: 10 of D 10 of H K of H K of D J of C 
Player Books: Q of H Q of C Q of H Q of D 
Player 2 B2's turn: 
Which card rank to ask for? Enter an integer: 1
Which player to ask from? Enter an integer: 5
Request is successful
current player has four of a kind
Player 1: A1
Player Hands: 9 of S 9 of H K of C 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: A of C 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 10 of S 10 of S 10 of H 10 of D 
Player 3: C3
Player Hands: A of H K of S 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C J of H J of H 10 of D J of D 9 of C 
Player Books: 
Player 5: E5
Player Hands: 10 of H K of H K of D J of C 
Player Books: Q of H Q of C Q of H Q of D 
Player 2 B2's turn: 
Which card rank to ask for? Enter an integer: 5
Which player to ask from? Enter an integer: 3
Request is successful
Player 1: A1
Player Hands: 9 of S 9 of H K of C 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: A of C A of H 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 10 of S 10 of S 10 of H 10 of D 
Player 3: C3
Player Hands: K of S 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C J of H J of H 10 of D J of D 9 of C 
Player Books: 
Player 5: E5
Player Hands: 10 of H K of H K of D J of C 
Player Books: Q of H Q of C Q of H Q of D 
Player 2 B2's turn: 
Which card rank to ask for? Enter an integer: 5
Which player to ask from? Enter an integer: 3
Request is not successful, Go fish
Failed to get requested rank, got 9
Player 1: A1
Player Hands: 9 of S 9 of H K of C 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: A of C A of H 9 of H 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 10 of S 10 of S 10 of H 10 of D 
Player 3: C3
Player Hands: K of S 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C J of H J of H 10 of D J of D 9 of C 
Player Books: 
Player 5: E5
Player Hands: 10 of H K of H K of D J of C 
Player Books: Q of H Q of C Q of H Q of D 
Player 3 C3's turn: 
Which card rank to ask for? Enter an integer: 4 
Which player to ask from? Enter an integer: 1
Request is successful
Player 1: A1
Player Hands: 9 of S 9 of H 
Player Books: 9 of D 9 of C 9 of S 9 of D J of D J of S J of S J of C 
Player 2: B2
Player Hands: A of C A of H 9 of H 
Player Books: K of D K of C K of H K of S A of H A of S A of S A of D 10 of S 10 of S 10 of H 10 of D 
Player 3: C3
Player Hands: K of S K of C 
Player Books: Q of S Q of D Q of S Q of C 
Player 4: D4
Player Hands: 10 of C J of H J of H 10 of D J of D 9 of C 
Player Books: 
Player 5: E5
Player Hands: 10 of H K of H K of D J of C 
Player Books: Q of H Q of C Q of H Q of D 
Player 3 C3's turn: 
Which card rank to ask for? Enter an integer: 

...

```



#### Texas HoldEm
```
[y.zichen@shell lab3]$ ./lab3 GoFish HoldEm A1 B2 C3 D4 E5
Round: 1
Player 1: A1
Player Hands: 8 of C 8 of H 8 of D 5 of S 6 of C 6 of S 7 of C 
Player Books: 
Player 2: B2
Player Hands: Q of S J of S Q of H K of D J of C 8 of S 5 of C 
Player Books: 
Player 3: C3
Player Hands: 5 of H K of C 5 of D K of H Q of D 6 of D A of S 
Player Books: 
Player 4: D4
Player Hands: 4 of D 2 of H 10 of D 2 of S 10 of C 9 of S 4 of C 
Player Books: 
Player 5: E5
Player Hands: 3 of C 7 of S Q of C 2 of D 3 of H 10 of H 4 of H 
Player Books: 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: 6
Which player to ask from? Enter an integer: 2
Request is successful
current player has four of a kind
Player 1: A1
Player Hands: 5 of S 6 of C 6 of S 7 of C 
Player Books: 8 of C 8 of H 8 of D 8 of S 
Player 2: B2
Player Hands: Q of S J of S Q of H K of D J of C 5 of C 
Player Books: 
Player 3: C3
Player Hands: 5 of H K of C 5 of D K of H Q of D 6 of D A of S 
Player Books: 
Player 4: D4
Player Hands: 4 of D 2 of H 10 of D 2 of S 10 of C 9 of S 4 of C 
Player Books: 
Player 5: E5
Player Hands: 3 of C 7 of S Q of C 2 of D 3 of H 10 of H 4 of H 
Player Books: 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: 10
Which player to ask from? Enter an integer: 5
rank input failedWhich card rank to ask for? Enter an integer: 4
Which player to ask from? Enter an integer: 2
Request is not successful, Go fish
Failed to get requested rank
Player 1: A1
Player Hands: 5 of S 6 of C 6 of S 7 of C 3 of S 
Player Books: 8 of C 8 of H 8 of D 8 of S 
Player 2: B2
Player Hands: Q of S J of S Q of H K of D J of C 5 of C 
Player Books: 
Player 3: C3
Player Hands: 5 of H K of C 5 of D K of H Q of D 6 of D A of S 
Player Books: 
Player 4: D4
Player Hands: 4 of D 2 of H 10 of D 2 of S 10 of C 9 of S 4 of C 
Player Books: 
Player 5: E5
Player Hands: 3 of C 7 of S Q of C 2 of D 3 of H 10 of H 4 of H 
Player Books: 
Player 2 B2's turn: 
Which card rank to ask for? Enter an integer: 10
Which player to ask from? Enter an integer: 3
Request is successful
Player 1: A1
Player Hands: 5 of S 6 of C 6 of S 7 of C 3 of S 
Player Books: 8 of C 8 of H 8 of D 8 of S 
Player 2: B2
Player Hands: Q of S J of S Q of H K of D J of C 5 of C Q of D 
Player Books: 
Player 3: C3
Player Hands: 5 of H K of C 5 of D K of H 6 of D A of S 
Player Books: 
Player 4: D4
Player Hands: 4 of D 2 of H 10 of D 2 of S 10 of C 9 of S 4 of C 
Player Books: 
Player 5: E5
Player Hands: 3 of C 7 of S Q of C 2 of D 3 of H 10 of H 4 of H 
Player Books: 
Player 2 B2's turn: 
Which card rank to ask for? Enter an integer: 10
Which player to ask from? Enter an integer: 5
Request is successful
current player has four of a kind

Player 1: A1
Player Hands: 5 of S 6 of C 6 of S 7 of C 3 of S 
Player Books: 8 of C 8 of H 8 of D 8 of S 
Player 2: B2
Player Hands: J of S K of D J of C 5 of C 
Player Books: Q of S Q of H Q of D Q of C 
Player 3: C3
Player Hands: 5 of H K of C 5 of D K of H 6 of D A of S 
Player Books: 
Player 4: D4
Player Hands: 4 of D 2 of H 10 of D 2 of S 10 of C 9 of S 4 of C 
Player Books: 
Player 5: E5
Player Hands: 3 of C 7 of S 2 of D 3 of H 10 of H 4 of H 
Player Books: 
Player 2 B2's turn: 
Which card rank to ask for? Enter an integer: 4
Which player to ask from? Enter an integer: 4
rank input failedWhich card rank to ask for? Enter an integer: 3
Which player to ask from? Enter an integer: 5
Request is not successful, Go fish
Failed to get requested rank
Player 1: A1
Player Hands: 5 of S 6 of C 6 of S 7 of C 3 of S 
Player Books: 8 of C 8 of H 8 of D 8 of S 
Player 2: B2
Player Hands: J of S K of D J of C 5 of C 9 of D 
Player Books: Q of S Q of H Q of D Q of C 
Player 3: C3
Player Hands: 5 of H K of C 5 of D K of H 6 of D A of S 
Player Books: 
Player 4: D4
Player Hands: 4 of D 2 of H 10 of D 2 of S 10 of C 9 of S 4 of C 
Player Books: 
Player 5: E5
Player Hands: 3 of C 7 of S 2 of D 3 of H 10 of H 4 of H 
Player Books: 
Player 3 C3's turn: 
Which card rank to ask for? Enter an integer: 3
Which player to ask from? Enter an integer: 5
Request is not successful, Go fish
Failed to get requested rank
Player 1: A1
Player Hands: 5 of S 6 of C 6 of S 7 of C 3 of S 
Player Books: 8 of C 8 of H 8 of D 8 of S 
Player 2: B2
Player Hands: J of S K of D J of C 5 of C 9 of D 
Player Books: Q of S Q of H Q of D Q of C 
Player 3: C3
Player Hands: 5 of H K of C 5 of D K of H 6 of D A of S J of D 
Player Books: 
Player 4: D4
Player Hands: 4 of D 2 of H 10 of D 2 of S 10 of C 9 of S 4 of C 
Player Books: 
Player 5: E5
Player Hands: 3 of C 7 of S 2 of D 3 of H 10 of H 4 of H 
Player Books: 
Player 4 D4's turn: 
Which card rank to ask for? Enter an integer: 8
Which player to ask from? Enter an integer: 1
Request is not successful, Go fish
Failed to get requested rank
Player 1: A1
Player Hands: 5 of S 6 of C 6 of S 7 of C 3 of S 
Player Books: 8 of C 8 of H 8 of D 8 of S 
Player 2: B2
Player Hands: J of S K of D J of C 5 of C 9 of D 
Player Books: Q of S Q of H Q of D Q of C 
Player 3: C3
Player Hands: 5 of H K of C 5 of D K of H 6 of D A of S J of D 
Player Books: 
Player 4: D4
Player Hands: 4 of D 2 of H 10 of D 2 of S 10 of C 9 of S 4 of C A of H 
Player Books: 
Player 5: E5
Player Hands: 3 of C 7 of S 2 of D 3 of H 10 of H 4 of H 
Player Books: 
Player 5 E5's turn: 
Which card rank to ask for? Enter an integer: 1
Which player to ask from? Enter an integer: 1
Request is successful
Player 1: A1
Player Hands: 5 of S 6 of C 6 of S 7 of C 
Player Books: 8 of C 8 of H 8 of D 8 of S 
Player 2: B2
Player Hands: J of S K of D J of C 5 of C 9 of D 
Player Books: Q of S Q of H Q of D Q of C 
Player 3: C3
Player Hands: 5 of H K of C 5 of D K of H 6 of D A of S J of D 
Player Books: 
Player 4: D4
Player Hands: 4 of D 2 of H 10 of D 2 of S 10 of C 9 of S 4 of C A of H 
Player Books: 
Player 5: E5
Player Hands: 3 of C 7 of S 2 of D 3 of H 10 of H 4 of H 3 of S 
Player Books: 
Player 5 E5's turn: 
Which card rank to ask for? Enter an integer: 3
Which player to ask from? Enter an integer: 1
rank input failed
Which card rank to ask for? Enter an integer: 1
Which player to ask from? Enter an integer: 1
Request is not successful, Go fish
Failed to get requested rank
Player 1: A1
Number of books collected: 4
Player 2: B2
Number of books collected: 4
Player 3: C3
Number of books collected: 0
Player 4: D4
Number of books collected: 0
Player 5: E5
Number of books collected: 0

Round: 2
Player 1: A1
Player Hands: 5 of S 6 of C 6 of S 7 of C 
Player Books: 8 of C 8 of H 8 of D 8 of S 
Player 2: B2
Player Hands: J of S K of D J of C 5 of C 9 of D 
Player Books: Q of S Q of H Q of D Q of C 
Player 3: C3
Player Hands: 5 of H K of C 5 of D K of H 6 of D A of S J of D 
Player Books: 
Player 4: D4
Player Hands: 4 of D 2 of H 10 of D 2 of S 10 of C 9 of S 4 of C A of H 
Player Books: 
Player 5: E5
Player Hands: 3 of C 7 of S 2 of D 3 of H 10 of H 4 of H 3 of S J of H 
Player Books: 
Player 1 A1's turn: 
Which card rank to ask for? Enter an integer: ^C
... 

```


### Design decisions

1. Refactored CardSet
Accessors: Replaced pointer access with begin() and end() iterators for safe, STL-compliant access.
Sort Method: Added sort() using std::sort for cleaner sorting logic.
Type Aliases: Added typedefs for card_type, rank_type, suit_type, and iterator to improve readability.
Collection Methods: Moved collect() to CardSet and added collect_if() to move cards based on conditions.
Request Method: Added request() to transfer a specific card between players, supporting Go Fish logic.
2. Added UnoDeck
Enums: Created Color and UnoRank enums to represent Uno's unique properties.
Operator Overloads: Added operator<< for printing and operator++ for iteration.
Deck Composition: Populated deck with 112 cards according to official Uno rules.
3. Implemented GoFishGame
Template Design: Supports decks of any type (HoldEm, Pinochle, Uno) with static_assert for type validation.
Player Setup: Uses deal() to distribute 7 cards each (2 players) or 5 cards each (3-5 players).
Turn Logic: Players request cards from each other using request(). If unsuccessful, they "go fish" from the deck.
Book Collection: Uses collect_if() to move 4-of-a-kind cards from player hands into their book collections.
Game Loop: Loops over players until one player remains or all cards are in books, declaring the winner.
4. Changes to create() and main()
Command Line Input: Added support for "GoFish" with deck types (HoldEm, Pinochle, Uno) and player names.
Error Handling: Used try-catch to manage invalid input and display helpful error messages.
5. Testing & Debugging
Test Cases: Tested all deck types, player counts, and input errors. Verified correct player elimination, book collection, and scorekeeping.
Fixes: Resolved iterator mismatch issues, template parameter validation, off-by-one player eliminations, and proper edge case handling.
