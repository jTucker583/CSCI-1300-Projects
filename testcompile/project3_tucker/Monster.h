#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
using namespace std;

class Monster
{
public:
    // constructor
    Monster();
    Monster(string name, int level);
    // getter functions
    string getName() const;
    int getLevel() const;

    // setter functions
    void setName(string name);
    void setLevel(int level);

private:
    string name_;
    int level_;
};
#endif