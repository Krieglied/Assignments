//Performance Lab 12C
//Robert John Graham III
//July 30, 2018

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	FILE * myFile_read_ptr = fopen("rangers.txt", "r"); // Opens a read-only file
	char readFromFile = 0; // Store char-by-char input from myFile_ptr
	if (myFile_read_ptr != NULL) 	// Verify fopen() succeeded
	{
		FILE * myFile_write_ptr = fopen("secondfile.txt", "w"); // Opens a write-to file
		while (readFromFile != EOF) // Continue reading until the end of file
		{
			readFromFile = getc(myFile_read_ptr); 	// Read one character
			if (readFromFile != EOF)
			{
				putc(readFromFile, myFile_write_ptr); 		// Print that character
			}
		}
		putc(EOF, myFile_write_ptr); 		// Print that character
		fclose(myFile_read_ptr); // Always fclose anything you fopen
		fclose(myFile_write_ptr); // Always fclose anything you fopen
	}
	else 			// Otherwise, fopen() failed
	{
		puts("Error opening file!"); 	// Tell the user and...
		getchar(); getchar();
		return -1;			// Return an error value
	}
	FILE * myFile_read2_ptr = fopen("secondfile.txt", "r"); // Opens a read-only file
	readFromFile = 0; // Store char-by-char input from myFile_ptr
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