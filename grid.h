#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <sstream>
#include "game_manager.h"

using namespace std;

enum LandType{Forest, Hills, Fields, Pasture, Mountain};
// The base class for all Uno Cards
class Grid{
    protected:
    // describes the card's color
    LandType land;
    // describes the card's number
    int number;
    
    string playerName;
    
    public:
    // Mutators and Accessors
    void setNumber(int);
    void setNumber();

    
    // virtual function to render the card's image in the terminal
    virtual string render(int); 
    // virutal function to call derived class' implementations
    // play returns a boolean to determine if card is valid to play and is 
    // passed the game manager to update changes in the game's state such as
    // turn order reversing or skipping next turn.
    virtual bool play(Grid, GameManager&);  
};

class ClearGrid : public Grid{
    public:
    ClearGrid(LandType, int);
    string render(int);
    bool play(Grid, GameManager&);
};

class HouseGrid : public Grid{
    public:
    HouseGrid(LandType, int);
    string render(int);
    bool play(Grid, GameManager&);
};


#endif