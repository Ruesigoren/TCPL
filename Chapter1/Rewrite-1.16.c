#include <stdio.h>

#define MAX_LENGTH			10

int Getline(char str[], int max);
void copy(char from[], char to[]);

int main()
{
	char s[MAX_LENGTH];
	char t[MAX_LENGTH];
	int n, maxlen;
	
	maxlen = 0;
	while ((n = Getline(s, MAX_LENGTH)) > 0) {
		if (maxlen < n) {
			maxlen = n;
			copy(s, t);
		}
	}
	if (maxlen > 0) {
		printf("%d\n", maxlen);
		printf("%s", t);
	}
	getchar();
	return 0;
}

int Getline(char str[], int max)
{
	int i, j, c;
	
	for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (j < max - 2) {
			str[j] = c;
			++j;
		}
	}
	if (c == '\n') {
		str[j] = c;
		++i;
		++j;
	}
	str[j] = '\0';
	return i;
}

void copy(char from[], char to[])
{
	int i;
	
	i = 0;
	while((to[i] = from[i]) != '\0') {
		++i;
	}
}