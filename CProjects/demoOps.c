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
	int x = 7, y =4;
	float z = 0, a = 7.5, b = 3.14;
	printf("%d\n", x*y);
	z = x / y;
	printf("%f\n", z);
	printf("%d\n", x%y);
	printf("%d\n", y+x);
	printf("%d\n", y-x);
	printf("%d\n", -y);
	printf("%d\n", ++x);
	printf("%d\n", y++);
	printf("%d\n", x--);
	printf("%d\n", --y);
	printf("%d\n", 1 + 2 *(3+y) +5);
	printf("%f\n", x%y);
	printf("%d\n", (++x)+(++y));
	printf("%d\n", (++x)+y);
	printf("%d\n", (x++)+y);
	return 0;
}
