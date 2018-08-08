//Practice, We're talking about Practice II
//Robert John Graham III
//August 7, 2018


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>

void add_numbers(const std::vector<int>& entity);
void sub_numbers(const std::vector<int>& entity);
void delete_specific(const std::vector<int>& entity);
void insert_specific(const std::vector<int>& entity);
void print_vector(const std::vector<int>& entity);

int main()
{
	int element;
	int userInput = 99;
	std::vector<int> entity; 
	std::string input;
	std::cout << "Please Enter a series of numbers, separated by spaces, end with a non-number character:  " << std::endl;
	while(std::cin >> element)
	{
		queue.push_back(element);
	}
	std::cin.ignore(INT_MAX);
	std::cin.clear();
	input = "";
	
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
				std::cout << "All numbers added together is: " << add_numbers(entity) << std::endl;
				break;
			//
			case 2:
				std::cout << "All numbers subtract from each other is: " << sub_numbers(entity) << std::endl;
				break;
			//
			case 3:
				std::cout << entity.front() << " is deleted from the vector.\n";
				entity.pop_front();
				break;
			case 4:
				std::cout << entity.back() << " is deleted from the vector.\n";
				entity.pop_back();
				break;
			case 5:
				entity.clear();
				std::cout << "The vector has been cleared.\n";
				break;
			case 6:
				std::cout << "Enter in a number you wish to add: \n";
				while(1)
				{
					//This sections validates whether the user selected a number 0 - 4 or put in junk
					std::getline(std::cin, input);
					std::stringstream myStream(input);
					if(myStream >> element)
					{
							break;
					}
					std::cout << "Invalid number, please try again" << std::endl;
				}
				std::cout << "Do you wish to add at the front (0) or the back (1)?\n";
				while(1)
				{
					//This sections validates whether the user selected a number 0 - 4 or put in junk
					std::getline(std::cin, input);
					std::stringstream myStream(input);
					if(myStream >> userInput)
					{
							break;
					}
					std::cout << "Invalid number, please try again" << std::endl;
				}
				if(userInput == 0)
				{
					entity.push_front(element);
					std::cout << element << " was added to the front of the vector." <<std::endl;
				}
				else if(userInput == 1)
				{
					entity.push_back(element);
					std::cout << element << " was added to the back of the vector." << std::endl;
				}
				else
				{
					std::cout << "Invalid value selected." << std::endl;
				}
				break;
			case 7:
				std::cout << "Enter in a number that you would like to put into the vector: " << std::endl;
				while(1){
						//This sections validates whether the user selected a number 0 - 4 or put in junk
						std::getline(std::cin, input);
						std::stringstream myStream(input);
						if(myStream >> element)
						{
								break;
						}
						std::cout << "Invalid number, please try again" << std::endl;
				}
				std::cout << "What position would you like to insert it into? (0 - " << entity.size() << ")" << std::endl;
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
				if(userInput > entity.size())
				{
					std::cout << "Position is out-of-bounds." << std::endl;
				}
				else
				{
					entity.emplace(entity.begin() + userInput, element);
					std::cout << element << " has been added to the vector." << std::endl;
				}
				break;
			case 8:
				std::cout << "What position would you like to delete? (0 - " << entity.size() << ")" << std::endl;
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
				if(userInput > entity.size())
				{
						std::cout << "Position is out-of-bounds." << std::endl;
				}
				else
				{
						entity.erase(entity.begin() + userInput);
						std::cout << element << " has been added to the vector." << std::endl;
				}

				break;
			case 9:
				print_queue(vector);
				break;
		}
		std::cout <<"\n\n";
	}
	return 0;
}
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
	std::cout << "Delete specific element (8)\n";
	std::cout << "Print entire queue (9)\n";
	std::cout << "Exit (0)\n\n";
}
int add_numbers(const std::vector<int>& entity)
{
	int result = 0;
	for(const auto& item : entity)
	{
		result += item;
	}
	return result;
}
int sub_numbers(const std::vector<int>& entity)
{
	int result = 0;
	for(const auto& item : entity)
	{
		result -= item;
	}
	return result;
}
void print_vector(const std::vector<int>& entity)
{
	for(const auto& item : entity)
	{
		std::cout << item << " ";
	}
	std::cout << "\n";
}
