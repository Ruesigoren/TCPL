#include <stdio.h>

int main()
{
	int x = 1, y = 2, z[10];
	int *ip;
	int *iq;
	
	double *dp, atof(char *);
	
	z[0] = 1;
	
	ip = &x;
	y = *ip;
	*ip = 0;
	ip = &z[0];
	
	*ip = *ip + 10;
	y = *ip + 1;
	*ip += 1;
	++*ip;
	(*ip)++;
	ip = iq;
}