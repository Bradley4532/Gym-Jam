#include <iostream>
#include <vector>
#include "grid.h"
#include "game_manager.h"

using namespace std;

/* buildDeck()
 *
 * Rececives a vector of card pointers by reference to assign derived 
 * Uno card classes to form a deck.
 *
 */
void buildGrid(vector<Grid*>){
    for(int c = Forest; c <= Mountain; c++){
        for(int m = 0; m < 7; m++){
            for(int n = 0; n < 7; n++){
                deck.push_back(new ClearGrid((LandType)l,m,n));
            }
        }
        
    }
    
}



/* shuffle()
 *
 * A reference to the deck vector is passed where random indecies are swapped
 * a specified number of times, creating a shuffled deck.
 *
 */
void shuffle(vector<Grid*>){
    Grid* temp;
    int idx1, idx2;
    for(int i = 0; i < 16; i++){
        idx1 = rand() % deck.size();
        idx2 = rand() % deck.size();
        
        temp = deck.at(idx1);
        deck.at(idx1) = deck.at(idx2);
        deck.at(idx2) = temp;
    }
}

/* renderHand()
 *
 * Renders the cards in he hand vector passed.
 *
 */
void renderGrid(vector<Grid*> hand){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                cout << hand.at(j)->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}



/* takeTurn()
 *
 * Passed references to the deck, hand, and discard vectors and a reference to 
 * the game manager. This function will resolve the turn for the current player
 * (whose index is stored in the game manager). TakeTurn will query the user for
 * input, draw cards if the previous card was a draw 2 card, or skip the current
 * players turn (see numCardsToPlay in GameManager).
 *
 */
void takeTurn(vector<Grid*> &deck, vector<Grid*> &hand, vector<Grid*> &discard, GameManager &gameManager){
    cout << "Player " << gameManager.currentPlayerIndex << "'s turn." << endl;
    
    // TODO: Draw cards if necessary (draw 2 card)
    drawCards(deck, hand, gameManager.numCardsToDraw);
    gameManager.numCardsToDraw = 0;
    renderHand(hands.at(gameManager.currentPlayerIndex));
    
    // loop for number of cards to play (0 if previously played card was a "skip" or "draw 2")
   // for(int j = 0; j < gameManager.numCardsToPlay; j++){
     if(gameManager.canPlayCard){
        cout << "What would you like to do?" << endl;
        int i;
        for(i = 0; i < hand.size(); i++){
            cout << i << ": Play Card" << endl;
        }
        cout << i << ": Draw a Card" << endl;
        int input;
        cin >> input;
        // TODO: check for valid input and loop if input is incorrect
        
        if(input < i){
            // Play card at index input
            if(hand.at(input)->play(*discard.at(discard.size()-1), gameManager)){
                Grid* temp;
                temp = hand.at(input);
                discard.push_back(temp);
                hand.erase(hand.begin() + input); // Remove card in hand at position "input"
            } else {
                cout << "Improper choice" << endl;
            }
        }else if(input == i){
            drawCards(deck, hand, 1);
        }
    }
    else{
        gameManager.canPlayCard = true;
    }
    
    // update variables for next turn
    gameManager.nextTurn();
}

int main(){
    srand(time(0));
    
    GameManager gameManager(2); // Create game for 2 players

    // vector of vectors to hold handls for n number of players
    vector<vector<Grid*>> hands(gameManager.numPlayers);
    
    buildGrid(deck);
    shuffle(deck);
    
    for(int i = 0; i < hands.size(); i++)
        drawCards(deck,hands.at(i),7);
    
    
    while(1 /* TODO: Check for winner (no cards in hand)*/){

        renderHand(hands.at(gameManager.currentPlayerIndex));
    
        takeTurn(deck, hands.at(gameManager.currentPlayerIndex), gameManager);
    }
    cout << "Congrates you win!"<< endl;
    
    exit(0);
}