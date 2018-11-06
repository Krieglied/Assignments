/* Performance Lab for SWITCH Statements
* July 17, 2018
* Robert John Graham III
*/


#include <stdio.h>

int main(void)
{
	unsigned int inputA, inputB = 0;
	double output = 0.0;
	char operator = {0};
	printf("Input a number, an operator and a number, separated by tabs: ");
	scanf("%d\t%c\t%d", &inputA, &operator, &inputB);
	switch(operator)
	{
		case '+':
			output = inputA + inputB;
			break;
		case '-':
			output = inputA - inputB;
			break;
		case '*':
			output = inputA * inputB;
			break;
		case '/':
			output = inputA / inputB;
			break;
		case '%':
			output = inputA % inputB;
			break;
		default:
			printf("You should've selected an appropriate operator.  ERROR");
			while (1);
			return 0;
	}
	printf("Your output is : %.2lf", output);
	while (1);
	return 0;
}