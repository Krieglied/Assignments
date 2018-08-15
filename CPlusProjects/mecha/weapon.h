#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h> 

//Base Class for the weapons
class Weapon {
protected:
	std::string weaponName;
	//Not all weapons will have a default value for damage, i.e. the missile type weapon use random chance
	int damage;
	//Based on BattleTech, each use of a weapon will generate heat and once the Heat Sink for a mech is at 0
	//The mech will shutdown for a turn
	int heatCost;
	//Some weapons have a limited use
	int ammo;
public:
	Weapon() {}
	//Default getters
	int getHeat()
	{
		return heatCost;
	}
	std::string getName()
	{
		return weaponName;
	}
	//Let's the players know how damage is being done
	virtual int fireWeapon()
	{
		std::cout << "Firing " << weaponName << " dealing " << damage << " damage." << std::endl;
		return damage;
	}
	virtual void useAmmo()
	{
		ammo--;
	}
	//Default display method, several weapons override this to account for ammo
	virtual void display_weapon_stats() {
		std::cout << "Model: " << weaponName << std::endl;
		std::cout << "Damage: " << damage << std::endl;
		std::cout << "Heat Cost: " << heatCost << std::endl;
	}
};

//This first set of weapons are just standard, with varying amounts of damage done and heat generated
class PPC : public Weapon {
public:
	PPC()
	{
		weaponName = "Extended Range Particle Projector Cannon";
		damage = 15;
		heatCost = 15;
	}
};

class ERMedLaser : public Weapon {
public:
	ERMedLaser()
	{
		weaponName = "Extended Range Medium Laser";
		damage = 7;
		heatCost = 5;
	}
};
class MedPLaser : public Weapon {
public:
	MedPLaser()
	{
		weaponName = "Medium Pulse Laser";
		damage = 7;
		heatCost = 4;
	}
};
class LargePLaser : public Weapon {
public:
	LargePLaser()
	{
		weaponName = "Large Pulse Laser";
		damage = 10;
		heatCost = 10;
	}
};

class ERLargeLaser : public Weapon {
public:
	ERLargeLaser()
	{
		weaponName = "Extended Range Large Laser";
		damage = 10;
		heatCost = 12;
	}
};

class SmallPLaser : public Weapon {
public:
	SmallPLaser()
	{
		weaponName = "Small Pulse Laser";
		damage = 3;
		heatCost = 2;
	}
};
//The next three weapons have an added element of limited ammunition, which depletes after every use.
class Gauss : public Weapon {
public:
	Gauss()
	{
		weaponName = "Gauss Rifle";
		damage = 15;
		heatCost = 1;
		ammo = 5;
	}
	int fireWeapon() override
	{
		if (ammo == 0)
		{
			std::cout << "Out of Ammo" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "Firing " << weaponName << " dealing " << damage << " damage." << std::endl;
			return damage;
		}
	}
	void display_weapon_stats() override {
		std::cout << "Model: " << weaponName << std::endl;
		std::cout << "Damage: " << damage << std::endl;
		std::cout << "Heat Cost: " << heatCost << std::endl;
		std::cout << "Ammunition: " << ammo << std::endl;
	}
};

class AC : public Weapon {
public:
	AC()
	{
		weaponName = "Autocannon";
		damage = 10;
		heatCost = 2;
		ammo = 15;
	}
	int fireWeapon() override
	{
		if (ammo == 0)
		{
			std::cout << "Out of Ammo" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "Firing " << weaponName << " dealing " << damage << " damage." << std::endl;
			return damage;
		}
	}
	void display_weapon_stats() override {
		std::cout << "Model: " << weaponName << std::endl;
		std::cout << "Damage: " << damage << std::endl;
		std::cout << "Heat Cost: " << heatCost << std::endl;
		std::cout << "Ammunition: " << ammo << std::endl;
	}
};

class AC20 : public Weapon {
public:
	AC20()
	{
		weaponName = "Autocannon/20";
		damage = 20;
		heatCost = 7;
		ammo = 15;
	}
	int fireWeapon() override
	{
		if (ammo == 0)
		{
			std::cout << "Out of Ammo" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "Firing " << weaponName << " dealing " << damage << " damage." << std::endl;
			return damage;
		}
	}
	void display_weapon_stats() override {
		std::cout << "Model: " << weaponName << std::endl;
		std::cout << "Damage: " << damage << std::endl;
		std::cout << "Heat Cost: " << heatCost << std::endl;
		std::cout << "Ammunition: " << ammo << std::endl;
	}
};
//The missiles, in addition to the ammunition, will have a random chance for damage
//Maximum damage is 10, minimum damage is 2
class LRM : public Weapon {
public:
	LRM()
	{
		weaponName = "Long Range Missiles";
		heatCost = 6;
		damage = 10;
		ammo = 10;
	}
	int fireWeapon() override
	{
		if (ammo == 0)
		{
			std::cout << "Out of Ammo" << std::endl;
			return 0;
		}
		else
		{
			int result = 0;
			srand(time(NULL));
			for (int i = 0; i < 10; i++)
			{
				int hitChance = (rand() % 10 + 1);
				if (hitChance < 7)
				{
					result++;
				}
			}
			if (result < 2)
			{
				std::cout << "Firing " << weaponName << " dealing " << 2 << " damage." << std::endl;
				return 2;
			}
			else
			{
				std::cout << "Firing " << weaponName << " dealing " << result << " damage." << std::endl;
				return result;
			}
		}
	}
	void display_weapon_stats() override {
		std::cout << "Model: " << weaponName << std::endl;
		std::cout << "Max Damage: " << 10 << std::endl;
		std::cout << "Heat Cost: " << heatCost << std::endl;
		std::cout << "Ammunition: " << ammo << std::endl;
	}
};

class SRM : public Weapon {
public:
	SRM()
	{
		weaponName = "Short Range Missiles";
		damage = 10;
		heatCost = 4;
		ammo = 10;
	}
	int fireWeapon() override
	{
		if (ammo == 0)
		{
			std::cout << "Out of Ammo" << std::endl;
			return 0;
		}
		else
		{
			int result = 0;
			srand(time(NULL));
			for (int i = 0; i < 10; i++)
			{
				int hitChance = (rand() % 10 + 1);
				if (hitChance < 7)
				{
					result++;
				}
			}
			if (result < 2)
			{
				std::cout << "Firing " << weaponName << " dealing " << 2 << " damage." << std::endl;
				return 2;
			}
			else
			{
				std::cout << "Firing " << weaponName << " dealing " << result << " damage." << std::endl;
				return result;
			}
		}
	}
	void display_weapon_stats() override {
		std::cout << "Model: " << weaponName << std::endl;
		std::cout << "Max Damage: " << 10 << std::endl;
		std::cout << "Heat Cost: " << heatCost << std::endl;
		std::cout << "Ammunition: " << ammo << std::endl;
	}
};
