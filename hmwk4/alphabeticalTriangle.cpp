// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Homework 4 - Problem #5

#include <iostream>
using namespace std;

/** Pseudocode:
 * START
 * Declare int height, char alphabet
 * Ask user for height
 * If height is a positive integer, continue with the program
 * NESTED FOR LOOPS
 *  outside loop for each row
 *  inside loop for each letter
 *  Each row has an odd amount of letters, so in outer for loop have one cout for a letter, add one to character index
 *  Inside loop runs until it hits outside loop, so we have two cout statements inside.
 *  Add 1 to alphabet index each time cout is run.
 * REPEAT
 * endline at the end of each inner for loop indicates a new line to start for the next iteration of the outer loop
 * END
 **/

int height = 0;
char alphabet = 'a';
int main()
{
    cout << "Enter the height:" << endl;
    cin >> height; // must be a positive integer.
    if (height <= 0 || isdigit(height) != false)
    {
        cout << "Invalid input." << endl;
        return 0; // end program
    }
    for (int i = 0; i < height; i++) // denotes each line
    {

        cout << alphabet;
        ++alphabet;
        for (int j = 1; j <= i; j++) // denotes characters in a line, as i gets larger by 1, cout prints two characters
        {
            if (alphabet > 122) // 122 = z, so we don't want anything above this index.
            {
                alphabet = 'a';
            }
            cout << alphabet;
            ++alphabet; // iterates through characters
            if (alphabet > 122)
            {
                alphabet = 'a';
            }
            cout << alphabet;
            ++alphabet;
            if (alphabet > 122)
            {
                alphabet = 'a';
            }
        }
        cout << endl; // starts a new line for the triangle
    }
    return 0;
}
