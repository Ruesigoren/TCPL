#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

main()
{
	unsigned test = 0b01111111;

	test = invert(test, 4, 5);
	printf("%d\n", test);
}

unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n)) << (p - n + 1);
}
