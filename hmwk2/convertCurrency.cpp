// convertCurrency.cpp

// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Homework 2 - Problem #5

#include <iostream>
#include <iomanip>
using namespace std;

int bolts, coins, gems = 0;
int main()
{
    cout << "Enter the number of Bolts:" << endl;
    cin >> bolts;
    while (bolts >= 23)
    {
        coins += 1;
        bolts -= 23;
    }

    while (coins >= 13)
    {
        gems += 1;
        coins -= 13;
    }
    cout << gems << " Gem(s) " << coins << " GoldCoin(s) " << bolts << " Bolt(s)" << endl;
    return 0;
}