// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Project 1 - Problem #1

#include <iostream>
#include <cassert>
#include <string>
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

/**
 * isValidTune works by taking a series of SPN and checking if each note is
 * valid. This is done using a for loop and a temporary string. Every two notes
 * that are added to the temporary string, this function calls isValidNote() to
 * see if the temp string is vaid. Once thats done the temp string is reset to an
 * empty string value. If and only if all temp strings pass the isValidNote()
 * test will this function return true.
 */
bool isValidTune(string tune)
{
    string temp;                // up to two characters to denote a note
    bool currentlyValid = true; // to be changed after every note check
    int tune_length = tune.length();
    if (tune_length % 2 != 0) // tune must be even. SPN denotes it so.
    {
        return false;
    }
    for (int i = 0; i < tune_length; i++) // iterate through all characters in the tune
    {
        temp += tune[i];
        if (temp.length() == 2)
        {
            currentlyValid = isValidNote(temp);
            temp = "";
        }
        if (currentlyValid == false) // will run once there is an invalid note
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string user_tune;
    bool valid;
    cout << "Enter a tune: " << endl;
    getline(cin, user_tune);
    valid = isValidTune(user_tune);
    if (valid == true)
    {
        cout << "Tune is valid" << endl;
    }
    else
    {
        cout << "Tune is not valid" << endl;
    }
    return 0;
}