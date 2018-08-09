//Performance Lab 2B Tower of Hanoi
//Robert John Graham III
//August 8, 2018


#include <iostream>
#include <stack>
#include <vector>
#include <ctime>

int Setup(std::stack<int>& tower, int n);
void Hanoi(std::stack<int>& source, std::stack<int>& dest, std::stack<int>&, int n);
void display(std::stack<int> tower);
static unsigned long long numMoves = 0;

int main()
{
	int discs = 1;      //Number of discs
	clock_t begin;		//This for monitioring performance, as the algorithms starts to take a while to perform
	clock_t end;
	while (discs < 101)
	{
		begin = clock();
		std::stack<int> TowerA;
		std::stack<int> TowerB;
		std::stack<int> TowerC;

		std::cout << "Number of discs : " << discs << std::endl;
		//Puts the discs onto the Tower A stack
		discs = Setup(TowerA, discs);
		//Performs the operation of moving the discs from A to C
		Hanoi(TowerA, TowerC, TowerB, discs);
		//Considering removing these prints, as the only tower with value after the function runs will be Tower C
		std::cout << "Displaying contents of tower A: " << std::endl;
		display(TowerA);
		std::cout << "Displaying contents of tower B: " << std::endl;
		display(TowerB);
		std::cout << "Displaying contents of tower C: " << std::endl;
		display(TowerC);
		std::cout << "Number of steps to solve: " << numMoves << std::endl;
		//Increases the number of discs for the next run
		discs++;
		end = clock();
		//Performance run time
		std::cout << "This run took " << double(end - begin) / CLOCKS_PER_SEC << " seconds." << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	while (true);
	return 0;
}

//Arguments: std::stack<int>& towerA - a stack container that will be setup with a number of discs 
//           int n - a number that represents the number of discs to load on to the tower stack
//Return     the number of discs that were loaded on to the tower 
//Functionality: Load a number of discs in descending order on to the stack 
int Setup(std::stack<int>& tower, int discs)
{
	for (int i = discs; i > 0; i--)
	{
		tower.emplace(i);
	}
	return discs;
}

//Arguments: std::stack<int>& source - the tower that discs will be moved from
//           std::stack<int>& dest - the tower that discs will be moved to 
//           std::stack<int>& temp - a tower that can hold discs 
//           int n - the number of discs on the source tower
//Return     none
//Functionality: Move a tower from source to another tower. 
void Hanoi(std::stack<int>& source, std::stack<int>& dest, std::stack<int>& temp, int n)
{
	//If the number of discs left is 1, then the disc can moved from source to dest, straight away
	if (n == 1)
	{
		dest.emplace(source.top());
		source.pop();
		numMoves++;
		return;
	}
	else
	{
		//Using the wikipedia article, the Hanoi function is recursively called twice, with the disc being
		//moved from source to dest between the two function calls
		Hanoi(source, temp, dest, n - 1);
		dest.emplace(source.top());
		source.pop();
		numMoves++;
		Hanoi(temp, dest, source, n - 1);
	}
}

//Arguments: std::stack<int>& tower - a tower that has discs to display
//Return     none
//Functionality: Display the contents of a tower
void display(std::stack<int> tower)
{
	//Simply calls the top element of the stack, prints it, pops that element, and goes until the stack is empty
	while (!tower.empty())
	{
		std::cout << tower.top() << " ";
		tower.pop();
	}
	std::cout << std::endl;
}
