#include <iostream>
#include <stack>
#include <vector>

int Setup(std::stack<int>& tower, int n);
void Hanoi(std::stack<int>& source, std::stack<int>& dest, std::stack<int>&, int n);
void display(std::stack<int> tower);
static int numMoves = 0;

int main()
{
	std::stack<int> TowerA;
	std::stack<int> TowerB;
	std::stack<int> TowerC;

	int n = 0;      //Number of discs 

	n = Setup(TowerA, n);
	Hanoi(TowerA, TowerB, TowerC, n);
	std::cout << "Displaying contents of tower A: " << std::endl;
	display(TowerA);
	std::cout << "Displaying contents of tower B: " << std::endl;
	display(TowerB);
	std::cout << "Displaying contents of tower C: " << std::endl;
	display(TowerC);
	std::cout << "Number of steps to solve: " << n << std::endl;
	while (true);
	return 0;

}

//Arguments: std::stack<int>& towerA - a stack container that will be setup with a number of discs 
//           int n - a number that represents the number of discs to load on to the tower stack
//Return     the number of discs that were loaded on to the tower 
//Functionality: Load a number of discs in ascending order on to the stack 
int Setup(std::stack<int>& tower, int n)
{
	for (int i = 0; i < n; i++)
	{
		tower.push(i);
	}
	return n;
}

//Arguments: std::stack<int>& source - the tower that discs will be moved from
//           std::stack<int>& dest - the tower that discs will be moved to 
//           std::stack<int>& temp - a tower that can hold discs 
//           int n - the number of discs on the source tower
//Return     none
//Functionality: Move a tower from source to another tower. 
void Hanoi(std::stack<int>& source, std::stack<int>& dest, std::stack<int>& temp, int n)
{

}

//Arguments: std::stack<int>& tower - a tower that has discs to dispay
//Return     none
//Functionality: Display the contents of a tower
void display(std::stack<int> tower)
{

}
