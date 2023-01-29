#include "Monster.h"
#include <iostream>
#include <fstream>

using namespace std;
// use a vector to make a dynamic list of monsters that can be subtracted from the list
Monster::Monster()
{
    name_ = "";
    level_ = 0;
}

Monster::Monster(string name, int level)
{
    name_ = name;
    level_ = level;
}

string Monster::getName() const
{
    return name_;
}

int Monster::getLevel() const
{
    return level_;
}

void Monster::setName(string name)
{
    name_ = name;
}

void Monster::setLevel(int level)
{
    level_ = level;
}