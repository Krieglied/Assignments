#pragma once
#include "weapon.h"
#include <time.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <map>
#include <list>

//Base Class for all mechs
class Mecha {
protected:
	//Holds the loadout for each particular mech
	std::vector<Weapon> weaponSet;
	std::string mechaName;
	//If the player wishes to name his/her mech, that is stored here
	std::string type;
	//Each mech will have a unique percentage for how often it performs a special attack
	//The basic understanding is that when a player selects a weapon to fire, there is
	//a 25% chance to normal, 25% to link fire, 25% to fire all weapons at 0.75 heat cost,
	//and a 25% chance to fire everything at 1.5x damage, but double heat cost

	//Fire everything at 1.5x damage, but double heat cost
	int deathBlossomChance;
	//Fire all weapons at 0.75 heat cost
	int everyoneChance;
	//Link fire
	int linkedChance;
	int normalChance;
	//Status effect that is inflicted once the player has exhausted his/her heat sink pool
	bool overHeated;
	//Health of the mech, once this reaches 0, it's game over, man. Game over.
	int hitPoints;
	//Limits the actions of the player.  Player should take care of his/her heat, once it reaches 0,
	//the mech will overheat and the player will be vulnerable for a turn
	int heatSink;
	char armorType;
public:
	// Default constructor... subclass should handle construction
	Mecha() {}
	//Used to display basic information about the mech.  Will be used to help the player decided which mech is right for him/her
	virtual void display_main_stats() {
		std::cout << "Type : " << type << std::endl;
		std::cout << "Hit Points: " << hitPoints << std::endl;
		std::cout << "Heat Tank: " << heatSink << std::endl;
	}
	//Loads the various weapons into weaponset
	virtual void setWeapons(){}
	//Return list of weapons of the mech'
	virtual std::vector<Weapon> getWeapons()
	{
		return weaponSet;
	}
	//Basic method to inflict damage on the mech from the opponent
	//Will return false upon a successful hit (mech got hit, but wasn't destroyed)
	//Will return 1 to indicate a dead mech
	virtual bool computeDamageReceived(std::map<char, int> damageMap)
	{
		return true;
	}
	//Might remove this
	virtual int getHP() {
		return hitPoints;
	}
	//Displays basic stats, but also the loadout for the mech
	virtual bool display_stats(int distance)
	{
		std::list<std::string> displayed;
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		int slot = 0;
		for (auto& item : weaponSet)
		{
			if ((std::find(displayed.begin(), displayed.end(), item.getName()) == displayed.end()) && item.getRange() >= distance)
			{
				displayed.emplace_back(item.getName());
				if (item.getName() == "Long Range Missiles")
				{
					LRM output;
					std::cout << "(" << (slot + 1) << ")" << std::endl;
					output.display_weapon_stats();
				}
				else if (item.getName() == "Short Range Missiles")
				{
					SRM output;
					std::cout << "(" << (slot + 1) << ")" << std::endl;
					output.display_weapon_stats();
				}
				else if (item.getName() == "Gauss Rifle")
				{
					Gauss output;
					std::cout << "(" << (slot + 1) << ")" << std::endl;
					output.display_weapon_stats();
				}
				else if (item.getName() == "Autocannon")
				{
					AC output;
					std::cout << "(" << (slot + 1) << ")" << std::endl;
					output.display_weapon_stats();
				}
				else if (item.getName() == "Autocannon/20")
				{
					AC20 output;
					std::cout << "(" << (slot + 1) << ")" << std::endl;
					output.display_weapon_stats();
				}
				else
				{
					std::cout << "(" << (slot + 1) << ")" << std::endl;
					item.display_weapon_stats();
				}
				slot++;
			}
		}
		if (slot == 0)
		{
			std::cout << " No weapons with range, available to fire.  Changing to next player." << std::endl;
			return false;
		}
		else
		{
			std::cout << std::endl << std::endl;
			return true;
		}
	}
	//When a player uses a weapon, the weapon generates some heat.  If there is no heat sink pool after the attack,
	//The mech will be shutdown for a turn
	virtual void soakHeat(int heatAmount)
	{
		heatSink -= heatAmount;
		if (heatSink < 0)
		{
			std::cout << "Your mech has overheated.  You're out of action for a turn." << std::endl;
			heatSink = 15;
			overHeated = true;
		}
	}
	//Switches the mech's overheated State
	virtual void switchHeatState()
	{
		overHeated = !overHeated;
	}
	//Status check to see if mech is shutdown or not
	virtual bool isOverHeated()
	{
		return overHeated;
	}
	//Default method for the Death Blossom, and EVERYONE attacks
	virtual std::map<char, int> fireAllWeapons(float damageBonus, float heatBonus, int distance)
	{
		int heatSoakedTotal = 0;
		//Changed the fire weapon method to account for the weapon type of the attacks
		std::map<char, int> damageMap;

		for (auto& item : weaponSet)
		{
			if (item.getName() == "Long Range Missiles")
			{
				LRM output;
				damageMap = loadWeaponDamage(output, damageMap, damageBonus, distance);
				item.useAmmo();
			}
			else if (item.getName() == "Short Range Missiles")
			{
				SRM output;
				damageMap = loadWeaponDamage(output, damageMap, damageBonus, distance);
				item.useAmmo();
			}
			else if (item.getName() == "Gauss Rifle")
			{
				Gauss output;
				damageMap = loadWeaponDamage(output, damageMap, damageBonus, distance);
				item.useAmmo();
			}
			else if (item.getName() == "Autocannon")
			{
				AC output;
				damageMap = loadWeaponDamage(output, damageMap, damageBonus, distance);
				item.useAmmo();
			}
			else if (item.getName() == "Autocannon/20")
			{
				AC20 output;
				damageMap = loadWeaponDamage(output, damageMap, damageBonus, distance);
				item.useAmmo();
			}
			else
			{
				damageMap = loadWeaponDamage(item, damageMap, damageBonus, distance);
			}
			heatSoakedTotal += item.getHeat();
		}
		heatSoakedTotal = (int)(heatBonus * heatSoakedTotal);
		soakHeat(heatSoakedTotal);
		return damageMap;
	}
	//Builds the damage map that will have the amount of damage done by each weapon type
	virtual std::map<char, int> loadWeaponDamage(Weapon& selected, std::map<char, int> damageMap, float damageBonus, int distance)
	{
		if (selected.getRange() < distance)
		{
			return damageMap;
		}
		auto result = damageMap.find(selected.getType());
		if (result == damageMap.end())
		{
			damageMap.emplace(selected.getType(), (int)(damageBonus * selected.fireWeapon()[selected.getType()]));
		}
		else
		{
			result->second += (int)(damageBonus * selected.fireWeapon()[selected.getType()]);
		}
		return damageMap;
	}
	//If this attack is rolled, then selected weapon and another weapon are fired at the same time
	virtual std::map<char, int> linkedWeaponsFire(Weapon& selected)
	{
		std::map<char, int> damageMap;
		int heatSoakedTotal = 0;
		int damageTotal = 0;
		for (auto& item : weaponSet)
		{
			if (item.getName() == selected.getName())
			{
				damageTotal += item.fireWeapon()[selected.getType()];
				heatSoakedTotal += item.getHeat();
			}
		}
		damageMap.emplace(selected.getType(), damageTotal);
		soakHeat(heatSoakedTotal);
		return damageMap;
	}
	//This function will handle randomly rolling for the chance of the 4 attacks
	virtual std::map<char, int> releasePayload(int index, int distance)
	{
		std::list<std::string> displayed;
		int position = 0, location = 0;;
		std::string weaponName = "";
		for(auto& item : weaponSet)
		{
			if (std::find(displayed.begin(), displayed.end(), item.getName()) == displayed.end())
			{
				displayed.emplace_back(item.getName());
				if (position == index)
				{
					break;
				}
				position++;
			}
			location++;
		}

		int result = 0;
		int chance = 0;
		srand(time(NULL));
		chance = (rand() % 100 + 1);
		Weapon selected = weaponSet.at(location);
		//Each chance value will be an int, and will be added to the previous to represent moving from 1 to 100
		if (chance <= normalChance)
		{
			//Normal attack just subtracts heat from heat sink and deals damage to opponent mech
			soakHeat(selected.getHeat());
			return selected.fireWeapon();
		}
		else if (chance <= (normalChance + linkedChance))
		{
			std::cout << "Focus Fire!!" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			return linkedWeaponsFire(selected);
		}
		//The two fire all weapons attack have special prints for them
		else if (chance <= (normalChance + linkedChance + everyoneChance))
		{
			std::cout << "Bring Everyone." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << "Everyone? .... " << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << "EVERYONE!!!!" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			return fireAllWeapons(1, 0.75, distance);
		}
		else
		{
			std::cout << "Initiating..... " << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << "Death Blossom" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			return fireAllWeapons(1.5, 2, distance);
		}
	}
};