#include <stdio.h>
#include <string.h>

#define MAXLINE		1000		/* maxmium input size */
#define LONGLINE	80			/* the length limit */

int getline(char line[], int maxline);

/* print longest input line */
main()
{
	int len;
	int max;
	char line[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > LONGLINE) {
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
