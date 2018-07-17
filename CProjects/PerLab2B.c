/* Performance Lab for IF ELSE Statements
* July 17, 2018
* Robert John Graham III
*/

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 
#include <stdio.h>

int main(void)
{
	int input = 0;
	int bitNeg = 0;
	printf("Input a number: ");
	scanf("%d", &input);
	bitNeg = 1 + (input >> 31) - (-input >> 31);
	if (bitNeg == 0)
	{
		printf("Your input number %d is negative\n", input);
		printf("Your input number %d ", input);
		printf("outputs as "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(input));
	}
	else
	{
		if (bitNeg == 2) 
		{
			printf("Your input number %d ", input);
			printf("outputs as "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(input));
			printf("\nThe negative value is %d", ~input + 1);
		}
		else
		{
			printf("Your input is %d\n", input);
			printf("Your input number %d ", input);
			printf("outputs as "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(input));
		}		
	}
	while (1);
	return 0;
}