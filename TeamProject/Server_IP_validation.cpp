
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>


// Program to check if a given string is valid IPv4 address or not
#define DELIM "."

/* return 1 if string contains only digits, else return 0 */
int valid_digit(char *ip_str)
{
	while (*ip_str) {
		if (*ip_str >= '0' && *ip_str <= '9')
			++ip_str;
		else
			return 0;
	}
	return 1;
}

/* return 1 if IP string is valid, else return 0 */
int is_valid_ip(char *ip_str)
{
	int i, num, dots = 0;
	char *ptr;

	if (ip_str == NULL)
		return 0;

	ptr = strtok(ip_str, DELIM);

	if (ptr == NULL)
		return 0;

	while (ptr) {

		/* after parsing string, it must contain only digits */
		if (!valid_digit(ptr))
		{
			std::cout << "ERROR:  Invalid Input" << std::endl;
			return 0;
		}

		num = atoi(ptr);

		/* check for valid IP */
		if (num >= 0 && num <= 255) {
			/* parse remaining string */
			ptr = strtok(NULL, DELIM);
			if (ptr != NULL)
				++dots;
		}
		else
		{
			std::cout << "ERROR:  Invalid Input" << std::endl;
			return 0;
		}
	}

	/* valid IP string must contain 3 dots */
	if (dots != 3)
	{
		std::cout << "ERROR:  Invalid Input" << std::endl;
		return 0;
	}
	return 1;
}
int main()
{
	std::string inputIP;
	int n = inputIP.length();
	while (inputIP != "exit")
	{
				
		std::cout << "Enter IPv4 address of the client you wish to connect to:  (i.e. 10.111.2.113)" << std::endl;
		
		while (1)
		{
			std::cin >> inputIP;

			int n = inputIP.length();
			if (n > 15)
			{
				std::cout << "\nERROR:  Invalid Input, too many numbers/characters.  Acceptable range is 0.0.0.0 through 255.255.255.255\n" << std::endl;
				break;
			}

			std::cout << "IP address input is:  ";
			char inputIParray[16] = { 0 };

			strcpy(inputIParray, inputIP.c_str());

			for (int i = 0; i < n; i++)
			{
				std::cout << inputIParray[i];
			}

			std::cout << std::endl;

			is_valid_ip(inputIParray) ? std::cout << "IPv4 Address:  " << inputIP << "  Accepted" << std::endl : std::cout << "Invalid IPv4 Address.  Acceptable range is 0.0.0.0 through 255.255.255.255" << std::endl;
			std::cout << "\n=====================================================\n";
		}
	}
	while (1);
	return 0;
}