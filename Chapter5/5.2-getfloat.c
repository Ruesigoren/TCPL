#include <stdio.h>
#include <ctype.h>

#define BUFSIZE		100

char buff[BUFSIZE];
int cp = 0;

int getch(void);
void ungetch(int c);
int getfloat(double *pn);

main()
{
	double a;

	getfloat(&a);
	printf("\t%.8g\n", a);
}

int getfloat(double *pn)
{
	double pow;
	int exp;
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
	for (*pn = 0.0; isdigit(c); c = getch()) {
		*pn = 10.0 * (*pn) + (c - '0');
	}
	if (c == '.') {
		c = getch();
	}
	for (pow = 1.0; isdigit(c); c = getch()) {
		*pn = 10.0 * (*pn) + (c - '0');
		pow *= 10;
	}
	*pn = sign * (*pn) / pow;
	if (c == 'e' || c == 'E') {
		c = getch();
		sign = (c == '-') ? (-1) : 1;
		if (c == '+' || c == '-') {
			c = getch();
		}
		for (exp = 0; isdigit(c); c = getch()) {
			exp = 10 * exp + (c - '0');
		}
		if (sign == 1) {
			while (exp-- > 0) {
				*pn *= 10;
			}
		}
		else {
			while (exp-- > 0) {
				*pn /= 10;
			}
		}
	}
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

