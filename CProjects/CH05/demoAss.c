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
	int x = 9, y = 3;
	printf("%d\n", x*=y);
	x =9;
	printf("%f\n", x/=y);
	x=9;
	printf("%d\n", x%=y);
	x=9;
	printf("%d\n", x+=y);
	x=9;
	printf("%d\n", x-=y);
	x=9;
	printf("%d\n", x *= ++y);
	x=9;
	printf("%d\n", x /= y--);
	x=9;
	printf("%d\n", x %= --x);
	x=9;
	printf("%d\n", x += --y);
	x=9;
	printf("%d\n", x -= y++);
	x=9;
	printf("%d\n", (y %= y) || (x /= x--));
	return 0;
}
