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
    string getPosition() const;
    bool getDeath() const;
    bool getStuck() const;
    bool getHasArmour() const;

    // setter functions
    void setHunger(int hunger);
    void setName(string name);
    void setPosition(int position[]); // set when a player dies.
    void setDeath(bool death);
    void setStuck(bool stuck);
    void setHasArmour(bool armour);

private:
    int MAX_HUNGER_ = 50;
    int hunger_;
    string name_;
    int position_[2]; // get from map class
    bool death_;
    bool stuck_;
    bool has_armour_;
};
#endif