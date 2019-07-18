#include <stdio.h>

int Getline(char line[], int max)
{
	int i, c;
	
	i = 0;
	while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
		line[i++] = c;
	}
	if (c == '\n') {
		line[i++] = '\n';
	}
	line[i] = '\0';
	return i;
}