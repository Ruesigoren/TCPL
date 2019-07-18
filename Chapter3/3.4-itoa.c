#include <stdio.h>
#include <string.h>

#define abs(x)	((x) < 0 ? (-x) : (x))

void itoa(int n, char s[]);
void reverse(char s[]);

main()
{
	char num = -128;
	char n[100];

	itoa(num, n);
	printf("%s\n", n);
}

void itoa(int n, char s[])
{
	int i, sign;

	//if ((sign = n) < 0) {
	//	n = -n;
	//}
	sign = n;
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}