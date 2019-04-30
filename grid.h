#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <sstream>
#include "game_manager.h"

using namespace std;

enum ColorType{Forest, Hills, Fields, Pasture, Mountain};
// The base class for all Uno Cards
class Grid{
    public:
    // Mutators and Accessors

    void setNumber1(int);
    void setNumber2(int);
    int getNumber1();
    int getNumber2();
    
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
    NumberGrid(int);
    string render(int);
    bool play(Grid, GameManager&);
};

class HouseGrid : public Grid{
    public:
    NumberGrid(int);
    string render(int);
    bool play(Grid, GameManager&);
};

class CityGrid : public Grid{
    public:
    NumberGrid(int);
    string render(int);
    bool play(Grid, GameManager&);
};

#endif