#include <stdio.h>

#define abs(x)	(x) > 0 ? (x): (-x)
//int pos = 0;

main()
{
	char tmp[100];
	void iota(int n, char s[]);
	
	iota(-10231, tmp);
	printf("%s", tmp);
	getchar();
}

void iota(int n, char s[])
{
	static int i;
	//if (n < 0) {
	//	s[pos++] = '-';
	//	s[pos++] = (-n) + '0';
	//}
	if (n / 10) {
		iota(n / 10, s);
	}
	else {
		if (n < 0) {
			i = 0;
			s[i++] = '-';
		}
	}
	s[i++] = abs(n % 10) + '0';
	s[i] = '\0';
}
