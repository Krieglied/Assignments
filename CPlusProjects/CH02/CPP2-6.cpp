//Practice, We're talking about Practice IV
//Robert John Graham III
//August 7, 2018


#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <climits>

void print_list(const std::list<char>& llist);
void print_menu();

int main()
{
	std::list<char> llist;
	char element;
	int userInput = 99;
	std::string input;
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
				std::cout << "Please input a character into the list: " << std::endl;
				while(true)
				{
					std::getline(std::cin, input);
					std::stringstream myStream(input);
					if(myStream >> element)
					{
						break;
					}
					std::cout << "Invalid input, please try again" << std::endl;
				}
				llist.push_back(element);
				std::cout << "list is now of size " << llist.size() << std::endl;
				break;
			//
			case 2:
				llist.pop_back();
				std::cout << "list is now of size " << llist.size() << std::endl;
				break;
			//
			case 3:
				print_list(llist);
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
	std::cout << "Add Character to List(1)\n";
	std::cout << "Pop Character from List(2)\n";
	std::cout << "Print Characters from List(3)\n";
	std::cout << "Exit (0)\n\n";
}
void print_list(const std::list<char>& llist)
{
	//The map consists of two items in each element
	for(const auto& item : llist)
	{
		std::cout << item << "\n";
	}
}
