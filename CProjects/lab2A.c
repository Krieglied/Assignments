/*
 *
 * Lab 2A for declaring and initializing variables
 *
 * Name: Robert John Graham III
 * Date: July 10, 2018
 * Project: Declare/Initialize Variables
 *
 */

#include <stdio.h>

int main(void)
{
	int testInt;
	float testFloat;
	double testDouble;
	char testChar;

	printf("Uninitialized integer is %d with size %d \n", testInt, sizeof(testInt));
	printf("Uninitialized float is %f with size %d \n", testFloat, sizeof(testFloat));
	printf("Uninitialized double is %lf with size %d \n", testDouble, sizeof(testDouble));
	printf("Uninitialized char is %c with size %d \n", testChar, sizeof(testChar));

	testInt = 17;
	testFloat = 3.11;
	testDouble = 7.1241352345435345;
	testChar = 'O';

	printf("Full integer is %d with size %d \n", testInt, sizeof(testInt));
	printf("Full float is %f with size %d \n", testFloat, sizeof(testFloat));
	printf("Full double is %lf with size %d \n", testDouble, sizeof(testDouble));
	printf("Full char is %c with size %d \n", testChar, sizeof(testChar));

	return 0;
}
