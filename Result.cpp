#include <iostream>
#include "Result.h"
#include "Player.h"

using namespace std;

Result::Result(string name, int score, Player people[], int anger_level, int num_monsters_defeated)
{
    name_ = name;
    score_ = score;
    anger_level_ = anger_level;
    num_monsters_defeated_ = num_monsters_defeated;
    for (int i = 0; i < PARTY_ARR_SIZE; i++)
    {
        people_[i] = people[i];
    }
}

string Result::getName()
{
    return name_;
}

int Result::getScore()
{
    return score_;
}

string Result::getPartyName(int index)
{
    if (index > -1 && index < 5)
    {
        return people_[index].getName();
    }
    else
    {
        return "Not a valid index!";
    }
}

int Result::getAngerLevel()
{
    return anger_level_;
}

int Result::getNumMonstersDefeated()
{
    return num_monsters_defeated_;
}

void Result::setName(string name)
{
    name_ = name;
}

void Result::setScore(int score)
{
    score_ = score;
}

void Result::setAngerLevel(int anger_level)
{
    anger_level_ = anger_level;
}

void Result::setNumMonstersDefeated(int num_monsters_defeated)
{
    num_monsters_defeated_ = num_monsters_defeated;
}