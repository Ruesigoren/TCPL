#include <stdio.h>

#define MAXLINE			10

int Getline(char s[], int max);
void reverse(char s[]);

int main()
{
	char s[MAXLINE];
	int len;
	
	while ((len = Getline(s, MAXLINE)) > 0) {
		reverse(s);
		printf("%s", s);
	}
	getchar();
	return 0;
}

int Getline(char s[], int max)
{
	int c;
	int i, j;
	
	for (i = j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (j < max - 2) {
			s[j] = c;
			j++;
		}
	}
	if (c == '\n') {
		s[j] = c;
		i++;
		j++;
	}
	s[j] = '\0';
	return i;
}

void reverse(char s[])
{
	int len;
	char tmp;
	int i;
	
	len = 0;
	while (s[len] != '\0') {
		len++;
	}
	len--;
	if (s[len] == '\n') {
		len--;
	}
	for (i = 0; i < len - i; i++) {
		tmp = s[i];
		s[i] = s[len - i];
		s[len - i] = tmp;
	}
}