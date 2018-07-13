/*
 *
 * Demo for Operators
 *
 * Name: Robert John Graham III
 * Date: July 13, 2018
 * Project: Different Types of Operators
 *
 */

#include <stdio.h>

int main(void)
{
	int y = 4;
	printf("%d\n", 1+ 6 +2*y +5);
	int x = 2;
	y = 6;
	printf("%f\n", x!=y!=3>=x);
	x=9; y=3;
	printf("%d\n", (y%=y)||(x/=x--));
	return 0;
}
