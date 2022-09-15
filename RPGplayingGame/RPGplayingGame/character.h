#pragma once
#include <iostream>
#include <string>
using namespace std;

//character base class header file: 
//enemy and player classes will inherit from character class

class character {
public:
    string name;
    string description;
    int damage;
    int totalHealth;
    int currentHealth;
    //constructors:
    character(); //default
    character(string enteredName, string enteredDescription); //overloaded constructor
    void describe();

    //virtual function: one that other classes can change how its implemented
    //=0 makes it an abstract class (aka pure virtual function)
    //abstract functions arent implemented into the base class, but enemy / player classes will
    virtual void fight(character* other) = 0; 

    virtual bool isAlive() = 0;
    virtual void setStats(int level) = 0;
};
