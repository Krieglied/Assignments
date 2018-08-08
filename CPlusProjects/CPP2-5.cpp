//Practice, We're talking about Practice IV
//Robert John Graham III
//August 7, 2018


#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <climits>

void print_queue(const std::deque<int>& queue);
int add_numbers(const std::deque<int>& queue);
int sub_numbers(const std::deque<int>& queue);
void print_menu();

int main()
{
	std::deque<int> queue;
	int element;
	int userInput = 99;
	std::string input, name, job;
	std::cout << "Please enter in a series of numbers: \n";
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
				std::cout << "All numbers added together is: " << add_numbers(queue) << std::endl;
				break;
			//
			case 2:
				std::cout << "All numbers subtract from each other is: " << sub_numbers(queue) << std::endl;
				break;
			//
			case 3:
				std::cout << queue.front() << " is deleted from the queue.\n";
				queue.pop_front();
				break;
			case 4:
				std::cout << queue.back() << " is deleted from the queue.\n";
				queue.pop_back();
				break;
			case 5:
				queue.clear();
				std::cout << "The queue has been cleared.\n";
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
                                if(userInput == 0)
                                {
					queue.push_front(element);
					std::cout << element << " was added to the front of the queue." <<std::endl;
                                }
                                else if(userInput == 1)
                                {
					queue.push_back(element);
					std::cout << element << " was added to the back of the queue." << std::endl;
                                }
				else
				{
					std::cout << "Invalid value selected." << std::endl;
				}
				break;
			case 7:
				std::cout << "Enter in a number that you would like to put into the queue: " << std::endl;
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
				std::cout << "What position would you like to insert it into? (0 - " << queue.size() << ")" << std::endl;
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
				if(userInput > queue.size())
				{
					std::cout << "Position is out-of-bounds." << std::endl;
				}
				else
				{
					queue.emplace(queue.begin() + userInput, element);
					std::cout << element << " has been added to the queue." << std::endl;
				}
				break;
			case 8:
				std::cout << "What position would you like to delete? (0 - " << queue.size() << ")" << std::endl;
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
                                if(userInput > queue.size())
                                {
                                        std::cout << "Position is out-of-bounds." << std::endl;
                                }
                                else
                                {
                                        queue.erase(queue.begin() + userInput);
                                        std::cout << element << " has been added to the queue." << std::endl;
                                }

				break;
			case 9:
				print_queue(queue);
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
	std::cout << "Delete specific element (8)\n";
	std::cout << "Print entire queue (9)\n";
	std::cout << "Exit (0)\n\n";
}
void print_queue(const std::deque<int>& queue)
{
	//The map consists of two items in each element
	for(const auto& item : queue)
	{
		std::cout << item << " ";
	}
	std::cout << "\n";
}
int add_numbers(const std::deque<int>& queue)
{
	int result = 0;
	for(const auto& item : queue)
	{
		result += item;
	}
	return result;
}
int sub_numbers(const std::deque<int>& queue)
{
	int result = 0;
	for(const auto& item : queue)
	{
		result -= item;
	}
	return result;
}
