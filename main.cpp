#include <iostream>
#include <vector>
#include "card.h"
#include "game_manager.h"

using namespace std;

/* buildDeck()
 *
 * Rececives a vector of card pointers by reference to assign derived 
 * Uno card classes to form a deck.
 *
 */
void buildDeck(vector<Card*> &deck){
    for(int c = RED; c <= YELLOW; c++){
        for(int n = 0; n < 10; n++){
            deck.push_back(new NumberCard((ColorType)c,n));
        }
        deck.push_back(new ReverseCard((ColorType)c));
        deck.push_back(new SkipCard((ColorType)c));
        deck.push_back(new Draw2Card((ColorType)c));
        deck.push_back(new WildCard(WILD));
    }
    
}

/* drawCards()
 *
 * Rececives references to the deck and hand and the number of cards to draw.
 * The specified number of cards will be removed from the deck and added to
 * the hand.
 *
 */
void drawCards(vector<Card*> &deck, vector<Card*> &hand, int numCardsToDraw){
    Card* temp;
    for(int i = 0; i < numCardsToDraw; i++){
        temp = deck.at(deck.size() - 1);
        deck.pop_back();
        hand.push_back(temp);
    }
}


/* shuffle()
 *
 * A reference to the deck vector is passed where random indecies are swapped
 * a specified number of times, creating a shuffled deck.
 *
 */
void shuffle(vector<Card*> &deck){
    Card* temp;
    int idx1, idx2;
    for(int i = 0; i < 500; i++){
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
void renderHand(vector<Card*> hand){
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

/* renderDiscard()
 *
 * Renders the top card of the passed discard vector.
 *
 */
void renderDiscard(vector<Card*> discard){
    for(int i = 0; i <= 7; i++){
        cout << discard.at(discard.size() - 1)->render(i) << endl;
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
void takeTurn(vector<Card*> &deck, vector<Card*> &hand, vector<Card*> &discard, GameManager &gameManager){
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
                Card* temp;
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
    
    GameManager gameManager(3); // Create game for 3 players
    
    vector<Card*> discard;
    vector<Card*> deck;
    // vector of vectors to hold handls for n number of players
    vector<vector<Card*>> hands(gameManager.numPlayers);
    
    buildDeck(deck);
    shuffle(deck);
    
    for(int i = 0; i < hands.size(); i++)
        drawCards(deck,hands.at(i),7);
    
    // add first card to discard
    drawCards(deck,discard,1);
    
    while(1 /* TODO: Check for winner (no cards in hand)*/){
        renderDiscard(discard);
      //  renderHand(hands.at(gameManager.currentPlayerIndex));
    
        takeTurn(deck, hands.at(gameManager.currentPlayerIndex), discard, gameManager);
    }
    cout << "Congrates you win!"<< endl;
    
    exit(0);
}