#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN			1000
#define MAXSTOR			5000
#define MAXLINES		5000

char *lineptr[MAXLINES];
int order = 1;
int dir = 0;

int getline(char *s, int lim);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void Qsort(void *lineptr[], int left, int right,
	int(*comp)(void *, void *));
int numcmp(char *, char *);
int charcmp(char *, char *);

/* 对输入的文本进行排序 */
int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;
	int c;
	int fold = 0;

	//if (argc > 1 && strcmp(argv[1], "-n") == 0) {
	//	numeric = 1;
	//}
	while (--argc > 0 && (*++argv)[0] == '-') {
		while (c = *++argv[0]) {
			switch (c)
			{
			case 'r':
				order = 0;
				break;
			case 'n':
				numeric = 1;
				break;
			case 'f':
				fold = 1;
				break;
			case 'd':
				dir = 1;
				break;
			default:
				argc = 1;
				printf("illeagl option %c\n", c);
				break;
			}
		}
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		if (fold) {
			Qsort((void **)lineptr, 0, nlines - 1, (int(*) (void *, void *)) charcmp);
		}
		else {
			Qsort((void **)lineptr, 0, nlines - 1,
				(int(*)(void *, void *))(numeric ? numcmp : strcmp));
		}
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("input too big to sort\n");
		return 1;
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

int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (order) {
		if (v1 < v2) {
			return -1;
		}
		else if (v1 > v2) {
			return 0;
		}
		else {
			return 0;
		}
	}
	else {
		if (v1 < v2) {
			return 0;
		}
		else if (v1 > v2) {
			return -1;
		}
		else {
			return 0;
		}
	}
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
	char line[MAXLEN];
	char *p;

	n = 0;
	while ((len = getline(line, MAXLEN)) > 0) {
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

int charcmp(char *s1, char *s2)
{
	char a, b;

	do {
		if (dir) {
			while (!isalnum(*s1) && *s1 != ' ' && *s1 != '\0') {
				s1++;
			}
			while (!isalnum(*s1) && *s1 != ' ' && *s1 != '\0') {
				s2++;
			}
		}
		a = tolower(*s1);
		s1++;
		b = tolower(*s2);
		s2++;
		if (a == b && a == '\0') {
			return 0;
		}
	} while (a == b);
	return a - b;
}
