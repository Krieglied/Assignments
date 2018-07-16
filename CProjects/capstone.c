/*
 *
 * Capstone
 *
 * Name: Robert John Graham III
 * Date: July 16, 2018
 * Project: Capstone
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>

int main(void)
{
	uint32_t randNumber = 0;
	int position = 0;
	int bitMask = 0;
	srand(time(0));
	randNumber = rand();
	do
	{
		printf("Which position would you like to bit flip? Maximum length is (%u): ", sizeof(randNumber) * 8);
		scanf("%d", &position);
	}
	while(position < 0 || position > (sizeof(randNumber) * 8));
	printf("The original number is %08X\n", randNumber);
	bitMask = pow(2, position);
	randNumber = randNumber ^ bitMask;
	printf("The new number is %08X\n", randNumber);
	return 0;
}
