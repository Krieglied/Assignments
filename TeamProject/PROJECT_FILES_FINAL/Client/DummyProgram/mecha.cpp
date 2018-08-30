//Mech Game Project
//Start of Project: August 10, 2018
//Developer: Robert John Graham III
//
//This project is a basic game that allows two players to select from a range of mechs (8 in total),
//Each with a separate loadout of weapons and stats, and lets the players take potshots at each other
//Until only one mech (and player) stands victorious

#include "mecha.h"
#include "mecha_subs.h"
#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include <vector>
#include <map>
#include <math.h>
#include <windows.h>
int userInput(int value);
char userInput(char value);
bool checkMove(char choice, std::vector<int>& location, std::vector<std::vector<Mecha*>>& rows);
int computeDistance(std::vector<int> location, std::vector<int> opplocation);

int MechPlay() {
	//Sets some default values for the console
	//The program nows introduces some windows specific features, and thus will not work on Linux
	SetConsoleTitle("Mecha Project");
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 730, TRUE);
	//Token to record whose turn it is (player 1 or player 2)
	bool player = true;
	//Token to record when the game is over (a mech is destroyed)
	bool gameOver = false;
	//Used to access information about player 1's mech
	Mecha *mech1_ptr = NULL;
	//Used to access information about player 2's mech
	Mecha *mech2_ptr = NULL;
	std::vector<std::vector<Mecha*>> rows;
	//Default class object, used to display information about the mechs' and also set to the player mech
	//When a choice is made
	Hellbringer hbringer;
	MadDog mdog;
	Summoner summoner;
	TimberWolf twolf;
	Warhammer whammer;
	Kodiak kodiak;
	StoneRhino srhino;
	Mauler mauler;
	for (int i = 1; i < 3; i++)
	{
		//All mechs are displayed, with information related to name, hit points, and heat sink pool
		int mechChoice = 0;
		std::cout << "MECHS AVAILABLE:" << std::endl;
		std::cout << "(1)" << std::endl;
		hbringer.display_main_stats();
		std::cout << std::endl << "(2)" << std::endl;
		mdog.display_main_stats();
		std::cout << std::endl << "(3)" << std::endl;
		summoner.display_main_stats();
		std::cout << std::endl << "(4)" << std::endl;
		twolf.display_main_stats();
		std::cout << std::endl << "(5)" << std::endl;
		whammer.display_main_stats();
		std::cout << std::endl << "(6)" << std::endl;
		kodiak.display_main_stats();
		std::cout << std::endl << "(7)" << std::endl;
		srhino.display_main_stats();
		std::cout << std::endl << "(8)" << std::endl;
		mauler.display_main_stats();
		std::cout << std::endl;

		std::cout << "Player " << i << ", please select your mech (Input the number):" << std::endl;
		do
		{
			//Handles user input, if not a number, send back as invalid
			mechChoice = userInput(mechChoice);
			//If not is range of the mech number, send back as invalid
			if (!(mechChoice > 0 && mechChoice < 9))
			{
				std::cout << "Invalid number, please try again" << std::endl;
			}
			//Continue loop until user makes a valid choice
		} while (!(mechChoice > 0 && mechChoice < 9));
		switch (mechChoice)
		{
			//These cases will set the user's mech pointer to the appropriate derived class
			//Based on the user's choice above
			//After the choice is made, then player token is changed to falses so that player 2
			//Can make their choice
		case 1:
		{
			if (player)
			{
				mech1_ptr = (Hellbringer *)&hbringer;
				player = false;
			}
			else
			{
				mech2_ptr = (Hellbringer *)&hbringer;
			}
		}
			break;
		case 2:
		{
			if (player)
			{
				mech1_ptr = (MadDog *)&mdog;
				player = false;
			}
			else
			{
				mech2_ptr = (MadDog *)&mdog;
			}
		}
			break;
		case 3:
		{
			if (player)
			{
				mech1_ptr = (Summoner *)&summoner;
				player = false;
			}
			else
			{
				mech2_ptr = (Summoner *)&summoner;
			}
		}
			break;
		case 4:
		{
			if (player)
			{
				mech1_ptr = (TimberWolf *)&twolf;
				player = false;
			}
			else
			{
				mech2_ptr = (TimberWolf *)&twolf;
			}
		}
			break;
		case 5:
		{
			if (player)
			{
				mech1_ptr = (Warhammer *)&whammer;
				player = false;
			}
			else
			{
				mech2_ptr = (Warhammer *)&whammer;
			}
		}
			break;
		case 6:
		{
			if (player)
			{
				mech1_ptr = (Kodiak *)&kodiak;
				player = false;
			}
			else
			{
				mech2_ptr = (Kodiak *)&kodiak;
			}
		}
			break;
		case 7:
		{
			if (player)
			{
				mech1_ptr = (StoneRhino *)&srhino;
				player = false;
			}
			else
			{
				mech2_ptr = (StoneRhino *)&srhino;
			}
		}
			break;
		case 8:
		{
			if (player)
			{
				mech1_ptr = (Mauler *)&mauler;
				player = false;
			}
			else
			{
				mech2_ptr = (Mauler *)&mauler;
			}
		}
			break;
		}
		system("cls");
	}
	//Builds the grid that the mechs are represented on
	for (int i = 0; i < 20; i++)
	{
		std::vector<Mecha*> columns;
		for (int j = 0; j < 20; j++)
		{
			if (i == 5 && j == 10)
			{
				columns.push_back(mech1_ptr);
			}
			else if (i == 10 && j == 10)
			{
				columns.push_back(mech2_ptr);
			}
			else
			{
				Mecha * temp = NULL;
				columns.push_back(temp);
			}
		}
		rows.push_back(columns);
	}
	//Reset player token so that player 1 gets the first shot
	player = true;
	//Game play continue until someone wins
	while (!gameOver)
	{
		//If the player's mech is overheated, then that player doesn't have a turn
		if (player ? mech1_ptr->isOverHeated() : mech2_ptr->isOverHeated())
		{
			std::cout << "Your mech is overheated. You have to wait a turn." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			player ? mech1_ptr->switchHeatState() : mech2_ptr->switchHeatState();
		}
		else
		{
			int weaponChoice = 0;
			char moveChoice = ' ';
			int damage = 0;
			int distance = 0;
			std::map<char, int> damageMap;
			//Current player's location
			std::vector<int> location;
			//Enemy's location
			std::vector<int> opplocation;
			//Printing the field the players play on
			for (int i = 0; i < rows.size(); i++)
			{
				std::cout << "----";
			}
			std::cout << "-" << std::endl;
			for (int i = 0; i < rows.size(); i++)
			{
				for (int j = 0; j < rows[i].size(); j++)
				{
					if (rows[i][j] == NULL)
					{
						std::cout << "|   ";
					}
					else
					{
						if (rows[i][j] == mech1_ptr)
						{
							std::cout << "| 1 ";
							
						}
						else
						{
							std::cout << "| 2 ";
						}
						if (player ? (rows[i][j] == mech1_ptr) : (rows[i][j] == mech2_ptr))
						{
							//Column located in
							location.push_back(j);
							//Row located in
							location.push_back(i);
						}
						if (player ? (rows[i][j] == mech2_ptr) : (rows[i][j] == mech1_ptr))
						{
							//Column located in
							opplocation.push_back(j);
							//Row located in
							opplocation.push_back(i);
						}
					}
				}
				std::cout << "|" << std::endl;
			}
			for (int i = 0; i < rows.size(); i++)
			{
				std::cout << "----";
			}
			std::cout << "-" << std::endl;
			std::cout << "Player " << (player ? 1 : 2) << std::endl;
			std::cout << std::endl;
			player ? mech1_ptr->display_main_stats() : mech2_ptr->display_main_stats();
			std::cout << std::endl << std::endl;
			//Section that handles the player move
			//Player can move up, down, left, right or stay still
			do
			{
				std::cout << "Player " << (player ? 1 : 2) << ", which direction would you to move (A:W:S:D) or 0 if you don't want to move: " << std::endl;
				moveChoice = userInput(moveChoice);
			} while (!checkMove(moveChoice, location, rows));
			distance = computeDistance(location, opplocation);
			std::cout << "Player " << (player ? 1 : 2) << ", select which weapon to use: " << std::endl;
			//Displays the weapon available to player, uses a ternary operator to determine which player's loadout to display
			if (player ? !mech1_ptr->display_stats(distance) : !mech2_ptr->display_stats(distance))
			{
				player = !player;
				continue;
			}
			do
			{
				//Handles user input, if not a number, send back as invalid
				weaponChoice = userInput(weaponChoice);
				//If not is range of the mech number, send back as invalid
				if (!(weaponChoice > 0 && weaponChoice < (player ? mech1_ptr->getWeapons().size() + 1 : mech2_ptr->getWeapons().size() + 1)))
				{
					std::cout << "Invalid number, please try again" << std::endl;
				}
				//Continue loop until user makes a valid choice
			} while (!(weaponChoice > 0 && weaponChoice < (player ? mech1_ptr->getWeapons().size() + 1 : mech2_ptr->getWeapons().size() + 1)));
			//Pull damage from the player's mech
			damageMap = player ? mech1_ptr->releasePayload(weaponChoice - 1, distance) : mech2_ptr->releasePayload(weaponChoice - 1, distance);
			std::this_thread::sleep_for(std::chrono::seconds(2));
			//Subtract the damage from the other player's mech's health and see if that mech is destroyed
			gameOver = player ? mech2_ptr->computeDamageReceived(damageMap) : mech1_ptr->computeDamageReceived(damageMap);
			std::this_thread::sleep_for(std::chrono::seconds(1));
			//If either mech is down, end match
			if (gameOver)
			{
				break;
			}
		}
		//Switch to other player
		player = !player;
		system("cls");
	}
	std::cout << "The match has finished!" << std::endl;
	std::cout << "Player " << (player ? 1 : 2) << " has defeated his enemy!" << std::endl << std::endl << std::endl;
	//Victory print
	std::cout << "          //** /(,*//( %                       (./../ /*./ #.        " << std::endl;
	std::cout << "          **,/ /*,/*// #                       *.#//(.((*(*/.        " << std::endl;
	std::cout << "          /*(/(*,#*/*,(#                       *((#/,%,*(#(/.        " << std::endl;
	std::cout << "          /*,/ */ *,,/ #        .,**,.         * / .* **.* /.        " << std::endl;
	std::cout << "          /**( ((,(///.(   *     #   #    /    *.(*(/.((/%*/.        " << std::endl;
	std::cout << "          *(,#,,,#*//*/( .       #   *      *  /,,((,#,/,**//        " << std::endl;
	std::cout << "          *///(*,,*****/*     (        .(. ..* (/*******%%&(,        " << std::endl;
	std::cout << "               ./**   ///   (  .      .   &  *#** , ,*.              " << std::endl;
	std::cout << "              .  #*   *//  /     *. ./     # *#*, , /(  ,            " << std::endl;
	std::cout << "           *  *, (,   **( /  ** ,*   ,  ..  (,#*, , /( *,            " << std::endl;
	std::cout << "         /#.   /*#*.  *//.   /   ***,*   *  ,*%*, ,./(,#    *        " << std::endl;
	std::cout << "       (  *(.* .%&(.  */,%  *  (**//,*/  .  .(,*, ,.#((    (,  (     " << std::endl;
	std::cout << "     **/% .*.       ,,,,/,% * *,/.. */,. .  #**.*#(,     ..(  ,/,*   " << std::endl;
	std::cout << "     #/((#             / (,/# */(*,..*/// (*/. .             #(*,/   " << std::endl;
	std::cout << "     *   ,                #/#.@.(/. /,*(& ###                ,   .   " << std::endl;
	std::cout << "      (//.                .*/. (%,,/ /&/ ##&                  ///*   " << std::endl;
	std::cout << "     ,***(                 %%&...*%#/,,.,((.                 ./**(   " << std::endl;
	std::cout << "     *. ,                  *               /                 *. *    " << std::endl;
	std::cout << "     (/((/.     .*.. **,.  #((/////////*///  #,**# * ,       #/(/#   " << std::endl;
	std::cout << "   *#,/%&*.(. .  *.**  // ,................,.,.  .**  *   *//,(%*.,,," << std::endl;
	std::cout << "   /.((((/*./  *.*//*/(,,,,,,,,,,,,,,,,,***,/**.**  ,#  *.%%#((#//," << std::endl;
	std::cout << "   /,%(((##//./  *.**.*(*.                  /,,./.**  ,#  *,##((((//," << std::endl;
	std::cout << "   /,###(&@/(.   *,*.((,,                    *.//.*/  /   ,,##((#%(/*" << std::endl;
	std::cout << "   #* ,,/* .#/  **,,*##*,                    //#(//( /    *( ,,/,*.*," << std::endl;
	std::cout << "    * ./// .     ***//                         /,,,,       . /(/(/ . " << std::endl;
	std::cout << "     , *,*,    *,**,/*                          ***.**/     . **, .  " << std::endl;
	std::cout << "            .*,**(* ,*                          ,  .****/            " << std::endl;
	std::cout << "           *     (* ,# .                      * ,  .    . .          " << std::endl;
	std::cout << "           *     #* *#,.                      (**  .    ..,          " << std::endl;
	std::cout << "           * ,****,/(, .                      * ,##//(//* ,          " << std::endl;
	std::cout << "            /((   (#%(                         ,*#%&   #/,           " << std::endl;
	std::cout << "             /.    *                              /.    *            " << std::endl;
	std::cout << "            * *,,,*,,                            /,/***/             " << std::endl;
	std::cout << "           .       / .                          . ,      .           " << std::endl;
	std::cout << "           *       * /                          * .       ,          " << std::endl;
	std::cout << "           *       * *                          * .       ,          " << std::endl;
	std::cout << "           *       * *                          * ,       *          " << std::endl;
	std::cout << "           *       * .                          , ,       *          " << std::endl;
	std::cout << "            .      **                             ,      .           " << std::endl;
	std::cout << "           * *     # *                          * *     , /          " << std::endl;
	std::cout << "              ,   .   *                        /  ..   ,   ,         " << std::endl;
	std::cout << "       ...##((((((((#(&...                     %(((/((*/((#&         " << std::endl;
	std::cout << "    #(((#%*// #/((# *//%###(.             /((((#/( (*/*/ */(###%#%   " << std::endl;
	std::cout << "   %. %(##(,/ #*((( .(,#%## (/          ,#.(/((/*( #/%*( #./(/*( **  " << std::endl;
	std::cout << "  ...( //*((/(*////(/#(/,..*,,/        (**(. /(#(#(#,,**/(##(/,.(//( " << std::endl;
	getchar();
	getchar();

	return 0;
}
int userInput(int value)
{
	//Handles user input from the console
	std::string input;
	while (true) {
		std::getline(std::cin, input);
		std::stringstream myStream(input);
		if (myStream >> value)
		{
			break;
		}
		std::cout << "Invalid number, please try again" << std::endl;
	}
	return value;
}

