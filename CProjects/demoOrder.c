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
	//1 + 2 *(3 + y) +5
	printf("%d\n", 1+ 6 +2*y +5);
	int x = 2;
	y = 6;
	// x != y != 3 >= x
	printf("%f\n", y != 3 != x >= x);
	x=9; y=3;
	//(y %= y) || (x /= x--)
	printf("%d\n", (y % y) || (x / x - 1);
	return 0;
}
