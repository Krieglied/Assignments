/*
*
* Performance Lab 8A
*
* Name: Robert John Graham III
* Date: July 18, 2018
* Project: Functions
*
*/

#include <stdio.h>

int replace_character(char * string, const char findThisChar, const char replaceItWithThis);

int main(void)
{
	char inputString[256] = { 0 };
	char replacmentChar = { 0 };
	char changeChar = { 0 };
	//Input string to look at
	printf("Input a string to test:");
	scanf("%255s", inputString);
	//Character to be replaced
	printf("Enter a char to be replaced: ");
	scanf("%c", replacmentChar);
	//Character to be replaced with
	printf("Enter a char to replace with: ");
	scanf("%c", changeChar);
	int numChar = replace_character(inputString, replacmentChar, changeChar);
	printf("Number of characters replaced: %d", numChar);
	while (1);
	return 0;
}
/* Parameters
*  Pointer to a null - terminated string
*  Character to find
*  Character to replace it with
*/
int replace_character(char * string, const char findThisChar, const char replaceItWithThis)
{
	int char_replaced = 0;
	int i = 0;
	while (&string[i] != '\0')
	{
		//Purpose - replace all occurrences of findThisChar with replaceItWithThis
		if (string[i] == findThisChar)
		{
			string[i] = replaceItWithThis;
			char_replaced++;
		}
		i++;
	}
	//Return Value - number of characters replaced
	return char_replaced;
}