// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Project 1 - Problem #1

#include <iostream>
#include <cassert>
using namespace std;
/**
 * isValidNote returns a true or false value based on if the input string is written
 * in SPN. SPN is only valid if the length of the string is equal to two, has a
 * valid letter A-G as the first character, and a valid number 0-9 as the second.
 * The function works so that if the string does not equal two, nothing else runs.
 * The use of a local variable set to true if the character test is true, and only
 * then the final check sees if the second character is a number.
 */

bool isValidNote(string note)
{
    if (note.length() != 2) // Tests to see if input is two characters long
    {
        return false;
    }
    else
    {
        char letter = note[0]; // Should be letter
        int level = note[1];   // Should be number
        bool char_condition = false;
        switch (letter) // Must be characters A-G. Not including flats or sharps.
        {
        case 'A':
            char_condition = true;
            break;
        case 'B':
            char_condition = true;
            break;
        case 'C':
            char_condition = true;
            break;
        case 'D':
            char_condition = true;
            break;
        case 'E':
            char_condition = true;
            break;
        case 'F':
            char_condition = true;
            break;
        case 'G':
            char_condition = true;
            break;
        default:
            char_condition = false;
        }
        if (char_condition == true && (level >= 48 && level <= 57)) // only runs if character test passes.
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    string userNote;
    bool valid;
    cout << "Enter a note: " << endl;
    cin >> userNote;
    valid = isValidNote(userNote);
    // Test cases:
    assert(isValidNote("A0") == true);
    assert(isValidNote("G9") == true);
    assert(isValidNote("E6") == true);
    assert(isValidNote("f4") == false);
    assert(isValidNote("E10") == false);
    assert(isValidNote("G6") == true);

    if (valid == true)
    {
        cout << "Note is valid" << endl;
    }
    else
    {
        cout << "note is not valid" << endl;
    }
    return 0;
}