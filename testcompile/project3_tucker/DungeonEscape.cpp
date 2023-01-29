#include "Player.h"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Map.h"
#include "Result.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
// BASIC FUNTIONS (Display Merchant Menu, Display map, Dispaly status, Split, Read Monster,
//                 Read Riddle, Append Results file, Append Leaderboard file, display riddle,
//                 display endgame results, fight monster, decide random misfortune)

// implement list vector and loop through until the user has finished purchasing
int getIndexOfGold(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "currency")
        {
            return i;
        }
    }
}
int getIndexOfIngredients(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "food")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfPot(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "cookware" && items.at(i).getName() == "Pot")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfPan(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "cookware" && items.at(i).getName() == "Pan")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfCauldron(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "cookware" && items.at(i).getName() == "Cauldron")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfClub(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "weapon" && items.at(i).getName() == "Club")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfSpear(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "weapon" && items.at(i).getName() == "Spear")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfRapier(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "weapon" && items.at(i).getName() == "Rapier")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfAxe(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "weapon" && items.at(i).getName() == "Axe")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfLongsword(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "weapon" && items.at(i).getName() == "Longsword")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfArmour(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "armour")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfRing(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "treasure" && items.at(i).getName() == "Silver ring")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfNecklace(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "treasure" && items.at(i).getName() == "Ruby necklace")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfBracelet(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "treasure" && items.at(i).getName() == "Emerald bracelet")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfCirclet(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "treasure" && items.at(i).getName() == "Diamond circlet")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfGoblet(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "treasure" && items.at(i).getName() == "Gem-encrusted goblet")
        {
            return i;
        }
    }
    return -1;
}
int getIndexOfKey(vector<Item> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "key")
        {
            return i;
        }
    }
    return -1;
}

// display leaderborad for the start of the game
void displayLeaderBoard(vector<Result> results)
{
    // sort vector based on score using bubble sort method
    Player temp_people[5];
    Result temp = Result("", 0, temp_people, 0, 0);
    for (int i = 0; i < results.size(); i++)
    {
        for (int j = i + 1; j < results.size(); j++)
        {
            if (results.at(j).getScore() > results.at(i).getScore())
            {
                temp = results.at(i);
                results.at(i) = results.at(j);
                results.at(j) = temp;
            }
        }
    }
    cout << "*LEADERBOARD*" << endl;
    int max = 10;
    if (results.size() < max)
    {
        max = results.size();
    }
    for (int i = 1; i <= max; i++)
    {
        cout << i << ". " << results.at(i - 1).getName() << ", " << results.at(i - 1).getScore() << "pts" << endl;
    }
}

// makes use of the getIndex() functions to get the name of the item in the item vector
// also uses getIndex() to get the amounts for each item.
void displayInventory(vector<Item> items)
{
    const string yellow("\033[0;33m"); // for terminal display
    const string white("\033[0m");     // for terminal display
    cout << "+-------------+ " << endl;
    cout << "| " << yellow << "*INVENTORY*" << white << " | " << endl;
    cout << "+-------------+ " << endl;
    cout << "| Gold        | " << items.at(getIndexOfGold(items)).getNum() << endl;
    cout << "| Ingredents  | " << items.at(getIndexOfIngredients(items)).getAmount() << endl;
    cout << "| Cookware    | "
         << "Pot: " << items.at(getIndexOfPot(items)).getAmount() << ", Pan: "
         << items.at(getIndexOfPan(items)).getAmount() << ", Cauldron: "
         << items.at(getIndexOfCauldron(items)).getAmount() << endl;

    cout << "| Weapons     | "
         << "Club: " << items.at(getIndexOfClub(items)).getAmount() << ", Spear: "
         << items.at(getIndexOfSpear(items)).getAmount() << ", Rapier: "
         << items.at(getIndexOfRapier(items)).getAmount() << ", Flaming-Axe: "
         << items.at(getIndexOfAxe(items)).getAmount() << ", Longsword: "
         << items.at(getIndexOfLongsword(items)).getAmount() << endl;
    cout << "| Armour      | " << items.at(getIndexOfArmour(items)).getAmount() << endl;
    cout << "| Treasures   | "
         << "Silver ring: " << items.at(getIndexOfRing(items)).getAmount() << ", Ruby necklace: "
         << items.at(getIndexOfNecklace(items)).getAmount() << ", Emerald bracelet: "
         << items.at(getIndexOfBracelet(items)).getAmount() << ", Diamond circlet: "
         << items.at(getIndexOfCirclet(items)).getAmount() << ", Gem-encrusted goblet: "
         << items.at(getIndexOfGoblet(items)).getAmount() << endl;
    cout << "| Keys        | " << items.at(getIndexOfKey(items)).getAmount() << endl;
    cout << "+-------------+ " << endl;
}

