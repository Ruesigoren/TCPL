#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "calc.h"

#define MAXOP	100

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
