#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    name_ = "";
    hunger_ = MAX_HUNGER_;
}

Player::Player(string name)
{
    name_ = name;
    hunger_ = MAX_HUNGER_;
}

int Player::getHunger() const
{
    return hunger_;
}
string Player::getName() const
{
    return name_;
}
void Player::setHunger(int hunger)
{
    hunger_ = hunger;
}
void Player::setName(string name)
{
    name_ = name;
}