// updates gold and item values based on user choices within the menu
// includes input validation statements to verify that the number of a given item can be bought/sold
// makes use of getIndex() functions for each item type so that the value of the item is updated in the vector.
// Note: It looks absolutley humungous, and probably could have been implemented in a much simpler way,
// but all of the choices are just slight variations, thus getting their own else if() code block.
void displayMerchantMenu(vector<Item> &items, int num_rooms_cleared, int &num_items_bought, int &num_items_sold, Player people[], int PLAYERS_ARR_SIZE)
{
    const string red("\033[0;31m");         // for terminal display
    const string white("\033[0m");          // for terminal display
    const string bright_blue("\033[0;96m"); // for terminal display
    cout << "If you're looking for supplies, you've come to the right place.";
    cout << "\nI can sell you anything you might need for your journey, for the right price!\n"
         << endl;
    int menu_choice;
    string menu_choice_string;
    do
    {
        displayInventory(items);
        cout << "Choose one of the following:\n"
             << "1. Ingredients: To make food, you have to cook raw ingredients.\n"
             << "2. Cookware: You will need something to cook those ingredients.\n"
             << "3. Weapons: It's dangerous to go alone, take this!\n"
             << "4. Armor: If you want to survive monster attacks, you will need some armor.\n"
             << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands.\n"
             << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!\n"
             << endl;
        getline(cin, menu_choice_string);
        if (menu_choice_string.length() > 1 || menu_choice_string.length() == 0)
        {
            cout << red << "Invalid input." << endl;
            menu_choice = 0;
        }
        else
        {
            if (menu_choice_string[0] > 54 || menu_choice_string[0] < 49)
            {
                cout << red << "Invalid input." << endl;
                menu_choice = 0;
            }
            else
            {
                menu_choice = stoi(menu_choice_string);
            }
        }
        if (menu_choice == 1)
        {
            double ingredients_rate = 1 + (1 * .25 * num_rooms_cleared);
            int currency_update = getIndexOfGold(items);
            string amount_string;
            int amount;
            do
            {
                cout << "How many kg of ingredients do you need [1 Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)" << endl;
                getline(cin, amount_string);
                amount = stoi(amount_string);
                if (amount % 5 != 0 || amount < 0)
                {
                    cout << red << "Invalid input." << white << endl;
                }
                else
                {
                    assert(amount >= 0);
                    if (items.at(currency_update).getNum() < (ingredients_rate * amount))
                    {
                        cout << red << "You can't afford this! You are " << (ingredients_rate * amount) - items.at(currency_update).getNum() << " units of gold short." << white << endl;
                        amount = 1;
                    }
                    else
                    {
                        if (amount == 0)
                        {
                            cout << "Anything else I could get you?\n"
                                 << endl;
                        }
                        else
                        {
                            cout << bright_blue << "Thank you for your patronage! What else can I get for you?\n"
                                 << white
                                 << endl;
                            int update_value = getIndexOfIngredients(items);
                            items.at(update_value).setAmount(amount + items.at(update_value).getAmount());
                            items.at(currency_update).setNum(items.at(currency_update).getNum() - (ingredients_rate * amount));
                            num_items_bought += amount;
                            amount = 0;
                        }
                    }
                }
            } while (amount != 0);
        }
        else if (menu_choice == 2)
        {
            cout << "I have a several types of cookware, which one would you like?\n"
                 << "Each type has a different probability of breaking when used, marked with(XX %)." << endl;
            double pot_rate = 2 + (2 * .25 * num_rooms_cleared);
            double pan_rate = 10 + (10 * .25 * num_rooms_cleared);
            double cauldron_rate = 20 + (20 * .25 * num_rooms_cleared);
            int internal_choice;
            string internal_choice_string;
            string amount_string;
            do
            {
                cout << "Choose one of the following:\n"
                     << "1. (25%) Ceramic Pot [" << pot_rate << "]\n"
                     << "2. (10%) Frying Pan [" << pan_rate << "]\n"
                     << "3. ( 2%) Cauldron [" << pan_rate << "]\n"
                     << "4. Cancel\n"
                     << endl;
                getline(cin, internal_choice_string);
                internal_choice = stoi(internal_choice_string);
                if (internal_choice == 1)
                {
                    int amount;
                    int currency_update = getIndexOfGold(items);
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, amount_string);
                    amount = stoi(amount_string);
                    if (amount < 0)
                    {
                        cout << red << "Invalid input." << white << endl;
                    }
                    else
                    {
                        // ADD CHECK TO SEE IF THE USER CAN AFFORD IT. GOLD SHOULD NOT GO BELOW ZERO.
                        assert(amount >= 0);
                        if (items.at(currency_update).getNum() < (pot_rate * amount))
                        {
                            cout << red << "You can't afford this! You are " << (pot_rate * amount) - items.at(currency_update).getNum() << " units of gold short." << white << endl;
                            amount = 0;
                        }
                        if (amount == 0)
                        {
                            cout << "Anything else I could get you?\n"
                                 << endl;
                            internal_choice = 4;
                        }
                        else
                        {
                            cout << bright_blue << "Thank you for your patronage! What else can I get for you?\n"
                                 << white
                                 << endl;
                            int update_value = getIndexOfPot(items);
                            items.at(update_value).setAmount(amount + items.at(update_value).getAmount());
                            items.at(currency_update).setNum(items.at(currency_update).getNum() - (pot_rate * amount));
                            num_items_bought += amount;
                            internal_choice = 4;
                        }
                    }
                }
                else if (internal_choice == 2)
                {
                    int amount;
                    int currency_update = getIndexOfGold(items);
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, amount_string);
                    amount = stoi(amount_string);
                    if (amount < 0)
                    {
                        cout << red << "Invalid input." << white << endl;
                    }
                    else
                    {
                        assert(amount >= 0);
                        // ADD CHECK TO SEE IF THE USER CAN AFFORD IT. GOLD SHOULD NOT GO BELOW ZERO.
                        if (items.at(currency_update).getNum() < (pan_rate * amount))
                        {
                            cout << red << "You can't afford this! You are " << (pan_rate * amount) - items.at(currency_update).getNum() << " units of gold short." << white << endl;
                            amount = 0;
                        }
                        if (amount == 0)
                        {
                            cout << "Anything else I could get you?\n"
                                 << endl;
                            internal_choice = 4;
                        }
                        else
                        {
                            cout << bright_blue << "Thank you for your patronage! What else can I get for you?\n"
                                 << white
                                 << endl;
                            int update_value = getIndexOfPan(items);
                            items.at(update_value).setAmount(amount + items.at(update_value).getAmount());
                            items.at(currency_update).setNum(items.at(currency_update).getNum() - (pan_rate * amount));
                            num_items_bought += amount;
                            internal_choice = 4;
                        }
                    }
                }
                else if (internal_choice == 3)
                {
                    int amount;
                    int currency_update = getIndexOfGold(items);
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, amount_string);
                    amount = stoi(amount_string);
                    if (amount < 0)
                    {
                        cout << red << "Invalid input." << white << endl;
                    }
                    else
                    {
                        assert(amount >= 0);
                        // ADD CHECK TO SEE IF THE USER CAN AFFORD IT. GOLD SHOULD NOT GO BELOW ZERO.
                        if (items.at(currency_update).getNum() < (cauldron_rate * amount))
                        {
                            cout << red << "You can't afford this! You are " << (cauldron_rate * amount) - items.at(currency_update).getNum() << " units of gold short." << white << endl;
                            amount = 0;
                        }
                        if (amount == 0)
                        {
                            cout << "Anything else I could get you?\n"
                                 << endl;
                            internal_choice = 4;
                        }
                        else
                        {
                            cout << bright_blue << "Thank you for your patronage! What else can I get for you?\n"
                                 << white
                                 << endl;
                            int update_value = getIndexOfCauldron(items);
                            items.at(update_value).setAmount(amount + items.at(update_value).getAmount());
                            items.at(currency_update).setNum(items.at(currency_update).getNum() - (cauldron_rate * amount));
                            num_items_bought += amount;
                            internal_choice = 4;
                        }
                    }
                }
                else if (internal_choice != 4)
                {
                    cout << red << "Invalid input!" << white << endl;
                }
            } while (internal_choice != 4);
            menu_choice = 0;
        }
        else if (menu_choice == 3)
        {
            cout << "I have a plentiful collection of weapons to choose from, what would you like?\n"
                 << "Note that some of them provide you a special bonus in combat, marked by a(+X)." << endl;
            double club_rate = 2 + (2 * .25 * num_rooms_cleared);
            double spear_rate = 2 + (2 * .25 * num_rooms_cleared);
            double rapier_rate = 5 + (5 * .25 * num_rooms_cleared);
            double axe_rate = 15 + (15 * .25 * num_rooms_cleared);
            double longsword_rate = 50 + (50 * .25 * num_rooms_cleared);
            int internal_choice;
            string internal_choice_string;
            string amount_string;
            do
            {
                cout << "Choose one of the following:\n"
                     << "1. Stone Club [" << club_rate << "]\n"
                     << "2. Iron Spear [" << spear_rate << "]\n"
                     << "3. (+1) Mythril Rapier [" << rapier_rate << "]\n"
                     << "4. (+2) Flaming Battle-Axe [" << axe_rate << "]\n"
                     << "5. (+3) Vorpal Longsword [" << longsword_rate << "]\n"
                     << "6. Cancel\n"
                     << endl;
                getline(cin, internal_choice_string);
                internal_choice = stoi(internal_choice_string);
                if (internal_choice == 1)
                {
                    int amount;
                    int currency_update = getIndexOfGold(items);
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, amount_string);
                    amount = stoi(amount_string);
                    if (amount < 0)
                    {
                        cout << red << "Invalid input." << white << endl;
                    }
                    else
                    {
                        assert(amount >= 0);
                        // ADD CHECK TO SEE IF THE USER CAN AFFORD IT. GOLD SHOULD NOT GO BELOW ZERO.
                        if (items.at(currency_update).getNum() < (club_rate * amount))
                        {
                            cout << red << "You can't afford this! You are " << (club_rate * amount) - items.at(currency_update).getNum() << " units of gold short." << white << endl;
                            amount = 0;
                        }
                        if (amount == 0)
                        {
                            cout << "Anything else I could get you?\n"
                                 << endl;
                            internal_choice = 6;
                        }
                        else
                        {
                            cout << bright_blue << "Thank you for your patronage! What else can I get for you?\n"
                                 << white
                                 << endl;
                            int update_value = getIndexOfClub(items);
                            items.at(update_value).setAmount(amount + items.at(update_value).getAmount());
                            items.at(currency_update).setNum(items.at(currency_update).getNum() - (club_rate * amount));
                            num_items_bought += amount;
                            internal_choice = 6;
                        }
                    }
                }
                else if (internal_choice == 2)
                {
                    int amount;
                    int currency_update = getIndexOfGold(items);
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, amount_string);
                    amount = stoi(amount_string);
                    if (amount < 0)
                    {
                        cout << red << "Invalid input." << white << endl;
                    }
                    else
                    {
                        assert(amount >= 0);
                        // ADD CHECK TO SEE IF THE USER CAN AFFORD IT. GOLD SHOULD NOT GO BELOW ZERO.
                        if (items.at(currency_update).getNum() < (spear_rate * amount))
                        {
                            cout << red << "You can't afford this! You are " << (spear_rate * amount) - items.at(currency_update).getNum() << " units of gold short." << white << endl;
                            amount = 0;
                        }
                        if (amount == 0)
                        {
                            cout << "Anything else I could get you?\n"
                                 << endl;
                            internal_choice = 6;
                        }
                        else
                        {
                            cout << bright_blue << "Thank you for your patronage! What else can I get for you?\n"
                                 << white
                                 << endl;
                            int update_value = getIndexOfSpear(items);
                            items.at(update_value).setAmount(amount + items.at(update_value).getAmount());
                            items.at(currency_update).setNum(items.at(currency_update).getNum() - (spear_rate * amount));
                            num_items_bought += amount;
                            internal_choice = 6;
                        }
                    }
                }
                else if (internal_choice == 3)
                {
                    int amount;
                    int currency_update = getIndexOfGold(items);
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, amount_string);
                    amount = stoi(amount_string);
                    if (amount < 0)
                    {
                        cout << red << "Invalid input." << white << endl;
                    }
                    else
                    {
                        assert(amount >= 0);
                        // ADD CHECK TO SEE IF THE USER CAN AFFORD IT. GOLD SHOULD NOT GO BELOW ZERO.
                        if (items.at(currency_update).getNum() < (rapier_rate * amount))
                        {
                            cout << red << "You can't afford this! You are " << (rapier_rate * amount) - items.at(currency_update).getNum() << " units of gold short." << white << endl;
                            amount = 0;
                        }
                        if (amount == 0)
                        {
                            cout << "Anything else I could get you?\n"
                                 << endl;
                            internal_choice = 6;
                        }
                        else
                        {
                            cout << bright_blue << "Thank you for your patronage! What else can I get for you?\n"
                                 << white
                                 << endl;
                            int update_value = getIndexOfRapier(items);
                            items.at(update_value).setAmount(amount + items.at(update_value).getAmount());
                            items.at(currency_update).setNum(items.at(currency_update).getNum() - (rapier_rate * amount));
                            num_items_bought += amount;
                            internal_choice = 6;
                        }
                    }
                }
                else if (internal_choice == 4)
                {
                    int amount;
                    int currency_update = getIndexOfGold(items);
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, amount_string);
                    amount = stoi(amount_string);
                    if (amount < 0)
                    {
                        cout << red << "Invalid input." << white << endl;
                    }
                    else
                    {
                        assert(amount >= 0);
                        // ADD CHECK TO SEE IF THE USER CAN AFFORD IT. GOLD SHOULD NOT GO BELOW ZERO.
                        if (items.at(currency_update).getNum() < (axe_rate * amount))
                        {
                            cout << red << "You can't afford this! You are " << (axe_rate * amount) - items.at(currency_update).getNum() << " units of gold short." << white << endl;
                            amount = 0;
                        }
                        if (amount == 0)
                        {
                            cout << "Anything else I could get you?\n"
                                 << endl;
                            internal_choice = 6;
                        }
                        else
                        {
                            cout << bright_blue << "Thank you for your patronage! What else can I get for you?\n"
                                 << white
                                 << endl;
                            int update_value = getIndexOfAxe(items);
                            items.at(update_value).setAmount(amount + items.at(update_value).getAmount());
                            items.at(currency_update).setNum(items.at(currency_update).getNum() - (axe_rate * amount));
                            num_items_bought += amount;
                            internal_choice = 6;
                        }
                    }
                }
                else if (internal_choice == 5)
                {
                    int amount;
                    int currency_update = getIndexOfGold(items);
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    getline(cin, amount_string);
                    amount = stoi(amount_string);
                    if (amount < 0)
                    {
                        cout << red << "Invalid input." << white << endl;
                    }
                    else
                    {
                        assert(amount >= 0);
                        // ADD CHECK TO SEE IF THE USER CAN AFFORD IT. GOLD SHOULD NOT GO BELOW ZERO.
                        if (items.at(currency_update).getNum() < (longsword_rate * amount))
                        {
                            cout << red << "You can't afford this! You are " << (longsword_rate * amount) - items.at(currency_update).getNum() << " units of gold short." << white << endl;
                            amount = 0;
                        }
                        if (amount == 0)
                        {
                            cout << "Anything else I could get you?\n"
                                 << endl;
                            internal_choice = 6;
                        }
                        else
                        {
                            cout << bright_blue << "Thank you for your patronage! What else can I get for you?\n"
                                 << white
                                 << endl;
                            int update_value = getIndexOfLongsword(items);
                            items.at(update_value).setAmount(amount + items.at(update_value).getAmount());
                            items.at(currency_update).setNum(items.at(currency_update).getNum() - (longsword_rate * amount));
                            num_items_bought += amount;
                            internal_choice = 6;
                        }
                    }
                }
                else if (internal_choice != 6)
                {
                    cout << red << "Invalid input!" << white << endl;
                }
            } while (internal_choice != 6);
            menu_choice = 0;
        }
        else if (menu_choice == 4)
        {
            double armour_rate = 5 + (5 * .25 * num_rooms_cleared);
            int currency_update = getIndexOfGold(items);
            string amount_string;
            int amount;
            do
            {
                cout << "How many suits of armor can I get you? (Enter a positive integer, or 0 to cancel)" << endl;
                getline(cin, amount_string);
                amount = stoi(amount_string);
                if (amount < 0)
                {
                    cout << red << "Invalid input." << white << endl;
                }
                else
                {
                    assert(amount > 0);
                    if (items.at(currency_update).getNum() < (armour_rate * amount))
                    {
                        cout << red << "You can't afford this! You are " << (armour_rate * amount) - items.at(currency_update).getNum() << " units of gold short." << white << endl;
                        amount = 1;
                    }
                    else
                    {
                        if (amount == 0)
                        {
                            cout << "Anything else I could get you?\n"
                                 << endl;
                        }
                        else
                        {
                            cout << bright_blue << "Thank you for your patronage! What else can I get for you?\n"
                                 << white
                                 << endl;
                            int update_value = getIndexOfArmour(items);
                            items.at(update_value).setAmount(amount + items.at(update_value).getAmount());
                            items.at(currency_update).setNum(items.at(currency_update).getNum() - (armour_rate * amount));
                            num_items_bought += amount;

                            // update player armour
                            int iterator = 0;
                            cout << items.at(getIndexOfArmour(items)).getAmount() << endl;
                            if (items.at(getIndexOfArmour(items)).getAmount() > 5) // sets all party members armour bools to true
                            {
                                for (int i = 0; i < PLAYERS_ARR_SIZE; i++)
                                {
                                    people[i].setHasArmour(true);
                                }
                            }
                            else
                            {
                                while (iterator < amount) // should run "amount" amount of times
                                {
                                    int player_has_armour = 0;
                                    for (int i = 0; i < PLAYERS_ARR_SIZE; i++)
                                    {
                                        if (people[i].getHasArmour() == false) // updates the armour if armour is not on player. Updates iterator
                                        {
                                            // The iterator updates here becasue we don't want everyone to get a piece of armour. Only that which was purchased.
                                            people[i].setHasArmour(true);
                                            iterator++;
                                            player_has_armour++;
                                            break;
                                        }
                                        else // denotes players already having armour and not updating the iterator.
                                        {
                                            player_has_armour++;
                                        }
                                    }
                                    if (player_has_armour >= items.at(getIndexOfArmour(items)).getAmount()) // should stop if everyone has armour
                                    {
                                        break;
                                    }
                                    else if (items.at(getIndexOfArmour(items)).getAmount() > 5) // should stop becuase there is more than 5 pieces available; everyone getes one.
                                    {
                                        break;
                                    }
                                }
                            }
                            amount = 0;
                        }
                    }
                }
            } while (amount != 0);
        }
        else if (menu_choice == 5)
        {
            int counter = 0;
            cout << "Here are my rates for treasure:\n"
                 << "Silver Ring - 10 gold pieces each\n"
                 << "Ruby Necklace - 20 gold pieces each\n"
                 << "Emerald Bracelet - 30 gold pieces each\n"
                 << "Diamond Circlet - 40 gold pieces each\n"
                 << "Gem-encrusted Goblet - 50 gold pieces each\n"
                 << endl;
            if (items.at(getIndexOfRing(items)).getAmount() > 0)
            {
                counter++;
            }
            if (items.at(getIndexOfNecklace(items)).getAmount() > 0)
            {
                counter++;
            }
            if (items.at(getIndexOfBracelet(items)).getAmount() > 0)
            {
                counter++;
            }
            if (items.at(getIndexOfCirclet(items)).getAmount() > 0)
            {
                counter++;
            }
            if (items.at(getIndexOfGoblet(items)).getAmount() > 0)
            {
                counter++;
            }
            int internal_choice;
            string internal_choice_string;
            do
            {

                if (counter == 0)
                {
                    cout << "You have nothing to sell!" << endl;
                }
                else
                {
                    cout << "You can sell up to:\n"
                         << "1. " << items.at(getIndexOfRing(items)).getAmount() << " Silver Ring(s)\n"
                         << "2. " << items.at(getIndexOfNecklace(items)).getAmount() << " Ruby Necklace(s)\n"
                         << "3. " << items.at(getIndexOfBracelet(items)).getAmount() << " Emerald Bracelet(s)\n"
                         << "4. " << items.at(getIndexOfCirclet(items)).getAmount() << " Diamond Circlet(s)\n"
                         << "5. " << items.at(getIndexOfGoblet(items)).getAmount() << " Gem-encrusted Goblet(s)\n"
                         << "6. Cancel\n"
                         << "What would you like to sell?\n"
                         << endl;
                    getline(cin, internal_choice_string);
                    internal_choice = stoi(internal_choice_string);
                    if (internal_choice < 1 || internal_choice > 6)
                    {
                        cout << red << "Invalid input." << white << endl;
                        internal_choice = 0;
                    }
                    else if (internal_choice == 1)
                    {
                        int amount;
                        string amount_string;
                        cout << "How many would you like to sell?" << endl;
                        getline(cin, amount_string);
                        amount = stoi(amount_string);
                        if (amount < 0)
                        {
                            cout << red << "Invalid input." << white << endl;
                        }
                        else
                        {
                            assert(amount > 0);
                            if (amount > items.at(getIndexOfRing(items)).getAmount())
                            {
                                cout << "You don't have this many!" << endl;
                            }
                            else
                            {
                                cout << bright_blue << "Thank you for your patronage!\n"
                                     << white
                                     << endl;
                                items.at(getIndexOfRing(items)).setAmount(items.at(getIndexOfRing(items)).getAmount() - amount);
                                items.at(getIndexOfGold(items)).setNum(items.at(getIndexOfGold(items)).getNum() + (amount * 10));
                                num_items_sold += amount;
                            }
                        }
                    }
                    else if (internal_choice == 2)
                    {
                        int amount;
                        string amount_string;
                        cout << "How many would you like to sell?" << endl;
                        getline(cin, amount_string);
                        amount = stoi(amount_string);
                        if (amount < 0)
                        {
                            cout << red << "Invalid input." << white << endl;
                        }
                        else
                        {
                            assert(amount > 0);
                            if (amount > items.at(getIndexOfNecklace(items)).getAmount())
                            {
                                cout << "You don't have this many!" << endl;
                            }
                            else
                            {
                                cout << bright_blue << "Thank you for your patronage!\n"
                                     << white
                                     << endl;
                                items.at(getIndexOfNecklace(items)).setAmount(items.at(getIndexOfNecklace(items)).getAmount() - amount);
                                items.at(getIndexOfGold(items)).setNum(items.at(getIndexOfGold(items)).getNum() + (amount * 20));
                                num_items_sold += amount;
                            }
                        }
                    }
                    else if (internal_choice == 3)
                    {
                        int amount;
                        string amount_string;
                        cout << "How many would you like to sell?" << endl;
                        getline(cin, amount_string);
                        amount = stoi(amount_string);
                        if (amount < 0)
                        {
                            cout << red << "Invalid input." << white << endl;
                        }
                        else
                        {
                            assert(amount > 0);
                            if (amount > items.at(getIndexOfBracelet(items)).getAmount())
                            {
                                cout << "You don't have this many!" << endl;
                            }
                            else
                            {
                                cout << bright_blue << "Thank you for your patronage!\n"
                                     << white
                                     << endl;
                                items.at(getIndexOfBracelet(items)).setAmount(items.at(getIndexOfBracelet(items)).getAmount() - amount);
                                items.at(getIndexOfGold(items)).setNum(items.at(getIndexOfGold(items)).getNum() + (amount * 30));
                                num_items_sold += amount * 2; // worth more points
                            }
                        }
                    }
                    else if (internal_choice == 4)
                    {
                        int amount;
                        string amount_string;
                        cout << "How many would you like to sell?" << endl;
                        getline(cin, amount_string);
                        amount = stoi(amount_string);
                        if (amount < 0)
                        {
                            cout << red << "Invalid input." << white << endl;
                        }
                        else
                        {
                            assert(amount > 0);
                            if (amount > items.at(getIndexOfCirclet(items)).getAmount())
                            {
                                cout << "You don't have this many!" << endl;
                            }
                            else
                            {
                                cout << bright_blue << "Thank you for your patronage!\n"
                                     << white
                                     << endl;
                                items.at(getIndexOfCirclet(items)).setAmount(items.at(getIndexOfCirclet(items)).getAmount() - amount);
                                items.at(getIndexOfGold(items)).setNum(items.at(getIndexOfGold(items)).getNum() + (amount * 40));
                                num_items_sold += amount * 2; // worth more points
                            }
                        }
                    }
                    else if (internal_choice == 5)
                    {
                        int amount;
                        string amount_string;
                        cout << "How many would you like to sell?" << endl;
                        getline(cin, amount_string);
                        amount = stoi(amount_string);
                        if (amount < 0)
                        {
                            cout << red << "Invalid input." << white << endl;
                        }
                        else
                        {
                            assert(amount > 0);
                            if (amount > items.at(getIndexOfGoblet(items)).getAmount())
                            {
                                cout << "You don't have this many!" << endl;
                            }
                            else
                            {
                                cout << bright_blue << "Thank you for your patronage!\n"
                                     << white
                                     << endl;
                                items.at(getIndexOfGoblet(items)).setAmount(items.at(getIndexOfGoblet(items)).getAmount() - amount);
                                items.at(getIndexOfGold(items)).setNum(items.at(getIndexOfGold(items)).getNum() + (amount * 50));
                                num_items_sold += amount * 3; // worth more points
                            }
                        }
                    }
                    else if (internal_choice == 6)
                    {
                        cout << "Your loss!" << endl;
                    }
                }
                internal_choice = 6;
            } while (internal_choice != 6);
        }
        else if (menu_choice != 6)
        {
            cout << red << "Invalid input." << white << endl;
        }
    } while (menu_choice != 6);
}

