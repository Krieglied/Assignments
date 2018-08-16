#pragma once

#include "mecha.h"
#include "weapon.h"
#include <vector>

//These are the various types of mechs that are available to the players
//There are eight in total, the main differences being the loadout of each mech
//The hit points, and the heat sink pool
//For now, the hit points and heat sink are balanced around 150 points
//Might change the numbers later if those are unfair or unfun
class Hellbringer : public Mecha
{
public:
	// Default Constructor
	Hellbringer() {
		mechaName = "Hellbringer";
		type = "Hellbringer";
		heatSink = 85;
		hitPoints = 65;
		//Kept for balancing purposes
		//deathBlossomChance = 10;
		everyoneChance = 10;
		linkedChance = 15;
		normalChance = 65;
		setWeapons();
	}
	// Constructor
	Hellbringer(std::string mn) {
		Hellbringer();
		mechaName = mn;
	}
	void setWeapons() override
	{
		PPC A;
		weaponSet.push_back(A);
		weaponSet.push_back(A);
		ERMedLaser B;
		weaponSet.push_back(B);
		weaponSet.push_back(B);
		weaponSet.push_back(B);
		SRM C;
		weaponSet.push_back(C);
	}
	virtual bool computeDamageReceived(std::map<char, int> damageMap) override
	{
		for (auto& item : damageMap)
		{
			if (item.first == 'P')
			{
				item.second -= 5;
			}
			if (hitPoints - item.second < 0)
			{
				return true;
			}
			else
			{
				hitPoints -= item.second;
			}
		}
		return false;
	}
};

class MadDog : public Mecha {
public:
	// Default Constructor
	MadDog() {
		mechaName = "Mad Dog";
		type = "Mad Dog";
		heatSink = 90;
		hitPoints = 60;
		//Kept for balancing purposes
		//deathBlossomChance = 13;
		everyoneChance = 20;
		linkedChance = 20;
		normalChance = 57;
		setWeapons();
	}
	// Constructor
	MadDog(std::string mn) {
		MadDog();
		mechaName = mn;
	}
	void setWeapons() override
	{
		LRM A;
		weaponSet.push_back(A);
		weaponSet.push_back(A);
		MedPLaser B;
		weaponSet.push_back(B);
		weaponSet.push_back(B);
		LargePLaser C;
		weaponSet.push_back(C);
		weaponSet.push_back(C);
	}
	virtual bool computeDamageReceived(std::map<char, int> damageMap) override
	{
		for (auto& item : damageMap)
		{
			if (item.first == 'L')
			{
				item.second -= 5;
			}
			if (hitPoints - item.second < 0)
			{
				return true;
			}
			else
			{
				hitPoints -= item.second;
			}
		}
		return false;
	}
};

class Summoner : public Mecha {
public:
	// Default Constructor
	Summoner() {
		mechaName = "Summoner";
		type = "Summoner";
		heatSink = 80;
		hitPoints = 70;
		//Kept for balancing purposes
		//deathBlossomChance = 35;
		everyoneChance = 35;
		linkedChance = 0;
		normalChance = 30;
		setWeapons();
	}
	// Constructor
	Summoner(std::string mn) {
		Summoner();
		mechaName = mn;
	}
	void setWeapons() override
	{
		AC A;		
		weaponSet.push_back(A);
		LRM B;
		weaponSet.push_back(B);
		PPC C;
		weaponSet.push_back(C);
	}
	virtual bool computeDamageReceived(std::map<char, int> damageMap) override
	{
		if (damageMap.size() > 1)
		{
			if (hitPoints - 10 < 0)
			{
				return true;
			}
			else
			{
				hitPoints -= 10;
				return false;
			}
		}
		else
		{
			for (auto& item : damageMap)
			{
				if (hitPoints - item.second < 0)
				{
					return true;
				}
				else
				{
					hitPoints -= item.second;
					return false;
				}
			}
		}
	}
};

class TimberWolf : public Mecha {
public:
	// Default Constructor
	TimberWolf() {
		mechaName = "Timber Wolf";
		type = "Timber Wolf";
		heatSink = 75;
		hitPoints = 75;
		//Kept for balancing purposes
		//deathBlossomChance = 10;
		everyoneChance = 15;
		linkedChance = 30;
		normalChance = 45;
		setWeapons();
	}
	// Constructor
	TimberWolf(std::string mn) {
		TimberWolf();
		mechaName = mn;
	}
	void setWeapons() override
	{
		ERLargeLaser A;
		weaponSet.push_back(A);
		weaponSet.push_back(A);
		ERMedLaser B;
		weaponSet.push_back(B);
		weaponSet.push_back(B);
		weaponSet.push_back(B);
		LRM C;
		weaponSet.push_back(C);
		weaponSet.push_back(C);
	}
	virtual bool computeDamageReceived(std::map<char, int> damageMap) override
	{
		for (auto& item : damageMap)
		{
			if (item.first == 'M')
			{
				item.second -= 5;
			}
			if (hitPoints - item.second < 0)
			{
				return true;
			}
			else
			{
				hitPoints -= item.second;
			}
		}
		return false;
	}
};

