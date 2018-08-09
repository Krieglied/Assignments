//Performance Lab 2A
//Robert John Graham III
//August 9, 2018

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

void find_word(const std::string& input, std::map< std::string, int>& map);

//This is a comparison section for the second element (the value of the map)
struct comp
{
	template<typename T>
	bool operator()(const T& l, const T& r) const
	{
		//The count (value portion of the element) is sort higher value to lower values
		if (l.second != r.second)
		{
			return l.second > r.second;
		}
		//If the count is equal between the two elements, then the elements are sorted by the string (key portion of the element)
		return l.first > r.first;
	}
};

int main()
{
	//Input text file
	std::ifstream file("textInput.txt");
	std::string line;
	std::map< std::string, int> output;
	int entry = 1;
	if (file.is_open())
	{
		//The file is looked at,line by line
		while (std::getline(file, line))
		{
			std::string word;
			//Each line is going to consist of words, so character by character is looked at
			for (const auto& item : line)
			{
				//If the character is not blank, then add the character to the current word
				if (item != ' ')
				{
					word += item;
				}
				//If it is blank, then the word is added to the map and the word is reset
				else
				{
					//find_word(word, output);
					word = "";
					output.emplace(word, entry++); 
				}
			}
			//End of line has been reached, the last word waiting needs to be added to the map
			//find_word(word, output);
			output.emplace(word, entry++);
		}
	}
	//The map is moved to set, sorting it by the value and then the key, higher values to lower values
	std::set<std::pair<std::string, int>, comp> set(output.begin(), output.end());
	for (const auto& item : output)
	{
		std::cout << item.first <<std::endl;
	}
	while (true);
	return 0;
}
void find_word(const std::string& input, std::map< std::string, int>& map)
{
	//Here the map is searched to see if the key has already been input
	auto search = map.find(input);
	//If the word has been found(i.e. iterator is not equal to the end iterator), then the value++
	if (search != map.end())
	{
		search->second++;
	}
	//Otherwise, the word needs to be added to the map (with a value of 1, of course)
	else
	{
		map.emplace(input, 1);
	}
}
