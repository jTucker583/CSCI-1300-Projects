// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Homework 3 - Problem #2

#include <iostream>
using namespace std;

int main()
{
    double budget = 0;
    char transportType;
    cout << "What is your budget?" << endl;
    cin >> budget;
    if (budget < 0) // if input for budget is invalid, stop the program
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }
    cout << "What mode of transportation would you like to take (B, T, or A)?" << endl;
    cin >> transportType;
    switch (transportType) // depending if the budget is higher than the transport type, execute whether its affordable.
    {
    case 'A':
        if (budget >= 350.93)
        {
            cout << "Yes, this vacation is within your budget!" << endl;
        }
        else
        {
            cout << "Sorry, this vacation is outside your budget." << endl;
        }
        break; // move on to next case
    case 'B':
        if (budget >= 175.25)
        {
            cout << "Yes, this vacation is within your budget!" << endl;
        }
        else
        {
            cout << "Sorry, this vacation is outside your budget." << endl;
        }
        break;
    case 'T':
        if (budget >= 240.66)
        {
            cout << "Yes, this vacation is within your budget!" << endl;
        }
        else
        {
            cout << "Sorry, this vacation is outside your budget." << endl;
        }
        break;
    default:
        cout << "Please enter a valid input." << endl; // if input for transportType is invalid, stop the program.
        return 0;
    }
    return 0;
}