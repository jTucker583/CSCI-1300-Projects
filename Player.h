#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player
{
public:
    // constructors
    Player();
    Player(string name);
    // getter functions
    int getHunger() const;
    string getName() const;

    // setter functions
    void setHunger(int hunger);
    void setName(string name);

private:
    int const MAX_HUNGER_ = 50;
    int hunger_;
    string name_;
};
#endif