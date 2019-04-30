#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

// The game manger class is used to store various variables concerning the 
// curent state of the game.
class GameManager{
    public:
    // number of players in the game
    int numPlayers;
    // index of the current player
    int currentPlayerIndex;
    // number of cards the player can play this turn
    // (usually 1 or 0. 0 in the cases when the last card was a skip or draw 2)
    int numCardsToPlay;
    // number of cards to draw this turn (usually 0. 2 when last card was draw 2)
    int numCardsToDraw;
    // indicates whether the index of the next player is determined by incrementing
    // or decrementing. Toggled by the reverse card.
    bool turnOrderForward;
    bool canPlayCard;
    
    
    // Constructor. Passed the number of players for the current game.
    GameManager(int);
    // Used to update the next turn.
    void nextTurn();
};


#endif