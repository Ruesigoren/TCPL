#include <stdio.h>
#include "calc.h"

#define STACKSIZE	100

double stack[STACKSIZE];
int sp = 0;

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
