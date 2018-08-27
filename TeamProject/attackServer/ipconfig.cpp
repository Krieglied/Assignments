#include "server.h"

std::string getIPaddress()
{
	//Get IP address
	std::string inputIP;
	char inputIParray[16] = { 0 };
	int z = 1;
	while (z == 1)
	{
		while (1)
		{
			std::cout << "Enter IPv4 address of the client you wish to connect to:  (i.e. 10.111.2.113)" << std::endl;
			std::getline(std::cin, inputIP);
			int n = inputIP.length();
			if (n < 16)  //ensure input is not longer than 15 elements
			{
				std::cout << "IPv4 address input is:  ";

				//copy string into char array for validation function input
				strcpy(inputIParray, inputIP.c_str());
				for (int i = 0; i < n; i++)
				{
					std::cout << inputIParray[i];  //prints out IP address from the char array
				}
				std::cout << std::endl;
				if (is_valid_ip(inputIParray))  //checks it input IP is valid
				{
					std::cout << "IPv4 Address:  " << inputIP << "  Accepted" << std::endl;
					z = 0; //changes value of z to continue past while loop once IP has been validated
					break;
				}
				else
				{
					std::cout << "Invalid IPv4 Address.  Acceptable range is 0.0.0.0 through 255.255.255.255" << std::endl;
				}
			}
			else
			{
				std::cout << "\nERROR:  Invalid IPv4 Input, too many numbers/characters.  Acceptable range is 0.0.0.0 through 255.255.255.255\n" << std::endl;
			}
		}
	}
	return inputIP;  //returns original IP input after it's been validated
}
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
			return 0;
		}
	}

	/* valid IP string must contain 3 dots */
	if (dots != 3)
	{
		return 0;
	}
	return 1;
}