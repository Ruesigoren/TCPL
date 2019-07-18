#include <stdio.h>

/* 我的实现- 因为对题意理解不同,所以我的实现跟习题解答的思路不一致 */
//#define MAXLINE		1000
//#define TABEND		40
//
//int getline(char line[], int maxline);
//void copy(char to[], char from[]);
//void detab(char line[], int n);
//
//main()
//{
//	char line[MAXLINE];
//	int len;
//
//	while ((len = getline(line, MAXLINE)) > 0) {
//		detab(line, TABEND);
//		printf("%s", line);
//	}
//}
//
//void detab(char line[], int n)
//{
//	char deline[MAXLINE];
//	int i, j, k;
//
//	for (i = 0, j = 0, k = 0; line[i] != '\0'; ++i) {
//		if (line[i] != '\t' && j < TABEND) {
//			deline[j] = line[i];
//			++j;
//			++k;
//		}
//		if (line[i] == '\t' && j < TABEND) {
//			//k = j + (k / 8 + 1) * 8 - k;
//			k = j + (8 - k % 8);
//			for (; j < k; ++j) {
//				deline[j] = ' ';
//			}
//			k = 0;
//		}
//	}
//	deline[j] = '\0';
//	copy(line, deline);
//}
//
//int getline(char line[], int maxline)
//{
//	int c, i, j;
//
//	for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
//		if (i < maxline - 2) {
//			line[j] = c;
//			++j;
//		}
//	}
//	if (c == '\n') {
//		line[j] = c;
//		++i;
//		++j;
//	}
//	line[j] = '\0';
//	return i;
//}
//
//void copy(char to[], char from[])
//{
//	int i = 0;
//
//	while ((to[i] = from[i]) != '\0') {
//		++i;
//	}
//}

#define TABINC		8		/* tab increment size */

/* replace tabs with the proper number of blanks */
main()
{
	int c, nb, pos;

	nb = 0;										/* number of blanks necessary */
	pos = 1;									/* postion of character in line */
	while ((c = getchar()) != EOF) {
		if (c == '\t') {						/* tab character */
			nb = TABINC - (pos - 1) % TABINC;
			while (nb > 0) {
				putchar(' ');
				++pos;
				--nb;
			}
		}
		else if (c == '\n') {					/* newline character */
			putchar(c);
			pos = 1;
		}
		else {									/* all other characters */
			putchar(c);
			++pos;
		}
	}
}
