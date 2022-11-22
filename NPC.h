#ifndef NPC_H
#define NPC_H
#include <iostream>
using namespace std;

class NPC
{
public:
    // constructor
    NPC();
    NPC(string riddle, string answer);
    // getter functions
    bool getCleared() const;
    string getRiddle() const;
    string getAnswer() const;

    // setter functions
    void setCleared(bool clear);
    void setRiddle(string riddle);
    void setAnswer(string answer);

private:
    bool clear_;
    string riddle_;
    string answer_;
};
#endif