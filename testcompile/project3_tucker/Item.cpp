#include "Item.h"
#include <iostream>

using namespace std;

Item::Item()
{
    type_ = "";
    name_ = "";
    amount_ = 0;
}
// player does not purchase an item, but it still needs to be initialized into the inventory system
// @overload
Item::Item(string type, string name)
{
    type_ = type;
    name_ = name;
    amount_ = 0;
}

// player purchases something from the store at the start of the game
Item::Item(string type, string name, int amount)
{
    type_ = type;
    name_ = name;
    amount_ = amount;
}
Item::Item(double amount)
{
    type_ = "currency";
    name_ = "Gold";
    amount_ = 0;
    num_ = amount;
}

string Item::getType() const
{
    return type_;
}

string Item::getName() const
{
    return name_;
}

int Item::getAmount() const
{
    return amount_;
}

void Item::setType(string type)
{
    type_ = type;
}

void Item::setName(string name)
{
    name_ = name;
}

void Item::setAmount(int amount)
{
    amount_ = amount;
}

double Item::getNum() const
{
    return num_;
}

void Item::setNum(double amount)
{
    num_ = amount;
}