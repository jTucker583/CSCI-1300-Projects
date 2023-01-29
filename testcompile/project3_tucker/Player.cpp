#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    name_ = "";
    hunger_ = MAX_HUNGER_;
    position_[0] = 0;
    position_[1] = 0;
    death_ = false;
    stuck_ = false;
    has_armour_ = false;
}

Player::Player(string name)
{
    name_ = name;
    hunger_ = MAX_HUNGER_;
    position_[0] = 0;
    position_[1] = 0;
    death_ = false;
    stuck_ = false;
    has_armour_ = false;
}

int Player::getHunger() const
{
    return hunger_;
}
string Player::getName() const
{
    return name_;
}
string Player::getPosition() const
{
    int x_pos = position_[0];
    int y_pos = position_[1];
    return "(" + to_string(x_pos) + ", " + to_string(y_pos) + ")";
}
bool Player::getDeath() const
{
    return death_;
}
bool Player::getStuck() const
{
    return stuck_;
}
bool Player::getHasArmour() const
{
    return has_armour_;
}
void Player::setHunger(int hunger)
{
    if (hunger > 50)
    {
        hunger_ = 50;
    }
    else
    {
        hunger_ = hunger;
    }
}
void Player::setName(string name)
{
    name_ = name;
}
void Player::setPosition(int position[])
{
    position_[0] = position[0];
    position_[1] = position[1];
}
void Player::setDeath(bool death)
{
    death_ = death;
}
void Player::setStuck(bool stuck)
{
    stuck_ = stuck;
}
void Player::setHasArmour(bool armour)
{
    has_armour_ = armour;
}