// snowfall.cpp

// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Homework 2 - Problem #4

#include <iostream>
#include <iomanip>
using namespace std;

int days = 0, breckenridge = 25, copper = 40, vail = 28;
int main()
{
    cout << "How many days in the future would you like a prediction for?" << endl;
    cin >> days;
    breckenridge += days * (10 - 5);
    if (breckenridge < 0)
    {
        breckenridge = 0;
    }
    copper += days * (5 - 3);
    if (copper < 0)
    {
        copper = 0;
    }
    vail += days * (14 - 2);
    if (vail < 0)
    {
        vail = 0;
    }

    cout << "Breckenridge will have " << breckenridge << " inches, Vail will have " << vail << " inches, and Copper Mountain will have " << copper << " inches." << endl;

    return 0;
}