// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Project 1 - Problem #1

#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>
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
    string temp;                 // up to two characters to denote a note
    bool currently_valid = true; // to be changed after every note check
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
            currently_valid = isValidNote(temp);
            temp = "";
        }
        if (currently_valid == false) // will run once there is an invalid note
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
    string temp;                  // up to two characters to denote a note
    bool currently_valid = false; // to be changed after every note check
    int counter = 0;
    int tune_length = tune.length();
    for (int i = 0; i < tune_length - 1; i++) // iterate through all characters in the tune, length must
                                              // be less than tune_length - 1 because of temp length
    {
        temp = tune.substr(i, 2); // checks evey time the index is increased
        currently_valid = isValidNote(temp);
        if (currently_valid == true)
        {
            counter++;
        }
    }
    return counter;
}

/**
 * tuneSimilarity() works by first comparing the letter value, then the whole SPN value
 * and finally checks for values in which the letter and number value differ. This reuses
 * for statements, just slightly altered in the substring portion in the if statements for each
 * check. Because we are measuring the length of the for loop in SPN length, that is the string
 * length divided by two, we multiply i by two in the for statements to get every other index.
 * This is effective becuase by increasing the index by one in the if statements, we can check for
 * all of the pitch values instead of the letter ones.
 */
double tuneSimilarity(string tune1, string tune2)
{
    int tune1_length = tune1.length();
    int tune2_length = tune2.length();
    int notes_to_check = tune1_length / 2; // length of notes in SPN
    int matched_notes = 0;
    int matched_notes_with_matched_pitch = 0;
    int notes_with_different_pitches = 0;
    if (tune1_length != tune2_length)
    {
        return 0;
    }
    for (int i = 0; i < notes_to_check; i++)
    {
        if (tune1.substr(2 * i, 1) == tune2.substr(2 * i, 1)) // checks only the letter note
        {
            matched_notes++;
        }
        if ((tune1.substr(2 * i, 1) != tune2.substr(2 * i, 1)) && (tune1.substr(2 * i + 1, 1) != tune2.substr(2 * i + 1, 1)))
        // Checks if note letter value AND the pitch are different
        {
            notes_with_different_pitches++;
        }
        if (tune1.substr(2 * i, 2) == tune2.substr(2 * i, 2)) // checks whole note SPN
        {
            matched_notes_with_matched_pitch++;
        }
    }

    return ((matched_notes / double(notes_to_check)) + matched_notes_with_matched_pitch - notes_with_different_pitches);
}

/** bestSimilarity() works basically by iterating through the larger user string, and checking each of those iterations
 * against the target string using the tuneSimilarity() function. This function returns the best score out of those
 * iterations by updating the double kept_score if the temp_score is higher than it.
 */
double bestSimilarity(string user, string target)
{
    string temp_string = "";
    int user_length = user.length();
    int target_length = target.length();
    double kept_score = -(target_length / 2); // Want to be negative because it accounts for the worst possible score.
    double temp_score = kept_score;

    if (target_length > user_length)
    {
        return 0;
    }
    for (int i = 0; i < user_length / 2; i++) // Iterates in SPN notation, that is every two characters.
    {
        temp_string = user.substr(2 * i, target_length);
        if (target_length > temp_string.length()) // Some cases where it iterates through and the end string end up being smaller than target.
        {
            return kept_score;
        }
        assert(temp_string.length() == target_length); // Before we pass into tuneSimilarity(), need to have the strings be equal length.

        temp_score = tuneSimilarity(temp_string, target);
        // cout << "\n....." << temp_string << "\n....." << endl;
        if (temp_score >= kept_score)
        {
            kept_score = temp_score;
        }
    }
    return kept_score;
}

/** printTuneRankins() works by just accounting for every test case. There are 15 different optoins
 * this function could output, accoutning for inclusivity. It make the most sense to just list all
 * of those different options, and test all of them using the scores gotten for each tune. The use
 * of an object would be AMAZING here!
 */
void printTuneRankings(string tune1, string tune2, string tune3, string targetTune)
{
    double tune1_score = bestSimilarity(tune1, targetTune);
    double tune2_score = bestSimilarity(tune2, targetTune);
    double tune3_score = bestSimilarity(tune3, targetTune);
    string tunes[3];
    if (tune1_score > tune2_score && tune2_score > tune3_score)
    {
        tunes[0] = "Tune 1";
        tunes[1] = "Tune 2";
        tunes[2] = "Tune 3";
    }
    else if (tune1_score > tune3_score && tune3_score > tune2_score)
    {
        tunes[0] = "Tune 1";
        tunes[1] = "Tune 3";
        tunes[2] = "Tune 2";
    }
    else if (tune2_score > tune1_score && tune1_score > tune3_score)
    {
        tunes[0] = "Tune 2";
        tunes[1] = "Tune 1";
        tunes[2] = "Tune 3";
    }
    else if (tune2_score > tune3_score && tune3_score > tune1_score)
    {
        tunes[0] = "Tune 2";
        tunes[1] = "Tune 3";
        tunes[2] = "Tune 1";
    }
    else if (tune3_score > tune2_score && tune2_score > tune1_score)
    {
        tunes[0] = "Tune 3";
        tunes[1] = "Tune 2";
        tunes[2] = "Tune 1";
    }
    else if (tune3_score > tune1_score && tune1_score > tune2_score)
    {
        tunes[0] = "Tune 3";
        tunes[1] = "Tune 1";
        tunes[2] = "Tune 2";
    }
    else if (tune1_score == tune2_score)
    {
        if (tune2_score >= tune3_score)
        {
            tunes[0] = "Tune 1";
            tunes[1] = "Tune 2";
            tunes[2] = "Tune 3";
        }
        else
        {
            tunes[0] = "Tune 3";
            tunes[1] = "Tune 1";
            tunes[2] = "Tune 2";
        }
    }
    else if (tune2_score == tune3_score)
    {
        if (tune1_score >= tune2_score)
        {
            tunes[0] = "Tune 1";
            tunes[1] = "Tune 2";
            tunes[2] = "Tune 3";
        }
        else
        {
            tunes[0] = "Tune 2";
            tunes[1] = "Tune 3";
            tunes[2] = "Tune 1";
        }
    }
    else if (tune3_score == tune1_score && tune2_score > tune1_score)
    {
        tunes[0] = "Tune 2";
        tunes[1] = "Tune 1";
        tunes[2] = "Tune 3";
    }
    else if (tune3_score == tune1_score && tune2_score < tune1_score)
    {
        tunes[0] = "Tune 1";
        tunes[1] = "Tune 3";
        tunes[2] = "Tune 2";
    }
    cout << "1) " << tunes[0] << ", 2) " << tunes[1] << ", 3) " << tunes[2] << endl;
}

int main()
{
    cout << setprecision(6) << endl;
    string user_tune1;
    string user_tune2;
    string user_tune3;
    string target_tune;
    cout << "Enter the first tune: " << endl;
    getline(cin, user_tune1);
    cout << "Enter the second tune: " << endl;
    getline(cin, user_tune2);
    cout << "Enter the third tune: " << endl;
    getline(cin, user_tune3);
    cout << "Enter the target tune: " << endl;
    getline(cin, target_tune);

    assert(numValidNotes("B4xA6n10") == 2);
    assert(numValidNotes(" G10B6") == 2);
    assert(numValidNotes(" sdf320fewkf1SDF") == 0);

    printTuneRankings(user_tune1, user_tune2, user_tune3, target_tune);
    return 0;
}
