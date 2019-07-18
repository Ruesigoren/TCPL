#include <stdio.h>
#include <ctype.h>

#define BUFSIZE		100

char buff[BUFSIZE];
int cp = 0;

int getch(void);
void ungetch(int c);
int getint(int *pn);

main()
{
	int a;

	getint(&a);
	printf("%d\n", a);
}

int getint(int *pn)
{
	int c, sign, d;

	while (isspace(c = getch())) {
		;
	}
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? (-1) : 1;
	if (c == '+' || c == '-') {
		d = c;
		if (!isdigit(c = getch())) {
			if (c != EOF) {
				ungetch(c);
			}
			ungetch(d);
			return d;
		}
	}
	for (*pn = 0; isdigit(c); c = getch()) {
		*pn = 10 * (*pn) + (c - '0');
	}
	*pn *= sign;

	if (c != EOF) {
		ungetch(c);
	}
	return c;
}

int getch(void)
{
	return (cp > 0) ? (buff[--cp]) : (getchar());
}

void ungetch(int c)
{
	if (cp < BUFSIZE) {
		buff[cp++] = c;
	}
	else {
		printf("Too many characters\n");
	}
}

