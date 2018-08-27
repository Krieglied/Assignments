#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS 1

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <sstream>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_ADDRESS "localhost"
#define DEFAULT_PORT "4444"

void printMenu();
int userInput(int value);

int __cdecl main(int argc, char **argv)
{
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;
	int iResult;
	int	cmdChoice = 99;

	// Initialize Winsock
	// Very necessary to make the socket work
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

	// Resolve the server address and port
	iResult = getaddrinfo(DEFAULT_ADDRESS, DEFAULT_PORT, &hints, &result);
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
	//Could not get a connection to the client
	if (ConnectSocket == INVALID_SOCKET)
	{
		std::cout << "Unable to connect to client!" << std::endl;
		WSACleanup();
		return 1;
	}

	std::cout << "Ready to start sending commands" << std::endl;
	std::string commands;
	//These variables are used to store results from the client
	std::stringstream input;
	char newbuffer[4096 * 2];
	do
	{
		//Handles the user input for which command to run
		do
		{
			printMenu();
			//Handles user input, if not a number, send back as invalid
			cmdChoice = userInput(cmdChoice);
			//If not is range of the commands, send back as invalid
			if (!(cmdChoice >= 0 && cmdChoice < 2))
			{
				std::cout << "Invalid number, please try again" << std::endl;
			}
			//Continue loop until user makes a valid choice
		} while (!(cmdChoice >= 0 && cmdChoice < 2));
		// Might make this section a switch case that will build the command string (represented here by test)
		// That will be sent on the socket to the client
		if (cmdChoice == 1)
		{
			std::string test = "d";
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
			//This section will handle any input that the client sends back
			char checkChar;
			do
			{
				iResult = recv(ConnectSocket, newbuffer, sizeof(newbuffer), 0);
				checkChar = newbuffer[0];
				//If the result is of the size of an int (<= 4 bytes) and is of value 0, then the client has 
				//finished the return message
				if (iResult <= 4 && checkChar == 0)
				{
					break;
				}
				//If message not finished, characters are put into a string stream.
				for (int i = 0; i < iResult; i++)
				{
					input << newbuffer[i];
				}
				//The buffer is clear for the next package
				memset(newbuffer, 0, sizeof(newbuffer));
			} while (true);
			std::cout << input.str() << std::endl;
			std::cout << "data has been received." << std::endl;
		}
		//Input from the client is complete, string stream needs to be reset
		input.str(std::string());
		input.clear();
	} while (cmdChoice != 0);

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
// Function that will display to the user a list of commands to run on client
void printMenu()
{
	std::cout << "Please select a command:" << std::endl;
	std::cout << "Test Command (1)" << std::endl;
	std::cout << "Exit (0)" << std::endl;
}
//Determines if the user input a correct command
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