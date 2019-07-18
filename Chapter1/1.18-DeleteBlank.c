#include <stdio.h>
#include <string.h>

#define MAXLINE		1000		/* maxmium input size */

int getline(char line[], int maxline);
int remov(char line[]);

/* print longest input line */
main()
{
	int len;
	int max;
	char line[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (remov(line) > 0) {
			printf("%s", line);
		}
	return 0;
}

int getline(char line[], int maxline)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < maxline - 2) {
			line[j] = c;
			++j;
		}
	}
	if (c == '\n') {
		line[j] = c;
		++i;
		++j;
	}
	line[j] = '\0';
	return i;
}

int remov(char line[])
{
	int i = 0;

	while (line[i] != '\n')
		++i;
	--i;
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
		--i;
	if (i >= 0) {
		++i;
		line[i] = '\n';
		++i;
		line[i] = '\0';
	}
	return i;
}