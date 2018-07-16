/*
 *
 * Demo for Bit Shift Operators
 *
 * Name: Robert John Graham III
 * Date: July 16, 2018
 * Project: Bit SHift Operators
 *
 */

#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int main(void)
{
	uint32_t input = 0;
	uint32_t holdover = 0;
	do
	{
	
		printf("Input a positive number: ");
		scanf("%u", &input);
	}
	while(input <= 0);
	printf("Your number was: 0x%08X\n", input);
	holdover = input;
	holdover = holdover >> 4;
	input = input << (sizeof(input)) - 4;
	input = input | holdover;
	printf("Your number is: 0x%08X\n", input);
	return 0;
}
