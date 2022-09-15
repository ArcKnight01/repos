#include "player.h"
using namespace std;

void player::fight(character* other)
{
	random_device rd;
	uniform_int_distribution<int> d6(1, 6);
	int option = 0;
	bool isFighting;

	cout << "1. fight" << endl;
	cout << "2. talk" << endl;
	cout << "3. walk away" << endl;
	if (healthPotionsAmount != 0 && currentHealth < totalHealth) {
		cout << "4. use health potion" << endl;
	}
	cout << ">";
	cin >> option;
	cout << "" << endl;

	if (other->actionOption == 1) { 
		isFighting = true;
	}
	else {
		isFighting = false;
	}
	actionOption = option;
	if (option == 4) {
		other->actionOption = 2;
	}
	else {
		other->actionOption = option; //if player fights enemy enemy also fights, otherwise doesnt at least immediately
	}

	hasTraded = other->hasTraded;

	//encounter options
	if (option == 1)
	{	
		//player chooses to fight
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
		other->actionOption = 1;
	}
	else if (option == 2) {
		cout << name << " speaks to the " << other -> name << endl;
		if (other->alignment == "Good") {
			cout << other->name << " pleasantly greets " << name << endl;
			if (other->hasTraded == false) {
				int chance = d6(rd);
				if (chance <= 2) {
					int amount = (d6(rd)) * 2;
					cout << other->name << " offers " << name << " " << amount << " coin(s)." << endl;
					coins += amount;
					cout << name << " currently has " << coins << " coin(s)." << endl;
					other->hasTraded = true;
				}
				else if (chance > 2 && chance <= 4) {
					int amount = (d6(rd)) * 2;
					cout << other->name << " offers " << name << " " << amount << " coin(s)." << endl;
					coins += amount;
					cout << name << " currently has " << coins << " coin(s)." << endl;
					other->hasTraded = true;

				}
				else if (chance > 4) {
					int weaponRoll = d6(rd);
					string weaponGiven;
					cout << other->name << " gifts " << name << " a weapon!" << endl;
					if (weaponRoll == 1 || weaponRoll == 2) {
						weaponGiven = "sword"; //other weapons can be sword, magic sword, battleaxe, warhammer, spear
					}
					else if (weaponRoll == 3) {
						weaponGiven = "spear";
					}
					else if (weaponRoll == 4) {
						weaponGiven = "battleaxe";
					}
					else if (weaponRoll == 5) {
						weaponGiven = "warhammer";
					}
					else if (weaponRoll == 6) {
						weaponGiven = "magic sword";
					}
					cout << name << " is given a " << weaponGiven << "." << endl;
					if (weapon != "" && weapon != weaponGiven) {
						//bool replaceWeapon = false;
						cout << "does " << name << " wish to replace their " << weapon << " with the " << weaponGiven << "?" << endl;
						cout << "1. yes" << endl;
						cout << "2. no" << endl;
						cout << "> ";
						int input;
						cin >> input;
						if (input == 1) {
							cout << name << " replaced " << weapon << " with " << weaponGiven << "." << endl;
							weapon = weaponGiven;

						}
						else {
							cout << name << " kept their " << weapon << " and returned the " << weaponGiven << "." << endl;

						}
						other->hasTraded = true;
					}
					else {
						weapon = weaponGiven;
						other->hasTraded = true;
					}
				}
			}
			else if (other->hasTraded == true) {
				cout << other->name << " has already given " << name << " a gift! But " << other-> name << " offers " << name << " good tidings on " << name<< "'s journey!" << endl;
			}
		}
		else if (other->alignment == "Neutral") {
			//chance of good trade
			int chance = d6(rd);
			//roll for which item
			int weaponRoll = d6(rd);
			//roll for amount of potion sold to trader or traded to player
			int potionRoll = d6(rd);
			//whether or not trader has potion
			bool hasPotion = (potionRoll >= 3)? true : false;
			//amount of potions requested or sold
			int potionRequest;
			//amount of money cost or sold for
			int amount;
			//tier
			int tier;

			string weaponGiven;

			//set amount of money for item to cost
			if (chance <= 2) {
				amount = (d6(rd)) * 1;
				tier = 1;
				potionRequest = 1;
			}
			else if(chance > 2 && chance <= 4){
				amount = (d6(rd)) * 2;
				tier = 2;
				potionRequest = 2;
			}
			else if (chance > 4) {
				amount = (d6(rd)) * 4;
				tier = 3;
				potionRequest = 2;
			}

			//determine which weapon traded:

			if (weaponRoll == 1 || weaponRoll == 2) {
				weaponGiven = "sword"; //other weapons can be sword, magic sword, battleaxe, warhammer, spear
			}
			else if (weaponRoll == 3) {  
				weaponGiven = "spear";
			}
			else if (weaponRoll == 4) {
				if (tier >= 2) {
					weaponGiven = "battleaxe";
				}
				else {
					weaponGiven = "spear";
				}
			}
			else if (weaponRoll == 5) {
				if (tier == 3) {
					weaponGiven = "warhammer";
				}
				else if (tier == 2){
					weaponGiven = "battleaxe";
				}
				else {
					weaponGiven = "spear";
				}
			}
			else if (weaponRoll == 6) {
				if (tier == 3) {
					weaponGiven = "magic sword";
				}
				else if (tier == 2) {
					weaponGiven = "warhammer";
				}
				else {
					weaponGiven = "battleaxe";
				}
			}

			//trading:
			if (other->hasTraded == false) {//if hasn't traded
				if (coins >= amount) {
					//npc can trade with player:
					cout << other->name << " offers to trade with " << name << endl;

					//player doesnt have weapon...
					if (weapon != "") {
						if (weapon != weaponGiven) {
							cout << "Does " << name << " wish to replace their " << weapon << " and buy a " << weaponGiven << "?" << endl;
						}
						else {
							cout << "Does " << name << " wish to buy a new " << weaponGiven << " for " << amount << " coin(s)?" << endl;
						}
						cout << "1. yes" << endl;
						cout << "2. no" << endl;
						cout << "> ";
						int input;
						cin >> input;
						if (input == 1) {
							cout << name << " bought " << weaponGiven << " for " << amount << " coins" << endl;
							cout << name << " replaced " << weapon << " with " << weaponGiven << "." << endl;
							weapon = weaponGiven;
							coins -= amount;
							cout << name << " currently has " << coins << " coin(s)." << endl;
							other->hasTraded = true;
						}
						else {
							cout << name << " chose not to buy the " << weaponGiven << "." << endl;
						}
					}
					if (hasPotion && !other->hasTraded && currentHealth < totalHealth) {
					//trader has potion	
					
					cout << "Does " << name << " wish to buy " << potionRequest << " health potions for " << amount << " coin(s)?" << endl;
					
					cout << "1. yes" << endl;
					cout << "2. no" << endl;
					cout << "> ";
					int input;
					cin >> input;
					if (input == 1) {
						cout << name << " bought " << potionRequest << " health potions " << " for " << amount << " coins" << endl;
						//cout << name << " replaced " << weapon << " with " << weaponGiven << "." << endl;
						//weapon = weaponGiven;
						healthPotionsAmount += potionRequest;
						coins -= amount;
						cout << name << " currently has " << coins << " coin(s)." << endl;
						hasPotion = false;
						other->hasTraded = true;
					}
					else {
						cout << name << " chose not to buy the " << potionRequest << " health potions" << "." << endl;
					}
					}
				}
				else if (coins < amount){
					//money is less than amount
					if (weapon != "") {
						//if player has a weapon to trade
						cout << other->name << " offers to trade with " << name << endl;
						cout << "does " << name << " wish to sell their " << weapon << " for " << amount << "coin(s)?" << endl;
						cout << "1. yes" << endl;
						cout << "2. no" << endl;
						cout << "> ";
						int input;
						cin >> input;
						if (input == 1) {
							//player agrees to sell
							cout << name << " sold " << weapon << " for " << amount << " coins" << endl;
							weapon = "";
							coins += amount;
							cout << name << " currently has " << coins << " coin(s)." << endl;
							other->hasTraded = true;
						}
						else {
							//does not agree to sell the weapon
							cout << name << " chose not to sell the " << weapon << "." << endl;
						}
					}
					if (healthPotionsAmount != 0 && !hasTraded) {
						//player has a health potion
						cout << other->name << " offers to trade with " << name << endl;

						if (healthPotionsAmount >= potionRequest) {
							cout << "does " << name << " wish to sell " << potionRequest << " health potions " << " for " << amount << "coin(s)?" << endl;
						}
						else {
							potionRequest = healthPotionsAmount;
							cout << "does " << name << " wish to sell " << potionRequest << " health potions " << " for " << amount << "coin(s)?" << endl;
						}
						cout << "1. yes" << endl;
						cout << "2. no" << endl;
						cout << "> ";
						int input;
						cin >> input;
						if (input == 1) {
							//player agrees to sell
							cout << name << " sold " << potionRequest << " health potions " << " for " << amount << " coins" << endl;
							healthPotionsAmount -= potionRequest;
							coins += amount;
							cout << name << " currently has " << coins << " coin(s)." << endl;
							if (!hasPotion) {
								hasPotion = true;
							}
							other->hasTraded = true;
						}
						else {
							//does not agree to sell the weapon
							cout << name << " chose not to sell the " << potionRequest << " health potions." << endl;
						}
					} 
					else {
						// no money at all (or weapon) ... npc doesnt see player fit to trade with
						cout << other->name << " grunts at " << name << " and then walks away." << endl;
					}
				}
				//other->hasTraded = true;
			}
			else {
				cout << name << " has already traded with " << other->name << "." << endl;
				other->actionOption = 2;
				//other->currentHealth = 0;
			}
		}
		else if (other->alignment == "Evil") {
			int amount = d6(rd);
			if (other->hasTraded == false) {
				cout << other->name << " demands " << amount << " coins from " << name << endl;
				if (coins >= amount) {
					cout << "Does " << name << " give the money?" << endl;
					cout << "1. yes" << endl;
					cout << "2. no" << endl;
					cout << "> ";
					int input;
					cin >> input;
					if (input == 1) {
						actionOption = 2;
						cout << other->name << " took " << amount << " coin(s)..." << endl;
						coins -= amount;
						cout << name << " currently has " << coins << " coin(s)." << endl;
						other->hasTraded = true;
					}
					else if (input == 2) {
						actionOption = 1;
					}

				}
				else if(coins <= amount) {
					cout << name << " doesn't have enough money!" << endl;
					actionOption = 1;
					other->actionOption = 1;
				}
			}
			else if (hasTraded == true){
				cout << other->name << " shouts insults at " << name << " in a foreign language then attacks!" << endl;
				other-> actionOption = 1;
			}
		}
		else {
			cout << other->name << " ignores " << name << " and walks away." << endl;
		}
	} 
	else if (option == 3) {
		if (!isFighting) {
			if (other->alignment != "Evil") {
				cout << name << " decided to walk away from " << other->name << endl;
				other->currentHealth = 0;
			}
			else {
				if (!other->hasTraded) {
					cout << other->name << " doesn't permit " << name << " to leave yet, and blocks the exit!" << endl;
					actionOption = 2;
					other->actionOption = 2;
				}
				else {
					cout << name << " decided to walk away from " << other->name << endl;
					other->currentHealth = 0;
				}
			}
		}
		else {
			cout << name << " can't walk away, because " << name << " is currently battling " << other->name << endl;
			actionOption = 1;
			other->actionOption = 1;
		}
	}
	else if (option == 4) {
	if (!isFighting) {
		string potionsCountDescriptor = (healthPotionsAmount <= 1) ? "a health potion" : "health potions";
		int consumedAmount;
		cout << name << " decided to " << "restore their health by drinking " << potionsCountDescriptor << endl;
		cout << name << "  currently has " << currentHealth << " out of " << totalHealth << " health," << endl;
		
		if (healthPotionsAmount > 1) {
			cout << "how many of their " << healthPotionsAmount << " health potions does " << name << " intend to consume?" << endl;
			cout << "> ";
			cin >> consumedAmount;
			while (consumedAmount > healthPotionsAmount) {
				int input;
				cout << name << " only has " << healthPotionsAmount << " health potions!" << endl;
				cout << name << " does not have enough potions to drink " << consumedAmount << " potions right now." << endl;
				cout << "Does " << name << " want to drink all " << healthPotionsAmount << " of their health potions?" << endl;
				cout << "1. yes" << endl;
				cout << "2. no" << endl;
				cout << "> ";
				cin >> input;
				if (input == 1) {
					consumedAmount = healthPotionsAmount;
					break;
				}
				else {
					cout << "how many of their " << healthPotionsAmount << " health potions does " << name << " intend to consume?" << endl;
					cout << "> ";
					cin >> consumedAmount;
					if (consumedAmount <= healthPotionsAmount) {
						break;
					}
				}
			}
			cout << name << " decided to drink " << consumedAmount << " out of their " << healthPotionsAmount << " health potions!" << endl;
		}
		else {
			consumedAmount = 1;
			if (consumedAmount > healthPotionsAmount) {
				cout << name << " has no health potions to consume!" << endl;
			}
			else {
				cout << name << " decided to drink their " << consumedAmount <<  " health potion!" << endl;
			}
		}

		//determine health gained
		//currentHealth / totalHealth
		int chance = d6(rd) - 1;
		int healthGained = 1 + chance * 2;
		currentHealth += healthGained;
		if (currentHealth > totalHealth) {
			currentHealth = totalHealth;
		}

		potionsCountDescriptor = (healthPotionsAmount <= 1) ? "potion" : consumedAmount + " potions";
		cout << name << " gained " << healthGained << " health from drinking the " << potionsCountDescriptor << ", and now has " << currentHealth << " out of " << totalHealth << " health" << endl;

		//player drinks consumed amount of health potions 
		healthPotionsAmount -= consumedAmount;
		cout << name << " currently has " << healthPotionsAmount << " health potions remaining" << endl;
		other->actionOption = 2;
	}
	else {
		cout << name << " chose to try to restore their health while " << name << " is currently battling " << other->name << endl;
		actionOption = 1;
		other->actionOption = 1;
	}
	}
}
void player::setStats(int level)
{	
	
	int baseStat = 2 * level;
	int x = rand() % baseStat + 1;

	damage = x;

	if (damage < 1)
		damage = 1;
	unarmedDamage = damage;
	damageBonus = unarmedDamage + level;
	attackBonus = level;

	armourClass = x + 4 + level;

	currentHealth = totalHealth = x * 3;
	
	characterLevel = level;
	displayStats();
}
bool player::isAlive()
{
	if (currentHealth > 0)
		return true;
	else
		return false;
}
void player::displayStats() {
	cout << "" << endl;
	cout << "Player Stats:" << endl;
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