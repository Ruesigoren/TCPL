#include <stdio.h> 

//#define TABINC		8
//#define IN			1
//#define OUT			0
//
//int main()
//{
//	int state = OUT;
//	int c;
//	int nb = 0;
//	int pos = 0;
//
//	while ((c = getchar()) != EOF) {
//		if (c == '\n') {
//			pos = -1;
//		}
//		if (state == IN) {
//			if (c == ' ') {
//				++nb;
//				if (nb == TABINC) {
//					putchar('\t');
//					nb = pos;
//					pos = 0;
//				}
//			}
//			else {
//				state = OUT;
//				while (nb > 0) {
//					putchar(' ');
//					--nb;
//				}
//				putchar(c);
//				pos += nb + 1;
//			}
//		}
//		else if (c == ' ') {
//				state = IN;
//				++nb;
//			}
//		else {
//			putchar(c);
//			++pos;
//		}
//	}
//}

#define TABINC		8

main()
{
	int c, nt, nb, pos;

	nb = 0;												/* # of blanks necessary */
	nt = 0;												/* # of tabs necessary */
	for (pos = 1; (c = getchar()) != EOF; ++pos) {
		if (c == ' ') {
			if (pos % TABINC != 0) {
				++nb;									/* increments # of blanks */
			}
			else {
				nb = 0;									/* reset # of blanks */
				++nt;									/* one more tab */
			}
		}
		else {
			for (; nt > 0; --nt) {						/* output tabs */
				putchar('\t');
			}
			for (; nb > 0; --nb) {
				putchar(' ');
			}
			//if (c == '\t') {							/* forget the blanks */
			//	nb = 0;
			//}
			//else {										/* output blanks */
			//	for (; nb > 0; --nb) {
			//		putchar(' ');
			//	}
			//}
			putchar(c);
			if (c == '\n') {
				pos = 0;
			}
			else if (c == '\t') {
				pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
				//pos = 0;
			}
		}
	}
}
