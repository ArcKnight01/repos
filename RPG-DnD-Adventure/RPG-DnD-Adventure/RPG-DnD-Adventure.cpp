// RPG-DnD-Adventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string> 
#include <thread> 
#include <chrono> 
#include <random>

#include "player.h"
#include "enemy.h"

using namespace std;


void delayScroll(int delayMS, int lineCount);
character* generateEnemy(character* player);
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
character* generateEnemy(character* player)
{
    random_device rd;
    uniform_int_distribution<int> d6(1, 6);
    uniform_int_distribution<int> randomLevel(1, (player->characterLevel - 1));

    character* e;

    int chance = d6(rd);

    if (chance == 1) {
        e = new enemy("Halfling", "short good humanoid creature", "Good");
    }
    else if (chance == 2 || chance == 3) {
        e = new enemy("Dwarf", "short bearded humanoid creature", "Neutral");
    }
    else {
        e = new enemy("Goblin", "small evil humanoid creature", "Evil");
    }

    if (player->weapon == "" && player->experience == 0) {
        //player is unarmed, and at starting level, so to make it easier only spawn level 1 enemies...
        e->setStats(1);
    }
    else {
        e->setStats(randomLevel(rd));
    }
    
    return e;
}
void encounterEnemy(character* player, character* enemy)
{
    while (player->isAlive() && enemy->isAlive())
    {
        //loop while enemy is alive
        player->fight(enemy);
        enemy->fight(player);
        delayScroll(10, 1);
    }
    if (player->experience >= player->levelingGoal) {
        int playerLevel = player->characterLevel;
        cout << player->name << " leveled up from " << playerLevel << " to " << (playerLevel + 1) << endl;
        playerLevel++;
        player->setStats(playerLevel);
        player->levelingGoal = player->levelingGoal + 500 * (playerLevel - 4);
        cout << player->name << " can level up from " << playerLevel << " to " << (playerLevel + 1) << " when " << player->levelingGoal << " experience is gained." << endl;
        //player->experience = 0;
        cout << player->name << " was restored to full health while leveling up!" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
    }
    this_thread::sleep_for(chrono::milliseconds(500));
    delayScroll(10, 30);
    fightDecisions(player);
}
void fightDecisions(character* player)
{   
    //random_device rd;
    //uniform_int_distribution<int> d6(1, 6);
    if (player->isAlive())
    {
        character* anEnemy = generateEnemy(player);
        int option = 0;
        cout << "You encounter a " << anEnemy->name << endl;
        anEnemy->describe();

        cout << "1. Encounter" << endl;
        cout << "2. Run (quit game)" << endl;
        cout << "3. View player's stats" << endl;
        cout << "> ";
        
        cin >> option;
        cout << "" << endl;
        if (option == 1) {
            encounterEnemy(player, anEnemy);
            cout << "" << endl;
        }
        else if (option == 3) {
            player->displayStats();
            cout << "1. Encounter" << endl;
            cout << "2. Run (quit game)" << endl;
            cout << "> ";

            cin >> option;
            cout << "" << endl;
            if (option == 1) {
                encounterEnemy(player, anEnemy);
                cout << "" << endl;
            }
            else{
                cout << "You run away, the game ends." << endl;
                cout << "You got a total of " << player->experience << " experience points." << endl;
            }
        }
        else {
            cout << "You run away, the game ends." << endl;
            cout << "You got a total of " << player->experience << " experience points." << endl;
        }
    }
    else
    {
        cout << "You lose! Hope you enjoyed!" << endl;
        cout << "You got a total of " << player->experience << " experience points." << endl;
    }
    
}
int main()
{
    srand(time(NULL));
    //random_device rd;
    //uniform_int_distribution<int> d6(1, 6);

    string intro =

"..............................\n"
"......%@@@@@@@................\n"
".....@@@&...@@@@..............\n"
"....*&@@..%.@@@@..............\n"
"....%@@@.@@.@&@...............\n"
" ..,@@@@@*@@(&@.....,@@@@@@@@.\n"
"   @.%@.@@@..@@@@..@@.........\n"
" #@@@@@@..@&.@@..@@...........\n"
"..@@@@@.......%@@@@......#....\n"
"..@@@@@&.....@@@@&@@@@@@..@@&.\n"
"..&@@@@@@@@@@@@@..@@@@@@@@@@..\n"
"  ....@@@@@@&......#.@@@@@@...\n"
"        A D&D ADVENTURE         ";

       

    cout << intro << endl;

    string playerName;
    //string playerStr;
    //int numb = 0;
    //int imax = 10, jmax = 10;
    /*for (int i = 0; i < imax; i++) {
        for (int j = 0; j < jmax; j++) {
            cout << i << " " << j << " / " << numb << endl;
            numb++;
            //cout << " " << (jmax) * (i) + j << endl;
        }
    }*/
    cout << "What is your adventurer's name?" << endl;
    cout << "> ";
    //cin >> playerName;
    getline(cin, playerName);
    cout << "Excellent! Let's begin " << playerName << "'s Adventure!" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
   
    delayScroll(10, 30);

    cout << "...to be continued..." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    delayScroll(10, 30);
    cout << "Create your adventurer:" << endl;
    //cout << "STR:" << endl;
    string adventurerDescription = "an average adventurer";
    cout << "how would you describe your adventurer?" << endl;
    cout << playerName << " is a(n) ";
    getline(cin, adventurerDescription);
    adventurerDescription = "a(n) " + adventurerDescription + ".";
    character* adventurer = new player(playerName, adventurerDescription, "Good");
    cout << "Nice! " << playerName << " is described as " << adventurerDescription << endl;

    int startLevel = 4;
    adventurer->setStats(startLevel);
    this_thread::sleep_for(chrono::milliseconds(5000));
    //this_thread::sleep_for(chrono::milliseconds(1000));

    delayScroll(10, 30);


    fightDecisions(adventurer);
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
