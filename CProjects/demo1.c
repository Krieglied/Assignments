/*
 *
 * Demo for Formatted I/O
 *
 * Name: Robert John Graham III
 * Date: July 12, 2018
 * Project: Input Output Functions
 *
 */

#include <stdio.h>

int main(void)
{
	char inputOutput[100] = {0};
	printf("Enter in a character string: ");
	scanf("%99[^A-Z\n]s",&inputOutput);
	printf("Your input was %s", inputOutput);
	return 0;
}
