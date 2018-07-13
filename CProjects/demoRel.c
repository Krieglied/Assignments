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
	int x = 2, y =6;
	printf("%d\n", y<x);
	printf("%d\n", y<=x);
	printf("%d\n", y>x);
	printf("%d\n", y>=x);
	printf("%d\n", y==x);
	printf("%d\n", y!=x);
	printf("%d\n", 2==y);
	printf("%d\n", 6!=x);
	printf("%d\n", 6>=2);
	printf("%d\n", 2<6);
	printf("%d\n", x!=y!=3>=x);
	return 0;
}
