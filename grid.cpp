#include "grid.h"

void Grid::setLand(LandType l){
    land = l;
}

void Grid::setNumber(int m, int n){
    number1 = m;
    number2 = n;
}

LandType Grid::getLand(){
    return land;
}

int Grid::getNumber1(){
    return number1;
}

int Grid::getNumber2(){
    return number2;
}

NumberGrid::NumberGrid(LandType l, int m, int n){
    setLand(l);
    setNumber1(m);
    setNumber2(n);
}

string ClearGrid::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
         case 2:return "|           |";
        case 3: return "|           |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

string HouseGrid::render(int line){
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2:  
            switch(land){
            case Forest:
                return "|   Forest  |";
                break;
            case Hills:
                return "|    Hills  |";
                break;
            case Fields:
                return "|   Fields  |";
                break;
            case Pasture:
                return "|  Pasture  |";
                break;
            case Mountain:
                return "| Mountain  |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3: return "|   /^^^\\  |";
        case 4: return "|  /_____\\ |";
        case 5: return "|  |     |  |";
        case 6: return "|  |_____|  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

string CityGrid::render(int line){
    stringstream ss;
   switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2:  
            switch(land){
            case Forest:
                return "|   Forest  |";
                break;
            case Hills:
                return "|    Hills  |";
                break;
            case Fields:
                return "|   Fields  |";
                break;
            case Pasture:
                return "|  Pasture  |";
                break;
            case Mountain:
                return "| Mountain  |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3: return "|  _______  |";
        case 4: return "|  | [_] |  |";
        case 5: return "|  |     |  |";
        case 6: return "|  |_____|  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool ClearGrid::play(Card discard, GameManager &gameManager){
    return false;
}

bool HouseGrid::play(Card discard, GameManager &gameManager){
    if( number == discard.getNumber()){
        return true;
    } else {
        return false;
    }
}

