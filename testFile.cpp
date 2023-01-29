#include <iostream>
#include <vector>
#include "Result.h"
#include "Player.h"
using namespace std;
int main()
{
    vector<int> elements;
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    elements.push_back(6);

    for (int i = 0; i < elements.size(); i++)
    {
        cout << elements.at(i) << ", ";
    }
    cout << endl;

    elements.erase(elements.begin() + 2);

    for (int i = 0; i < elements.size(); i++)
    {
        cout << elements.at(i) << ", ";
    }
    cout << endl;

    Player people[5];
    for (int i = 0; i < 5; i++)
    {
        people[i].setName("name");
    }

    int score = 600;
    string name = "Jake";
    int anger_level = 42;
    Result res(name, score, people, anger_level);
    cout << res.getScore() << " " << res.getName() << " " << endl;
    cout << "Party:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "  " << res.getPartyName(i) << endl;
    }

    return 0;
}