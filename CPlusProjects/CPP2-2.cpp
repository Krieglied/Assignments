//Practice, We're talking about Practice
//Robert John Graham III
//August 7, 2018


#include <iostream>


int main()
{
	std::string output ("Hello World!");
	auto string_len = output.length();
	std::string output_part = output.substr(0,5);
	int result = output.find("r");
	std::cout << output + "\n";
	std::cout << "The length of the string is : ";
	std::cout << string_len;
	std::cout << "\n";
	std::cout << "The substring is : ";
	std::cout << output_part;
	std::cout << "\n";
	std::cout << "The location of r is at: ";
	std::cout << result;
	std::cout << "\n";
	output_part.append("Robert");
	std::cout << "The new substring is : ";
	std::cout << output_part;
	std::cout << "\n";	
    	return 0;
}
