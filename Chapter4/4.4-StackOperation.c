//#include <stdio.h>
//
//#define STACKSIZE	100
//
//double stack[STACKSIZE];
//int sp = 0;
//
//void push(double var);
//double pop(void);
//void print(void);
//void swap(void);
//void clear(void);
//
//main()
//{
//
//}
//
//void push(double var)
//{
//	if (sp < STACKSIZE) {
//		stack[sp++] = var;
//	}
//	else {
//		printf("Error: Stack is Full, Can't Push %g\n", var);
//	}
//}
//
//double pop(void)
//{
//	if (sp > 0) {
//		return stack[--sp];
//	}
//	else {
//		printf("Error: Empty Stack.\n");
//		return 0.0;
//	}
//}
//
//void print(void)
//{
//	if (sp > 0) {
//		printf("%.8g\n", stack[sp - 1]);
//	}
//	else {
//		printf("Error: Empty Stack.\n");
//	}
//}
//
//void swap(void)
//{
//	double tmp;
//
//	if (sp > 1) {
//		tmp = stack[sp - 2];
//		stack[sp - 2] = stack[sp - 1];
//		stack[sp - 1] = tmp;
//	}
//	else {
//		printf("Error: Not Enough Stack Elements.\n");
//	}
//}
//
//void clear(void)
//{
//	int i;
//
//	for (i = 0; i < sp; ++i) {
//		stack[i] = 0.0;
//	}
//}


#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define STACKSIZE	100
#define MAXOP		100
#define BUFSIZE		100
#define NUMBER		'0'

char buf[BUFSIZE];
int bufp = 0;
double stack[STACKSIZE];
int sp = 0;
double my_atof(char s[]);
double pop(void);
void push(double var);
void clear(void);
int getop(char s[]);
int getch(void);
void ungetch(int c);

main()
{
	int type;
	char s[MAXOP];
	double tmp, tmp2;

	while ((type = getop(s)) != EOF) {
		switch (type)
		{
		case NUMBER:
			push(my_atof(s));
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
		case '?':
			tmp = pop();
			printf("\t%.8g\n", tmp);
			push(tmp);
			break;
		case 'c':
			clear();
			break;
		case 'd':
			tmp = pop();
			push(tmp);
			push(tmp);
			break;
		case 's':
			tmp = pop();
			tmp2 = pop();
			push(tmp);
			push(tmp2);
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("Error: Unknown command %s\n", s);
			break;
		}
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

void clear(void)
{
	sp = 0;
}
int getop(char s[])
{
	int i;
	int c;

	while ((s[0] = c = getch()) == ' ' || c == '\t') {
		;
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-') {
		return c;
	}
	i = 0;
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
