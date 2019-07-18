#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES	5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int maxlines);

void u_qsort(char *v[], int left, int right);

int main()
{
	int nlines;
	
	if (nlines = readlines(lineptr, MAXLINES) >= 0) {
		u_qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN	1000

int Getline(char *, int);
char *alloc(int);

/* 这个函数有错误 */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	
	nlines = 0;
	while ((len = Getline(line, MAXLEN)) >= 0) {
		if (nlines >= maxlines || (p = malloc(len)) == NULL) {
			return -1;
		}
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

int Getline(char line[], int max)
{
	int i, c;
	
	i = 0;
	while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
		line[i++] = c;
	}
	if (c == '\n') {
		line[i++] = '\n';
	}
	line[i] = '\0';
	return i;
}

/* 版本1 */
// void writelines(char *lineptr[], int maxlines)
// {
	// int i;
	
	// for (i = 0; i < nlines; i++) {
		// printf("%s\n", lineptr[i]);
	// }
// }

void writelines(char *lineptr[], int maxlines)
{
	int i;
	
	while (maxlines-- > 0) {
		printf("%s\n", *lineptr++);
	}
}

void u_qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	
	if (left >= right) {
		return;
	}
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (strcmp(v[i], v[left]) < 0) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last - 1);
	u_qsort(v, left, last - 1);
	u_qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
