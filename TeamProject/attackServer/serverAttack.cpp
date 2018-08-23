#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


//#define DEFAULT_ADDRESS "localhost"
#define DEFAULT_PORT "4444"

#define DELIM "."

void printMenu();
int userInput(int value);
int is_valid_ip(char *ip_str);
int valid_digit(char *ip_str);

int __cdecl main(int argc, char **argv)
{
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;
	std::vector<char> buffer(5000);
	int iResult;
	int	cmdChoice = 99;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		std::cout << "WSAStartup failed with error: " << iResult << std::endl;
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	//Get IP address
	std::string inputIP;
	int n = inputIP.length();
	char inputIParray[16] = { 0 };
	int z = 1;
	while (z == 1)
	{
		while (1)
		{
			std::cout << "Enter IPv4 address of the client you wish to connect to:  (i.e. 10.111.2.113)" << std::endl;
			std::cin >> inputIP;
			int n = inputIP.length();
			if (n < 16)
			{
				std::cout << "IPv4 address input is:  ";

				//copy string into char array for validation function input
				strcpy(inputIParray, inputIP.c_str());
				for (int i = 0; i < n; i++)
				{
					std::cout << inputIParray[i];
				}
				std::cout << std::endl;
				if (is_valid_ip(inputIParray))
				{
					std::cout << "IPv4 Address:  " << inputIP << "  Accepted" << std::endl;
					z = 0;
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
	//test print
	std::cout << "loop ended" << std::endl;

	// Resolve the server address and port
//	iResult = getaddrinfo(DEFAULT_ADDRESS, DEFAULT_PORT, &hints, &result);
	iResult = getaddrinfo(inputIParray, DEFAULT_PORT, &hints, &result);
	if (iResult != 0)
	{
		std::cout << "WSAStartup failed with error: " << iResult << std::endl;
		WSACleanup();
		return 1;
	}

	// Attempt to connect to an address until one succeeds
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
	{

		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET)
		{
			std::cout << "socket failed with error: " << WSAGetLastError() << std::endl;
			WSACleanup();
			return 1;
		}

		// Connect to server.
		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR)
		{
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET)
	{
		std::cout << "Unable to connect to server!" << std::endl;
		WSACleanup();
		return 1;
	}
	std::cout << "Ready to start sending commands" << std::endl;
	std::string commands;
	do
	{
		std::vector<char> inputBuffer(5000);
		do
		{
			printMenu();
			//Handles user input, if not a number, send back as invalid
			cmdChoice = userInput(cmdChoice);
			//If not is range of the mech number, send back as invalid
			if (!(cmdChoice >= 0 && cmdChoice < 2))
			{
				std::cout << "Invalid number, please try again" << std::endl;
			}
			//Continue loop until user makes a valid choice
		} while (!(cmdChoice >= 0 && cmdChoice < 2));
		if (cmdChoice == 1)
		{
			std::string test = "dir";
			// Send an initial buffer
			iResult = send(ConnectSocket, test.data(), test.size(), 0);
			if (iResult == SOCKET_ERROR)
			{
				std::cout << "send failed with error: " << WSAGetLastError() << std::endl;
				closesocket(ConnectSocket);
				WSACleanup();
				return 1;
			}
			std::cout << "Bytes Sent: " << iResult << std::endl;

			iResult = recv(ConnectSocket, inputBuffer.data(), inputBuffer.size(), 0);
			std::cout << "data has been received." << std::endl;
			if (iResult != -1)
			{
				inputBuffer.resize(iResult);
			}
			if (iResult != 0)
			{
				std::cout << inputBuffer.data() << std::endl;
			}
		}
		//Here is where test server code will go
	} while (cmdChoice != 0);

	std::cout << "Bytes Sent: " << iResult << std::endl;

	// shutdown the connection since no more data will be sent
	iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR)
	{
		std::cout << "shutdown failed with error: " << WSAGetLastError() << std::endl;
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	// cleanup
	closesocket(ConnectSocket);
	WSACleanup();

	return 0;
}
void printMenu()
{
	std::cout << "Please select a command:" << std::endl;
	std::cout << "Test Command (1)" << std::endl;
	std::cout << "Exit (0)" << std::endl;
}
int userInput(int value)
{
	//Handles user input from the console
	std::string input;
	while (true) {
		std::getline(std::cin, input);
		std::stringstream myStream(input);
		if (myStream >> value)
		{
			break;
		}
		std::cout << "Invalid number, please try again" << std::endl;
	}
	return value;
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
			//std::cout << "ERROR:  Invalid Input" << std::endl;
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
			//std::cout << "ERROR:  Invalid Input" << std::endl;
			return 0;
		}
	}

	/* valid IP string must contain 3 dots */
	if (dots != 3)
	{
		//std::cout << "ERROR:  Invalid Input" << std::endl;
		return 0;
	}
	return 1;
}