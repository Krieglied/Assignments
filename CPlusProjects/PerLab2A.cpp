//Performance Lab 2A
//Robert John Graham III
//August 8, 2018
//
//
//Lab 2A
//
//---
//
//Provided a text file, use the STL to read from it and count each occurrence of each word. Once complete, output to **stdout **each word, and the number of times it occurred. //Sort the output by words that occured the most to words that occured the least.
//
//You will write this program in its entirety. There will be no source code provided by the instructor, only a text file containing the input.
//
//The instructional goal of this lab is to give you practice using the STL. Use _STL containers_, _algorithms_, and _iterators_ where they would be helpful.

//Provided text file is lyrics.txt

#include <iostream>
#include <fstream>
#include <list>

void print_queue(const std::list<std::string>& queue);
int count_word(std::list<std::string>::iterator& it);

int main()
{
	std::ifstream file("lyrics.txt");
	std::string line;
	std::list<std::string> contents;
	if(file.is_open())
	{
		while (std::getline(file, line))
        	{
			std::string word;
            		for(const auto& item : line)
			{
				//std::cout << item;
				if(item != ' ')
				{
					word += item;
				}
				else
				{
					contents.push_back(word);
					word = "";
				}
			}
			contents.push_back(word);
        	}
        	file.close();
	}
	contents.sort();
	auto con_iterator = contents.begin();
	while(con_iterator != contents.end())
	{
		std::cout << "| " << *con_iterator << " | ";
		std::cout << count_word(con_iterator) << " |" << std::endl;;
	}
	//print_queue(contents);
	return 0;
}
void print_queue(const std::list<std::string>& queue)
{
	for(const auto& item : queue)
        {
                std::cout << item << std::endl;
        }
}
int count_word(std::list<std::string>::iterator& it)
{
	int count = 1;
	bool match = true;
	while(match)
	{
		if(*it == *(it++))
		{
			count++;
		}
		else
		{
			match = false;
		}
	}
	return count;
}
