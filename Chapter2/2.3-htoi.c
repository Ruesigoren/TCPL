#include <stdio.h>
#include <math.h>

#define MAX	 16

int atoi(char c);

main()
{
	int i;
	int c;
	int len;
	char s[MAX + 4];
	long long num;

	while (1)
	{
		for (i = 0; i < MAX + 3 && (c = getchar()) != '\n' && c != EOF; ++i) {
			s[i] = c;
		}
		if (c == EOF) {
			break;
		}
		len = i;
		num = 0;
		if (len >= 3 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
			for (i = 2; len >= 3; ++i, --len) {
				num += atoi(s[i]) * pow(16, len - 3);
			}
		}
		printf("%lld\n", num);
	}
}

int atoi(char c)
{
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	else if (c >= 'A' && c <= 'F') {
		return c - 'A' + 10;
	}
	else if (c >= 'a' && c <= 'f') {
		return c - 'a' + 10;
	}
	else {
		return 0;
	}
}
