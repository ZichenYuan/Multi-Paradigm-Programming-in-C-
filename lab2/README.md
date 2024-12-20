# Lab2
## Group Members
- Sunny Yuan (y.zichen@wustl.edu)
- Kathy Pan (kaiyun.p@wustl.edu)
- Samantha Zheng (samantha.z@wustl.edu)

### Question 8
Please document why you added your own copy constructor if that is what you did, or why you instead are using the one the compiler supplies (i.e., why that one is sufficient). 

We used the default copy constructor because it creates a deep copy of the cards vector, which is sufficient.

## Error documentation
### Compile errors
```
g++ -o lab2 -DUNIX   -DTEMPLATE_HEADERS_INCLUDE_SOURCE cardsuit.cpp pinochle.cpp texas.cpp main.cpp game.cpp pinochleGame.cpp texasGame.cpp 
pinochleGame.cpp: In member function ‘void PinochleGame::collectAll()’:
pinochleGame.cpp:101:26: error: no match for ‘operator*’ (operand type is ‘CardSet<PinochleRank, Suit>’)
             deck.collect(*hand);
                          ^~~~~
make: *** [Makefile:60: lab2] Error 1
```
Solution: getting rid of the * parameter, no need to dereference

### Runtime errors
```
[y.zichen@shell lab2]$ ./lab2 Pinochle Tom David Jess John
Name: Tom
A of D  Q of D  K of C  Q of S  
K of D  9 of S  10 of S  9 of H  
10 of H  10 of S  K of S  10 of D  

Melds: 
No possible melds!

Name: David
J of C  J of D  J of D  A of H  
10 of C  J of H  A of C  10 of C  
Q of H  K of S  10 of H  Q of H  

Melds: 
No possible melds!

Name: Jess
J of H  Q of S  9 of C  10 of D  
A of D  9 of D  K of H  Q of D  
K of C  J of C  Q of C  K of D  

Melds: 
No possible melds!

Name: John
A of S  9 of H  J of S  A of C  
K of H  9 of S  9 of D  A of H  
Q of C  J of S  A of S  9 of C  

Segmentation fault (core dumped)
```
Solution: Incremented the playerHand pointer before calling `suit_independent_evaluation` resulting in the pointer pointing to something that doesn't exist. Moved `suit_independent_evaluation` before updating the pointer.

### Final Output

#### Test (Exceptions)
```
[kaiyun.p@iht32-1508.sif lab2]$ ./lab2
Usage: ./lab2 <GameName> <Player1> <Player2> ...
GameName: Pinochle or HoldEm.
Pinochle: 4 players.
HoldEm: 2-9 players.
[kaiyun.p@iht32-1508.sif lab2]$ echo $?
1
[kaiyun.p@iht32-1508.sif lab2]$ ./lab2 HoldEm
Usage: ./lab2 HoldEm <Player1> <Player2> [<Player3> ... <Player9>]
HoldEm needs 2-9 players.
[kaiyun.p@iht32-1508.sif lab2]$ echo $?
4
[kaiyun.p@iht32-1508.sif lab2]$ ./lab2 Game3
Error: Unknown game type "Game3".
[kaiyun.p@iht32-1508.sif lab2]$ echo $?
2
```

#### Pinochle
```
[y.zichen@shell lab2]$ ./lab2 Pinochle Tom David Jess John
Name: Tom
K of H  9 of S  K of S  10 of C  
9 of C  A of H  J of D  A of S  
K of C  10 of C  Q of D  A of C  

Melds: No possible melds!

Name: David
J of D  A of S  10 of S  9 of C  
J of S  J of S  Q of C  10 of D  
A of D  10 of S  Q of D  J of H  

Melds: No possible melds!

Name: Jess
9 of H  Q of H  K of D  9 of S  
Q of S  J of C  9 of H  A of H  
K of C  A of C  10 of H  10 of H  

Melds: No possible melds!

Name: John
Q of C  K of D  Q of S  J of C  
K of H  J of H  9 of D  10 of D  
Q of H  K of S  9 of D  A of D  

Melds: No possible melds!

Do you want to end the game? (Type 'yes' to end): no
Starting a new game... 

Name: Tom
J of C  K of C  J of C  A of C  
A of H  K of C  J of D  K of D  
A of S  Q of H  K of D  J of H  

Melds: No possible melds!

Name: David
9 of D  A of D  J of S  A of H  
10 of D  Q of D  J of S  A of C  
J of H  K of S  9 of S  9 of C  

Melds: No possible melds!

Name: Jess
9 of H  K of H  10 of S  Q of C  
10 of C  Q of S  Q of D  Q of H  
10 of D  9 of D  K of S  10 of C  

Melds: sixtyqueens: 60 points, 

Name: John
9 of H  10 of S  9 of C  10 of H  
A of S  J of D  9 of S  A of D  
Q of S  10 of H  K of H  Q of C  

Melds: pinochle: 40 points, 

Do you want to end the game? (Type 'yes' to end): yes
```

