//Practice, We're talking about Practice IV
//Robert John Graham III
//August 7, 2018


#include <iostream>
#include <deque>
#include <string>
#include <sstream>

void print_map(const std::deque<int> queue);
void print_menu();

int main()
{
	std::deque<int> queue;
	int element;
	std::cout << "Please enter in a series of numbers: \n";
	int userInput = 99;
	std::string input, name, job;
	std::getline(std::cin, input);
	std::istringstream 
	for(std::string line; std::getline(input, line);)
	{
		element = std::stoi(line);
		std::cout << element << "\n";
		queue.push_back(element);
	}
	//This variable will control for the program, and the user gets 5 choices
	while(userInput != 0)
	{
		print_menu();
		while(1){
			//This sections validates whether the user selected a number 0 - 4 or put in junk
			std::getline(std::cin, input);
			std::stringstream myStream(input);
			if(myStream >> userInput)
			{
				break;
			}
			std::cout << "Invalid number, please try again" << std::endl;
		}
		switch(userInput)
		{
			//If the user selected 1, 
			case 1:
				std::cout << "Please enter in a name: " << std::endl;
				std::getline(std::cin, name);
				std::cout << "\nPlease enter in a job title: " << std::endl;
				std::getline(std::cin, job);
				break;
			//
			case 2:
				std::cout << "Please enter in a name to find: " << std::endl;
				std::getline(std::cin, name);
				//person.end() is the out-of-bound condition, which indicates item not found
				break;
			//
			case 3:
				std::cout << "\n";
				std::cout << "Which person do you want to delete?" << std::endl;
				std::getline(std::cin, name);
				break;
			case 4:
				break;
		}
		std::cout <<"\n\n";
	}
	return 0;
}
//
void print_menu()
{
	std::cout << "Please select from the following choices: \n";
	std::cout << "Add numbers together (1)\n";
	std::cout << "Subtract Numbers(2)\n";
	std::cout << "Delete first element(3)\n";
	std::cout << "Delete last element(4)\n";
	std::cout << "Clear queue (5)\n";
	std::cout << "Add new element (6)\n";
	std::cout << "Insert new element (7)\n";
	std::cout << "Delete specific elemtn (8)\n";
	std::cout << "Exit (0)\n\n";
}
void print_map(const std::deque<int> queue)
{
	//The map consists of two items in each element
	for(const auto& item : queue)
	{
		std::cout << item << "\n";
	}
}	
