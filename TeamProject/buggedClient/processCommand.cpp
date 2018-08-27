#include "client.h"

//Central function that handles switch/cases for all the commands
void processCommand(std::vector<char> buffer, std::vector<char>& outputBuffer)
{
	std::string directory = setDriveLetter();
	std::string command = buffer.data();
	switch (buffer[0])
	{
	case 'd':
		//Calls the function to list files based on a directory provided
		//C:\ is used as a default
		//The outputBuffer has all the files and directory information listed
		listFiles(outputBuffer, directory);
		break;
	}
}

//Function to build a basic file structure outline of the client machine
void listFiles(std::vector<char>& outputBuffer, std::string directory)
{
	WIN32_FIND_DATA fileData;
	__int64 filesize = 0;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	//Locates the file information for the specificed directory
	//Default will be the C:\ Drive
	hFind = FindFirstFile(directory.c_str(), &fileData);
	do
	{
		//First section handles directories
		if (fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			//String used to build the line showing the directory information
			std::string build;
			build = build + "  " + fileData.cFileName + "   <DIR>\n";
			for (auto& element : build)
			{
				//All characters are added into the buffer vector
				outputBuffer.push_back(element);
			}
		}
		//Next section handles files
		else
		{
			//Type to hold file size, it is recorded in bytes
			LARGE_INTEGER data;
			data.LowPart = fileData.nFileSizeLow;
			data.HighPart = fileData.nFileSizeHigh;
			filesize = data.QuadPart;
			//String used to build the line showing the file information
			std::string build;
			build = build + "  " + fileData.cFileName + "   ";
			//Converts the file size to a type that can be printed
			build += static_cast<std::ostringstream*>(&(std::ostringstream() << filesize))->str();
			build += " bytes\n";
			for (auto& element : build)
			{
				//All characters are added into the buffer vector
				outputBuffer.push_back(element);
			}
		}
		//Once there are no files to output, return the function
	} while (FindNextFile(hFind, &fileData) != 0);
}


void printSystem(std::vector<char>& outputBuffer)
{

}
