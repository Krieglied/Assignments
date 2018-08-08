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
a//Performance Lab 2A
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
#include <string>
#include <list>
#include <map>

int count_word(std::list<std::string>::iterator& it, const std::list<std::string>::iterator& end);

int main()
{
	//Input text file
	std::ifstream file("lyrics.txt");
	std::string line;
	std::list<std::string> contents;
	std::map< std::string, int> output;
	if (file.is_open())
	{
		//The file is looked line by line
		while (std::getline(file, line))
		{
			std::string word;
			//Each line is going to consist of words, so if character by character is looked at
			for (const auto& item : line)
			{
				//If the character is not blank, then add the character to the current word
				if (item != ' ')
				{
					word += item;
				}
				//If it is blank, then the word is added to the list, and word is reset
				else
				{
					contents.push_back(word);
					word = "";
				}
			}
			//If the line is at the end, then the last word needs to added to the list
			contents.push_back(word);
		}
		file.close();
	}
	//List is sorted
	contents.sort();
	//This iterator will be sent to the function
	auto con_iterator = contents.begin();
	//This loop needs to be changed to translate list to map with <int, string>
	while (con_iterator != contents.end())
	{
		std::string word = *con_iterator;
		output.emplace(word, count_word(con_iterator, contents.end()));
		//std::cout << "| " << *con_iterator << " | ";
		//std::cout << count_word(con_iterator) << " |" << std::endl;;
	}
	while (1);
	return 0;
}
int count_word(std::list<std::string>::iterator& it, const std::list<std::string>::iterator& end)
{
	//Start at 1, because by virtue of passing the iterator, there is already at least 1
	int count = 1;
	bool match = true;
	std::list<std::string>::iterator& test = it;
	while (match)
	{
		if (test++ == end)
		{
			break;
		}
		//If next slot matches, then count needs to be increased
		//And this line will increase the iterator
		if (*it == *(test++))
		{
			count++;
		}
		//Otherwise, break loop to return count
		else
		{
			match = false;
		}
		it++;
	}
	return count;
}
int count_word(std::list<std::string>::iterator& it);

int main()
{
	//Input text file
	std::ifstream file("lyrics.txt");
	std::string line;
	std::list<std::string> contents;
	if(file.is_open())
	{
		//The file is looked line by line
		while (std::getline(file, line))
        {
			std::string word;
			//Each line is going to consist of words, so if character by character is looked at
            for(const auto& item : line)
			{
				//If the character is not blank, then add the character to the current word
				if(item != ' ')
				{
					word += item;
				}
				//If it is blank, then the word is added to the list, and word is reset
				else
				{
					contents.push_back(word);
					word = "";
				}
			}
			//If the line is at the end, then the last word needs to added to the list
			contents.push_back(word);
        }
        file.close();
	}
	//List is sorted
	contents.sort();
	//This iterator will be sent to the function
	auto con_iterator = contents.begin();
	//This loop needs to be changed to translate list to map with <int, string>
	while(con_iterator != contents.end())
	{
		std::cout << "| " << *con_iterator << " | ";
		std::cout << count_word(con_iterator) << " |" << std::endl;;
	}
	return 0;
}
int count_word(std::list<std::string>::iterator& it)
{
	//Start at 1, because by virtue of passing the iterator, there is already at least 1
	int count = 1;
	bool match = true;
	while(match)
	{
		//If next slot matches, then count needs to be increased
		//And this line will increase the iterator
		if(*it == *(it++))
		{
			count++;
		}
		//Otherwise, break loop to return count
		else
		{
			match = false;
		}
	}
	return count;
}
