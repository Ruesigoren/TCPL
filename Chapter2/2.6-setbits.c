#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

main()
{
	unsigned test;

	//test = getbits(0b10110111, 2, 3);
	//printf("%x\n",test);
	test = setbits(0b01000111, 4, 2, 0b10110110);
	printf("%x\n", test);
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
//	return (x >> p) & ~(~0 << n);
}

//unsigned setbits(unsigned x, int p, int n, unsigned y)
//{
//	int i, z = 0;
//
//	for (i = p; i < p + n; ++i) {
//		x |= (1 << (i - n + 1));
//	}
//	y = getbits(y, n, n);
//	
//	for (i = p; i < p + n; ++i) {
//		z |= (1 << (i - n + 1));
//	}
//	y <<= (p + 1 - n);
//	y |= ~z;
//
//	x &= y;
//	return x;
//}
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return x & ~((~(~0 << n)) << (p - n + 1)) | (y & (~(~0 << n))) << (p - n + 1);
}
