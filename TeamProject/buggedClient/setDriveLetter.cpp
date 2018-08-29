#include "client.h"

std::string setDriveLetter()
{
	std::string tempDrive;	//temp choice for drive
	std::string tempLetter;
	std::string directory = "C:\\";
	std::string logicalDisks;	 
	std::cout << "Available drives" << std::endl;
	std::cout << "----------------" << std::endl;
	system("wmic logicaldisk get name");
	std::cout << "Current drive is " << directory << std::endl; //Displays current drive
	std::cout << "Would you like to change drives(Y/N)? ";	//Prompts user for change if desired
	std::getline(std::cin, tempDrive);//Takes in user's choice 
	
	//If users choice is any of the below options, user chooses new letter
	if (tempDrive == "y" || tempDrive == "Y" || tempDrive == "yes" || tempDrive == "Yes" || tempDrive == "YES")
	{
		std::cout << "Enter the new drive letter: ";	//Accepts new drive letter
		std::cin >> tempLetter;
		std::cin.clear();
		//Error checking for new drive letter
		if (isLetters(tempLetter) == false) //checks tempLetter to see if a letter
		{
			std::cout << "You entered invalid characters!" << std::endl;
			setDriveLetter(); //invalid character entry recalls setDriveLetter function
		}
		else
		{
			if (choseAvailableDrive(tempLetter) == true) //Makes sure the user didn't select a non-available drive
			{
				if (tempLetter[0] > 64 && tempLetter[0] <= 90) //Checks if letter is already uppercase
				{
					std::string newDirectory = tempLetter + ":\\"; //Builds directory structure
					directory = newDirectory; //sets return directory equal the one built above
				}
				else if (tempLetter[0] > 96 && tempLetter[0] <= 122)
				{
					char castLetter = tempLetter[0] - 32; //castLetter is a temp variable, to allow string character to change to uppercase
					tempLetter[0] = castLetter;	//This is to set tempLetter equal to the Uppercase letter above
					std::string newDirectory = tempLetter + ":\\";	//Builds directory structure
					directory = newDirectory; //sets return directory equal the one built above
				}
			}					
		}
	}
	else
	{
		directory = ("C:\\");
	}
	return directory;
}

bool choseAvailableDrive(std::string input)
{
	if (input == "c" || input == "C")
	{
		return true;
	}
	else if (input == "d" || input == "D")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isLetters(std::string input)
{
	for (int i = 0; i < 1; i++)
	{
		int uppercaseChar = input[i]; //Convert character to upper case version of character
		if (uppercaseChar < 'A' && uppercaseChar > 'Z' || uppercaseChar < 'a' && uppercaseChar > 'z') //If character is not A-Z or a-z
		{
			return false;
		}
	}
	//At this point, we have gone through every character and checked it.
	return true; //Return true since every character had to be A-Z
}

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