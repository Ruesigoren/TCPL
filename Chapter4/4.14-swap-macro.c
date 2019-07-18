#include <stdio.h>

//#define swap(x,y)	{(x) = (x) + (y);\
//					(y) = (x) - (y);\
//					(x) = (x) - (y);}

#define swap(t, x, y)	{t _z;\
						_z = x;\
						x = y;\
						y = _z;}

main()
{
	int a;
	int b;

	a = 4;
	b = 5;
	//swap(a,b);
	swap(int, a, b);
}