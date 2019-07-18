#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define STACKSIZE	100
#define MAXOP		100
#define BUFSIZE		100
#define NUMBER		'0'
#define NAME		'n'

char buf[BUFSIZE];
int bufp = 0;
double stack[STACKSIZE];
int sp = 0;
double my_atof(char s[]);
double pop(void);
void push(double var);
int getop(char s[]);
int getch(void);
void ungetch(int c);
void mathfnc(char s[]);

main()
{
	int i, type, var = 0;
	char s[MAXOP];
	double tmp, v;
	double variable[26];

	for (i = 0; i < 26; ++i) {
		variable[i] = 0.0;
	}
	while ((type = getop(s)) != EOF) {
		switch (type)
		{
		case NUMBER:
			push(my_atof(s));
			break;
		case NAME:
			mathfnc(s);
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			tmp = pop();
			push(pop() - tmp);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			tmp = pop();
			if (tmp + 0 != 0) {
				push(pop() / tmp);
			}
			else {
				printf("Error: Zero Divisior\n");
			}
			break;
		case '%':
			tmp = pop();
			if (tmp + 0 != 0) {
				push(fmod(pop(), tmp));
			}
			else {
				printf("Error: Zero Divisior\n");
			}
			break;
		case '\n':
			v = pop();
			printf("\t%.8g\n", v);
			break;
		case '=':
			pop();
			if (var >= 'A' && var <= 'Z') {
				variable[var - 'A'] = pop();
				push(variable[var - 'A']);
			}
			else {
				printf("Error: No variable name\n");
			}
			break;
		default:
			if (type >= 'A' && type <= 'Z') {
				push(variable[type - 'A']);
			}
			else if (type == 'v') {
				push(v);
			}
			else {
				printf("Error: Unknown command %s\n", s);
			}
			break;
		}
		var = type;
	}
}

double pop(void)
{
	if (sp > 0) {
		return stack[--sp];
	}
	else {
		printf("Error: Empty Stack.\n");
		return 0.0;
	}
}

void push(double var)
{
	if (sp >= STACKSIZE) {
		printf("Error: Stack is Full, Can't Push %g\n", var);
	}
	else {
		stack[sp++] = var;
	}
}

int getop(char s[])
{
	int i;
	int c;

	while ((s[0] = c = getch()) == ' ' || c == '\t') {
		;
	}
	s[1] = '\0';
	if (!isdigit(c) && !islower(c) && c != '.' && c != '-') {
		return c;
	}
	i = 0;
	if (islower(c)) {
		while (islower(s[++i] = c = getch())) {
			;
		}
		s[i] = '\0';
		if (c != EOF) {
			ungetch(c);
		}
		if (strlen(s) == 3) {
			return NAME;
		}
		else
			return s[0];	//答案中 return c; 应该是错的
	}
	if (c == '-') {
		if (isdigit(c = getch()) || c == '.') {
			s[++i] = c;
		}
		else {
			if (c != EOF) {
				ungetch(c);
			}
			return '-';
		}
	}
	if (isdigit(c)) {
		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}
	if (c == '.') {
		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}

double my_atof(char s[])
{
	double val, power;
	int exp;
	int i, sign;

	for (i = 0; isspace(s[i]); ++i) {
		;
	}
	sign = (s[i] == '-') ? (-1) : 1;
	if (s[i] == '-' || s[i] == '+') {
		++i;
	}
	for (val = 0.0; isdigit(s[i]); ++i) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.') {
		++i;
	}
	for (power = 1.0; isdigit(s[i]); ++i) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	val = sign * val / power;
	if (s[i] == 'e' || s[i] == 'E') {
		++i;
		sign = (s[i] == '-') ? (-1) : 1;
		if (s[i] == '+' || s[i] == '-') {
			++i;
		}
		for (exp = 0; isdigit(s[i]); ++i) {
			exp = 10 * exp + (s[i] - '0');
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

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp < BUFSIZE) {
		buf[bufp++] = c;
	}
	else {
		printf("Error; Buff is Full\n");
	}
}

void mathfnc(char s[])
{
	double tmp;

	if (strcmp(s, "sin") == 0) {
		push(sin(pop()));
	}
	else if (strcmp(s, "cos") == 0) {
		push(cos(pop()));
	}
	else if (strcmp(s, "exp") == 0) {
		push(exp(pop()));
	}
	else if (strcmp(s, "pow") == 0) {
		tmp = pop();
		tmp = pow(pop(), tmp);
		push(tmp);
	}
	else {
		printf("Erroe: Unsupported Operation\n");
	}
}
