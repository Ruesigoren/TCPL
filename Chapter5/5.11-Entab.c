//#include <stdio.h>
//#include <ctype.h>
//
//#define TABINC	8
//
//int main(int argc, char *argv[])
//{
//	int c, nt, nb, pos;
//	int TabINC = 0;
//	int UserDefine = 0;
//	int tabinc;
//
//	nb = 0;												/* # of blanks necessary */
//	nt = 0;												/* # of tabs necessary */
//
//	while (--argc > 0 && (*++argv)[0] == '-') {
//		while (isdigit(c = *++argv[0])) {
//			TabINC = 10 * TabINC + c - '0';
//		}
//		if (isblank(c) || c == '\0') {
//			UserDefine = 1;
//		}
//	}
//	if (UserDefine) {
//		tabinc = TabINC;
//	}
//	else {
//		tabinc = TABINC;
//	}
//	for (pos = 1; (c = getchar()) != EOF; ++pos) {
//		if (c == ' ') {
//			if (pos % tabinc != 0) {
//				++nb;									/* increments # of blanks */
//			}
//			else {
//				nb = 0;									/* reset # of blanks */
//				++nt;									/* one more tab */
//			}
//		}
//		else {
//			for (; nt > 0; --nt) {						/* output tabs */
//				putchar('\t');
//			}
//			for (; nb > 0; --nb) {
//				putchar(' ');
//			}
//			putchar(c);
//			if (c == '\n') {
//				pos = 0;
//			}
//			else if (c == '\t') {
//				pos = pos + (tabinc - (pos - 1) % tabinc) - 1;
//				//pos = 0;
//			}
//		}
//	}
//}


#include <stdio.h>

#define MAXLINE		100
#define TABINC		8
#define YES			1
#define NO			0

void settab(int argc, char *argv[], char *tab);
void entab(char *tab);
void detab(char *tab);
int tabpos(int pos, char *tab);

/* replace strings of blanks with tabs */
main(int argc, char *argv[])
{
	char tab[MAXLINE + 1];

	settab(argc, argv, tab);	/* initialize tab stops */
	//entab(tab);					/* replace blanks with tab */
	detab(tab);
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
