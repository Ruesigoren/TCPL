#include <stdio.h>

#define MAXLINE			10

int max;
char line[MAXLINE];
char longeset[MAXLINE];

int Getline(void);
void copy(void);

int main()
{
	int len;
	extern int max;
	extern char longeset[];
	
	max = 0;
	while ((len = Getline()) > 0) {
		if (max < len) {
			max = len;
			copy();
		}
	}
	if (max > 0) {
		printf("%s", longeset);
	}
	getchar();
	return 0;
}

int Getline(void)
{
	int i, j;
	int c;
	extern char line[];
	
	for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (j < MAXLINE - 2) {
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

void copy()
{
	int i;
	extern char line[], longeset[];
	
	i = 0;
	while ((longeset[i] = line[i]) != '\0') {
		++i;
	}
}