/*
 *
 * Lab 4A for Basic I/O
 *
 * Name: Robert John Graham III
 * Date: July 11, 2018
 * Project: Input Output Functions
 *
 */

#include <stdio.h>

int main(void)
{
	int userInput = 0;
	printf("Input a character:  ");
	userInput = getchar();
	printf("Next character is ");
	putchar(++userInput);
	printf("\n");
	return 0;
}