class Warhammer : public Mecha {
public:
	// Default Constructor
	Warhammer() {
		mechaName = "Warhammer";
		type = "Warhammer";
		heatSink = 70;
		hitPoints = 80;
		//Kept for balancing purposes
		//deathBlossomChance = 12;
		everyoneChance = 15;
		linkedChance = 18;
		normalChance = 65;
		setWeapons();
	}
	// Constructor
	Warhammer(std::string mn) {
		Warhammer();
		mechaName = mn;
	}
	void setWeapons() override
	{
		PPC A;
		weaponSet.push_back(A);
		weaponSet.push_back(A);
		MedPLaser B;
		weaponSet.push_back(B);
		weaponSet.push_back(B);
		weaponSet.push_back(B);
		weaponSet.push_back(B);
		weaponSet.push_back(B);
		SRM C;
		weaponSet.push_back(C);
	}
	virtual bool computeDamageReceived(std::map<char, int> damageMap) override
	{
		for (auto& item : damageMap)
		{
			if (item.first == 'K')
			{
				item.second -= 5;
			}
			if (hitPoints - item.second < 0)
			{
				return true;
			}
			else
			{
				hitPoints -= item.second;
			}
		}
		return false;
	}
};

class Kodiak : public Mecha {
public:
	// Default Constructor
	Kodiak() {
		mechaName = "Kodiak";
		type = "Kodiak";
		heatSink = 50;
		hitPoints = 100;
		//Kept for balancing purposes
		//deathBlossomChance = 5;
		everyoneChance = 5;
		linkedChance = 5;
		normalChance = 85;
		setWeapons();
	}
	// Constructor
	Kodiak(std::string mn) {
		Kodiak();
		mechaName = mn;
	}
	void setWeapons() override
	{
		AC A;
		weaponSet.push_back(A);
		ERLargeLaser B;
		weaponSet.push_back(B);
		SRM C;
		weaponSet.push_back(C);
		weaponSet.push_back(C);
		ERMedLaser D;
		weaponSet.push_back(D);
		weaponSet.push_back(D);
		weaponSet.push_back(D);
		weaponSet.push_back(D);
		weaponSet.push_back(D);
		weaponSet.push_back(D);
		weaponSet.push_back(D);
		weaponSet.push_back(D);
	}
	virtual bool computeDamageReceived(std::map<char, int> damageMap) override
	{
		for (auto& item : damageMap)
		{
			if (item.first == 'R')
			{
				item.second -= 5;
			}
			if (hitPoints - item.second < 0)
			{
				return true;
			}
			else
			{
				hitPoints -= item.second;
			}
		}
		return false;
	}
};

class StoneRhino : public Mecha {
public:
	// Default Constructor
	StoneRhino() {
		mechaName = "Stone Rhino";
		type = "Stone Rhino";
		heatSink = 50;
		hitPoints = 100;
		//Kept for balancing purposes
		//deathBlossomChance = 6;
		everyoneChance = 7;
		linkedChance = 7;
		normalChance = 80;
		setWeapons();
	}
	// Constructor
	StoneRhino(std::string mn) {
		StoneRhino();
		mechaName = mn;
	}
	void setWeapons() override
	{
		Gauss A;
		weaponSet.push_back(A);
		weaponSet.push_back(A);
		LargePLaser B;
		weaponSet.push_back(B);
		weaponSet.push_back(B);
		SmallPLaser C;
		weaponSet.push_back(C);
	}
	virtual bool computeDamageReceived(std::map<char, int> damageMap) override
	{
		for (auto& item : damageMap)
		{
			if (item.first == 'R' || item.first == 'L')
			{
				item.second -= 5;
			}
			if (hitPoints - item.second < 0)
			{
				return true;
			}
			else
			{
				hitPoints -= item.second;
			}
		}
		return false;
	}
};

class Mauler : public Mecha {
public:
	// Default Constructor
	Mauler() {
		mechaName = "Mauler";
		type = "Mauler";
		heatSink = 60;
		hitPoints = 90;
		//Kept for balancing purposes
		//deathBlossomChance = 4;
		everyoneChance = 4;
		linkedChance = 15;
		normalChance = 77;
		setWeapons();
	}
	// Constructor
	Mauler(std::string mn) {
		Mauler();
		mechaName = mn;
	}
	void setWeapons() override
	{
		ERLargeLaser A;
		weaponSet.push_back(A);
		weaponSet.push_back(A);
		LRM B;
		weaponSet.push_back(B);
		weaponSet.push_back(B);
		AC C;
		weaponSet.push_back(C);
		weaponSet.push_back(C);
		weaponSet.push_back(C);
		weaponSet.push_back(C);
	}
	virtual bool computeDamageReceived(std::map<char, int> damageMap) override
	{
		bool resist = true;
		for (auto& item : damageMap)
		{
			if (resist)
			{
				item.second -= 5;
			}
			if (hitPoints - item.second < 0)
			{
				return true;
			}
			else
			{
				hitPoints -= item.second;
			}
		}
		return false;
	}
};
