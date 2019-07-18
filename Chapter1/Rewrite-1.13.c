#include <stdio.h>

#define IN				1
#define OUT				0
#define WORD_LENGTH		20
#define WORD_COUNT		20
#define DISPLAY_LENGTH	10

int main()
{
	int c, state;
	int i, j, wl, maxwl, overflow;
	int nw[WORD_COUNT];
	
	/* initialize array of word length */
	for (i = 0; i < WORD_COUNT; ++i) {
		nw[i] = 0;
	}
	wl = 0;	/* initialize word length */
	overflow = 0;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
			if (wl > 0 ) {
				if (wl < WORD_LENGTH) {
					++nw[wl];
				}
			    else {
					++overflow;
				}
			}
			wl = 0;
		}
		else if (state == OUT) {
			state = IN;
			++wl;
		}
		else {
			++wl;
		}
	}
	maxwl = 0;
	for (i = 0; i < WORD_LENGTH; ++i) {
		if (maxwl < nw[i]) {
			maxwl = nw[i];
		}
	}
	
	/* 水平直方图 */
	// for (i = 0; i < WORD_LENGTH; ++i) {
		// printf("%2d:", i);
		// for (j = 0; j < nw[i] * DISPLAY_LENGTH / maxwl; ++j) {
			// printf("|");
		// }
		// printf("\n");
	// }
	// if (overflow > 0) {
		// printf("There are %d words >= %d", overflow, WORD_LENGTH);
	// }
	
	/* 垂直直方图 */
	for (i = 0; i < DISPLAY_LENGTH; ++i) {
		for (j = 0; j < WORD_LENGTH; ++j) {
			if (nw[i] * DISPLAY_LENGTH / maxwl - i > 0) {
				printf(" * ");
			}	
		}
		printf("\n");
	}
	if (overflow > 0) {
		printf("There are %d words >= %d", overflow, WORD_LENGTH);
	}	
	getchar();
}