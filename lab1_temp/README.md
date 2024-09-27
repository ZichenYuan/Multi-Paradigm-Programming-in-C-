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

### Runtime errors
No error occurred during runtime


## Expected Output

### Initial Output
```
```

### Final Output
```
```