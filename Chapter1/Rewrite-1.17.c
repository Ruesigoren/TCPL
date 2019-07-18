#include <stdio.h>

#define MAXLINE			10
#define LIMIT			8

int Getline(char line[], int max);

int main()
{
	char s[MAXLINE];
	int len;
	
	while ((len = Getline(s, MAXLINE)) > 0) {
		if (len > LIMIT) {
			printf("%s", s);
		}
	}
	getchar();
	return 0;
}

int Getline(char line[], int max)
{
	int i, j;
	int c;
	
	for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (j < max - 2) {
			line[j] = c;
			j++;
		}
	}
	if (c == '\n') {
		line[j] = c;
		i++;
		j++;
	}
	line[j] = '\0';
	return i;
}