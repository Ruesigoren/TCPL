#include <stdio.h>
#include <ctype.h>

#define BUFFSIZE		100
#define NUMBER			'0'

char buf[BUFFSIZE];
int bufp = 0;

int getline(char *s, int lim);
int atoi(char *s);
void iota(int n, char *s);
double atof(char s[]);
void reverse(char *s);
int strindex(char *s, char *t);
int getop(char *s);
int getch(void);
void ungetch(int c);

main()
{
	int n;
	char s[10];
	char t[20] = "hello world";
	char u[5] = "llo";
	char v[10];
	char w[10] = "112.3";

	getline(s, 5);
	printf("%s\n", s);
	n = atoi(s);
	printf("%d\n", n);
	iota(n, s);
	printf("%s\n", s);
	reverse(s);
	printf("%s\n", s);
	printf("%d\n", strindex(t, u));
	printf("%d\n", getop(v));
	printf("%f\n", atof(w));
}

int getline(char *s, int lim)
{
	int c;
	char *t = s;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		*s++ = c;
	}
	if (c == '\n') {
		*s++ = c;
	}
	*s = '\0';
	return s - t;
}

int atoi(char *s)
{
	int n, sign;

	while (isspace(*s)) {
		s++;
	}
	sign = (*s == '-') ? (-1) : 1;
	if (*s == '-' || *s == '+') {
		s++;
	}

	for(n = 0; isdigit(*s); s++) {
		n = 10 * n + *s - '0';
	}
	return sign * n;
}

void iota(int n, char *s)
{
	int sign;
	char *t = s;

	sign = n;
	n = (n < 0) ? (-n) : n;
	do {
		*s++ = (n % 10) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0) {
		*s++ = '-';
	}
	*s = '\0';
	reverse(t);
}

double atof(char s[])
{
	double val, power;
	int exp;
	int i, sign;

	for (i = 0; isspace(*s); ++s) {
		;
	}
	sign = (*s == '-') ? (-1) : 1;
	if (*s == '-' || *s == '+') {
		s++;
	}
	for (val = 0.0; isdigit(*s); ++s) {
		val = 10.0 * val + (*s - '0');
	}
	if (*s == '.') {
		++s;
	}
	for (power = 1.0; isdigit(*s); ++s) {
		val = 10.0 * val + (*s - '0');
		power *= 10;
	}
	val = sign * val / power;
	if (*s == 'e' || *s == 'E') {
		s++;
		sign = (*s == '-') ? (-1) : 1;
		if (*s == '+' || *s == '-') {
			s++;
		}
		for (exp = 0; isdigit(*s); ++s) {
			exp = 10 * exp + (*s - '0');
		}
		if (sign == 1) {
			while (exp-- > 0) {
				val *= 10;
			}
		}
		else {
			while (exp-- > 0) {
				val /= 10;
			}
		}
	}
	return val;
}

void reverse(char *s)
{
	char *t;
	char c;

	t = s;
	while (*s) {
		s++;
	}
	s--;
	while (s - t > 0) {
		c = *s;
		*s = *t;
		*t = c;
		s--;
		t++;
	}
}

int strindex(char *s, char *t)
{
	char *a = s;
	char *c, *d;

	for (; *s != '\0'; s++) {
		for (c = s, d = t; *d != '\0' && *d == *c; c++, d++) {
			;
		}
		if (d > t && *d == '\0') {
			return s - a;
		}
	}
	return -1;
}

int getop(char *s)
{
	int c;

	while ((*s = c = getch()) == ' ' || c == '\t') {
		s++;
	}
	*(s + 1) = '\0';
	while (!isdigit(c) && c != '+' && c != '-') {
		return c;
	}
	if (c == '-') {
		if (isdigit(c = getch()) || c == '.') {
			*++s = c;
		}
		else {
			if (c != EOF) {
				ungetch(c);
			}
			return '-';
		}
	}
	if (isdigit(c)) {
		while (isdigit(*++s = c = getch())) {
			;
		}
	}
	if (c == '.') {
		while (isdigit(*++s = c = getch())) {
			;
		}
	}
	*s = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}

int getch(void)
{
	return (bufp > 0) ? (buf[--bufp]) : getchar();
}

void ungetch(int c)
{
	if (bufp < BUFFSIZE) {
		buf[bufp++] = c;
	}
	else {
		printf("Error: buff is full.\n");
	}
}
