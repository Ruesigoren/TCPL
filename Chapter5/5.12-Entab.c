#include <stdio.h>

#define MAXLINE		100
#define TABINC		8
#define YES			1
#define NO			0

void esettab(int argc, char *argv[], char *tab);
int tabpos(int pos, char *tab);
void entab(char *tab);
void detab(char *tab);

main(int argc, char *argv[]) 
{
	char tab[MAXLINE + 1];

	esettab(argc, argv, tab);
	entab(tab);
	return	0;
}

/* entab: replace strings of blanks with tabs and blanks */
void entab(char *tab)
{
	int c, pos;
	int nb = 0;
	int nt = 0;

	for (pos = 1; (c = getchar()) != EOF; pos++) {
		if (c == ' ') {
			if (tabpos(pos, tab) == NO) {
				++nb;		/* increment of blanks */
			}
			else {
				nb = 0;		/* reset of blanks */
				++nt;
			}
		}
		else {
			for (; nt > 0; nt--) {
				putchar('\t');
			}
			if (c == '\t') {
				nb = 0;
			}
			else {
				for (; nb > 0; nb--) {
					putchar(' ');
				}
			}
			putchar(c);
			if (c == '\n') {
				pos = 0;
			}
			else if (c == '\t') {
				while (tabpos(pos, tab) != YES) {
					++pos;
				}
			}
		}
	}
}

void detab(char *tab)
{
	int c, pos = 1;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			do
				putchar(' ');
			while (tabpos(pos++, tab) != YES);
		}
		else if (c == '\n') {
			putchar(c);
			++pos;
		}
		else {
			putchar(c);
			++pos;
		}
	}
}
