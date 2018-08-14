#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h> 

/*
This one is already built for you... feel free to add to it.
Utilize the damage in either a method (pref in mecha_sub) or main() to determine how muchh damage you do on an enemy mech
Ensure power is being subtracted by cost after every action. Prevent action if power is too low for action (this can be done via method (pref in mecha sub)  or main)
*/




class Weapon {
protected:
	std::string weaponName;
	int damage;					// How much damage this weapon does
	int heatCost;					// Cost to use weapon on turn
public:
	Weapon() {}
	int getHeat()
	{
		return heatCost;
	}
	virtual int fireWeapon()
	{
		std::cout << "Firing " << weaponName << " dealing " << damage << " damage." << std::endl;
		return damage;
	}
	virtual void display_weapon_stats() {
		std::cout << "Model: " << weaponName << std::endl;
		std::cout << "Damage: " << damage << std::endl;
		std::cout << "Heat Cost: " << heatCost << std::endl;
	}
};


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

class Gauss : public Weapon {
private:
	int ammo;
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
			ammo--;
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
private:
	int ammo;
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
			ammo--;
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
private:
	int ammo;
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
			ammo--;
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

class LRM : public Weapon {
private:
	int ammo;
public:
	LRM()
	{
		weaponName = "Long Range Missiles";
		heatCost = 6;
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
				if ((rand() % 10 + 1) < 4)
				{
					result++;
				}
			}
			if (result < 2)
			{
				ammo--;
				return 2;
			}
			else
			{
				ammo--;
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
private:
	int ammo;
public:
	SRM()
	{
		weaponName = "Long Range Missiles";
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
				if ((rand() % 10 + 1) < 4)
				{
					result++;
				}
			}
			if (result < 2)
			{
				ammo--;
				return 2;
			}
			else
			{
				ammo--;
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
