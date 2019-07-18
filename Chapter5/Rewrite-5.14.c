#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define NUMERIC			1
#define DECR			2
#define FOLD			4
#define DIR				8

void readargs(int argc, char *argv[]);
int readlines(char *lineptr[], int maxline);
void writelines(char **lineptr, int maxline, int decr);
int Getline(char line[], int max);
int numcmp(char *, char *);
int charcmp(char *, char *);
void substr(char *, char *t, int maxstr);
void error(char *s);

int POS1 = 0;
int POS2 = 0;
int OPTION = 0;

#define MAXLINE			100
#define MAXLEN			100

void u_qsort(char *v[], int left, int right, int (*comp) (void *, void *));

int main(int argc, char *argv[])
{	
	/* 读取输入行 */
	char *lineptr[MAXLINE];
	int nlines;
	
	int i;

	//lineptr = (char **)malloc(MAXLINE * sizeof(char **));
	/* 读取命令行参数 */
	readargs(argc, argv);
	for (i = 0; i < 100; i++) {
		lineptr[i] = NULL;
	}
	if ((nlines = readlines(lineptr, MAXLINE)) > 0) {
		/* 按不同的排序算法排序 */
		if (OPTION & NUMERIC) {
			u_qsort(lineptr, 0, nlines - 1, (int (*) (void *, void *)) numcmp);
		}
		else {
			u_qsort(lineptr, 0, nlines - 1, (int (*) (void *, void *)) charcmp);
		}
		/* 按不同的要求打印 */
		writelines(lineptr, nlines, OPTION & DECR);
	}
	else {
		printf("Input too big to sort\n");
		return -1;
	}
	getchar();
	return 0;
}


void readargs(int argc, char *argv[])
{
	int c, d;
	
	while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+') {
		d = *(argv[0] + 1);
		if (c == '-' && !isdigit(d)) {
			while (c = *++argv[0]) {
				switch (c) {
				case 'd':
					OPTION |= DIR;
					break;
				case 'f':
					OPTION |= FOLD;
					break;
				case 'n':
					OPTION |= NUMERIC;
					break;
				case 'r':
					OPTION |= DECR;
					break;
				default :
					printf("Illegal OPTION\n");
					error("Usage: sort -dfnr [+pos1] [-pos2]");
					break;
				}
			}
		}
		else if (c == '-') {
			POS2 = atoi(argv[0] + 1);
		}
		else if ((POS1 = atoi(argv[0] + 1)) < 0) {
			error("Usage: sort -dfnr [+pos1] [-pos2]");
		}
	}
	if (argc || POS1 > POS2) {
		error("Usage: sort -dfnr [+pos1] [-pos2]");
	}
}

/* readlines 版本1 */
#define BUFSIZE			10000

char *alloc(int len);
char buf[BUFSIZE];
char *pbuf = buf;

int readlines(char **lineptr, int maxline)
{
	int len, nlines;
	char *p, line[MAXLEN];
	
	nlines = 0;
	while ((len = Getline(line, MAXLEN)) > 0) {
		if (nlines > MAXLINE || (p = alloc(len)) == NULL) {
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

char *alloc(int len)
{
	if (pbuf + len <= buf + BUFSIZE) {
		pbuf += len;
		return pbuf - len;
	}
	else {
		return NULL;
	}
}

int Getline(char line[], int max)
{
	int c;
	int i;
	
	i = 0;
	while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
		line[i++] = c;
	}
	if (c == '\n') {
		line[i++] = c;
	}
	line[i] = '\0';
	return i;
}

void u_qsort(char *v[], int left, int right, int (*comp) (void *, void *))
{
	int i, last;
	void swap(char *v[], int i, int j);
	
	if (left >= right) {
		return;
	}
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if ((*comp)(v[i], v[left]) < 0) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	u_qsort(v, left, last - 1, comp);
	u_qsort(v, last + 1, right, comp);
}

void swap(char *v[], int i, int j)
{
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#define MAXSTR			100

int numcmp(char *s1, char *s2)
{
	double v1, v2;
	char str[MAXSTR];
	
	substr(s1, str, MAXSTR);
	v1 = atof(s1);
	substr(s1, str, MAXSTR);
	v2 = atof(s2);
	if (v1 < v2) {
		return -1;
	}
	else if (v1 > v2) {
		return 1;
	}
	else {
		return 0;
	}
}

int charcmp(char *s1, char *s2)
{
	char a, b;
	int i, j, endpos;
	int fold = (OPTION & FOLD) ? 1 : 0;
	int dir = (OPTION & DIR) ? 1 : 0;
	
	i = j = POS1;
	if (POS2 > 0) {
		endpos = POS2;
	}
	else if ((endpos = strlen(s1)) > strlen(s2)) {
		endpos = strlen(s2);
	}
	do {
		if (dir) {
			while (i < endpos && !isalnum(s1[i]) &&
				s1[i] != ' ' && s1[i] != '\0') {
					i++;
			}
			while (j < endpos && !isalnum(s2[j]) &&
				s2[j] != ' ' && s2[j] != '\0') {
					j++;
			}
		}
		if (i < endpos && j < endpos) {
			a = fold ? tolower(s1[i]) : s1[i];
			i++;
			b = fold ? tolower(s2[j]) : s2[j];
			j++;
			if (a == b && a == '\0') {
				return 0;
			}
		}
	} while (a == b && i < endpos && j < endpos);
	return a - b;
}

void substr(char *s, char *str, int maxstr)
{
	int i, j, len;
	
	len = strlen(s);
	if (POS2 > 0 && len > POS2) {
		len = POS2;
	}
	else if (POS2 > 0 && len < POS2) {
		error("substr: string too short");
	}
	for (j = 0, i = POS1; i < len; i++, j++) {
		str[j] = str[i];
	}
	str[j] = '\0';
}

void error(char *s)
{
	printf("%s", s);
	exit(1);
}

void writelines(char *lineptr[], int maxline, int decr)
{
	int i;
	
	if (decr) {
		for (i = maxline - 1; i >= 0; i--) {
			printf("%s\n", lineptr[i]);
		}
	}
	else {
		for (i = 0; i < maxline; i++) {
			printf("%s\n", lineptr[i]);
		}
	}
}