#### Texas HoldEm
```
[kaiyun.p@iht32-1508.sif lab2]$ ./lab2 HoldEm Apple Bob Candy Debby
Name: Apple
A of S  7 of C  

Name: Bob
2 of H  A of H  

Name: Candy
3 of S  8 of H  

Name: Debby
J of S  Q of D  

BOARD (flop):
5 of S  9 of S  4 of D  

Player rankings after the flop:
Player Apple
A of S  7 of C  5 of S  9 of S  
4 of D  
Rank: X High

Player Bob
2 of H  A of H  5 of S  9 of S  
4 of D  
Rank: X High

Player Debby
J of S  Q of D  5 of S  9 of S  
4 of D  
Rank: X High

Player Candy
3 of S  8 of H  5 of S  9 of S  
4 of D  
Rank: X High

BOARD (turn):
5 of S  9 of S  4 of D  3 of H  
BOARD (river):
5 of S  9 of S  4 of D  3 of H  
9 of H  
Do you want to end the game? (Type 'yes' to end): no
Starting a new game
Name: Apple
5 of H  Q of D  

Name: Bob
Q of S  9 of D  

Name: Candy
7 of D  9 of C  

Name: Debby
2 of S  2 of D  

BOARD (flop):
4 of H  A of C  4 of D  

Player rankings after the flop:
Player Debby
2 of S  2 of D  4 of H  A of C  
4 of D  
Rank: Two Pair

Player Bob
Q of S  9 of D  4 of H  A of C  
4 of D  
Rank: Pair

Player Apple
5 of H  Q of D  4 of H  A of C  
4 of D  
Rank: Pair

Player Candy
7 of D  9 of C  4 of H  A of C  
4 of D  
Rank: Pair

BOARD (turn):
4 of H  A of C  4 of D  2 of C  
BOARD (river):
4 of H  A of C  4 of D  2 of C  
A of D  
Do you want to end the game? (Type 'yes' to end): yes
```


### Design decisions
Custom Copy Constructor in CardSet Class Template

We implemented a custom copy constructor for the CardSet class to ensure a deep copy of the card vector, preventing unintended data sharing between CardSet objects. We also declared a default constructor using = default to let the compiler synthesize it.

Controlled Violation of Encapsulation

We added a static public member function to CardSet that returns a pointer to the protected card vector. This controlled access allows operations like sorting and evaluation, while minimizing the risk of misuse.

Meld Evaluation for Pinochle Game

We created an enum class, PinochleMelds, to represent melds, and used an array to map meld types to point values, simplifying lookups. A private function, suit_independent_evaluation, evaluates melds by making a deep copy of the player's CardSet to avoid modifying the original set.

Hold'Em Hand Evaluation Logic

The HoldEmGame class has an enum class, HoldEmHandRank, for different poker hand ranks. The holdem_hand_evaluation function uses a deep copy of the CardSet to evaluate and rank hands, ensuring the original set remains unchanged.

Nested Struct for Player Hand in Hold'Em Game

We added a nested struct in HoldEmGame to represent a player's state, including a CardSet, player name, and hand rank. This design simplifies data management and game logic.

Overloading Comparison Operators

We overloaded comparison operators for Card to facilitate card ordering by rank or suit. In HoldEmGame, we overloaded the less than (<) operator for the nested struct to rank players' hands according to game rules.

Use of Copy Constructor During Evaluation

The evaluation functions use deep copies of players' hands to maintain integrity of the original cards while allowing sorting and manipulation for evaluation purposes.

Print Representation of Melds and Hands

We overloaded operator<< for PinochleMelds and HoldEmHandRank to provide a readable representation of melds and hand ranks, making gameplay output more user-friendly and helpful for debugging.