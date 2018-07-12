/*
 *
 * Lab 4D for scanf function
 *
 * Name: Robert John Graham III
 * Date: July 11, 2018
 * Project: Using scanf
 *
 */

#include <stdio.h>

int main(void)
{
	int firstVar = 0, secondVar = 0;
	printf("Please input your first variable and then second variable: ");
	scanf("%24d*%24d", &firstVar, &secondVar);
	printf("The result of %d multiplied by %d is %d", firstVar, secondVar, firstVar * secondVar);
	return 0;
}
