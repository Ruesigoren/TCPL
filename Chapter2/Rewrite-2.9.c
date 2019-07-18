#include <stdio.h>

int bitcount(unsigned x);

int main()
{
	printf("%d", bitcount(255));
	getchar();
}

int bitcount(unsigned x)
{
	int b = 0;
	
	while (x) {
		b++;
		x &= x - 1;
	}
	return b;
}