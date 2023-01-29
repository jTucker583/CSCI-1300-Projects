#ifndef SORCERER_H
#define SORCERER_H
#include <iostream>
#include "NPC.h"
using namespace std;

class Monster
{
public:
    // constructor
    Sorcerer();
    // getter functions
    getDefeat() const;
    getName() const;

    // setter functions
    setDefeat(bool defeat);
    setName(string name);

private:
    bool defeat_;
};
#endif