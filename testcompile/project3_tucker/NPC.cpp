#include "NPC.h"
#include <iostream>
using namespace std;

NPC::NPC()
{
    clear_ = false;
    riddle_ = "";
    answer_ = "";
}
NPC::NPC(string riddle, string answer)
{
    clear_ = false;
    riddle_ = riddle;
    answer_ = answer;
}

bool NPC::getCleared() const
{
    return clear_;
}

string NPC::getRiddle() const
{
    return riddle_;
}

string NPC::getAnswer() const
{
    return answer_;
}

void NPC::setCleared(bool clear)
{
    clear_ = clear;
}

void NPC::setRiddle(string riddle)
{
    riddle_ = riddle;
}

void NPC::setAnswer(string answer)
{
    answer_ = answer;
}

// should be an array of NPC's which have a random prompt that can be chosen from an array. Array will be 2D, with columns being riddle and answer respectively.
// NPC will be in a vector of NPC's, each being removed every time the user anwers the riddle.