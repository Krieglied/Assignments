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
	char firstName[25] = {0}, middleName[25] = {0}, lastName[25] = {0};
	printf("Please input your first name, middle name, last name: ");
	scanf("%24s\t%24s\t%24s", &firstName, &middleName, &lastName);
	printf("\t%s\n\t%s\n\t%s\n", firstName, middleName, lastName);
	return 0;
}
