#pragma once
#include "character.h"

using namespace std;

class player : public character {
public:
    player(string enteredName, string enteredDescription, string enteredAlignment) : character(enteredName, enteredDescription, enteredAlignment) {};
    void fight(character* other);
    bool isAlive();
    void setStats(int level);
    void displayStats();

};