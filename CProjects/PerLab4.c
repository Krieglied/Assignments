/*
*
* Performance Lab 7.4
*
* Name: Robert John Graham III
* Date: July 18, 2018
* Project: Continue
*
*/

#include <stdio.h>

int main(void)
{
	unsigned int input = 0;
	int counter = 1;
	int test = 1;
	printf("Input a number, up to 999: ");
	scanf("%d", &input);
	while (counter <= 20 && input < 999 && test <= input)
	{
		if (test == 0)
		{
			continue;
		}
		if (input % test == 0)
		{
			printf("%d: %d divides into %d\n", counter, test, input);
			counter++;
		}
		test++;
	}
	printf("Loop is done.");
	while (1);
	return 0;
}