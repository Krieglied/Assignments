/*
 *
 * Lab 2B for declaring and initializing variables
 *
 * Name: Robert John Graham III
 * Date: July 10, 2018
 * Project: Declare/Initialize Variables,
 * 	Type Conversions
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

	testInt = 97;
	testFloat = 3.11;
	testDouble = 7.1241352345435345;
	testChar = 'O';

	printf("Full integer is %d with size %d \n", testInt, sizeof(testInt));
	printf("Full float is %f with size %d \n", testFloat, sizeof(testFloat));
	printf("Full double is %lf with size %d \n", testDouble, sizeof(testDouble));
	printf("Full char is %c with size %d \n", testChar, sizeof(testChar));

	float convertItoF;
	char convertItoC;
	double convertFtoD;
	float convertDtoF;
	int convertCtoI;
	char rawNumberConvert;

	convertItoF = (float) testInt;
	convertItoC = (char) testInt;
	convertFtoD = (double) testFloat;
	convertDtoF = (float) testDouble;
	convertCtoI = (int) testChar;
	rawNumberConvert = (char) 33;

	printf("Converting int %d to float %f \n", testInt, convertItoF);
	printf("Converting int %d to char %c \n", testInt, convertItoC);
	printf("Converting float %f to double %lf \n", testFloat, convertFtoD);
	printf("Converting double %lf to float %f \n", testDouble, convertDtoF);
	printf("Converting char %c to int %d \n", testChar, convertCtoI);
	printf("Converting number 33 to char %c \n", rawNumberConvert);
	
	return 0;
}
