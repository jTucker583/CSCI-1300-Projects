// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Homework 3 - Problem #4

#include <iostream>
using namespace std;

int main()
{
    double wifi_speed1 = 0;
    double wifi_speed2 = 0;
    double wifi_speed3 = 0;

    cout << "Enter wifi speeds over the last 3 classes:" << endl;
    cin >> wifi_speed1;
    cin >> wifi_speed2;
    cin >> wifi_speed3; // cin only takes the first bit of characters, not the space.
    if (wifi_speed1 < 0 or wifi_speed1 < 0 or wifi_speed1 < 0)
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }

    if (wifi_speed1 > wifi_speed2 and wifi_speed2 > wifi_speed3) // wifi gets slower
    {
        cout << "The wifi is getting slower!" << endl;
    }
    else if (wifi_speed1 < wifi_speed2 and wifi_speed2 < wifi_speed3) // wifi gets faster
    {
        cout << "The wifi is getting faster!" << endl;
    }
    else // wifi changes unpredectably
    {
        cout << "The wifi speed is changing unpredictably." << endl;
    }
}