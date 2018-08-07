//Practice, We're talking about Practice II
//Robert John Graham III
//August 7, 2018


#include <iostream>
#include <vector>

void add_numbers(const std::vector<int>& entity);
void sub_numbers(const std::vector<int>& entity);
void delete_specific(const std::vector<int>& entity);
void insert_specific(const std::vector<int>& entity);
void print_vector(const std::vector<int>& entity);

int main()
{
	int element;
	std::vector<int> input; 
	std::cout << "Please Enter a series of numbers, separated by spaces, end with a non-number character:  " << std::endl;
	while(std::cin >> element)
	{
		input.push_back(element);
	}
	std::cout << "Your input was : " << std::endl;
	print_vector(input);
	std::cout << "\n\n";
	add_numbers(input);
	std::cout <<"\n";
	sub_numbers(input);
	std::cout <<"\n";
	input.pop_back();
	print_vector(input);
	input.push_back(100);
	print_vector(input);
	input.insert(input.begin()+ 2, 50);
	print_vector(input);
	input.erase(input.begin()+2);
	print_vector(input);
	input.clear();
	print_vector(input);
	std::cout << " Testing input: ";
	std::cin >> element;
	std::cout << element;
	return 0;
}

void add_numbers(const std::vector<int>& entity)
{
	int result = 0;
	for(const auto& item : entity)
	{
		result += item;
	}
	std::cout << "All elements added together are : ";
	std::cout << result;	
}
void sub_numbers(const std::vector<int>& entity)
{
	int result = 0;
	for(const auto& item : entity)
	{
		result -= item;
	}
	std::cout << "All elements subtract from other is : ";
	std:: cout << result;
}
void print_vector(const std::vector<int>& entity)
{
	for(const auto& item : entity)
	{
		std::cout << item << " ";
	}
	std::cout << "\n";
}
