#include <stdio.h>

//#define LENGTH		8
//#define MAXLINE		1000
//
//int getline(char line[], int maxline);
//
//main()
//{
//	char line[MAXLINE];
//	int len;
//	int i, j;
//	int start, pos;
//
//	while ((len  = getline(line, MAXLINE)) > 0) {
//		i = j = 0;
//		start = 0, pos = 0;
//		while (pos + LENGTH < len) {
//			start = pos;
//			for (i = pos; i < pos + LENGTH && i < len; ++i) {
//				if (line[i] == ' ' || line[i] == '\t') {
//					pos = i;
//				}
//			}
//			if (pos != start) {
//				for (j = start; j < pos; ++j) {
//					putchar(line[j]);
//				}
//				putchar('\n');
//			}
//			else {
//				for (j = start; j < start + LENGTH; ++j) {
//					putchar(line[j]);
//				}
//				pos = start = start + LENGTH;
//				putchar('\n');
//			}
//		}
//		for (j = start; j < start + LENGTH && j < len; ++j) {
//			putchar(line[j]);
//		}
//	}
//}
//
//int getline(char line[], int maxline)
//{
//	int c, i, j;
//
//	j = 0;
//	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
//		if (j < maxline - 2) {
//			line[j] = c;
//			++j;
//		}
//	}
//	if (c == '\n') {
//		line[j] = '\n';
//		++i;
//		++j;
//	}
//	line[j] = '\0';
//	return i;
//}

//#define MAXCOL		10		/* maximum column of input */
//#define TABINC		8		/* tab increment size */
//
//char line[MAXCOL];			/* input line */
//int exptab(int pos);
//int findblank(int pos);
//int newpos(int pos);
//void printl(int pos);
//
///* fold long input lines into two or more shorter lines */
//main()
//{
//	int c, pos;
//
//	pos = 0;							/* position in the line */
//	while ((c = getchar()) != EOF) {
//		line[pos] = c;					/* store current character */
//		if (c == '\t') {
//			pos = exptab(pos);			/* expand tab charater */
//		}
//		else if (c == '\n') {
//			printl(pos);				/* print current input line */
//			pos = 0;
//		}
//		else if (++pos >= MAXCOL) {
//			pos = findblank(pos);
//			printl(pos);
//			pos = newpos(pos);
//		}
//	}
//}
//
///* exptab: expand tab into blanks */
//int exptab(int pos)
//{
//	line[pos] = ' ';		/* tab is at least one blank */
//	for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos) {
//		line[pos] = ' ';
//	}
//	if (pos < MAXCOL) {		/* room left in current line */
//		return pos;
//	}
//	else {					/* current line is full */
//		printl(pos);
//		return 0;			/* reset current position */
//	}
//}
//
///* findblank: find blank's position */
//int findblank(int pos)
//{
//	while (pos > 0 && line[pos] != ' ') {
//		--pos;
//	}
//	if (pos == 0) {			/* no blanks in the line? */
//		return MAXCOL;
//	}
//	else {					/* at least one blank */
//		return pos + 1;		/* position after the blank */
//	}
//}
//
///* newpos: rearrange line with new position */
//int newpos(int pos)
//{
//	int i, j;
//
//	if (pos <= 0 || pos >= MAXCOL) {
//		return 0;						/* nothing to rearrange */
//	}
//	else {
//		i = 0;
//		for (j = pos; j < MAXCOL; ++j) {
//			line[i] = line[j];
//			++i;
//		}
//		return i;						/* new position */
//	}
//}
//
///* print line until pos column */
//void printl(int pos)
//{
//	int i;
//
//	for (i = 0; i < pos; ++i) {
//		putchar(line[i]);
//	}
//	if (pos > 0) {					/* any chars printed? */
//		putchar('\n');
//	}
//}

#define MAXCOL		10
#define TABINC		8

char LINE[MAXCOL];
int expPos(int pos);
void printLine(int pos);
int findBlank(int pos);
int newPos(int pos);
int realpos = 0;
int nline = 0;

main()
{
	int pos = 0;
	int c;

	while ((c = getchar()) != EOF) {
		LINE[pos] = c;
		++realpos;
		if (c == '\t') {
			pos = expPos(pos);
		}
		else if (c == '\n') {
			printLine(pos);
			pos = 0;
		}
		else if (++pos >= MAXCOL) {
			pos = findBlank(pos);
			printLine(pos);
			pos = newPos(pos);
		}
	}
}

int expPos(int pos)
{
	//int i;

	//i = pos;
	//LINE[i] = ' ';
	//for (;(i < pos + pos % TABINC) && i < MAXCOL; ++i) {
	//	LINE[i] = ' ';
	//}
	//if (i == MAXCOL) {
	//	printLine(i);
	//	return 0;
	//}
	//else {
	//	pos = i;
	//	return pos;
	//}
	int i;

	LINE[pos] = ' ';
	for (++pos; pos < MAXCOL && (pos + nline * MAXCOL) % TABINC != 0; ++pos) {
		LINE[pos] = ' ';
	}
	for (++realpos; realpos % TABINC != 0; ++realpos) {
		;
	}
	if (pos < MAXCOL) {
		return pos;
	}
	else {
		printLine(pos);
		for (i = 0; i < (realpos - nline * MAXCOL) % TABINC; ++i) {
			LINE[i] = ' ';
		}
		return i;
	}
}

void printLine(int pos)
{
	int i;

	for (i = 0; i < pos; ++i) {
		putchar(LINE[i]);
	}
	if (pos > 0) {
		putchar('\n');
	}
	++nline;
}

int findBlank(int pos)
{
	while (pos > 0 && LINE[pos] != ' ') {
		--pos;
	}
	if (pos == 0) {
		return MAXCOL;
	}
	else {
		return pos + 1;
	}
}


int newPos(int pos)
{
	int i, j;

	if (pos <= 0 || pos >= MAXCOL) {
		return 0;
	}
	for (i = 0, j = pos; j < MAXCOL; ++i, ++j) {
		LINE[i] = LINE[j];
	}
	return i;
}
