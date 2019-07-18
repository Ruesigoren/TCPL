#include <stdio.h>

/*	//这是我的实现
#define IN		1
#define OUT		0
#define LEN		20

main()
{
	int c, nc, state;
	int i, n[LEN];

	nc = 0;
	state = OUT;
	for (i = 0; i < LEN; ++i) {
		n[i] = 0;
	}
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				++n[nc];
				if (nc > 0) {
					putchar(' ');
				}
				while (nc > 0) {
					putchar('*');
					--nc;
				}
				state = OUT;
				putchar('\n');
			}
		}
		else if (state == OUT) {
			state = IN;
			putchar(c);
			++nc;
		}
		else {
			putchar(c);
			++nc;
		}
	}
	for (i = 0; i < LEN; ++i) {
		printf("%d", i);
		printf(" ");
		while (n[i] > 0) {
			printf("*");
			--n[i];
		}
		printf("\n");
	}
}
*/


//#define MAXHIST	15	/* max length of histogram */
//#define MAXWORD	11	/* max length of a word */
//#define IN		1	/* inside a word */
//#define OUT		0	/* outside a word */
//
///* print horizontal histogram */
//main()
//{
//	int c, i, nc, state;
//	int len;			/* length of each bar */
//	int maxvalue;		/* maximum value for wl[] */
//	int overflow;		/* number of overflow values */
//	int wl[MAXWORD];	/* word length counters */
//
//	state = OUT;
//	nc = 0;				/* number of chars in a word */
//	overflow = 0;		/* number of words >= MAXWORD */
//	for (i = 0; i < MAXWORD; ++i) {
//		wl[i] = 0;
//	}
//	while ((c = getchar()) != EOF) {
//		if (c == ' ' || c == '\t' || c == '\n') {
//			state = OUT;
//			if (nc > 0) {
//				if (nc < MAXWORD)
//					++wl[nc];
//				else
//					++overflow;
//			}
//		}
//		else if (state == OUT) {
//			state = IN;
//			nc = 1;			/* beginning of a new word */
//		}
//		else
//			++nc;			/* inside a word */
//	}
//	maxvalue = 0;
//	for (i = 0; i < MAXWORD; ++i) {
//		if (wl[i] > maxvalue)
//			maxvalue = wl[i];
//	}
//	for (i = 0; i < MAXWORD; ++i) {
//		printf("%5d - %5d : ", i, wl[i]);
//		if (wl[i] > 0) {
//			if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
//				len = 1;
//		}
//		else
//			len = 0;
//		while (len > 0) {
//			putchar('*');
//			--len;
//		}
//		putchar('\n');
//	}
//	if (overflow > 0)
//		printf("There are %d words >= %d \n", overflow, MAXWORD);
//}


#include <stdio.h>

#define	MAX_WORD_LENGTH		10
#define HIST_RANGE			10
#define IN_WORD				1
#define OUT_OF_WORD			0

main()
{
	int c, i, state, nc, wl[HIST_RANGE];
	int overflow;
	int len;
	int maxvalue;

	nc = 0;
	overflow = 0;
	state = OUT_OF_WORD;
	for (i = 0; i < HIST_RANGE; ++i) {
		wl[i] = 0;
	}
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT_OF_WORD;
			if (nc > 0) {
				if (nc < HIST_RANGE)
					++wl[nc];
				else
					++overflow;
			}
			nc = 0;
		}
		else if (state == OUT_OF_WORD){
			state = IN_WORD;
			nc =  1;
		}
		else {
			++nc;
		}
	}
	maxvalue = wl[0];
	for (i = 0; i < HIST_RANGE; i++) {
		if (maxvalue < wl[i])
			maxvalue = wl[i];
	}

	for (i = 0; i < HIST_RANGE; i++) {
		printf("%d - %d", i, wl[i]);
		if (wl[i] > 0) {
			if (len = wl[i] * MAX_WORD_LENGTH / maxvalue  <= 0)	//将打印的长度规范在最大单词长度内
				len = 1;
		}
		else
			len = 0;
		while (len > 0) {
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if (overflow > 0) {
		printf("There are %d words >= %d \n", overflow, MAX_WORD_LENGTH);
	}
}

