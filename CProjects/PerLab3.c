/*
*
* Performance Lab 7.3 
*
* Name: Robert John Graham III
* Date: July 10, 2018
* Project: For Loops
*
*/

#include <stdio.h>

int main(void)
{
	int testInt;
	float testFloat;
	double testDouble;
	char testChar;

	testInt = 17;
	testFloat = 3.11;
	testDouble = 7.1241352345435345;
	testChar = 'O';
	for (int i = 0; i < 5; i++) 
	{
		printf("Full integer is %d with size %d \n", testInt, sizeof(testInt));
		printf("Full float is %f with size %d \n", testFloat, sizeof(testFloat));
		printf("Full double is %lf with size %d \n", testDouble, sizeof(testDouble));
		printf("Full char is %c with size %d \n", testChar, sizeof(testChar));
	}
	for (int j = 0; j < 10; j++)
	{
		printf("This is a number %d\n", j * 15);
	}
	for (int k = 0; k < 14; k += 2)
	{
		if (k / 2)
		{
			printf("This number is even %d\n", k);
		}
	}
	while (1);
	return 0;
}