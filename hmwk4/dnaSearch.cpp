// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Homework 4 - Problem #4

#include <iostream>
#include <string>
using namespace std;

/** Pseudocode:
 * Declare variable user_string, search_query
 * Declare variable counter
 * ask user for input for user_string
 * ask user for input for search_query
 * using a for statement, iterate through the entire user_string, searching if the substring of that is equivalent to search_query
 * if there are instances where search_query is found, add one to the counter.
 **/

string user_string;
string search_query;
int counter = 0;
bool keep_asking = true;
int main()
{
    /* // IF WE WANTED TO KEEP ASKING FOR VALID INPUT:
    do
    {
        keep_asking = false;
        cout << "Enter the DNA Sequence:" << endl;
        cin >> user_string;
        for (int i = 0; i < user_string.length(); i++)
        {
            if (int(user_string[i]) < 65 or int(user_string[i]) > 90)
            {
                cout << "This is not a valid DNA sequence." << endl;
                keep_asking = true;
                break;
            }
        }
    } while (keep_asking == true);

    do
    {
        keep_asking = false;
        cout << "Enter the DNA fragment to be searched:" << endl;
        cin >> search_query;
        for (int i = 0; i < search_query.length(); i++)
        {
            if (int(search_query[i]) < 65 or int(search_query[i]) > 90)
            {
                cout << "This is not a valid search sequence." << endl;
                keep_asking = true;
                break;
            }
        }
    } while (keep_asking == true);
*/

    cout << "Enter the DNA Sequence:" << endl;
    cin >> user_string;
    for (int i = 0; i < user_string.length(); i++)
    {
        if (int(user_string[i]) < 65 or int(user_string[i]) > 90)
        {
            cout << "This is not a valid DNA sequence." << endl;
            return 0;
        }
    }
    cout << "Enter the DNA fragment to be searched:" << endl;
    cin >> search_query;
    for (int i = 0; i < search_query.length(); i++)
    {
        if (int(search_query[i]) < 65 or int(search_query[i]) > 90)
        {
            cout << "This is not a valid DNA sequence" << endl;
            return 0;
        }
    }

    int user_length = user_string.length();
    int query_length = search_query.length();
    for (int i = 0; i < user_length - (query_length - 1); i++)
    {
        if (search_query == user_string.substr(i, query_length))
        {
            counter++;
        }
    }

    cout << "Number of occurrences: " << counter << endl;
    return 0;
}