#include "Player.h"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

// BASIC FUNTIONS (Display Merchant Menu, Display map, Dispaly status, Split, Read Monster,
//                 Read Riddle, Append Results file, Append Leaderboard file, display riddle,
//                 display endgame results, fight monster, decide random misfortune)

// displays a list of items that can be purchased.
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

void displayInventory(vector<Item> items)
{
    cout << "  *INVENTORY* " << endl;
    cout << "+-------------+ " << endl;
    cout << "| Gold        | " << items.at(getIndexOfGold(items)).getNum() << endl;
    cout << "| Ingredents  | " << items.at(getIndexOfIngredients(items)).getAmount() << endl;
    cout << "| Cookware    | "
         << "Pot: " << items.at(getIndexOfPot(items)).getAmount() << ", Pan: "
         << items.at(getIndexOfPan(items)).getAmount() << ", Cauldron: "
         << items.at(getIndexOfPan(items)).getAmount() << endl;

    cout << "| Weapons     | "
         << "Club: " << items.at(getIndexOfClub(items)).getAmount() << ", Spear: "
         << items.at(getIndexOfSpear(items)).getAmount() << ", Rapier: "
         << items.at(getIndexOfRapier(items)).getAmount() << ", Rapier: "
         << items.at(getIndexOfAxe(items)).getAmount() << ", Longsword: "
         << items.at(getIndexOfLongsword(items)).getAmount() << endl;
    cout << "| Armour      | " << items.at(getIndexOfArmour(items)).getAmount() << endl;
    cout << "| Treasures   | "
         << "Silver ring: " << items.at(getIndexOfRing(items)).getAmount() << ", Ruby necklace: "
         << items.at(getIndexOfNecklace(items)).getAmount() << ", Emerald bracelet: "
         << items.at(getIndexOfBracelet(items)).getAmount() << ", Diamond circlet: "
         << items.at(getIndexOfCirclet(items)).getAmount() << ", Gem-encrusted goblet: "
         << items.at(getIndexOfGoblet(items)).getAmount() << endl;
    cout << "+-------------+ " << endl;
}

void displayMerchantMenu(vector<Item> &items, int num_rooms_cleared)
{
    cout << "If you're looking for supplies, you've come to the right place.";
    cout << "\nI can sell you anything you might need for your journey, for the right price!\n"
         << endl;
    int menu_choice;
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
        cin >> menu_choice;
        if (menu_choice == 1)
        {
            cout << "I have a several types of cookware, which one would you like?\n"
                 << "Each type has a different probability of breaking when used, marked with(XX %)." << endl;
            double pot_rate = 2 + (2 * .25 * num_rooms_cleared);
            double pan_rate = 10 + (10 * .25 * num_rooms_cleared);
            double cauldron_rate = 20 + (20 * .25 * num_rooms_cleared);
            int internal_choice;
            do
            {
                cout << "Choose one of the following:\n"
                     << "1. (25%) Ceramic Pot [" << pot_rate << "]\n"
                     << "2. (10%) Frying Pan [" << pan_rate << "]\n"
                     << "3. ( 2%) Cauldron [" << pan_rate << "]\n"
                     << "4. Cancel\n"
                     << endl;
                cin >> internal_choice;
                if (internal_choice == 1)
                {
                    int amount;
                    char confirmation;
                    int currency_update = getIndexOfGold(items);
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> amount;
                    // ADD CHECK TO SEE IF THE USER CAN AFFORD IT. GOLD SHOULD NOT GO BELOW ZERO.
                    if (items.at(currency_update).getNum() < (pot_rate * amount))
                    {
                        cout << "You can't afford this! You are " << (pot_rate * amount) - items.at(currency_update).getNum() << " units of gold short." << endl;
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
                        cout << "Thank you for your patronage! What else can I get for you?\n"
                             << endl;
                        int update_value = getIndexOfPot(items);
                        items.at(update_value).setAmount(amount + items.at(update_value).getAmount());
                        items.at(currency_update).setNum(items.at(currency_update).getNum() - (pot_rate * amount));

                        internal_choice = 4;
                    }
                }
                else if (internal_choice == 2)
                {
                }
                else if (internal_choice == 3)
                {
                }
            } while (internal_choice != 4);
            menu_choice = 0;
        }
        else if (menu_choice == 2)
        {
        }
        else if (menu_choice == 3)
        {
        }
        else if (menu_choice == 4)
        {
        }
        else if (menu_choice == 5)
        {
        }
    } while (menu_choice != 6);
}

// display the current poision of the player and postion of rooms and discovered NPC's using the map class
// to be called every time an action is made in main().
void displayMap()
{
}

// display the hunger and armour capabilities of each party member
// to be called every time an action is made in main().
void displayStatus()
{
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

// utilize fstream object to write results of the game, plus the date.
int appendResultsFile(string filename, string leader, int numRooms, int goldPiecesRemaining,
                      vector<Item> treasure, int exploredspaces, int defeatedMonsters, int numTurns, string date)
{
}

// collect all infromation based on the turns, the leader name, gold pieces and such to be displayed at the end of the game.
void displayEndgameResults(string leader, int numRooms, int goldPiecesRemaining, vector<Item> treasure,
                           int exploredspaces, int defeatedMonsters, int numTurns)
{
}

// based on an equation given in the github, determine if fighting a monster leads to victory or defeat.
// if defeat, update stats in each of the player objects, and reduce the treasure in the items vector.
// use rand() to calculate if the monster drops a key if it is defeated.
double fightMonster(vector<Item> weapons, vector<Monster> monsters)
{
}

// utilize the rand function to decide if a misfortune happens, and what that is. Use ints to correspond to a misfortune type
int decideRandomMisfortune()
{
}

// need to utilize a sotrting method and a score calculator to append to the leaderboard and sort the file.
int appendLeaderboard(string resultsfile, string leaderboardfile)
{
}

// to be altered as the program progresses, for now just assert that the vectors of objects is instanciated correctly.
int tester(vector<Player> people, vector<Monster> monsters, vector<NPC> npcs, vector<Item> items)
{
    cout << "////// TESTER FUNCTION //////" << endl;

    cout << "The following numbers should be completely random between 1 and 100: ";
    int max = 100;
    int min = 1;
    for (int i = 0; i < 5; i++)
    {
        cout << rand() % (max - min + 1) + min << ", ";
    }
    cout << endl;

    assert(people.size() == 5);
    cout << "Party members: ";
    for (int i = 0; i < people.size(); i++)
    {
        cout << people.at(i).getName() << ", " << people.at(i).getHunger() << "; ";
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

    cout << "////// END TESTER FUNCTION //////" << endl;
}

// ****** MAIN FUNCTION ****** //

int main()
{
    // inventory stuff:
    // gold type = currency
    // ingredients type = food
    // cookware type = cookware
    // weapons type = weapon
    // armour type = armour
    // treasure type = treasure

    // initial object creaton
    vector<Player> people;
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

    // seed the rand() function
    srand(time(0));
    // useful variables
    int num_cleared_rooms = 1;
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
        people.push_back(person);
    }

    // create monsters vector
    int monster_result = readMonsterFile(monsters_file, monsters);
    assert(monster_result == 21);

    // create NPC vector
    int npc_result = readRiddleFile(riddles_file, npcs);
    assert(npc_result == 20);
    displayMerchantMenu(items, num_cleared_rooms);

    tester(people, monsters, npcs, items);
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
    2. open the door (PLAYER MUST HAVE A KEY)
    3. give up
    */
    // note: player needs to have keys to open the door. They can get them by pissing off an NPC, or simply picking a fight.

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