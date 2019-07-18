#include <stdio.h>
#include <string.h>
#include <time.h>
#include "alloc.h"

#define MAXLINES		5000
#define MAXWORD			1000
char *lineptr[MAXLINES];

//int readlines(char *lineptr[], int maxlines);
int readlines(char *lineptr[], int maxlines, char buf[]);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

main()
{
	int nlines;
	char buf[MAXWORD];

	if ((nlines = readlines(lineptr, MAXLINES, buf)) >= 0) {
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN		1000
int getline(char *, int);

int readlines(char *lineptr[], int maxlines, char buf[])
{
	int len, nlines;
	char *p, line[MAXLEN];
	double start, finish, elapsed;

	p = buf;
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0) {
		start = (double)clock() / CLOCKS_PER_SEC;
		if (nlines >= maxlines || len > MAXWORD) {
			return -1;
		}
		else {
			line[len - 1] = '\0';
#pragma warning(suppress : 4996)
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
		finish = (double)clock() / CLOCKS_PER_SEC;
		elapsed = finish - start;
		printf("%f\n", elapsed);
	}
	return nlines;
}

//int readlines(char *lineptr[], int maxlines)
//{
//	int len, nlines;
//	char *p, line[MAXLEN];
//	double start, finish, elapsed;
//
//	nlines = 0;
//	while ((len = getline(line, MAXLEN)) > 0) {
//		start = (double) clock() / CLOCKS_PER_SEC;
//		if (nlines >= maxlines || (p = alloc(len)) == NULL) {
//			return -1;
//		}
//		else {
//			line[len - 1] = '\0';
//#pragma warning(suppress : 4996)
//			strcpy(p, line);
//			lineptr[nlines++] = p;
//		}
//		finish = (double)clock() / CLOCKS_PER_SEC;
//		elapsed = finish - start;
//		printf("%f\n", elapsed);
//	}
//	return nlines;
//}

void writelines(char *lineptr[], int nlines)
{
	//int i;

	//for (i = 0; i < nlines; i++) {
	//	printf("%s\n", lineptr[i]);
	//}

	while (nlines-- > 0) {
		printf("%s\n", *lineptr++);
	}
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

void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right) {
		return;
	}
	swap(v, left, ((left + right) / 2));
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (strcmp(v[i], v[left]) < 0) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
