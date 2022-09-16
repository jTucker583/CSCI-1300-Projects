// calcSigmoid.cpp

// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Homework 2 - Problem #6

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double sigmoid, x = 0;
int main()
{
    cout << "Enter a value for x: " << endl;
    cin >> x;
    sigmoid = 1 / (1 + exp(-x));
    cout << "The sigmoid for x=" << x << " is " << sigmoid << endl;
    return 0;
}