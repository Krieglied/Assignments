/* Performance Lab for IF Statements
* July 17, 2018
* Robert John Graham III
*/

#include <stdio.h>

int main(void)
{
	char inputString[256] = { 0 };
	printf("Input a string: ");
	scanf("%255s", &inputString);
	if (inputString[0] >= 32 && inputString[0] < 126)
	{
		printf("Your input string is: %s", inputString);
	}
	while (1);
	return 0;
}