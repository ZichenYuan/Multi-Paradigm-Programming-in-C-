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
```
```