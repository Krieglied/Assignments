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


//#define DEFAULT_ADDRESS "localhost"
#define DEFAULT_PORT "4444"

#define DELIM "."

//
void printMenu();

//
int userInput(int value);

//Verifies that the user enter a valid IP
int is_valid_ip(char *ip_str);

//verifies that IP_str element is a digit from 0-9
int valid_digit(char *ip_str);

//Function that allows user to set IP address
std::string getIPaddress();