// generate a random integer within a range
int generateRandomInteger(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// display the hunger and armour capabilities of each party member
// to be called every time an action is made in main().
void displayStatus(int num_cleared_rooms, int num_keys, int anger_level, vector<Item> items, Player people[], int num_monsters_defeated)
{
    const string yellow("\033[0;33m"); // for terminal display
    const string white("\033[0m");     // for terminal display
    cout << "+-------------+ " << endl;
    cout << "|   " << yellow << "*STATS*" << white << "   | " << endl;
    cout << "+-------------+ " << endl;
    cout << "| Rooms cleared: " << num_cleared_rooms << " | Keys: " << num_keys << " | Anger level: " << anger_level << endl;
    displayInventory(items);
    cout << "|   " << yellow << "*PARTY*" << white << "   |" << endl;
    cout << "+-------------+ " << endl;
    cout << "| " << people[0].getName() << " | Hunger: " << people[0].getHunger() << " | Armour: " << people[0].getHasArmour() << " | Dead: " << people[0].getDeath() << " | Position: " << people[0].getPosition() << endl;
    cout << "| " << people[1].getName() << " | Hunger: " << people[1].getHunger() << " | Armour: " << people[1].getHasArmour() << " | Dead: " << people[1].getDeath() << " | Position: " << people[1].getPosition() << endl;
    cout << "| " << people[2].getName() << " | Hunger: " << people[2].getHunger() << " | Armour: " << people[2].getHasArmour() << " | Dead: " << people[2].getDeath() << " | Position: " << people[2].getPosition() << endl;
    cout << "| " << people[3].getName() << " | Hunger: " << people[3].getHunger() << " | Armour: " << people[3].getHasArmour() << " | Dead: " << people[3].getDeath() << " | Position: " << people[3].getPosition() << endl;
    cout << "| " << people[4].getName() << " | Hunger: " << people[4].getHunger() << " | Armour: " << people[4].getHasArmour() << " | Dead: " << people[4].getDeath() << " | Position: " << people[4].getPosition() << endl;
    cout << "+-------------+ " << endl;
}

// taken from homework 5, takes in a string and splits it into array parts
int split(string input, char delimator, string array[], int size)
{
    string temp = "";
    int counter = 0;
    int input_length = input.length();
    int array_counter = 1;

    if (input_length == 0) // if there is an empty input, there should be no values inside the array.
    {
        array_counter = 0;
    }
    for (int i = 0; i < input_length; i++) // check if input string is larger than array
    {
        if (input[i] == delimator)
        {
            counter++;
        }
    }
    if (counter == 0 && size > 0) // if there is no delimators, and the array is greater than 0, the first element is the input.
    {
        array[0] = input;
        return array_counter;
    }

    for (int i = 0; i < size; i++)
    {
        input_length = input.length();
        temp = "";
        for (int j = 0; j < input_length; j++)
        {
            if (input[j] != delimator)
            {
                temp += input[j];
            }
            else
            {
                input = input.substr(j + 1);
                array_counter++;
                break;
            }
        }
        array[i] = temp;
    }
    if (counter >= size)
    {
        return -1;
    }
    else
    {
        return array_counter;
    }
}

// utilizing split, reads the monster file and appends each monster to the vector by reference.
// if the line is not formatted correctly, the monster will not be added.
int readMonsterFile(string filename, vector<Monster> &monsters)
{
    ifstream file;
    string line;
    int line_length = 2;
    file.open(filename);
    int monster_counter = 0;
    if (file.is_open())
    {
        string current_line[line_length];
        int num_changes = 0;
        while (getline(file, line))
        {
            if (line != "")
            {
                num_changes = split(line, ',', current_line, line_length);
                if (num_changes == line_length) // data validaiton
                {
                    Monster current_monster(current_line[0], stoi(current_line[1]));
                    monsters.push_back(current_monster);
                    monster_counter++;
                }
            }
        }
        return monster_counter;
    }
    else
    {
        return -1;
    }
}

// utilizing split, reads the riddle file and appends each NPC to the vector by reference.
// if the line is not formatted correctly, the NPC will not be added.
// Sets default values in each NPC not specified in the text file.
int readRiddleFile(string filename, vector<NPC> &npcs)
{
    ifstream file;
    string line;
    int line_length = 2;
    file.open(filename);
    int npc_counter = 0;
    if (file.is_open())
    {
        string current_line[line_length];
        int num_changes = 0;
        while (getline(file, line))
        {
            if (line != "")
            {
                num_changes = split(line, '~', current_line, line_length);
                if (num_changes == line_length) // data validaiton
                {
                    NPC current_NPC(current_line[0], current_line[1]);
                    npcs.push_back(current_NPC);
                    npc_counter++;
                }
            }
        }
        return npc_counter;
    }
    else
    {
        return -1;
    }
}

// just the same as the readMonsterFile, this ustilizes split. This creates a vector of all Result objects in the file.
int readLeaderboardFile(string filename, vector<Result> &results)
{
    ifstream file;
    string line;
    int line_length = 9;
    file.open(filename);
    int result_counter = 0;
    if (file.is_open())
    {
        string current_line[line_length];
        int num_changes = 0;
        while (getline(file, line))
        {
            if (line != "")
            {
                num_changes = split(line, ',', current_line, line_length);
                if (num_changes == line_length) // data validaiton
                {
                    Player peopleNames[5] = {
                        Player(current_line[2]),
                        Player(current_line[3]),
                        Player(current_line[4]),
                        Player(current_line[5]),
                        Player(current_line[6]),
                    };
                    Result current_res(current_line[0], stoi(current_line[1]), peopleNames, stoi(current_line[7]), stoi(current_line[8]));
                    results.push_back(current_res);
                    result_counter++;
                }
            }
        }
        return result_counter;
    }
    else
    {
        return -1;
    }
}

// my own formula (I know how creative) :)
int calculateScore(int num_cleared_rooms, int anger_level, int num_found_treasure, int num_moves, int num_items_purchased, int num_items_sold, int num_monsters_defeated)
{
    return 1.5 * ((num_cleared_rooms * 50) + (num_monsters_defeated * 75) + (num_found_treasure * 33) + (num_items_purchased * 5) + (num_items_sold * 17) +
                  (num_moves * 2) - (anger_level * 3));
}

// utilize calculateScore function
// for display during the game
void displayScore(int num_cleared_rooms, int anger_level, int num_found_treasure, int num_moves, int num_items_purchased, int num_items_sold, int num_monsters_defeated)
{
    const string green("\033[0;32m"); // for terminal display
    const string white("\033[0m");    // for terminal display
    cout << "+-------------+ " << endl;
    cout << "| " << green << "  *SCORE*  " << white << " | " << endl;
    cout << "+-------------+ " << endl;
    cout << "| " << calculateScore(num_cleared_rooms, anger_level, num_found_treasure, num_moves, num_items_purchased, num_items_sold, num_monsters_defeated)
         << " pts" << endl;
    cout << "+-------------+ " << endl;
}

// utilize fstream object to write results of the game, plus the date.
int appendResultsFile(string filename, Result result)
{
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << endl;
    result.setName(name);

    ofstream fout;
    fout.open(filename, ios::app);
    fout << result.getName() << "," << result.getScore() << "," << result.getPartyName(0) << "," << result.getPartyName(1) << "," << result.getPartyName(2) << "," << result.getPartyName(3)
         << "," << result.getPartyName(4) << "," << result.getAngerLevel() << "," << result.getNumMonstersDefeated() << endl;
    fout.close();
}

// collect all infromation based on the turns, the leader name, gold pieces and such to be displayed at the end of the game.
void displayEndgameResults(int score, Player people[], int anger_level, int num_monsters_defeated, bool is_sorcerer_defeated)
{
    int bonus = 0;
    if (is_sorcerer_defeated)
    {
        bonus = int(is_sorcerer_defeated) * 200;
    }
    Result res("", score + bonus, people, anger_level, num_monsters_defeated);

    cout << "GAME OVER" << endl;
    cout << "Base score: " << score << "pts" << endl;
    cout << "Sorcerer defeat bonus: " << bonus << "pts" << endl;
    cout << "Total score: " << res.getScore() << "pts" << endl;
    cout << "Number of defeated Monsters: " << res.getNumMonstersDefeated() << endl;
    cout << "Anger level: " << res.getAngerLevel() << endl;
    cout << appendResultsFile("leaderboard.txt", res);
}

// utilize the rand function to decide if a misfortune happens, and what that is. Use ints to correspond to a misfortune type.
// Reduces inventory count by specified amount in github for each type of misfortune. If it is armour, update each player object if
// the total count of amrour plates is less than 5.
int decideRandomMisfortune(Player people[], int PLAYER_ARR_SIZE, vector<Item> &items, Map map, int chance)
{
    const string white("\033[0m");            // for terminal display
    const string yellow_black("\033[30;43m"); // for terminal display
    const string yellow("\033[0;33m");        // for terminal display
    const string green("\033[0;32m");         // for terminal display
    const string red("\033[0;31m");           // for terminal display
    const string bright_blue("\033[0;96m");   // for terminal display

    int result = generateRandomInteger(1, 10);
    if (result < chance)
    {
        int internal_result = generateRandomInteger(1, 10);
        if (internal_result <= 3)
        {
            cout << yellow << "Oh no! You have been robbed by dungeon bandits!!" << endl;
            int ingredients_armour = generateRandomInteger(1, 2);
            if (items.at(getIndexOfIngredients(items)).getAmount() < 10 && items.at(getIndexOfArmour(items)).getAmount() > 0) // not enough ingredients
            {
                items.at(getIndexOfArmour(items)).setAmount(items.at(getIndexOfArmour(items)).getAmount() - 1); // reduce armour by 1
                cout << "You lost a piece of armour." << white << endl;
                // if armour count is now less than 5, randomly take a piece of armour from someone who has it.
                if (items.at(getIndexOfArmour(items)).getAmount() < 5 && items.at(getIndexOfArmour(items)).getAmount() > 0)
                {
                    do
                    {
                        int armour_index = generateRandomInteger(1, 5);
                        if (people[armour_index].getHasArmour() == true)
                        {
                            people[armour_index].setHasArmour(false);
                            break;
                        }
                    } while (true);
                }
                else if (items.at(getIndexOfArmour(items)).getAmount() == 0)
                {
                    for (int i = 0; i < PLAYER_ARR_SIZE; i++)
                    {
                        people[i].setHasArmour(false);
                    }
                }
            }
            else if (items.at(getIndexOfArmour(items)).getAmount() == 0 && items.at(getIndexOfIngredients(items)).getAmount() >= 10) // not enough armour
            {
                items.at(getIndexOfIngredients(items)).setAmount(items.at(getIndexOfIngredients(items)).getAmount() - 10); // reduce ingredients by 10
                cout << "You lost 10 ingredients." << white << endl;
            }
            else if (items.at(getIndexOfArmour(items)).getAmount() > 0 && items.at(getIndexOfIngredients(items)).getAmount() >= 10) // enough of both
            {
                if (ingredients_armour == 1) // reduce ingredients
                {
                    items.at(getIndexOfIngredients(items)).setAmount(items.at(getIndexOfIngredients(items)).getAmount() - 10); // reduce ingredients by 10
                    cout << "You lost 10 ingredients." << white << endl;
                }
                else // reduce armour
                {
                    items.at(getIndexOfArmour(items)).setAmount(items.at(getIndexOfArmour(items)).getAmount() - 1); // reduce armour by 1
                    cout << "You lost a piece of armour." << white << endl;
                    // if armour count is now less than 5, randomly take a piece of armour from someone who has it.
                    if (items.at(getIndexOfArmour(items)).getAmount() < 5 && items.at(getIndexOfArmour(items)).getAmount())
                    {
                        do
                        {
                            int armour_index = generateRandomInteger(1, 5);
                            if (people[armour_index].getHasArmour() == true)
                            {
                                people[armour_index].setHasArmour(false);
                                break;
                            }
                        } while (true);
                    }
                    else if (items.at(getIndexOfArmour(items)).getAmount() == 0)
                    {
                        for (int i = 0; i < PLAYER_ARR_SIZE; i++)
                        {
                            people[i].setHasArmour(false);
                        }
                    }
                }
            }
            else if (items.at(getIndexOfArmour(items)).getAmount() == 0 && items.at(getIndexOfIngredients(items)).getAmount() < 10)
            {
                cout << "Fortunately there was nothing worth stealing!" << white << endl;
            }

            return 1;
        }

        else if (internal_result == 4)
        {
            // collect all index's of weapons and armour if there are values greater than 0 of them
            int none_avail_counter = 0;
            bool res1_been_checked = false;
            bool res2_been_checked = false;
            bool res3_been_checked = false;
            bool res4_been_checked = false;
            bool res5_been_checked = false;
            bool res6_been_checked = false;
            do
            {
                int dicider = generateRandomInteger(1, 6);
                if (dicider == 1 && res1_been_checked == false)
                {
                    if (items.at(getIndexOfArmour(items)).getAmount() > 0)
                    {
                        items.at(getIndexOfArmour(items)).setAmount(items.at(getIndexOfArmour(items)).getAmount() - 1); // reduce armour by 1
                        cout << yellow << "Oh no! A piece of armour broke!" << white << endl;
                        // if armour count is now less than 5, randomly take a piece of armour from someone who has it.
                        if (items.at(getIndexOfArmour(items)).getAmount() < 5 && items.at(getIndexOfArmour(items)).getAmount())
                        {
                            do
                            {
                                int armour_index = generateRandomInteger(1, 5);
                                if (people[armour_index].getHasArmour() == true)
                                {
                                    people[armour_index].setHasArmour(false);
                                    break;
                                }
                            } while (true);
                        }
                        else if (items.at(getIndexOfArmour(items)).getAmount() == 0)
                        {
                            for (int i = 0; i < PLAYER_ARR_SIZE; i++)
                            {
                                people[i].setHasArmour(false);
                            }
                        }
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    res1_been_checked = true;
                }
                else if (dicider == 2 && res2_been_checked == false)
                {
                    if (items.at(getIndexOfAxe(items)).getAmount() > 0)
                    {
                        items.at(getIndexOfAxe(items)).setAmount(items.at(getIndexOfAxe(items)).getAmount() - 1); // reduce axe by 1
                        cout << yellow << "Oh no! Your axe broke!" << white << endl;
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    res2_been_checked = true;
                }
                else if (dicider == 3 && res3_been_checked == false)
                {
                    if (items.at(getIndexOfClub(items)).getAmount() > 0)
                    {
                        items.at(getIndexOfClub(items)).setAmount(items.at(getIndexOfClub(items)).getAmount() - 1); // reduce club by 1
                        cout << yellow << "Oh no! Your club broke!" << white << endl;
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    res3_been_checked = true;
                }
                else if (dicider == 4 && res4_been_checked == false)
                {
                    if (items.at(getIndexOfLongsword(items)).getAmount() > 0)
                    {
                        items.at(getIndexOfLongsword(items)).setAmount(items.at(getIndexOfLongsword(items)).getAmount() - 1); // reduce longsword by 1
                        cout << yellow << "Oh no! Your longsword broke!" << white << endl;
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    res4_been_checked = true;
                }
                else if (dicider == 5 && res5_been_checked == false)
                {
                    if (items.at(getIndexOfRapier(items)).getAmount() > 0)
                    {
                        items.at(getIndexOfRapier(items)).setAmount(items.at(getIndexOfRapier(items)).getAmount() - 1); // reduce rapier by 1
                        cout << yellow << "Oh no! Your rapier broke!" << white << endl;
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    res5_been_checked = true;
                }
                else if (dicider == 6 && res6_been_checked == false)
                {
                    if (items.at(getIndexOfSpear(items)).getAmount() > 0)
                    {
                        items.at(getIndexOfSpear(items)).setAmount(items.at(getIndexOfSpear(items)).getAmount() - 1); // reduce spear by 1
                        cout << yellow << "Oh no! Your spear broke!" << white << endl;
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    res6_been_checked = true;
                }
            } while (none_avail_counter < 6);
            if (none_avail_counter >= 6)
            {
                cout << "Fortunately, there was nothing to break." << endl;
            }
            return 2;
        }

        else if (internal_result > 4 && internal_result <= 7)
        {
            int none_avail_counter = 0;
            bool option1_checked = false;
            bool option2_checked = false;
            bool option3_checked = false;
            bool option4_checked = false;
            do
            {

                int member_index = generateRandomInteger(1, 4); // party member cannot get food poisoning
                if (option1_checked == false && member_index == 1)
                {
                    if (people[member_index].getDeath() == false)
                    {
                        people[member_index].setHunger(people[member_index].getHunger() - 10);
                        cout << yellow << people[member_index].getName() << " has gotten food poisoning!" << white << endl;
                        if (people[member_index].getHunger() <= 0)
                        {
                            people[member_index].setHunger(0);
                            people[member_index].setDeath(true);
                            cout << red << people[member_index].getName() << " has died of hunger!" << white << endl;
                        }
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    option1_checked = true;
                }
                else if (option2_checked == false && member_index == 2)
                {
                    if (people[member_index].getDeath() == false)
                    {
                        people[member_index].setHunger(people[member_index].getHunger() - 10);
                        cout << yellow << people[member_index].getName() << " has gotten food poisoning!" << white << endl;
                        if (people[member_index].getHunger() <= 0)
                        {
                            people[member_index].setHunger(0);
                            people[member_index].setDeath(true);
                            cout << red << people[member_index].getName() << " has died of hunger!" << white << endl;
                        }
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    option2_checked = true;
                }
                else if (option3_checked == false && member_index == 3)
                {
                    if (people[member_index].getDeath() == false)
                    {
                        people[member_index].setHunger(people[member_index].getHunger() - 10);
                        cout << yellow << people[member_index].getName() << " has gotten food poisoning!" << white << endl;
                        if (people[member_index].getHunger() <= 0)
                        {
                            people[member_index].setHunger(0);
                            people[member_index].setDeath(true);
                            cout << red << people[member_index].getName() << " has died of hunger!" << white << endl;
                        }
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    option3_checked = true;
                }
                else if (option4_checked == false && member_index == 4)
                {
                    if (people[member_index].getDeath() == false)
                    {
                        people[member_index].setHunger(people[member_index].getHunger() - 10);
                        cout << yellow << people[member_index].getName() << " has gotten food poisoning!" << white << endl;
                        if (people[member_index].getHunger() <= 0)
                        {
                            people[member_index].setHunger(0);
                            people[member_index].setDeath(true);
                            cout << red << people[member_index].getName() << " has died of hunger!" << white << endl;
                        }
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    option4_checked = true;
                }
            } while (none_avail_counter >= 4);
            return 3;
        }

        else if (internal_result > 7 && map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
        {

            int none_avail_counter = 0;
            bool option1_checked = false;
            bool option2_checked = false;
            bool option3_checked = false;
            bool option4_checked = false;
            do
            {

                int member_index = generateRandomInteger(1, 4); // party member cannot get stuck
                if (option1_checked == false && member_index == 1)
                {
                    if (people[member_index].getDeath() == false)
                    {
                        people[member_index].setStuck(true);
                        cout << yellow << people[member_index].getName() << " has gotten stuck in the room! You will need a key to get them out!" << white << endl;
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    option1_checked = true;
                }
                else if (option2_checked == false && member_index == 2)
                {
                    if (people[member_index].getDeath() == false)
                    {
                        people[member_index].setStuck(true);
                        cout << yellow << people[member_index].getName() << " has gotten stuck in the room! You will need a key to get them out!" << white << endl;
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    option2_checked = true;
                }
                else if (option3_checked == false && member_index == 3)
                {
                    if (people[member_index].getDeath() == false)
                    {
                        people[member_index].setStuck(true);
                        cout << yellow << people[member_index].getName() << " has gotten stuck in the room! You will need a key to get them out!" << white << endl;
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    option3_checked = true;
                }
                else if (option4_checked == false && member_index == 4)
                {
                    if (people[member_index].getDeath() == false)
                    {
                        people[member_index].setStuck(true);
                        cout << yellow << people[member_index].getName() << " has gotten stuck in the room! You will need a key to get them out!" << white << endl;
                        break;
                    }
                    else
                    {
                        none_avail_counter++;
                    }
                    option4_checked = true;
                }
            } while (none_avail_counter >= 4);
            return 4;
        }
    }

    else
    {
        return 0;
    }
}

// updates the map, the people array, the num mobes, and the anger level
// has check to see if the players die of hunger based on moving
// updates the num_moves and anger_level every time it is called
// Notes findings of a room or an NPC and displays their respective menu
// rooms and NPC's are found using the map class
bool move(Player people[], Map &map, int PLAYER_ARR_SIZE, int &num_moves, int &anger_level, bool is_sorcerer_defeated)
{
    const string white("\033[0m");            // for terminal display
    const string yellow_black("\033[30;43m"); // for terminal display
    const string yellow("\033[0;33m");        // for terminal display
    const string green("\033[0;32m");         // for terminal display
    const string red("\033[0;31m");           // for terminal display
    const string bright_blue("\033[0;96m");   // for terminal display
    char direction;
    string direction_string;
    cout << "Choose a direction (w - up, a - left, s - down, d - right):" << endl;
    getline(cin, direction_string);
    if (direction_string.length() > 1 || direction_string.length() == 0)
    {
        cout << red << "Invalid input." << white << endl;
        return false;
    }
    else
    {
        for (int i = 0; i < PLAYER_ARR_SIZE; i++) // check if player is dead based on hunger
        {
            if (people[i].getHunger() == 0 && people[i].getDeath() == false)
            {
                people[i].setDeath(true);
                cout << red << people[i].getName() << " has died of hunger!" << white << endl;
                if (people[0].getDeath() == true)
                {
                    // RUN ENDGAME FUNCTION
                }
            }
        }
        direction = direction_string[0];
        if (direction == 119 || direction == 97 || direction == 115 || direction == 100) // must be w a s d
        {
            map.move(direction);
            for (int i = 0; i < PLAYER_ARR_SIZE; i++) // change each player's position if they are alive
            {
                int position[2] = {map.getPlayerRow(),
                                   map.getPlayerCol()};
                if (people[i].getDeath() == false && people[i].getStuck() == false)
                {
                    people[i].setPosition(position);
                }
            }

            num_moves++;
            if (is_sorcerer_defeated == false)
            {
                anger_level++;
            }
            for (int i = 0; i < PLAYER_ARR_SIZE; i++) // reduce each alive players hunger based on chance
            {
                if (people[i].getDeath() == false)
                {
                    if (generateRandomInteger(2, 10) <= 2)
                    {
                        people[i].setHunger(people[i].getHunger() - 1);
                    }
                }
            }
            for (int i = 0; i < PLAYER_ARR_SIZE; i++) // warn player if someones hunger has reached zero
            {
                if (people[i].getHunger() == 0 && people[i].getDeath() == false)
                {
                    cout << red << people[i].getName() << "'s hunger has reached 0! They need to be fed next turn or they will die!" << white << endl;
                }
            }
            if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())) // explore space if it is an NPC location
            {
                map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                cout << bright_blue << "an NPC has been found!" << white << endl;
            }
            return true;
        }
        else
        {
            cout << red << "Invalid input." << white << endl;
            return false;
        }
    }
}

// randomly reduces the hunger for each player based on chance.
void reduceHunger(Player people[], int PLAYER_ARR_SIZE)
{
    for (int i = 0; i < PLAYER_ARR_SIZE; i++)
    {
        int chance = generateRandomInteger(1, 10);
        if (people[i].getDeath() == false && chance > 5)
        {
            people[i].setHunger(people[i].getHunger() - 1);
        }
    }
}

// using a standard input validation loop, player makes a choice for how much ingredients to use and what to cook with (provided they have it)
// uses the probabilities given in the github and the generateRandomInteger() function to decide if the cookware will break, thus losing it and
// all of the respective materials.
// increases each players hunger by 1 for every 5 ingredients used.
int displayCookingMenu(Player people[], int PLAYER_ARR_SIZE, vector<Item> &items)
{
    const string white("\033[0m");            // for terminal display
    const string yellow_black("\033[30;43m"); // for terminal display
    const string yellow("\033[0;33m");        // for terminal display
    const string green("\033[0;32m");         // for terminal display
    const string red("\033[0;31m");           // for terminal display
    const string bright_blue("\033[0;96m");   // for terminal display

    int cookware_counter = 0;
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).getType() == "cookware")
        {
            cookware_counter += items.at(i).getAmount();
        }
    }
    if (cookware_counter > 0 && items.at(getIndexOfIngredients(items)).getAmount() >= 5)
    {
        // display cooking menu
        // calculate num of each cookware
        int num_ingredients = items.at(getIndexOfIngredients(items)).getAmount();
        int num_pots = 0;
        int num_pans = 0;
        int num_cauldrons = 0;

        for (int i = 0; i < items.size(); i++)
        {
            if (items.at(i).getType() == "cookware" && items.at(i).getName() == "Pot")
            {
                num_pots = items.at(i).getAmount();
            }
        }
        for (int i = 0; i < items.size(); i++)
        {
            if (items.at(i).getType() == "cookware" && items.at(i).getName() == "Pan")
            {
                num_pans = items.at(i).getAmount();
            }
        }
        for (int i = 0; i < items.size(); i++)
        {
            if (items.at(i).getType() == "cookware" && items.at(i).getName() == "Cauldron")
            {
                num_cauldrons = items.at(i).getAmount();
            }
        }

        // actually display cooking menu
        int amount;
        string amount_string;
        do
        {
            cout << "How many ingredients would you like to use (Enter a multiple of 5, 0 to cancel. Every person gets +1 hunger\n"
                 << "for every 5 ingredients used)?" << endl;
            getline(cin, amount_string);
            if (amount_string.length() == 0)
            {
                cout << red << "Invalid input." << white << endl;
            }
            else
            {
                bool passed_int_check = true;
                for (int i = 0; i < amount_string.length(); i++)
                {
                    if (!isdigit(amount_string[i]))
                    {
                        cout << red << "Invalid input." << white << endl;
                        passed_int_check = false;
                        break;
                    }
                }
                if (passed_int_check == true)
                {
                    amount = stoi(amount_string);
                    if (stoi(amount_string) % 5 != 0)
                    {
                        cout << red << "Invalid input." << white << endl;
                    }
                    else if (amount > items.at(getIndexOfIngredients(items)).getAmount())
                    {
                        cout << yellow << "You don't have enough ingredients!" << white << endl;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        } while (true);
        int cookware_choice;
        string cookware_choice_string;
        if (amount > 0)
        {
            do
            {
                cout << "Which type of cookware would you like to use?" << endl;
                cout << "1. Pot" << endl;
                cout << "2. Pan" << endl;
                cout << "3. Cauldron" << endl;
                cout << "4. Cancel" << endl;
                getline(cin, cookware_choice_string);
                if (cookware_choice_string.length() == 0 || cookware_choice_string.length() > 1)
                {
                    cout << red << "Invalid input." << white << endl;
                }
                else
                {
                    if (!isdigit(cookware_choice_string[0]))
                    {
                        cout << red << "Invalid input." << white << endl;
                    }
                    else
                    {
                        cookware_choice = stoi(cookware_choice_string);
                        if (cookware_choice == 1)
                        {
                            if (items.at(getIndexOfPot(items)).getAmount() == 0)
                            {
                                cout << "You don't have any pots!" << endl;
                            }
                            else
                            {
                                // use pot
                                if (generateRandomInteger(1, 4) == 1)
                                {
                                    cout << yellow << "Oh no! It looks like the pot broke. Unfortunately this meal is ruined." << white << endl;
                                    items.at(getIndexOfPot(items)).setAmount(items.at(getIndexOfPot(items)).getAmount() - 1);
                                    items.at(getIndexOfIngredients(items)).setAmount(items.at(getIndexOfIngredients(items)).getAmount() - amount);
                                }
                                else
                                {
                                    int increase_amount = amount % 5;
                                    for (int i = 0; i < PLAYER_ARR_SIZE; i++)
                                    {
                                        people[i].setHunger(people[i].getHunger() + increase_amount);
                                    }
                                    items.at(getIndexOfIngredients(items)).setAmount(items.at(getIndexOfIngredients(items)).getAmount() - amount);
                                }
                                return 1;
                            }
                        }
                        else if (cookware_choice == 2)
                        {
                            if (items.at(getIndexOfPan(items)).getAmount() == 0)
                            {
                                cout << "You don't have any pans!" << endl;
                            }
                            else
                            {
                                // use pan
                                if (generateRandomInteger(1, 10) == 1)
                                {
                                    cout << yellow << "Oh no! It looks like the pan broke. Unfortunately this meal is ruined." << white << endl;
                                    items.at(getIndexOfPan(items)).setAmount(items.at(getIndexOfPan(items)).getAmount() - 1);
                                    items.at(getIndexOfIngredients(items)).setAmount(items.at(getIndexOfIngredients(items)).getAmount() - amount);
                                }
                                else
                                {
                                    int increase_amount = amount % 5;
                                    for (int i = 0; i < PLAYER_ARR_SIZE; i++)
                                    {
                                        people[i].setHunger(people[i].getHunger() + increase_amount);
                                    }
                                    items.at(getIndexOfIngredients(items)).setAmount(items.at(getIndexOfIngredients(items)).getAmount() - amount);
                                }
                                return 2;
                            }
                        }
                        else if (cookware_choice == 3)
                        {
                            if (items.at(getIndexOfCauldron(items)).getAmount() == 0)
                            {
                                cout << "You don't have any cauldrons!" << endl;
                            }
                            else
                            {
                                // use cauldron
                                if (generateRandomInteger(1, 4) == 1)
                                {
                                    cout << yellow << "Oh no! It looks like the cauldron broke. Unfortunately this meal is ruined." << white << endl;
                                    items.at(getIndexOfCauldron(items)).setAmount(items.at(getIndexOfCauldron(items)).getAmount() - 1);
                                    items.at(getIndexOfIngredients(items)).setAmount(items.at(getIndexOfIngredients(items)).getAmount() - amount);
                                }
                                else
                                {
                                    int increase_amount = amount % 5;
                                    for (int i = 0; i < PLAYER_ARR_SIZE; i++)
                                    {
                                        people[i].setHunger(people[i].getHunger() + increase_amount);
                                    }
                                    items.at(getIndexOfIngredients(items)).setAmount(items.at(getIndexOfIngredients(items)).getAmount() - amount);
                                }
                                return 3;
                            }
                        }
                        else if (cookware_choice == 4)
                        {
                            return 4;
                        }
                        else
                        {
                            cout << red << "Invalid input." << white << endl;
                        }
                    }
                }
            } while (true);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        cout << yellow << "You either don't have enough ingredients to cook, or no cookware! Find a merchant if you want to eat!" << white << endl;
        return 0;
    }
}

// based on an equation given in the github, determine if fighting a monster leads to victory or defeat.
// if defeat, update stats in each of the player objects, and reduce the treasure in the items vector.
// use rand() to calculate if the monster drops a key if it is defeated.
// if win, free the people trapped in the room and add gold and ingredients respective of github instructions
void fightMonster(vector<Item> &weapons, vector<Monster> &monsters, Player people[], Map &map, int PLAYER_ARR_SIZE, int &num_cleared_rooms, int level_increaser, int &num_monsters_defeated)
{
    const string white("\033[0m");            // for terminal display
    const string yellow_black("\033[30;43m"); // for terminal display
    const string yellow("\033[0;33m");        // for terminal display
    const string green("\033[0;32m");         // for terminal display
    const string red("\033[0;31m");           // for terminal display
    const string bright_blue("\033[0;96m");   // for terminal display

    int num_available_monsters = 0;
    int num_present_people = 0;
    int num_unique_weapons = 0;
    int d_added_bonus = 0;
    int num_base_weapons = 0; // either num of players if weapons is greater or num weapons if less.
    int damage_bonus = 0;
    int num_armour = weapons.at(getIndexOfArmour(weapons)).getAmount();
    int rand1 = generateRandomInteger(1, 6);
    int rand2 = generateRandomInteger(1, 6);

    // find num of monsters available
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters.at(i).getLevel() == num_cleared_rooms + level_increaser)
        {
            num_available_monsters++;
        }
    }

    // find num of base weapons - either the number of people or the number of weapons
    for (int i = 0; i < weapons.size(); i++)
    {
        if (weapons.at(i).getType() == "weapon")
        {
            num_base_weapons += weapons.at(i).getAmount();
        }
    }
    if (num_base_weapons == 0)
    {
        cout << "You don't have any weapons to fight with!" << endl;
        return;
    }
    if (num_cleared_rooms == 5)
    {
        cout << yellow << "The sorcerer is waiting for you..." << white << endl;
        return;
    }
    else if (num_available_monsters == 0)
    {
        cout << green << "Fortunately there are no monsters for you to fight at this level!" << white << endl;
        return;
    }
    else // if all other test cases fail, then the player can actually fight the monster.
    {
        Monster monster;
        int index;
        bool passed_case = false;
        do
        {
            index = generateRandomInteger(0, monsters.size() - 1);
            monster = monsters.at(index);
            if (monster.getLevel() == num_cleared_rooms + level_increaser)
            {
                passed_case = true;
            }
        } while (passed_case == false);
        // find number of present players
        for (int i = 0; i < PLAYER_ARR_SIZE; i++)
        {
            if (people[i].getPosition() == people[i].getPosition() && people[i].getDeath() == false)
            {
                num_present_people++;
            }
        }
        // find number of unique weapons and damage bonus
        if (weapons.at(getIndexOfClub(weapons)).getAmount() > 0)
        {
            num_unique_weapons++;
        }
        if (weapons.at(getIndexOfSpear(weapons)).getAmount() > 0)
        {
            num_unique_weapons++;
        }
        if (weapons.at(getIndexOfRapier(weapons)).getAmount() > 0)
        {
            num_unique_weapons++;
            damage_bonus += 1;
        }
        if (weapons.at(getIndexOfAxe(weapons)).getAmount() > 0)
        {
            num_unique_weapons++;
            damage_bonus += 2;
        }
        if (weapons.at(getIndexOfLongsword(weapons)).getAmount() > 0)
        {
            num_unique_weapons++;
            damage_bonus += 3;
        }
        if (num_present_people < num_base_weapons)
        {
            num_base_weapons = num_present_people;
        }
        if (num_unique_weapons >= num_present_people)
        {
            d_added_bonus = 4;
        }
        cout << red << "A " << monster.getName() << " has appeared!!!" << white << endl;
        // take input to either fight the monster or surrender
        int menu_choice = 0;
        string menu_choice_string;
        do
        {
            cout << "Choose an option:" << endl;
            cout << "1. Fight the " << monster.getName() << endl;
            cout << "2. Surrender to the " << monster.getName() << endl;
            getline(cin, menu_choice_string);
            if (menu_choice_string.length() > 1 || menu_choice_string.length() == 0)
            {
                cout << red << "Invalid input." << white << endl;
            }
            else
            {
                if (menu_choice_string[0] == 49 || menu_choice_string[0] == 50)
                {
                    menu_choice = stoi(menu_choice_string);
                    if (menu_choice == 1)
                    {
                        // fight monster
                        double outcome = (rand1 * num_base_weapons + d_added_bonus) - ((rand2 * (num_cleared_rooms + level_increaser)) / double(num_armour));
                        if (outcome > 0)
                        {
                            // win battle
                            cout << green << "You beat the " << monsters.at(index).getName() << "!" << white << endl;
                            weapons.at(getIndexOfGold(weapons)).setNum(weapons.at(getIndexOfGold(weapons)).getNum() + 10 * (num_cleared_rooms + level_increaser));
                            weapons.at(getIndexOfIngredients(weapons)).setAmount(weapons.at(getIndexOfIngredients(weapons)).getAmount() + 5 * (num_cleared_rooms + level_increaser));
                            if (generateRandomInteger(1, 10) == 1)
                            {
                                weapons.at(getIndexOfKey(weapons)).setAmount(weapons.at(getIndexOfKey(weapons)).getAmount() + 1); // add one key
                            }
                            monsters.erase(monsters.begin() + index);
                            // free party members if stuck
                            for (int i = 0; i < PLAYER_ARR_SIZE; i++)
                            {
                                string current_pos = "(" + to_string(map.getPlayerRow()) + ", " + to_string(map.getPlayerCol()) + ")";
                                if (people[i].getPosition() == current_pos)
                                {
                                    people[i].setStuck(false);
                                }
                            }
                            // if this is a room, remove it and decide larger chance of misfortune
                            if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()))
                            {
                                map.removeRoom(map.getPlayerRow(), map.getPlayerCol());
                                decideRandomMisfortune(people, PLAYER_ARR_SIZE, weapons, map, 6);
                                num_cleared_rooms++;
                            }
                            else
                            {
                                decideRandomMisfortune(people, PLAYER_ARR_SIZE, weapons, map, 4);
                            }
                            num_monsters_defeated++;
                        }
                        else
                        {
                            // lose battle
                            // subtract ingredients
                            cout << red << "You have LOST your battle to the " << monsters.at(index).getName() << "!" << white << endl;
                            double current_ingredients = weapons.at(getIndexOfIngredients(weapons)).getAmount();
                            int subtract_ingredients = int(current_ingredients * .25);
                            int new_ingred = subtract_ingredients;
                            if (subtract_ingredients >= 30)
                            {
                                new_ingred = 30;
                            }
                            weapons.at(getIndexOfIngredients(weapons)).setAmount(new_ingred);
                            // subtract gold
                            double current_gold = weapons.at(getIndexOfGold(weapons)).getNum();
                            int subtract_gold = int(current_gold * .75);
                            weapons.at(getIndexOfGold(weapons)).setNum(subtract_gold);
                            // determine player death probabilities using armour
                            for (int i = 0; i < PLAYER_ARR_SIZE; i++)
                            {
                                if (people[i].getHasArmour() == true)
                                {
                                    if (generateRandomInteger(1, 20) == 1)
                                    {
                                        people[i].setDeath(true);
                                        cout << red << people[i].getName() << " has been slain!" << white << endl;
                                    }
                                }
                                else
                                {
                                    if (generateRandomInteger(1, 10) == 1)
                                    {
                                        people[i].setDeath(true);
                                        cout << red << people[i].getName() << " has been slain!" << white << endl;
                                    }
                                }
                            }
                            // if this is a room, lose the key if there is one
                            if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()))
                            {
                                if (weapons.at(getIndexOfKey(weapons)).getAmount() > 0)
                                {
                                    weapons.at(getIndexOfKey(weapons)).setAmount(weapons.at(getIndexOfKey(weapons)).getAmount() - 1);
                                }
                            }
                            // just to add insult to injury, decide random misfortune
                            decideRandomMisfortune(people, PLAYER_ARR_SIZE, weapons, map, 4);
                        }
                        break;
                    }
                    if (menu_choice == 2)
                    {
                        // surrender
                        do
                        {
                            int index = generateRandomInteger(1, 5);
                            if (people[index].getDeath() == false && people[index].getStuck() == false)
                            {
                                cout << red << people[index].getName() << " has been taken captive and slain by the " << monster.getName() << "!" << endl;
                                people[index].setDeath(true);
                                break;
                            }
                        } while (true);
                        // just to add insult to injury, decide random misfortune
                        decideRandomMisfortune(people, PLAYER_ARR_SIZE, weapons, map, 4);
                        break;
                    }
                }
                else
                {
                    cout << red << "Invalid input." << white << endl;
                    menu_choice = 0;
                }
            }
        } while (menu_choice == 0);
        reduceHunger(people, PLAYER_ARR_SIZE);
        return;
    }
}

// same functionality as the fight monster function, only this updates the is_sorcerer_defeated variable that stops the anger_level count.
// This is made its own function becuase of slightly different calls. This can only be called when at the dungeon location, and the fight
// monster function can be called from anywhere.
void fightSorcerer(vector<Item> &weapons, vector<Monster> &monsters, Player people[], Map &map, int PLAYER_ARR_SIZE, int num_cleared_rooms, int level_increaser, bool &is_sorcerer_defeated, int &num_monsters_defeated)
{
    const string white("\033[0m");            // for terminal display
    const string yellow_black("\033[30;43m"); // for terminal display
    const string yellow("\033[0;33m");        // for terminal display
    const string green("\033[0;32m");         // for terminal display
    const string red("\033[0;31m");           // for terminal display
    const string bright_blue("\033[0;96m");   // for terminal display

    int num_available_monsters = 0;
    int num_present_people = 0;
    int num_unique_weapons = 0;
    int d_added_bonus = 0;
    int num_base_weapons = 0; // either num of players if weapons is greater or num weapons if less.
    int damage_bonus = 0;
    int num_armour = weapons.at(getIndexOfArmour(weapons)).getAmount();
    int rand1 = generateRandomInteger(1, 6);
    int rand2 = generateRandomInteger(1, 6);

    // find num of monsters available. Should be the Sorcerer.
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters.at(i).getLevel() == num_cleared_rooms + level_increaser)
        {
            num_available_monsters++;
        }
    }

    // find num of base weapons - either the number of people or the number of weapons
    for (int i = 0; i < weapons.size(); i++)
    {
        if (weapons.at(i).getType() == "weapon")
        {
            num_base_weapons += weapons.at(i).getAmount();
        }
    }
    if (num_base_weapons == 0)
    {
        cout << "You don't have any weapons to fight with!" << endl;
        return;
    }
    else if (num_cleared_rooms != 4)
    {
        cout << yellow << "You have not cleared all of the rooms yet!" << endl;
        return;
    }
    else if (num_available_monsters == 0)
    {
        cout << green << "Fortunately there are no monsters for you to fight at this level!" << white << endl;
        return;
    }
    else
    {
        // get sorcerer.
        Monster monster;
        int index;
        for (int i = 0; i < monsters.size(); i++)
        {
            if (monsters.at(i).getLevel() == 6)
            {
                monster = monsters.at(i);
                index = i;
                break;
            }
        }

        // find number of present players
        for (int i = 0; i < PLAYER_ARR_SIZE; i++)
        {
            if (people[i].getPosition() == people[i].getPosition() && people[i].getDeath() == false)
            {
                num_present_people++;
            }
        }
        // find number of unique weapons and damage bonus
        if (weapons.at(getIndexOfClub(weapons)).getAmount() > 0)
        {
            num_unique_weapons++;
        }
        if (weapons.at(getIndexOfSpear(weapons)).getAmount() > 0)
        {
            num_unique_weapons++;
        }
        if (weapons.at(getIndexOfRapier(weapons)).getAmount() > 0)
        {
            num_unique_weapons++;
            damage_bonus += 1;
        }
        if (weapons.at(getIndexOfAxe(weapons)).getAmount() > 0)
        {
            num_unique_weapons++;
            damage_bonus += 2;
        }
        if (weapons.at(getIndexOfLongsword(weapons)).getAmount() > 0)
        {
            num_unique_weapons++;
            damage_bonus += 3;
        }
        if (num_present_people < num_base_weapons)
        {
            num_base_weapons = num_present_people;
        }
        if (num_unique_weapons >= num_present_people)
        {
            d_added_bonus = 4;
        }

        cout << red << "The Sorcerer has appeared!!!" << white << endl;
        // take input to either fight the monster or leave
        int menu_choice = 0;
        string menu_choice_string;
        do
        {
            cout << "Choose an option:" << endl;
            cout << "1. Fight the " << monster.getName() << endl;
            cout << "2. Surrender to the " << monster.getName() << endl;
            getline(cin, menu_choice_string);
            if (menu_choice_string.length() > 1 || menu_choice_string.length() == 0)
            {
                cout << red << "Invalid input." << white << endl;
            }
            else
            {
                if (menu_choice_string[0] == 49 || menu_choice_string[0] == 50)
                {
                    menu_choice = stoi(menu_choice_string);
                    if (menu_choice == 1)
                    {
                        // fight monster
                        double outcome = (rand1 * num_base_weapons + d_added_bonus) - ((rand2 * (num_cleared_rooms + level_increaser)) / double(num_armour));
                        if (outcome > 0)
                        {
                            // win battle
                            cout << green << "You beat the " << monsters.at(index).getName() << "!" << white << endl;
                            weapons.at(getIndexOfGold(weapons)).setNum(weapons.at(getIndexOfGold(weapons)).getNum() + 10 * (num_cleared_rooms + level_increaser));
                            weapons.at(getIndexOfIngredients(weapons)).setAmount(weapons.at(getIndexOfIngredients(weapons)).getAmount() + 5 * (num_cleared_rooms + level_increaser));
                            if (generateRandomInteger(1, 10) == 1)
                            {
                                weapons.at(getIndexOfKey(weapons)).setAmount(weapons.at(getIndexOfKey(weapons)).getAmount() + 1); // add one key
                            }
                            monsters.erase(monsters.begin() + index);
                            is_sorcerer_defeated = true;
                            // free party members if stuck
                            for (int i = 0; i < PLAYER_ARR_SIZE; i++)
                            {
                                string current_pos = "(" + to_string(map.getPlayerRow()) + ", " + to_string(map.getPlayerCol()) + ")";
                                if (people[i].getPosition() == current_pos)
                                {
                                    people[i].setStuck(false);
                                }
                            }
                            // decide larger misfortune chance
                            num_cleared_rooms++;
                            num_monsters_defeated++;
                            decideRandomMisfortune(people, PLAYER_ARR_SIZE, weapons, map, 6);
                        }
                        else
                        {
                            // lose battle
                            // subtract ingredients
                            cout << red << "You have LOST your battle to the " << monsters.at(index).getName() << "!" << white << endl;
                            double current_ingredients = weapons.at(getIndexOfIngredients(weapons)).getAmount();
                            int subtract_ingredients = int(current_ingredients * .25);
                            int new_ingred = subtract_ingredients;
                            if (subtract_ingredients >= 30)
                            {
                                new_ingred = 30;
                            }
                            weapons.at(getIndexOfIngredients(weapons)).setAmount(new_ingred);
                            // subtract gold
                            double current_gold = weapons.at(getIndexOfGold(weapons)).getNum();
                            int subtract_gold = int(current_gold * .75);
                            weapons.at(getIndexOfGold(weapons)).setNum(subtract_gold);
                            // determine player death probabilities using armour
                            for (int i = 0; i < PLAYER_ARR_SIZE; i++)
                            {
                                if (people[i].getHasArmour() == true)
                                {
                                    if (generateRandomInteger(1, 20) == 1)
                                    {
                                        people[i].setDeath(true);
                                        cout << red << people[i].getName() << " has been slain!" << white << endl;
                                    }
                                }
                                else
                                {
                                    if (generateRandomInteger(1, 10) == 1)
                                    {
                                        people[i].setDeath(true);
                                        cout << red << people[i].getName() << " has been slain!" << white << endl;
                                    }
                                }
                            }
                            // if this is a room, lose the key if there is one
                            if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()))
                            {
                                if (weapons.at(getIndexOfKey(weapons)).getAmount() > 0)
                                {
                                    weapons.at(getIndexOfKey(weapons)).setAmount(weapons.at(getIndexOfKey(weapons)).getAmount() - 1);
                                }
                            }
                            // just to add insult to injury, decide random misfortune
                            decideRandomMisfortune(people, PLAYER_ARR_SIZE, weapons, map, 4);
                        }
                        break;
                    }
                    if (menu_choice == 2)
                    {
                        // surrender
                        do
                        {
                            int index = generateRandomInteger(1, 5);
                            if (people[index].getDeath() == false && people[index].getStuck() == false)
                            {
                                cout << red << people[index].getName() << " has been taken captive and slain by the " << monster.getName() << "!" << endl;
                                people[index].setDeath(true);
                                break;
                            }
                        } while (true);
                        // just to add insult to injury, decide random misfortune
                        decideRandomMisfortune(people, PLAYER_ARR_SIZE, weapons, map, 4);
                        break;
                    }
                }
                else
                {
                    cout << red << "Invalid input." << white << endl;
                    menu_choice = 0;
                }
            }
        } while (menu_choice == 0);
        reduceHunger(people, PLAYER_ARR_SIZE);
        return;
    }
}

// This looks humungous, but the code is largely repetitive, just varied slightly.
// checks to see if the room found is in fact the dungeon exit. If it is, continue as it is a room, but fight the sorcerer if possible
// instead of a standard monster.
// if the player chooses move in the opetions, utilise the move function
// opening the door without the use of a key requires the user to play a game of rock paper scissors.
// if the user does not beat the door guard within three tries, one of the team members (not the player) gets locked in the room.
// Those players locked inside are not freed until the room is cleared by fighting a monster after the door has been opened.
// Trapping loop is huge becuase it ensures someone gets trapped at all times (some may be dead), unless there is no party members except the player.
int displayRoomMenu(vector<NPC> npcs, Player people[], Map &map, int PLAYER_ARR_SIZE, int &num_moves, int &anger_level, vector<Item> &items,
                    int &num_cleared_rooms, int &num_items_purchased, int &num_items_sold, int &num_correct_riddles, vector<Monster> &monsters, bool &is_sorcerer_defeated, int &num_monsters_defeated)
{
    const string white("\033[0m");            // for terminal display
    const string yellow_black("\033[30;43m"); // for terminal display
    const string yellow("\033[0;33m");        // for terminal display
    const string green("\033[0;32m");         // for terminal display
    const string red("\033[0;31m");           // for terminal display
    const string bright_blue("\033[0;96m");   // for terminal display

    if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
    {
        cout << bright_blue << "You've found the dungeon exit!" << white << endl;
    }
    else
    {
        cout << bright_blue << "You have encountered a room!" << white << endl;
    }
    int menu_choice;
    string menu_choice_string;
    do
    {
        cout << "1. Move" << endl;
        cout << "2. Open Door" << endl;
        cout << "3. Give up" << endl;
        getline(cin, menu_choice_string);
        if (menu_choice_string.length() == 0 || menu_choice_string.length() > 1)
        {
            cout << red << "Invalid input." << white << endl;
        }
        else
        {
            if (!isdigit(menu_choice_string[0]))
            {
                cout << red << "Invalid input." << white << endl;
            }
            else
            {
                menu_choice = stoi(menu_choice_string);
                if (menu_choice == 1)
                {
                    move(people, map, PLAYER_ARR_SIZE, num_moves, anger_level, is_sorcerer_defeated);
                    return 1;
                }
                else if (menu_choice == 2)
                {
                    // key puzzle, fight monster
                    if (items.at(getIndexOfKey(items)).getAmount() > 0)
                    {
                        // use key
                        cout << "Luckily you have a key to open this door! Lets use it..." << endl;
                        items.at(getIndexOfKey(items)).setAmount(items.at(getIndexOfKey(items)).getAmount() - 1);
                        // update map and num_cleared_rooms inside fightmonster function
                        if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
                        {
                            fightSorcerer(items, monsters, people, map, PLAYER_ARR_SIZE, num_cleared_rooms, 2, is_sorcerer_defeated, num_monsters_defeated);
                        }
                        else
                        {
                            fightMonster(items, monsters, people, map, PLAYER_ARR_SIZE, num_cleared_rooms, 2, num_monsters_defeated);
                        }
                    }
                    else
                    {
                        // rock paper scissors
                        int counter = 1;
                        int menu_choice;
                        string menu_choice_string;
                        cout << "You don't have a key. You'll have to beat the door guard in a game of Boulder, Parchment, Shears!" << endl;
                        cout << green << "If you don't beat me in three tries, I'm locking one of you inside!" << white << endl;
                        do
                        {
                            int game_choice = generateRandomInteger(1, 3);
                            cout << "Boulder, Parchment, or Shears?" << endl;
                            cout << "1. Boulder" << endl;
                            cout << "2. Parchment" << endl;
                            cout << "3. Shears" << endl;
                            getline(cin, menu_choice_string);
                            if (menu_choice_string.length() == 0 || menu_choice_string.length() > 1)
                            {
                                cout << red << "Invalid input." << white << endl;
                            }
                            else
                            {
                                if (!isdigit(menu_choice_string[0]))
                                {
                                    cout << red << "Invalid input." << white << endl;
                                }
                                else
                                {
                                    menu_choice = stoi(menu_choice_string);
                                    if (menu_choice == 1 && game_choice == 1)
                                    {
                                        counter++;
                                        cout << "It's a tie! This is try number " << counter << endl;
                                    }
                                    if (menu_choice == 1 && game_choice == 2)
                                    {
                                        counter++;
                                        cout << "You lost! This is try number " << counter << endl;
                                    }
                                    if (menu_choice == 1 && game_choice == 3)
                                    {
                                        cout << "You win! But now you must fight a monster..." << endl;
                                        // update map inside fightmonster function
                                        if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
                                        {
                                            fightSorcerer(items, monsters, people, map, PLAYER_ARR_SIZE, num_cleared_rooms, 1, is_sorcerer_defeated, num_monsters_defeated);
                                        }
                                        else
                                        {
                                            fightMonster(items, monsters, people, map, PLAYER_ARR_SIZE, num_cleared_rooms, 2, num_monsters_defeated);
                                        }
                                        break;
                                    }
                                    else if (menu_choice == 2 && game_choice == 1)
                                    {
                                        cout << "You win! But now you must fight a monster..." << endl;
                                        // update map inside fightmonster function
                                        if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
                                        {
                                            fightSorcerer(items, monsters, people, map, PLAYER_ARR_SIZE, num_cleared_rooms, 1, is_sorcerer_defeated, num_monsters_defeated);
                                        }
                                        else
                                        {
                                            fightMonster(items, monsters, people, map, PLAYER_ARR_SIZE, num_cleared_rooms, 2, num_monsters_defeated);
                                        }
                                        break;
                                    }
                                    else if (menu_choice == 2 && game_choice == 2)
                                    {
                                        counter++;
                                        cout << "It's a tie! This is try number " << counter << endl;
                                    }
                                    else if (menu_choice == 2 && game_choice == 3)
                                    {
                                        counter++;
                                        cout << "You lost! This is try number " << counter << endl;
                                    }
                                    else if (menu_choice == 3 && game_choice == 1)
                                    {
                                        counter++;
                                        cout << "You lost! This is try number " << counter << endl;
                                    }
                                    else if (menu_choice == 3 && game_choice == 2)
                                    {
                                        cout << "You win! But now you must fight a monster..." << endl;
                                        // update map inside fightmonster function
                                        if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
                                        {
                                            fightSorcerer(items, monsters, people, map, PLAYER_ARR_SIZE, num_cleared_rooms, 1, is_sorcerer_defeated, num_monsters_defeated);
                                        }
                                        else
                                        {
                                            fightMonster(items, monsters, people, map, PLAYER_ARR_SIZE, num_cleared_rooms, 2, num_monsters_defeated);
                                        }
                                        break;
                                    }
                                    else if (menu_choice == 3 && game_choice == 3)
                                    {
                                        counter++;
                                        cout << "It's a tie! This is try number " << counter << endl;
                                    }
                                    else if (menu_choice > 3 || menu_choice < 1)
                                    {
                                        cout << red << "Invalid input." << white << endl;
                                    }
                                    cout << counter << endl;
                                }
                            }

                        } while (counter <= 3);
                        if (counter > 3)
                        {
                            // trap one of the players in the room

                            int none_avail_counter = 0;
                            bool option1_checked = false;
                            bool option2_checked = false;
                            bool option3_checked = false;
                            bool option4_checked = false;
                            do
                            {

                                int member_index = generateRandomInteger(1, 4); // party member cannot get stuck
                                if (option1_checked == false && member_index == 1)
                                {
                                    if (people[member_index].getDeath() == false)
                                    {
                                        people[member_index].setStuck(true);
                                        cout << yellow << people[member_index].getName() << " has gotten stuck in the room! You will need a key to get them out!" << white << endl;
                                        break;
                                    }
                                    else
                                    {
                                        none_avail_counter++;
                                    }
                                    option1_checked = true;
                                }
                                else if (option2_checked == false && member_index == 2)
                                {
                                    if (people[member_index].getDeath() == false)
                                    {
                                        people[member_index].setStuck(true);
                                        cout << yellow << people[member_index].getName() << " has gotten stuck in the room! You will need a key to get them out!" << white << endl;
                                        break;
                                    }
                                    else
                                    {
                                        none_avail_counter++;
                                    }
                                    option2_checked = true;
                                }
                                else if (option3_checked == false && member_index == 3)
                                {
                                    if (people[member_index].getDeath() == false)
                                    {
                                        people[member_index].setStuck(true);
                                        cout << yellow << people[member_index].getName() << " has gotten stuck in the room! You will need a key to get them out!" << white << endl;
                                        break;
                                    }
                                    else
                                    {
                                        none_avail_counter++;
                                    }
                                    option3_checked = true;
                                }
                                else if (option4_checked == false && member_index == 4)
                                {
                                    if (people[member_index].getDeath() == false)
                                    {
                                        people[member_index].setStuck(true);
                                        cout << yellow << people[member_index].getName() << " has gotten stuck in the room! You will need a key to get them out!" << white << endl;
                                        break;
                                    }
                                    else
                                    {
                                        none_avail_counter++;
                                    }
                                    option4_checked = true;
                                }
                            } while (none_avail_counter >= 4);
                        }
                    }
                    return 2;
                }
                else if (menu_choice == 3)
                {
                    return 3;
                }
                else
                {
                    cout << red << "Invalid input." << white << endl;
                }
            }
        }
    } while (true);
}

// displays the NPC menu, and provides the riddle function. If a player decides to
// solve a riddle, then one will be randomly generated, and if the answer is correct, then
// it will not be asked again because of the correct parameter in the riddle class.
// decides random misfortune within the menu. FIGHTMONSTER NEEDS TO BE IMPLEMENTED.
int displayNPCMenu(vector<NPC> npcs, Player people[], Map &map, int PLAYER_ARR_SIZE, int &num_moves, int &anger_level, vector<Item> &items,
                   int num_cleared_rooms, int &num_items_purchased, int &num_items_sold, int &num_correct_riddles, vector<Monster> &monsters, bool is_sorcerer_defeated, int &num_monsters_defeated)
{
    const string white("\033[0m");            // for terminal display
    const string yellow_black("\033[30;43m"); // for terminal display
    const string yellow("\033[0;33m");        // for terminal display
    const string green("\033[0;32m");         // for terminal display
    const string red("\033[0;31m");           // for terminal display
    const string bright_blue("\033[0;96m");   // for terminal display

    int menu_choice;
    string menu_choice_string;
    do
    {
        cout << "1. move" << endl;
        cout << "2. Speak to NPC" << endl;
        cout << "3. Give up" << endl;
        getline(cin, menu_choice_string);
        if (menu_choice_string.length() > 1 || menu_choice_string.length() == 0)
        {
            cout << red << "Invalid input." << white << endl;
            menu_choice = 0;
        }
        else
        {
            menu_choice = stoi(menu_choice_string);
            if (menu_choice == 1) // move
            {
                move(people, map, PLAYER_ARR_SIZE, num_moves, anger_level, is_sorcerer_defeated);
                return 1;
            }
            else if (menu_choice == 2) // riddle
            {
                if (npcs.size() > 0)
                {
                    int min_index = 0;
                    int max_index = npcs.size() - 1;
                    int index = 0;
                    string answer;
                    do // ensures riddle is not repeated if it is passed.
                    {
                        index = generateRandomInteger(min_index, max_index);
                    } while (npcs.at(index).getCleared() == true);

                    cout << green << "I have a riddle for you. If you solve it correctly, I might be willing to barter.\n"
                         << "You won't see me again after this so think hard!" << white << endl;
                    cout << npcs.at(index).getRiddle() << "\n"
                         << endl;
                    cout << "Answer: ";
                    getline(cin, answer);
                    cout << endl;
                    if (answer == npcs.at(index).getAnswer())
                    {
                        cout << green << "Correct!" << white << endl;
                        npcs.at(index).setCleared(true);
                        displayMerchantMenu(items, num_cleared_rooms, num_items_purchased, num_items_sold, people, PLAYER_ARR_SIZE);
                        decideRandomMisfortune(people, PLAYER_ARR_SIZE, items, map, 4);
                    }
                    else
                    {
                        cout << red << "Incorrect!" << white << endl;
                        cout << "The merchant has summoned a monster!" << endl;
                        fightMonster(items, monsters, people, map, PLAYER_ARR_SIZE, num_cleared_rooms, 1, num_monsters_defeated);
                    }
                    map.removeNPC(map.getPlayerRow(), map.getPlayerCol()); // NPC cannot be accessed again.
                    return 2;
                }
                else
                {
                    cout << green << "Unfortunatly I have no more riddles for you! But if you'd like to purchase something, I'm willing to barter." << white << endl;
                    displayMerchantMenu(items, num_cleared_rooms, num_items_purchased, num_items_sold, people, PLAYER_ARR_SIZE);
                    map.removeNPC(map.getPlayerRow(), map.getPlayerCol()); // NPC cannot be accessed again.
                    decideRandomMisfortune(people, PLAYER_ARR_SIZE, items, map, 4);
                    return 2;
                }
            }
            else if (menu_choice == 3) // give up
            {
                return 3;
            }
            else
            {
                cout << red << "Invalid input." << white << endl;
                menu_choice = 0;
            }
        }

    } while (menu_choice == 0);
}

// similar to the NPC, Room, and Cooking menu, utilise a do-while loop to validate user input for two choices: leave game or move
// If the player chooses move, run the move function.
// If the player chooses leave, end the game and append stuff to the leaderboard file.
int displayExitMenu(int score, int num_monsters_defeated, bool is_sorcerer_defeated, Map map, Player people[], int PLAYER_ARR_SIZE, int num_moves, int anger_level)
{
    const string white("\033[0m");            // for terminal display
    const string yellow_black("\033[30;43m"); // for terminal display
    const string yellow("\033[0;33m");        // for terminal display
    const string green("\033[0;32m");         // for terminal display
    const string red("\033[0;31m");           // for terminal display
    const string bright_blue("\033[0;96m");   // for terminal display
    int final_score = 0;
    if (is_sorcerer_defeated)
    {
        final_score = score + num_monsters_defeated + 250;
    }
    else
    {
        final_score = score + num_monsters_defeated;
    }

    int menu_choice;
    string menu_choice_string;
    if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) && is_sorcerer_defeated == true) // only for dungeon exit menu
    {
        do // standard input validation loop
        {
            cout << bright_blue << "You have beaten the Sorcerer!" << white << endl;
            cout << "1. Move" << endl;
            cout << green << "2. Exit the dungeon" << white << endl;
            getline(cin, menu_choice_string);
            if (menu_choice_string.length() == 0)
            {
                cout << red << "Invalid input." << white << endl;
            }
            else
            {
                if (!isdigit(menu_choice_string[0]))
                {
                    cout << red << "Invalid input." << white << endl;
                }
                else
                {
                    menu_choice = stoi(menu_choice_string);
                    if (menu_choice == 1)
                    {
                        move(people, map, PLAYER_ARR_SIZE, num_moves, anger_level, is_sorcerer_defeated);
                        return 1;
                    }
                    else if (menu_choice == 2)
                    {
                        cout << green << "\n\nYOU WIN!" << white << endl;
                        displayEndgameResults(score, people, anger_level, num_monsters_defeated, is_sorcerer_defeated);
                        return 2;
                    }
                    else
                    {
                        cout << red << "Invalid input." << white << endl;
                    }
                }
            }
        } while (true);
    }
    else // for give up, or if the main player dies, or the anger level reaches 100 before the player beats the Sorcerer.
    {
        if (is_sorcerer_defeated)
        {
            cout << "\n\n   You may have defeated the Sorcerer, but you didn't exit the dungeon!" << endl;
            displayEndgameResults(score, people, anger_level, num_monsters_defeated, is_sorcerer_defeated);
            return 0;
        }
        else
        {
            cout << red << "\n\n   YOU LOST." << white << endl;
            displayEndgameResults(score, people, anger_level, num_monsters_defeated, is_sorcerer_defeated);
            return 0;
        }
    }
}
// to be altered as the program progresses, for now just assert that the vectors of objects is instanciated correctly.
int tester(Player people[], vector<Monster> monsters, vector<NPC> npcs, vector<Item> items)
{
    const string white("\033[0m");            // for terminal display
    const string yellow_black("\033[30;43m"); // for terminal display
    const string yellow("\033[0;33m");        // for terminal display
    cout << yellow_black << "////// TESTER FUNCTION //////" << yellow << endl;

    cout << "The following numbers should be completely random between 1 and 100: ";
    int max = 100;
    int min = 1;
    for (int i = 0; i < 5; i++)
    {
        cout << rand() % (max - min + 1) + min << ", ";
    }
    cout << endl;

    cout << "Party members: ";
    for (int i = 0; i < 5; i++)
    {
        cout << people[i].getName() << ", " << people[i].getHunger() << "; ";
    }
    cout << endl;

    cout << "\n ********************** \n"
         << endl;
    cout << "Monsters: (only printing the name)";
    for (int i = 0; i < monsters.size(); i++)
    {
        cout << monsters.at(i).getName() << ", ";
    }
    cout << endl;

    cout << "\n ********************** \n"
         << endl;
    cout << "NPCs (only printing the answer): ";
    for (int i = 0; i < npcs.size(); i++)
    {
        cout << npcs.at(i).getAnswer() << ", ";
    }
    cout << endl;

    cout << "\n ********************** \n"
         << endl;
    cout << "Inventory (printing name and amount): ";
    for (int i = 0; i < items.size(); i++)
    {
        cout << items.at(i).getName() << "; " << items.at(i).getAmount() << ", ";
    }
    cout << endl;

    cout << yellow_black << "////// END TESTER FUNCTION //////" << white << endl;
}

int mapTester(Map map)
{
    const string white("\033[0m");            // for terminal display
    const string yellow_black("\033[30;43m"); // for terminal display
    const string red_black("\033[30;41m");    // for terminal display
    const string yellow("\033[0;33m");        // for terminal display
    cout << red_black << "////// MAP TESTER FUNCTION //////" << yellow << endl;
    cout << "Num rows: " << map.getNumRows() << endl;
    cout << "Num columns: " << map.getNumCols() << endl;
    cout << "NPC Count: " << map.getNPCCount() << endl;
    cout << "NPC Spaces:" << endl;
    for (int i = 0; i < map.getNumRows(); i++)
    {
        for (int j = 0; j < map.getNumCols(); j++)
        {
            if (map.isNPCLocation(i, j))
            {
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }
    cout << endl;
    cout << "Room Count: " << map.getRoomCount() << endl;
    cout << "Room Spaces:" << endl;
    for (int i = 0; i < map.getNumRows(); i++)
    {
        for (int j = 0; j < map.getNumCols(); j++)
        {
            if (map.isRoomLocation(i, j))
            {
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }
    cout << endl;
    cout << "Dungeon Exit: ";
    for (int i = 0; i < map.getNumRows(); i++)
    {
        for (int j = 0; j < map.getNumCols(); j++)
        {
            if (map.isDungeonExit(i, j))
            {
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }
    cout << red_black << "////// END MAP TESTER FUNCTION //////" << white << endl;
}

// ****** MAIN FUNCTION ****** //

int main()
{
    const string white("\033[0m");            // for terminal display
    const string yellow_black("\033[30;43m"); // for terminal display
    const string yellow("\033[0;33m");        // for terminal display
    const string green("\033[0;32m");         // for terminal display
    const string red("\033[0;31m");           // for terminal display
    const string bright_blue("\033[0;96m");   // for terminal display
    // inventory stuff:
    // gold type = currency
    // ingredients type = food
    // cookware type = cookware
    // weapons type = weapon
    // armour type = armour
    // treasure type = treasure

    // Minimum Requirements Checklist
    // 4+ user defined classes - ✅
    //    classes with 4+ data members - Player and Item ✅
    //    array of objects from another class - ✅
    //    getters and setters for each class - ✅
    // 6+ if else statements - ✅
    // 6+ loops - ✅
    // 2+ nested loops - L:2642, 2789 (and others) ✅
    // File IO - ✅
    // Interactive menu - ✅
    // Status update - ✅

    // create results vector
    vector<Result> results;
    readLeaderboardFile("leaderboard.txt", results);

    // display main menu
    int main_menu;
    string main_menu_string;
    do
    {
        cout << " *----* DUNGEON ESCAPE *----*" << endl;
        cout << "1. Play game" << endl;
        cout << "2. Diplay leaderboard" << endl;
        cout << "3. Exit program" << endl;
        getline(cin, main_menu_string);
        if (main_menu_string.length() > 1)
        {
            cout << red << "Invalid input." << white << endl;
        }
        else
        {
            if (!isdigit(main_menu_string[0]))
            {
                cout << red << "Invalid input." << white << endl;
            }
            else
            {
                main_menu = stoi(main_menu_string);
                if (main_menu == 1)
                {
                    break;
                }
                if (main_menu == 2)
                {
                    displayLeaderBoard(results);
                    cout << "\n"
                         << endl;
                }
                if (main_menu == 3)
                {
                    return 0;
                }
                else if (main_menu > 3 || main_menu < 1)
                {
                    cout << red << "Invalid input." << white << endl;
                }
            }
        }
    } while (true);

    // initial object creaton
    const int PLAYER_ARR_SIZE = 5;
    Player people[PLAYER_ARR_SIZE];
    vector<Monster> monsters;
    vector<NPC> npcs;
    vector<Item> items;
    string monsters_file = "Monsters.txt";
    string riddles_file = "Riddles.txt";
    items.push_back(Item(100));
    items.push_back(Item("food", "Ingredients"));
    items.push_back(Item("cookware", "Pot"));
    items.push_back(Item("cookware", "Pan"));
    items.push_back(Item("cookware", "Cauldron"));
    items.push_back(Item("weapon", "Club"));
    items.push_back(Item("weapon", "Spear"));
    items.push_back(Item("weapon", "Rapier"));
    items.push_back(Item("weapon", "Axe"));
    items.push_back(Item("weapon", "Longsword"));
    items.push_back(Item("armour", "Armour"));
    items.push_back(Item("treasure", "Silver ring"));
    items.push_back(Item("treasure", "Ruby necklace"));
    items.push_back(Item("treasure", "Emerald bracelet"));
    items.push_back(Item("treasure", "Diamond circlet"));
    items.push_back(Item("treasure", "Gem-encrusted goblet"));
    items.push_back(Item("key", "Key"));
    Map map;
    // seed the rand() function
    srand(time(0));
    // useful variables
    bool is_sorcerer_defeated = false;
    int num_cleared_rooms = 0;
    int num_keys = 0;
    int anger_level = 0;
    int num_found_treasure = 0;
    int num_moves = 0;
    int num_items_purchased = 0;
    int num_items_sold = 0;
    int num_correct_riddles = 0;
    int num_monsters_defeated = 0;

    // **************************************************************************** //
    // PHASE 1
    /*
    Ask for player names and instanciate player objects
    Read monster files and put into a monster vector
    Read riddle file and put into a riddle vector
    Instanciate a map object using random numbers (Escape door must be in the last row)
    instanciate items vector
    Display the merchnat menu and change amounts in item inventory based on user input
    */

    // create people vector
    for (int i = 0; i < 5; i++)
    {
        string name;
        if (i != 0)
        {
            cout << "Enter party member " << i << " name:" << endl;
            getline(cin, name);
        }
        else
        {
            cout << "Enter player name:" << endl;
            getline(cin, name);
        }
        Player person(name);
        people[i] = person;
    }

    // create monsters vector
    int monster_result = readMonsterFile(monsters_file, monsters);
    assert(monster_result == 21);

    // create NPC vector
    int npc_result = readRiddleFile(riddles_file, npcs);
    assert(npc_result == 20);

    // generate NPC spaces, room spaces, and dungeon exit
    int i = 0;
    while (i < 5)
    {
        int row = generateRandomInteger(0, 10);
        int column = generateRandomInteger(0, 11);
        if (map.isFreeSpace(row, column))
        {
            assert(map.addNPC(row, column));
            i++;
        }
    }
    assert(map.getNPCCount() == 5);
    i = 0;
    while (i < 4)
    {
        int row = generateRandomInteger(0, 10);
        int column = generateRandomInteger(0, 11);
        if (map.isFreeSpace(row, column))
        {
            assert(map.addRoom(row, column));
            i++;
        }
    }
    assert(map.getRoomCount() == 4);
    map.displayMap();
    displayStatus(num_cleared_rooms, num_keys, anger_level, items, people, num_monsters_defeated);
    // mapTester(map);
    // tester(people, monsters, npcs, items);
    cout << yellow << "\nWelcome to the Dungeon." << endl;
    cout << "Your goal is to escape the dungeon, but you can only do that by defeating all of the monsters in each of the rooms displayed on your map." << endl;
    cout << "You may encounter people within the dungeon that may provide you with materials necessary to your success." << endl;
    cout << "One thing to note though, if the Sorcerer's anger reaches 100, he will kill everyone and everything in the dungeon!!" << endl;
    cout << "Good luck...\n"
         << white
         << endl;
    displayMerchantMenu(items, num_cleared_rooms, num_items_purchased, num_items_sold, people, PLAYER_ARR_SIZE);
    // **************************************************************************** //
    // PHASE 2
    /*
    In a while loop, present the user with the following options in any normal space:
    1. move
    2. investigate
    3. pick a fight
    4. cook and eat
    5. give up

    If the player is in an NPC occupied space, present them with the following options:
    1. move
    2. speak to the NPC
    3. give up
    If they choose 2, present with a riddle to solve.
    If solved correctly, open the merchant menu
    If not, fight a monster

    If the player is in a room occupied space, present them with the following options:
    1. move
    2. open the door (PLAYER MUST HAVE A KEY OR BARTER WITH GUARD)
    3. give up
    */
    // note: player needs to have keys to open the door. They can get them by pissing off an NPC, or simply picking a fight.
    string menu_choice_string;
    int menu_choice = 0;
    do
    {
        cout << "\n " << bright_blue << "MAP:" << white << endl;

        map.displayMap();
        displayStatus(num_cleared_rooms, num_keys, anger_level, items, people, num_monsters_defeated);
        displayScore(num_cleared_rooms, anger_level, num_found_treasure, num_moves, num_items_purchased, num_items_sold, num_monsters_defeated);
        int score = calculateScore(num_cleared_rooms, anger_level, num_found_treasure, num_moves, num_items_purchased, num_items_sold, num_monsters_defeated);
        cout
            << endl;
        cout << yellow << "*MAIN MENU*" << white << endl;
        cout << "1. move" << endl;
        cout << "2. investigate" << endl;
        cout << "3. pick a fight" << endl;
        cout << "4. cook and eat" << endl;
        cout << "5. give up" << endl;
        getline(cin, menu_choice_string);
        if (menu_choice_string.length() > 1 || menu_choice_string.length() == 0)
        {
            cout << red << "Invalid input." << endl;
            menu_choice = 0;
        }
        else
        {
            if (menu_choice_string[0] > 53 || menu_choice_string[0] < 49)
            {
                cout << red << "Invalid input." << endl;
                menu_choice = 0;
            }
            else
            {
                menu_choice = stoi(menu_choice_string);
            }
        }
        if (menu_choice == 1)
        {
            move(people, map, PLAYER_ARR_SIZE, num_moves, anger_level, is_sorcerer_defeated);
            if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())) // check and display NPC menu
            {
                int result = displayNPCMenu(npcs, people, map, PLAYER_ARR_SIZE, num_moves, anger_level,
                                            items, num_cleared_rooms, num_items_purchased, num_items_sold, num_correct_riddles, monsters, is_sorcerer_defeated, num_monsters_defeated);
                if (result == 3)
                {
                    displayExitMenu(score, num_monsters_defeated, is_sorcerer_defeated, map, people, PLAYER_ARR_SIZE, num_moves, anger_level);
                    return 0;
                }
            }
            else if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol())) // check and display Room menu
            {
                int result = displayRoomMenu(npcs, people, map, PLAYER_ARR_SIZE, num_moves, anger_level, items,
                                             num_cleared_rooms, num_items_purchased, num_items_sold, num_correct_riddles, monsters, is_sorcerer_defeated, num_monsters_defeated);
                if (result == 3)
                {
                    displayExitMenu(score, num_monsters_defeated, is_sorcerer_defeated, map, people, PLAYER_ARR_SIZE, num_moves, anger_level);
                    return 0;
                }
            }
            else if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol())) // check and display Dungeon Exit menu
            {
                if (is_sorcerer_defeated)
                {
                    if (displayExitMenu(score, num_monsters_defeated, is_sorcerer_defeated, map, people, PLAYER_ARR_SIZE, num_moves, anger_level) == 2)
                    {
                        return 0;
                    }
                }
                else
                {
                    int result = displayRoomMenu(npcs, people, map, PLAYER_ARR_SIZE, num_moves, anger_level, items,
                                                 num_cleared_rooms, num_items_purchased, num_items_sold, num_correct_riddles, monsters, is_sorcerer_defeated, num_monsters_defeated);
                    if (result == 3)
                    {
                        displayExitMenu(score, num_monsters_defeated, is_sorcerer_defeated, map, people, PLAYER_ARR_SIZE, num_moves, anger_level);
                        return 0;
                    }
                }
            }

            for (int i = 0; i < PLAYER_ARR_SIZE; i++) // check if player is dead based on hunger - ENDS THE GAME
            {
                if (people[i].getHunger() == 0 && people[i].getDeath() == false)
                {
                    people[i].setDeath(true);
                    cout << red << people[i].getName() << " has died of hunger!" << white << endl;
                    if (people[0].getDeath() == true)
                    {
                        displayExitMenu(score, num_monsters_defeated, is_sorcerer_defeated, map, people, PLAYER_ARR_SIZE, num_moves, anger_level);
                        return 0;
                    }
                }
            }
            if (anger_level >= 100) // check if the anger level has reached the threshold - ENDS THE GAME
            {
                displayExitMenu(score, num_monsters_defeated, is_sorcerer_defeated, map, people, PLAYER_ARR_SIZE, num_moves, anger_level);
                return 0;
            }
            menu_choice = 0;
        }
        if (menu_choice == 2)
        {
            for (int i = 0; i < PLAYER_ARR_SIZE; i++) // check if player is dead based on hunger
            {
                if (people[i].getHunger() == 0 && people[i].getDeath() == false)
                {
                    people[i].setDeath(true);
                    cout << red << people[i].getName() << " has died of hunger!" << white << endl;
                    if (people[0].getDeath() == true)
                    {
                        displayExitMenu(score, num_monsters_defeated, is_sorcerer_defeated, map, people, PLAYER_ARR_SIZE, num_moves, anger_level);
                        return 0;
                    }
                }
            }
            int chance = generateRandomInteger(1, 10);
            if (chance == 1)
            {
                cout << green << "You found a key!" << white << endl;
                items.at(getIndexOfKey(items)).setAmount(items.at(getIndexOfKey(items)).getAmount() + 1);
                reduceHunger(people, PLAYER_ARR_SIZE);
                decideRandomMisfortune(people, PLAYER_ARR_SIZE, items, map, 4);
            }
            else if (chance > 1 && chance <= 3)
            {
                if (num_cleared_rooms == 0)
                {
                    cout << green << "You found a Silver Ring!" << white << endl;
                    items.at(getIndexOfRing(items)).setAmount(items.at(getIndexOfRing(items)).getAmount() + 1);
                    decideRandomMisfortune(people, PLAYER_ARR_SIZE, items, map, 4);
                }
                else if (num_cleared_rooms == 1)
                {
                    cout << green << "You found a Ruby Necklace!" << white << endl;
                    items.at(getIndexOfNecklace(items)).setAmount(items.at(getIndexOfNecklace(items)).getAmount() + 1);
                    decideRandomMisfortune(people, PLAYER_ARR_SIZE, items, map, 4);
                }
                else if (num_cleared_rooms == 2)
                {
                    cout << green << "You found an Emerald Bracelet!" << white << endl;
                    items.at(getIndexOfBracelet(items)).setAmount(items.at(getIndexOfBracelet(items)).getAmount() + 1);
                    decideRandomMisfortune(people, PLAYER_ARR_SIZE, items, map, 4);
                }
                else if (num_cleared_rooms == 3)
                {
                    cout << green << "You found a Diamond Circlet!" << white << endl;
                    items.at(getIndexOfCirclet(items)).setAmount(items.at(getIndexOfCirclet(items)).getAmount() + 1);
                    decideRandomMisfortune(people, PLAYER_ARR_SIZE, items, map, 4);
                }
                else if (num_cleared_rooms >= 4)
                {
                    cout << green << "You found a Gem-encrusted goblet!" << white << endl;
                    items.at(getIndexOfGoblet(items)).setAmount(items.at(getIndexOfGoblet(items)).getAmount() + 1);
                    decideRandomMisfortune(people, PLAYER_ARR_SIZE, items, map, 4);
                }
                reduceHunger(people, PLAYER_ARR_SIZE);
            }
            else if (chance > 3 && chance <= 6)
            {
                fightMonster(items, monsters, people, map, PLAYER_ARR_SIZE, num_cleared_rooms, 1, num_monsters_defeated);
            }
            else
            {
                cout << "Nothing found!" << endl;
                decideRandomMisfortune(people, PLAYER_ARR_SIZE, items, map, 4);
            }
            map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
            menu_choice = 0;
        }
        if (menu_choice == 3)
        {
            for (int i = 0; i < PLAYER_ARR_SIZE; i++) // check if player is dead based on hunger
            {
                if (people[i].getHunger() == 0 && people[i].getDeath() == false)
                {
                    people[i].setDeath(true);
                    cout << red << people[i].getName() << " has died of hunger!" << white << endl;
                    if (people[0].getDeath() == true)
                    {
                        displayExitMenu(score, num_monsters_defeated, is_sorcerer_defeated, map, people, PLAYER_ARR_SIZE, num_moves, anger_level);
                        return 0;
                    }
                }
            }
            fightMonster(items, monsters, people, map, PLAYER_ARR_SIZE, num_cleared_rooms, 1, num_monsters_defeated);
            menu_choice = 0;
        }
        if (menu_choice == 4)
        {
            for (int i = 0; i < PLAYER_ARR_SIZE; i++) // check if player is dead based on hunger
            {
                if (people[i].getHunger() == 0 && people[i].getDeath() == false)
                {
                    people[i].setDeath(true);
                    cout << red << people[i].getName() << " has died of hunger!" << white << endl;
                    if (people[0].getDeath() == true)
                    {
                        displayExitMenu(score, num_monsters_defeated, is_sorcerer_defeated, map, people, PLAYER_ARR_SIZE, num_moves, anger_level);
                        return 0;
                    }
                }
            }
            displayCookingMenu(people, PLAYER_ARR_SIZE, items);
            menu_choice = 0;
        }
        if (menu_choice == 5)
        {
            displayExitMenu(score, num_monsters_defeated, is_sorcerer_defeated, map, people, PLAYER_ARR_SIZE, num_moves, anger_level);
            return 0;
            // run endgame stats
        }
    } while (menu_choice == 0);

    // **************************************************************************** //
    // PHASE 3
    /*
    1. make phase three its own function
    2. state the reason for the end of game
    3. use a conditional to display an end of game congratulatory or game over message,
    along with reasoning as to why the game was won or lost
    4. print end of game statistics described in the github.
    */
    return 0;
}