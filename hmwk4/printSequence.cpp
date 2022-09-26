// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Homework 4 - Problem #2

#include <iostream>
#include <cmath>
using namespace std;

/** Pseudocode:
 * declare int a
 * ask user for a input
 * if invalid, ask again
 * else execute a while loop containing:
 *  if a mod 2 == 0, a = floor(a/2), display a
 *  else a = 3a + 1, display a
 * if a == 1, display a
 **/

int a = 0;
int main()
{
    do
    {
        cout << "Enter  a value between 1 and 1000:" << endl;
        cin >> a;
        if (a <= 1 || a >= 1000)
        {
            cout << "Invalid input." << endl;
        }
    } while (a <= 1 || a >= 1000); // Asks again for a valid input between 1 and 1000.
    if (a > 1 && a < 1000)         // runs only when input is valid
    {
        while (a > 1)
        {
            if (a % 2 == 0) // if number is even
            {
                cout << a << endl;
                a = floor(a / 2);
            }
            else // if number is odd
            {
                cout << a << endl;
                a = 3 * a + 1;
            }
        }
        if (a == 1) // while statement won't print 1, so this finishes the program.
        {
            cout << a << endl;
        }
    }
    return 0;
}