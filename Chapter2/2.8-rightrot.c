#include <stdio.h>

int wordlength(void);
unsigned rightrot(unsigned x, int n);

main()
{
	unsigned test = 0b01101101;

	test = rightrot(test, 1);
	printf("%x\n", test);
	getchar();
}

unsigned rightrot(unsigned x, int n)
{
	int  len;

	len = wordlength();
	n %= len;
	return (x >> n) | ((x & ~(~0 << n)) << (len - n));
}

int wordlength(void)
{
	int i = 1;
	unsigned w = (unsigned)~0;

	while (w >>= 1 > 0) {
		++i;
	}
	return i;
}
