#include <stdio.h>
#include <ctype.h>

#define TSIZE			8

int main(int argc, char *argv[])
{
	int pos;
	int nblank;
	int ntab;
	int c;
	int U_TABSIZE = 0;
	int TABSIZE;
	
	TABSIZE = TSIZE;
	while (--argc > 0 && (*++argv)[0] == '-') {
		while (isdigit(c = *++argv[0])) {
			U_TABSIZE = U_TABSIZE * 10 + c - '0';
		}
		if (c == '\0') {
			TABSIZE = U_TABSIZE;
		}
	}
	nblank = ntab = 0;
	for (pos = 1; (c = getchar()) != EOF; pos++) {
		if (c == ' ') {
			if (pos % TABSIZE == 0) {
				ntab++;
				nblank = 0;
				pos = 0;
			}
			else {
				nblank++;
			}
		}
		else {
			while (ntab > 0) {
				putchar('\t');
				ntab--;
			}
			if (c == '\t') {
				nblank = 0;
				pos = 0;
			}
			else {
				while (nblank > 0) {
					putchar(' ');
					nblank--;
				}
			}
			if (c == '\n') {
				pos = 0;
			}
			putchar(c);
		}
	}
}