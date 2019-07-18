#include <stdio.h>
#include <string.h>

#define abs(x)	((x) < 0 ? (-x) : (x))

void itob(int n, char s[], int b);
void reverse(char s[]);

main()
{
	char num = 127;
	char n[100];

	itob(num, n, 16);
	printf("%s\n", n);
	getchar();
}

void itob(int n, char s[], int b)
{
	int i, j, sign;

	//if ((sign = n) < 0) {
	//	n = -n;
	//}
	sign = n;
	i = 0;
	do {
		j = abs(n % b);
		s[i++] = (j <= 9) ? (j + '0') : (j + 'a' - 10);
	} while ((n /= b) != 0);
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
