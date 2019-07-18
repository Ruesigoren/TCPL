#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES	3
#define LINES		10
#define MAXLEN		100

void error(char *s);
//int Getline(char *, int);
int Getline(char line[], int maxline);

/* print last n lines of the input */
main(int argc, char *argv[])
{
	char *p;
	char *buf;
	char *bufend;
	char line[MAXLEN];
	char *lineptr[LINES];
	int first, i, last, len, n, nlines;

	if (argc == 1) {
		n = DEFLINES;
	}
	else if (argc == 2 && (*++argv)[0] == '-') {
		n = atoi(argv[0] + 1);
	}
	else {
		error("usage: tail [-n]");
	}
	if (n < 1 || n > LINES) {
		n = LINES;
	}
	for (i = 0; i < LINES; i++) {
		lineptr[i] = NULL;
	}
	if ((p = buf = malloc(LINES * MAXLEN)) == NULL) {
		error("tail: cannot alocate buf");
	}
	bufend = buf + LINES * MAXLEN;
	last = 0;
	nlines = 0;
	while ((len = Getline(line, MAXLEN)) > 0) {
		if (p + len + 1 >= bufend) {
			p = buf;
		}
		lineptr[last] = p;
		strcpy_s(lineptr[last], LINES, line);
		if (++last >= LINES) {
			last = 0;
		}
		p += len + 1;
		nlines++;
	}
	if (n > nlines) {
		n = nlines;
	}
	first = last - n;
	if (first < 0) {
		first += LINES;
	}
	for (i = first; n-- > 0; i = (i + 1) % LINES) {
		printf("%s", lineptr[i]);
	}
	return 0;
}

/* error: print error message and exit */
void error(char *s) {
	printf("%s\n", s);
	exit(1);
}


int Getline(char line[], int maxline)
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
