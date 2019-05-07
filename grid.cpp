#include "grid.h"

void Grid::setLand(LandType l){
    land = l;
}

void Grid::setNumber(int n){
    number = n;

}
void Grid::setName(Player p){
    playernum = p;
}

void Grid::setBuilding(Building b){
    building = b;
}

Building Grid::getBuilding(){
    return building;
}

Player Grid::getName(){
    return playername;
}

LandType Grid::getLand(){
    return land;
}

int Grid::getNumber1(){
    return number1;
}


HouseGrid::HouseGrid(LandType l, Building b, int n, Player p){
    setLand(l);
    setBuilding(b);
    setNumber(n);
    setName(p);
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
        case 7: return "|           |";
        case 8: return "|           |";
        case 9: return "|___________|";
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
        case 3:
        ss << "|     " <<  number << "     |";
            return ss.str();
            break;
        case 4: 
            switch(building){
            case House:
                return "|   /^^^\\  |";
                return "|  /_____\\ |";
                return "|  |     |  |";
                return "|  |_____|  |";
                break;
            case City:
                return "|  _______  |";
                return "|  | [_] |  |";
                return "|  |     |  |";
                return "|  |_____|  |";
            default:
                return "|           |";
                return "|           |";
                return "|           |";
                return "|           |";
                break;
        case 5: 
            switch(playernum)
                return "|    Player " <<  playerNum << "     |";
                 default:
                return "|           |";
            break;
        case 6: return "|___________|";
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

