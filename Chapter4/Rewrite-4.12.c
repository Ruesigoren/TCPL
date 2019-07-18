#include <stdio.h>

#define abs(x)		((x) > 0 ? (x) : (-x))

#undef itoa
void itoa(int x, char s[]);

int main()
{
	char s[20];
	
	itoa(-23121, s);
	printf("%s", s);
	getchar();
}

void itoa(int x, char s[])
{
	static int i;
	
	i = 0;
	if (x / 10) {
		itoa(x / 10, s);
	}
	else if (x < 0) {
		s[i++] = '-';
	}
	s[i++] = abs(x % 10) + '0';
	s[i] = '\0';
}