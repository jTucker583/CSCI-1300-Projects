// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Homework 3 - Problem #5

#include <iostream>
#include <string>
using namespace std;

string department;
string classes; // used in cout statement
string section; // used in cout statement
int option;     // for switch statements; to be reused in all switch statements.

int main()
{
    cout << "Select a department: (1)Computer Science (2)Math (3)Science" << endl;
    cin >> option;
    switch (option) // switch statement for selecting a department
    {
    case 1: // Computer Science
        department = "Computer Science";
        cout << "Select a class: (1)Starting Computing (2)Data Structures (3)Algorithms" << endl;
        cin >> option;
        switch (option) // switch statement for selecting a class
        {
        case 1:
            classes = "Starting Computing";
            cout << "Select a section: (1)Section 100 (2)Section 200" << endl;
            cin >> option;
            switch (option) // switch statement for selecting a section
            {
            case 1:
                section = "100";
                break;
            case 2:
                section = "200";
                break;
            default:
                cout << "Please enter a valid input." << endl;
                return 0;
                break;
            }
            break;
        case 2:
            classes = "Data Structures";
            cout << "Select a section: (1)Section 101 (2)Section 201" << endl;
            cin >> option;
            switch (option) // switch statement for selecting a section
            {
            case 1:
                section = "101";
                break;
            case 2:
                section = "201";
                break;
            default:
                cout << "Please enter a valid input." << endl;
                return 0;
                break;
            }
            break;
        case 3:
            classes = "Algorithms";
            cout << "Select a section: (1)Section 102 (2)Section 202" << endl;
            cin >> option;
            switch (option) // switch statement for selecting a section
            {
            case 1:
                section = "102";
                break;
            case 2:
                section = "202";
                break;
            default:
                cout << "Please enter a valid input." << endl;
                return 0;
                break;
            }
            break;
        default:
            cout << "Please enter a valid input." << endl;
            return 0;
        }
        break;

    case 2: // Math
        department = "Math";
        cout << "Select a class: (1)Calculus 1 (2)Calculus 2 (3)Linear Algebra" << endl;
        cin >> option;
        switch (option) // switch statement for selecting a class
        {
        case 1:
            classes = "Calculus 1";
            cout << "Select a section: (1)Section 400 (2)Section 500" << endl;
            cin >> option;
            switch (option) // switch statement for selecting a section
            {
            case 1:
                section = "400";
                break;
            case 2:
                section = "500";
                break;
            default:
                cout << "Please enter a valid input." << endl;
                return 0;
                break;
            }
            break;
        case 2:
            classes = "Calculus 2";
            cout << "Select a section: (1)Section 401 (2)Section 501" << endl;
            cin >> option;
            switch (option) // switch statement for selecting a section
            {
            case 1:
                section = "401";
                break;
            case 2:
                section = "501";
                break;
            default:
                cout << "Please enter a valid input." << endl;
                return 0;
                break;
            }
            break;
        case 3:
            classes = "Linear Algebra";
            cout << "Select a section: (1)Section 402 (2)Section 502" << endl;
            cin >> option;
            switch (option) // switch statement for selecting a section
            {
            case 1:
                section = "402";
                break;
            case 2:
                section = "502";
                break;
            default:
                cout << "Please enter a valid input." << endl;
                return 0;
                break;
            }
            break;
        default:
            cout << "Please enter a valid input." << endl;
            return 0;
        }
        break;

    case 3: // Science
        department = "Science";
        cout << "Select a class: (1)General Chemistry 1 (2)Physics 1" << endl;
        cin >> option;
        switch (option) // switch statement for selecting a class
        {
        case 1:
            classes = "General Chemistry 1";
            cout << "Select a section: (1)Section 700 (2)Section 800" << endl;
            cin >> option;
            switch (option) // switch statement for selecting a section
            {
            case 1:
                section = "700";
                break;
            case 2:
                section = "800";
                break;
            default:
                cout << "Please enter a valid input." << endl;
                return 0;
                break;
            }
            break;
        case 2:
            classes = "Physics 1";
            cout << "Select a section: (1)Section 701 (2)Section 801" << endl;
            cin >> option;
            switch (option) // switch statement for selecting a section
            {
            case 1:
                section = "701";
                break;
            case 2:
                section = "801";
                break;
            default:
                cout << "Please enter a valid input." << endl;
                return 0;
                break;
            }
            break;
        default:
            cout << "Please enter a valid input." << endl;
            return 0;
        }
        break;

    default:
        cout << "Please enter a valid input." << endl;
        return 0;
    }

    cout << "You've been enrolled in Section " << section << " of " << classes << "!" << endl;
    return 0;
}
