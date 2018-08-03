#define _CRT_SECURE_NO_WARNINGS 1
/* ITOA
* August 3, 2018
* Robert John Graham III
*/


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned int inputA, inputB, inputC = 0;
	unsigned int temp = 0;
	char * bufferA[32] = { 0 };
	char * bufferB[32] = { 0 };
	char * bufferC[32] = { 0 };
	printf("Input two numbers, separated by tabs: ");
	scanf("%d\t%d", &inputA, &inputB);
	if (inputA != inputB)
	{
		if (inputA > inputB)
		{
			temp = inputA;
			inputA = inputC;
			inputC = temp;
		}
		else
		{
			temp = inputB;
			inputB = inputC;
			inputC = temp;
		}
	}
	else
	{
		printf("The two values are equal.  ERROR\n");
	}
	if ((inputA + inputB + inputC) > 2)
	{
		_itoa(inputA, bufferA, 10);
		_itoa(inputB, bufferB, 10);
		_itoa(inputC, bufferC, 10);
		printf("The sum of %s + %s + %s is %d", bufferA, bufferB, bufferC, inputA + inputB + inputC);
	}
	while (1);
	return 0;
}