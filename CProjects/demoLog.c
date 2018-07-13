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
	int x =99, y=0;
	printf("%d\n", x&&y);
	printf("%d\n", y||x);
	printf("%d\n", !y);
	printf("%d\n", y&&0);
	printf("%d\n", x||42);
	printf("%d\n", !x);
	printf("%d\n", x&&x);
	printf("%d\n", y||y);
	printf("%d\n", !1);
	printf("%d\n", 1&&1);
	printf("%d\n", (0&&1) || (2&&3));
	return 0;
}
