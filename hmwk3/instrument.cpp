// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Homework 3 - Problem #6

#include <iostream>
using namespace std;

int option; // to be used in multiple switch statements
int main()
{
    cout << "Select a category: (1)Brass (2)Woodwind (3)Percussion" << endl;
    cin >> option;
    switch (option) // takes category
    {
    case 1:
        cout << "Select an instrument: (1)Trumpet (2)Trombone" << endl;
        cin >> option;
        switch (option) // nested switch for brass
        {
        case 1:
            cout << "Your instrument will be $350." << endl;
            break;
        case 2:
            cout << "Your instrument will be $400." << endl;
            break;
        default:
            cout << "Please enter a valid input." << endl;
            break;
        }
        break;
    case 2:
        cout << "Select an instrument: (1)Flute (2)Saxophone" << endl;
        cin >> option;
        switch (option) // nested switch for woodwind
        {
        case 1:
            cout << "Your instrument will be $325." << endl;
            break;
        case 2:
            cout << "Your instrument will be $425." << endl;
            break;
        default:
            cout << "Please enter a valid input." << endl;
            break;
        }
        break;
    case 3: // nested switch for precussion
        cout << "Select an instrument: (1)Snare Drum (2)Cymbals" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Your instrument will be $275." << endl;
            break;
        case 2:
            cout << "Your instrument will be $200." << endl;
            break;
        default:
            cout << "Please enter a valid input." << endl;
            break;
        }
        break;
    default:
        cout << "Please enter a valid input." << endl;
    }
    return 0;
}