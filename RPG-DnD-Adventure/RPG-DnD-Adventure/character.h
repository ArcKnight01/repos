#pragma once
#include <iostream>
#include <string>
#include <random>

using namespace std;

//character base class header file: 
//enemy and player classes will inherit from character class

class character {

public:

    string name;
    string description;
    string alignment; //good, neutral, evil
    int coins = 0; //player should start with zero coins
    int actionOption;

    string weapon = "";
    int healthPotionsAmount = 0;
    bool hasTraded;

    int damage;
    int unarmedDamage;
    int damageBonus;
    int attackBonus;
   
    int armourClass;
    int totalHealth;
    int currentHealth;

    int experience = 0;
    int characterLevel;
    int levelingGoal = 500;
    //constructors:
    character(); //default
    character(string enteredName, string enteredDescription, string enteredAlignment); //overloaded constructor
    void describe();
    

    //virtual function: one that other classes can change how its implemented
    //=0 makes it an abstract class (aka pure virtual function)
    //abstract functions arent implemented into the base class, but enemy / player classes will
    virtual void fight(character* other) = 0;

    virtual bool isAlive() = 0;
    virtual void setStats(int level) = 0;
    virtual void displayStats() = 0;
};

