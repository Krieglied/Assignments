//Performance Lab 11
//Robert John Graham III
//July 25, 2018
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1
int main(void)
{
	//Declare userInput, tempValue , and input_ptr as the same data type
	int userInput;
	int tempValue = 0;
	int * input_ptr;

	//Read user input into variable userInput 
	printf("Enter in a number: ");
	scanf("%d", &userInput);

	//Ensure tempValue contains the same value as userInput utilizing one or more memory operators
	input_ptr = &userInput;
	tempValue = *input_ptr;

	//Print the value *and* the pointer for each of the three variables in a human - readable format
	printf("The pointer of userInput is 0x%x and the value is %d\n", &userInput, userInput);
	printf("The pointer of tempValue is 0x%x and the value is %d\n", &tempValue, tempValue);
	printf("The pointer of input_ptr is 0x%x and the value is 0x%x\n", &input_ptr, input_ptr);
	while (1);
}