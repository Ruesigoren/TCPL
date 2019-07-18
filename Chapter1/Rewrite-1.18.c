#include <stdio.h>

#define MAXLINE			10

int Getline(char s[], int max);

int main()
{
	char s[MAXLINE];
	int len;
	
	while ((len = Getline(s, MAXLINE)) >= 1) {
		printf("%s", s);
	}
	getchar();
	return 0;
}

int Getline(char s[], int max)
{
	int i, j;
	int c;
	
	for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (j < max - 2) {
			s[j] = c;
			j++;
		}
	}
	if (c == '\n') {
		while (j >= 0 && (s[j] == ' ' || s[j] == '\t')) {
			j--;
		}
		if (j >= 0) {			
			s[j] = c;
			j++;
			i++;
		}
	}
	s[j] = '\0';
	return i;
}