#include <stdio.h>
#define get(x) #x
int main(void)
{
	printf(get(icecream));
	while (1);
	return 0;
}