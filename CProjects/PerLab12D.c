//Performance Lab 12D
//Robert John Graham III
//July 30, 2018

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	FILE * myFile_read_ptr = fopen("rangers.txt", "r"); // Opens a read-only file
	char readFromFile = 0; // Store char-by-char input from myFile_ptr
	char tempBuff[256] = { 0 };	// Temporary buffer to store read lines
	char * tempReturnValue = tempBuff; // Holds fgets() return value
	if (myFile_read_ptr != NULL) 	// Verify fopen() succeeded
	{
		FILE * myFile_write_ptr = fopen("thirdfile.txt", "w"); // Opens a write-to file
		while (tempReturnValue) // Continue reading until return value is NULL
		{
			tempReturnValue = fgets(tempBuff, 256, myFile_read_ptr); 	// Read the line
			if (tempReturnValue)
			{
				fputs(tempReturnValue, myFile_write_ptr); 		// Print that character
			}
		}
		fclose(myFile_read_ptr); // Always fclose anything you fopen
		fclose(myFile_write_ptr); // Always fclose anything you fopen
	}
	else 			// Otherwise, fopen() failed
	{
		puts("Error opening file!"); 	// Tell the user and...
		getchar(); getchar();
		return -1;			// Return an error value
	}
	FILE * myFile_read2_ptr = fopen("thirdfile.txt", "r"); // Opens a read-only files
	if (myFile_read2_ptr != NULL) 	// Verify fopen() succeeded
	{
		while (readFromFile != EOF) // Continue reading until the end of file
		{
			readFromFile = getc(myFile_read2_ptr); 	// Read one character
			putc(readFromFile, stdout); 		// Print that character
		}
		fclose(myFile_read2_ptr); // Always fclose anything you fopen
	}
	else 			// Otherwise, fopen() failed
	{
		puts("Error opening file!"); 	// Tell the user and...
		getchar(); getchar();
		return -1;			// Return an error value
	}

	getchar(); getchar();

	return 0;
}