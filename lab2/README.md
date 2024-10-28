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



### Design decisions