char userInput(char value)
{
	std::string input;
	do
	{
		std::getline(std::cin, input);
		std::stringstream myStream(input);
		if (toupper(input[0]) != 'A' && toupper(input[0]) != 'W' 
			&& toupper(input[0]) != 'S' && toupper(input[0]) != 'D' && toupper(input[0]) != '0')
		{
			std::cout << "Invalid choice, please try again" << std::endl;
		}
		//Continue loop until user makes a valid choice
	} while (toupper(input[0]) != 'A' && toupper(input[0]) != 'W'
		&& toupper(input[0]) != 'S' && toupper(input[0]) != 'D' && toupper(input[0]) != '0');
	return toupper(input[0]);
}
//Checks to see if the player is valid.
//If so, perform the action.  Otherwise, player needs to be prompted for another move
bool checkMove(char choice, std::vector<int>& location, std::vector<std::vector<Mecha*>>& rows)
{
	//Column
	int x = location[0];
	//Row
	int y = location[1];
	//If the move is valid, the ptr is moved to new slot in the vector of vectors
	//The previous space is set to NULL
	switch (choice)
	{
	case 'A':
		if ((x - 1 > 0) && (rows[y][x - 1] == NULL))
		{
			rows[y][x - 1] = rows[y][x];
			rows[y][x] = NULL;
			location[0]--;
			std::cout << "Move successful!" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Illegal move.  Try Again." << std::endl;
			return false;
		}
	case 'W':
		if ((y - 1 > 0) && (rows[y - 1][x] == NULL))
		{
			rows[y - 1][x] = rows[y][x];
			rows[y][x] = NULL;
			location[1]--;
			std::cout << "Move successful!" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Illegal move.  Try Again." << std::endl;
			return false;
		}
	case 'S':
		if ((y + 1 < rows[x].size()) && (rows[y + 1][x] == NULL))
		{
			rows[y + 1][x] = rows[y][x];
			rows[y][x] = NULL;
			location[1]++;
			std::cout << "Move successful!" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Illegal move.  Try Again." << std::endl;
			return false;
		}
	case 'D':
		if ((x + 1 < rows.size()) && (rows[y][x + 1] == NULL))
		{
			rows[y][x + 1] = rows[y][x];
			rows[y][x] = NULL;
			location[0]++;
			std::cout << "Move successful!" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Illegal move.  Try Again." << std::endl;
			return false;
		}
	case '0':
		std::cout << "No move to perform." << std::endl;
		return true;
	}
}
//Calculate the distance between the two mechs, to determine what range is allowed for the weapons
int computeDistance(std::vector<int> location, std::vector<int> opplocation)
{
	int distance = 0;
	int a = opplocation[0] - location[0];
	int b = opplocation[1] - location[1];
	if (a < 0) 
	{
		a = (-a);
	}
	if (b < 0)
	{
		b = (-b);
	}
	distance= (int)(sqrt(pow((double)a, (double)2) + pow((double)b, (double)2)));
	return distance;
}