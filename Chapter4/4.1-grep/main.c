#include <stdio.h>

#define MAXLINE			100

int Getline(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould";

int main()
{
	char line[MAXLINE];
	int found;
	
	while (Getline(line, MAXLINE) > 0) {
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	}
	return found;
}