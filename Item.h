#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

class Item
{
public:
    // constructors
    Item();
    Item(string type, string name);
    Item(string type, string name, int amount);
    Item(double amount); // for gold
    // getter functions
    string getType() const;
    string getName() const;
    int getAmount() const;
    double getNum() const; // for gold

    // setter functions
    void setType(string type);
    void setName(string name);
    void setAmount(int amount);
    void setNum(double amount); // for gold

private:
    string type_;
    string name_; // intended to be used for specifying weapons and cookingware, without creating a class specifically for them
    int amount_;
    double num_ = 0; // for currency
};
#endif