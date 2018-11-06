/*
*
* Performance Lab 7.5
*
* Name: Robert John Graham III
* Date: July 18, 2018
* Project: Nested Control
*
*/

#include <stdio.h>

int main(void)
{
	char number = { 0 };
	char input = { 0 };
	//Prompt the user for input to indicate odds or evens.
	printf("Do you wish to see either even (e) or odd (o) numbers?: ");
	scanf("%c", &number);
	do
	{
		//Error checking for user input
		if (number != 'e' && number != 'o')
		{
			printf("You made an incorrect choice. ERROR");
			return 0;
		}
		//For Loop Version
		//Loop from 0 to 100 and print all indicated numbers.
		for (int i = 0; i <= 100; i++)
		{
			//Use and IF statement to check if even or odd.
			if (number == 'e' && i % 2 == 0)
			{
				printf("%d\n", i);
			}
			if (number == 'o' && i % 2 == 1)
			{
				printf("%d\n", i);
			}
		}
		/* While Loop version
		int j = 0;
		while(j <= 100)
		{
			//Use and IF statement to check if even or odd.
			if (number == 'e' && j % 2 == 0)
			{
				printf("%d\n", j);
			}
			if (number == 'o' && j % 2 == 1)
			{
				printf("%d\n", j);
			}
			j++;
		}*/
		//Ask the user to continue with a DO-WHILE loop
		printf("Do you wish to continue? (y) or (n)");
		scanf("%c", &input);
	}
	while (input != 'n');
	return 0;
}