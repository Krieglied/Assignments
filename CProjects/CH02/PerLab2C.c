/* Performance Lab for IF ELSE IF Statements
* July 17, 2018
* Robert John Graham III
*/


#include <stdio.h>

int main(void)
{
	unsigned int inputA, inputB, inputC = 0;
	unsigned int temp = 0;
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
		printf("The sum of %d + %d + %d is %d", inputA, inputB, inputC, inputA + inputB + inputC);
	}
	while (1);
	return 0;
}