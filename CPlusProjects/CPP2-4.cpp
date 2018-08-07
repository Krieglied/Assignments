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
	int userInput = 99;
	while(userInput != 0)
	{
		print_menu();
		while(1){
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
			case 1:
				std::cout << "Please enter in a name: " << std::endl;
				std::getline(std::cin, name);
				std::cout << "\nPlease enter in a job title: " << std::endl;
				std::getline(std::cin, job);
				person.emplace(name, job);
				break;
			case 2:
				std::map<std::string, std::string>::iterator findPerson;
				std::cout << "Please enter in a name to find: " << std::endl;
				std::getline(std::cin, name);
				findPerson = person.find(name);
				if(findPerson == person.end())
				{
					std::cout << "Person not found";
				}
				else
				{
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
		}
		std::cout <<"\n\n";
	}
	print_map(person);
	return 0;
}
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
	for(const auto& item : person)
	{
		std::cout << item.first << " " << item.second << "\n";
	}
}	
