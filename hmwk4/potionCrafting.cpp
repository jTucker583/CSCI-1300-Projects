// CSCI 1300 Fall 2022
// Author: Jakob Tucker
// Recitation: 102 – Ojasvi Bhalerao
// Homework 4 - Problem #3

#include <iostream>
using namespace std;

/** Pseudocode:
 * declare priority, dandelians, honeycombs, coal
 * Ask user for potion crafting priority
 * if invalid input, ask again
 * ask user for dandelians, honeycombs, coal
 * if invalid input, ask again
 * if priority = health
 *  run health function first, followed by mana
 * else
 *  run mana first, followed by health
 **/

int potion_priority;
int health_potion = 0;
int mana_potion = 0;
int global_honeycomb = 0;
int global_dandelions = 0;
int global_coal = 0;
int global_toadstools = 0;

int health(int honeycomb, int dandelions, int coal, int toadstools)
{
    int potion = 0;
    while (honeycomb >= 5 and dandelions >= 0 and coal >= 2 and toadstools >= 3)
    {
        potion++;
        honeycomb = honeycomb - 5;
        coal = coal - 2;
        toadstools = toadstools - 3;
        global_honeycomb = honeycomb;
        global_coal = coal;
        global_toadstools = toadstools;
    }
    return potion;
}
int mana(int honeycomb, int dandelions, int coal, int toadstools)
{
    int potion = 0;
    while (honeycomb >= 5 and dandelions >= 3 and coal >= 1 and toadstools >= 0)
    {
        potion++;
        honeycomb = honeycomb - 5;
        dandelions = dandelions - 3;
        coal = coal - 1;
        toadstools = toadstools - 0;
        global_honeycomb = honeycomb;
        global_dandelions = dandelions;
        global_coal = coal;
        global_toadstools = toadstools;
    }
    return potion;
}

int main()
{
    do
    {
        cout << "Select a potion crafting priority:" << endl;
        cout << "1. Minor Mana" << endl;
        cout << "2. Minor Healing" << endl;
        cin >> potion_priority;
        if (potion_priority < 1 or potion_priority > 2)
        {
            cout << "Invalid input." << endl;
        }
    } while (potion_priority < 1 or potion_priority > 2);

    do
    {
        cout << "How many Honeycombs do you have?" << endl;
        cin >> global_honeycomb;
        if (global_honeycomb < 0)
        {
            cout << "Invalid input. ";
        }
    } while (global_honeycomb < 0);

    do
    {
        cout << "How many Dandelions do you have?" << endl;
        cin >> global_dandelions;
        if (global_dandelions < 0)
        {
            cout << "Invalid input. ";
        }
    } while (global_dandelions < 0);

    do
    {
        cout << "How many Coal do you have?" << endl;
        cin >> global_coal;
        if (global_coal < 0)
        {
            cout << "Invalid input. ";
        }
    } while (global_coal < 0);

    do
    {
        cout << "How many Toadstools do you have?" << endl;
        cin >> global_toadstools;
        if (global_toadstools < 0)
        {
            cout << "Invalid input. ";
        }
    } while (global_toadstools < 0);

    switch (potion_priority)
    {
    case 1:
        mana_potion = mana(global_honeycomb, global_dandelions, global_coal, global_toadstools);
        health_potion = health(global_honeycomb, global_dandelions, global_coal, global_toadstools);
    case 2:
        health_potion = health(global_honeycomb, global_dandelions, global_coal, global_toadstools);
        mana_potion = mana(global_honeycomb, global_dandelions, global_coal, global_toadstools);
    }

    if (potion_priority == 2)
    {
        cout << "You can make " << health_potion << " Healing potion(s) and " << mana_potion << " Mana potion(s)." << endl;
    }
    else
    {
        cout << "You can make " << mana_potion << " Mana potion(s) and " << health_potion << " Healing potion(s)." << endl;
    }
    return 0;
}