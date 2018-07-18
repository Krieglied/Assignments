#include <stdio.h>
#include <string.h>
#include "MyStringHeader.h"

int main(void)
{
	int i = 0;
	int tempStrLen = 0;
	int tempReturnValue = 0;
	int totalUnitTestsRun = 0;
	int numUnitTestsPassed = 0;
	char testString1[] = { "This is a test string." }; // NULL terminated string
	char testString2[15] = { 'N', 'o', 't', ' ', 't', 'e', 'r', 'm', 'i', 'n', 'a', 't', 'e', 'd', '!' }; // Not null-terminated
	char testString3[] = { "!@#$%^&*()" }; // No alphabet letters in the string
	char * testString4 = NULL; // NULL pointer
	char testString5[] = { "This is a normal string the but main() will pass zero as a string length." }; // Good string but passed with zero length
	char testString6[] = { "This is a normal string but main() will pass an invalid string length." }; // Good string but passed with invalid length
	char * testStringArray[] = { testString1, testString2, testString3, testString4, testString5, testString6 };
	int testStringLength[] = { strlen(testString1), 15, strlen(testString3), 999, 0, -999 };
	int testStringReturnValues[] = { 0, 0, 0, -1, -2, -2 };

	for (i = 0; i < (sizeof(testStringArray) / sizeof(testStringArray[0])); i++)
	{
		/* Unit test header */
		printf("UNIT TEST #%d STRING:\n\t", i + 1);
		/* Print the test string */
		if (1 == i)
		{
			printf("Passing a non null-terminated string.\n");
		}
		else if (3 == i)
		{
			printf("Passing a NULL pointer.\n");
		}
		else
		{
			puts(testStringArray[i]);
		}
		/* Pass the unit test data to print_the_count() */
		tempReturnValue = reverse_it(testStringArray[i], testStringLength[i]);
		totalUnitTestsRun++;

		if (tempReturnValue == testStringReturnValues[i])
		{
			printf("\tPASS\n");
			numUnitTestsPassed++;
		}
		else
		{
			printf("\tFAIL\n");
		}
	}
	printf("\n********************************\n");
	printf("This program ran %d unit tests.\n", totalUnitTestsRun);
	printf("Your header passed %d unit tests.\n", numUnitTestsPassed);
	printf("********************************\n");
	while (1);
	return 0;
}
