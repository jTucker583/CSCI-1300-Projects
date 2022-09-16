// almondMilk.cpp

// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Homework 2 - Problem #3

#include <iostream>
#include <iomanip>
using namespace std;

double cart_length, cart_height, cart_volume, cart_volume_in_ounces = 0;
int main()
{
    cout << fixed << setprecision(1);
    cout << "What is the side length of the base of the carton in inches? " << endl;
    cin >> cart_length;
    cout << "What is the height of the carton in inches? " << endl;
    cin >> cart_height;
    cart_volume = cart_length * cart_length * cart_height;
    cart_volume_in_ounces = cart_volume * .55;
    cout << "The carton has a volume of " << cart_volume_in_ounces << " ounces." << endl;
    return 0;
}