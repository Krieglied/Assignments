#include <stdio.h>

// Prints numbers from 1 to n
void printNos(unsigned int n)
{
	int bool = n > 0;
	switch(bool)
	{
	case 1:
		printNos(n - 1);
		printf("%d ", n);
		break;
	}
	return;
}

//Driver code
int main()
{
	printNos(100);
	getchar();
	return 0;
}