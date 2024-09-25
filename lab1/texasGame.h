class TexasGame : public Game {
protected:
   // The current state of the game
   // The Hold 'Em deck
    std::vector<CardSet<TexasRank, Suit>> playerHands; 
    CardSet<Rank, Suit> shared;  // The shared board of cards

    // Protected method to deal cards
    virtual void deal();

public:
    TexasGame(int argc, const char* argv[]);
    virtual int play();
    virtual ~TexasGame() {}
};