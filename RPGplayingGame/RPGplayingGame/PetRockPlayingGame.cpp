// RPGplayingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 
#include <thread> 
#include <chrono> 

#include "player.h"
#include "enemy.h"

using namespace std;

void delayScroll(int delayMS, int lineCount);
character* generateEnemy();
void encounterEnemy(character* player, character* enemy);
void fightDecisions(character* player);

void delayScroll(int delayMS, int lineCount)

{
    for (int i = 0; i < lineCount; i++)
    {
        cout << "" << endl;
        this_thread::sleep_for(chrono::milliseconds(delayMS));
    }
}
character* generateEnemy()
{
    character* e = new enemy("Umbrella", "A household object that keeps you dry in the rain.");
    e->setStats(1);
    return e;
}
void encounterEnemy(character* player, character* enemy)
{
    while (player->isAlive() && enemy->isAlive())
    {
        player->fight(enemy);
        enemy->fight(player);
        delayScroll(10, 1);
    }
    fightDecisions(player);
}
void fightDecisions(character* player)
{
    if (player->isAlive())
    {
        character* anEnemy = generateEnemy();
        int option = 0;
        cout << "You encounter " << anEnemy->name << endl;
        cout << "1. Encounter" << endl;
        cout << "2. Run" << endl;
        cout << ">";
        cin >> option;
        if (option == 1)
            encounterEnemy(player, anEnemy);
        else
            cout << "You run away, the game ends." << endl;

    }
    else
    {
        cout << "You lose! Hope you enjoyed!" << endl;
    }
}
int main()
{
    srand(time(NULL));
    string intro =

        "          _____          \n"
        "      __ /__    \\__     \n"
        "   _ /      \\    __\\   \n"
        "  /          \\__ /  \\  \n"
        " |   O          O    |    \n"
        " |      ______      /    \n"
        "  \\     \\____/     /   \n"
        "   \\______________/     \n"

        "  PET ROCK ADVENTURE";

    cout << intro << endl;

    string playerName;

    cout << "What is your rock's name?" << endl;
    cout << "> ";
    cin >> playerName;
    cout << "Excellent! Let's get started with " << playerName << "'s Adventure!" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    delayScroll(10, 30);
    cout << "...to be continued..." << endl;
    character* petRock = new player(playerName, "Just a regular rock.");
    petRock->setStats(4);

    fightDecisions(petRock);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
