//Performance Lab 12E
//Robert John Graham III
//July 30, 2018

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	//Variables to be used for the exercise
	int numberStudents = 0;
	char firstName[256] = { 0 };
	char middleName[256] = { 0 };
	char lastName[256] = { 0 };
	char outputString[256] = { 0 };
	//If the user keeps putting in a non-valid value, repeat the loop
	while (numberStudents <= 0)
	{
		printf("Please enter the number of students: ");
		scanf("%d", &numberStudents);
	}
	FILE * myFile_write_ptr = fopen("usernames.txt", "w"); // Opens a write-to file
	//For each student, grab the first, middle, and last name
	for (int i = 0; i < numberStudents; i++)
	{
		printf("Please enter students first name: ");
		scanf("%255s", &firstName);
		int iterator = 0;
		while (*(firstName + iterator) != '\0')
		{
			//Here a check is made if the user input a newline character, in which case it is removed
			if (*(firstName + iterator) == '\n')
			{
				memmove(firstName + iterator, firstName + iterator + 1, strlen(firstName) - iterator);
			}
			iterator++;
		}
		printf("Please enter students middle name: ");
		scanf("%255s", &middleName);
		iterator = 0;
		while(*(middleName + iterator) !='\0')
		{
			//Here a check is made if the user input a newline character, in which case it is removed
			if (*(middleName + iterator) == '\n')
			{
				memmove(middleName + iterator, middleName + iterator + 1, strlen(middleName) - iterator);
			}
			iterator++;
		}
		printf("Please enter students last name: ");
		scanf("%255s", &lastName);
		iterator = 0;
		while (*(lastName + iterator) != '\0')
		{
			//Here a check is made if the user input a newline character, in which case it is removed
			if (*(lastName + iterator) == '\n')
			{
				memmove(lastName + iterator, lastName + iterator + 1, strlen(lastName) - iterator);
			}
			iterator++;
		}
		
		//Here the string to output to the file is built
		int position = 0;
		//The format outputted is (First Name) (Middle Inital). (Last Name) has a username of
		//(first initial)(middle initial)(last name)
		outputString[position++] = toupper(firstName[0]);
		for (int i = 1; i < strlen(firstName); i++)
		{
			outputString[position++] = firstName[i];
		}
		outputString[position++] = ' ';
		outputString[position++] = toupper(middleName[0]);
		outputString[position++] = '.';
		outputString[position++] = ' ';
		outputString[position++] = toupper(lastName[0]);
		for (int i = 1; i < strlen(lastName); i++)
		{
			outputString[position++] = lastName[i];
		}
		outputString[position++] = ' ';//Concatenation doesnt seem to work, so the characters need to be added manually, one
		outputString[position++] = 'h';//at a time
		outputString[position++] = 'a';
		outputString[position++] = 's';
		outputString[position++] = ' ';
		outputString[position++] = 'a';
		outputString[position++] = ' ';
		outputString[position++] = 'u';
		outputString[position++] = 's';
		outputString[position++] = 'e';
		outputString[position++] = 'r';
		outputString[position++] = 'n';
		outputString[position++] = 'a';
		outputString[position++] = 'm';
		outputString[position++] = 'e';
		outputString[position++] = ' ';
		outputString[position++] = 'o';
		outputString[position++] = 'f';
		outputString[position++] = ' ';
		outputString[position++] = tolower(firstName[0]);
		outputString[position++] = tolower(middleName[0]);
		for (int i = 0; i < strlen(lastName); i++)
		{
			outputString[position++] = tolower(lastName[i]);
		}
		outputString[position++] = '.';
		outputString[position++] = '\n';
		fputs(outputString, myFile_write_ptr); 		// The line is printed to the file
	}
	fclose(myFile_write_ptr); // Always fclose anything you fopen
	getchar(); getchar();

	return 0;
}