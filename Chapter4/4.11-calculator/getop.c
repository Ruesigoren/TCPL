#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[])
{
	int i;
	int c;
	static int save = 0;

	if (save == 0) {
		c = getch();
	}
	else {
		c = save;
		save = 0;
	}
	while ((s[0] = c) == ' ' || c == '\t') {
		c = getch();
	}
	s[1] = '\0';
	if (!isdigit(c) && !islower(c) && c != '.' && c != '-') {
		return c;
	}
	i = 0;
	if (islower(c)) {
		while (islower(s[++i] = c = getch())) {
			;
		}
		s[i] = '\0';
		if (c != EOF) {
			save = c; //ungetch(c);
		}
		if (strlen(s) == 3) {
			return NAME;
		}
		else
			return s[0];	//答案中 return c; 应该是错的
	}
	if (c == '-') {
		if (isdigit(c = getch()) || c == '.') {
			s[++i] = c;
		}
		else {
			if (c != EOF) {
				save = c;//ungetch(c);
			}
			return '-';
		}
	}
	if (isdigit(c)) {
		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}
	if (c == '.') {
		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}
	s[i] = '\0';
	if (c != EOF) {
		save = c; //ungetch(c);
	}
	return NUMBER;
}