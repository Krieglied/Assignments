/*
 *
 * Lab 3A for Using Arrays
 *
 * Name: Robert John Graham III
 * Date: July 10, 2018
 * Project: Student Ages, Favorite Quotes
 *
 */

#include <stdio.h>

int main(void)
{
	int classAges[] = {0, 27, 25, 31, 32, 28, 26, 24, 28, 22, 31, 29, 26};	
	for(int i=0; i < 13; i++)
	{
		printf("Age of student %d: %d \n", i, classAges[i]);
	}

	char quote[] = "I've\nhurt\nyou,\nand\nI\nwish\nto\ngo\non\nhurting\nyou.\n";
	for(int i=0;i < 43; i++)
	{
		printf("%c",quote[i]);
	}
	
	return 0;
}
