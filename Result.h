#ifndef RESULT
#define RESULT
#include <iostream>
#include "Player.h"
using namespace std;

class Result
{
public:
    // getter functions
    Result(string name, int score, Player people[], int anger_level, int num_monsters_defeated);
    string getName();
    int getScore();
    string getPartyName(int index);
    int getAngerLevel();
    int getNumMonstersDefeated();
    // setter functions
    void setName(string name);
    void setScore(int score);
    void setAngerLevel(int anger_level);
    void setNumMonstersDefeated(int num_monsters_defeated);

private:
    string name_;
    int score_;
    int PARTY_ARR_SIZE = 5;
    Player people_[5];
    int anger_level_;
    int num_monsters_defeated_;
};
#endif