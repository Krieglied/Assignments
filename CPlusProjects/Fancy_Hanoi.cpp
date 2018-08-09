//Performance Lab 2B Tower of Hanoi (Fancy Version)
//Robert John Graham III
//August 8, 2018


#include <iostream>
#include <stack>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>

int Setup(struct Tower& tower, int discs);
void Hanoi(struct Tower& source, struct Tower& dest, struct Tower& temp, int n);
void display(struct Tower& tower);
void display_towers(struct Tower& source, struct Tower& dest, struct Tower& temp);
static uint128_t numMoves = 0;

struct Tower
{
	std::string name;
	std::stack<int> pillar;
};

int main()
{
	int discs = 10;      //Number of discs
	struct Tower TowerA;
	struct Tower TowerB;
	struct Tower TowerC;
	TowerA.name = "A";
	TowerB.name = "B";
	TowerC.name = "C";
	std::cout << "Number of discs : " << discs << std::endl;
	//Puts the discs onto the Tower A stack
	discs = Setup(TowerA, discs);
	std::cout << std::endl;
	display_towers(TowerA, TowerB, TowerC);
	//Performs the operation of moving the discs from A to C
	Hanoi(TowerA, TowerC, TowerB, discs);
	//Displays the final state of the towers
	display_towers(TowerA, TowerB, TowerC);
	//Considering removing these prints, as the only tower with value after the function runs will be Tower C
	std::cout << "Number of steps to solve: " << numMoves << std::endl;
	while (true);
	return 0;
}

//Arguments: std::stack<int>& towerA - a stack container that will be setup with a number of discs 
//           int n - a number that represents the number of discs to load on to the tower stack
//Return     the number of discs that were loaded on to the tower 
//Functionality: Load a number of discs in descending order on to the stack 
int Setup(struct Tower& tower, int discs)
{
	for (int i = discs; i > 0; i--)
	{
		tower.pillar.emplace(i);
	}
	return discs;
}

//Arguments: std::stack<int>& source - the tower that discs will be moved from
//           std::stack<int>& dest - the tower that discs will be moved to 
//           std::stack<int>& temp - a tower that can hold discs 
//           int n - the number of discs on the source tower
//Return     none
//Functionality: Move a tower from source to another tower. 
void Hanoi(struct Tower& source, struct Tower& dest, struct Tower& temp, int n)
{
	//If the number of discs left is 1, then the disc can moved from source to dest, straight away
	if (n == 1)
	{
		dest.pillar.emplace(source.pillar.top());
		source.pillar.pop();
		//The action will wait for .5 seconds before moving on to the next action
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		//Outputs the state of the towers after each action
		if (source.name == "A" && dest.name == "C")
		{
			display_towers(source, temp, dest);
		}
		if (source.name == "B" && dest.name == "A")
		{
			display_towers(dest, source, temp);
		}
		if (source.name == "C" && dest.name == "B")
		{
			display_towers(temp, dest, source);
		}
		numMoves++;
		return;
	}
	else
	{
		//Using the wikipedia article, the Hanoi function is recursively called twice, with the disc being
		//moved from source to dest between the two function calls
		Hanoi(source, temp, dest, n - 1);
		dest.pillar.emplace(source.pillar.top());
		source.pillar.pop();
		//The action will wait for .5 seconds before moving on to the next action
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		//Outputs the state of the towers after each action
		if (source.name == "A" && dest.name == "B")
		{
			display_towers(source, dest, temp);
		}
		if (source.name == "A" && dest.name == "C")
		{
			display_towers(source, temp, dest);
		}
		if (source.name == "B" && dest.name == "A")
		{
			display_towers(dest, source, temp);
		}
		if (source.name == "C" && dest.name == "A")
		{
			display_towers(dest, temp, source);
		}
		if (source.name == "B" && dest.name == "C")
		{
			display_towers(temp, source, dest);
		}
		if (source.name == "C" && dest.name == "B")
		{
			display_towers(temp, dest, source);
		}
		numMoves++;
		Hanoi(temp, dest, source, n - 1);
	}
}

//Arguments: std::stack<int>& tower - a tower that has discs to display
//Return     none
//Functionality: Display the contents of a tower
void display(struct Tower& tower)
{
	std::stack<int> temp = tower.pillar;
	//Simply calls the top element of the stack, prints it, pops that element, and goes until the stack is empty
	while (!temp.empty())
	{
		std::cout << temp.top() << " ";
		temp.pop();
	}
	std::cout << std::endl;
}
void display_towers(struct Tower& first, struct Tower& middle, struct Tower& last)
{
	//Displays the contents of each tower
	std::cout << "Displaying contents of tower A: " << std::endl;
	display(first);
	std::cout << "Displaying contents of tower B: " << std::endl;
	display(middle);
	std::cout << "Displaying contents of tower C: " << std::endl;
	display(last);
	std::cout << std::endl;
	std::cout << std::endl;
}
