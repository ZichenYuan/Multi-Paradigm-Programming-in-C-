# Lab1
## Group Members
- Sunny Yuan (y.zichen@wustl.edu)
- Kathy Pan (kaiyun.p@wustl.edu)
- Samantha Zheng (samantha.z@wustl.edu)

## Error documentation
### Compile errors
Error Message:
``` 
deck.cpp:4:6: error: redefinition of ‘void Deck<R, S>::shuffle()’
 void Deck<R, S>::shuffle() {
      ^~~~~~~~~~
In file included from deck.h:23,
                 from deck.cpp:1:
deck.cpp:4:6: note: ‘void Deck<R, S>::shuffle()’ previously declared here
 void Deck<R, S>::shuffle() {
      ^~~~~~~~~~
main.cpp: In function ‘int main()’:
main.cpp:11:27: error: ‘void Deck<R, S>::shuffle() [with R = PinochleRank; S = Suit]’ is private within this context
     pinochle_deck.shuffle();
                           ^
In file included from deck.h:23,
                 from texas.h:5,
                 from main.cpp:1:
deck.cpp:4:6: note: declared private here
 void Deck<R, S>::shuffle() {
      ^~~~~~~~~~
main.cpp:12:24: error: ‘void Deck<R, S>::shuffle() [with R = TexasRank; S = Suit]’ is private within this context
     texas_deck.shuffle();
                        ^
In file included from deck.h:23,
                 from texas.h:5,
                 from main.cpp:1:
deck.cpp:4:6: note: declared private here
 void Deck<R, S>::shuffle() {
      ^~~~~~~~~~
make: *** [Makefile:60: lab1] Error 1
```
Problem found: Accidently define `shuffle()` in both header and source file, so it is defined multiple times; also it's private by default because I defined it directly in the `Deck` class without specifying public access, after adding `Public:`, the program compile successfully.


Error message:
```
g++ -o lab1 -DUNIX   -DTEMPLATE_HEADERS_INCLUDE_SOURCE cardsuit.cpp deck.cpp pinochle.cpp texas.cpp main.cpp 
deck.cpp:6:6: error: redefinition of ‘void Deck<R, S>::shuffle()’
 void Deck<R, S>::shuffle()
      ^~~~~~~~~~
In file included from deck.h:18,
                 from deck.cpp:1:
deck.cpp:6:6: note: ‘void Deck<R, S>::shuffle()’ previously declared here
 void Deck<R, S>::shuffle()
      ^~~~~~~~~~
deck.cpp:15:6: error: redefinition of ‘void Deck<R, S>::collect(CardSet<R, S>&)’
 void Deck<R, S>::collect(CardSet<R, S> &cardset)
      ^~~~~~~~~~
In file included from deck.h:18,
                 from deck.cpp:1:
deck.cpp:15:6: note: ‘void Deck<R, S>::collect(CardSet<R, S>&)’ previously declared here
 void Deck<R, S>::collect(CardSet<R, S> &cardset)
      ^~~~~~~~~~
```
For templated classes like Deck<R, S>, the compiler needs to know the entire implementation of the class wherever it is instantiated. If you split the declaration (in deck.h) and definition (in deck.cpp), the compiler will fail to resolve the symbol correctly during the linking phase, resulting in errors.


### Runtime errors
No error occurred during runtime


## Expected Output

### Initial Output
```
```

### Final Output
Testing no arguments passed in
```
[samantha.z@shell lab1_temp]$ ./lab1
Usage: ./lab1 <GameName> <Player1> <Player2> ...
[samantha.z@shell lab1_temp]$ ./lab1 大名单 p1 p2
Error: Unknown game type "大名单".
```
Testing fewer or more than required arguments passed in
```
[samantha.z@shell lab1_temp]$ ./lab1 Pinochle p1 p2
Usage: ./lab1 Pinochle <Player1> <Player2> <Player3> <Player4>
[samantha.z@shell lab1_temp]$ ./lab1 HoldEm p1 p2 p3 p4 p5 p6 p7 p8 p9 p10
Usage: ./lab1 HoldEm <Player1> <Player2> [<Player3> ... <Player9>]
[samantha.z@shell lab1_temp]$ ./lab1 HoldEm p1 p2 p3 p4 p5 p6 p7 p8 p9
Name: p1
7 of S  A of H  

Name: p2
10 of C  4 of C  

Name: p3
3 of H  5 of C  

Name: p4
7 of D  10 of D  

Name: p5
4 of S  J of D  

Name: p6
4 of H  10 of H  

Name: p7
6 of S  8 of C  

Name: p8
6 of D  8 of S  

Name: p9
A of C  Q of H  

BOARD (flop):
8 of H  3 of S  A of D  
BOARD (turn):
8 of H  3 of S  A of D  3 of D  
BOARD (river):
8 of H  3 of S  A of D  3 of D  
5 of S  
^C
```
Normal testing, and testing for game randomness
```
[samantha.z@shell lab1_temp]$ ./lab1 HoldEm p1 p2
Name: p1
5 of C  J of H  

Name: p2
6 of D  5 of D  

BOARD (flop):
Q of H  7 of S  A of H  
BOARD (turn):
Q of H  7 of S  A of H  3 of D  
BOARD (river):
Q of H  7 of S  A of H  3 of D  
Q of S  
^C
[samantha.z@shell lab1_temp]$ ./lab1 HoldEm p1 p2
Name: p1
7 of S  10 of S  

Name: p2
4 of D  2 of S  

BOARD (flop):
8 of C  Q of D  5 of S  
BOARD (turn):
8 of C  Q of D  5 of S  3 of C  
BOARD (river):
8 of C  Q of D  5 of S  3 of C  
J of H  
^C
[samantha.z@shell lab1_temp]$ ./lab1 Pinochle p1 p2 p3 p4
Name: p1
9 of C  Q of H  10 of S  10 of D  
J of D  J of D  9 of D  K of C  
9 of H  A of D  K of H  J of H  

Name: p2
Q of D  J of H  K of S  Q of S  
A of C  9 of C  K of D  A of H  
10 of H  J of S  9 of S  9 of D  

Name: p3
10 of D  10 of C  9 of H  K of C  
J of C  10 of H  A of D  A of H  
J of C  Q of C  10 of S  Q of C  

Name: p4
J of S  A of C  K of S  K of H  
K of D  Q of D  Q of H  9 of S  
A of S  Q of S  10 of C  A of S  

^C
[samantha.z@shell lab1_temp]$ ./lab1 Pinochle p1 p2 p3 p4
Name: p1
J of D  A of H  10 of C  Q of H  
9 of H  J of C  A of S  K of H  
Q of D  A of S  K of D  K of S  

Name: p2
10 of H  Q of D  9 of C  10 of D  
9 of H  10 of S  J of S  10 of D  
J of S  A of D  K of H  K of C  

Name: p3
9 of S  9 of C  K of S  Q of H  
Q of C  J of H  J of D  J of H  
10 of H  A of D  Q of C  Q of S  

Name: p4
9 of S  10 of S  K of C  Q of S  
9 of D  J of C  A of C  9 of D  
A of C  K of D  A of H  10 of C
```

### Design decisions
