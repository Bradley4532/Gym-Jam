#ifndef RULES_H
#define RULES_H

#include <iostream>
#include <sstream>
#include "game_manager.h"
#include "grid.h"

using namespace std;

class Point{
    public:
    
    void setPoits(int);
    int getPoits;
};

class library : public Point{
    int point = point + 1;

};

class university : public Point{
    int point = point + 1;

};

class townHall : public Point{
    int point = point + 1;

};

class harvestBounty : public Point{
    int point = point + 1;

};


class Land{
    public:

    void setResource(int);
    int getResource();
   
};

class landForest : public Land{
    public:
    int wood;
};

class landHills : public Land{
    public:
    int brick;
};

class landFields : public Land{
    public:
    int grain;
};

class landPasture : public Land{
    public:
    int wool;
};

class landMountain : public Land{
    public:
    int ore;
};

#endif