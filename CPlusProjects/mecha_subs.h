#pragma once

#include "mecha.h"
#include "weapon.h"
// WARNING
/*
There is an example subclass included... delete it if you want to try it without reference
Please note, this is a bare bones subclass. It only includes enough to get you started
*/

// Sub Classes
class Hellbringer : public Mecha 
{
private:
	PPC A;
	PPC B;
	ERMedLaser C;
	ERMedLaser D;
	ERMedLaser E;
	SRM F;

public:
	// Default Constructor
	Hellbringer() {
		mechaName = "Hellbringer";
		type = "Hellbringer";
		heatSink = 85;
		hitPoints = 65;
	}
	// Constructor
	Hellbringer(std::string mn) {
		mechaName = mn;
		type = "Hellbringer";
		heatSink = 85;
		hitPoints = 65;
	}
	void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		A.display_weapon_stats();
		B.display_weapon_stats();
		C.display_weapon_stats();
		D.display_weapon_stats();
		E.display_weapon_stats();
		F.display_weapon_stats(); 
		std::cout << "\n\n";

	}
};

class MadDog : public Mecha {
private:
	LRM A;
	LRM B;
	MedPLaser C;
	MedPLaser D;
	LargePLaser E;
	LargePLaser F;

public:
	// Default Constructor
	MadDog() {
		mechaName = "Mad Dog";
		type = "Mad Dog";
		heatSink = 90;
		hitPoints = 60;
	}
	// Constructor
	MadDog(std::string mn) {
		mechaName = mn;
		type = "Mad Dog";
		heatSink = 90;
		hitPoints = 60;
	}
	void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		A.display_weapon_stats();
		B.display_weapon_stats();
		C.display_weapon_stats();
		D.display_weapon_stats();
		E.display_weapon_stats();
		F.display_weapon_stats();
		std::cout << "\n\n";

	}
};

class Summoner : public Mecha {
private:
	AC A;
	LRM B;
	PPC C;

public:
	// Default Constructor
	Summoner() {
		mechaName = "Summoner";
		type = "Summoner";
		heatSink = 80;
		hitPoints = 70;
	}
	// Constructor
	Summoner(std::string mn) {
		mechaName = mn;
		type = "Summoner";
		heatSink = 80;
		hitPoints = 70;
	}
	void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		A.display_weapon_stats();
		B.display_weapon_stats();
		C.display_weapon_stats();
		std::cout << "\n\n";

	}
};

class TimberWolf : public Mecha {
private:
	ERLargeLaser A;
	ERLargeLaser B;
	ERMedLaser C;
	ERMedLaser D;
	ERMedLaser E;
	LRM F;
	LRM G;

public:
	// Default Constructor
	TimberWolf() {
		mechaName = "Timber Wolf";
		type = "Timber Wolf";
		heatSink = 75;
		hitPoints = 75;
	}
	// Constructor
	TimberWolf(std::string mn) {
		mechaName = mn;
		type = "Timber Wolf";
		heatSink = 75;
		hitPoints = 75;
	}
	void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		A.display_weapon_stats();
		B.display_weapon_stats();
		C.display_weapon_stats();
		D.display_weapon_stats();
		E.display_weapon_stats();
		F.display_weapon_stats();
		G.display_weapon_stats();
		std::cout << "\n\n";

	}
};

class Warhammer : public Mecha {
private:
	PPC A;
	PPC B;
	MedPLaser C;
	MedPLaser D;
	MedPLaser E;
	MedPLaser F;
	MedPLaser G;
	SRM H;

public:
	// Default Constructor
	Warhammer() {
		mechaName = "Warhammer";
		type = "Warhammer";
		heatSink = 70;
		hitPoints = 80;
	}
	// Constructor
	Warhammer(std::string mn) {
		mechaName = mn;
		type = "Warhammer";
		heatSink = 70;
		hitPoints = 80;
	}
	void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		A.display_weapon_stats();
		B.display_weapon_stats();
		C.display_weapon_stats();
		D.display_weapon_stats();
		E.display_weapon_stats();
		F.display_weapon_stats();
		G.display_weapon_stats();
		H.display_weapon_stats();
		std::cout << "\n\n";

	}
};

class Kodiak : public Mecha {
private:
	AC A;
	ERLargeLaser B;
	SRM C;
	SRM D;
	ERMedLaser E;
	ERMedLaser F;
	ERMedLaser G;
	ERMedLaser H;
	ERMedLaser I;
	ERMedLaser J;
	ERMedLaser K;
	ERMedLaser L;

public:
	// Default Constructor
	Kodiak() {
		mechaName = "Kodiak";
		type = "Kodiak";
		heatSink = 50;
		hitPoints = 100;
	}
	// Constructor
	Kodiak(std::string mn) {
		mechaName = mn;
		type = "Kodiak";
		heatSink = 50;
		hitPoints = 100;
	}
	void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		A.display_weapon_stats();
		B.display_weapon_stats();
		C.display_weapon_stats();
		D.display_weapon_stats();
		E.display_weapon_stats();
		F.display_weapon_stats();
		G.display_weapon_stats();
		H.display_weapon_stats();
		I.display_weapon_stats();
		J.display_weapon_stats();
		K.display_weapon_stats();
		L.display_weapon_stats();
		std::cout << "\n\n";

	}
};

class StoneRhino : public Mecha {
private:
	Gauss A;
	Gauss B;
	LargePLaser C;
	LargePLaser D;
	SmallPLaser E;

public:
	// Default Constructor
	StoneRhino() {
		mechaName = "Stone Rhino";
		type = "Stone Rhino";
		heatSink = 50;
		hitPoints = 100;
	}
	// Constructor
	StoneRhino(std::string mn) {
		mechaName = mn;
		type = "Stone Rhino";
		heatSink = 50;
		hitPoints = 100;
	}
	void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		A.display_weapon_stats();
		B.display_weapon_stats();
		C.display_weapon_stats();
		D.display_weapon_stats();
		E.display_weapon_stats();
		std::cout << "\n\n";

	}
};

class Mauler : public Mecha {
private:
	ERLargeLaser A;
	ERLargeLaser B;
	LRM C;
	LRM D;
	AC E;
	AC F;
	AC G;
	AC H;

public:
	// Default Constructor
	Mauler() {
		mechaName = "Mauler";
		type = "Mauler";
		heatSink = 60;
		hitPoints = 90;
	}
	// Constructor
	Mauler(std::string mn) {
		mechaName = mn;
		type = "Mauler";
		heatSink = 60;
		hitPoints = 90;
	}
	void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		A.display_weapon_stats();
		B.display_weapon_stats();
		C.display_weapon_stats();
		D.display_weapon_stats();
		E.display_weapon_stats();
		F.display_weapon_stats();
		G.display_weapon_stats();
		H.display_weapon_stats();
		std::cout << "\n\n";

	}
};
