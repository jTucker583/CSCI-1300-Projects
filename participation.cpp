#include <iostream>
using namespace std;

int main()
{
    bool wear_jacket;
    bool wear_pants;
    bool wear_boots;

    int temperature;
    bool is_raining;
    bool is_snowing;
    cout << "Enter the temperature" << endl;
    cin >> temperature;
    cout << "Is it raining? 1 for yes, 0 for no" << endl;
    cin >> is_raining;
    cout << "Is it snowing? 1 for yes, 0 for no" << endl;
    cin >> is_snowing;
    if (temperature < 60)
    {
        wear_jacket = true;
    }
    if (temperature < 45)
    {
        wear_pants = true;
    }
    if (is_raining)
    {
        wear_jacket = true;
    }
    if (is_snowing)
    {
        wear_boots = true;
    }
    return 0;
}