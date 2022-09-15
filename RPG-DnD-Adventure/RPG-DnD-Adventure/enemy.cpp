#include "enemy.h"

using namespace std;

void enemy::fight(character* other)
{   
    random_device rd;
    uniform_int_distribution<int> d6(1, 6);
    actionOption = 0;
    bool isHostile = false;
    bool isKilled = false;
    actionOption = other -> actionOption;

    if (actionOption == 1) {
        isHostile = true;
    }
    else {
        isHostile = false;
    }
    if (isHostile == true) {
        //enemy fights player
        if (weapon == "") {
            damage = unarmedDamage + damageBonus;
        }
        else {
            int damageRoll = d6(rd);
            if (weapon == "sword") {
                damage = 1 + damageRoll % 3 + damageBonus;
            }
            else if (weapon == "spear") {
                damage = 1 + damageRoll % 4 + damageBonus;
            }
            else if (weapon == "battleaxe") {
                damage = 1 + damageRoll % 5 + damageBonus;
            }
            else if (weapon == "warhammer") {
                damage = 2 + damageRoll % 6 + damageBonus;
            }
            else if (weapon == "magic sword") {
                damage = 2 * (1 + damageRoll % 6) + damageBonus;
            }
        }
        if (weapon == "") {
            cout << name << " attacks!" << endl;
        }
        else {
            cout << name << " attacks using a " << weapon << "!" << endl;
        }
        int attackRoll = (2 * d6(rd) - 2) + attackBonus;
        if (attackRoll >= other->armourClass) {
            other->currentHealth -= damage;
            cout << name << " hit " << other->name << " for " << damage << " damage." << endl;
        }
        else {
            other->currentHealth -= 0;
            cout << name << " missed " << other->name << " and dealt no damage." << endl;
        }
        
        cout << other->name << " is at " << other->currentHealth << " out of " << other->totalHealth << " health." << endl;
        if (currentHealth <= 0) {
            isKilled = true;
        }
    }
    else if (isHostile == false) {}//do nothing
    if (isKilled) {
        int input;
        currentHealth = 0;
        cout << name << " was slain by " << other->name << "!" << endl;
        other->experience += d6(rd) * 10 + 40;
        cout << "Does " << other->name << " wish to loot the " << name << "'s dead body?" << endl;
        cout << "1. yes" << endl;
        cout << "2. no" << endl;
        cout << "> ";
        cin >> input;
        if (input == 1) {
            if (coins != 0 || weapon != "") {
                bool coinLootExists = false, weaponLootExists = false;
                if (coins > 0) { //if there are coins 
                    coinLootExists = true;
                }
                if (weapon != "") { //if weapon exists
                    weaponLootExists = true;
                } 
                if (coinLootExists && weaponLootExists) {
                    cout << other->name << " looted the " << name << "'s body and found " << coins << " coin(s) and a " << weapon << "!" << endl;
                    other->coins += coins;
                    cout << other->name << " currently has " << other->coins << " coin(s)." << endl;
                    if (other->weapon != "" && other->weapon != weapon) {
                        cout << "Does " << other->name << " wish to replace their " << other->weapon << " with the "<< name << "'s " << weapon << "?" << endl;
                        cout << "1. yes" << endl;
                        cout << "2. no" << endl;
                        cout << "> ";
                        int decision;
                        cin >> decision;
                        cout << "" << endl;
                        if (decision == 1) {
                            cout << other->name << " replaced " << other->weapon << " with " << weapon << "." << endl;
                            other->weapon = weapon;
                        }
                        else {
                            cout << other->name << " kept their " << other->weapon << " and left the dead body's " << weapon << " where it was." << endl;
                        }
                    }
                    else if (other->weapon != "" && other->weapon == weapon){
                        cout << "Does " << other->name << " wish to replace their " << other->weapon << " with the " << name << "'s " << weapon << "?" << endl;
                        cout << "1. yes" << endl;
                        cout << "2. no" << endl;
                        cout << "> ";
                        int decision;
                        cin >> decision;
                        cout << "" << endl;
                        if (decision == 1) {
                            cout << other->name << " replaced " << other->weapon << " with a new " << weapon << "." << endl;
                            other->weapon = weapon;

                        }
                        else {
                            cout << other->name << " kept their " << other->weapon << " and left the dead body's " << weapon << " where it was." << endl;
                        }
                    }
                    else {
                        cout << other->name << " looted the " << weapon << " from the "<< name << "." << endl;
                        other->weapon = weapon;
                    }
                }
                else if (coinLootExists && !weaponLootExists) {
                    cout << other->name << "looted the " << name << "'s body and found " << coins << " coin(s)!" << endl;
                    other->coins += coins;
                    cout << other->name << " currently has " << other->coins << " coin(s)." << endl;
                }
                else if (!coinLootExists && weaponLootExists) {
                    cout << other->name << " looted the " << name << "'s body and found a " << weapon << "!" << endl;
                    if (other->weapon != "" && other->weapon != weapon) {
                        cout << "Does " << other->name << " wish to replace their " << other->weapon << " with the " << name << "'s " << weapon << "?" << endl;
                        cout << "1. yes" << endl;
                        cout << "2. no" << endl;
                        cout << "> ";
                        int decision;
                        cin >> decision;
                        cout << "" << endl;
                        if (decision == 1) {
                            cout << other->name << " replaced " << other->weapon << " with " << weapon << "." << endl;
                            other->weapon = weapon;
                        }
                        else {
                            cout << other->name << " kept their " << other->weapon << " and left the dead body's " << weapon << " where it was." << endl;
                        }
                    }
                    else if (other->weapon != "" && other->weapon == weapon) {
                        cout << "Does " << other->name << " wish to replace their " << other->weapon << " with the " << name << "'s " << weapon << "?" << endl;
                        cout << "1. yes" << endl;
                        cout << "2. no" << endl;
                        cout << "> ";
                        int decision;
                        cin >> decision;
                        cout << "" << endl;
                        if (decision == 1) {
                            cout << other->name << " replaced their " << other->weapon << " with a new " << weapon << "." << endl;
                            other->weapon = weapon;

                        }
                        else {
                            cout << other->name << " kept their " << other->weapon << " and left the dead body's " << weapon << " where it was." << endl;
                        }
                    }
                    else {
                        cout << other->name << " looted the " << weapon << " from the " << name << "." << endl;
                        other->weapon = weapon;
                    }
                }
            }
            else {
                //no coins
                cout << other->name << " looted the " << name << "'s body but found no loot." << endl;
            }
        }
        else {

        }

    }
}
void enemy::setStats(int level)
{   
    random_device rd;
    uniform_int_distribution<int> d6(1, 6);
    int baseStat = 2 * level;
    int x = rand() % baseStat + 1;

    damage = (int)(x / 2);

    if (damage < 1)
        damage = 1;
    unarmedDamage = damage;
    damageBonus = unarmedDamage + level;
    attackBonus = level;

    attackBonus = level;

    armourClass = x + 4 + level;

    currentHealth = totalHealth = x * 2;
    if (d6(rd) > 3) {
        coins = x * 3 + level;
    }
    else {
        coins = 0;
    }
    if (alignment != "Good") {
        int Roll = d6(rd);
        int tier = d6(rd) % 3 + 1;
        if (alignment == "Evil" ) {
            if (tier != 3 && Roll != 6) {
                if (tier >= 2) {
                    tier = 1;
                }
            }
            else {
                tier = 3;
                Roll = 6;
            }
        }
        else if (alignment == "Neutral") {
            tier--;
        }
        if (Roll == 1 || Roll == 2) {
            weapon = "sword"; //other weapons can be sword, magic sword, battleaxe, warhammer, spear
        }
        else if (Roll == 3) {
            weapon = "spear";
        }
        else if (Roll == 4) {
            if (tier >= 2) {
                weapon = "battleaxe";
            }
            else {
                weapon = "spear";
            }
        }
        else if (Roll == 5) {
            if (tier == 3) {
                weapon = "warhammer";
            }
            else if (tier == 2) {
                weapon = "battleaxe";
            }
            else {
                weapon = "spear";
            }
        }
        else if (Roll == 6) {
            if (tier == 3) {
                weapon = "magic sword";
            }
            else if (tier == 2) {
                weapon = "warhammer";
            }
            else {
                weapon = "battleaxe";
            }
        }
    }
    else {
        weapon = "";
    }

    hasTraded = false;

    characterLevel = level;
    displayStats();
}
void enemy::displayStats()
{
    cout << "" << endl;
    cout << "Enemy Stats:" << endl;
    cout << "-------------" << endl;
    cout << "level: " << characterLevel << endl;
    cout << "health: " << currentHealth << " / " << totalHealth << endl;
    cout << "weapon: " << weapon << endl;
    cout << "coins: " << coins << endl;
    //cout << "damage:" << damage << endl;
    cout << "unarmed damage: " << unarmedDamage << endl;
    cout << "ac: " << armourClass << endl;
    cout << "damage bonus: " << damageBonus << endl;
    cout << "attack bonus: " << attackBonus << endl;
    cout << "exp: " << experience << endl;
    cout << "-------------" << endl;
    cout << "" << endl;
}
bool enemy::isAlive()
{
    if (currentHealth > 0)
        return true;
    else
        return false;
}