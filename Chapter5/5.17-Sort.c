#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NUMERIC			1	/* numeric sort */
#define DECR			2	/* sort in decreasing order*/
#define FOLD			4	/* fold upper and lower cases */
#define DIR				8	/* directory order */

#define LINES			100	/* max # of lines to be sorted */

int charcmp(char *, char *);
void error(char *);
int numcmp(char *, char *);
void readargs(int argc, char *argv[]);
int getline(char *s, int lim);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void Qsort(void *lineptr[], int left, int right,
	int(*comp)(void *, void *));

char option = 0;
int pos1 = 0;
int pos2 = 0;

/* 对输入的文本进行排序 */
int main(int argc, char *argv[])
{
	char *lineptr[LINES];
	int nlines;
	int rc = 0;

	readargs(argc, argv);
	if ((nlines = readlines(lineptr, LINES)) > 0) {
		if (option & NUMERIC) {
			Qsort((void **)lineptr, 0, nlines - 1,
				(int(*)(void *, void *))numcmp);
		}
		else {
			Qsort((void **)lineptr, 0, nlines - 1,
				(int(*)(void *, void *))charcmp);
		}
		writelines(lineptr, nlines);
	}
	else {
		printf("input too big to sort\n");
		rc = -1;
	}
	return rc;
}

void readargs(int argc, char *argv[])
{
	int c;
	//int atoi(char *);

	while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+') {
		if (c == '-' && !isdigit(*(argv[0] + 1))) {
			while (c = *++argv[0]) {
				switch (c) {
					case 'd':
						option |= DIR;
						break;
					case 'f':
						option |= FOLD;
						break;
					case 'n':
						option |= NUMERIC;
					default:
						printf("sort: illegal option %c\n", c);
						error("Usage: sort -dfnr [+pos1] [-pos2]");
						break;
				}
			}
		}
		else if (c == '-') {
			pos2 = atoi(argv[0] + 1);
		}
		else if ((pos1 = atoi(argv[0] + 1)) < 0) {
			error("Usage: sort -dfnr [+pos1] [-pos2]");
		}
	}
	if (argc || pos1 > pos2) {
		error("Usage: sort -dfnr [+pos1] [-pos2]");
	}
}


void Qsort(void *lineptr[], int left, int right,
	int(*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right) {
		return;
	}
	swap(lineptr, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if ((*comp)(lineptr[i], lineptr[left]) < 0) {
			swap(lineptr, ++last, i);
		}
	}
	swap(lineptr, left, last);
	Qsort(lineptr, left, last - 1, comp);
	Qsort(lineptr, last + 1, right, comp);
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int getline(char *s, int lim)
{
	int c;
	char *t = s;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		*s++ = c;
	}
	if (c == '\n') {
		*s++ = c;
	}
	*s = '\0';
	return s - t;
}

int readlines(char *lineptr[], int nlines)
{
	int len, n;
	char line[LINES];
	char *p;

	n = 0;
	while ((len = getline(line, LINES)) > 0) {
		if (n >= nlines || (p = (char *)malloc(len)) == NULL) {
			return -1;
		}
		else {
			line[len - 1] = '\0';
			strcpy_s(p, len, line);
			lineptr[n++] = p;
		}
	}
	return n;
}

void writelines(char *lineptr[], int nlines)
{
	int i;
	//if (order)
	//{
	//	for (i = 0; i < nlines; i++) {
	//		printf("%s\n", lineptr[i]);
	//	}
	//}
	//else {
	//	for (i = nlines - 1; i >= 0; i--) {
	//		printf("%s\n", lineptr[i]);
	//	}
	//}
	for (i = 0; i < nlines; i++) {
		printf("%s\n", lineptr[i]);
	}
}

void error(char *s) {
	printf("%s\n", s);
	exit(1);
}