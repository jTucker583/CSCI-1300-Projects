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

/**
 * Works similarly to isValidTune(), but instead of checking if a part of the string is valid
 * for every two characters, this checks every single character iteration, still with a temp
 * variable with a length of two characters to check isValidNote(). If that returns true, add
 * one to the counter variable.
 */
int numValidNotes(string tune)
{
    string temp;                 // up to two characters to denote a note
    bool currentlyValid = false; // to be changed after every note check
    int counter = 0;
    int tune_length = tune.length();
    for (int i = 0; i < tune_length - 1; i++) // iterate through all characters in the tune, length must
                                              // be less than tune_length - 1 because of temp length
    {
        temp = tune.substr(i, 2); // checks evey time the index is increased
        currentlyValid = isValidNote(temp);
        if (currentlyValid == true)
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    string user_tune;
    cout << "Enter a tune: " << endl;
    getline(cin, user_tune);

    assert(numValidNotes("B4xA6n10") == 2);
    assert(numValidNotes(" G10B6") == 2);
    assert(numValidNotes(" sdf320fewkf1SDF") == 0);

    int numNotes = numValidNotes(user_tune);
    cout << "Number of valid notes: " << numNotes << endl;
    return 0;
}