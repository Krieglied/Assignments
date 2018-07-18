// MyStringHeader.c
#include <stdio.h>
#include <ctype.h>
#include "MyStringHeader.h"

#define ERR_NULL_POINTER -1;        // string is null
#define ERR_INVALID_LENGTH -2;      // string length is zero or less

extern int print_the_count(char * inputString, int strLen)
{
    char tempChar = 0;      // Current char being acted on
    int table[26] = {0};    // Alpha
    int count = 0;

    if (!inputString)
    {
        return ERR_NULL_POINTER;
    }
    else if (!strLen)
    {
        return ERR_INVALID_LENGTH;
    }

    for (int i = 0; i < strLen; i++)
    {
        if (inputString[i] >= 65 && inputString[i] <= 122)
        {
            tempChar = inputString[i];
            tempChar = toupper(tempChar);
            table[tempChar - 65] += 1;
            count++;
        }
    }

    // Print the table
    for (int i = 0; i < sizeof(table)/sizeof(table[0]); i++)
    {
        printf("%c: %d\n", i + 65, table[i]);
    }
    return count;
}
//Purpose - Print a non-null terminated string backwards and then print a newline 
extern int reverse_it(char * forwardString, int strLen)
{
	char tempChar = { 0 };
	// Return value -1 if forwardString is NULL
	if (!forwardString)
	{
		return ERR_NULL_POINTER;
	}
	// Return value -2 if strLen is zero or less
	else if (strLen <= 0)
	{
		return ERR_INVALID_LENGTH;
	}
	for (int i = 0; i <= strLen / 2; i++)
	{
		tempChar = forwardString[i];
		forwardString[i] = forwardString[strLen - i - 1];
		forwardString[strLen - i -1] = tempChar;
	}
	printf("%s\n",forwardString);
	return 0;
}
