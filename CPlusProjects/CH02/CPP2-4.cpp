//Practice, We're talking about Practice III
//Robert John Graham III
//August 7, 2018


#include <iostream>
#include <map>
#include <string>
#include <sstream>

void print_map(const std::map<std::string, std::string>& person);
void print_menu();

int main()
{
	std::string input;
	std::string name, job;
	std::map<std::string, std::string> person;
	std::map<std::string, std::string>::iterator findPerson;
	int userInput = 99;
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
			//If the user selected 1, first a name gets asked for, then job title, and then that information is placed into the map
			case 1:
				std::cout << "Please enter in a name: " << std::endl;
				std::getline(std::cin, name);
				std::cout << "\nPlease enter in a job title: " << std::endl;
				std::getline(std::cin, job);
				person.emplace(name, job);
				break;
			//The find case sets up an iterator on the map and returns the position if the name is found
			case 2:
				std::cout << "Please enter in a name to find: " << std::endl;
				std::getline(std::cin, name);
				findPerson = person.find(name);
				//person.end() is the out-of-bound condition, which indicates item not found
				if(findPerson == person.end())
				{
					std::cout << "Person not found";
				}
				else
				{
					//If selection is found, user will be prompted if they want to delete selection
					std::cout << name << " found.  Would you like to delete this user(Y) or (N)?";
					std::getline(std::cin, input);
					if(toupper(input[0]) == 'Y')
					{
						person.erase(findPerson);
						std::cout << name << " deleted.";
					}
					else
					{
						std::cout << name << " not deleted.";
					}
				}
				break;
			//Whole map gets printed to let the user know what is available.
			//User can delete selection based on that
			case 3:
				print_map(person);
				std::cout << "\n";
				std::cout << "Which person do you want to delete?" << std::endl;
				std::getline(std::cin, name);
				if(findPerson == person.end())
				{
					std::cout << "Person not found." << std::endl;
				}
				else
				{
					person.erase(findPerson);
					std::cout << name << " deleted.";
				}
				findPerson = person.find(name);
				break;
			//Whole map is printed
			case 4:
				print_map(person);
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
	std::cout << "Enter in a person and job (1)\n";
	std::cout << "Find a person, by name (2)\n";
	std::cout << "Delete a person, by name (3)\n";
	std::cout << "Print all person (4)\n";
	std::cout << "Exit (0)\n\n";
}
void print_map(const std::map<std::string, std::string>& person)
{
	//The map consists of two items in each element
	for(const auto& item : person)
	{
		std::cout << item.first << " " << item.second << "\n";
	}
}	
