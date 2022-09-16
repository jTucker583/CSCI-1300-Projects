// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Homework 3 - Problem #3

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int toppings = 0;
    char pizzaSize;
    double price = 0;

    cout << fixed << setprecision(2); // sets so there are two decimal places in a double
    cout << "What size pizza would you like to order?" << endl;
    cin >> pizzaSize;
    if (pizzaSize == 'S' || pizzaSize == 'M' || pizzaSize == 'L')
    {
        cout << "How many toppings do you want?" << endl;
        cin >> toppings;
        if (toppings < 0) // only if toppings is invalid.
        {
            cout << "Please enter a valid input." << endl;
            return 0;
        }
        else
        {
            switch (pizzaSize) // depending on the size of the pizza chosen, add that size to the price.
            {
            case 'S':
                price += 4.99;
                price += toppings * 0.75;
                break;
            case 'M':
                price += 5.99;
                price += toppings * 1.5;
                break;
            case 'L':
                price += 6.99;
                price += toppings * 2.25;
                break;
            }
            cout << "Your total is $" << price << endl;
            return 0;
        }
    }
    else // only if pizzaSize input is invalid
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }
}